section .bss
    buffer  resb 1

section .text
    global  ft_memmove

ft_memmove:
    mov     rax, rdi
    mov     rdi, buffer
    mov     rcx, rdx
    rep     movsb

    mov     rdi, rax
    mov     rsi, buffer
    mov     rcx, rdx
    rep     movsb

    ret