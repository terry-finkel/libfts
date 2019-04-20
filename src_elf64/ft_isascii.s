section .text
    global  ft_isascii

ft_isascii:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    cmp     rdi, 127
    jg      .end
    inc     rax

.end:
    leave
    ret
