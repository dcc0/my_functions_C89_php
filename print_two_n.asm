; Найдено здесь (Found here): https://mrempy.medium.com/assembly-16-bits-printing-strings-a114c72f6e43
; 1) Добавлен цвет фона
; 2) Добавлено обновление экрана
; 3) Вывод клавиш по нажатию 0 и 1. Символы выводятся из массива
; Команда сборки и выполнения
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
       rep   stosw      ;// записать АХ в ES:DI, по длине С
;call PrintStr ; Вызываем вывод на экран, для каждого сообщения (функция)
		mov si, 0

jmp if_char
enter:
        mov ax, 03         ; Обновим экран
        int 10h
       mov di, msg3
       call PrintStr        ;PrintStr(si);

jmp if_char
first:
        mov ax, 03          ;Обновим экран
        int 10h
        mov di,  msg
        mov ah, 0x0E         ;Установим режим телетайп
        mov al, [di +bp]     ;Добавим  элемент массива в al по номеру
        ;int 0x10            ;Системный вызов BIOS
      mov  [result +si], al  ;Пишем в строку
	  inc si
        mov di, result
        call PrintStr       ; PrintStr(si)
;Ожидание клавиши
if_char:                     ;закр. метка
        mov ah, 0            ;вызов обработки клавиши
        int 16h              ;вызываем 16 прерывание функции 0h
        mov di, msg2 +1 ;Код клавиши 1 из массива по номеру
        cmp ah, [di]         ;код клавиши '1'
        mov bp, 1            ; Пишем значения для поиска по элемента по номеру
        jz first
        mov di, msg2 +0
        cmp ah, [di]        ;код клавиши '0'
        mov bp, 0
        jz first
        cmp ah, 1Ch          ;код клавиши '0'
        jz enter
jne if_char                  ;Ждём нажатия
jmp $
PrintStr:                    ; Вывод сообщения (функция)
        mov ah, 0x0E         ;Установим режим телетайп
        mov al, [di]         ;Добавим  элемент массива в al
        psloop:              ;Цикл
        int 0x10             ;Системный вызов BIOS
        inc di               ;инкремент
        mov al, [di]         ;пишем след. значение
        cmp al, 0            ;Если равен 0, выходим
        jne psloop           ;Возврат в цикл
    ret
ret
		msg3 db  "Enter pressed ", 13, 10, 0
        msg db    "01", 0        ;Массив символов
        msg2 db 0Bh, 02h, 0  ;Массив клавиш
        result db 4, 13, 10, 0
        times 510 - ($-$$) db 0    ;Заполняем нулями до 510 байта
        dw 0xAA55                   ; Последние два байта сектора, к которым обращается BIOS
