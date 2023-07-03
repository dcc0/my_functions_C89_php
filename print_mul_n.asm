; Печать числа через умножение
; 
section .data
 	 stroka dw 4            ;буфер для вывод
section .text

global _start  	                ;must be declared for using gcc

_start:                         ;tell linker entry point
	push rbp                ;Работа со стеком
	mov rbp, rsp

        mov al, 1
        mov [rbp +2], al              ;кладём в стек по адресу +1 байт
        mov  al, [rbp +2]
        mov bl, 10
        mul bl
        add al, 2 ;Ввод числа 1234 через умножение на 10
        mov bl, 10
        mul bl
        add al, 3
         mov bl, 10
        mul bl
        add al, 4
  	;mov eax, 123
   	;add eax, 45
	mov edi, 4              ;Переменная цикла.
loop:                           ;Начало цикла
      	dec edi
			                 	;Декремент, чтобы  записать все значения остатка в stroka
	mov ebx, 10             ;Делитель. Запишем  в цикл, чтобы вернуть ему значение на новой итерации
    	xor edx, edx            ;Обнулим остаток
    	div ebx                 ;Делим
    	add edx, 30h            ;Добавим в остаток 0, равносильно add edx, '0'
    	mov  [stroka + edi], dl ;Пишем в строку остаток в обратном порядке.
    	cmp edi,  0             ;Выходим
jne loop               	        ;Возврат в цикл
                                ;Собрали строку и далее выводим
  	mov ecx, stroka         ;Кладём
    	mov     edx, 4          ;Длина выводимой строки  4 (видимо, в байтах)
    	mov     ebx, 1          ;file descriptor (stdout)
    	mov     eax, 4          ;system call number (sys_write)
    	int     0x80            ;call kernel

    	mov     eax, 1          ;system call number (sys_exit)
    	int     0x80            ;call kernel
