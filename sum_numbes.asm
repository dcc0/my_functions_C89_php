section .data
        sum db  4
section .text

global _start             ;must be declared for using gcc

_start:                     ;tell linker entry point
    mov     ecx, '3'
    add     ecx, '4'
    sub    ecx, '0'

    mov     [sum], ecx
    mov     ecx, sum

    mov     edx, 1
    mov     ebx, 1          ;file descriptor (stdout)
    mov     eax, 4          ;system call number (sys_write)
    int     0x80              ;call kernel

    mov     eax, 1          ;system call number (sys_exit)
    int     0x80            ;call kernel
