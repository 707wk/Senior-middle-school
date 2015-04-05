//查漏补缺-已合并 (5.19)
//不带参数的宏定义往往就是高考喜欢出的题目
#include <stdio.h>
void main()
{
	int M=4;
	#define M 5
	printf("%d",M); 	//就近原则
	#undef M
	printf("%d",M);
}
/*运行结果：54*/

/*
 * 这是带参数的宏定义
 * 并不是函数调用
 * 请同学们注意区分
 * 有一个宏展开的过程
 */
#include <stdio.h>
#define MAX(a,b) a>b?a:b
void main()
{
	int a=3,b=5;
	printf("%d",MAX(a+b,b));
	/*
	 * 要考虑优先级的问题
	 * 算术运算符高于？：运算符
	 */
}

#include <stdio.h>
#define mul(a,b) a*b
void main()
{
	int a=3,b=5;
	printf("%d",mul(a+b,a+b));
	//3+5*3+5		正确
	//(3+5)*(3+5) 		错误
}
/*结果是：23*/

#include <stdio.h>
int mul(int a,int b)
{
	return a*b;
}
void	main()
{
	int a=3,b=5;
	printf("%d",mul(a+b,a+b));
	//这个结果是64，那是因为它是函数调用，
	//上一道题目是宏代换，不一样注意区分
}

#include <stdio.h>
#define M 1
/*
 * 如果M为1就对第10行编译
 * 否则就对第12行编译
 */
void main()
{
	int a,b;
	a=3,b=5;
	#if M==1		//这是条件的开始
		printf("%d",a+b);
	#else		//这是条件的反面
		printf("%d",a-b);
	#endif	 	//这是条件的结束
}
/*结果为8*/

#include <stdio.h>
//所有代码全部要编译
void main()
{
	int a,b,m=1;
	a=3,b=5;
	if(m==1)printf("%d",a+b);
	else printf("%d",a-b);
}
/*结果为8*/

#include <stdio.h>
#define M
void main()
{
	int a,b;
	a=3,b=5;
	#ifdef M	//这是条件的开始
		printf("%d",a+b);
	#else		//这是条件的反面
		printf("%d",a-b);
	#endif	 //这是条件的结束
}
/*运行结果为8*/

#include <stdio.h>
#define M
void main()
{
	int a,b;
	a=3,b=5;
	#ifndef M	//这是条件的开始
		printf("%d",a+b);
	#else		//这是条件的反面
		printf("%d",a-b);
	#endif	 //这是条件的结束
}
/*运行结果为-2*/

#include <stdio.h>
void main()
{
	typedef int X[10];
	int i;
	X a={1,2,3,4,5,6,7,8,9,10};
	//含有10个元素的整型数组
	for(i=0;i<10;i++)
		printf("%3d",a[i]);
}
/*运行结果:1 2 3 4 5 6 7 8 9 10*/

#include <stdio.h>
void main()
{
	int x,y=4,*p=&x;
	*p++;
	(*p)++;
	printf("%3d",*p);
}
/*结果是5*/

#include <stdio.h>
void main()
{
	int x,*p;
	*p=&x;	//这是错误的
	p=&x;	// 这是正确的
}

#include <stdio.h>
void main()
{
	int a=3,b=5,*pa,*pb;
	pa=&a;
	pb=&b;
	printf("%d",pb-pa);
	//可以进行减法运算
}
/*结果是1*/

#include <stdio.h>
void main()
{
	int a=3,b=5,*pa,*pb;
	pa=&a;
	pb=&b;
	(*pa)++;
	printf("%d",*pa);
}
/*结果是4*/

#include <stdio.h>
void main()
{
	int a=3,b=5,*pa,*pb;
	pa=&a;
	pb=&b;
	printf("%d", *(pa++));
	/*
	 * 这是一个例外与*pa++等价
	 * 先取出3然后地址再自加
	 */
}
/*结果是3*/

//利用指针计算字符串的长度
#include <stdio.h>
int fun(char *a)
{
	char *p;
	p=a;
	while(*p)p++;
	return p-a;
	//用到了指针的减法运算
}
void main()
{
	char a[]="administrator";
	printf("%d",fun(a));
}

//插入法排升序
#include <stdio.h>
void main()
{
	int a[]={1,3,2,5,4},*p,*q,t;
	for(p=a+1;p<a+5;p++)
	{
		t=*p;				//不动
		q=p-1;				//减
		for(;t<*q&&(q-a)>=0;q--)//大降小升
		{
			*(q+1)=*q;		//增
		}
		*(q+1)=t;				//增
	}
	for(p=a;p<a+5;p++)
		printf("%3d",*p);
}

#include <stdio.h>
void main()
{
	int a[3][4]={1,2,3,4,
				5,6,7,8,
				9,10,11,12};
	int (*p)[4];
	//定义一个指向含有4个元素的一维数组指针
	p=a;
	//以下三行是等价的写法
	printf("%d",*(*(p+1)+2));
	printf("%d",(*(p+1))[2]);
	printf("%d",*(p[1]+2));
}
/*结果是777*/

#include <stdio.h>
#define M 4
void main()
{
	int a[M][M]={1},i=1,j=0,k=2;
	for(;j<M;k++)
	{
		a[i][j]=k;
		i--;
		j++;
		if(i<0)
		{
			i=j;
			j=0;
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<M-i;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	 }
}
/*
 * 输出：
1 3 6 10
2 5 9
4 8
7
*/

/*
 * 利用指针数组来排降序
 * 不需要用到strcpy
 */
#include <stdio.h>
void main()
{
	char *a[4]={"001",
			"002",
			"003",
			"004"},i,j,*p;
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
			if(strcmp(a[i],a[j])<0)
			{
				p=a[i];a[i]=a[j];a[j]=p;
			}
	}
	for(i=0;i<4;i++)
		printf("%s\n",a[i]);
}

