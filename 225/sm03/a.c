#include "stdio.h"

struct X {
    long double d;
    char x;
};

int main() {
    printf("%lu", sizeof(long double));
}
