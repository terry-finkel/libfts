section .text
    global  ft_isprint

ft_isprint:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    cmp     rdi, 32
    jl      .end
    cmp     rdi, 126
    jg      .end
    mov     rax, 16384 ;16384

.end:
    ret
