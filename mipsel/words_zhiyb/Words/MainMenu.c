/**************************************
 *FILE    :MainMenu.c
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :1/5/2012
***************************************/

#include "Common.h"
#include "MainMenu.h"

static char init = 0;
static short clr_ides, clr_con, clr_igvn, clr_ibkg;
static short clr_obkg, clr_ottl, clr_oopt, clr_otip;

void InitMainMenu(void)
{
  if (init > 0) return;
  InitWriteWords();
  InitKnowWords();
  InitWordList();
  //Color for information description
  clr_ides = _alloc_color(COLOR_RED, COLOR_WHITE);
  //Color for `press any key to continue' message
  clr_con = _alloc_color(COLOR_WHITE, COLOR_BLUE);
  //Color for information - given
  clr_igvn = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for information - background
  clr_ibkg = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for option - background
  clr_obkg = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for option - title
  clr_ottl = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for option - options
  clr_oopt = _alloc_color(COLOR_CYAN, COLOR_WHITE);
  //Color for option - tips
  clr_otip = _alloc_color(COLOR_WHITE, COLOR_GREEN);
  init++;
}

unsigned char DisInfo(struct words_info *words)
{
  char *path, *size, *wrdf, *wrdl;
  int i, len = 0, key;
_resize:
  path = _cut(1, getmaxx(stdscr) - 14, words->fpath);
  size = _husize(words->size);
  for (i = 0; i < 6; i++)
    len += _intlength(words->num[i]);
  len += 7;
  wrdf = _cut(2, getmaxx(stdscr) - 14, words->p->mean);
  wrdl = _cut(2, getmaxx(stdscr) - 14, words->p->prev->mean);
  len = _max(strlen(path), _max(strlen(size), _max(len, _max(strlen(wrdf), strlen(wrdl))))) + 12;
  clear();
  border('|', '|', '-', '-', '+', '+', '+', '+');
  _mvchgrectat(1, 1, getmaxy(stdscr) - 2, getmaxx(stdscr) - 2, 0, clr_ibkg, NULL);
  i = (getmaxy(stdscr) - 8) / 2 + 1;
  attron(COLOR_PAIR(clr_ides));
  mvaddstr(i++, 1, "单词表文件: ");
  mvaddstr(i++, 1, "文件大小:   ");
  mvaddstr(i++, 1, "单词个数:   ");
  mvaddstr(i++, 1, "第一个单词: ");
  mvprintw(i++, 1, "最后一个:   ");
  attroff(COLOR_PAIR(clr_ides));
  attron(COLOR_PAIR(clr_con) | A_BOLD);
  mvaddstr(i++, 1, "按回车键继续,返回键返回...");
  attroff(COLOR_PAIR(clr_con) | A_BOLD);
  i = (getmaxy(stdscr) - 8) / 2 + 1;
  attron(COLOR_PAIR(clr_igvn));
  mvaddstr(i++, 13, path);
  mvaddstr(i++, 13, size);
  mvprintw(i++, 13, "%d (%d/%d/%d/%d/%d)", words->num[0], words->num[1], words->num[2], words->num[3], words->num[4], words->num[5]);
  mvaddstr(i++, 13, wrdf);
  mvaddstr(i++, 13, wrdl);
  attroff(COLOR_PAIR(clr_igvn));
  refresh();
  while (key = getch(), key != '\n' && key != 033)
    goto _resize;
  free(path); free(size); free(wrdf); free(wrdl);
  return key != 033;
}

unsigned char FunctionMenu(struct words_info *words)
{
  unsigned int i, j;
_refresh:
  clear();
  border('|', '|', '-', '-', '+', '+', '+', '+');
  _mvchgrectat(1, 1, getmaxy(stdscr) - 2, getmaxx(stdscr) - 2, 0, clr_obkg, NULL);
  attron(COLOR_PAIR(clr_ottl));
  mvaddstr(1, (getmaxx(stdscr) - 16) / 2, "Words - 学习方式");
  attroff(COLOR_PAIR(clr_ottl));
  i = (getmaxy(stdscr) - 6) / 4;
  j = (getmaxx(stdscr) - 12 ) / 2;
  attron(COLOR_PAIR(clr_oopt) | A_BOLD);
  mvaddstr(2 + (getmaxy(stdscr) - 6 - 2 * i) / 2, j, "[↑]记默模式");
  mvaddstr(getcury(stdscr) + 1 + i, (getmaxx(stdscr) - 24) / 3, "[←]认知模式");
  mvaddstr(getcury(stdscr), ((getmaxx(stdscr) - 24) / 3) * 2 + 12, "[→]检测模式");
  mvaddstr(getcury(stdscr) + 1 + i, j, "[↓]进入设置");
  attroff(COLOR_PAIR(clr_oopt));
  i = (getmaxx(stdscr) - 36) / 4;
  attron(COLOR_PAIR(clr_otip));
  mvaddstr(getcury(stdscr), j - i - 12, "[输入]单词表");
  mvaddstr(getcury(stdscr), j + i + 12, "[返回]返回");
  attroff(COLOR_PAIR(clr_otip) | A_BOLD);
  refresh();
_getkey:
  switch (getch()) {
  case KEY_UP:
    return 2;
  case KEY_DOWN:
    return 4;
  case KEY_LEFT:
    return 1;
  case KEY_RIGHT:
    return 3;
  case '\n':
    return 5;
  case 033:
    return 0;
  case KEY_RESIZE:
    goto _refresh;
  default:
    goto _getkey;
  }
  return 0;
}

void DisWords(struct words_info *words)
{
  struct words_p *p = words->p;
  clear();
  printw("%s\n单词数: %d\n", words->fpath, words->num[0]);
  refresh();
  getch();
  while (p != NULL) {
    clear();
    printw("%s\n%s\n", p->word, p->mean);
    p = words->order == 0 ? p->prev : p->next;
    refresh();
    getch();
  }
}
