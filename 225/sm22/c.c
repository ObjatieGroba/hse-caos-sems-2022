/// ls | grep x

#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    pid_t child1 = fork();
    if (child1 == 0) {
        /// LS
        /// close(1); НЕ НУЖНО, DUP2 молодец
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", NULL);
        _exit(0);
    }
    pid_t child2 = fork();
    if (child2 == 0) {
        /// grep x
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "x", NULL);
        _exit(0);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
}
