/**************************************
 *FILE    :main.c
 *PROJECT :001
 *AUTHOR  :
 *CREATED :4/10/2013
***************************************/

int main(int argc, char *argv[])
{
int i,flag=1;
float a=89,b=55,s=0,t;
for(i=1;i<=8;i++)
{
s=s+flag*a/b;
flag=-flag;
t=b;b=a-b;a=t;
}
printf("%5.1f",s);
}

