section .text
    global  _ft_isprint

_ft_isprint:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    cmp     rdi, 32
    jl      .end
    cmp     rdi, 126
    jg      .end
    inc     rax

.end:
    leave
    ret
