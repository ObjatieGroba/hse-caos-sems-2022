    // xor %eax, %eax
    addl $1, %eax
    addl $1, %ecx

    testl %eax, %eax
    jz zero
    jnz non-zero

non-zero:
    ...
    jmp continue

zero:
    ...
    jmp continue

continue:
    xorl %ebx, %ebx