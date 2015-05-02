/**************************************
 *FILE    :main.c
 *PROJECT :027
 *AUTHOR  :707wk
 *CREATED :9/16/2013
***************************************/
//²Î¿¼030
#include<stdio.h>
int main()
{
//system("clear");
char z;
for(z='a';z<='d';z++)
{
if((((z!='b')+(z=='d'))==1)&&(((z!='b')+(z=='d'))==1)&&(((z!='a')+(z=='b'))==1)&&(z!='d'))break;
//a=(z!='b')&&(z=='d')+(z!='b')&&(z=='d')+(z!='a')&&(z=='b')+(z!='d');
//if(a==1||a==4)break;
}
printf("The thief is %c\n",z-32);
getchar();
    return 0;
}
