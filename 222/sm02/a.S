    .global main
    .text
main:
    mov $42000, %eax
    call writei32
    call finish

    add $A, %eax
    addl A, %eax
    add %eax, A

    .data
A:  call writei32