//动态开辟数组示例
#include <stdio.h>
#include <malloc.h>
void main()
{
	int *p=(int *)malloc(sizeof(int)*10);
	int i,j=1;
	for(i=0;i<10;i++)
	{
		p[i]=j;
		j+=2;
	}
	for(i=0;i<10;i++)
		printf("%3d",p[i]);
	//动态开辟出来的空间，要记得释放
	free(p);
}

#include <stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a>b?b:a;
}
void main()
{
	int a=3,b=5;
	//这是指向函数的指针变量的写法
	int (*p)();
	p=min;
	printf("%d",p(a,b));
}

/*
 * 链表综合应用
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node *crfun(int n)
{
	struct node *head,*p1,*p2;
	p1=p2=head=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&head->num);
	n--;
	while(n)
	{
		p2=p1;
		p1=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&p1->num);
		p2->next=p1;
		n--;
	}
	p1->next=NULL;
	return head;
}
struct node *hbfun(struct node *p1,struct node *p2)
{
	 struct node *head,*p;
	 if(p1->num<p2->num)head=p1;
	 else head=p2;
	 p=NULL;
	 while(p1!=NULL&&p2!=NULL)
	 {
		 if(p1->num<p2->num)
		 {
			 p->next=p1;
			 p=p1;
			 p1=p1->next;
		 }
		 else
		 {
			 p->next=p2;
			 p=p2;
			 p2=p2->next;
		 }
	 }
	 //以下两句作用是把多余的部分连接起来
	 if(p1!=NULL)p->next=p1;
	 if(p2!=NULL)p->next=p2;
	 return head;
}
struct node *delfun(struct node *head,int m)
{
	struct node *p1,*p2;
	p1=p2=head;
	if(m==head->num)
	{
		head=head->next;
		return head;
	}
	while(p2!=NULL&&p2->num!=m)
	{
		p1=p2;
		p2=p2->next;
	}
	if(p2->num==m)
	{
		p1->next=p2->next;
	}
	return head;
}
struct node *insfun(struct node *head,int m)
{
	struct node *p1,*p2,*p;
	p=p2=head;
	p1=(struct node *)malloc(sizeof(struct node));
	p1->num=m;
	if(m<=head->num)
	{
		p1->next=head;
		head=p1;
		return head;
	}
	while(m>=p2->num&&p2!=NULL)
	{
		p=p2;
		p2=p2->next;
	}
		p->next=p1;
		p1->next=p2;
	return head;
}
struct node *sortfun(struct node *head)
{
	struct node *p;
	p=head->next;
	head->next=NULL;
	while(p!=NULL)
	{
		head=insfun(head,p->num);
		p=p->next;
	}
	return head;
}
void putfun(struct node *head)
{
	while(head!=NULL)
	{
		printf("%3d",head->num);
		head=head->next;
	}
	printf("\n");
}
void main()
{
	 struct node *head,*p1,*p2;
	 int m;
	 p1=crfun(5);			//创建链表
	 p2=crfun(5);			//创建链表
	 head=hbfun(p1,p2);	//合并链表
	 scanf("%d",&m);		//(二路合并法)
	 head=delfun(p1,m);		//删除节点
	 scanf("%d",&m);
	 head=insfun(p1,m);		//插入节点
	 head=sortfun(p1);		//排序链表
	 putfun(head);			//输出链表
	 //在实际应用中链表使用完后要记得释放
}
4.27

#include <stdio.h>
void main()
{
	enum a
	{
		one,two,three=1,four,five=0,
		six,seven,eight,nthreeine,ten
	};
	/*
	 * 里面的＝号不代表赋值
	 * 赋值只能用在变量当中
	 * 它只是一个申明
	 */
	//结果是0
	printf("%d",one);
}

#include <stdio.h>
void main()
{
	enum sz
	{
		one,two,three=1,four,five=0
	}a,b,c;
	/*
	 * 里面的＝号不代表赋值
	 * 赋值只能用在变量当中
	 * 它只是一个申明
	 */
	a=four;
	//结果是2
	printf("%d",a);
}

#include <stdio.h>
void main()
{
	enum sz
	{
		one,two,three=1,four,five=2
	}a,b,c;
	/*
	 * 里面的＝号不代表赋值
	 * 赋值只能用在变量当中
	 * 它只是一个申明
	 */
	for(a=one;a<=five;a++)
		printf("*");
	//结果是***
}

#include <stdio.h>
void main()
{
	enum
	{
		red,yellow,blue,white,black
	}i,j,k;
	FILE *fp;
	char *color[5]={"red",
				"yellow",
				"blue",
				"white",
				"black"};
	int n=0;
	fp=fopen("abc.txt","w");
	for(i=red;i<=black;i++)
	for(j=red;j<=black;j++)
	for(k=red;k<=black;k++)
	if(i!=j&&i!=k&&j!=k)
	{
		fprintf(fp,"%d:%s-%s-%s\n",
			n+1,color[i],color[j],color[k]);
		n++;
	}
	printf("%d",n);
	/*
	 * 结果在文件abc.txt里
	 * 自已编译运行
	 */
	fclose(fp);
}

//共用体示例
#include <stdio.h>
union node
{
	int a;
	float b;
	char c;
};
void main()
{
	union node x={256};
	/*
	 *	x={256};//这种写法是错误的
	 */
	printf("%d",x.c);
}
//00000000 00000000 00000001 00000000
/* 结果是0 */

//共用体示例
#include <stdio.h>
union node
{
	int a;
	float b;
	char c;
};
void main()
{
	union node x;
	x.a=256;
	x.c=1;
	printf("%d",x.a);
}
//00000000 00000000 00000001 00000000
//程序运行的结果是257
/*
 * 联合体它们是共用同一存储单元
 * 以自右至左的方式排列
 * 共用体在内存当以最长的那个内存单元为准
 */

