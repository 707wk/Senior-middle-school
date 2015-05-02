/**************************************
 *FILE    :Fopen.h
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :2/10/2012
***************************************/

#ifndef _Z_COMMON_FOPEN_H
#define _Z_COMMON_FOPEN_H

//Initialize the Fopen function.
void InitFopen(void);

//Fopen function.
//Parameter: the initial directory, the selected file.
//It returns the path of the chosen file or NULL for cancel.
//The returned string needs to be freed if useless.
char *Fopen(const char *, const char *);

#endif
