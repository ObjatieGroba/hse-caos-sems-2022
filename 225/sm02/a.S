    .text
    //.global main
//main:
    //pushl s
    //call puts
    //call finish

    .global func, X, Y
func:
    movl X, %eax
    movl %eax, Y
    ret

s:  .asciz "ABA"

    .data
A:  xor %eax, %eax
X:  .int 0
Y:  .int 0
