#include <dlfcn.h>
#include <stdio.h>

typedef int (*Func)(int);

int main() {
//    printf("%d\n", func(1));
    void *h = dlopen("liblib.so", RTLD_LAZY);
    Func func = dlsym(h, "func");
    printf("%p\n", func);
    printf("%d\n", func(1));
    dlclose(h);
}