section .text
    global ft_memset

ft_memset:
    push    rdi
    mov     rax, rsi
    mov     rcx, rdx
    rep     stosb

    pop     rax
    ret
