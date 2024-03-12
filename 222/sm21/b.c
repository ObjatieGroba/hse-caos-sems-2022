#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>

int main() {
    printf("%d\n", getpid());
    int fd = open("input.txt", O_RDWR);
    printf("%d\n", fd);

    char *s = mmap(NULL, 5,
                   PROT_READ | PROT_WRITE, MAP_SHARED,
                   fd, 0);
    printf("%p\n", s);
    s[100] = '0';
    ftruncate(fd, 128);
}
