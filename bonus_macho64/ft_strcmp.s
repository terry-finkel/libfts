section .text
    global  _ft_strcmp

_ft_strcmp:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax

.loop:
    cmpsb
    jne     .diff

    cmp     byte[rdi - 1], 0
    jz      .end

    jmp     .loop

.diff:
    movzx   rax, byte[rdi - 1]
    movzx   rdx, byte[rsi - 1]
    sub     rax, rdx

.end:
    leave
    ret