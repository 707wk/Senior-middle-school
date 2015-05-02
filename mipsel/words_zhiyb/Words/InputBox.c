/**************************************
 *FILE    :InputBox.c
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :12/20/2011
***************************************/

#include "Common.h"
#include "InputBox.h"

#define WIN_Y ((getmaxy(stdscr) - 5) / 2)
#define WIN_X ((getmaxx(stdscr) - len - 4) / 2)
#define POS (_wstrpos((char *)input, pos))
#define DISPOS (_wstrpos((char *)input, dispos))

static char init = 0;
static short clr_bkg, clr_nptchr, clr_nptspc, clr_ttl, clr_pnum, clr_tnum;
static int dispos;

void InitInputBox(void)
{
  if (init > 0) return;
  //Color for back ground
  clr_bkg = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for input chars
  clr_nptchr = _alloc_color(COLOR_YELLOW, COLOR_BLUE);
  //Color for input spaces
  clr_nptspc = _alloc_color(COLOR_WHITE, COLOR_BLUE);
  //Color for title
  clr_ttl = _alloc_color(COLOR_RED, COLOR_WHITE);
  //Color for currency position number
  clr_pnum = _alloc_color(COLOR_YELLOW, COLOR_GREEN);
  //Color for total number and maximum number
  clr_tnum = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  init++;
}

static void _boxdis (char *msg, char *input, int pos, int max)
{
  char *p;
  int i, j, len = strlen(msg);
  clear ();
  border ( '|', '|', '-', '-', '+', '+', '+', '+' );
  j = _intlength(max - 1);
  len = MAX(len, j * 3 + 2);
  j += _intlength(strlen(input)) + _intlength(POS) + 2;
  _mvchgrectat(WIN_Y, WIN_X, 5, len + 4, 0, clr_bkg, NULL);
  move(WIN_Y + 1, WIN_X + 2);
  attron(COLOR_PAIR(clr_ttl));
  addstr(msg);
  attroff(COLOR_PAIR(clr_ttl));
  move(WIN_Y + 2, WIN_X + len - j + 2);
  attron(COLOR_PAIR(clr_pnum) | A_BOLD);
  printw("%d", POS);
  attroff(COLOR_PAIR(clr_pnum) | A_BOLD);
  addch(' ' | COLOR_PAIR(clr_bkg));
  attron(COLOR_PAIR(clr_tnum));
  printw("%d/%d", strlen(input), max - 1);
  attroff(COLOR_PAIR(clr_tnum));
  move(WIN_Y + 3, WIN_X + 1);
  i = POS - DISPOS;
  if (i < len / 3)
    dispos = _strpos(input, _max(0, POS - len / 3));
  else if (i > len / 3 * 2)
    dispos = _nstrpos(input, _min(strlen(input) + 1 - len, POS - len / 3 * 2));
  addch(COLOR_PAIR(clr_bkg) | (dispos == 0 ? ' ' : '<'));
  attron(COLOR_PAIR(clr_nptchr) | A_BOLD);
  addnstr(p = _arrange(&input[DISPOS]), _WSTRPOS(input, DISPOS + len) - DISPOS);
  free(p);
  attroff(COLOR_PAIR(clr_nptchr));
  attron(COLOR_PAIR(clr_nptspc));
  while (getcurx(stdscr) != WIN_X + 2 + len) addch(' ');
  attroff(COLOR_PAIR(clr_nptspc) | A_BOLD);
  addch(COLOR_PAIR(clr_bkg) | (DISPOS < (int)strlen(input) + 1 - len ? '>' : ' '));
  move(WIN_Y + 3, WIN_X + 2 + pos - dispos );
  refresh ();
}

char *InputBox ( /*bool bksave, int bkmax,*/ int max, /*char *bkfile*/ char *msg, char *init )
{
  unsigned char *p;
  unsigned char input[max += max == 0 ? 1025 : 1];
  int key, pos = _wstrlen(init), strpos;
  dispos = 0;
  curs_set(1);
  strcpy((char *)input, init);
  while(1)
  {
    _boxdis(msg, (char *)input, pos, max);
    switch (key = getch()) {
    case KEY_UP:
      break;
    case KEY_DOWN:
      input[0] = '\0';
      pos = 0;
      break;
    case KEY_LEFT:
      pos = MAX(0, pos - 1);
      break;
    case KEY_RIGHT:
      pos = MIN(_wstrlen((char *)input), pos + 1);
      break;
    case KEY_RESIZE:
      break;
    case 033:
      curs_set(0);
      return NULL;
    case '\n':
      curs_set(0);
      return _getstr((char *)input);
    case KEY_DC:
    case KEY_BACKSPACE:
    case 127:
      strpos = POS;
      strcpy((char *)&input[strpos == 0 ? 0 : _wstrpos((char *)input, pos - 1)], (char *)&input[strpos == 0 ? _wstrpos((char *)input, 1) : strpos]);
      pos -= pos != 0;
      break;
    default:
      if (key > 255 || key < 0) break;
      if (isascii(key) && (int)strlen((char *)input) > max - 2) break;
      if (!isascii(key) && (int)strlen((char *)input) > max - 3) {
        getch();
        break;
      }
      strpos = POS;
      p = malloc(strlen((char *)input) - strpos + 1);
      strcpy((char *)p, (char *)&input[strpos]);
      input[strpos] = key;
      if (!isascii(key))
        input[strpos + 1] = getch();
      pos++;
      strcpy((char *)&input[strpos + 1 + !isascii(key)], (char *)p);
      free(p);
    }
  }
}
