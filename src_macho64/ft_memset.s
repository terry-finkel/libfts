section .text
    global _ft_memset

_ft_memset:
    push    rbp
    mov     rbp, rsp

    push    rdi
    mov     rax, rsi
    mov     rcx, rdx
    rep     stosb

    pop     rax
    leave
    ret
