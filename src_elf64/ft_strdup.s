section .text
    global  ft_strdup
    extern  ft_strlen
    extern  malloc

ft_strdup:
    push    rbp
    mov     rbp, rsp

    push    rdi
    call    ft_strlen
    inc     rax
    push    rax

    mov     rdi, rax
    call    malloc wrt ..plt

    cmp     rax, 0
    jz      .end

    pop     rcx
    pop     rsi
    mov     rdi, rax
    cld
    rep     movsb

.end:
    ret
