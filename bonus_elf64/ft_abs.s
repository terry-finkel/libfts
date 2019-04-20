section .text
    global  ft_abs

ft_abs:
    push    rbp
    mov     rbp, rsp

    mov     rax, rdi
    and     edi, 0x80000000
    jz      .end
    not     eax
    inc     eax

.end:
    leave
    ret