#include <stdio.h>
void main()
{
	int a=1,b=2;
	//这是异或运算符
	a=a^b;
	b=a^b;
	a=a^b;
	printf("%d%d",a,b);
}
/* 结果为21 */
//1^0=1,0^1=1,0^0=0,1^1=0

#include <stdio.h>
void main()
{
	int x=0xffff,y=10;
	printf("%d",x&y);
}
//1111 1111 1111 1111
//0000 0000 0000 1010
//0000 0000 0000 1010
//按位与起一个保留作用.
//结果为10

#include <stdio.h>
void main()
{
	int x=0xffff,y=10;
	printf("%d",x|y);
}
//1111 1111 1111 1111
//0000 0000 0000 1010
//1111 1111 1111 1111
/* 结果为-1 */
/*
原码
+10:00000000 00001010
-10:10000000 00001010

+0 :00000000 00000000
-0 :10000000 00000000

反码
+10:00000000 00001010
-10:11111111 11110101

+0:0000000 0000000
-0:1111111 1111111

补码:
+0:	00000000 00000000
-0:	11111111 11111111 + 1
	00000000 00000000
	采用了溢出原理.
	口决,各位取反再+1
*/

#include <stdio.h>
void main()
{
	printf("%d",-1>>2);
}
/* 程序运行结果是-1 */

#include <stdio.h>
void main()
{
	int a=1;
	//移了，但没有赋值(好坑的感觉)
	a>>2;
	printf("%d",a);
}
/* 结果是1*/

#include <stdio.h>
void main()
{
	int a=7;
	//算术运算符的优先级来得高些
	a=a+1>>2;
	printf("%d",a);
}
/* 结果是2 */

//循环右移1位的算法，n只能是1
#include <stdio.h>
void main()
{
	int x=5,a,b,n;
	scanf("%d",&n);
	a=x>>n;
	b=x&0x0001; //保留关键位
	//	 0000 0000 0000 0101
	//	 0000 0000 0000 0001
	//	 0000 0000 0000 0001
	b=b<<(16-n);
	printf("%d",a|b);
}
// 00000000 00000101
//00000000 00000010
//10000000 00000000
/* 结果是-32766 */

//循环右移n位的算法
#include <stdio.h>
void main()
{
	int x=10,a,b,n;
	//这个地方申明为无符号非常重要
	unsigned c;
	scanf("%d",&n);
	a=x>>n;
	c=0xffff;
	c=c>>(16-n);
	//11111111 11111111
	//00000000 00000011
	b=x&c; //保留关键位
	//	 0000 0000 0000 1010
	//	 0000 0000 0000 0011
	//	 0000 0000 0000 0010
	b=b<<(16-n);
	printf("%d",a|b);
}

//循环右移n位的算法
#include <stdio.h>
struct bit
{
	unsigned a1  :1;
	unsigned a2  :1;
	unsigned a3  :1;
	unsigned a4  :1;
	unsigned a5  :1;
	unsigned a6  :1;
	unsigned a7  :1;
	unsigned a8  :1;
	unsigned a9  :1;
	unsigned a10:1;
	unsigned a11:1;
	unsigned a12:1;
	unsigned a13:1;
	unsigned a14:1;
	unsigned a15:1;
	unsigned a16:1;
};
void putfun(int x)
{
	struct bit *p;
	p=(struct bit *)&x;
	printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",p->a16,p->a15,p->a14,p->a13,p->a12,p->a11,p->a10,p->a9,p->a8,p->a7,p->a6,p->a5,p->a4,p->a3,p->a2,p->a1);
}
void main()
{
	int x=10,a,b,n;
	//这个地方申明为无符号非常重要
	unsigned c;
	scanf("%d",&n);
	a=x>>n;
	c=0xffff;
	c=c>>(16-n);
	//11111111 11111111
	//00000000 00000011
	b=x&c; //保留关键位
	//	 0000 0000 0000 1010
	//	 0000 0000 0000 0011
	//	 0000 0000 0000 0010
	b=b<<(16-n);
	x=a|b;
	putfun(x);
	printf("%d",a|b);
}
/*
 * 位右移，相当于每次除以2
 * 位左移，相当于每次乘以2
 * 有算术运算符和位运算符先算算术运算符
 */

#include <stdio.h>
void main()
{
	int x=999,n=0;
	while(x)
	{
		x=x&(x-1);
		n++;
	}
	printf("%d",n);
	/*
	 * 循环右移n位的算法
	 * 程序结果是2
	 * 相当于求10的二进制里1的个数
	 */
}

#include <stdio.h>
struct bit
{
	unsigned a1:1;
	unsigned a2:1;
	unsigned a3:1;
	unsigned a4:1;
};
void main()
{
	struct bit *p;
	int x=10;
	p=(struct bit *)&x;
	printf("%u%u%u%u",
		p->a4,p->a3,p->a2,p->a1);
}
/*
 * 结序结果是1010
 * 利用位段直接将10进制化成2进制并输出
 * （考纲没有明确指出）
 */

//fgetc()函数的应用
#include <stdio.h>
void main()
{
	FILE *fp;
	char x;
	//这是只读方式
	fp=fopen("abc.txt","r");
	while((x=fgetc(fp))!=EOF)
	{
		//fgetc(fp)从文件当中读取一个字符
		//然后光标向后移动一格
		printf("%c",x);
	}
	fclose(fp);
}

#include <stdio.h>
void main()
{
	FILE *fp;
	char x;
	//w方式是写入方式
	fp=fopen("abc.txt","w");
	while((x=getchar())!='\n')
	{
		fputc(x,fp);
		//每调用一次，光标向后移动一格
	}
	fclose(fp);
}

