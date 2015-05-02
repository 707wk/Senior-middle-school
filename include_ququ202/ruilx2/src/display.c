/* Display.c made by Ruilx Alxa */

/* 2013 06 04 13 49 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "display.h"

#include "slowprint.h"
#include "struct.h"
#include "checkdate.h"
#include "getch.h"
#include "input.h"

#define PRINT "%-12s|%11s|%14s|%29s|%19s|%4d-%02d-%02d\n",p->name,p->tele,p->fixtel,p->addr,p->email,p->birth.year,p->birth.month,p->birth.day
#define N sizeof(struct contacts)
#define CON contacts
#define STR struct
//#define PTST(a,b) #a" Group Has "#b" contacts.\n"

void display(STR CON *p){
	p=p->next;
	printf("Name--------+Telephone--+FixedTele-----+Addr-------------------------+E-mail-------------+Birthday--\n");
	while(p != NULL){
		printf(PRINT);
		usleep(100000);
		fflush(stdout);
		p=p->next;
	}
	printf("--------Name+--Telephone+-----FixedTele+-------------------------Addr+-------------E-mail+--Birthday\n");
}

STR CON *create(void){
	STR CON *p1, *p2, *head;
	head=p2=(STR CON *)malloc(N);
	p1=(STR CON *)malloc(N);
input:
	slowprint("Please Enter name telephone fixedtelephone address E-mail birthday\n",20);
	/*
	do{
		fflush(stdin);
		scanf("%s%s%s%s%s%d%d%d",p1->name,p1->tele,p1->fixtel,p1->addr,p1->email,&p1->birth.year,&p1->birth.month,&p1->birth.day);
	}while(strlen(p1->name)>12 && strlen(p1->tele)>12 && strlen(p1->fixtel)>15 && strlen(p1->addr)>30 && strlen(p1->email)>20 \
		&& !Checkyear(p1->birth.year) && !Checkmonth(p1->birth.month) && !Checkday(p1->birth.day, p1->birth.month, p1->birth.year));
	*/
	slowprint("\tEnter Name: ",30);
	inputstr(p1->name,12);
	slowprint("\tEnter Telephone: ",30);
	inputnumstr(p1->tele,10);
	slowprint("\tEnter Fixed-Telephone: ",30);
	inputnumstr(p1->fixtel,14);
	slowprint("\tEnter Address: ",30);
	inputstr(p1->addr,29);
	slowprint("\tEnter E-mail address: ",30);
	inputstr(p1->email,19);
	slowprint("\tChoose your birthday: ",30);
	inputdate(&(p1->birth.year), &(p1->birth.month), &(p1->birth.day));
	
askconti:
	slowprint("Do you want to type next?[ Y/n ]:",20);
/*	scanf("%c",&conti);
	if(conti == 'n' || conti == 'N'){
		goto nextstep;
	}else if(conti == 'y' || conti == 'Y'){
		p2->next = p1;
		p2 = p1;
		p1 = (STR CON *)malloc(N);
		goto input;
	}else goto askconti;
*/
	switch(getch()){
		case 'Y':
		case 'y':
			p2->next = p1;
			p2 = p1;
			p1 = (STR CON *)malloc(N);
			goto input;
			break;
		case 'N':
		case 'n':
			break;
		default :
			goto askconti;
			break;
	}
	p2->next = NULL;
	free(p1);
	return head;
}

STR CON *find(STR CON *p){
	char name[12];
	slowprint("Please Enter name what you wanna find: ",20);
	scanf("%s",name);
	while(p->next != NULL){
		p=p->next;
		if(strcmp(p->name, name)==0){
			return p;
		}
	}
	return NULL;
}

int del(STR CON *p0){
	char name[12];
	STR CON *p;
	p=p0->next;
	if(p==NULL){
		return 0;
	}
	slowprint("Please Enter name what you wanna delete: ",20);
	scanf("%s",name);
	while(p != NULL){
		if(strcmp(p->name, name)==0){
			p0->next = p->next;
			free(p);
			return 1;
		}
		p0=p;
		p=p->next;
	}
	return 0;
}

int ins(STR CON *p0){
	STR CON *p;
	p=(STR CON *)malloc(N);
	slowprint("Please Enter Insert name telephone fixedtelephone address E-mail birthday\n",20);
	fflush(stdin);
	/*
	scanf("%s%s%s%s%s%d%d%d",p->name,p->tele,p->fixtel,p->addr,p->email,&p->birth.year,&p->birth.month,&p->birth.day);
	*/
	slowprint("\tEnter Name: ",30);
        inputstr(p->name,12);
        slowprint("\tEnter Telephone: ",30);
        inputnumstr(p->tele,10);
        slowprint("\tEnter Fixed-Telephone: ",30);
        inputnumstr(p->fixtel,14);
        slowprint("\tEnter Address: ",30);
        inputstr(p->addr,29);
        slowprint("\tEnter E-mail address: ",30);
        inputstr(p->email,19);
        slowprint("\tChoose your birthday: ",30);
        inputdate(&(p->birth.year), &(p->birth.month), &(p->birth.day));

	while(p0->next != NULL && strcmp(p0->next->name, p->name)==0){
		p0=p0->next;
	}
	if(p0->next != NULL && strcmp(p0->next->name, p->name)==0){
		free(p);
		return 0;
	}
	p->next = p0->next;
	p0->next = p;
	return 1;
}

void ptst(char a, int i){
	printf("\t%c Group has %d contact(s).\n", a, i);
}

void printstat(int *st){
	int ct;
	printf("There are %d Person in this contacts.\n", st[28]);
	for(ct=0; ct<26; ct++){
		fflush(stdout);
		ptst((ct+65),st[ct]);
		usleep(150000);
	}
	printf("\t# Group has %d contact(s).\n",st[26]);
	fflush(stdout);
	usleep(150000);
	printf("\tOther Group has %d contact(s).\n",st[27]);
}

