#------------------------------------------------------------------
#
# gcc -c hello.s && ld hello.o && ./a.out
#
#------------------------------------------------------------------
	.global _start

	.text
_start:
	mov $5000000000,%rax
	mov $50000,%ax
	mov $0x32,%al

	#exit(0)
	mov $60,%rax	#systemcall 60 is exit
	xor %rdi,%rdi	#return code 0
	syscall		#invoke operating system to exit
