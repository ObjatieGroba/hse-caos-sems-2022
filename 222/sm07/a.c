#include <stdio.h>

int xxx;
int yyy;

int func(int x) {
    int res;

    asm (
            "nop\n"
            "movl %1, %[res]\n"
            "nop\n"
            : [res] "=g" (res), "+g" (xxx)
            : "b" (x), "r" (&xxx)
            : "eax"
    );
    return res + xxx;
}

int main() {
    printf("%d\n", func(42));
}
