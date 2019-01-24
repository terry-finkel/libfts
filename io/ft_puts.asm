SYS_WRITE   equ 1

section .text
    global ft_puts
    extern ft_strlen

ft_puts:
    call    ft_strlen

    mov     rdx, rax
    inc     rdx
    mov     rsi, rdi
    mov     byte[rsi + rax], 0x0a
    mov     byte[rsi + rax + 1], 0
    mov     rdi, 1
    push    rax
    mov     rax, SYS_WRITE
    syscall

    pop     rax
    mov     byte[rsi + rax], 0
    mov     rax, rdx
    ret