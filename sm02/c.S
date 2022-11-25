    .global main
    .text
main:
    jmp kek
    xor %eax, %eax
    ret

    .data
kek:
    xor %eax, %eax
    ret
Arr: .skip 100500
