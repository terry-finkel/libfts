default rel
NULL_LEN    equ 6
SYS_WRITE   equ 0x2000004

section .data
    null    db "(null)", 0
    nl      db 0x0a, 0

section .text
    global  _ft_puts
    extern  _ft_strlen

_ft_puts:
    push    rbp
    mov     rbp, rsp

    cmp     rdi, 0
    jz      .null
    push    rdi
    call    _ft_strlen
    pop     rsi
    mov     rdx, rax
    jmp     .write

.null:
    lea     rsi, [null]
    mov     rdx, NULL_LEN

.write:
    mov     rdi, 1
    mov     rax, SYS_WRITE
    syscall
    jc      .dead

    mov     rdx, 1
    lea     rsi, [nl]
    mov     rax, SYS_WRITE
    syscall
    jc      .dead

    mov     rax, 10
    jmp     .end

.dead:
    mov     rax, -1

.end:
    leave
    ret
