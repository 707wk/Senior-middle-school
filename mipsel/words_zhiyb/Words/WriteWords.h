/**************************************
 *FILE    :WriteWords.h
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :5/18/2012
***************************************/

#ifndef _Z_WORDS_WRITEWORDS_H
#define _Z_WORDS_WRITEWORDS_H

//words_info and words_p structs
#include "Load.h"

//Initialize all functions in this part.
void InitWriteWords(void);

//Write the words from memory.
//Parameters: words_info pointer;
void WriteWords(struct words_info *);

#endif
