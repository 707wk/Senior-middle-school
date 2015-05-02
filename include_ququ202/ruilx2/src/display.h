#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "struct.h"
#define STR struct
#define CON contacts
void display(STR CON *p);
STR CON *create(void);
STR CON *find(STR CON *p);
int del(STR CON *p0);
int ins(STR CON *p0);
void printstat(int *st);
#endif
