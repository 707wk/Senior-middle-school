/**************************************
 *FILE    :List.h
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :12/30/2011
***************************************/

#ifndef _Z_COMMON_LIST_H
#define _Z_COMMON_LIST_H

//Undesigned. Just test codes.

struct list_data {
  char *dis;
  char *argc[10];
  int argi[10];
  struct list_data *next;
};

struct list_data *list_push(struct list_data *);
void List(struct list_data *);

#endif
