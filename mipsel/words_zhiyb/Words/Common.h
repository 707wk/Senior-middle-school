/**************************************
 *FILE    :Common.h
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :12/26/2011
***************************************/

#ifndef _Z_COMMON_COMMON_H
#define _Z_COMMON_COMMON_H

//Debug mode
#define debug

//Include files
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>

//For debug
#ifdef debug
#define CL clear();
#define SS(m) printw("d%is " #m " = %s\n", ++_debug_, (m));
#define SI(m) printw("d%ii " #m " = %i\n", ++_debug_, (m));
#define SM(m) printw("d%im %s\n", ++_debug_, (m));
#define BP refresh(); getch();
int _debug_;
#else
#define CL
#define SS(m)
#define SI(m)
#define SM(m)
#define BP
#endif

//Find the minimum of two parameters.
#define MIN(m,n) ((m) > (n) ? (n) : (m))
//Find the maximum of two parameters.
#define MAX(m,n) ((m) > (n) ? (m) : (n))
//Swap two parameters.
#define SWAP(m,n) \
  (m) = (m) ^ (n);\
  (n) = (m) ^ (n);\
  (m) = (m) ^ (n);

//Find the correct position of a string.
#define _WSTRPOS(m,n) (_wstrpos((m), _strpos((m),(n))))

//Swap two strings.
void _strswap(char *, char *);
//Split the path into dir name and file name.
//_splitpath(path, &dirname, &filename);
//dirname and filename need to be free if useless.
void _splitpath(char *, char **, char **);
//Change the chars' attribute within a rectangle area.
//Parameters: y0, x0, y, x, attribute, color pair, NULL.
void _mvchgrectat(int, int, int, int, attr_t, short, const void *);
//Malloc a new pointer to store the string.
//The returned string needs to be free.
char *_getstr(char *);
//Return a human readable string from the size in byte.
//The returned string needs to be free.
char *_husize(int);
//Read 1 line from a FILE type pointer.
//The returned string needs to be free.
char *_freadline(FILE *);
//Intercept a string.
//Parameters: type, length, string.
//types: 0-cut from left/1-cut from right/
//       2-cut from left, and add `...' at the end.
//The returned string needs to be free.
char *_cut(char, int, char []);
//Determin the sequence of two strings.
//Sequences: signs, numbers, uppers, lowers, two bytes chars.
//Return 1: string1 should below string2.
char _larger(unsigned char *, unsigned char *);
//Arrange the strings.
//Change TAB and return to space.
//The returned string needs to be free.
char *_arrange(char *);
//Return the count of color pairs.
short _getcolorcnt(void);
//Alloc a number's number and initialise it
short _alloc_color(int, int);
//Find how many entries(include `..') in a DIR type pointer.
int _fnum(DIR *);
//Return the length of a string which may have two bytes chars.
int _wstrlen(char *);
//Return the position(byte) in a string.
int _strpos(char *, int);
//Return the position(char) in a string.
//If the position is in a two bytes char, will turn to the previous.
int _nstrpos(char *, int);
//Return the position(char) in a string.
//If the position is in a two bytes char, will turn to the next.
int _wstrpos(char *, int);
//Return a integer's display length.
int _intlength(int i);
//Return the maximum. Sometimes quicker.
int _max(int, int);
//Return the minimum. Sometimes quicker.
int _min(int, int);

#endif
