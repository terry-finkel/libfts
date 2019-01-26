section .text
    global  ft_abs

ft_abs:
    mov     rax, rdi
    and     edi, 0x80000000
    jz      .end
    not     eax
    inc     eax

.end:
    ret