#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>

volatile sig_atomic_t f = 0;

void handler(int sig) {
    f += 1;
    printf("Signal %d\n", sig);
    signal(sig, handler);
}

int main() {
    pid_t child = fork();
    if (child == 0) {
        /// Child
        signal(SIGUSR1, handler);
        signal(SIGTERM, handler);
        sleep(1);
        sleep(1);
        sleep(1);
        printf("After sleep %d\n", f);
    } else {
        /// Parent
        sleep(1);
        kill(child, SIGTERM);
//        sleep(1);
        kill(child, SIGUSR1);
//        sleep(1);
        kill(child, SIGTERM);
        int i;
        wait(&i);
        if (WIFEXITED(i)) {
            printf("Exited\n");
        } else if (WIFSIGNALED(i)) {
            printf("Signaled\n");
        }
    }
}
