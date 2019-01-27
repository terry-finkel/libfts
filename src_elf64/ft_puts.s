SYS_WRITE   equ 1

section .data
    nl      db 0x0a

section .text
    global  ft_puts
    extern  ft_strlen

ft_puts:
    call    ft_strlen
    push    rax

    mov     rdx, rax
    mov     rsi, rdi
    mov     rdi, 1
    mov     rax, SYS_WRITE
    syscall

    mov     rdx, 1
    mov     rsi, nl
    mov     rax, SYS_WRITE
    syscall

    pop     rax
    inc     rax
    ret