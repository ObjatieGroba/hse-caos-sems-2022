#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("%d\n", getpid());
    int i;
    scanf("%d", &i);
    char *s = mmap(NULL, 1,
                   PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON,
                   -1, 0);
    printf("%p\n", s);
    scanf("%d", &i);
    s[0] = '1';
    s[16000] = '1';
    munmap(s, 1);
}
