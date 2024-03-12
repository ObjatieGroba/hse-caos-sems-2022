#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid = fork();
    int i;
    scanf("%d", &i);
    printf("%ld %d\n", getpid(), i);
    int res;
    wait(&res);
    /// pid < 0
//    if (pid == 0) {
//        int i;
//        scanf("%d", &i);
//        /// Child
//        execl("/usr/bin/ls", "ls", "-la", NULL);
//        printf("Error\n");
//        exit(1);
//    } else {
//        /// Parent
//        printf("Parent\n");
//        wait(NULL);
//    }
}
