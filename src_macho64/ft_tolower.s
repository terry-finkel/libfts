section .text
    global  _ft_tolower

_ft_tolower:
    push    rbp
    mov     rbp, rsp

    mov     rax, rdi
    cmp     rax, 'A'
    jl      .end
    cmp     rax, 'Z'
    jg      .end
    or      rax, 0b100000

.end:
    leave
    ret
