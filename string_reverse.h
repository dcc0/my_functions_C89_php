/* Данная функция переворачивает строку
 * This function reverse a string. */

char * string_reverse (char * string) {

    int i = 0;
    int j = 0;
    char c;

	for (i; string[i] != '\0'; i++);

	while (i > j) {
   
    i--;
    c = string[j];
    string[j] = string[i];
    string[i] = c;
    j++;
    
    }
    
	 return string;

}
