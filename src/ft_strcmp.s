section .text
	global ft_strcmp

ft_strcmp:
	mov rcx, 0

.loop:
	mov al, byte [rdi + rcx]
	mov dl, byte [rsi + rcx]

	cmp al, dl
	jne .fin

	cmp al, 0
	je .equal

	inc rcx
	jmp .loop

.fin:
	movzx rax, al
	movzx rcx, dl
	sub rax, rcx
	ret

.equal:
	mov rax, 0
	ret
