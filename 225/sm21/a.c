#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("%d\n", getpid());
    int i;
    scanf("%d", &i);
    void * ptr = mmap(NULL, 1,
         PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON,
         -1 , 0);
    printf("%p\n", ptr);
    scanf("%d", &i);
    char * c = ptr;
    c[0] = 1;
    c[1] = 'a';
    printf("%c\n", c[1]);
    scanf("%d", &i);
//    c[4096] = 1;
}
