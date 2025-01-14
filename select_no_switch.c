/* This program is an example of selector with choice confirmation, written in C (ANSI).
 * Программа для выбора запускаемой программы с подтверждением. Реализация: C (ANSI или C89).
 * By Ivan Gavryushin (dcc0@mail.ru, ivangavr777@gmail.com, mol0t@list.ru). MSK. Butovo. 2025*/

	#include <stdio.h>

	#include <stdlib.h>

	#include <string.h>

	#include <unistd.h>

	/* Пример реализации выбора с перерисовкой окна и выходом.
	 * Сохранение положения элементов окна осуществляется через вызов clear -
	 * очищение окна*/


	// Функция подтверждения ввода. Возвращает 0 при успехе.
	int confirm_choice() {
	  char input_confirm;
	  int  i =  0;
	  /*Используем двойной scanf, чтобы подтвердить нажатие*/
	  printf("\nНажмите Enter\n");
	  scanf("%c", & input_confirm);
	  scanf("%c", & input_confirm);
	  if (input_confirm == '\n') {
		return 0;
	}
		return 1;
	}

	// Функция вывода селектора.  Возвращает название программы
	char * print_select(int select, char *p) {
	  //============READING FILE============//
	  // Читаем файл с программами
	  FILE * file;
	  char buffer;
	  char str[10];
	  int i = 0;
	  /*Количество вариантов*/
	  int z = 0;
	  int j = 0;
	  // Количество показываемых файлов. Массив
	  char arr1[6][20];
	  // Файл с программами. Ищем файлы .sh в количестве 6 шт. в текущей директории
	  // (демо версия:)). system("ls *.sh | head -n 6 > data.txt"); В data.txt
	  // следует писать названия программ с абсолютными путями, если используем execl
	  // Если system, то так: ls, pwd и т.д.
	  file = fopen("data.txt", "r");

	  while ((buffer = getc(file)) != EOF) {
		str[i] = buffer;

		if (str[i] == '\n') {
		  // Пишем строку  посимвольно в отдельный массив
		  for (j = 0; str[j] != '\n'; j++) {
			arr1[z][j] = str[j];
		  }
		  /*Запишем 0 в конец строки*/
		  arr1[z][j] = '\0';
		  z++;
		  //Сбросим i , чтобы очистить str[0]
		  //Так как ниже инкремент, то сбросим в -1, т.е. ниже i уже = 0
		  //Иначе в str[0] всегда будет в начале первый символ
		  i = -1;
		}
		i++;
	  }

	  fclose(file);
	  // Завершаем чтение файла
	  //===========END OF FILE READING=============//

	  /*Выделение цветом*/
	  char colored[14] = "\033[43m";
	  /*Сброс цвета*/
	  char uncolored[14] = "\033[0m";

	  //====ВЫВОДИМ СЕЛЕКТОР===
	  /*Очистим экран. Обновим. Первый раз выводим*/
	  system("clear");
	  if (select == 0) {
		/*Количество вариантов выбора в переменной z*/
		for (j = 0; j != z; j++) {
		  printf("%d.[%s]\n", j+1, arr1[j]);
		}
	  }

	//====ЕСЛИ СДЕЛАН ВЫБОР===
	  int choice = select - 1;
	  // Выводим результат выбора
	  if (select > 0) {
		for (j = 0; j != z; j++) {
		  // Выделяем цветом выбор
		  if (select == j && select !=7) {
			// Запомним выбор. Нужно, чтобы напечатать в правильно
			// последовательности так как селектор с 1 по 6, массив с 0 по 5
			choice = select - 1;
			printf("->[%s%s%s]\n", colored, arr1[select - 1], uncolored);
			/* Возвращаем указатель на область памяти, где эта строка. Заодно
			 * выделили память под нее (strlen - если не известен размер)*/
			//p = (char * ) malloc(strlen(arr1[select - 1]) + 1);
			//Но мы знаем размер 20. char * - приведение к типу "указатель на строку"
			p = (char * ) malloc(20);
			strcpy(p, arr1[select - 1]);
		  }
		  //Раскрасим выход
		  	if (select == 7 && select ==j+1) {
			choice = select - 1;
			printf("->[%s%s%s]\n", colored, arr1[select - 1], uncolored);
		 }
		  if (j != choice) printf("%d.[%s]\n", j+1, arr1[j]);
		}
	  }


	  /*Вернем название программы, которую надо выполнить*/
	  if (p != "")
	  return p;
	  return "1";
	}

	int main() {
	  char * run_program;
	  int select = 0;
	  int input;
	  //Указатель на строку с программой, которая будет выделена и выполнена
	  char * p;
	  //Счётчик для неправильных попыток
	  int i = 3;
	  /*Сбросим цвет при старте*/
	  /*Первый вызов селектора*/
	  print_select(select, p);

	  /*Сканируем ввод*/
	  while ( 1) {
		scanf("%d", &input);
		//Проверим введённые данные. Попробуем привести к целому, если символ; так проверим ввод
		if (input - '\0' == 0 ) {
		//Вызываем подтверждение ввода. Таким образом вернёмся к scanf, сбросим input
		//На следующей итерации сканируем заново
		//Возвращаем 0 и переходим к ожиданию нового ввода. Прыгаем к scanf
		confirm_choice();
		printf("Неправильный ввод %d\n", i);
		if (i == 1)
		return 1;
		i--;
		}

		if (input == 7) {
		  select=input;
		  print_select(select, p);
		  printf("Выход\n");
		  break;
		}

		/*Выбор тут*/
		if (input > 0 && input < 7) {
		  select = input;
		  run_program = print_select(select, p);
		  /*Подтвердим и выполним*/
		  if (confirm_choice() == 0) {
			printf("Выполним программу %d\n", select);
			printf("%s", run_program);
			// system(run_program);
			execl(run_program, 0, NULL);
			//Освободим память, выделенную для p
			free(p);
		  } else {
			select = 0;
			print_select(select, p);
			printf("Выбор сброшен\n");
		  }

		}

	  }
	  return 0;
	}
