#include <linux/unistd.h>
#include <unistd.h>
#include <termios.h>  
#include <stdio.h>
int input;
pthread_t thread[1];
pthread_mutex_t mut;
void *regetch()
{
  int n=0;
  n=fgetc(stdin);
  input+=n;
  pthread_exit(NULL);
}
int getch(void)
{
  struct termios tm, tm_old;
  int fd = STDIN_FILENO,c;
  if(tcgetattr(fd,&tm)<0)return -1;
  tm_old=tm;
  cfmakeraw(&tm);
  if(tcsetattr(fd,TCSANOW,&tm)<0)return -1;
  unsigned int k;
  int temp;
  input=fgetc(stdin);
  k=input;
  if(tcsetattr(fd,TCSANOW,&tm_old)<0) return -1;
  if(k>32)c=k;
  else{
    while(1)
    {
      memset(&thread,0,sizeof(thread));
      if((temp=pthread_create(&thread[0],NULL,regetch,NULL))!=0)
      printf("用于获取按键输入的线程创建失败!\n");
      usleep(1000);
      pthread_cancel(thread[0]);
      pthread_join(thread[0],NULL);
      if(k == input)
      {
        c=input;
        break;
      }
      else
      {
        k = input;
        c=c+k;
      }
    }
  }
  return c;

}
