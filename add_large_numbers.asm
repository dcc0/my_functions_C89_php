;Сложение многозначных чисел и вывод
; nasm -f elf32 1.asm; ld -m elf_i386 -s -o 1 1.o; ./1 1 2 -
section .text


global _start             ;must be declared for using gcc
_start:                         ;tell linker entry point
 mov eax, '12345'     ; Пишем первое число в eax
 mov ebx, '11111'       ;Пишем второе в ebx
 add eax, ebx            ; Добавим в eax  ebx
mov esi, '0'               ; 0 в esi для вычитания из разрядов
mov [sum], eax       ; Запишем результат в sum
mov edi, 5               ; Счётчик

loop:                               ; Цикл
 dec edi                          ; Декремент (счётчик цикла)
    sub [sum +edi], esi  ; Вычитаем 0 из каждого разряда, чтобы вывести в десятичном виде
cmp  edi, 0                     ; Сравним с 0
jne loop                          ; Выход из цикла

   mov ecx, sum
    mov     edx, 5
    mov     ebx, 1          ;file descriptor (stdout)
    mov     eax, 4          ;system call number (sys_write)
    int     0x80               ;call kernel
    mov     eax, 1          ;system call number (sys_exit)
    int     0x80               ;call kernel

section .data
  sum db 4;             ; для хранения вывода
