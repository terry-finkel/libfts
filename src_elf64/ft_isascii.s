section .text
    global  ft_isascii

ft_isascii:
    xor     rax, rax
    cmp     rdi, 127
    jg      .end
    inc     rax

.end:
    ret