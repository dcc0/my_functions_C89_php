/*Вычислим факториал
для остановки алгоритма. */
#include <stdio.h>
#include  "argv1toi.h"

/* It calculates a factorial to stop the algorithm. */

int factorial (int var) {

	 int f = 1;
	 int j = 0;

	while (j != var) {
	j++;
 	f = j * f;
 }
	return f;
}


int main(int argc, char * argv[]) {
	
	int f = 0;
	f = argv1toi(argv[1]);
	
	if (f > 13) {
	printf("This program doesn't support long arithmetic, so a number must be < 13");
}	 	

	f = factorial(f);
	printf("%d", f); 	
		
}	
