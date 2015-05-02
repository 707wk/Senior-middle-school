int host_count(int mask)
{
    int temp;
    int i;
    i=(mask/8+1)*8-mask;
    for(temp=1; i>0; i--)
    {
        temp=temp*2;
    }
    switch(mask/8)
    {
    case 0:
        return temp*256*256*256;
    case 1:
        return temp*256*256;
    case 2:
        return temp*256;
    case 3:
        return temp;
    }
    return -1;
}

int net_count(int mask)
{
	int i;
	int temp;
	i=mask-mask/8*8;
	for(temp=1;i>0;i--)
	{
		temp=temp*2;
	}
	return temp;
}

int ip_analysis(char* str_ip)
{
	int i;
    int ip_address[4];
    int mask;
    int host_num;
    int net_num;
    FILE* fp;
    if((fp=fopen("temp","w"))==NULL)
    {
        printf("文件错误：不能创建临时文件!\n");
        return 0;
    }
    fprintf(fp,"%s",str_ip);
    fclose(fp);
    if((fp=fopen("temp","r"))==NULL)
    {
        printf("文件错误：不能打开临时文件!\n");
        return 0;
    }
    fscanf(fp,"%d.%d.%d.%d/%d",
           &ip_address[0],
           &ip_address[1],
           &ip_address[2],
           &ip_address[3],
           &mask);
    fclose(fp);
    for(i=0; i<4; i++)
    {
        if(ip_address[i]>255||ip_address[i]<0)
        {
            return 1;
        }
    }
    if(mask>32||mask<0)
    {
        return 1;
    }
    if(mask%8==0)
    {
    	printf("该子网未划分\n");
    	return 1;
    }
    host_num=host_count(mask);
    printf("子网内ip数:%10d\n",host_num);
    net_num=net_count(mask);
    printf("子网数:%10d\n",net_num);
    printf("可用子网数:%10d\n",net_num-2);
    printf("与未划分子网相比损失的ip地址总数:%10d",host_num*2+(net_num-2)*2-2);
    return 0;
}
