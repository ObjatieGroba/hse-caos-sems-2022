    .global main
main:
    movl $42, %eax
    addl $1, %eax
    call writei32
    call finish

    jmp label
label:

    cmp %eax, %ebx  /// sub
    test %eax, %eax   /// and
