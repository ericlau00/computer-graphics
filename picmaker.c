#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //open
#include <unistd.h> //read, write, close
#include <errno.h> //errno

char ** parse_args(char * line) {
    char * buff = line;
    char ** args = malloc(sizeof(char) * 6);
    int arg = 0;
    while(buff != NULL) {
        args[arg++] = strsep(&buff, " ");
    }
    args[arg] = NULL;
    return args;
}

int main() {
    int fd = open("pic.ppm", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd < 0) {
        printf("errno: %d error: %s\n", errno, strerror(errno));
        return 1;
    }

    char buff[] = "P3\n500 500\n255\n";
    if( write(fd, &buff, sizeof(buff) - 1) < 0) {
        printf("errno: %d error: %s\n", errno, strerror(errno));
        return 1;
    }

    // char pixel[11] = "255 255 255";
    // char

    // char lines[] = "255 255 0 255 255 0 255 255 0 255 255 0 255 255 0\n255 255 0 255 255 0 255 255 0 255 255 0 255 255 0\n255 255 0 255 255 0 255 255 0 255 255 0 255 255 0\n255 255 0 255 255 0 255 255 0 255 255 0 255 255 0\n255 255 0 255 255 0 255 255 0 255 255 0 255 255 0\n";
    // if( write(fd, &lines, sizeof(lines) - 1) < 0) {
    //     printf("errno: %d error: %s\n", errno, strerror(errno));
    //     return 1;
    // }

    if( close(fd) < 0) {
        printf("errno: %d error: %s\n", errno, strerror(errno));
        return 1;
    }

    char command[23] = "convert pic.ppm pic.png";
    char ** args = parse_args(command);
    execvp(args[0], args);
    free(args);
    return 0;
}