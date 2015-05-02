#include <stdio.h>

#include "../readcon.h"
#include "../display.h"
#include "../struct.h"

int main(void){
	struct contacts *head;
	head = readcon("contracts.dat",head);
	display(head);
	return 0;
}
	
