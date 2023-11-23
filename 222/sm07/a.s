	.file	"a.c"
	.text
	.p2align 4
	.globl	func
	.type	func, @function
func:
.LFB23:
	.cfi_startproc
	call	__x86.get_pc_thunk.cx
	addl	$_GLOBAL_OFFSET_TABLE_, %ecx
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ebx
	leal	xxx@GOTOFF(%ecx), %edx
#APP
# 9 "a.c" 1
	nop
movl xxx@GOTOFF(%ecx), %edx
nop

# 0 "" 2
#NO_APP
	movl	xxx@GOTOFF(%ecx), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	addl	%edx, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	func, .-func
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	call	__x86.get_pc_thunk.dx
	addl	$_GLOBAL_OFFSET_TABLE_, %edx
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	pushl	%ebx
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	movl	$42, %ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	leal	xxx@GOTOFF(%edx), %ecx
#APP
# 9 "a.c" 1
	nop
movl xxx@GOTOFF(%edx), %ebx
nop

# 0 "" 2
#NO_APP
	leal	.LC0@GOTOFF(%edx), %eax
	addl	xxx@GOTOFF(%edx), %ebx
	subl	$4, %esp
	pushl	%ebx
	movl	%edx, %ebx
	pushl	%eax
	pushl	$1
	call	__printf_chk@PLT
	addl	$16, %esp
	leal	-8(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.globl	yyy
	.bss
	.align 4
	.type	yyy, @object
	.size	yyy, 4
yyy:
	.zero	4
	.globl	xxx
	.align 4
	.type	xxx, @object
	.size	xxx, 4
xxx:
	.zero	4
	.section	.text.__x86.get_pc_thunk.dx,"axG",@progbits,__x86.get_pc_thunk.dx,comdat
	.globl	__x86.get_pc_thunk.dx
	.hidden	__x86.get_pc_thunk.dx
	.type	__x86.get_pc_thunk.dx, @function
__x86.get_pc_thunk.dx:
.LFB25:
	.cfi_startproc
	movl	(%esp), %edx
	ret
	.cfi_endproc
.LFE25:
	.section	.text.__x86.get_pc_thunk.cx,"axG",@progbits,__x86.get_pc_thunk.cx,comdat
	.globl	__x86.get_pc_thunk.cx
	.hidden	__x86.get_pc_thunk.cx
	.type	__x86.get_pc_thunk.cx, @function
__x86.get_pc_thunk.cx:
.LFB26:
	.cfi_startproc
	movl	(%esp), %ecx
	ret
	.cfi_endproc
.LFE26:
	.ident	"GCC: (Ubuntu 13.2.0-6ubuntu1) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
