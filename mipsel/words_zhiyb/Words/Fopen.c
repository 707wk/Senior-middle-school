/**************************************
 *FILE    :Fopen.c
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :11/23/2011
***************************************/

#include "Common.h"
#include "Fopen.h"
#include "InputBox.h"

#define CNUM 256
#define LNUM 2
#define STNUM 2
#define FORM_LINES 6
#define LIST_Y 4
#define LIST_LINES ( getmaxy ( stdscr ) - FORM_LINES )
#define LDISY MIN ( LIST_LINES, FNUM )
#define LISTI ddata.listi
#define ILIST ddata.ilist
#define FNUM ddata.fnum
#define IFOCUS ddata.ifocus
#define ISORT ddata.isort
#define L_NAME(m) list[(int)(m)][0]
#define L_PATH(m) list[(int)(m)][1]
#define L_TYPE(m) st[(int)(m)][0]
#define L_SIZE(m) st[(int)(m)][1]
#define L_REFRESH() (LISTI = MIN(MAX(MIN(MAX(LISTI, ILIST - LIST_LINES + 1), FNUM - LIST_LINES), 0), ILIST))

typedef struct _disdatas
{
  int fnum, listi, ilist, ifocus, isort;
} DIS;

DIS ddata;

static char init;
static short clr_ttl, clr_mn, clr_ddrss, clr_lbl, clr_fcs, clr_rrw, clr_lst, clr_scrll, clr_bttn, clr_bsel;

void InitFopen(void)
{
  if (init > 0) return;
  InitInputBox();
  //Color for title
  clr_ttl = _alloc_color(COLOR_WHITE, COLOR_BLUE);
  //Color for menu button
  clr_mn = _alloc_color(COLOR_WHITE, COLOR_BLUE);
  //Color for address bar
  clr_ddrss = _alloc_color(COLOR_WHITE, COLOR_RED);
  //Color for labels
  clr_lbl = _alloc_color(COLOR_WHITE, COLOR_RED);
  //Color for label's arrow
  clr_rrw = _alloc_color(COLOR_BLUE, COLOR_WHITE);
  //Color for file list
  clr_lst = _alloc_color(COLOR_BLACK, COLOR_WHITE);
  //Color for focus item in file list
  clr_fcs = _alloc_color(COLOR_WHITE, COLOR_BLUE);
  //Color for scroll bar
  clr_scrll = _alloc_color(COLOR_BLUE, COLOR_WHITE);
  //Color for buttons
  clr_bttn = _alloc_color(COLOR_WHITE, COLOR_BLUE);
  //Color for selected button
  clr_bsel = _alloc_color(COLOR_YELLOW, COLOR_GREEN);
  init++;
}

static void _sort(unsigned char list[][LNUM][CNUM], int st[][STNUM])
{
  char j = 1, k;
  int i;
  for (k = 0; k < 2; k++, j = 1)
    while (j != 0) {
      i = 2; j = 0;
      while (i < FNUM) {
        if (k ^ S_ISDIR(L_TYPE(i - 1)) && k ^ S_ISDIR(L_TYPE(i)) && _larger(L_NAME(i - (ISORT != 1)), L_NAME(i - (ISORT == 1)))) {
          _strswap((char *)L_NAME(i - 1), (char *)L_NAME(i));
          _strswap((char *)L_PATH(i - 1), (char *)L_PATH(i));
          SWAP(L_TYPE(i - 1), L_TYPE(i));
          SWAP(L_SIZE(i - 1), L_SIZE(i));
          ILIST -= ILIST == i ? 1 : 0 - (ILIST == i - 1);
          j = 1;
        }
        i++;
      }
    }
  if (j = 1, ISORT > 1)
    while (j != 0) {
      i = 2; j = 0;
      while (i < FNUM) {
        if (!S_ISDIR(L_TYPE(i - 1)) && !S_ISDIR(L_TYPE(i)) && L_SIZE(i - 3 + ISORT) > L_SIZE(i - ISORT + 2)) {
          _strswap((char *)L_NAME(i - 1), (char *)L_NAME(i));
          _strswap((char *)L_PATH(i - 1), (char *)L_PATH(i));
          SWAP(L_TYPE(i - 1), L_TYPE(i));
          SWAP(L_SIZE(i - 1), L_SIZE(i));
          ILIST -= ILIST == i ? 1 : 0 - (ILIST == i - 1);
          j = 1;
        }
        i++;
      }
    }
  L_REFRESH();
}

