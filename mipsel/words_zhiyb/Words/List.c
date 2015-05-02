/**************************************
 *FILE    :List.c
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :12/30/2011
***************************************/

#include "Common.h"
#include "List.h"

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
#define L_NAME(m) list[( m )][0]
#define L_PATH(m) list[( m )][1]
#define L_TYPE(m) st[( m )][0]
#define L_SIZE(m) st[( m )][1]
#define L_REFRESH() ( LISTI = MIN ( MAX ( MIN ( MAX ( LISTI, ILIST - LIST_LINES + 1 ), FNUM - LIST_LINES ), 0 ), ILIST ) )
/*
typedef struct _disdatas
{
  int fnum, listi, ilist, ifocus, isort;
} DIS;
*/
//struct LDATA *ldata;
/*DIS ddata;

static void _sort ( unsigned char list[][LNUM][CNUM], int st[][STNUM] )
{
  char j = 1, k;
  int i;
  LISTI = 0; ILIST = 0;
  for ( k = 0; k < 2; k++, j = 1 )
    while ( j != 0 )
    {
      i = 2; j = 0;
      while ( i < FNUM )
      {
        if ( k ^ S_ISDIR ( L_TYPE ( i - 1 ) ) && k ^ S_ISDIR ( L_TYPE ( i ) ) && _larger ( L_NAME ( i - ( ISORT != 1 ) ), L_NAME ( i - ( ISORT == 1 ) ) ) )
        {
          _strswap ( L_NAME ( i - 1 ), L_NAME ( i ) );
          _strswap ( L_PATH ( i - 1 ), L_PATH ( i ) );
          SWAP ( L_TYPE ( i - 1 ), L_TYPE ( i ) );
          SWAP ( L_SIZE ( i - 1 ), L_SIZE ( i ) );
          j = 1;
        }
        i++;
      }
    }
  if ( j = 1, ISORT > 1 )
    while ( j != 0 )
    {
      i = 2; j = 0;
      while ( i < FNUM )
      {
        if ( ! S_ISDIR ( L_TYPE ( i - 1 ) ) && ! S_ISDIR ( L_TYPE ( i ) ) && L_SIZE ( i - 3 + ISORT ) > L_SIZE ( i - ISORT + 2 ) )
        {
          _strswap ( L_NAME ( i - 1 ), L_NAME ( i ) );
          _strswap ( L_PATH ( i - 1 ), L_PATH ( i ) );
          SWAP ( L_TYPE ( i - 1 ), L_TYPE ( i ) );
          SWAP ( L_SIZE ( i - 1 ), L_SIZE ( i ) );
          j = 1;
        }
        i++;
      }
    }
}

static void _fdis ( unsigned char list[][LNUM][CNUM], int st[][STNUM] )
{
  char i, j, k;
  char *o, *p, *q;
  i = ( getmaxx ( stdscr ) - 14 ) / 3;
  clear ();
  border ( '|', '|', '-', '-', '+', '+', '+', '+' );
  mvaddstr ( 1, i + 1, "打开文件" );
  if ( IFOCUS == -3 )
    attron ( A_REVERSE );
  mvaddstr ( 1, i * 2 + 5, "菜单" );
  if ( IFOCUS == -3 )
    attroff ( A_REVERSE );
  mvaddch ( 1, getmaxx ( stdscr ) - 7, '|' );
  if ( IFOCUS == -2 )
    attron ( A_REVERSE );
  mvaddstr ( 2, 1, q = _arrange ( p = _cut ( 1, getmaxx ( stdscr ) - 2, ( o = getcwd ( NULL, 0 ) ) ) ) );
  free ( o );
  free ( q );
  if ( IFOCUS == -2 )
    attroff ( A_REVERSE );
  for ( j = 0; j < getmaxx ( stdscr ) - strlen ( p ) - 2; j++ )
    addch ( ' ' | A_PROTECT );
  addch ( '|' );
  free ( p );
  i = ( getmaxx ( stdscr ) - 12 ) / 3;
  if ( IFOCUS == -1 )
    attron ( A_REVERSE );
  mvaddstr ( 3, 1, "文件名" );
  if ( ISORT == 0 )
    addstr ( " ∨" );
  else if ( ISORT == 1 )
    addstr ( " ∧" );
  mvaddstr ( 3, getmaxx ( stdscr ) - ( ISORT < 2 ) - 13, "大小" );
  if ( ISORT == 2 )
    addstr ( " ∨" );
  else if ( ISORT == 3 )
    addstr ( " ∧" );
  if ( IFOCUS == -1 )
    attroff ( A_REVERSE );
  if ( ISORT < 2 )
    addstr ( "   " );
  addstr ( "  |" );
  move ( LIST_Y, 0 );
  for ( i = LISTI; i < MIN ( LIST_LINES + LISTI, FNUM ); i++ )
  {
    if ( i == ILIST )
      attron ( A_REVERSE );
    mvaddstr ( getcury ( stdscr ), 1, ( p = _cut ( 2, getmaxx ( stdscr ) - 11, L_NAME ( i ) ) ) );
    if ( i == ILIST )
      attroff ( A_REVERSE );
    for ( j = 0; j < getmaxx ( stdscr ) - strlen ( p ) - 11; j++ )
      addch ( ' ' | A_PROTECT );
    free ( p );
    if ( S_ISDIR ( L_TYPE ( i ) ) )
      addstr ( "<DIR>   " );
    else {
      addstr ( p = _husize ( L_SIZE ( i ) ) );
      free ( p );
    }
    if ( IFOCUS == 1 )
      attron ( A_REVERSE );
    addch ( LDISY * ILIST / FNUM == i - LISTI ? '#' : '|' );
    if ( IFOCUS == 1 )
      attroff ( A_REVERSE );
    addch ( '|' );
  }
  i = ( getmaxx ( stdscr ) - 10 ) / 3;
  if ( IFOCUS == 2 )
    attron ( A_REVERSE );
  mvaddstr ( getmaxy ( stdscr ) - 2, i + 1, "确定" );
  if ( IFOCUS == 2 )
    attroff ( A_REVERSE );
  if ( IFOCUS == 3 )
    attron ( A_REVERSE );
  mvaddstr ( getcury ( stdscr ), i * 2 + 3, "取消" );
  if ( IFOCUS == 3 )
    attroff ( A_REVERSE );
  mvaddch ( getcury ( stdscr ), getmaxx ( stdscr ) - 5, '|' );
  refresh ();
}

static int _next ( unsigned char list[][LNUM][CNUM], int st[][STNUM] )
{
  bool zero;
  char input[CNUM] = "";
  int key, i, index, found;
  halfdelay ( 5 );
  key = getch ();
  if ( ! isascii ( key ) )
    goto __return;
  sprintf ( input, "%s%c", input, key );
  if ( strncasecmp ( input, L_NAME ( ILIST ), strlen ( input ) ) != 0 )
    goto __fnext;
  ILIST++;
  goto __fnext;
 __next:
  key = getch ();
  if ( ! isascii ( key ) )
    goto __return;
  sprintf ( input, "%s%c", input, key );
  if ( strncasecmp ( input, L_NAME ( ILIST ), strlen ( input ) ) == 0 )
    goto __next;
 __fnext:
  zero = FALSE;
 __fnextloop:
  found = -1;
  for ( i = ILIST; i < FNUM; i++ )
    if ( strncasecmp ( input, L_NAME ( i ), strlen ( input ) ) == 0 )
    {
      found = i;
      break;
    }
  if ( found >= 0 )
  {
    ILIST = found;
    L_REFRESH ();
    _fdis ( list, st );
    goto __next;
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

static char *_fselect ( DIR *dir )
{
  unsigned char list[_fnum ( dir )][LNUM][CNUM];
  char *p;
  int i = 0, fnd = -1, key;
  int st[_fnum ( dir )][STNUM];
  struct stat fstat;
  struct dirent * dent;
  rewinddir ( dir );
  while ( ( dent = readdir ( dir ) ) != NULL )
    if ( strcmp ( dent -> d_name, "." ) != 0 )
    {
      if ( strcmp ( dent -> d_name, ".." ) == 0 )
        strcpy ( L_NAME ( i ), "Parent directory" );
      else {
        strcpy ( L_NAME ( i ), p = _arrange ( dent -> d_name ) );
        free ( p );
      }
      strcpy ( L_PATH ( i ), dent -> d_name );
      stat ( dent -> d_name, &fstat );
      L_TYPE ( i ) = fstat.st_mode;
      if ( S_ISDIR ( L_TYPE ( i ) ) )
      {
        if ( fnd != -1 )
        {
          _strswap ( L_NAME ( i ), L_NAME ( fnd ) );
          _strswap ( L_PATH ( i ), L_PATH ( fnd ) );
          SWAP ( L_TYPE ( i ), L_TYPE ( fnd ) );
          SWAP ( L_SIZE ( i ), L_SIZE ( fnd ) );
          fnd++;
        }
      } else {
        if ( fnd == -1 )
          fnd = i;
        L_SIZE ( i ) = fstat.st_size;
      }
      i++;
    }
  FNUM = i, LISTI = 0, ILIST = 0, IFOCUS = 0;
  _sort ( list, st );
  while ( 1 )
  {
    _fdis ( list, st );
    i = LDISY;
    switch ( key = getch () )
    {
     case KEY_UP:
      switch ( IFOCUS )
      {
       case -1:
        ISORT -= ISORT != 0;
        _sort ( list, st );
        break;
       case 1:
        ILIST = MAX ( ILIST - FNUM / i, 0 );
        LISTI = MIN ( ILIST, LISTI );
        break;
       default:
        ILIST -= ILIST != 0;
        LISTI = MIN ( LISTI, ILIST );
      }
      break;
     case KEY_DOWN:
      switch ( IFOCUS )
      {
       case -1:
        ISORT += ISORT != 3;
        _sort ( list, st );
        break;
       case 1:
        ILIST = MIN ( ILIST + FNUM / i, FNUM - 1 );
        LISTI = MAX ( LISTI, ILIST - LIST_LINES + 1 );
        break;
       default:
        ILIST += ILIST != FNUM - 1;
        LISTI = MAX ( LISTI, ILIST - LIST_LINES + 1 );
      }
      break;
     case KEY_LEFT:
      IFOCUS -= IFOCUS != -3;
      break;
     case KEY_RIGHT:
      IFOCUS += IFOCUS != 3;
      break;
     case KEY_RESIZE:
      L_REFRESH ();
      break;
     case 033:
      if ( strcmp ( L_PATH ( 0 ), ".." ) == 0 )
        return _getstr ( L_PATH ( 0 ) );
      break;
     case '\n':
      switch ( IFOCUS )
      {
       case 1:
        InputBox ( *1, 100, 256, "Fopen_Sort",*256, "Please input the first few letters:", L_NAME ( ILIST ) );
        break;
       case 0:
        stat ( L_PATH ( ILIST ), &fstat );
        if ( ! S_ISDIR ( fstat.st_mode ) )
          continue;
       case 2:
        return _getstr ( L_PATH ( ILIST ) );
       case 3:
        return _getstr ( "\0" );
      }
     default:
      if ( ( key > 255 ) ^ ( key < 0 ) )
        break;
      switch ( IFOCUS )
      {
       default:
        ungetch ( key );
        ILIST = _next ( list, st );
      }
    }
  }
}
*/
struct list_data *list_push(struct list_data *p1)
{
  if (p1 == NULL) {
    p1 = (struct list_data *)calloc(1, sizeof(*p1));
    return p1;
  }
  while (p1->next != NULL)
    p1 = p1->next;
  p1->next = (struct list_data *)calloc(1, sizeof(struct list_data));
  return p1->next;
}

void List(struct list_data *ldata)
{
  struct list_data *p = ldata;
  while (p != NULL) {
    printw("%s\n", p->dis);
    p = p->next;
  }
  refresh();
  getch();
}

void list_init ( void )
{
  ;
}
