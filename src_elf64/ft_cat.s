SYS_READ    equ 0
SYS_WRITE   equ 1

section .bss
    buffer  resb 0x1000             ;4096

section .text
    global  ft_cat

ft_cat:
    push    rbp
    mov     rbp, rsp

    push    r15
    push    r14
    mov     r15, buffer
    mov     r15, rdi

.loop:
    mov     rsi, buffer
    mov     rdx, 0xfff
    mov     rax, SYS_READ
    syscall                         ;read buffer_size bytes
    jc      .end                    ;exit if read failed

    mov     r14, rax                ;save count

    mov     rdi, 1
    mov     rsi, buffer
    mov     rdx, rax
    mov     rax, SYS_WRITE
    syscall                         ;print buffer

    cmp     r14, 0xfff
    jl      .end                    ;if count is lesser then 4095, EOF was reached

    mov     rdi, r15                ;set RDI to file descriptor before looping
    jmp     .loop

.end:
    pop     r14
    pop     r15
    leave
    ret
