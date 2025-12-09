section .text
	global ft_list_push_front
	extern malloc

ft_list_push_front:
	push rdi
	push rsi
	push rdx

	mov rdi, 16 ; sizeof(t_list) son 16 bytes, 8 bytes del void* y otros 8 del t_list *
	call malloc wrt ..plt

	cmp rax, 0
	je .error

	pop rdx
	pop rsi
	pop rdi

	mov [rax], rsi ;Estoy poniendo el void *data en los primeros 8 bytes

	mov rcx, [rdi] ;Como es un t_list **, no puedo mover datos en RAM a otra direccion de RAM
	mov [rax + 8], rcx ;por lo que tienes que utilizar una variable temporal

	mov [rdi], rax ;Necesito que la cabeza de la lista sea el nuevo nodo

	ret

.error:
	pop rdx
	pop rsi
	pop rdi

	ret
