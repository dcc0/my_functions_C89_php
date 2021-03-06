/"Конечный автомат на С с двумя состояниями.
Работает в фоне, уведомляет о разрыве сети*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(char * ip) {

        if(system(ip)==0) {	
	return 1;			
}
	else {
	return 0;
   }
		
}	

void wait(int b, char * ip) {

	while (1) {	
	
	sleep (5);
	test(ip);
		
	if (b!=test(ip)) {
	b=test(ip);
		
	if (test(ip) == 1) {
	system("beep -f 2200 -l 3000");
} 
	else {
	system("beep -f 1200 -l 2000");
		
	    }	
	}
    }
}



void start (char * ip) {
	
	if (test(ip)==0)
	system("beep -f 1200 -l 2000");
	
}


int main (int argc, char *argv[]) {
             
	if (argc < 2) {
        printf("Введите адрес  вторым параметром ");
        return 0;         
} 
		
	char ip[100]="ping -c 1 ";
	sprintf(ip, "%s%s", ip, argv[1]); 
	    
	int b = 0;
	start (ip);
	wait (b, ip);	
}
