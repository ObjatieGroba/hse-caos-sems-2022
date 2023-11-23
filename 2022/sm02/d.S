    .global main
    .text
main:
    // movl $4, Arr + 16 /// 5th elem
    movl $Arr, %eax
    movl $4, 16(%eax)

    movl $4, %ebx
    movl $100500, (%eax, %ebx, 4)

    xor %eax, %eax
    movl $4, Arr(%eax, %ebx, 4) // *(address) = 4

    lea Arr(%eax, %ebx, 4), %eax // %eax = address of ...

    // movl $4, offset(c)(array_begin(r), index(r), 1/2/4/8 elem size(c))
    //  offset + array_begin + index * size
    // (array_begin(r))
    // offset(c)(array_begin(r))
    // offset(c)(index(r), 1/2/4/8)  -- not work


    xor %eax, %eax
    ret

    .data
Arr: .skip 100500 /// Array of int
