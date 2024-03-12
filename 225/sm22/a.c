#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>

int i = 0;

void handler(int sig) {
    i += 1;
    printf("%d\n", i);
    signal(sig, handler);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        /// Child
        signal(SIGUSR1, handler);
        while (1) {
            sleep(2);
            printf("%d\n", i);
        }
    } else {
        /// Father
        int c = 5;
        while (--c) {
            sleep(1);
            kill(pid, SIGUSR1);
        }
        kill(pid, SIGTERM);
        int i;
        wait(&i);
        if (WIFSIGNALED(i)) {
            printf("Signal exit\n");
        } else if (WIFEXITED(i)) {
            printf("Exited\n");
        }
    }
}