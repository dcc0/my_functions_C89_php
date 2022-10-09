#include <stdio.h>
#include <stdlib.h>
   /*
 * Эта программа читает файл по одному симолу, и ищет слово в тексте
 * Первый аргумент - имя файла, второй - строка.
 * Если задан третий аргумент, то программа будет печатать весь вывод на экран.
 * */

int main (int argc, char *argv[])
{

	char c;
	int  i, x, z;
	FILE *file;
	if (argc < 3) {
	printf("poisk ИМЯ ФАЙЛА СЛОВО\n");
	printf("Третий параметр 'o' выводит содержимое файла\n");
	return 0;
	}
	if  (fopen(argv[1], "r") == NULL) {
	printf("Нет такого файла\n");
	return 0;
 	}

	char *string = argv[2];
	for (z = 0; string[z] != '\0'; z++);

	file = fopen(argv[1], "r");

	while (1)
    {
	c = getc (file);
	//if (argv[3] > 0 && argv[3][0] == 'o')
	printf("\033[37m%c", c);
	if (c == EOF)
 	break;
	if (argv[2][x]!=c) {
	x=0;
	}
	if (argv[2][x]==c) {
	x++;
	}
	i++;

	if (x==z) {
	x=0;
	printf ("\n \033[34m Сочетание найдено: \033[33m");
	printf (string);
	printf (", \033[34m позиция символа: ");
	printf("%c", string[z-1]);
	printf(" %ld\n", ftell(file));
	continue;
			}
		}
fclose(file);
}

