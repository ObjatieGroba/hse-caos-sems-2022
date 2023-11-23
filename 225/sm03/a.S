    .global func
func:
    // enter 0, 0
    pushl %ebp
    movl %esp, %ebp

    subl $8, %esp
    movl $1, 4(%esp)  // x
    movb $1, 8(%esp)  // b

    movl $1, -4(%ebp)  // x
    movb $1, 0(%ebp)  // b

    subl $4, %esp
    movl $1, 8(%esp)  // x
    movb $1, 12(%esp)  // b

    movl $1, -4(%ebp)  // x
    movb $1, 0(%ebp)  // b

    call other_func
    // может попортить eax ecx edx

    // leave
    movl %ebp, %esp
    popl %ebp
    ret

    .data
    .skip 128
