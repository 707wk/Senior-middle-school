/*----------------------------------------------
File: G:\soft\02\168.c
Date: 2014-3-26 17:55:18
Author: 1174843091@qq.com
利用malloc创建链表，增加、删除或倒序链表
----------------------------------------------*/
#include<stdio.h>
#include<malloc.h>

struct student
{
	int num;
	struct student *next;
};

//检测链表降序/顺序
int shun(struct student *head)
{
	struct student *p,*q;
	for(p=q=head;p!=NULL;)
	{
		if(p->num<q->num)return 0;
		q=p;
		p=p->next;
	}
	return 1;
}

//输出链表
void prf(struct student *head)
{
	while(head!=NULL)
	{
		printf("%3d",head->num);
		head=head->next;
	}
	printf("\n");
}

//倒序链表
struct student *dao(struct student *head)
{
	struct student *p,*q,*temp;
	for(p=NULL,q=head;q!=NULL;)
	{
		temp=q->next;
		q->next=p;
		p=q;
		q=temp;
	}
	head=p;
	return head;
}

int main()
{
	int n,i=1,num,flag;
	char c[100];
	struct student *head,*p,*q,*temp;
	printf("请输入要创建的链表数:\n");
	scanf("%d",&n);
	if(n<1)return 0;
	head=p=q=(struct student *)malloc(sizeof(struct student));
	q->num=i++;
	for(n--;n>0;n--)
	{
		q=p;
		p=(struct student *)malloc(sizeof(struct student));
		p->num=i++;
		q->next=p;
	}
	p->next=NULL;
	q=p=head;
	prf(head);
	getchar();
	for(i=1;head!=NULL;i=1,q=p=head)
	{
		if(flag=shun(head))printf("当前链表为升序\n");
		else printf("当前链表为降序\n");
		printf(" 你想要插入一个节点(a) 删除一个节点(b) 倒置链表(c) 退出(d)?\n");
		gets(c);
		switch(c[0])
		{
			case 'a':
			{
				printf("请输入插入节点的数值:\n");
				temp=(struct student *)malloc(sizeof(struct student));
				scanf("%d",&temp->num);
				if(flag)for(q=p=head;p!=NULL&&p->num<temp->num;)
				{
					q=p;
					p=p->next;
				}
				else for(q=p=head;p!=NULL&&p->num>temp->num;)
					p=p->next;
				temp->next=p->next;
				p->next=temp;
				prf(head);
				getchar();
				break;
			}
			case 'b':
			{
				printf("请输入删除节点的数值:\n");
				scanf("%d",&num);
				if(head->num==num)head=head->next;
				for(;p!=NULL&&p->num!=num;)
				{
					q=p;
					p=p->next;
				}
				if(p==NULL)
				{
					printf("没有找到!");
					getchar();
					break;
				}
				q->next=p->next;
				prf(head);
				getchar();
				break;
			}
			case 'c':head=dao(head);prf(head);break;
			case 'd':return 0;
	}
	}
	if(c[0]!='c')printf("链表节点已全部删除!");
	getchar();
	return 0;
}
