section .text
    global ft_bzero

ft_bzero:
    cmp     rsi, 0
    jz      .finish
    mov     byte[rdi + rsi - 1], 0
    dec     rsi
    jmp     ft_bzero

.finish:
    ret