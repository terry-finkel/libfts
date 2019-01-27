section .text
    global  _ft_strdup
    extern  _ft_strlen
    extern  _malloc

_ft_strdup:
    push    rbp
    mov     rbp, rsp

    push    rdi
    call    _ft_strlen
    inc     rax
    push    rax

    mov     rdi, rax
    call    _malloc

    test    rax, rax
    jz      .end

    pop     rcx
    pop     rsi
    mov     rdi, rax
    rep     movsb

.end:
    leave
    ret