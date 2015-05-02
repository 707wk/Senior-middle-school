/**************************************
 *FILE    :WriteWords.c
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :5/18/2012
***************************************/

#include "Common.h"
#include "WriteWords.h"

static char init = 0;
static short clr_wbkg, clr_wttl, clr_wmn, clr_winw, clr_winr, clr_wmsg, clr_wmop, clr_wmcu;

void InitWriteWords(void)
{
  if (init > 0) return;
  //Color for write mode - background
  clr_wbkg = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for write mode - title
  clr_wttl = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for write mode - word's means
  clr_wmn = _alloc_color(COLOR_RED, COLOR_WHITE);
  //Color for write mode - input wrong chars
  clr_winw = _alloc_color(COLOR_YELLOW, COLOR_BLUE);
  //Color for write mode - input right chars
  clr_winr = _alloc_color(COLOR_GREEN, COLOR_BLUE);
  //Color for write mode - message texts
  clr_wmsg = _alloc_color(COLOR_CYAN, COLOR_WHITE);
  //Color for write mode - menu - option
  clr_wmop = _alloc_color(COLOR_WHITE, COLOR_BLUE);
  //Color for write mode - menu - current option
  clr_wmcu = _alloc_color(COLOR_YELLOW, COLOR_GREEN);
  init++;
}

void WriteWords(struct words_info *words)
{
  unsigned char refresh, confirm, menu = 0, gotonext;
  unsigned char *input = NULL;
  unsigned int pos = 0, i, j, wrong;
  int key;
  struct words_p *p = words->p;
  if (words->order < 5)
    words->p = words->f;
  else
    words->order -= 10;
  do {
    p->tmp = 0; p = p->next;
  } while (p != words->p);
_restart:
  pos = 0; confirm = 0;
  free(input);
  input = calloc(sizeof(char), strlen(words->p->word) + 1);
  memset(input, ' ', strlen(words->p->word));
  curs_set(1);
_refresh:
  refresh = 1;
  clear();
  border('|', '|', '-', '-', '+', '+', '+', '+');
  _mvchgrectat(1, 1, getmaxy(stdscr) - 2, getmaxx(stdscr) - 2, 0, clr_wbkg, NULL);
  attron(COLOR_PAIR(clr_wttl)/* | A_BOLD*/);
  mvaddstr(1, (getmaxx(stdscr) - 16) / 2, "Words - 记默模式");
  attroff(COLOR_PAIR(clr_wttl)/* | A_BOLD*/);
  j = (getmaxy(stdscr) - 5) / 3;
  attron(COLOR_PAIR(clr_wmn));
  mvaddstr(2 + j, 4, words->p->mean);
  attroff(COLOR_PAIR(clr_wmn));
  move(getmaxy(stdscr) - j - 2, 4);
_input:
  move(getcury(stdscr), 4);
  for (i = 0, wrong = 0; i < strlen(words->p->word); i++)
    if (*(input + i) != *(words->p->word + i))
      wrong++, addch(*(input + i) | COLOR_PAIR(clr_winw) | A_BOLD);
    else
      addch(*(input + i) | COLOR_PAIR(clr_winr) | A_BOLD);
  if (!wrong)
    if (!refresh) goto _refresh; else goto _next;
  else if (confirm) goto _next;
  if (menu) {
    i = (getmaxx(stdscr) - 32) / 4;
    attron(COLOR_PAIR(menu == 1 ? clr_wmcu : clr_wmop) | A_BOLD);
    mvaddstr(2 + (getmaxy(stdscr) - 3) / 2, 1 + (getmaxx(stdscr) - 2 * i - 32) / 2, "[上一单词]");
    attroff(COLOR_PAIR(menu == 1 ? clr_wmcu : clr_wmop));
    attron(COLOR_PAIR(menu == 2 ? clr_wmcu : clr_wmop));
    mvaddstr(getcury(stdscr), getcurx(stdscr) + i, "[提示字母]");
    attroff(COLOR_PAIR(menu == 2 ? clr_wmcu : clr_wmop));
    attron(COLOR_PAIR(menu == 3 ? clr_wmcu : clr_wmop));
    mvaddstr(getcury(stdscr), getcurx(stdscr) + i, "[下一单词]");
    attroff(COLOR_PAIR(menu == 3 ? clr_wmcu : clr_wmop) | A_BOLD);
  }
  move(getmaxy(stdscr) - j - 2, 4 + pos);
  refresh();
  refresh = 0;
_getch:
  key = getch();
  if (menu)
    switch (key) {
    case KEY_LEFT:
      menu -= menu != 1;
      goto _refresh;
    case KEY_RIGHT:
      menu += menu != 3;
      goto _refresh;
    case KEY_DOWN:
    case 033:
      menu = 0;
    case KEY_RESIZE:
      goto _refresh;
    case '\n':
      switch (menu) {
      case 1:
        menu = 0; gotonext = 0;
        goto _goto;
      case 2:
        *(input + pos) = *(words->p->word + pos);
        pos += pos + 1 != strlen(words->p->word);
        goto _input;
      case 3:
        menu = 0; gotonext = 1;
        goto _goto;
      }
    default:
      goto _getch;
    }
  switch (key) {
  case KEY_RIGHT:
    pos += pos + 1 != strlen(words->p->word);
    goto _input;
  case KEY_UP:
    menu = 2;
    goto _refresh;
  case KEY_DOWN:
    goto _restart;
  case 033:
    curs_set(0);
    return;
  case '\t':
    *(input + pos) = *(words->p->word + pos);
    pos += pos + 1 != strlen(words->p->word);
    goto _input;
  case '\n':
    confirm = 1;
  case KEY_RESIZE:
    goto _refresh;
  case KEY_DC:
  case KEY_BACKSPACE:
  case 127:
    //*(input + pos/* - 1*/) = ' ';
  case KEY_LEFT:
    pos -= pos != 0;
    goto _input;
  default:
    if (key < 0 || key > 127) goto _getch;
    *(input + pos) = (char)key;
    if (pos + 1 < strlen(words->p->word))
      pos++;
    goto _input;
  };
_next:
  menu = 0;
  curs_set(0);
  attron(COLOR_PAIR(clr_wmsg) | A_BOLD);
  if (!wrong)
    mvaddstr(getmaxy(stdscr) - 2, (getmaxx(stdscr) - 29) / 2, "正确! 按任意键继续下一单词...");
  else
    mvaddstr(getmaxy(stdscr) - 2, (getmaxx(stdscr) - 35) / 2, "错误! [输入]下一单词/[返回]继续输入");
  attroff(COLOR_PAIR(clr_wmsg) | A_BOLD);
  refresh();
_getkey:
  switch (getch()) {
  case 033:
    if (wrong) {
      confirm = 0;
      curs_set(1);
      goto _refresh;
    } else break;
  case KEY_RESIZE:
    goto _refresh;
  case -1:
    goto _getkey;
  case '\n':
    if (wrong) break;
  default:
    if (wrong) goto _getkey;
  }
  if (words->order == 1)
    words->p = words->p->next;
  else if (words->order == -1)
    words->p = words->p->prev;
  if (words->p != words->f)
    goto _restart;
  free(input);
  return;
_goto:
  if (words->order == 1)
    words->p = (gotonext ? words->p->next : words->p->prev);
  else if (words->order == -1)
    words->p = (gotonext ? words->p->prev : words->p->next);
  if (gotonext) {
    if (words->p == words->f)
      words->p = words->f->prev;
  } else {
    if (words->p == words->f->prev)
      words->p = words->f;
  }
  goto _restart;
}
