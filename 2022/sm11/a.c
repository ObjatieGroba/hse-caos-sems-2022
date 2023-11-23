#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv, char**envp) {
    pid_t pid = fork();
    if (pid == -1) {
        /// No child
        return 1;
    }
    if (pid == 0) {
        /// I am child
//        printf("Feed me\n");
//        int y;
//        int*x = rand() ? NULL : &y;
//        scanf("%d", x);
        char *const argv[10] = {"cat", "a.c", NULL};
        execvp("cat", argv);
        return 1;
    } else {
        /// I am parent
        printf("Go home %d, you are dr...\n", pid);
        int status;
        wait(&status);
        // waitpid(pid, &status, 0);
        printf("Child status %d\n", status);
        if (WIFEXITED(status)) {
            printf("Exit code %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Signal %d\n", WTERMSIG(status));
        }
    }
}
