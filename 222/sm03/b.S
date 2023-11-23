    .text
    .global func
func:
    push %ebp
    mov %esp, %ebp

    pushl $s
    call printf
    // pushl %eax
    // call exit
    popl %eax

    leave
    ret

    .data
s:  .asciz "ABA\n"
