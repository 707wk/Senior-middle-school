#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qtextcodec.h>
#include<time.h>
#define py QMessageBox::information(NULL,"PYBOX",QObject::tr("��ӭʹ����������ѵ����v5.0\n�����ԭ����:pengyao1207\nת����ע��ԭ����"))
#define asd "/mnt/UsrDisk/��������浵/save"
#define ase "/mnt/UsrDisk/��������浵"
/*Ԥ�����ͷ�ļ�*/
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
/*�жϴ浵�Ƿ����*/
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
/*�����浵*/
int sfwk()
{
char c;
FILE *fp;
fp=fopen(asd,"r");
if(fscanf(fp,"%c",&c)==EOF)return 0;
else return 1;
fclose(fp);
}
/*�жϴ浵�Ƿ�Ϊ��*/
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
/*��ȡ�浵*/
int bc(int zqs,int zs)
{
FILE *fp;
fp=fopen(asd,"w+");
fprintf(fp,"%d %d",zqs,zs);
fclose(fp);
}
/*�浵*/
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
/*ָ������*/
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
/*��������*/
cj();
/*�����浵�ļ�*/
if(sfwk()==1){
zqs=zqsz();
zs=zsz();}
/*��ȡ����*/
aa=py;
if(aa==-1)return 0;
/*�������*/
aa=QMessageBox::information(NULL,QObject::tr("PYBOX"),QObject::tr("��ѡ����㷶Χ"),QObject::tr("100"),QObject::tr("1000"),QObject::tr("10000"));
if(aa==-1)return 0;
if(aa==0)w=100;
if(aa==1)w=1000;
if(aa==2)w=10000;
/*���㷶Χ����*/
for(i=2;i<=w;i++)if(zsys(i,2)>w){zd=i-1;break;}
for(i=2;i<=w;i++)if(zsys(i,3)>w){gd=i-1;break;}
if(zd<0)zd=0;
if(gd<0)gd=0;
/*������Ŀ��׼��*/
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
/*�Բ�ͬ�������ʹ���*/
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
/*�����ɴ𰸴���*/
e=(rand() % 6);
if(e==0){w1=d1; w2=d2; w3=d3; wz=0;}
if(e==1){w1=d1; w2=d3; w3=d2; wz=0;}
if(e==2){w1=d2; w2=d1; w3=d3; wz=1;}
if(e==3){w1=d3; w2=d1; w3=d2; wz=1;}
if(e==4){w1=d2; w2=d3; w3=d1; wz=2;}
if(e==5){w1=d3; w2=d2; w3=d1; wz=2;}
/*����ʾ�𰸴���*/
memset(cs,0,2000);
if(z==0){strcat(cs,mkstr(a)); strcat(cs,"x"); strcat(cs,mkstr(b));}
if(z==1){strcat(cs,mkstr(a)); strcat(cs,"+"); strcat(cs,mkstr(b));}
if(z==2){strcat(cs,mkstr(a)); strcat(cs,"-"); strcat(cs,mkstr(b));}
if(z==3){strcat(cs,mkstr(a)); strcat(cs,"��"); strcat(cs,mkstr(b));}
if(z==4){strcat(cs,mkstr(a)); strcat(cs,"^"); strcat(cs,mkstr(b));}
if(z==5){strcat(cs,"log("); strcat(cs,mkstr(a)); strcat(cs,")("); strcat(cs,mkstr(b)); strcat(cs,")");}
/*����ʾ��Ŀ����*/
aa=QMessageBox::information(NULL,QObject::tr("PYBOX"),QObject::tr(cs),QObject::tr(mkstr(w1)),QObject::tr(mkstr(w2)),QObject::tr(mkstr(w3)));
/*��ʾ��Ŀ��*/
if(aa==-1)return 0;
if(aa==wz)
{
zqs++; 
zs++; 
zql=zqs*100/zs; 
memset(cs,0,2000);
strcat(cs,"right \n��ȷ��:");
strcat(cs,mkstr(zql));
strcat(cs,"%  \n������:");
strcat(cs,mkstr(zs));
aa=QMessageBox::information(NULL,"PYBOX",QObject::tr(cs));
if(aa==-1)return 0;
}
else 
{
zs++; 
zql=zqs*100/zs; 
memset(cs,0,2000);
strcat(cs,"wrong\n��ȷ��;");
strcat(cs,mkstr(d));
strcat(cs," \n��ȷ��:");
strcat(cs,mkstr(zql));
strcat(cs,"%   \n������:");
strcat(cs,mkstr(zs));
aa=QMessageBox::information(NULL,"PYBOX",QObject::tr(cs));
if(aa==-1)return 0;
}
/*��ʾ���*/
bc(zqs,zs);
/*�浵*/
goto back;
}