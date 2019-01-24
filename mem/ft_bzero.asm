section .text
    global  ft_bzero

ft_bzero:
    mov     rcx, rsi
    xor     al, al
    rep     stosb

    ret