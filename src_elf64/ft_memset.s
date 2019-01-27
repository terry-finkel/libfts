section .text
    global ft_memset

ft_memset:
    mov     rax, rsi
    mov     rcx, rdx
    rep     stosb

    mov     rdi, rax
    ret