// float func(float *a, size_t n); // n % 4 == 0
    .text
    .global func
func:
    push %ebp
    movl %esp, %ebp

    movl 8(%ebp), %eax   // a
    movl 12(%ebp), %ecx  // n

    movaps %eax, %xmm0

loop:
    subl $4, %ecx
    cmp $0, %ecx
    jz end
    addl $16, %eax
    // movups %eax, %xmm1
    // addps %xmm1, %xmm0
    addps %eax, %xmm0
    jmp loop
end:

    haddps %xmm0, %xmm0
    haddps %xmm0, %xmm0

    // dec %esp ...
    movss %xmm0, -4(%esp)
    flds -4(%esp)  // %st(0)
    // inc %esp back

    leave
    ret