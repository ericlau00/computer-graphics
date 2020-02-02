#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //open
#include <unistd.h> //read, write, close
#include <errno.h> //errno

char ** _parse_args(char * line);

int main() {
    int IMAGE_SIZE = 500;
    int fd = open("pic.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0666);

    char header[15];
    sprintf(header, "P3\n%d %d\n255\n", IMAGE_SIZE, IMAGE_SIZE);

    write(fd, &header, sizeof(header));

    int x, y;
    char pixel[13];
    for( y = 0; y < 500; y++ ) {
        for( x = 0; x < 500; x++) {
            if (y < 50 || y > 450 || (y > 300 && y < 350) || x < 50 || x > 450) {
                sprintf(pixel, "%d %d %d ", 252, 163, 255);
            } else {
                if ( y < 350 ) {
                    sprintf(pixel, "%d %d %d ", 0, 0, 0);
                } else {
                    sprintf(pixel, "%d %d %d ", 255, 255, 255);
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