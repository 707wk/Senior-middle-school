/**************************************
 *FILE    :WordList.h
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :1/2/2013
***************************************/

#ifndef _Z_WORDS_WORDLIST_H
#define _Z_WORDS_WORDLIST_H

//structs. words_info & words_p
#include "Load.h"

//Initialise colors
void InitWordList(void);

//Word List function
//Parameter: words_info pointer
void WordList(struct words_info *words);

#endif
