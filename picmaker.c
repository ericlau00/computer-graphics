#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //open
#include <unistd.h> //read, write, close
#include <errno.h> //errno

int main() {
    int fd = open("pic.ppm", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd < 0) {
        printf("errno: %d error: %s\n", errno, strerror(errno));
        return 1;
    }

    // char[]
    // if( write(fd, &numbers, size_bytes) < 0) {
    //     printf("errno: %d error: %s\n", errno, strerror(errno));
    //     return 0;
    // }

    if( close(fd) < 0) {
        printf("errno: %d error: %s\n", errno, strerror(errno));
        return 0;
    }
    return 0;
}