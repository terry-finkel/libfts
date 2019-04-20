section .text
    global  ft_isdigit

ft_isdigit:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    cmp     rdi, '0'
    jl      .end
    cmp     rdi, '9'
    jg      .end
    or      rax, 0b100000000000  ;2048

.end:
    leave
    ret
