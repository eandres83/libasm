section .text
	global ft_list_sort

ft_list_sort:
	push r12
	push r13
	push r14
	push rbx
	mov r12, rdi
	mov r13, rsi

.main_loop:
	mov r14, 0
	mov rbx, [r12]

.loop:
	cmp rbx, 0
	je .check_swap

	mov rdx, [rbx + 8]
	cmp rdx, 0
	je .check_swap

	mov rdi, [rbx]
	mov rsi, [rdx]

	call r13

	cmp eax, 0
	jg .swap

	mov rbx, [rbx + 8]
	jmp .loop

.swap:
	mov rdx, [rbx + 8]

	mov r8, [rbx]
	mov r9, [rdx]

	mov [rbx], r9
	mov [rdx], r8

	mov r14, 1
	mov rbx, [rbx + 8]
	jmp .loop

.check_swap:
	cmp r14, 1
	je .main_loop

.end:
	pop rbx
	pop r14
	pop r13
	pop r12
	ret

