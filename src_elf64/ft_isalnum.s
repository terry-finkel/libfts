section .text
    global  ft_isalnum
    extern  ft_isalpha
    extern  ft_isdigit

ft_isalnum:
    push    rbp
    mov     rbp, rsp

    call    ft_isalpha
    cmp     rax, 0
    jne     .end
    call    ft_isdigit
    cmp     rax, 0
    jne     .end
    ret

.end:
    mov     rax, 0b1000     ;8

    leave
    ret
