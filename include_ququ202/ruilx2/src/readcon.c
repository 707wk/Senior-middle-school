#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "readcon.h"
#include "struct.h"
#include "slowprint.h"

#define STR struct
#define CON contacts

STR CON *readcon(char *filename, STR CON *head){
	FILE *fp;
	STR CON *p1, *p2;
	if((fp=fopen(filename,"rt"))==NULL){
		printf("Bad command or file name\n");
		return NULL;
	}
	//h=p2=(STR CON *)malloc(sizeof(STR CON));
	//if(sizeof(head) != sizeof(STR CON) ){
	//	printf("Bad struct blocks size\n");
	//	return NULL;
	//}
	p2=(STR CON *)malloc(sizeof(STR CON));
	head=p2;
	slowprint("Reading... Please Wait...\n",30);
	while(!feof(fp)){
		p1=(STR CON *)malloc(sizeof(STR CON));
		fscanf(fp,"%s%s%s%s%s%d%d%d",p1->name,p1->tele,p1->fixtel,p1->addr,p1->email, \
		&p1->birth.year, &p1->birth.month, &p1->birth.day);
		if(!feof(fp)){
			p2->next=p1;
			p2=p1;
		}
	}
	fclose(fp);
	p2->next=NULL;
	free(p1);
	sleep(2);
	return head;
}
