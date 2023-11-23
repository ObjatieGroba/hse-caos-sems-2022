#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

pid_t async_mysys(const char * cmd) {
    pid_t pid = fork();
    if (pid) {
        /// Parent
        return pid;
    } else {
        execlp("/bin/bash", "/bin/bash", "-c", cmd, NULL);
        _exit(0);
    }
}

int main(int argc, char ** argv) {
    int fd[2];
    pipe(fd);

    int fd_stdout = dup(1);

    dup2(fd[1], 1);  /// stdout
    int pid1 = async_mysys(argv[1]);
//    close(1);

    dup2(fd[0], 0);  /// stdin
    dup2(fd_stdout, 1);  /// stdout
    close(fd[1]);
    int pid2 = async_mysys(argv[2]);
    close(0);

    printf("%d\n", wait(NULL));
    printf("%d\n", wait(NULL));
}
