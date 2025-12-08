section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	extern __errno_location

ft_strdup:
	push rdi

	call ft_strlen

	inc rax
	mov rdi, rax

	call malloc wrt ..plt

	cmp rax, 0
	je .error

	mov rdi, rax
	pop rsi

	call ft_strcpy
	ret

.error:
	pop rdi
	mov rax, 0
	ret
