#include<stdio.h>
void encrypt()
{
	char c;
	FILE *fin,*fout;
	if((fin=fopen("temp","r"))==NULL)
	{
		printf("error");
		return ;	
	}
	if((fout=fopen("error","w"))==NULL)
	{
		printf("error");
		return ;	
	}
	while(!feof(fin))
	{
		c=fgetc(fin);
		c+=5;
		//fwrite(&c,1,1,fout);
		fputc(c,fout);
	}
	fclose(fin);
	fclose(fout);
}
int main()
{
	encrypt();
	return 0;	
}
