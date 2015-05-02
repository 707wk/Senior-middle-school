#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qtextcodec.h>
#include<time.h>
#define py QMessageBox::information(NULL,"PYBOX",QObject::tr("欢迎使用六则运算训练器v5.0\n本软件原作者:pengyao1207\n转载请注明原作者"))
#define asd "/mnt/UsrDisk/四则运算存档/save"
#define ase "/mnt/UsrDisk/四则运算存档"
/*预处理和头文件*/
int exist(char *file)
{
FILE *fp;
fp=fopen(file,"r");
if(fp==NULL)return 0;
else
{fclose(fp);
return 1;
}
}
/*判断存档是否存在*/
int cj()
{
long a;
char cs[2000]="mkdir -p ";
strcat(cs,ase);
system(cs);
a=exist(asd);
if(a==0)
{
FILE *fp;
fp=fopen(asd,"w+");
fclose(fp);
}
}
/*创建存档*/
int sfwk()
{
char c;
FILE *fp;
fp=fopen(asd,"r");
if(fscanf(fp,"%c",&c)==EOF)return 0;
else return 1;
fclose(fp);
}
/*判断存档是否为空*/
int zqsz()
{
int a;
FILE *fp;
fp=fopen(asd,"r");
fscanf(fp,"%d",&a);
fclose(fp);
return a;
}
int zsz()
{FILE *fp;
int a,b;
fp=fopen(asd,"r");
fscanf(fp,"%d",&a);
fscanf(fp,"%d",&b);
fclose(fp);
return b;
}
/*读取存档*/
int bc(int zqs,int zs)
{
FILE *fp;
fp=fopen(asd,"w+");
fprintf(fp,"%d %d",zqs,zs);
fclose(fp);
}
/*存档*/
char *mkstr(int aa)
{
int j=1,i,k,ws=1;
for(i=1;i<=10;i++){j=j*10;if(aa>=j)ws++;}
j=aa;
char l[500]="",e[1000]="",c;
for(i=1;i<=ws;i++)
{k=j%10;
j=j/10;
if(k==1)l[0]='1';
if(k==2)l[0]='2';
if(k==3)l[0]='3';
if(k==4)l[0]='4';
if(k==5)l[0]='5';
if(k==6)l[0]='6';
if(k==7)l[0]='7';
if(k==8)l[0]='8';
if(k==9)l[0]='9';
if(k==0)l[0]='0';
strcat(e,l);
}
j=ws/2;
for(i=0;i<=j-1;i++){c=e[i]; e[i]=e[ws-1-i]; e[ws-1-i]=c;}
return e;
}
/*int to string*/
int zsys(int a,int b){int i,j=1;if(b==0)j=1;if(b!=0)for(i=1;i<=b;i++)j=a*j;if(a==0)j=0;return j;}
/*指数运算*/
int main(int argc, char **argv)
{ 
int aa; 
        QApplication ab(argc,argv);
        QTextCodec *codec=QTextCodec::codecForName("GB2312");
         ab.setDefaultCodec(codec);
         long zs=0,zqs=0;
srand((unsigned long)time(NULL));
long w,a,z,b,d,e,zql,i,j,zd,gd=0,d1,d2,d3,w1,w2,w3,wz;
char cs[2000]="";
char y[5],s[5];
/*变量设置*/
cj();
/*创建存档文件*/
if(sfwk()==1){
zqs=zqsz();
zs=zsz();}
/*读取进度*/
aa=py;
if(aa==-1)return 0;
/*程序介绍*/
aa=QMessageBox::information(NULL,QObject::tr("PYBOX"),QObject::tr("请选择计算范围"),QObject::tr("100"),QObject::tr("1000"),QObject::tr("10000"));
if(aa==-1)return 0;
if(aa==0)w=100;
if(aa==1)w=1000;
if(aa==2)w=10000;
/*计算范围处理*/
for(i=2;i<=w;i++)if(zsys(i,2)>w){zd=i-1;break;}
for(i=2;i<=w;i++)if(zsys(i,3)>w){gd=i-1;break;}
if(zd<0)zd=0;
if(gd<0)gd=0;
/*生成题目的准备*/
back: 
z=(rand() % 6);
bc: 
a=(rand() % (w+1));
b=(rand() % (w+1));
if(z==0){d=a*b; if(d>w)goto bc; }
if(z==1){d=a+b; if(d>w)goto bc;}
if(z==2){d=a-b; if(d>w)goto bc;if(d<0)goto bc; }
if(z==3){e=a*b; if(e>w)goto bc;if(b==0)goto bc; if(e<=w){d=a; a=e;}}
if(z==4){d=1;i=(rand() % 3);if(i==1)a=(rand() % (zd+1));if(i==2)a=(rand() % (gd+1));if(a==0){b=(rand() % w)+1; d=0;} if(a!=0)if(a!=1){for(i=1;i<=10001;i++)if(zsys(a,i)>w){j=i-1; break;} b=(rand() % (j+1)); d=zsys(a,b);}if(b>10000)goto bc;} 
if(z==5){i=(rand() % 3);if(i==1)a=(rand() % (zd+1));if(i==2)a=(rand() % (gd+1));if(a<2)goto bc;if(a!=0){for(i=1;i<=10001;i++)if(zsys(a,i)>w){j=i-1; break;} b=(rand() % j)+1; d=zsys(a,b);} if(b>10000)goto bc;i=d; d=b; b=i;}
/*对不同计算类型处理*/
i=100;
d1=d;
bcc:
e=(rand() % 3);
if(e==i)goto bcc;
i=e;
if(z<4)
{
if(e==0){d2=d1+8+(rand() % 5);d3=d1+18+(rand() % 5);}
if(e==1){d2=d1-8-(rand() % 5);d3=d1-18-(rand() % 5);}
if(e==2){d2=d1-8-(rand() % 5);d3=d1+8+(rand() % 5);}
}
if(z>3)
{
if(e==0){d2=d1+1;d3=d1+2;}
if(e==1){d2=d1-1;d3=d1-2;}
if(e==2){d2=d1+1;d3=d1-1;}
}
if(d2>w)goto bcc;
if(d2<0)goto bcc;
if(d3>w)goto bcc;
if(d3<0)goto bcc;
/*对生成答案处理*/
e=(rand() % 6);
if(e==0){w1=d1; w2=d2; w3=d3; wz=0;}
if(e==1){w1=d1; w2=d3; w3=d2; wz=0;}
if(e==2){w1=d2; w2=d1; w3=d3; wz=1;}
if(e==3){w1=d3; w2=d1; w3=d2; wz=1;}
if(e==4){w1=d2; w2=d3; w3=d1; wz=2;}
if(e==5){w1=d3; w2=d2; w3=d1; wz=2;}
/*对显示答案处理*/
memset(cs,0,2000);
if(z==0){strcat(cs,mkstr(a)); strcat(cs,"x"); strcat(cs,mkstr(b));}
if(z==1){strcat(cs,mkstr(a)); strcat(cs,"+"); strcat(cs,mkstr(b));}
if(z==2){strcat(cs,mkstr(a)); strcat(cs,"-"); strcat(cs,mkstr(b));}
if(z==3){strcat(cs,mkstr(a)); strcat(cs,"÷"); strcat(cs,mkstr(b));}
if(z==4){strcat(cs,mkstr(a)); strcat(cs,"^"); strcat(cs,mkstr(b));}
if(z==5){strcat(cs,"log("); strcat(cs,mkstr(a)); strcat(cs,")("); strcat(cs,mkstr(b)); strcat(cs,")");}
/*对显示题目处理*/
aa=QMessageBox::information(NULL,QObject::tr("PYBOX"),QObject::tr(cs),QObject::tr(mkstr(w1)),QObject::tr(mkstr(w2)),QObject::tr(mkstr(w3)));
/*显示题目答案*/
if(aa==-1)return 0;
if(aa==wz)
{
zqs++; 
zs++; 
zql=zqs*100/zs; 
memset(cs,0,2000);
strcat(cs,"right \n正确率:");
strcat(cs,mkstr(zql));
strcat(cs,"%  \n总题数:");
strcat(cs,mkstr(zs));
aa=QMessageBox::information(NULL,"PYBOX",QObject::tr(cs));
if(aa==-1)return 0;
}
else 
{
zs++; 
zql=zqs*100/zs; 
memset(cs,0,2000);
strcat(cs,"wrong\n正确答案;");
strcat(cs,mkstr(d));
strcat(cs," \n正确率:");
strcat(cs,mkstr(zql));
strcat(cs,"%   \n总题数:");
strcat(cs,mkstr(zs));
aa=QMessageBox::information(NULL,"PYBOX",QObject::tr(cs));
if(aa==-1)return 0;
}
/*显示结果*/
bc(zqs,zs);
/*存档*/
goto back;
}