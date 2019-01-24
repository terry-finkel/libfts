section .text
    global  ft_strlen

ft_strlen:
    push    rdi

    mov     rcx, -1
    xor     al, al
    cld
    repne   scasb

    not     rcx
    lea     rax, [rcx - 1]
    pop     rdi
    ret