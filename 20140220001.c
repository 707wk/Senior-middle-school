//一张纸撕去ROP张纸后还剩SURPLUS张
//问撕去的那ROP张纸的页数是多少,撕法有多少种
#include<stdio.h>
#include<malloc.h>
#define SURPLUS 10835
#define DROP 2
int main()
{
    int num_sum_page=1,num_sum_sum=0,num_page1;
	int num_page2,num_page_temp,num_sum_temp ;
	int *num_rop,i,num_way=0;
	num_rop=(int *)malloc(sizeof(int)*DROP);
    for(;num_sum_sum<=SURPLUS;num_sum_page++)
        num_sum_sum+=num_sum_page*4-1 ;
    for(num_page_temp=num_sum_page;num_sum_page<=num_page_temp+DROP;)
    {
    	for(i=0;i<DROP;i++)
			num_rop[i]=i+1;
        for(;num_rop[0]<=num_sum_page-DROP;num_rop[DROP-1]++)
        {
        	for(i=0;i<DROP;i++)
        		if(num_rop[DROP-i-1]>num_sum_page-i)
				{
					if(DROP-i-2>=0)
					num_rop[DROP-i-2]++;
					num_rop[DROP-i-1]=num_rop[DROP-i-2]+1;
				}
        	num_sum_temp=num_sum_sum;
        	for(i=0;i<DROP;i++)
            	num_sum_temp=num_sum_temp-num_rop[i]*4+1 ;
        	if(num_sum_temp==SURPLUS)
        	{	
				num_way++;
        		printf("%2d:sum=%6d sum_page=%3d",num_way,num_sum_sum,num_sum_page);
        		for(i=0;i<DROP;i++)
        			printf(" %3d:%3d %3d ",num_rop[i],num_rop[i]*2-1,num_rop[i]*2);
        		printf("surplus=%6d\n",num_sum_temp);
        	}
        }
        num_sum_sum+=++num_sum_page*4-1 ;
    }
    printf("it is have : %2d\n",num_way);
    getchar();
    return 0 ;
}
