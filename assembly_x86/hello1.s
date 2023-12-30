#------------------------------------------------------------------
#
# gcc -c hello.s && ld hello.o && ./a.out
#
#------------------------------------------------------------------
	.global _start

	.text
_start:
	movl $10,%eax
	movl %eax ,8(%rsp)

	#exit(0)
	mov $60,%rax	#systemcall 60 is exit
	xor %rdi,%rdi	#return code 0
	syscall		#invoke operating system to exit