static void _fdis(unsigned char list[][LNUM][CNUM], int st[][STNUM])
{
  char i, *o, *p, *q;
  i = (getmaxx(stdscr) - 18) / 3;
  clear();
  border('|', '|', '-', '-', '+', '+', '+', '+');
  mvchgat(1, 1, getmaxx(stdscr) - 2, A_BOLD, clr_ttl, NULL);
  mvchgat(2, 1, getmaxx(stdscr) - 2, 0, clr_ddrss, NULL);
  mvchgat(3, 1, getmaxx(stdscr) - 2, 0, clr_lbl, NULL);
  mvchgat(getmaxy(stdscr) - 2, 1, getmaxx(stdscr) - 2, 0, clr_bttn, NULL);
  _mvchgrectat(4, 1, getmaxy(stdscr) - 6, getmaxx(stdscr) - 2, 0, clr_lst, NULL);
  attron(COLOR_PAIR(clr_ttl) | A_BOLD);
  mvaddstr(1, i + 1, "打开文件");
  attroff(COLOR_PAIR(clr_ttl) | A_BOLD);
  attron(COLOR_PAIR(clr_mn) | A_BOLD);
  if (IFOCUS == -3) attron(COLOR_PAIR(clr_bsel));
  mvaddstr(1, i * 2 + 9, "[ 菜单 ]");
  if (IFOCUS == -3) attroff(COLOR_PAIR(clr_bsel));
  attroff(COLOR_PAIR(clr_mn) | A_BOLD);
  if (IFOCUS == -2) attron(A_REVERSE);
  attron(COLOR_PAIR(clr_ddrss));
  mvaddstr(2, 1, q = _arrange(p = _cut(1, getmaxx(stdscr) - 2, (o = getcwd(NULL, 0)))));
  free(o); free(q); free(p);
  attroff(COLOR_PAIR(clr_ddrss));
  if (IFOCUS == -2) attroff(A_REVERSE);
  if (IFOCUS == -1) attron(A_REVERSE);
  attron(COLOR_PAIR(clr_lbl));
  mvaddstr(3, 1, "文件名 ");
  attroff(COLOR_PAIR(clr_lbl));
  attron(COLOR_PAIR(clr_rrw));
  if (ISORT == 0) addstr("∨");
  else if (ISORT == 1) addstr("∧");
  attroff(COLOR_PAIR(clr_rrw));
  attron(COLOR_PAIR(clr_lbl));
  mvaddstr(3, getmaxx(stdscr) - 10, "大小 ");
  attroff(COLOR_PAIR(clr_lbl));
  attron(COLOR_PAIR(clr_rrw));
  if (ISORT == 2) addstr("∨");
  else if (ISORT == 3) addstr("∧");
  attroff(COLOR_PAIR(clr_rrw));
  if (IFOCUS == -1) attroff(A_REVERSE);
  move(LIST_Y, 0);
  for (i = LISTI; i < MIN(LIST_LINES + LISTI, FNUM); i++)
  {
    if (i == ILIST)
      if (IFOCUS == 0)
        attron(COLOR_PAIR(clr_lst) | A_REVERSE);
      else
        attron(COLOR_PAIR(clr_fcs));
    else
      attron(COLOR_PAIR(clr_lst));
    mvchgat(getcury(stdscr), 1, getmaxx(stdscr) - 2, 0, i == ILIST ? clr_fcs : clr_lst, NULL);
    mvaddstr(getcury(stdscr), 1, (p = _cut(2, getmaxx(stdscr) - 11, (char *)L_NAME(i))));
    free(p);
    if (i == ILIST)
      if (IFOCUS == 0) {
        attroff(COLOR_PAIR(clr_lst) | A_REVERSE);
        attron(COLOR_PAIR(clr_fcs));
      }
    move(getcury(stdscr), getmaxx(stdscr) - 10);
    if (S_ISDIR(L_TYPE(i))) addstr("<DIR>");
    else {
      addstr(p = _husize(L_SIZE(i))); free(p);
    }
    attroff(COLOR_PAIR(i == ILIST ? clr_fcs : clr_lst));
    if (IFOCUS == 1) attron(A_REVERSE);
    attron(COLOR_PAIR(clr_scrll));
    mvaddch(getcury(stdscr), getmaxx(stdscr) - 2, LDISY * ILIST / FNUM == i - LISTI ? '#' | A_BOLD : '|');
    attroff(COLOR_PAIR(clr_scrll));
    if (IFOCUS == 1) attroff(A_REVERSE);
    move(getcury(stdscr) + 1, 0);
  }
  i = (getmaxx(stdscr) - 18) / 3;
  attron(COLOR_PAIR(clr_bttn) | A_BOLD);
  if (IFOCUS == 2) attron(COLOR_PAIR(clr_bsel));
  mvaddstr(getmaxy(stdscr) - 2, i + 1, "[ 确定 ]");
  if (IFOCUS == 2) attroff(COLOR_PAIR(clr_bsel));
  attron(COLOR_PAIR(clr_bttn));
  if (IFOCUS == 3) attron(COLOR_PAIR(clr_bsel));
  mvaddstr(getcury(stdscr), i * 2 + 9, "[ 取消 ]");
  if (IFOCUS == 3) attroff(COLOR_PAIR(clr_bsel));
  attroff(COLOR_PAIR(clr_bttn) | A_BOLD);
  refresh();
}

