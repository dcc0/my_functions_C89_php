; Найдено здесь (Found here): https://mrempy.medium.com/assembly-16-bits-printing-strings-a114c72f6e43
; 1) Добавлена спящая кошка, которая появляется по нажатию клавиши 0. By dcc0 30.12.2022
; 2) Добавлен цвет фона
; 4) Задержка вывода слова Loading (анимация).
; 5) Добавлено обновление экрана
; 6) Добавлена кошка с открытыми глазами
; Программа собрана из разных примеров, найденных в Интернете
; Команда компиляции и запуска:
; nasm cat_on_boot.asm -o cat_on_boot.bin;  qemu-system-x86_64 cat_on_boot.bin
ORG 0x7C00    ; Смещение (в загрузочный сектор - MBR)
BITS 16             ; 16 битный режим
       mov   ax,3 ; Загрузим новый цвет в видеопамять
       int 0x10
       push 0xb800
       pop   es
       xor   di,di      ;// ES:DI = указатель на в/буфер (приёмник для stosw)
       mov   cx,80*25   ;// кол-во символов в буфере
       mov   ax,0x7020  ;// атрибут = цвет фона(7), цвет текста(0), символ(20=пробел)
       rep   stosw      ;// записать АХ в ES:DI, по длине СХ
       mov dx, 22000 ; Задержка с помощью цикла
       mess: ;  Метка для вывода сообщений
       call PrintStr ; Вызываем вывод на экран, для каждого сообщения (функция)
        ;cmp di, msg_7 ; Последнее сообщение
;С помощью такого цикла можно реализовать анимацию
; Далее реализация паузы перед выводом разных сообщений
delay_loop:
         dec dx
         int 1ah ; Вызов таймера. Доступ к системным часам биос
         cmp  dx, 21000
         mov di, msg; Загружаем название
         jz mess ;Прыгаем в цикл вывода
         cmp  dx, 18000
         mov di, msg_2
         jz mess ;
         cmp  dx, 15000
         mov di, msg_3
          jz mess
         cmp  dx, 12000
         mov di, msg_4
          jz mess
         cmp  dx, 9000
         mov di, msg_5
          jz mess
          cmp  dx, 6000
         mov di, msg_6
          jz mess
          cmp  dx, 3000
         mov di, msg_7
          jz mess
         cmp  dx, 0 ; Выход из цикла
jne  delay_loop
jmp if_char
second:
        mov ax, 03 ; Обновим экран
        int 10h
        mov di, cat_2      ; char* di = msg;
        call PrintStr         ; PrintStr(si);
        mov ah, 0x06
        mov al, 0
        int 10h
;Переходим к циклу ожидания нажатия клавиши, пропускаем код ниже
jmp if_char
first:
        mov ax, 03         ; Обновим экран
        int 10h
        mov di, cat        ; char* di = msg;
        call PrintStr       ; PrintStr(si);
        mov ah, 0x06
        mov al, 0
        int 10h
;Ожидание клавиши
if_char:                      ;закр. метка
        mov ah, 0          ;вызов обработки клавиши
        int 16h               ;вызываем 16 прерывание функции 0h
        cmp ah, 0Bh      ;код клавиши '0'
        jz first                ; Если нажали 0, то загружаем кошку
        cmp ah, 1Ch      ;код клавиши 'Enter'
        jz second           ; Если нажали Enter, то загружаем другую кошку
jne if_char                  ;Ждём нажатия
jmp $
PrintStr:                     ; Вывод сообщения (функция)
        mov ah, 0x0E     ;Установим режим телетайп
        mov al, [di]         ;Добавим  элемент массива в al
        psloop:               ;Цикл
        int 0x10              ;Системный вызов BIOS
        inc di                  ;инкремент
        mov al, [di]         ;пишем след. значение
        cmp al, 0            ;Если равен 0, выходим
        jne psloop           ;Возврат в цикл
    ret
ret
        msg db "Operating System Sleeping Cat. Press Key 0", 13, 10, 0
        msg_2 db "Made in Russia...", 13, 10, 0
        msg_3 db "Loading...", 13, 10, 0
        msg_4 db "MSK 2022-2023", 13, 10, 0
        msg_5 db "Constructed by dcc0", 13, 10, 0
        msg_6 db "nasm is the best", 13, 10, 0
        msg_7 db "Waiting for a key 0... ", 13, 10, 0
        cat  db  0x0A,0x0D, "Press Enter", 0x0A,0x0D,   20h, 5Eh, 5Eh, 0x0A,0x0D, 28h,  2Dh, 2Dh, 29h, 0x0A,0x0D, 5Ch, 2Fh, 20h, 5Ch, 0x0A,0x0D, 20h, 7Ch, 7Ch, 0x0A, 0x0D, 20h,  20h, 5Ch, 5Ch, 0x0A,0x0D, 0;
        cat_2  db  0x0A,0x0D, "C 2023!", 0x0A,0x0D, 20h, 5Eh, 5Eh, 0x0A,0x0D, 28h,  6Fh, 6Fh, 29h, 0x0A,0x0D, 5Ch, 2Fh, 20h, 5Ch, 0x0A,0x0D, 20h, 7Ch, 7Ch, 0x0A, 0x0D, 20h,  20h, 5Ch, 5Ch, 0x0A,0x0D, 0;
        times 510 - ($-$$) db 0   ;Заполняем нулями до 510 байта
        dw 0xAA55                   ; Последние два байта сектора, к которым обращается BIOS
