#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Пример реализации выбора с перерисовкой окна и выходом.
 * Сохранение положения элементов окна осуществляется через вызов clear - очищение окна
 Добавлена возможность запуска программы.
 */
//Функция подтверждения ввода. Возвращает 0 при успехе.
int confirm_choice () {

		char input_confirm;
	    /*Используем двойной scanf, чтобы подтвердить нажатие*/
	    printf("Нажмите Enter");
		scanf( "%c", &input_confirm );
		scanf( "%c", &input_confirm );
		if (input_confirm =='\n')
 		return 0;
 }



//Функция вывода селектора.  Возвращает название программы
char * print_select(int select) {

//============READING FILE============//
//Читаем файл с программами
	FILE *file;
   char buffer;
   char str[10];
    int i =0;
    int z = 0;
    int j = 0;
 //Количество показываемых файлов. Массив
char  arr1[6][12];
//Файл с программами. Ищем файлы .sh в количестве 6 шт. в текущей директории (демо версия:)).
	//system("ls *.sh | head -n 6 > data.txt");
    file = fopen("data.txt", "r");
    while ((buffer = getc(file)) != EOF) {
        str[i]=buffer;

		if (str[i] == '\n') {
		//Пишем строку  посимвольно в отдельный массив
				for (j = 0; str[j] !='\n'; j++ ) {
				 arr1[z][j] = str[j];

				 //Добавим пробел, иначе в начале строки будет лишний символ
				 str[0]=' ';
				}
//Читаем в массив строк названия программ
			arr1[z][j]='\0';
		z++;
		i=0;
	}
	i++;
	}
 fclose(file);
//Завершаем чтение файла
//===========END OF FILE READING=============//

/*Выделение цветом*/
char  colored[14] = "\033[44m";
/*Сброс цвета*/
char  uncolored[14] = "\033[0m";


//====ВЫВОДИМ СЕЛЕКТОР===
	/*Очистим экран. Обновим. Первый раз выводим*/

system("clear");
	  if( select ==0 ) {
		for (j=0; j < z+1; j++) {
		printf("%s%s\n", arr1[j], uncolored);
	}
}
/*Результат тут будет. Передали в эту функцию строку.*/
char *p ;
int choice = select-1;
//Выводим результат выбора
	  if( select > 0  ) {
for (j=0; j < z+1; j++) {

//Выделяем цветом выбор
	if(  select ==j ) {
//Запомним выбор. Нужно, чтобы напечатать в правильно последовательности так как селектор с 1 по 6, массив с 0 по 5
		choice=select-1;
printf("->%s%s%s\n",   colored, arr1[select-1], uncolored);
 /* Возвращаем указатель на область памяти, где эта строка. Заодно выделили память под нее*/
p = (char*) malloc(strlen(arr1[select-1])+1);
		 strcpy(p, arr1[select-1]);
}

if (j != choice)
 printf("%s\n",   arr1[j]);


}
}

/*Вернем название программы, которую надо выполнить*/
if (p !="")
	return p;
}



int main()
{

char * run_program;
int select = 0;
int input;

/*Сбросим цвет при старте*/
/*Первый вызов селектора*/
print_select(select);

/*Сканируем ввод*/
while(1) {
    scanf( "%d", &input );
    if (input==7) {
	  printf( "Выход\n" );
    break;
}

//тут выбор
switch ( input ) {

	case 1:
	select=1;
			run_program=print_select(select);
    		if(confirm_choice()== 0)  {
    		printf( "Выполним программу 1\n" );
    			printf( "%s", run_program );
				system(run_program);
			}
			break;

      case 2:
      select =2;
		run_program=print_select(select);
    		if(confirm_choice()== 0)  {
    		printf( "Выполним программу 2\n" );
			system(run_program);
			}
			break;


      case 3:
    		select=3;
		run_program=print_select(select);
    		if(confirm_choice()== 0)  {
    		printf( "Выполним программу 3\n" );
			system(run_program);

			}
			break;


	case 4:
    		select=4;
		run_program=print_select(select);
    		if(confirm_choice()== 0)  {
    		printf( "Выполним программу 4\n" );
			system(run_program);
			}
			break;


	 case 5:
    		select=5;
   		run_program=print_select(select);
    		if(confirm_choice()== 0)  {
    		printf( "Выполним программу 5\n" );
			system(run_program);
			}
			break;


	case 6:
    		select=6;
   		run_program=print_select(select);
    		if(confirm_choice()== 0)  {
    		printf( "Выполним программу 6\n" );
			system(run_program);
			}
			break;

        default:
        select=7;
    }
    }
    if (select > 0) {
    printf("%d", select);

}
}

