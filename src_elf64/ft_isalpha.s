section .text
    global  ft_isalpha

ft_isalpha:
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
    or      rax, 0b10000000000   ;1024
    leave
    ret

.innercheck:
    cmp     rdi, 'a'
    jge     .true

.false:
    leave
    ret
