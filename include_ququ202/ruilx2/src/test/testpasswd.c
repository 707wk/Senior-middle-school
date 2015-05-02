#include <stdio.h>
#include "../passwd.h"

int main(void){
	char a[20];
	printf("Now Test Passwd.c\n");
	printf("Test createpass():\n"
		"Enter Your Password:\n");
	scanf("%s",a);
	printf("CREATING PASSWORD...\n");
	createpass(a);
	printf("PASSWORD CREATED SUCCESSFULLY!\nFile name:\"passwd\"");
	printf("Now, you enter.\n");
	do{
		printf("\tEnter Password:\n");
	}while(!passwd());
	return 0;
}		

