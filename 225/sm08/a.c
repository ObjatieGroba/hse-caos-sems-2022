typedef unsigned long long ull;

#include <stdio.h>

union U {
    double d;
    ull u;
    char c[8];
};

struct BitS {
    ull m: 52;
    ull e: 11;
    ull s: 1;
};

union U2 {
    double d;
    struct BitS b;
};

int main() {
//    float f;
//    int i;
//    i = *(int*)(void*)&f;

    union U u;
    u.d = -0.5;
    printf("%lld\n", u.u);

    union U2 u2;
    u2.d = u.d;

    printf("%llu %llu %llu\n",
           (long long unsigned)u2.b.s,
           (long long unsigned)u2.b.e,
           (long long unsigned)u2.b.m);
}
