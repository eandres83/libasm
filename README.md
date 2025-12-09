# Libasm - The Art of Assembly

![Language](https://img.shields.io/badge/language-x86__64_Assembly-red)
![Syntax](https://img.shields.io/badge/syntax-Intel-lightgrey)
![Compiler](https://img.shields.io/badge/compiler-NASM-green)
![Status](https://img.shields.io/badge/build-passing-brightgreen)

<br />
<p align="center">
  <h3 align="center">Recreating the C Standard Library in x86-64 Assembly</h3>
</p>

## 🗣️ About The Project

**Libasm** is a project at **42 School** designed to demystify the low-level operations of the CPU. The goal is to rewrite standard C library functions (`libc`) using **pure x86-64 Assembly (Intel Syntax)**.

This project requires a deep understanding of the **System V AMD64 ABI** calling convention, manual stack management, direct system calls (syscalls), and register manipulation (`rax`, `rdi`, `rsi`, etc.).

### 🎯 Key Engineering Concepts
- **Registers & Memory:** Manual management of volatile/non-volatile registers and pointer arithmetic.
- **Syscalls:** Interacting directly with the kernel for I/O operations (`write`, `read`) without C wrappers.
- **Errno Handling:** Manually handling error codes returned by the kernel (negative values in `rax`) and setting the external `errno` variable via `__errno_location`.
- **Calling Convention:** Strictly following the ABI (arguments in `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`).

---

## 🛠️ Mandatory Part: String & I/O Manipulation

I have implemented the following functions optimizing for instructions and register usage:

| Function | Description | Key Assembly Logic |
| :--- | :--- | :--- |
| **ft_strlen** | Calculate string length. | Iterates using `cmp byte [rdi + rax], 0` until null terminator is found. |
| **ft_strcpy** | Copy a string. | Byte-by-byte copy from source (`rsi`) to dest (`rdi`) using `al`/`dl` partial registers. |
| **ft_strcmp** | Compare two strings. | Performs subtraction of unsigned bytes (`movzx`) to return the lexical difference. |
| **ft_write** | Write to a file descriptor. | Invokes `syscall` ID 1. Handles errors by negating `rax` and calling `__errno_location`. |
| **ft_read** | Read from a file descriptor. | Invokes `syscall` ID 0. Similar error handling to write. |
| **ft_strdup** | Duplicate a string. | Calls `malloc` (external), checks for NULL, and then calls `ft_strcpy`. |

---

## 🌟 Bonus Part: Linked Lists in Assembly

Currently working on the implementation of Linked List manipulation in Assembly. This involves understanding data structure alignment and memory offsets manually.

**The Struct:**
~~~c
typedef struct s_list {
    void *data;          // Offset 0
    struct s_list *next; // Offset 8 (on 64-bit systems)
} t_list;
~~~

### Functions in Progress:

#### 1. ft_list_size
* **Logic:** Traverses the linked list by following the `next` pointer.
* **Assembly Challenge:** Loading the pointer at `[rdi + 8]` (the `next` element) repeatedly into `rdi` until it is `NULL` (0), while incrementing a counter in `rax`.

#### 2. ft_list_push_front
* **Logic:** Adds a new element to the beginning of the list.
* **Assembly Challenge:**
    1. Call `malloc` (size of `t_list`).
    2. Dereference the new pointer to set `new->data` (Offset 0).
    3. Set `new->next` (Offset 8) to point to the current head (`begin_list`).
    4. Update the head pointer to the new element.

---

## ⚙️ Technical Highlights

### Error Handling (The `__errno_location` dance)
In C, `write` returns -1 and sets `errno`. In Assembly, the syscall returns a negative error code in `rax`. To replicate libc behavior:

~~~nasm
cmp rax, 0
jl .error        ; If rax < 0, it's an error

.error:
    neg rax              ; Make error code positive
    mov rdi, rax         ; Save code to rdi
    push rdi             ; Align stack / save register
    call __errno_location wrt ..plt ; Get address of errno variable
    pop rdi              ; Restore error code
    mov [rax], edi       ; Write error code to address returned by function
    mov rax, -1          ; Return -1 as per POSIX standard
    ret
~~~

---

## 🚀 Installation & Usage

### Requirements
* `nasm` compiler
* `gcc` or `clang`
* `make`

### Build the Library
~~~bash
git clone [https://github.com/eandres83/libasm.git](https://github.com/eandres83/libasm.git)
cd libasm
make
~~~
This generates `libasm.a`.

### Testing
To test the functions, compile your C program linking against the library:

~~~bash
# Example compilation
gcc main.c -L. -lasm -o tester
./tester
~~~

---
*Developed by Eleder Andres as part of the Assembly curriculum.*
