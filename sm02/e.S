    .global process
    .global main
process:
    nop
    nop
    nop
    // ret // pop %eip (но так низя)

func:
    call process
    call process
    call process
    ret

main:
    call func
    xor %eax, %eax
    ret
