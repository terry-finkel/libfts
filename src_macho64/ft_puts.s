default rel
SYS_WRITE   equ 0x2000004

section .data
    nl      db 0x0a

section .text
    global  _ft_puts
    extern  _ft_strlen

_ft_puts:
    push    rbp
    mov     rbp, rsp
    call    _ft_strlen

    mov     rdx, rax
    mov     rsi, rdi
    mov     rdi, 1
    mov     rax, SYS_WRITE
    syscall

    mov     rdx, 1
    lea     rsi, [nl]
    mov     rax, SYS_WRITE
    syscall

    mov     rax, 10
    leave
    ret