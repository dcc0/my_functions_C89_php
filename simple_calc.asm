; Простейший калькулятор для сложения двух чисел, взятых из аргументов
; Команда запуска
; nasm -f elf32 1.asm; ld -m elf_i386 -s -o 1 1.o; ./1 1 2
section .text

global _start           ;must be declared for using gcc

_start:                 ;tell linker entry point
push ebp                ; Работа со стеком
mov ebp, esp
push    esi             ; Кладём esi на стек

 mov esi, esp[12]    ; Вынимаем из стека строку с аргуметом и кладём в esi
   mov ecx, 4        ; Для первого аргумента - символа
   mov bl, [esi+ecx] ; Кладём в ebx, именно в bl, содержимое стека со смещением  до символа 4
   sub bl, '0'       ; Вычитаем из bl 0
   mov ecx, 6        ; Кладём второй аргумент
   add bl, [esi+ecx] ; Складываем

    mov     [sum], ebx ;Кладём результат в sum
    mov     ecx, sum   ; Кладём sum в ecx для вывода

    mov     edx, 2
    mov     ebx, 1          ;file descriptor (stdout)
    mov     eax, 4          ;system call number (sys_write)
    int     0x80            ;call kernel

    mov     eax, 1          ;system call number (sys_exit)
    int     0x80            ;call kernel

section .data
 	sum db 4;
