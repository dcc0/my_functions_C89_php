;Преобразование строки из символов в число (работа со стеком через eax)
;Взят https://asmtutor.com/#lesson16 (Спасибо участникам wasm.in за подсказку)
;Отредактирован и максимально сокращён by dcc0 (2023)
;Данный скрипт является только примером для изучения
;Команда запуска
;nasm -f elf32 7.asm; ld -m elf_i386 -s -o 7 7.o; ./7 123

section .text
global _start             ;must be declared for using gcc
_start:

    pop  ecx            ; first value on the stack is the number of arguments
    pop edx             ; second value on the stack is the program name (discarded when we initialise edx)
    pop eax             ; Здесь будет результат

    mov     esi, eax        ; move pointer in eax into esi (our number to convert)
    mov     eax, 0          ; initialise eax with decimal value 0
    mov     ecx, 0          ; Счётчик цикла
lp3:
    xor     ebx, ebx        ; Обнулим ebx
    mov     bl, [esi+ecx]   ; Запишем в bl новое значение из строки. Пишем именно в bl
    sub     bl, 48          ; convert ebx register's lower half to decimal representation of ascii value
    add     eax, ebx        ; add ebx to our interger value in eax
    mov     ebx, 10         ; move decimal value 10 into ebx. Умножим на 10
    mul     ebx             ; Само умножение
     inc     ecx            ; Инкремент
     cmp ecx, 3             ; Условие выхода
jne lp3

                            ; Делим eax на 10 в конце, чтобы удалить лишний разряд
    mov     ebx, 10         ; move decimal value 10 into ebx
    div     ebx
								            ;Вывод через деление
mov edi, 6                  ;Счётчик
loop:                          ;Начало цикла
        dec edi                ;Декремент, чтобы  записать все значения остатка в stroka
        mov ebx, 10            ;Делитель. Запишем  в цикл, чтобы вернуть ему значение на новой итерации
        xor edx, edx                ;Обнулим остаток
        div ebx                     ;Делим (edx,eax)/ebx = eax, edx
        add edx, 30h                ;Добавим в остаток 0, равносильно add edx, '0'
        mov  [result + edi], dl     ;Пишем в строку остаток в обратном порядке.
        cmp edi,  0                 ;Выходим
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
