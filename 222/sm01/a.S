    .global main
main:
    xorl %ecx, %ecx
    mov $42, %eax
    add %eax, %ecx
    call writei32
    mov %ecx, %eax
    call writei32

metka:
    subl $42, %eax
    jz end
    jmp metka

    pushl %eax
    popl %ebx

end:
    call finish
