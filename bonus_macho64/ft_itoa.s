default rel

section .data
    buffer  times 11 db 0

section .text
    global  _ft_itoa
    extern  _ft_strdup

_ft_itoa:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx                    ;initialize counter
    xor     r9, r9                      ;set neg flag to 0
    mov     eax, edi                    ;move number in RAX for DIV instruction
    push    rbx                         ;save RBX
    mov     ebx, 10

.check_negative:
    and     edi, 0x80000000
    lea     rdi, [buffer]
    jz      .divide                     ;number is positive, proceed to main loop
    not     eax                         ;else
    inc     eax                         ;compute absolute value with binary complement
    inc     r9                          ;set neg flag

.divide:
    xor     edx, edx
    div     ebx
    add     edx, 48                     ;convert int to char
    push    rdx
    inc     rcx
    cmp     eax, 0
    jnz     .divide

.check_neg_flag:
    cmp     r9, 1
    jne     .buff_string
    mov     byte[rdi], '-'

.buff_string:
    pop     rdx
    mov     byte[rdi + r9], dl
    dec     rcx
    inc     r9
    cmp     rcx, 0
    jnz     .buff_string
    pop     rbx

.dup:
    mov     byte[rdi + r9], 0
    call    _ft_strdup                  ;copy buffer string in memory and return pointer

    leave
    ret
