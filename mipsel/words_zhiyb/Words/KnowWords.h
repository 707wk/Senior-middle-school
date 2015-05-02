/**************************************
 *FILE    :KnowWords.h
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :6/15/2012
***************************************/

#ifndef _Z_WORDS_KNOWWORDS_H
#define _Z_WORDS_KNOWWORDS_H

//words_info and words_p structs
#include "Load.h"

//Initialize colors
void InitKnowWords(void);

//Study the words. (Know mode)
//Parameter: words_info pointer;
void KnowWords(struct words_info *);

#endif
