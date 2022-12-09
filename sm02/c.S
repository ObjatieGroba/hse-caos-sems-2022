    .global main
    .text
main:
    jmp kek
    xor %eax, %eax
    ret

    movl .-3, %eax
    movl $' ', %eax

    .data
kek:
    xor %eax, %eax
    ret
Arr: .skip 100500
