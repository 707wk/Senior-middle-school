#include <stdio.h>
#include "save.h"
#include "struct.h"
#include "slowprint.h"

int save(struct contacts *p){
	FILE *fp;
	p=p->next;
	if((fp=fopen("contracts.dat","wt"))==NULL){
		slowprint("Cannot open current file...\n",30);
		return 127;
	}
	
	while(p!=NULL){
		fprintf(fp,"%s %s %s %s %s %d %d %d\n", p->name, p->tele, p->fixtel, p->addr \
			, p->email, p->birth.year, p->birth.month, p->birth.day);
		p=p->next;
	}

	fclose(fp);
	return 1;
}

