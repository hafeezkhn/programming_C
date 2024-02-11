#----------------------------------------------------------------------
#
#int add(int x,int y)
#man syscall  rdi,rsi parametr passed rax to be returned
#----------------------------------------------------------------------

	.global add
	.text
add:
	push %rbp
	mov  %rsi,%rax
	mov  %rdi,%rax
	pop %rbp
ret



