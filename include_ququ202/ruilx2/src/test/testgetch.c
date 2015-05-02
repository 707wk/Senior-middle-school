#include <stdio.h>
#include "../getch.h"

int main(void){
	char c[20];
	char *p=c, *w=c;

	for(;p<w+19;p++){
		printf("\nPlease Enter a Char for %d: ",(int)(p-w));
		*p=(char)getch();
		printf("\nYou Entered %d number.\n",*p);
	}
	*p='\0';
	printf("Enter over: You Entered:\n");

	puts(c);

	return 0;
}

