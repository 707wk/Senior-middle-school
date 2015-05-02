#include<stdio.h>
void putico()
{
	int i;
	char *a[]= {"=====================================================================",
				"|| GGGGGGGGGG  TTTTTTTTTTT       SSSSSS  OOOOOOO  FFFFFF  TTTTTTTT ||",
				"|| GG               TT           SS      OO   OO  FF         TT    ||",
				"|| GG               TT           SS      OO   OO  FF         TT    ||",
				"|| GG               TT  =======  SSSSSS  OO   OO  FF         TT    ||",
				"|| GG               TT               SS  OO   OO  FFFFFF     TT    ||",
				"|| GG     GGGGG     TT               SS  OO   OO  FF         TT    ||",
				"|| GG      GG       TT               SS  OO   OO  FF         TT    ||",
				"|| GGGGGGGGGG       TT           SSSSSS  OOOOOOO  FF         TT    ||",
				"====================================================================="};
	printf("\n\n\n\n\n\n");
	for(i=0;i<10;i++)
		printf("     %s\n",a[i]);
}
int main()
{
putico();
 getchar();
return 0;
}
