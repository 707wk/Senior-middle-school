#include<stdio.h>
#include<windows.h>
int main()
{
	SYSTEM_INFO sysInfo;
	char str[100];
	GetSystemInfo(&sysInfo);
	sprintf(str,"OEM ID: %u\n",sysInfo.dwOemId);
	printf("%s",str);
	sprintf(str,"CPU ����: %u\n",sysInfo.dwNumberOfProcessors);
	printf("%s",str);
	sprintf(str,"�ڴ��ҳ��С: %u\n",sysInfo.dwPageSize);
	printf("%s",str);
	sprintf(str,"CPU ����: %u\n",sysInfo.dwProcessorType);
	printf("%s",str);
	sprintf(str,"CPU �ܹ�: %u\n",sysInfo.wProcessorArchitecture);
	printf("%s",str);
	sprintf(str,"CPU �ļ���: %u\n",sysInfo.wProcessorLevel);
	printf("%s",str);
	sprintf(str,"CPU �İ汾: %u\n",sysInfo.wProcessorRevision);
	printf("%s",str);
	getchar();
	return 0;
}
