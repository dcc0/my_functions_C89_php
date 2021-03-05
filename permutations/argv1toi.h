/*Данная функция переводит аргумент argv[1],
 * содержащй строку, в целое  число (по аналогии с функцией atoi).
/* This function converts an argument (argv[1]) to integer (int)*/
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
