section .text
    global ft_memset

ft_memset:
    push    rbp
    mov     rbp, rsp

    push    rdi
    mov     rax, rsi
    mov     rcx, rdx
    cld
    rep     stosb

    pop     rax
    leave
    ret
