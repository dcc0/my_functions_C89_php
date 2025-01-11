#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Пример реализации выбора с перерисовкой окна и выходом.
 * Сохранение положеня элементов окна осуществляется через вызов clear - очищение окна*/

void print_select(int select) {


/*Выделение цветом*/
char  colored[14] = "\033[47m";
/*Сброс цвета*/
char  uncolored[14] = "\033[0m\n";

/*Сбросим цвета, чтоб выделить один*/
char * color_select1="";
char * color_select2="";
char * color_select3="";


/*Выбор того, кукую опцию выделить*/
if (select == 1)
color_select1 =colored;
if (select == 2)
color_select2 =colored;
if (select == 3)
color_select3 =colored;

/*Очистим экран. Обновим*/
	system("clear");
/*Выводим выбор (селектор)*/	
	printf( "-----------------------------------------\n" );
    printf( "\033[35mВыбор устройства?\033[0m\n" );
    printf( "-----------------------------------------\n" );
    printf( "%s 1. Загрузить c диска%s\n", color_select1, uncolored);
    printf( "%s 2. Загрузить c флешки%s\n", color_select2, uncolored);
    printf( "%s 3. Загрузить c дискеты%s \n", color_select3, uncolored);
    printf( "4. Выход \n" );

}



int main()
{
int select = 0;
int input;
/*Сбросим цвет при старте*/
/*Первый вызов*/
print_select(select);
printf("%d", select);
/*Сканируем ввод*/    

while(1) {
    scanf( "%d", &input );
    if (input==4)
    break;

switch ( input ) {

	case 1:           
	select=1;
    		print_select(select);
        	break;
        case 2:
	 	select=2;
		print_select(select);
	    	break;
        case 3:	
    		select=3;
   		 print_select(select);
   	       break;
        default:
        printf( "Выход\n" );
        select=4;
    }
    }
    printf("%d", select);
}
