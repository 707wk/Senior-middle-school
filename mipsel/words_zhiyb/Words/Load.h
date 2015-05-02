/**************************************
 *FILE    :Load.h
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :1/5/2012
***************************************/

#ifndef _Z_WORDS_LOAD_H
#define _Z_WORDS_LOAD_H

//Stores words.
struct words_p {
  struct words_p *prev;  //The previous word.
  struct words_p *next;  //The next word.
  char *word, *mean;  //This word and its mean.
  int level;  //This word's level.
  int tmp;  //Temporary data while running.
};

//Stores the file's information.
struct words_info {
  struct words_p *p;  //The initial word.
  struct words_p *f;  //The first word.
  char *fpath;  //The file's path.
  unsigned char order, reset;
  unsigned int num[6];  //Sums and order.
  unsigned int size;  //The file's size(byte).
};

//Load the words list file.
//Parameter: the path of the file.
//It returns the initialized words_info struct.
struct words_info *Load(char *);

#endif
