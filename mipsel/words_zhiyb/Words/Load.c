/**************************************
 *FILE    :Load.c
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :1/5/2012
***************************************/

#include "Common.h"
#include "Load.h"

#define ALLOC_INFO ((struct words_info *)calloc(1, sizeof(struct words_info)))
#define ALLOC_P ((struct words_p *)calloc(1, sizeof(struct words_p)))

static struct words_p *_alloc_next(struct words_info *words)
{
  struct words_p *p = NULL;
  if (words->p == NULL) {
    words->p = ALLOC_P;
    words->f = words->p;
    words->p->prev = words->p;
    words->p->next = words->p;
    return words->p;
  } else {
    p = words->p->prev;
    p->next = words->p->prev = ALLOC_P;
    p->next->prev = p;
    p->next->next = words->p;
    return p->next;
  }
}

void _free_last(struct words_info *words)
{
  struct words_p *p = words->p;
  if (p == NULL)
    return;
  p = p->prev;
  free(p->word);
  free(p->mean);
  words->num[0]--;
  if (p->prev == words->p)
    words->p = NULL;
  else {
    p->prev->next = p->next;
    p->next->prev = p->prev;
  }
  free(p);
}

struct words_info *Load(char *fpath)
{
  FILE *fp = fopen(fpath, "r");
  struct stat fstat;
  struct words_info *words = NULL;
  struct words_p *p = NULL;
  if (fp == NULL) return NULL;
  words = ALLOC_INFO;
  words->order = 1;
  words->fpath = calloc(sizeof(char), strlen(fpath) + 1);
  strcpy(words->fpath, fpath);
  stat(fpath, &fstat);
  words->size = fstat.st_size;
  rewind(fp);
  while (feof(fp) == 0) {
    p = _alloc_next(words);
    p->word = _freadline(fp);
    p->mean = _freadline(fp);
    words->num[0]++;
    if (p->word == NULL || p->mean == NULL)
      _free_last(words);
  }
  fclose(fp);
  return words;
}
