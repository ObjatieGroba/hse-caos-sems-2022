    .global func
func:
    // enter
    push %ebp
    mov %esp, %ebp

    subl $12, %esp  // X, Y, Z
    movl 8(%esp), ...  // X
    movl -4(%ebp), ...  // X
    ...
    subl $12, %esp  // A, B, C
    movl 20(%esp), ...  // X
    movl -4(%ebp), ...  // X
    ...

    // addl $24, %esp
    mov %ebp, %esp
    pop %ebp


