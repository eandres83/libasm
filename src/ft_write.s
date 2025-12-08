section .text
	global ft_write
	extern __errno_location

ft_write:
	mov rax, 1
	syscall

	cmp rax, 0
	jl .erro ;Jump if Less <=

	ret

.erro:
	neg rax
	mov rdi, rax

	push rdi ;Guardo el valor de rdi para no perderlo

	call __errno_location ;Ahora rax tiene la direccion de memoria de errno

	pop rdi ;Recupero el valor de rdi

	mov [rax], edi ;

	mov rax, -1 ;write siempre devuelve -1 en error
	ret
