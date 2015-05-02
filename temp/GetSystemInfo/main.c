#include<stdio.h>
#include<windows.h>
int main()
{
	SYSTEM_INFO sysInfo;
	char str[100];
	GetSystemInfo(&sysInfo);
	sprintf(str,"OEM ID: %u\n",sysInfo.dwOemId);
	printf("%s",str);
	sprintf(str,"CPU 个数: %u\n",sysInfo.dwNumberOfProcessors);
	printf("%s",str);
	sprintf(str,"内存分页大小: %u\n",sysInfo.dwPageSize);
	printf("%s",str);
	sprintf(str,"CPU 类型: %u\n",sysInfo.dwProcessorType);
	printf("%s",str);
	sprintf(str,"CPU 架构: %u\n",sysInfo.wProcessorArchitecture);
	printf("%s",str);
	sprintf(str,"CPU 的级别: %u\n",sysInfo.wProcessorLevel);
	printf("%s",str);
	sprintf(str,"CPU 的版本: %u\n",sysInfo.wProcessorRevision);
	printf("%s",str);
	getchar();
	return 0;
}
