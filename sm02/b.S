    .global main
    .text
main:
    mov $A, %eax
    movl $3, (%eax)
    xor %eax, %eax
    ret

    .data
A:  .int 0
