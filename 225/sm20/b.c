#include "unistd.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("a\n");
    fork();
    printf("b\n");
}
