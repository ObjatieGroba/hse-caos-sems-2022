#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>

int main() {
    int fd = open("input.txt", O_RDWR);
    printf("%d\n", fd);
    char *c = mmap(NULL, 1000,
                   PROT_READ | PROT_WRITE, MAP_SHARED,
                   fd, 0);
    printf("%p\n", c);
    c[100] = '0';
    munmap(c, 1000);
    ftruncate(fd, 128);
    close(fd);
}
