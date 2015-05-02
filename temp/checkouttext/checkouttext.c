#include<stdio.h>

int checkouttext(char *files)
{
	int sum_subject=0;
	int num_ans=0;
	int num_subject_sizeof=0;
	char s[3];
	FILE *fpin;
	if((fpin=fopen(files,"r"))==NULL)
	{
		printf("no files\n");
	}
	if(!feof(fpin))
	{
		s[0]=fgetc(fpin);
		num_subject_sizeof++;
	}
	if(!feof(fpin))
	{
		s[1]=fgetc(fpin);
		num_subject_sizeof++;
	}
	if(!feof(fpin))
	{
		s[2]=fgetc(fpin);
		num_subject_sizeof++;
	}
	for(;!feof(fpin);)
	{
		if(s[1]=='^')
		{
			sum_subject++;
		}
		if(s[0]=='\n')
		{
			if(s[1]=='^')
			{
				if(s[2]>='A'&&s[2]<='D')
				{
					num_ans++;
					num_subject_sizeof=0;
				}
			}
		}
		if(num_subject_sizeof>4000)
		{
			fclose(fpin);
			return 0;
		}
		if(sum_subject!=num_ans)
		{
			fclose(fpin);
			return 0;
		}
		s[0]=s[1];
		s[1]=s[2];
		if(!feof(fpin))
		{
			s[2]=fgetc(fpin);
			num_subject_sizeof++;
		}
		else
		{
			break;
		}
	}
	fclose(fpin);
	if(sum_subject==0)
	{
		return 0;
	}
	return 1;
}

int main(int argc,char *argv[])
{
    //if(argc==2)
    {
        //if(checkouttext(argv[1]))
        if(checkouttext("text1.txt"))
        {
            printf("%s 是一个合法的题库文件 !\n",argv[1]);
        }
        else
        {
            printf("%s 不是一个合法的题库文件 !\n",argv[1]);
        }
    }
    //else
    {
    //    printf("未载入文件 !\n");
    }
    getchar();
    return 0;
}
