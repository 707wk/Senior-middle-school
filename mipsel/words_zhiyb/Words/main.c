/**************************************
 *FILE    :main.c
 *PROJECT :Words
 *AUTHOR  :zhiyb
 *CREATED :11/23/2011
***************************************/

#include "Common.h"
#include "List.h"
#include "Load.h"
#include "Fopen.h"
#include "MainMenu.h"

void recover(int i, void *v)
{
  endwin ();
}

void init(void)
{
  setenv("TERM", "screen", 1);
  on_exit(recover, NULL);
  initscr();
  keypad(stdscr, TRUE);
  //raw();
  cbreak();
  noecho();
  start_color();
  InitFopen();
  InitMainMenu();
  clear();
}

int main(int argc, char *argv[])
{
  char *fp, *dirname, *filename = NULL;
  struct list_data *ldata = NULL, *p = ldata;
  struct words_info *words = NULL;
  init();
  p = ldata = list_push(ldata);
  p->dis = malloc(6);
  strcpy(p->dis, "Test!");
  p = list_push(p);
  p->dis = malloc(11);
  strcpy(p->dis, "List tool.");
  p = list_push(p);
  p->dis = malloc(14);
  strcpy(p->dis, "Made by zhiyb");
  List(ldata);
  dirname = calloc(strlen("/opt/QtPalmtop/data/z/words") + 1, sizeof(char));
  strcpy(dirname, "/opt/QtPalmtop/data/z/words");
_back:
  fp = Fopen(dirname, filename);
  if (fp != NULL) {
    words = Load(fp);
    free(dirname); free(filename);
    _splitpath(fp, &dirname, &filename);
    free(fp);
    if (!DisInfo(words)) goto _back;
_FunMenu:
    switch (FunctionMenu(words)) {
    case 0:
      goto _back;
    case 1:
      KnowWords(words);
      goto _FunMenu;
    case 2:
      WriteWords(words);
      goto _FunMenu;
    case 5:
      WordList(words);
      goto _FunMenu;
    }
CL SI(_getcolorcnt()) BP
  }
  clear();
  refresh();
  return 0;
}