#include <stdio.h>
//asci码文件的复制
void fun(FILE *fp1,FILE *fp2)
{
	char x;
	while((x=fgetc(fp1))!=EOF)
	{
		fputc(x,fp2);
	}
}
void main()
{
	FILE *fp1,*fp2;
	fp1=fopen("abc.txt","r");
	fp2=fopen("123.txt","w");
	fun(fp1,fp2);
	fclose(fp1);
	fclose(fp2);
	printf("success's copy");
}

#include <stdio.h>
void main()
{
	FILE *fp;
	int x,x1;
	fp=fopen("abc.txt","r");
	//利用函数从文件当中读取两个数字
	fscanf(fp,"%d%d",&x,&x1);
	printf("%d%d",x,x1);
	fclose(fp);
}

/*
 * 把键盘缓冲区里面的字符写入到文件当中去
 */
#include <stdio.h>
void main()
{
	FILE *fp;
	int x,x1;
	scanf("%d%d",&x,&x1);
	fp=fopen("abc.txt","w");
	fprintf(fp,"%d %d",x,x1);
	fclose(fp);
}

#include <stdio.h>
void main()//从文件当中读取一个字符串
{
	FILE *fp;
	char *x;
	fp=fopen("abc.txt","r");
	fgets(x,6,fp);
	/*
	* 读n个取n-1个
	* 其中第1个参数是地址
	* 第2个参数是长度
	* 第3个参数是文件
	*/
	puts(x);
	fclose(fp);
}

#include <stdio.h>
void main()//把字符串，写到文件当中去
{
	FILE *fp;
	char *x="thisisabook";
	fp=fopen("abc.txt","w");
	fputs(x,fp);
	fclose(fp);
}
4.28

#include <stdio.h>
struct node
{
	int num;
	char a[20];
};
void main()
{
	struct node x[3]={1,"guanyu",
					2,"zhangfei",
					3,"zhaoyun"};
	FILE *fp;
	int i;
	fp=fopen("abc.txt","wb");
	for(i=0;i<3;i++)
		fwrite(x+i,sizeof(struct node),1,fp);
	fclose(fp);
}
//将结构体数组的内容写到文件里面去

#include <stdio.h>
struct node
{
	int num;
	char a[20];
};
void main()
{
	struct node x[3];
	FILE *fp;
	int i;
	fp=fopen("abc.txt","rb");
	for(i=0;i<3;i++)
		fread(x+i,sizeof(struct node),1,fp);
	fclose(fp);
	for(i=0;i<3;i++)
	{
		printf("%d:%s",x[i].num,x[i].a);
		printf("\n");
	}
}
/* 
 * 从文件当中读取结构体数据
 * 并一行一行的显示出来
 */

#include <stdio.h>
void main()
{
	int n;
	FILE *fp;
	scanf("%d",&n);
	fp=fopen("abc.txt","wb");
	putw(n,fp);
	fclose(fp);
}
//将一个阿拉伯数字写到文件到当中去

#include <stdio.h>
void main()
{
	int n;
	FILE *fp;
	fp=fopen("abc.txt","rb");
	n=getw(fp);
	printf("%d",n);
	fclose(fp);
}
/*
 * 从一个文件当中读取一个阿拉伯数字
 * 到屏幕中显示出来
 */

#include <stdio.h>
void fputw(int n,FILE *fp)
{
	char *a;
	int i;
	a=(char *)&n;
	for(i=0;i<2;i++)
	{
		fputc(a[i],fp);
	}
}
void main()
{
	int n;
	FILE *fp;
	scanf("%d",&n);
	fp=fopen("abc.txt","wb");
	fputw(n,fp);
	fclose(fp);
}
//以上程序的功能是实现与putw()函数一样的功能

#include <stdio.h>
int fgetw(FILE *fp)
{
	int i,*p;
	char a[2];
	p=(int *)a;
	for(i=0;i<2;i++)
		a[i]=fgetc(fp);
	return *p;
}
void main()
{
	int n;
	FILE *fp;
	fp=fopen("abc.txt","rb");
	n=fgetw(fp);
	printf("%d",n);
	fclose(fp);
}
//以上程序的功能与getw()函数的功能是一样的

#include <stdio.h>
void main()
{
	FILE *fp;
	char *a;
	fp=fopen("abc.txt","r");
	fseek(fp,4L,SEEK_SET); 
	//SEEK_SET 相当于 0
	//4L是长整型常量,代表往右移动4格
	fscanf(fp,"%s",a);
	printf("%s",a);
}
/* 123456789
 * 结序运行的结果：56789
 * ftell(fp); 显示光标的位置
 * rewind(fp); 光标来到文件的开头
 */
4.28

//求阶乘.方法一:
#include <stdio.h>
int fun(int n)
{
	if(n==0||n==1)return 1;
	return fun(n-1)*n;
}
void main()
{
	printf("%d",fun(5));
}

//求阶乘.方法二:
#include <stdio.h>
int fun(int n)
{
	int t=1,i;
	for(i=0;i<n;i++)
		t=t*(i+1);
	return t;
}
void main()
{
	printf("%d",fun(5));
}

//把一个整数各个位上的数字存到数组中
//该算法为倒序输出
#include <stdio.h>
void fun(int n,int a[])
{
	int i;
	for(i=0;i<20;i++)
		a[i]=-1;
	for(i=0;n;i++)
	{
		a[i]=n%10;
		n=n/10;
	}
}
void main()
{
	int n,a[20],i;
	scanf("%d",&n);
	fun(n,a);
	for(i=0;a[i]!=-1;i++)
		printf("%3d",a[i]);
}

//求一个数的因子之和
#include <stdio.h>
int fun(int n)
{
	int i,s=0;
	for(i=1;i<=n;i++)
		if(n%i==0)s=s+i;
	return s;
}
void main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fun(n));
}

