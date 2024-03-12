#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    /// ls | grep x > output.txt

    int fd[2];
    pipe(fd);

    pid_t pid1 = fork();
    if (pid1 == 0) {
        /// ls
        /// 0 1 2 fd[0] fd[1] -> 0 fd[1] 2 fd[0] fd[1] -> 0 fd[1] 2
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", NULL);
        _exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        /// ls
        /// 0 1 2 fd[0] fd[1] -> fd[0] 1 2
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
//        int f = open("output.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666);
//        dup2(f, 1);
//        close(f);
        execlp("grep", "grep", "i", NULL);
        _exit(1);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
