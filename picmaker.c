#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //open
#include <unistd.h> //read, write, close
#include <errno.h> //errno

int main() {
    FILE * stream = fopen("pic.ppm", "w");

    char header[16];
    sprintf(header, "P3\n%d %d\n255\n", 500, 700);

    fwrite(header, 1, strlen(header), stream);

    int x, y;
    char pixel[13];
    for( y = 0; y < 700; y++ ) {
        int top_stripe = rand() % 5;
        int bottom_stripe = rand() % 7;
        for( x = 0; x < 500; x++) {
            if (y < 50 || y > 650 || x < 50 || x > 450 || (y < 450 && y > 420)) {
                fprintf(stream, "%d %d %d ", 50, 50, 50);
            }
            else if (y < 450) {
                if(top_stripe == 0) {
                    fprintf(stream, "%d %d %d ", 200 + rand() % 20, 200 + rand() % 20, 200 + rand() % 20);
                } else {
                    fprintf(stream, "%d %d %d ", 200, 200, 200);
                }
            } else {
                if(bottom_stripe == 0) {
                    fprintf(stream, "%d %d %d ", 100 + rand() % 30, 100 + rand() % 30, 100 + rand() % 30);
                } else {
                    fprintf(stream, "%d %d %d ", 100 + rand() % 5, 100 + rand() % 5, 100 + rand() % 5);
                }
            }
        }
        fwrite("\n", 1, sizeof("\n") - 1, stream);
    }

    fclose(stream);

    return 0;
}