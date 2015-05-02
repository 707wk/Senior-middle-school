#include <stdio.h>
#include <stdlib.h>
#include "../cipher.h"

int main(void){
	int i;
	char *p, c[20];
	i=encryption("I Love You Panke!","testcipher.txt",555);
	if(i!=0){
		printf("Find Error! Exitting...\n");
		return 0;
	}
	printf("Succeed!,File is:\n\n");
	system("cat ./testcipher.txt");
	p=deciphering("testcipher.txt",c,555);
	if(p==NULL){
		printf("Read Error! Exitting...\n");
		return 0;
	}
	printf("\n\nSucceed!,String is:\n\n");
	puts(c);
	printf("\n");
	return 0;
}
	