//求2个数的最大公约数，辗转相除法
#include <stdio.h>
int fun(int a,int b)
{
	int r;
	r=a%b;
	//辗转相除法的核心
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
void main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",fun(a,b));	//求最大公约数
	printf("%d",a*b/fun(a,b));	//求最小公倍数
}

#include <stdio.h>
#include <math.h>
//判断m是否为素数
int fun(int m)
{
	int i,n;
	n=sqrt(m);
	/* 使用临时变量存储，减少运算次数 */
	for(i=2;i<=n;i++)
		if(m%i==0)return 0;
	return 1;
}
//返回n的反序数
int ffun(int n)
{
	int s=0;
	while(n)
	{
		s=s*10+n%10;
		n=n/10;
	}
	return s;
}
//判断n是否为回文数
int hwfun(int n)
{
	//判断n是否与它自己的反序数相等
	if(n==ffun(n))return 1;
	return 0;
}
void main()
{
	int n;
	for(n=3;n<1000;n+=2)
	{
		//n为素数且n的反序数也为素数
		if(fun(n)&&fun(ffun(n)))
		{
			printf("%5d",n);
		}
		//n为素书并且n也为回文数
		if(fun(n)&&hwfun(n))
		{
			printf("%5d",n);
		}
	}
}
4.29

//求一个数组当中的最大值
#include <stdio.h>
int max(int a[],int n)
{
	int i,max;
	max=a[0];
	for(i=1;i<n;i++)
		if(max<a[i])max=a[i];
	return max;
}
void main()
{
	int a[]={1,2,3,4,5,9,7};
	printf("%d",max(a,7));
}
//结果9

//快速排升序法
#include <stdio.h>
void sortfun(int a[],int n)
{
	 int i=0,j=n-1,t=a[0];
	 if(n>1)
	 {
		while(i<j)
		{
			for(;i<j;j--)
				if(a[j]<t)
				{
					a[i]=a[j];
					break;
				}
			for(;i<j;i++)
				if(a[i]>t)
				{
					a[j]=a[i];
					break;
				}
			a[i]=t;
		}
		sortfun(a,i);
		sortfun(a+i+1,n-i-1);
	 }
}

void main()
{
	int a[]={1,5,3,3,2,6},i;
	sortfun(a,6);
	for(i=0;i<6;i++)
		printf("%3d",a[i]);
}

//顺序查找法，返回这个元素数组当中的位置
#include <stdio.h>
int fun(int a[],int m,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(m==a[i])return i+1;
	return 0;
}
void main()
{
	int a[]={1,2,3,4,5,6};
	printf("%d",fun(a,4,6));
}

//折半查找法(二分法)
#include <stdio.h>
int fun(int a[],int x,int n)
{
	int i,j,m;
	i=0;
	j=n-1;
	m=(i+j)/2;
	while(i<j)
	{
		if(a[m]<x)i=m+1;
		/*
		 * 如果待找的元素比中间的数还要大
		 * 就让最小那个下标＝中间下标+1
		 */
		else j=m-1;
		m=(i+j)/2;
	}
	if(x==a[m])return m+1;
	return 0;
}
void main()
{
	int a[]={1,2,3,4,5,6};
	printf("%d",fun(a,0,6));
}

//利用插入法插入一个元素到已经升序的数组当中去
#include <stdio.h>
void fun(int a[],int x,int n)
{
	int i=0,j=n;
	while(x>a[i])i++;
	while(j>i)
	{
		a[j]=a[j-1];
		j--;
	}
	a[j]=x;
}
void main()
{
	int a[7]={1,2,3,4,5,7},i=0;
	fun(a,7,6);
	for(i=0;i<7;i++)
		printf("%3d",a[i]);
}

//采用冒泡思想插入一个元素到已经升序的数组当中去
#include <stdio.h>
void fun(int a[],int x,int n)
{
	int i,t;
	a[n]=x;
	for(i=n;i>0;i--)
		if(a[i]<a[i-1])
		{
			t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}
}
void main()
{
	int a[7]={1,2,3,4,5,7},i=0;
	fun(a,6,6);
	for(i=0;i<7;i++)
		printf("%3d",a[i]);
}
4.30

//数组转置
#include <stdio.h>
#define M 3
void main()
{
	int a[M][M]={1,2,3,4,5,6,7,8,9},i,j,t;
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<M-1;i++)
		for(j=i+1;j<M;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
}

//行列相加为相同的数
#include <stdio.h>
#define M 5
void main()
{
	int a[M][M]={0},i=0,j=M/2,m=1;
	a[i][j]=m;
	while(m<M*M)
	{
		m++;
		i--;
		j++;
		if(i<0&&j>M-1)
		{
			i+=2;
			j--;
		}//行与列同时超出范围
		if(i<0)i=M-1;//仅行超出范围
		if(j>M-1)j=0;//仅列超出范围
		if(a[i][j]!=0)
		{
			i+=2;
			j--;
		}
		a[i][j]=m;
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
}

//将十进制转化为二进制
#include <stdio.h>
int fun(int n) //这个函数只能起一个输出的作用。
{
	if(n<2){printf("%d",n);return;}
	fun(n/2);
	printf("%d",n%2);
}
void main()
{
	int n;
	scanf("%d",&n);
	fun(n);
}

//将十进制转化为二进制
#include <stdio.h>
//这个函数返回一个结果
int fun(int n)
{
	if(n<2)return n;
	return fun(n/2)*10+n%2;
}
void main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fun(n));
}

//将十进制转化为二进制
#include <stdio.h>
//这个函数只能起一个输出的作用。
fun(int n,int a[])
{
	int i=0;
	while(n)
	{
		a[15-i]=n%2;
		n=n/2;
		i++;
	}
	return a;
}
void main()
{
	int n,a[16]={0},i;
	scanf("%d",&n);
	fun(n,a);//用双向传值
	for(i=0;i<16;i++)
		printf("%d",a[i]);
}

