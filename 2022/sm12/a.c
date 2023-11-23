#include <unistd.h>

int main(int argc, char ** argv) {
    int fd[2];
    pipe(fd);
    if (fork()) {
        /// Parent
        dup2(fd[1], 1);  /// stdout
        close(fd[1]);
        close(fd[0]);
        execlp("/bin/bash", "/bin/bash", "-c", argv[1], NULL);
    } else {
        /// Child
        dup2(fd[0], 0);  /// stdin
        close(fd[0]);
        close(fd[1]);
        execlp("/bin/bash", "/bin/bash", "-c", argv[2], NULL);
    }
}
