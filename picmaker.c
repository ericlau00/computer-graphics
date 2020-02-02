#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //open
#include <unistd.h> //read, write, close
#include <errno.h> //errno

char ** _parse_args(char * line);

int main() {
    int fd = open("pic.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0666);

    char header[16];
    sprintf(header, "P3\n%d %d\n255\n", 500, 700);

    write(fd, &header, strlen(header));

    int x, y;
    char pixel[13];
    for( y = 0; y < 700; y++ ) {
        int top_stripe = rand() % 5;
        int bottom_stripe = rand() % 7;
        for( x = 0; x < 500; x++) {
            if (y < 50 || y > 650 || x < 50 || x > 450 || (y < 450 && y > 420)) {
                sprintf(pixel, "%d %d %d ", 255, 255, 255);
            }
            else if (y < 450) {
                if(top_stripe == 0) {
                    sprintf(pixel, "%d %d %d ", 200 + rand() % 20, 200 + rand() % 20, 200 + rand() % 20);
                } else {
                    sprintf(pixel, "%d %d %d ", 200, 200, 200);
                }
            } else {
                if(bottom_stripe == 0) {
                    sprintf(pixel, "%d %d %d ", 100 + rand() % 30, 100 + rand() % 30, 100 + rand() % 30);
                } else {
                    sprintf(pixel, "%d %d %d ", 100 + rand() % 5, 100 + rand() % 5, 100 + rand() % 5);
                }
            }
            write(fd, pixel, strlen(pixel));
        }
        write(fd, &"\n", sizeof("\n") - 1);
    }

    close(fd);

    char command[23] = "convert pic.ppm pic.png";
    char ** args = _parse_args(command);
    execvp(args[0], args);
    free(args);

    return 0;
}

char ** _parse_args(char * line) {
    char * buff = line;
    char ** args = malloc(sizeof(char) * 6);
    int arg = 0;
    while(buff != NULL) {
        args[arg++] = strsep(&buff, " ");
    }
    args[arg] = NULL;
    return args;
}