#include <stdio.h>
void main()
{
	char a[]="this is a book ",n=0,*p;
	p=a;
	while(*p)
	{
		while(*p==' '&&*p)p++;//跳过空格
		if(*p!='\0')n++;//没有结束就计数
		while(*p!=' '&&*p)p++;//跳过非空格
	}
	printf("%d",n);
}
//输出4

//求一个字符串中单词的数量
#include <stdio.h>//这个函数返回一个结果
/*
 * 谭浩强书上的算法
 * 规则0001规则或1110规则
 */
void main()
{
	char a[]="  this is a book ",
	int n=0,i,flag=0;
	for(i=0;a[i];i++)
	{
		if(a[i]==' ')flag=0;
		else if(flag==0)
		{
			flag=1;
			n++;
		}
	}
	printf("%3d",n);
}
//输出4

//分鱼问题
#include <stdio.h>
int fun(int n)
{
	if((n-1)%5==0)return n-(n-1)/5-1;
	return 0;
}
void main()
{
	int n,x,i;
	for(n=1;;n++)
	{
		x=n;
		for(i=1;i<=5;i++)
		{
			if((x=fun(x))==0)break;
		}
		if(i==6)break;
	}
	printf("%d\n",n);
}
//输出3121
5.4

#include <stdio.h>
//这个函数返回剩余鱼的量
int fun(int n,int i)
{  
	if((n+1)%(i+1)==0)return n=n-(n+1)/(i+1);
	return 0;
	//如果条件不成立，鱼就卖不出去了。
}
void main()
{
	int n,x,i;
	for(n=1;;n++)
	{
		x=n;//累试法
		for(i=1;i<=4;i++)
			if((x=fun(x,i))==0)break;
		if(i==5&&x==11)break;
	}
	printf("%3d",n);
}

//亲密数
#include <stdio.h>
int fun(int n)
{
	int s=0,i;
	for(i=1;i<n;i++)
		if(n%i==0)s=s+i;
	return s;
}
void main()
{
	int a,b;
	for(a=1;a<3000;a++)
	{
		b=fun(a);
		if(a==fun(b)&&a!=b)
			printf("%3d %3d\n",a,b);
	}
}
5.6

#include <stdio.h>
void main()
{
	long i,x=13,t=1;
	//如果是保留3位就用int型
	//如果是4位就用long型
	for(i=1;i<=13;i++)
	{
		t=(t%10000)*x;
	}
	printf("%d",t%10000);
}

#include <stdio.h>
void main()
{
	int x,i,m,n=0;
	scanf("%d",&x);
	for(i=5;i<=x;i+=5)//每次+5
	{
		m=i;
		//用一个临时的变量来存放i
		while(m%5==0)
		{
			n++;
			m=m/5;
		}
	}
	printf("%d",n);
}

#include <stdio.h>
#include <math.h>
int fun(int a,int b)//判断是否为完全平方数
{
	int m;
	m=sqrt(a*1000+a*100+b*10+b);
	if(m*m==a*1000+a*100+b*10+b)
		return 1;
	return 0;
}
void main()
{
	int a,b;
	for(a=1;a<10;a++)
	for(b=0;b<10;b++)
		if(fun(a,b)==1)
			printf("%d%d%d%d",a,a,b,b);
}
//输出 7744

//★除不尽的自然数
//一个自然数被8除余1，
//所得的商被8除也余1，
//再将第二次的商被8除后余7，
//最后得到一个商为a
//又知这个自然数被17除余4，
//所得的商被17除余15，
//最后得到一个商是a的2倍
//求这个自然数
void main()
{
	int a,b,c;
	for(a=1;;a++)
	{
		b=((a*8+7)*8+1)*8+1;
		c=(2*a*17+15)*17+4;
			if(b==c)
				break;
	}
	printf("%d",b);
}

#include <stdio.h>
int fun(int n,int m)
{	
	//将十进制转换成m进制(m<10)
	if(n<m)return n;
	return fun(n/m,m)*10+n%m;
}
int ffun(int n)
{	
	//求一个数的反序数
	int s=0;
	while(n)
	{
		s=s*10+n%10;
		n=n/10;
	}
	return s;
}
void main()
{
	int n,a,b;
	for(n=100;n<1000;n++)
	{
		a=fun(n,7);
		b=fun(n,9);
		if(ffun(a)==b)break;
	}
	printf("%d:%d,%d",n,a,b);
}

#include <stdio.h>
int ffun(int n)
{	
	//求一个数的反序数
	int s=0;
	while(n)
	{
		s=s*10+n%10;
		n=n/10;
	}
	return s;
}
void main()
{
	int i;
	for(i=1000;i<10000;i++)
		if(ffun(i)==9*i)break;
	printf("%d",i);
}

#include <stdio.h>
int fun(long n)
{
	long s=0,m=n;
	while(n)
	{
		s=s*10+n%10;
		n=n/10;
	}
	if(s==m)return 1;
	return 0;
}
void main()
{
	long i,v;
	for(i=95859+1;i<=99999;i++)
	{
		v=(i-95859)/2;
		if(fun(i)&&v>=60&&v<=120)
			break;
	}
	printf("%ld:%d",i,v);
}

/*
 * 由两个平方三位数获得三个平方二位数
 * 已知两个平方三位数abc和xyz，
 * 其中a、b、c、x、y、z未必是不同的；
 * 而ax、by、cz是三个平方二位数
 * 请编程求三位数abc和xyz
 */
