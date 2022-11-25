    .global main
    .text
main:
    mov A, %eax
    mov %eax, B
    call writei32
    mov $1, %eax
    mov $0xAAAA, %eax
    mov $077, %eax
    mov $0b1101, %eax
    xor %eax, %eax
    ret

    .data
A:  .int 0
B:  .int 4
