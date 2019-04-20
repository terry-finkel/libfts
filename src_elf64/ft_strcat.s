section .text
    global  ft_strcat
    extern  ft_strlen

ft_strcat:
    push    rbp
    mov     rbp, rsp
    push    rdi

    xor     al, al
    mov     rcx, -1
    cld
    repne   scasb

    dec     rdi
    push    rdi
    mov     rdi, rsi
    call    _ft_strlen

    mov     rcx, rax
    inc     rcx
    pop     rdi
    rep     movsb

    pop     rax
    leave
    ret
