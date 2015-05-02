/**************************************
 *FILE    :Common.c
 *PROJECT :Common
 *AUTHOR  :zhiyb
 *CREATED :12/26/2011
***************************************/

#include "Common.h"

#ifdef debug
int _debug_ = 0;
#endif

static short color_cnt = 1;

char *_getstr(char *s)
{
  char *o = malloc(strlen(s) + 1);
  strcpy(o, s);
  return o;
}

char *_arrange(char *s)
{
  char *r = malloc(strlen(s) + 1);
  char *p;
  strcpy(r, s);
  for (p = r; *p != '\0'; p++)
    if (*p == '\t' || *p == '\n')
      *p = ' ';
  return r;
}

char *_cut(char type, int l, char s[])
{
  char o[l + 1];
  int i, j, length;
  length = MIN(l, (int) strlen(s));
  if (type % 2 == 0)
  {
    for (i = 0; i < length; i++)
      if (isascii(s[i])) {
        if (i < length - 3 || ! ((int) strlen (s) > l && type == 2))
          o[i] = s[i];
        else {
          for (l = 0; l < 3; l++)
            o[i++] = '.';
          break;
        }
      } else if (i != l - 1) {
        if (i < length - 4 || !((int) strlen(s) > l && type == 2))
          o[i] = s[i], i++, o[i] = s[i];
        else {
          for (l = 0; l < 3; l++)
            o[i++] = '.';
          break;
        }
      }
    o[i] = '\0';
  } else if (type == 1) {
    for (i = 0, j = 0; i < (int)strlen(s); i++)
      if ((int)strlen(s) - i > length)
        i += !isascii(s[i]), j = i + 1;
      else {
        o[i - j] = s[i];
        if (!isascii(s[i]))
          i++, o[i - j] = s[i];
      }
    o[i - j] = '\0';
  }
  return _getstr(o);
}

void _strswap ( char *s1, char *s2 )
{
  char *p = malloc ( MAX ( strlen ( s1 ), strlen ( s2 ) ) + 1 );
  strcpy ( p, s1 );
  strcpy ( s1, s2 );
  strcpy ( s2, p );
  free ( p );
}

int _fnum ( DIR *dir )
{
  int i = 0;
  struct dirent *dent;
  rewinddir ( dir );
  while ( ( dent = readdir ( dir ) ) != NULL )
    if ( strcmp ( dent -> d_name, "." ) != 0 )
      i++;
  return i;
}

char *_husize(int size)
{
  char *s = malloc(9);
  if (size < 1024)
    sprintf(s, "%d B", size);
  else if (size < 1024 * 1024)
    sprintf(s, "%.1f k", (float)size / 1024);
  else if (size < 1024 * 1024 * 1024)
    sprintf(s, "%.1f M", (float)size / 1024 / 1024);
  else
    sprintf(s, "%.1f G", (float)size / 1024 / 1024 / 1024);
  return s;
}

char _larger ( unsigned char *s1, unsigned char *s2 )
{
  while ( *s1 == *s2 && *s1 != '\0' && *s2 != '\0' )
    s1++, s2++;
  if ( *s1 == '\0' )
    return 0;
  else if ( *s2 == '\0' )
    return 1;
  if ( ! isascii ( *s1 ) )
    return *s1 > *s2;
  else if ( ! isascii ( *s2 ) )
    return 0;
  else if ( isdigit ( *s1 ) )
    return isdigit ( *s2 ) ? *s1 > *s2 : ! isalpha ( *s2 );
  else if ( isalpha ( *s1 ) )
    return isalpha ( *s2 ) ? *s1 > *s2 : 1;
  else
    return isalnum ( *s2 ) ? 0 : *s1 > *s2;
}

int _wstrlen(char *s)
{
  int i = 0;
  while (*s != '\0')
    if (isascii(*s))
      i++, s++;
    else
      i++, s += 2;
  return i;
}

int _wstrpos(char *s, int pos)
{
  int i;
  if (pos < 0)
    pos = 0;
  for (i = 0; pos > 0 && *s != '\0'; pos--, i++, s++)
    if (!isascii(*s))
      i++, s++;
  return i;
}

int _strpos(char *s, int pos)
{
  int i;
  if(pos < 0)
    pos = 0;
  for (i = 0; pos > 0 && *s != '\0'; pos--, i++, s++)
    if (!isascii(*s))
      pos--, s++;
  i -= pos == -1;
  return i;
}

int _nstrpos(char *s, int pos)
{
  int i;
  if (pos < 0)
    pos = 0;
  for (i = 0; pos > 0 && *s != '\0'; pos--, i++, s++)
    if (!isascii(*s))
      pos--, s++;
  return i;
}

int _max(int a, int b)
{
  return MAX(a, b);
}

int _min(int a, int b)
{
  return MIN(a, b);
}

int _intlength(int i)
{
  int cnt;
  for (cnt = 1; i / (int)pow(10, cnt) >= 1; cnt++);
  return cnt;
}

char *_freadline(FILE *fp)
{
  char c, *p = calloc(sizeof(char), 1);
  if (feof(fp) != 0) {
    free(p);
    return NULL;
  }
  while (c = fgetc(fp), c != EOF && c != '\n') {
    p = realloc(p, strlen(p) + 2);
    *(p + strlen(p) + 1) = '\0';
    *(p + strlen(p)) = c;
  }
  return p;
}

short _alloc_color(int front, int back)
{
  init_pair(color_cnt, front, back);
  return color_cnt++;
}

short _getcolorcnt(void)
{
  return color_cnt++;
}

void _mvchgrectat(int y0, int x0, int y, int x, attr_t attr, short color, const void *v)
{
  int i;
  for (i = 0; i < y; i++)
    mvchgat(y0 + i, x0, x, attr, color, v);
}

void _splitpath(char *path, char **dir, char **file)
{
  char *p = rindex(path, '/');
  *file = calloc(strlen(p), sizeof(char));
  strcpy(*file, p + 1);
  *p = '\0';
  *dir = calloc(strlen(path) + 1, sizeof(char));
  strcpy(*dir, path);
  return;
}
