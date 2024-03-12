#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);
    char buf[4];
    close(fd[0]);
    write(fd[1], buf, sizeof(buf));
}
