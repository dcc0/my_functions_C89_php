;Преобразование строки из двух символов 12 в число 12
;Данный скрипт является только примером для изучения
;Команда запуска
;nasm -f elf32 5.asm; ld -m elf_i386 -s -o 5 5.o; ./5 12

section .text
global _start           ;must be declared for using gcc
_start:
                        ;tell linker entry point
push ebp                ;Работа со стеком
mov ebp, esp
push    esi             ;Кладём esi на стек

 mov esi, esp[12]    ; Вынимаем из стека строку с аргументом и кладём в esi
 mov al, [esi+4] ; Кладём в ebx, именно в bl, содержимое стека со смещением  до символа 4
                            ; Преобразование символа строки осуществляется в несколько  существенных оперций:
                            ; 1) вычитаем 48
                            ; 2) умножаем на число с основанием 10, в зависимости от разряда
                            ; 3) прибавляем предыдущий разряд
                            ; Нужно зациклить все операции, а строку куда-то поместить.
                            ; Также требуется проверять символ на то, что он меньше 48 и больше 57
   sub al, 48         ;Вычитаем 48
   mov ebx, 10        ;Умножаем на 10
   mul ebx            ;Само умножение
   mov ecx, eax       ;Для обмена

   mov al, [esi+5]    ;Кладём в ebx, именно в bl, содержимое стека со смещением  до символа 5
   sub al, 48         ;Вычитаем 48
   mov ebx, 1         ;Умножаем на 1
   mul ebx            ;Умножим
   add ecx, eax       ;Добавим в ecx
   mov eax, ecx       ;Обмен для вывода

mov edi, 6             ;Счётчик

loop:                   ;Начало цикла
        dec edi         ;Декремент, чтобы  записать все значения остатка в stroka
        mov ebx, 10     ;Делитель. Запишем  в цикл, чтобы вернуть ему значение на новой итерации
        xor edx, edx             ;Обнулим остаток
        div ebx                  ;Делим (edx,eax)/ebx = eax, edx
        add edx, 30h             ;Добавим в остаток 0, равносильно add edx, '0'
        mov  [result + edi], dl  ;Пишем в строку остаток в обратном порядке.
        cmp edi,  0              ;Выходим
jne loop

    mov     ecx, result  ;пишем для вывода
    mov     edx, 6       ;длина строки
    mov     ebx, 1       ;file descriptor (stdout)
    mov     eax, 4       ;system call number (sys_write)
    int     0x80         ;call kernel

    mov     eax, 1        ;system call number (sys_exit)
    int     0x80


section .data
          result db   6, 13, 10, 0 ;массив для вывода
