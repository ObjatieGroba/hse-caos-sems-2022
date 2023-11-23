    .global main
    .text
main:
    call readi32
    movl %eax, A
    call process
    call finish

    .global A, B
    .data
A:  .int 0
B:
