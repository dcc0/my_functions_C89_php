/*Simple string text editor*/
/*Пример редактора строки.
 * 1) Перемещение по строке на стрелки
 * 2) Замена символов
 * 3) Удаление символов*/
 /*Если задавать при старте аргумент в виде файла и читать его,
  * потом записывать, то возможно написать простейший редактор текста*/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>

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

int main(int argc, char * argv[]) {
if (argc < 2) {
 printf("Не задано имя текстового файла\n");
return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
  //==================READING FILE============//
  /////////////////////////////////////////////////////////////////////////////////////////
  // Читаем файл
  FILE * file;
  char buffer1;
    //str = буфер, который будем реадактировать
  char str[200];
  int i = 0;
  /*Количество вариантов*/
  int z = 0;
  int j = 0;
//Читаем файл из аргумента в буфер
  file = fopen(argv[1], "r");
while ((buffer1 = getc(file)) != EOF) {
    str[i] = buffer1;
    i++;
  }
 fclose(file);
/////////////////////////////////////////////////////////////////////////////////////////



//Стрелки
	int  KEY_D = 68;
	int  KEY_C = 67;
	int  KEY_Backspace = 127;
	int  KEY_space = 32;
	int  KEY_backqote = 96;
	int KEY_ENTER=10;



      z = 0; //Длина строки
	//char str[20] = "Edit thic string!";
	set_keypress(); //Переключим в non-canonical
	 system("clear");
	 printf("%s", str); //Печатаем строку первый раз

	char value = getchar(); //Ввод
	i = 0;
	int y = 0;
	int input = value - '\0';


//Ищем длину строки
for (i=0; str[i] != '\0'; i++)
z++;
y = z;


//printf("%d", input);
  //return 0;

  while (1) {

input = value - '\0';

//Двигаемся влево
	if (input == KEY_D ) {
	  system("clear");
	  y--;
	 for (i=0; i <= z; i++) {
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
	  input= KEY_backqote;
	}

	//Двигаемся вправо
if (input == KEY_C ) {
	  system("clear");
	  y++;
	 for (i=0; i <= z; i++) {
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
		input= KEY_backqote;
	}

//Удаляем символы. BackSpace
	  if (input ==KEY_Backspace) {
	  system("clear");
	  y--;
	  input= KEY_backqote;
	 for (i=0; i <= z; i++) {
		 str[y]=value;
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
		 printf("%c", str[i]);
	}

//Если достигли предела декремента
	if (y < 0)
	y=0;

//Если достигли предела инкремента
	if (y > z)
	y=z;



	//Редактируем символ (цифры и большие буквы)
	  if (input > 96 && input < 127 || input > 32 && input  < 67 ||  input > 68 && input  <  89 || input > 91 && input  < 96) {

	  system("clear");
	 for (i=0; i <= z; i++) {
		 str[y]=value;
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
		 printf("%c", str[i]);
	input= KEY_backqote;
	 y++;
	}

//Записываем новое значение в файл
	if (input == KEY_ENTER ) {

	FILE *fp = fopen(argv[1], "w");
    if(fp)
    {
        // Записываем строку
        fputs(str, fp);
        fclose(fp);
        printf("Edited\n");
    }

    z=0;
    i=0;

    //Заново читаем файл
    file = fopen(argv[1], "r");
	while ((buffer1 = getc(file)) != EOF) {
    str[i] = buffer1;
    i++;
  }
 fclose(file);
	//Ищем длину строки
	for (i=0; str[i] != '\0'; i++)
	z++;
	y = z;
	}

//Ожидание символа
	value = getchar();

	}
}



