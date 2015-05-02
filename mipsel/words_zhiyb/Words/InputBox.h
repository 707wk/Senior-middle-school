/**************************************
 *FILE    :InputBox.h
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :2/10/2012
***************************************/

#ifndef _Z_COMMON_INPUTBOX_H
#define _Z_COMMON_INPUTBOX_H

//Initialize the InputBox function.
void InitInputBox(void);

//InputBox function.
//Parameters: maximum inputs, title, initial chars.
//It returns the final inputs or NULL for cancel.
//The returned string needs to be freed if useless.
char *InputBox(int, char *, char*);

#endif
