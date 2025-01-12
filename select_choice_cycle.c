#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Пример реализации выбора с перерисовкой окна и выходом.
 * Сохранение положения элементов окна осуществляется через вызов clear - очищение окна*/

int confirm_choice () {

		char input_confirm;
	    /*Используем двойной scanf, чтобы подтвердить нажатие*/
        scanf( "%c", &input_confirm );
        scanf( "%c", &input_confirm );
       if (input_confirm =='\n') {
 		return 0;
	} else {
		return 1;
	}
 }


void print_select(int select) {

/*Выделение цветом*/
char  colored[14] = "\033[44m";
/*Сброс цвета*/
char  uncolored[14] = "\033[0m";
/*Массив строк*/
char * color_select [6][10]={};

int i = 0;

/*Выбор того, какую опцию выделить*/
while (i < 7) {
	i++;
if (select == i)
color_select[i-1][10]=colored;
if (select != i)
color_select[i-1][10]="";
}

/*Очистим экран. Обновим*/
	system("clear");
/*Выводим выбор (селектор)*/
	printf( "-----------------------------------------\n" );
    printf( "\033[44mВыбор устройства?\033[0m\n" );
    printf( "-----------------------------------------\n" );
    printf( "%s 1. Загрузить c диска%s   || ", color_select[0][10], uncolored);
    printf( "%s 2. Загрузить c флешки%s      || ", color_select[1][10], uncolored);
    printf( "%s 3. Загрузить c дискеты%s\n ", color_select[2][10], uncolored);
    printf( "%s4. Загрузить из сети%s   || ", color_select[3][10], uncolored);
    printf( "%s 5. Загрузить из Интернета%s  || ", color_select[4][10], uncolored);
    printf( "%s 6. Загрузить по WIFI%s\n", color_select[5][10], uncolored);
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
    		if(confirm_choice()== 0)
    		printf( "Выполним программу 1\n" );
			break;

      case 2:
      select =2;
	 	print_select(select);
    		if(confirm_choice()== 0)
    		printf( "Выполним программу 2\n" );
	    	break;

      case 3:
    		select=3;
   		 print_select(select);
   		 if(confirm_choice()==0)
   		 printf( "Выполним программу 3\n" );
   	       break;

	case 4:
    		select=4;
   		 print_select(select);
   		 if(confirm_choice()==0)
   		 printf( "Выполним программу 4\n" );
   	       break;

	 case 5:
    		select=5;
   		 print_select(select);
   		 if(confirm_choice()==0)
   		 printf( "Выполним программу 5\n" );
   	       break;

	case 6:
    		select=6;
   		 print_select(select);
   		 if(confirm_choice()==0)
   		 printf( "Выполним программу 6\n" );
   	       break;
        default:
        printf( "Выход\n" );
        select=7;
    }
    }
    printf("%d", select);
}

