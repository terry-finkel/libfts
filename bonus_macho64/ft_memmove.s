default rel

section .bss
    buffer  resb 1

section .text
    global  _ft_memmove

_ft_memmove:
    push    rbp
    mov     rbp, rsp

    mov     rax, rdi
    lea     rdi, [buffer]
    mov     rcx, rdx
    cld
    rep     movsb

    mov     rdi, rax
    lea     rsi, [buffer]
    mov     rcx, rdx
    cld
    rep     movsb

    leave
    ret
