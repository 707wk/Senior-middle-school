#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubblesortnew.h"

#include "struct.h"

#define STR struct
#define CON contacts

/*
STR CON *findpre(STR CON *items, STR CON *p){
	STR CON *pre=items;
	while((pre->next)!=p && (pre->next)!=NULL){
		printf("--------------Find Addr:%d pre->next != p------\n");
		pre=(pre->next);
	}
	if(pre==NULL){
		printf("--------------IMPOSSIBLE pre->next==NULL------\n");
		return NULL;
	}
	printf("--------------Pre Now FOUNDED!!! LEAVE FUNCTION------\n");
	return pre;
}
*/

/*
void swap(STR CON *items, STR CON *p1, STR CON *p2){
	STR CON *p3, *p4, *p5;
	if((p2->next)!=NULL){
		puts("------p2->next != NULL------\n");
		if((p1->next)!=NULL){
			puts("----------p1->next != NULL------\n");
			puts("----------p5=p2->next-------\n");
			p5=(p2->next);
			puts("----------p3=findpre(p1)------\n");
			p3=findpre(items, p1);
			puts("----------p4=findpre(p2)------\n");
			p4=findpre(items, p2);
			puts("----------p2->next=p1->next------\n");
			(p2->next)=(p1->next);
			puts("----------p1->next=p5------\n");
			(p1->next)=p5;
			puts("----------p4->next=p1------\n");
			(p4->next)=p1;
			puts("----------p3->next=p2------\n");
			(p3->next)=p2;
			puts("----------IF END------\n");
		}else{
			puts("----------p1->next == NULL------\n");
			puts("----------p3=findpre(p1)------\n");
			p3=findpre(items, p1);
			puts("----------p4=findpre(p2)------\n");
			p4=findpre(items, p2);
			puts("----------p1->next=p2->next------\n");
			(p1->next)=(p2->next);
			puts("----------p3->next=p1------\n");
			(p3->next)=p1;
			puts("----------p4->next=p2------\n");
			(p4->next)=p2;
			puts("----------p2->next=NULL------\n");
			(p2->next)=NULL;
			puts("----------ELSE END------\n");
		}
		puts("------IF END------\n");
	}else{
		puts("------p2->next != NULL-------\n");
		puts("------p3=findpre(p1)------\n");
		p3=findpre(items, p1);
		puts("------p4=findpre(p2)------\n");
		p4=findpre(items, p2);
		puts("------p2->next=p1->next------\n");
		(p2->next)=(p1->next);
		puts("------p3->next=p2------\n");
		(p3->next)=p2;
		puts("------p4->next=p1------\n");
		(p4->next)=p1;
		puts("------p1->next=NULL------\n");
		(p1->next)=NULL;
		puts("------ELSE END------\n");
	}
	puts("--LEAVE FUNCTION------\n");
}
*/

