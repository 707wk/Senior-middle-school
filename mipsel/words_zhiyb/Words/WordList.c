/**************************************
 *FILE    :WordList.c
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :1/2/2013
***************************************/

#include "Common.h"
#include "WordList.h"

static char init = 0;
static short clr_lbkg;

void InitWordList(void)
{
  if (init > 0) return;
  //Background
  clr_lbkg = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  init++;
  return;
}

void WordList(struct words_info *words)
{
  int i;
  struct words_p *p = words->p;
  if (words->order < 5)
    words->p = words->f;
  else
    words->order -= 10;
  do {
    p->tmp = 0; p = p->next;
  } while (p != words->p);
_next:
  clear();
  border('|', '|', '-', '-', '+', '+', '+', '+');
  _mvchgrectat(1, 1, getmaxy(stdscr) - 2, getmaxx(stdscr) - 2, 0, clr_lbkg, NULL);
  i = (getmaxy(stdscr) - 5) / 3;
  mvaddstr(i + 1, 1, words->p->word);
  mvaddstr(i + 2, 1, words->p->mean);
  move(getmaxy(stdscr) - i - 2, 1);
  addstr("Next...");
  printw(" %d", words->p->tmp);
  refresh();
  switch (getch()) {
  case KEY_LEFT:
    words->p->tmp = 1;
  };
  return;
}
