    .global main
main:

loop_b:
    call readi32
    call writei32
    test %eax, %eax
    jnz loop_b

    call finish
