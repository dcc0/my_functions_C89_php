#include <stdio.h>
#include  "argv1toi.h"
#include  "factorial.h"

/*Функция перебора перестановок.
 * Permutation function.*/

int permute(int
  var) {

  int i = 0;
  int j = 0;
  int x = 0; /*Длина строки. String length*/
  int c = 0; /*Обмен. Buffer*/
  int f = 1; /*Факториал. Factorial*/
  int a[100] = {}; /*Вектор целых. Vector. Integers*/

  /*Вычислим длину строки и заполним массив. It calculates an array's length and fills an array*/
  for (x; x < var +1; x++)
  a[x] = x;
  a[x] = '\0';

  /*Вычислим факториал
  для остановки алгоритма.
  * It calculates a factorial to stop the algorithm. */
  //f = factorial(var);

  /*Перестановки. Permutations.*/
  while (f--) {

  for (x = 0; a[x] != '\0'; x++)
  printf("%d ", a[x]);
  printf("\n");

  i = 1;

  /*Поиск следующей перестановки. Search next permutation*/
  while (a[i] > a[i - 1]) i++;

  j = 0;

  while (a[j] < a[i]) j++;

  /*Обмен. Change*/
  c = a[j];
  a[j] = a[i];
  a[i] = c;

  i--;

  /*Оборот хвоста. Tail reverse*/
  for (j = 0; j < i; i--, j++) {

  c = a[i];
  a[i] = a[j];
  a[j] = c;

    }
  }
}


int main(int argc, char * argv[]) {

 int a = 0;

  /*Проверим число аргументов. Here we check a number
   * of arguments*/
 if (argc != 2) {
  printf("Restart it with an argument\n");
  return 0;
 }

  /*Конвертируем аргумент (строку) в целое число
   * String (argument) to integer conversion*/
  a = argv1toi(argv[1]);

  if (a > 99) return 0;
  /*Функция перестановок. Permutation function*/
  permute(a);
}
