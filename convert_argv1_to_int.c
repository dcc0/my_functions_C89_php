/*Конвертация аргумента в число (по аналогии с функцией atoi)
Converts an argument argv[1] to an integer*/
/*Written: MSK. 2021. Iv.Gavryushin. e-mail: ivangavr777@mail.com*/

#include <stdio.h>
int main (int argc, char * argv[]) {

	int i = 0;
	int j = 1;
	int sum = 0;
	int vector[30] = {};
	
	/*Чтение символов аргумента в вектор
 	 Reading symbols and creating vector*/	
	for (i = 0;  argv[1][i] != '\0'; i++)
	vector[i] = argv[1][i]-48;
	
	i = i - 1;
	/*Multiplying numbers in signs by multiples of 10*/
	for (i; i > -1; i--, j = j*10) 
	vector[i] = vector[i]*j;
	
	
	/*Adding vector values into one variable*/
	for (i = 0; argv[1][i] != '\0'; i++) 
	sum+=vector[i];
		
	printf("%d", sum);
}
