#include <stdio.h>

int main() {
    int x = 5, y = 3, z;
    asm("mov $3, %%ebx" : : : "%ebx", "%eax", "%ecx", "%edx",
                              "%esi", "%edi", "memory");
    printf("%d\n", x);

    asm("mov %1, %0 \n add %2, %0" :
        "=rm"(z) : "rm"(x), "rm"(y));
    printf("%d\n", z);

    asm("mov %[x], %[z] \n sub %[y2], %[z]" :
        [z]"=rm"(z) : [x]"rm"(x), [y2]"rm"(y));
    printf("%d\n", z);

    asm("mov $2, %%eax" : "=a"(z));  /// z value store in eax

    z = 1;
    int vvv;
    asm("mov %%edx, %%eax\n"
        "mov $2, %%edx\n" : "+d"(z), "=a"(vvv));

    /// vvv == old_z; z == 2

}
