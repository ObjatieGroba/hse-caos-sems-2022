#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>

int main() {
    int fd = open("file.txt",
                  O_CREAT | O_RDWR,
                  0600);
    if (fd < 0) {
        printf("Failed to open\n");
        return 1;
    }
    errno = 0;
    char * addr = mmap(NULL, 16,
                       PROT_WRITE | PROT_READ,
                       MAP_SHARED,
                        fd, 0);
    printf("%p %d\n", addr, errno);
    // char t[] = "awdjnnaiwbdliawidbakd";
    // write(fd, t, sizeof(t) - 1);
    addr[10] = 'b';
    addr[26] = 'c';
    scanf("%d", &errno);
}
