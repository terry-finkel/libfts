section .text
    global  _ft_isdigit

_ft_isdigit:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    cmp     rdi, '0'
    jl      .end
    cmp     rdi, '9'
    jg      .end
    inc     rax

.end:
    leave
    ret