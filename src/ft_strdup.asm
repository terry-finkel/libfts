section .text
    global  ft_strdup
    extern  ft_strlen
    extern  malloc

ft_strdup:
    push    rdi
    call    ft_strlen
    push    rax

    mov     rdi, rax
    call    malloc wrt ..plt

    cmp     rax, 0
    jz      .end

    pop     rcx
    pop     rsi
    mov     rdi, rax
    rep     movsb

.end:
    ret