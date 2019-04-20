section .text
    global  _ft_strlen

_ft_strlen:
    push    rbp
    mov     rbp, rsp

    mov     rcx, -1
    xor     al, al
    cld
    repne   scasb

    not     rcx
    lea     rax, [rcx - 1]

    leave
    ret
