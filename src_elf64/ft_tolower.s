section .text
    global  ft_tolower

ft_tolower:
    mov     rax, rdi
    cmp     rax, 'A'
    jl      .end
    cmp     rax, 'Z'
    jg      .end
    or      rax, 0b100000

.end:
    ret