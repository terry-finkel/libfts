section .text
    global  _ft_isalpha

_ft_isalpha:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    cmp     rdi, 'A'
    jl      .false
    cmp     rdi, 'z'
    jg      .false
    cmp     rdi, 'Z'
    jg      .innercheck

.true:
    inc     rax
    leave
    ret

.innercheck:
    cmp     rdi, 'a'
    jge     .true

.false:
    leave
    ret