#include <stdio.h>
#include <math.h>
int fun(int n)
{
	int m;
	m=sqrt(n);
	if(m*m==n)return 1;
	return 0;
}
void main()
{
	int a,b,c,x,y,z,m,n;
	for(m=100;m<1000;m++)
		for(n=100;n<1000;n++)
		{
			a=m/100;
			b=m/10%10;
			c=m%10;
			x=n/100;
			y=n/10%10;
			z=n%10;
			if(fun(m)&&fun(n))
			if(fun(a*10+x))
			if(fun(b*10+y))
			if(fun(c*10+z))
				printf("%5d%5d\n",m,n);
		}
}

//自守数
#include <stdio.h>
int fun(int n)
{
	long x;
	x=1L*n*n;	//强制类型转换
	if(x%10==n)return 1;
	if(x%100==n)return 1;
	if(x%1000==n)reutrn 1;
	if(x%10000==n)return 1;
	return 0;
}
void main()
{
	int i;
	for(i=1;i<=10000;i++)
	{
	  if(fun(i))printf("%d*%d=%ld\n",i,i,1L*i*i);
	}
}
5.11

/*
 * 新娘和新郞
 * 三对情侣参加婚礼，三个新郞为
 * A、B、C，三个新娘为X、Y、Z。
 * 有人不知道谁和谁结婚，
 * 于是询问了六位新人中的三位，
 * 但听到的回答是这样的：A说他将和
 * X结婚；X说她的未婚夫是C；
 * C说他将和Z结婚。
 * 这人听后知道他们在开玩笑，
 * 全是假话。请编程找出谁将和谁结婚。
*/
#include <stdio.h>
void main()
{
	int a,b,c;
	for(a='X';a<='Z';a++)
	for(b='X';b<='Z';b++)
	for(c='X';c<='Z';c++)
	{
		if(a!=b&&a!=c&&b!=c)
		{
		  //说的那三句话是假话
		  if((a=='X')+(c=='X')+(c=='Z')==0)
		  {
			goto _END;
		  }
		}
	}
	_END:;
	printf("A-%c\nB-%c\nC-%c",a,b,c);
}
/*
 * 结果是:
 * A--Z
 * B--X
 * C--Y
*/

/*
 * 用 1 到 9 组成 3 个 3 位数
 * 且三者之比为 1:2:3
 */
#include <stdio.h>
int fun(int a,int b,int c)
{
	int x[9],i,j;
	x[0]=a/100;
	x[1]=a/10%10;
	x[2]=a%10;
	x[3]=b/100;
	x[4]=b/10%10;
	x[5]=b%10;
	x[6]=c/100;
	x[7]=c/10%10;
	x[8]=c%10;
	for(i=0;i<8;i++)
		for(j=i+1;j<9;j++)
		{
			if(x[i]==x[j])return 0;
			if(x[i]== 0 )return 0;
			if(x[j]== 0 )return 0;
		}
	return 1;
}
void main()
{
	int a,b,c;
	for(a=100;a<333;a++)
	{
		b=2*a;
		c=3*a;
		if(fun(a,b,c))
		printf("%4d %4d %4d\n",a,b,c);
	}
}
/*
 * 结果：
 * 192  384  576
 * 219  438  657
 * 273  546  819
 * 327  654  981
*/

//投票算法，此算法比较先进。
#include <stdio.h>
int fun(int a,int b,int c)
{
	int x[10]={0},i,j;
	x[a/100]=1;
	x[a/10%10]=1;
	x[a%10]=1;
	x[b/100]=1;
	x[b/10%10]=1;
	x[b%10]=1;
	x[c/100]=1;
	x[c/10%10]=1;
	x[c%10]=1;
	for(i=1;i<10;i++)
		if(x[i]==0)return 0;
	return 1;
}
void main()
{
	int a,b,c;
	for(a=100;a<333;a++)
	{
		b=2*a;
		c=3*a;
		if(fun(a,b,c))
		printf("%4d %4d %4d\n",a,b,c);
	}
}
/*结果同上*/

/*
 * 角谷猜想
 * 日本一位中学生发现一个奇妙的 “ 定理 ”
 * 请角谷教授证明,而教授无能为力,于是产生
 * 角谷猜想。猜想的内容是:任给一个自然数,
 * 若为偶数除以 2,若为奇数则乘 3 加 1,得到
 * 一个新的自然数后按照上面的法则继续演算
 * 若干次后得到的结果必然为 1。请编程验证。
 */
int fun(long n)
{
	long m;
	if(n<2)return n;
	if(n%2==0)m=n/2;	//若为偶数除以2，
	else m=3*n+1;	//若为奇数则乘3加1
	return fun(m);
}
void main()
{
	long n;
	for(n=1;n<100000;n++)
		if(fun(n)!=1)break;
	if(n>=100000)printf("ok");
	else printf("no");
}

/*
 * 数论中著名的 “ 四方定理 ” 讲的是
 * 所有自然数至多只要用四个数的平方
 * 和就可以表示。请编程证此定理。
 */
#include <stdio.h>
#include <math.h>
int fun(int n)
{
	int a,b,c,d,m=sqrt(n);
	for(a=0;a<=m;a++)
	for(b=0;b<=m;b++)
	for(c=0;c<=m;c++)
	for(d=0;d<=m;d++)
	if(a*a+b*b+c*c+d*d==n)
		return 1;
	return 0;
}
void main()
{
	int n;
	for(n=1;n<1000;n++)
		if(fun(n)==0)break;
	if(n>=1000)printf("ok");
	else printf("no");
}
5.12

/*
 * 求数列 1 2 2 2 3 3 3 3 3 4 4 4 4 前20项和
 */
#include <stdio.h>
void main()
{
	int i,j,k=0,flag=1,s=0;
	for(i=1;flag;i++)
	{
		for(j=1;j<=2*i-1;j++)
		{
			if(k==20)
			{
				flag=0;
				break;
			}
			s=s+i;
			k++;
		}
	}
	printf("%d",s);
}

/*
 * 一本书撕去一张之后其余的页码之和为11166
 * 求撕去的那一张，和页码总数
 */
