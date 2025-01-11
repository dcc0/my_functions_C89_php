#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Пример реализации выбора с перерисовкой окна и выходом.
 * Программа зациклена через команду goto.
 * Сохранение положеня элементов окна осуществляется через вызов clear - очищение окна*/

void print_select(int select) {


/*Выделение цветом*/
char  colored[14] = "\033[47m";
/*Сброс цвета*/
char  uncolored[14] = "\033[0m";

/*Сбросим цвета, чтоб выделить один*/
char * color_select1="";
char * color_select2="";
char * color_select3="";
char * color_select4="";
char * color_select5="";
char * color_select6="";


/*Выбор того, кукую опцию выделить*/
if (select == 1)
color_select1 =colored;
if (select == 2)
color_select2 =colored;
if (select == 3)
color_select3 =colored;
if (select == 4)
color_select4 =colored;
if (select == 5)
color_select5 =colored;
if (select == 6)
color_select6 =colored;


/*Очистим экран. Обновим*/
	system("clear");
/*Выводим выбор (селектор)*/	
	printf( "-----------------------------------------\n" );
    printf( "\033[35mВыбор устройства?\033[0m\n" );
    printf( "-----------------------------------------\n" );
    printf( "%s 1. Загрузить c диска%s   || ", color_select1, uncolored);
    printf( "%s 2. Загрузить c флешки%s      || ", color_select2, uncolored);
    printf( "%s 3. Загрузить c дискеты%s\n ", color_select3, uncolored);
    
    printf( "%s4. Загрузить из сети%s   || ", color_select4, uncolored);
    printf( "%s 5. Загрузить из Интернета%s  || ", color_select5, uncolored);
    printf( "%s 6. Загрузить по WIFI%s\n", color_select6, uncolored);

    printf( "7. Выход \n" );

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
    if (input==7)
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
	case 4:	
    		select=4;
   		 print_select(select);
   	       break;

	 case 5:	
    		select=5;
   		 print_select(select);
   	       break;
      
	case 6:	
    		select=6;
   		 print_select(select);
   	       break;
        default:
        printf( "Выход\n" );
        select=7;
    }
    }
    printf("%d", select);
}

