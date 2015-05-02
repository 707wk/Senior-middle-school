#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubblesort.h"

#include "struct.h"

#define STR struct
#define CON contacts

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


void bubblesort(STR CON *head, int i){
	STR CON *p1, *p2;

	for(p1=head; (p1->next)!=NULL; p1=(p1->next)){
		for(p2=head; (p2->next)!=p1; p2=(p2->next)){
			if(i==1){
				if(strcmp((p1->name),(p2->name))<0){
					printf("SWAP P1 %x P1->NEXT %x P2 %x P2->NEXT %x\n",p1,p1->next,p2,p2->next);
					swap(head, p1, p2);
					printf("SWAP P1 %x P1->NEXT %x P2 %x P2->NEXT %x\n",p1,p1->next,p2,p2->next);
				}
			}else{
				if(strcmp((p1->tele),(p2->tele))<0){
					swap(head, p1, p2);
				}
			}
		}
	}
}

