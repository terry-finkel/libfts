section .text
    global  ft_memcpy

ft_memcpy:
    push    rbp
    mov     rbp, rsp

    mov     rax, rdi
    mov     rcx, rdx
    cld
    rep     movsb

    leave
    ret
