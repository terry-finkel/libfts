section .text
    global  ft_toupper

ft_toupper:
    push    rbp
    mov     rbp, rsp

    mov     rax, rdi
    cmp     rax, 'a'
    jl      .end
    cmp     rax, 'z'
    jg      .end
    xor     rax, 0b100000

.end:
    leave
    ret
