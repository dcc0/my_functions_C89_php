//////////////////////////ПОИСК И ЗАПУСК КОМАНД ИЗ .BASH_HISTORY///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////MSK. 2025/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////crafted by: dcc0@yandex.ru/////////////////////////////////////////////////////////
//Селектор, выбор через цифры. Enter: подтверждение
#include <stdio.h>

#include <stdlib.h>

#include <termios.h>

#include <string.h>

#include <unistd.h>

/*Перевод в режим non-canonical, getch работает без Enter. Этот фрагмент кода взят в Интернете*/
//This function found on stackoverflow
                           //////////////////////////////////////////////SWITCH TO NON-CANONICAL///////////////////////
/////////SOURCE: stackoverflow.com SLASH questions/63751531/non-canonical-terminal-mode-buffer-stdout-in-c-program///////////////////
                        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static struct termios stored_settings;

void set_keypress(void) {
  struct termios new_settings;

  tcgetattr(0, & stored_settings);

  new_settings = stored_settings;

  /* Disable canonical mode, and set buffer size to 1 byte */
  new_settings.c_lflag &= (~ICANON);
  new_settings.c_cc[VTIME] = 0;
  new_settings.c_cc[VMIN] = 1;

  tcsetattr(0, TCSANOW, & new_settings);
  return;
}

void reset_keypress(void) {
  tcsetattr(0, TCSANOW, & stored_settings);
  return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                      //////////////////////////////Вызов Селектора/////////////////
          //////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Функция вывода селектора.  Возвращает название программы
char * print_select(int select, char * p) {
  //============READING FILE============//
  // Читаем файл с программами
  FILE * file;
  char buffer;
  char str[200];
  int i = 0;
  /*Количество вариантов*/
  int z = 0;
  int j = 0;
  // Количество показываемых файлов. Массив
  char arr1[500][200];
  // Файл с программами. Ищем файлы .sh в количестве 6 шт. в текущей директории
  // (демо версия:)). system("ls *.sh | head -n 6 > data.txt"); В data.txt
  // следует писать названия программ с абсолютными путями, если используем execl
  // Если system, то так: ls, pwd и т.д.
  file = fopen("../.bash_history", "r");

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
      printf("%d.[%s]\n", j + 1, arr1[j]);
    }
  }

  //====ЕСЛИ СДЕЛАН ВЫБОР===
  int choice = select - 1;
  // Выводим результат выбора
  if (select > 0) {
    for (j = 0; j != z; j++) {
      // Выделяем цветом выбор
      if (select == j && select != 501) {
        // Запомним выбор. Нужно, чтобы напечатать в правильно
        // последовательности так как селектор с 1 по 6, массив с 0 по 5
        choice = select - 1;
        printf("->[%s%s%s]\n", colored, arr1[select - 1], uncolored);
        /* Возвращаем указатель на область памяти, где эта строка. Заодно
         * выделили память под нее (strlen - если не известен размер)*/
        //p = (char * ) malloc(strlen(arr1[select - 1]) + 1);
        //Но мы знаем размер 20. char * - приведение к типу "указатель на строку"
        p = (char * ) malloc(200);
        strcpy(p, arr1[select - 1]);
        break;
      }

      if (j != choice) printf("%d.[%s]\n", j + 1, arr1[j]);
    }

    //Последнюю опцию добавим вне цикла
if (select ==500) {
	printf("->[%s%s%s]\n", colored, arr1[select - 1], uncolored);
	  p = (char * ) malloc(200);
     strcpy(p, arr1[select -1]);
}


  }
  //Раскрасим выход
  if (select == 501) {
    choice = select - 1;
    printf("->[%s Выход %s]\n", colored, uncolored);
  } else {
    printf("Выход\n");
  }

  printf("Для выхода: 501 \n");
  printf("Для сброса нажмите любую букву: s (например) \n");
  printf("Для справки  добавьте ключ -h: select_and_run_history.comb -h\n");
  printf("О программе: select_and_run_history.comb -a\n");
  printf("Если трехзначное число, то нажатие s обнулит буфер!");

  /*Вернем название программы, которую надо выполнить*/
  if (p != "")
    return p;
  return "1";
}

              ////////////////////////////////MAIN///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                  ////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {

  char * run_program;
  //для названия команды
  char * p;

  //Цвет
  char colored[14] = "\033[43m";
  /*Сброс цвета*/
  char uncolored[14] = "\033[0m";
  int select = 0;
  //Вызываем селектор 1 раз, пустой
  print_select(select, p);
  //С помощью terminos переключим вывод терминала в non-canonical mode.
  //Это позволит не нажимать Enter при переходе от опции к опции, но для выполнения нажать надо
  set_keypress();
  //Для чтения   с терминала
  char value = getchar();
  //Для перемещения по разрядам
  char buffer[3] = {
    0
  };
  //Счётчик буфера
  int i = 0;


  while (1) {

    if (value != ' ' && value != 's') {
      buffer[i] = value;
      value = ' ';
      //Приведем к int
      select = strtol(buffer, NULL, 10);
      //Вызываем селектор с выбором
      run_program = print_select(select, p);
      i++;
    }

    //Проверим буфер. Если буфер заполнен, то обнулим его. Напечатаем то что в нем было сначала
    if (buffer[0] > 0 && buffer[1] > 0 && buffer[2] > 0) {
      printf("%c %c %c", buffer[0], buffer[1], buffer[2]);
      value = ' ';
    }



    //Добавляем новое число в буфер
    if (buffer[i] > 0) {
      buffer[i] = value;
    }

    //Ожидаем ввол
    value = getchar();

    //Выполним
    //Проверим, что нажат Enter (\n) и то, что не выходим
    if (select != 501 && value == '\n') {
      printf("%s", run_program);
      system(run_program);
      //Чтобы остановить обновление
      //и показать результат программу
      value = ' ';
    }

    //Обнулим проход
    if (value == 's') {
      //Обнулим буфер
      buffer[0] = 0;
      buffer[1] = 0;
      buffer[2] = 0;
      //Обнулим счётчик буфера
      i = 0;
      select = 0;
      print_select(select, p);
    }

    //Выход
    if (value == '\n' && select == 501)
      break;
    //Пишем символ на stdout
    putchar('[');
    putchar(value);
    putchar(']');

  }
  printf("%s Выход %s", colored, uncolored);
  return 0;
}
