section .text
    global  _ft_memcmp

_ft_memcmp:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax

.loop:
    cmp     rdx, 0
    jz      .end

    cmpsb
    jne     .diff

    dec     rdx
    jmp     .loop

.diff:
    movzx   rax, byte[rdi - 1]
    movzx   rdx, byte[rsi - 1]
    sub     rax, rdx

.end:
    leave
    ret