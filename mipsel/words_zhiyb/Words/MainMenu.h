/**************************************
 *FILE    :MainMenu.h
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :1/5/2012
***************************************/

#ifndef _Z_WORDS_RECITE_H
#define _Z_WORDS_RECITE_H

//words_info and words_p structs
#include "Load.h"
//Word list function
#include "WordList.h"
//Write the words from memory
#include "WriteWords.h"
//Study the words (Know mode)
#include "KnowWords.h"

//Initialize all functions in recite part.
void InitMainMenu(void);

//Display the words' info.
//Parameter: words_info pointer.
//Return whether to continue(1) or not(0).
unsigned char DisInfo(struct words_info *);

//Choose the options to recite.
//Parameter: words_info pointer;
unsigned char FunctionMenu(struct words_info *);

//Cyclical display all the words.
//Parameters: words_info pointer;
void DisWords(struct words_info *);

#endif
