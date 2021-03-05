/*Вычислим факториал
для остановки алгоритма.
* It calculates a factorial to stop the algorithm. */

int factorial (int var) {

	int f = 1;
	int j = 0;

	while (j != var) {

	j++;
 	f = j * f;
 
  }
	return f;
}
