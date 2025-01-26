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
//Стрелки
	int  KEY_D = 68;
	int  KEY_C = 67;

     int z = 0; //Длина строки
	char str[20] = "Edit thic string!";
	set_keypress(); //Переключим в non-canonical
	 system("clear");
	 printf("%s", str); //Печатаем строку первый раз

 char value = getchar(); //Ввод
  int i = 0;

//Ищем длину строки
for (i=0; str[i] != '\0'; i++)
z++;
int y = z;

  while (1) {
//Двигаемся влево
	if (value - '\0' == KEY_D ) {
	  system("clear");
	  y--;
	 for (i=0; i <= z; i++) {
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
	  value= ' ';
	}

	//Двигаемся вправо
if (value - '\0' == KEY_C ) {
	  system("clear");
	  y++;
	 for (i=0; i <= z; i++) {
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
		value= ' ';
	}

//Удаляем символы. BackSpace
	  if (value - '\0' ==127 && value != ' ') {
	  system("clear");
	  y--;
	  value= ' ';
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

//Редактируем символ
	  if (value - '\0' > 96 && value - '\0' < 122  && value != ' ') {
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
	value= ' ';
	 y++;
	}
	value = getchar();

	}
}


















