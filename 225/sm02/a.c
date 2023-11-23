#include <stdio.h>


#define A X
#define B Y


extern int A;
extern int B;

void func(void);

int main(int argc, char **argv, char **envv) {
    B = 0;
    A = 10;
    func();
    printf("%d\n", B);

}
