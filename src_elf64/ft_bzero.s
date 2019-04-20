section .text
    global  ft_bzero

ft_bzero:
    push    rbp
    mov     rbp, rsp

    mov     rcx, rsi
    xor     al, al
    cld
    rep     stosb

    leave
    ret
