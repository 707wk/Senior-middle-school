#include <stdio.h>
#include <stdlib.h>
#include "findcon.h"

#include "struct.h"
#include "slowprint.h"
#include "getch.h"

#define STR struct
#define CON contacts
#define LOC(y,x) "\e["#y";"#x"H"
#define LINECLR "\e[2K"
#define PRINTC "%-3d%-12s%12s%15s%27s%20s%5d-%02d-%02d\n",i,(*l[i]).name,(*l[i]).tele,(*l[i]).fixtel,(*l[i]).addr,(*l[i]).email,(*l[i]).birth.year,(*l[i]).birth.month,(*l[i]).birth.day

int lookup(STR CON *head, char *b, STR CON *l[20]){
	char *c;
	int i=0, j=0;
	STR CON *p=head;
	while(*b!='\0'){
		c=(p->name);
		while(*c!='\0'){
			if(*b==*c){
				for(j=0; j<i && i<20; j++){
					if(l[j]==p){			/* If Table Alreadly had, Ignore it */
						goto next1;
					}
				}
				l[i]=p;
				i++;
			}
			c++;
		}
next1:
		c=(p->tele);
		while(*c!='\0'){
			if(*b==*c){
				for(j=0; j<i && i<20; j++){
					if(l[j]==p){
						goto next2;
					}
				}
				l[i]=p;
				i++;
			}
			c++;
		}
next2:
		c=(p->fixtel);
		while(*c!='\0'){
			if(*b==*c){
				for(j=0; j<i && i<20; j++){
					if(l[j]==p){
						goto next3;
					}
				}
				l[i]=p;
				i++;
			}
			c++;
		}
next3:
	b++;
	}
	return i;
}

void printlist(STR CON *l[20], int k){
	int i;
	printf("No-Name---------Telephone---FixedTele------Addr-----------------------E-mail--------------Birthday--\n");
	if(k<1){
		printf("No Match Found!\n");
	}else{
		for(i=0; i<k; i++){
			printf(PRINTC);
		}
	}
}
	

void findcon(STR CON *head){
	
	char a[20], b;
	int i=0, j, k;
	STR CON *l[20];
	slowprint("Enter Key Word: ",30);
	while(((b=getch())!=13) && (i<20)){
		if(b!=127){
			putchar(b);
			a[i]=b;
			a[i+1]='\0';
			i++;
			k=lookup(head, a, l);
		}else{
			if(i>0){
				a[i]='\0';
				i--;
				putchar('\b');
				putchar(' ');
				putchar('\b');
				k=lookup(head, a, l);
			}
		}
		printf("\e7");	/* Save current curior location */
//		for(;j<(k-1);j++){
//			printf("\e[1B");
//			printf(LINECLR);
//		}
		printf(LOC(3,1)); /* Move curior to 3,1 */
		printlist(l, k);	/* List all founded */
		printf("\e8");	/* Load current curior location */
	}
}

