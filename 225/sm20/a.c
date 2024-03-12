#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char**argv) {
    printf("1\n");
    pid_t res = fork();
    if (res == -1) {
        // Error
    } else if (res == 0) {
        // Child
        printf("-1\n");
        execl("/usr/bin/cat", "cat", NULL);
        execlp("cat", "cat", NULL);
        printf("Error\n");
        exit(1);
    } else {
        // Parent, res == child_pid
        printf("2\n");
        wait(NULL);
        printf("3\n");
    }
}
