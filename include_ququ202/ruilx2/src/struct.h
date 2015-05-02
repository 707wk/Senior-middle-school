#ifndef _STRUCT_H_
#define _STRUCT_H_

struct date{
	int year;
	int month;
	int day;
};

struct contacts{
	char name[20];
	char tele[15];
	char fixtel[15];
	char addr[50];
	char email[40];
	struct date birth;
	struct contacts *next;
};

#endif
