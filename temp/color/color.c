#include<stdio.h>
#include <windows.h>
/*  颜色属性由两个十六进制数字指定  --  第一个为背景,第二个则为字体。
每个数字可以为以下任何值之一:
0 =  黑色 1 =  蓝色 2 =  绿色 3 =  浅绿色
4 =  红色 8 =  灰色 9 =  淡蓝色 A =  淡绿色
B =  淡浅绿色 C =  淡红色5 =  紫色 6 =  黄色
7 =  白色 D =  淡紫色 E =  淡黄色 F =  亮白色 */
//#define FOREGROUND_BLUE            0x0001 // text color contains blue.
//#define FOREGROUND_GREEN          0x0002 // text color contains green.
//#define FOREGROUND_RED              0x0004 // text color contains red.
//#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
//#define BACKGROUND_BLUE            0x0010 // background color contains blue.
//#define BACKGROUND_GREEN          0x0020 // background color contains green.
//#define BACKGROUND_RED              0x0040 // background color contains red.
//#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.
void fun()
{
    HANDLE haConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(haConsole,BACKGROUND_BLUE|FOREGROUND_GREEN);
    printf("我的世界");
    for(;;)putchar(getch());
}
int main()
{
    fun();
    getchar();
    return 0 ;
}