static int _next(unsigned char list[][LNUM][CNUM], int st[][STNUM], unsigned char *p)
{
  bool zero;
  unsigned char input[CNUM] = "";
  int key, i, index, found;
  halfdelay(5);
  if (p != NULL) key = *p++; else key = getch();
  if (key < 0 || key > 255) goto __return;
  sprintf((char *)input, "%s%c", input, key);
  if(strncasecmp((char *)input, (char *)L_NAME(ILIST), strlen((char *)input)) != 0)
    goto __fnext;
  ILIST++;
  goto __fnext;
__next:
  if (p != NULL) key = *p++; else key = getch();
  if(key < 0 || key > 255) goto __return;
  sprintf((char *)input, "%s%c", input, key);
  if (strncasecmp((char *)input, (char *)L_NAME(ILIST), strlen((char *)input)) == 0)
    goto __next;
__fnext:
  zero = FALSE;
__fnextloop:
  found = -1;
  for ( i = ILIST; i < FNUM; i++ )
    if (strncasecmp((char *)input, (char *)L_NAME(i), strlen((char *)input)) == 0) {
      found = i;
      break;
    }
  if ( found >= 0 )
  {
    ILIST = found; L_REFRESH ();
    _fdis ( list, st ); goto __next;
  }
  if ( ! zero )
  {
    index = ILIST, ILIST = 0, zero = TRUE;
    goto __fnextloop;
  }
  ILIST = index;
  L_REFRESH ();
  _fdis ( list, st );
  while ( isascii ( getch () ) );
__return:
  cbreak ();
  return ILIST;
}

