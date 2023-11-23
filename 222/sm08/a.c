#include <stdio.h>

union U {
    double d;
    unsigned long long ull;
    char c[8];
};

struct BitFiledsDouble {
    unsigned long long m:52;
    unsigned long long e:11;
    unsigned long long s:1;
};

void generate(void*buf) {
    ((char*)buf)[0] = 0x99;
}

union U2 {
    struct BitFiledsDouble bfd;
    double d;
};

int main() {
    double d = -0.5;
    unsigned long long *ptr = (unsigned long long*)(void*)&d;

    union U u;
    u.d = d;
    u.ull;

    union U2 u2;
    u2.d = d;

    printf("%lld %lld\n",  *ptr, u.ull);

    printf("%llu %llu %llu\n",
           (long long unsigned)u2.bfd.s,
           (long long unsigned)u2.bfd.e,
           (long long unsigned)u2.bfd.m);

//    char c[4096];
//    generate(c)();
}