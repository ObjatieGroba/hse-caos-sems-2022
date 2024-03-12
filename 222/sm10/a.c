#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

ssize_t read_all(int fd, char *buf, size_t size) {
    size_t copy = size;
    while (size) {
        ssize_t r = read(fd, buf, size);
        if (r < 0) {
            return r;
        }
        if (r == 0) {
            return -1; /// EOF
        }
        buf += r;
        size -= r;
    }
    return copy;
}

int main() {
    close(0);
    int fd = open("input.txt", O_RDONLY);
//    int fd2 = open("input.txt", O_RDONLY);
    printf("%d\n", fd);
    write(1, "abacaba\n", 8);

    char buf[32];
    ssize_t r = read(0, buf, sizeof(buf));
    write(1, buf, r);



    int x;
    scanf("%d", &x);
    printf("%d\n", x);
    printf("%d\n", fd2);

    close(1);
    open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);

    printf("MAMA\n");
}