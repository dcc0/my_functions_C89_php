; Умножение многозначных чисел. Вывод через деление и запись в массив result
section .text

global _start               ;must be declared for using gcc
_start:                     ;tell linker entry point

    mov     eax, 125 ;пишем 5
    mov     ebx, 125 ;пишем 3
    mul     ebx         ;умножаем, результат в регистрах edx:eax

    mov edi, 6          ;счётчик

loop:                           ;Начало цикла
        dec edi                 ;Декремент, чтобы  записать все значения остатка в stroka
        mov ebx, 10             ;Делитель. Запишем  в цикл, чтобы вернуть ему значение на новой итерации
        xor edx, edx            ;Обнулим остаток
        div ebx                 ;Делим (edx,eax)/ebx = eax, edx
        add edx, 30h            ;Добавим в остаток 0, равносильно add edx, '0'
        mov  [result + edi], dl ;Пишем в строку остаток в обратном порядке.
        cmp edi,  0             ;Выходим
jne loop

    mov     ecx, result     ;пишем для вывода
    mov     edx, 6          ;длина строки
    mov     ebx, 1          ;file descriptor (stdout)
    mov     eax, 4          ;system call number (sys_write)
    int     0x80            ;call kernel

    mov     eax, 1          ;system call number (sys_exit)
    int     0x80


section .data
          result db   6, 13, 10, 0 ;массив для вывода
