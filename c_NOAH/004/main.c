/**************************************
 *FILE    :main.c
 *PROJECT :004
 *AUTHOR  :
 *CREATED :4/11/2013
***************************************/
#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#define ESC 'q'
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
int main(int argc, char *argv[])
{
char key;
key=getch();
while(key!=ESC)
{
switch(key)
{
case UP:printf("��");break;
case DOWN:printf("��");break;
case LEFT:printf("��");break;
case RIGHT:printf("��");break;
default:break;
}
key=getch();
}
}
