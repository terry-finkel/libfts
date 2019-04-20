section .text
    global  _ft_memmove

_ft_memmove:
    push    rbp
    mov     rbp, rsp

    ;Check if dst is greater than src
    mov     rax, rdi
    cmp     rdi, rsi
    je      .end
    jb      .cpy

    ;Check if there is overlap
    mov     rcx, rsi
    add     rcx, rdx
    cmp     rdi, rcx
    jae     .cpy

.move:
    mov     rcx, rdx
    dec     rdx
    add     rsi, rdx
    add     rdi, rdx
    std
    rep     movsb
    jmp     .end

.cpy:
    mov     rcx, rdx
    cld
    rep     movsb

.end:
    leave
    ret
