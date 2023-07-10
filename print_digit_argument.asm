; Вывод числового аргумента командной строки (nasm)
; Команда запуска
; nasm -f elf32 1.asm; ld -m elf_i386 -s -o 1 1.o; ./1 8 3
section .text
global _start             ;must be declared for using gcc

_start:                     ;tell linker entry point
push ebp                ; работа со стеком
mov  ebp, esp

        mov  eax, ebp[12]    ;читаем адрес стека, в котором хранится первый аргумент
        mov [string], eax ;пишеи его в строку
		mov ecx, string[0]   ; пишем строку для вывода
		mov     edx, 2        ;длина  выводимой строки
		mov     ebx, 1        ;file descriptor (stdout)
		mov     eax, 4        ;system call number (sys_write)
		int     0x80            ;call kernel

		mov     eax, 1        ;system call number (sys_exit)
		int     0x80            ;call kernel

section .data
 	string db 4; строка в 4 байта
