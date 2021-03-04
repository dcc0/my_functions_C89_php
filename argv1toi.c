/*Данная функция переводит аргумент argv[1],
 * содержащй строку, в целое  число (по аналогии с функцией atoi).
/* This function converts an argument (argv[1]) to integer (int)*/
/*Written: MSK. 2021. Iv.Gavryushin. e-mail: ivangavr777@mail.com*/


#include <stdio.h>


int argv1toi (char * var) {

	int i = 0;
	int j = 1;
	int sum = 0;
	int vector[100] = {};


	/*Чтение символов аргумента в вектор
	 * Reading symbols */

	for (i = 0;  var[i] != '\0'; i++)
	vector[i] = var[i]-48;

	i = i - 1;

	/*Умножение чисел в знаках на кратные 10
	 * Multiply the numbers in signs by multiples of 10 */

	for (i; i > -1; i--, j = j*10) {
	vector[i] = vector[i]*j;
	sum+=vector[i];
}


	return sum;
}


int main (int argc, char * argv[]) {

	/*Проверим количество аргументов*/
	/*Verifying number of arguments*/
	if (argc !=2) {
	printf("Run it with a one argument. It must be an integer\n\r");
	return 0;

	}

	int result;
	result = argv1toi( argv[1]);
	printf("%d", result);
}
