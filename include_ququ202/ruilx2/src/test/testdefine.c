#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define SHOW(a)	#a
//#define MIDDLE(d) "\e["#d"G"

void middle(int i,char *p){
	*p=92;p++;
	*p='e';p++;
	*p='[';p++;
	*p=((i/10)%10+48);p++;
	*p=(i%10+48);p++;
	*p='G';p++;
}

int calmiddle(char *c){
	return ((atoi(getenv("COLUMNS"))-strlen(c))/2);
}

int main(void){
	char a[]="hello world!", b[6];
	int i=calmiddle(a);
	middle(i,b);
	printf("%s%s",b,a);
	return 0;
}

