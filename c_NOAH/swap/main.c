/**************************************
 *FILE    :main.c
 *PROJECT :swap
 *AUTHOR  :707wk
 *CREATED :4/10/2013
***************************************/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
  char a;
  if(fopen("/mnt/mmc/swap","r")==NULL)
  {
    system("echo '���������ڴ���...'");
    system("dd if=/dev/zero of=/mnt/mmc/swap bs=1M count=64  ; mkswap /mnt/mmc/swap;");
    system("echo '\n�����ڴ��Ѵ���' \nsleep 1s");
  }
  system("clear");
  system("free");
  printf("����/�ر������ڴ� y/n\n");
  system("mount -o rw,remount /");
  system("mount -o rw,remount /tmp");
  scanf("%c",&a);
  if(a=='y'||a=='Y')
  {
    system("/bin/busybox swapon /mnt/mmc/swap");
    printf("swap�ѿ���");
  }
  else if(a=='n'||a=='N')
  {
    system("/bin/busybox swapoff /mnt/mmc/swap");
    printf("swap�ѹر�");
  }
  system("free");
}

