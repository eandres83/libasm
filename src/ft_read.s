section .text
	global ft_read
	extern __errno_location

ft_read:
	mov rax, 0

	syscall

	cmp rax, 0
	jl .error

	ret

.error:
	neg rax

	mov rdi, rax

	push rdi

	call __errno_location

	pop rdi;

	mov [rax], edi ;edi es la version de 32 bits de rdi 64 bits
;Si yo intento mov [rax] rdi estaria intentado mover 64 bits a un int que solo caben 32 bits, estaria sobreescribiendo la memoria del vecino.

	mov rax, -1
	ret
