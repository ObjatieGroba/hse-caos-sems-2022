#include <signal.h>
#include <stdio.h>

void handler(int signo, void (*func)(int)) {
    printf("Abacaba\n");
//    signal(signo, handler);
};

//char buf[SIZE];
// int cur_size = 0;

int main(int argc, char * argv[]) {
    signal(SIGUSR1, handler);
    while(1) {
        printf("a");
        // try fill buf
        // else flush buf

        //   if size - cur_size < str_size
        //       flush
        //    else
        //       cpy buf + cur_size,  str
        //          SIGNAL
        ///            printf
        ////               if size - cur_size ...

        //       cur_size += str_size
    }
}
