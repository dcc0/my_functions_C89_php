#include <stdio.h>
#include <stdlib.h>
/* Пример реализации выбора с перерисовкой окна и выходом.
 * Программа зациклена через команду goto.
 * Сохранение положеня элементов окна осуществляется через вызов clear - очищение окна*/

void confirm_choice () {

	    char input_confirm;
	    /*Используем двойной scanf, чтобы подтердить нажатие*/
	    scanf( "%c", &input_confirm );
        scanf( "%c", &input_confirm );
     if (input_confirm =='\n')
         printf( "Вы подтверили нажатие%c", input_confirm);
 }

int main()
{
	system("clear");
	printf( "-----------------------------------------\n" );
    printf( "\033[35mВыбор устройства?\033[0m\n" );
    printf( "-----------------------------------------\n" );
    printf( "1. Загрузить c диска\n" );
    printf( "2. Загрузить c флешки\n" );
    printf( "3. Загрузить c дискеты \n" );
    printf( "4. Выход \n" );
    int select = 0;
    int input;
    start:
    printf("%d", select);
    scanf( "%d", &input );
    switch ( input ) {
		case 1:            /* обратите внимание на двоеточие, точки сзапятой тут нет */
    system("clear");
    printf( "Выбор устройства\n" );
    printf( "-----------------------------------------\n" );
    printf( "\033[35m1. Загрузить c диска\033[0m\n" );
    printf( "-----------------------------------------\n" );
    printf( "2. Загрузить c флешки\n" );
    printf( "3. Загрузить c дискеты \n" );
    printf( "4. Выход \n" );
    select=1;
    confirm_choice ();
    goto start;
        break;
        case 2:
system("clear");
    printf( "Выбор устройства\n" );
    printf( "1. Загрузить c диска\n" );
    printf( "-----------------------------------------\n" );
    printf( "\033[35m2. Загрузить c флешки\033[0m\n" );
    printf( "-----------------------------------------\n" );
    printf( "3. Загрузить c дискеты \n" );
    printf( "4. Выход \n" );
    select=2;
    goto start;
        break;
        case 3:
    system("clear");
    printf( "Выбор устройства\n" );
    printf( "1. Загрузить c диска\n" );
    printf( "2. Загрузить c флешки\n" );
    printf( "-----------------------------------------\n" );
    printf( "\033[35m3. Загрузить c дискеты \033[0m\n" );
    printf( "-----------------------------------------\n" );
    printf( "4. Выход \n" );
    select=3;
    goto start;
        break;
        default:
        printf( "Выход\n" );
        select=4;
    }
    printf("%d", select);
}
