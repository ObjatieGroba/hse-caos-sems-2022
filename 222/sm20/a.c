#include <unistd.h>
#include <stdio.h>

int main() {
    printf("1");
    pid_t res = fork();
    printf("2");
//    printf("%ld", res);
}