#include <stdio.h>
int fun(int *n)
{
	int i,j,s=0;
	for(i=1;;i+=2)
	{
		s=0;
		for(j=1;s<11166;j++)
			if(j!=i&&j!=i+1)
			{
				s=s+j;
				if(s==11166)
				{
					*n=j;
					return i;
				}
			}
	}
}
void main()
{
	int n;
	printf("%d %d",n,fun(&n));
}

/*
 * 利用随机数函数随机生成10个不重复的随机数
 */
#include <stdio.h>
#include <stdlib.h>
void main()
{
	int n,a[10],i,j;
	randomize();
	a[0]=random(10);
	for(i=1;i<10;i++)
	{
		a[i]=random(10);
		for(j=0;j<i;j++)
			if(a[i]==a[j])
			{
				i--;
				break;
			}
	}
	for(i=0;i<10;i++)
		printf("%3d",a[i]);
}

/*
 * n盏灯，k个人去开关灯
 * 开着的被关闭，关闭的被打开
 * 最终哪些灯是开的
 */
#include <stdio.h>
#include <malloc.h>
int fun(int a[],int n,int m)
{
	int i;
	for(i=0;i<m;i++)
		if((i+1)%n==0)a[i]=-a[i];
}
void main()
{
	int *a,i,k,n;
	scanf("%d%d",&n,&k);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)a[i]=-1;
	for(i=1;i<=k;i++)
	{
		fun(a,i,n);
	}
	for(i=0;i<n;i++)
		if(a[i]==1)printf("%3d",i+1);
}

/*
 * 输出符合条件的三位数素数：
 * 该数的倒序数、
 * 各位数字之和、各位数字之积也为素数
 */
#include <stdio.h>
#include <math.h>
//判断是否为素数
int isfun(int n)
{

	int m=sqrt(n),i;
	if(n<2)return 0;
	for(i=2;i<=m;i++)
		if(n%i==0)return 0;
	return 1;
}
//返回倒序数
int fun1(int n)
{
	int s=0;
	while(n)
	{
		s=s*10+n%10;
		n=n/10;
	}
	return s;
}
//计算各位数字之和
int fun2(int n)
{
	if(n==0)return n;
	return fun2(n/10)+n%10;
}
//计算各位数字之积
int fun3(int n)
{
	int s=1;
	while(n)
	{
		s=s*(n%10);
		n=n/10;
	}
	return s;
}
void main()
{
	int n;
	for(n=101;n<1000;n++)
		if(isfun(n)&&isfun(fun1(n))&&
		isfun(fun2(n))&&isfun(fun3(n)))
				printf("%d\n",n);
}
5.14

#include <stdio.h>
int fun(unsigned long n)
{
	int a[10]={0},i;
	while(n){
	a[n%10]++;
	n=n/10;
	}
	for(i=0;i<10;i++)
		if(a[i]>1)return 0;
	return 1;
}
void main()
{
	unsigned long x;
	for(x=10;x<1000;x++)
	{
		if(fun(x*x))printf("%lu %lu\n",x,x*x);
	}
}

/*
 * 删除一个字符串中重复的字符只留下最后一个
 */
#include <stdio.h>
#include <stdio.h>
void main()
{
	char a[]="12332123523123";
	int i,j;
	for(i=0;a[i];i++)
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			{
			 strcpy(a+i,a+i+1);
			 i--;
			}
		}
	 puts(a);
}

/*
 * 耶稣的叛徒
 */
#include <stdio.h>
void main()
{
	int a[10],i,j,m=0,n=10;
	for(i=0;i<10;i++)
		a[i]=i+1;
	for(i=0;n>1;i++)
	{
		if(i==10)i=0;			//范围
		if(a[i]!=0)m++;			//数数
		if(m==3){a[i]=0;m=0;n--;}//归零
	}
	for(i=0;i<10;i++)
		if(a[i]!=0)printf("%d",a[i]);
}

/*
 * 删除一个字符串中ASCII码为偶数的字符
 */
#include <stdio.h>
void fun(char a[])
{
	char *p,*q=a;
	for(p=a;*p;p++,p++)
		if(*p%2!=0)*q=*p;
	*q=0;
}
void main()
{
	char a[]="123456789",*p,*q;
	fun(a);
	puts(a);
}

/*
 * 求1－100里面素数和的平均值
 */
#include <stdio.h>
#include <math.h>
int fun(int n)
{
	int m,i;
	if(n==1)return 0;
	m=sqrt(n);
	for(i=2;i<=m;i++)
		if(n%i==0)return 0;
	return 1;
}
void main()
{
	int n,s=0,m=0;
	float ave;
	for(n=1;n<=100;n++)
	{
		if(fun(n)){s=s+n;m++;}
	}
	ave=1.0*s/m;
	printf("%f",ave);
}

#include <stdio.h>
int fun(int n)	//求1+……到n
{  
	if(n==1)return 1;
	return fun(n-1)+n;
}
int sfun(int n)	//求n组上面的和的和
{
	if(n==1)return 1;
	return sfun(n-1)+fun(n);
}
void main()
{
	printf("%d",sfun(3));
}

#include <stdio.h>
void fun(char *a,char *b)
{
	char t,*p;
	for(p=a;p-a<strlen(b);p++);
	t=*p;
	strcpy(a,b);
	while(*a)a++;
	*a=t;
}
void main()
{
	char a[]="abcedf",b[]="fk";
	fun(a,b);
	puts(a);
}
/*
 * 上面程序的结果：fkcedf
 */

#include <stdio.h>
void main()
{
	char a[]="abcedf",b[]="fk";
	char *p,*q;
	p=a;
	for(q=b;*q;p++,q++)
	{
		*p=*q;
	}
	puts(a);
}
/*
 * 上面程序的结果：fkcedf
 */
5.19