static char *_fselect(DIR *dir,const char *initfile)
{
  unsigned char list[_fnum(dir)][LNUM][CNUM];
  unsigned char *p;
  int i = 0, fnd = -1, key;
  int st[_fnum(dir)][STNUM];
  struct stat fstat;
  struct dirent *dent;
  rewinddir(dir);
  ILIST = 0;
  while ((dent = readdir(dir)) != NULL)
    if (strcmp(dent->d_name, ".") != 0) {
      strcpy((char *)L_PATH(i), dent->d_name);
      if (initfile != NULL)
        if (strcmp(dent->d_name, initfile) == 0)
          ILIST = i;
      stat(dent->d_name, &fstat);
      L_TYPE(i) = fstat.st_mode;
      if (strcmp(dent->d_name, "..") == 0) {
        strcpy((char *)L_NAME(i), "Parent directory");
        if (i != 0) {
          _strswap((char *)L_NAME(i), (char *)L_NAME(0));
          _strswap((char *)L_PATH(i), (char *)L_PATH(0));
          SWAP(L_TYPE(i), L_TYPE(0));
          ILIST = ILIST == i ? 0 : ILIST;
        }
      } else {
        strcpy((char *)L_NAME(i), (char *)(p = (unsigned char *)_arrange((char *)dent->d_name)));
        free(p);
      }
      if (S_ISDIR(L_TYPE(i))) {
        if (fnd != -1) {
          _strswap((char *)L_NAME(i), (char *)L_NAME(fnd));
          _strswap((char *)L_PATH(i), (char *)L_PATH(fnd));
          SWAP(L_TYPE(i), L_TYPE(fnd));
          SWAP(L_SIZE(i), L_SIZE(fnd));
          if (ILIST == i) ILIST = fnd;
          fnd++;
        }
      } else {
        if (fnd == -1 && i != 0) fnd = i;
        L_SIZE ( i ) = fstat.st_size;
      }
      i++;
    }
  FNUM = i, IFOCUS = 0, LISTI = 0;
  _sort(list, st);
  while (1) {
    _fdis ( list, st );
    i = LDISY;
    switch (key = getch()) {
    case KEY_UP:
      switch (IFOCUS) {
      case -1:
        ISORT -= ISORT != 0;
        _sort(list, st);
        break;
      case 1:
        ILIST = MAX(ILIST - FNUM / i, 0);
        LISTI = MIN(ILIST, LISTI);
        break;
      case 0:
        ILIST -= ILIST != 0;
        LISTI = MIN(LISTI, ILIST);
      }
      break;
    case KEY_DOWN:
      switch (IFOCUS) {
      case -1:
        ISORT += ISORT != 3;
        _sort(list, st);
        break;
      case 1:
        ILIST = MIN(ILIST + FNUM / i, FNUM - 1);
        LISTI = MAX(LISTI, ILIST - LIST_LINES + 1);
        break;
      case 0:
        ILIST += ILIST != FNUM - 1;
        LISTI = MAX(LISTI, ILIST - LIST_LINES + 1);
      }
      break;
    case KEY_LEFT:
      IFOCUS -= IFOCUS > -1;
      break;
    case KEY_RIGHT:
      IFOCUS += IFOCUS < 3;
      break;
    case KEY_RESIZE:
      L_REFRESH();
      break;
    case 033:
      if (strcmp((char *)L_PATH(0), "..") == 0)
        return _getstr((char *)L_PATH(0));
      break;
    case '\n':
      switch (IFOCUS) {
      case 1:
        p = (unsigned char *)InputBox(256, "请输入要跳转的文件名: ", (char *)L_NAME(ILIST));
        if (p != NULL)
          ILIST = _next(list, st, p);
        free(p);
        break;
      case 0:
/*         stat ( L_PATH ( ILIST ), &fstat );
 *         if ( ! S_ISDIR ( fstat.st_mode ) )
 *           continue;
 */
      case 2:
        return _getstr((char *)L_PATH(ILIST));
      case 3:
        return NULL;
      }
    default:
      if (key > 255 || key < 0) break;
      switch (IFOCUS) {
      default:
        ungetch(key);
        ILIST = _next(list, st, NULL);
      }
    }
  }
}

char * Fopen(const char *initdir, const char *initfile)
{
  char *fname = calloc(CNUM + 1, sizeof(char));
  char *o, *p;
  DIR *dir;
  struct stat fstat;
  curs_set(0);
  ISORT = 0;
  *fname = '.';
  if (chdir(initdir) != 0) {
    mkdir(initdir, S_IRWXG);
    if (chdir(initdir) != 0)
      return NULL;
  }
  do {
    if (chdir(fname) != 0) return NULL;
    dir = opendir(".");
    p = _fselect(dir, initfile);
    if (p == NULL) fname = NULL;
    else strcpy(fname, p);
    free(p);
    closedir(dir);
    if (fname == NULL) return NULL;
    stat(fname, &fstat);
  } while (S_ISDIR(fstat.st_mode));
  o = malloc(strlen(p = getcwd(NULL, 0)) + strlen(fname) + 2);
  free(p);
  sprintf(o, "%s/%s", p = getcwd(NULL, 0), fname);
  free(p);
  chdir(initdir);
  return o;
}
