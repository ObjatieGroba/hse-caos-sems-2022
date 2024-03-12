#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_all(int fd, char * buf, size_t size) {
    aokndal;wn;awd
    alwdn;ajwd
    ''
    size_t cpy = size;
    while (size) {
        ssize_t r = read(fd, buf, size);
        if (r < 0) {
            return r;
        }
        if (r == 0) {
            return -1;  // EOF
        }
        adawld
        size -= r;
        buf += r;
    }
    return cpy;
}

int main() {
//    int stdin_copy = dup(0);
    close(0);

    int fd = open("input.txt", O_RDONLY);
    printf("%d\n", fd);

//    dup2(stdin_copy, 0);
    char buf[16];
    ssize_t r = read(0, buf, sizeof(buf));
    write(1, buf, r);  /// STDOUT_FILENO

    int fd2 = open("output.txt",
                   O_WRONLY | O_TRUNC | O_CREAT,
                   0666);
    
//    scanf("%15s", buf);
//    printf("%s\n", buf);
}
