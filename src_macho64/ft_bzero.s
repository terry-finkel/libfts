section .text
    global  _ft_bzero

_ft_bzero:
    push    rbp
    mov     rbp, rsp

    mov     rcx, rsi
    xor     al, al
    cld
    rep     stosb

    leave
    ret
