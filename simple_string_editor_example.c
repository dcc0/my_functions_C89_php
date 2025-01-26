/*Simple string text editor*/
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

	char str[13] = "testtesttest";
	set_keypress();
	//printf("%s", str);
	char value = getchar();


  int i = 0;
  int y = 12;

  while (1) {



	if (value == 'D' ) {
	  system("clear");
	  y--;
	 for (i=0; i <= 12; i++) {
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
	  value= ' ';
	}


if (value == 'C' ) {
	  system("clear");
	  y++;
	 for (i=0; i <= 12; i++) {
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
		value= ' ';
	}





	  if (value == '0' && value != ' ') {
	  system("clear");
	  y--;
	  value= ' ';
	 for (i=0; i <= 12; i++) {
		 str[y]=value;
		 if (i == y)
		  printf("[");
		 printf("%c", str[i]);
		 if (i == y)
		  printf("]");
		}
		 printf("%c", str[i]);
	}




	if (y < 0)
	y=0;


	  if (value == 's' ||  value == 'a' || value == 'b' && value != ' ') {
	  system("clear");
	 for (i=0; i <= 12; i++) {
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


