void swap(STR CON *p1, STR CON *p2){
	STR CON p;
	//printf("====INFO====STRCPY p1->name :%s p2->name :%s\n",(p1->name), (p2->name));
	strcpy(p.name, p1->name);
	//printf("                   p1->name :%s p2->name :%s p->name :%s\n",(p1->name), (p2->name), (p.name));
	strcpy(p1->name, p2->name);
	//printf("                   p1->name :%s p2->name :%s p->name :%s\n",(p1->name), (p2->name), (p.name));
	strcpy(p2->name, p.name);
	//printf("                   p1->name :%s p2->name :%s p->name :%s\n",(p1->name), (p2->name), (p.name));

	//printf("====INFO====STRCPY p1->tele :%s p2->tele :%s\n",(p1->tele), (p2->tele));
	strcpy(p.tele, p1->tele);
	strcpy(p1->tele, p2->tele);
	strcpy(p2->tele, p.tele);
	//printf("====INFO====STRCPY p1->tele :%s p2->tele :%s\n",(p1->tele), (p2->tele));

	//printf("====INFO====STRCPY p1->fix :%s p2->fix :%s\n",(p1->fixtel), (p2->fixtel));
	strcpy(p.fixtel, p1->fixtel);
        strcpy(p1->fixtel, p2->fixtel);
        strcpy(p2->fixtel, p.fixtel);
	//printf("====INFO====STRCPY p1->fix :%s p2->fix :%s\n",(p1->fixtel), (p2->fixtel));

	//printf("====INFO====STRCPY p1->addr :%s p2->addr :%s\n",(p1->addr), (p2->addr));
	strcpy(p.addr, p1->addr);
        strcpy(p1->addr, p2->addr);
        strcpy(p2->addr, p.addr);
	//printf("====INFO====STRCPY p1->addr :%s p2->addr :%s\n",(p1->addr), (p2->addr));

	//printf("====INFO====STRCPY p1->email :%s p2->email :%s\n",(p1->email), (p2->email));
	strcpy(p.email, p1->email);
        strcpy(p1->email, p2->email);
        strcpy(p2->email, p.email);
	//printf("====INFO====STRCPY p1->email :%s p2->email :%s\n",(p1->email), (p2->email));

	//printf("====INFO====SWAP p1->.y :%d p2->.y :%d\n",(p1->birth.year), (p2->birth.year));
	p1->birth.year = p1->birth.year ^ p2->birth.year;
	p2->birth.year = p1->birth.year ^ p2->birth.year;
	p1->birth.year = p1->birth.year ^ p2->birth.year;
	//printf("====INFO====SWAP p1->.y :%d p2->.y :%d\n",(p1->birth.year), (p2->birth.year));

	//printf("====INFO====SWAP p1->.m :%d p2->.m :%d\n",(p1->birth.month), (p2->birth.month));
	p1->birth.month = p1->birth.month ^ p2->birth.month;
        p2->birth.month = p1->birth.month ^ p2->birth.month;
        p1->birth.month = p1->birth.month ^ p2->birth.month;
	//printf("====INFO====SWAP p1->.m :%d p2->.m :%d\n",(p1->birth.month), (p2->birth.month));

	//printf("====INFO====SWAP p1->.d :%d p2->.d :%d\n",(p1->birth.day), (p2->birth.day));
	p1->birth.day = p1->birth.day ^ p2->birth.day;
        p2->birth.day = p1->birth.day ^ p2->birth.day;
        p1->birth.day = p1->birth.day ^ p2->birth.day;
	//printf("====INFO====SWAP p1->.d :%d p2->.d :%d\n",(p1->birth.day), (p2->birth.day));

}

void bubblesort(STR CON *head, int i){
	STR CON *p1, *p2;

	//puts("Bubblesore in bubblesortnew.c\n");
	//printf("====For(p1=head; (p1->next)= %d !=NULL; p1=(p1->next))\n",*(p1->next));
	for((p1=head->next); p1!=NULL; p1=(p1->next)){
		//printf("======For(p2=head; (p2->next) %d !=p1; p2=(p2->next))\n",*(p2->next));
		for((p2=head->next); p2!=p1; p2=(p2->next)){
			//puts("========IF sort by NAME\n");
			if(i==1){
				//puts("==========SORT BY NAME!!!\n");
				//puts("==========STRCMP((p1->name),(p2->name))>0\n");
				if(strcmp((p1->name),(p2->name))>0){
					//puts("==============(p1->name),(p2->name))>0!!!\n");
					//printf("SWAP P1 %d P2 %d\n",*p1,*p2);
					//swap(head, p1, p2);
					//puts("==============SWAPPPPPPPPPPPPPPPPPPPPPPP\n");
					swap(p1, p2);
					//puts("==============SWAPPPPPP ENDDDDDDDD\n");
					//printf("SWAP P1 %d P2 %d\n",*p1,*p2);
				}
				//puts("============DONT NEED SWAP~~~\n");
			}else{
				//puts("==========SORT BY TELEPHONE!!!\n");
				//puts("==========STRCMP((p1->tele),(p2->tele))>0\n");
				if(strcmp((p1->tele),(p2->tele))>0){
					//puts("==============SWAP2222222222222222222222\n");
					//swap(head, p1, p2);
					swap(p1, p2);
					//puts("==============SWAP222222 END2222222\n");
				}
				//puts("==========IF ENDDD\n");
			}
			//puts("========IF ENDDD\n");
		}
		//puts("========FOR ENDDD\n");
	}
	//puts("======FOR ENDDD\n");
	//puts("======END OF FUNCTION\n");
}

