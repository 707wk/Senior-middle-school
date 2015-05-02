/*
学校	班次	姓名	考号
语文	数学	英语	物理	化学	生物
政治	历史	地理 总分 县名 校名 班名
成绩排序
*/

typedef struct student_data
{
    char school[10];
    short int class_num ;
    char name[12];
    int exam_num ;
    char score[9];
    short int score_sum ;
    short int position[3];
    struct student_data* next ;
}
data ;

typedef struct school_data
{
    char name[10];
    float average ;
    int num_sum_students ;
    struct school_data* next ;
}
sch_data ;

typedef struct class_data
{
    char school[10];
    int class_num;
    int sum_stu;
    float average[10];
    struct class_data* next;
}
cla_data;

//检验数据格式
int check_data(data* temp)
{
    int i ;
    if(temp->school[0]==' ')
    {
        return 1 ;
    }
    if(strcmp(temp->name,"")==0)
    {
        return 1 ;
    }
    for(i=0; i<9; i++)
    {
        if(temp->score[i]<0||temp->score[i]>120)
        {
            return 1 ;
        }
    }
    return 0 ;
}

//校总分
int check_in_data(sch_data* sch,data* p)
{
    while(sch!=NULL)
    {
        if(strcmp(sch->name,p->school)==0)
        {
            sch->average=sch->average+p->score_sum ;
            sch->num_sum_students++;
            return 0 ;
        }
        sch=sch->next ;
    }
    return 1 ;
}

//计算校平均分
void average_school(sch_data* head)
{
    while(head!=NULL)
    {
        head->average=head->average*1.0/head->num_sum_students ;
        head=head->next ;
    }
}

//输出错误数据
int put_data_error(data* head,int num_student_sum)
{
    printf("错误数据:\n第%4d行:",num_student_sum);
    printf("%8s %4d %8s %7d %3d %3d %3d %3d %3d %3d %3d %3d %3d\n",
           head->school,
           head->class_num,
           head->name,
           head->exam_num,
           head->score[0],head->score[1],head->score[2],head->score[3],head->score[4],head->score[5],head->score[6],head->score[7],head->score[8]);
}

//输出数据
int put_data(data* head)
{
    FILE* fpout ;
    if((fpout=fopen("data_after.txt","w"))==NULL)
    {
        return 1 ;
    }
    while(head!=NULL)
    {
        fprintf(fpout,"%8s %4d %8s %7d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d\n",
                head->school,
                head->class_num,
                head->name,
                head->exam_num,
                head->score[0],head->score[1],head->score[2],head->score[3],head->score[4],head->score[5],head->score[6],head->score[7],head->score[8],
                head->score_sum,
                head->position[0],
                head->position[1],
                head->position[2]);
        head=head->next ;
    }
    fclose(fpout);
}

//输出校平均成绩
void put_data_average(sch_data* head)
{
    printf("学校\t\t校平均成绩\n");
    while(head!=NULL)
    {
        printf("%s\t%4.1f\n",head->name,head->average);
        head=head->next ;
    }
}

//输出班平均成绩
void put_clas_average(cla_data* head)
{
	while(head!=NULL)
	{
		printf("%s %d:%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%4.1f\n",head->school,head->class_num,head->[0])
	}
}

//释放内存
int free_data(data* head)
{
    data* temp ;
    while(head!=NULL)
    {
        temp=head->next ;
        free(head);
        head=temp ;
    }
}

//交换内容
void data_exchange(data* link_one,data* link_two)
{
    data data_temp=* link_one ;
    data* link_temp_one=link_one->next ;
    data* link_temp_two=link_two->next ;
    *link_one=*link_two ;
    *link_two=data_temp ;
    link_one->next=link_temp_one ;
    link_two->next=link_temp_two ;
}

//总排名
int data_county_ranking(data* head)
{
    data* p ;
    data* q ;
    printf("统计排名\n");
    p=head ;
    for(; p!=NULL;)
    {
        for(q=head; q!=NULL;)
        {
            if(q->score_sum>p->score_sum)
            {
                p->position[0]++;
                if(strcmp(p->school,q->school)==0)
                {
                    p->position[1]++;
                    if(p->class_num==q->class_num)
                    {
                        p->position[2]++;
                    }
                }
            }
            q=q->next ;
        }
        p=p->next ;
    }
}

//按校排序
int data_school_ranking(data* head)
{
    data* p ;
    data* q ;
    p=head ;
    printf("按校排序\n");
    for(; p!=NULL;)
    {
        for(q=p->next; q!=NULL;)
        {
            if(strcmp(p->school,q->school)==0)
            {
                data_exchange(p->next,q);
                break ;
            }
            q=q->next ;
        }
        p=p->next ;
    }
    p=head ;
    for(; p!=NULL;)
    {
        for(q=p; q!=NULL;)
        {
            if(strcmp(p->school,q->school)==0)
            {
                if(q->score_sum>p->score_sum)
                {
                    data_exchange(p,q);
                }
            }
            else
            {
                break ;
            }
            q=q->next ;
        }
        p=p->next ;
    }
}

//按班排序
int data_class_ranking(data* head)
{
    data* p ;
    data* q ;
    p=head ;
    printf("按班排序\n");
    for(; p!=NULL;)
    {
        for(q=p; q!=NULL;)
        {
            if(strcmp(p->school,q->school)==0)
            {
                if(q->class_num<p->class_num)
                {
                    data_exchange(p,q);
                }
            }
            else
            {
                break ;
            }
            q=q->next ;
        }
        p=p->next ;
    }
    p=head ;
    for(; p!=NULL;)
    {
        for(q=p; q!=NULL&&strcmp(p->school,q->school)==0&&q->class_num==p->class_num;)
        {

            if(q->score_sum>p->score_sum)
            {
                data_exchange(p,q);
            }
            q=q->next ;
        }
        p=p->next ;
    }
}

//读取数据
int data_read()
{
    FILE* fpin ;
    FILE* fpout ;
    data* head ;
    data* p ;
    data* q ;
    sch_data* sch ;
    sch_data* sch_p ;
    sch_data* sch_q ;
    int i ;
    int num_student=1 ;
    int flag_error=0 ;
    printf("载入数据\n");
    if((fpin=fopen("data\\data_ranking.txt","r"))==NULL)
    {
        return 1 ;
    }
    head=p=(data*)malloc(sizeof(data));
    sch=sch_p=(sch_data*)malloc(sizeof(sch_data));
    sch->num_sum_students=1 ;
    fscanf(fpin,"%s\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
           p->school,
           &p->class_num,
           p->name,
           &p->exam_num,
           &p->score[0],&p->score[1],&p->score[2],&p->score[3],&p->score[4],&p->score[5],&p->score[6],&p->score[7],&p->score[8]);
    if(check_data(p))
    {
        flag_error++;
        put_data_error(p,num_student);
    }
    for(i=0; i<9; i++)
    {
        p->score_sum=p->score_sum+p->score[i];
    }
    for(i=0; i<3; i++)
    {
        p->position[i]=1 ;
    }
    strcpy(sch->name,p->school);
    sch->average=p->score_sum ;
    sch->next=NULL ;
    for(; !feof(fpin);)
    {
        if(!flag_error)q=p ;
        p=(data*)malloc(sizeof(data));
        fscanf(fpin,"%s\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p->school,
               &p->class_num,
               p->name,
               &p->exam_num,
               &p->score[0],&p->score[1],&p->score[2],&p->score[3],&p->score[4],&p->score[5],&p->score[6],&p->score[7],&p->score[8]);
        num_student++;
        if(check_data(p))
        {
            flag_error++;
            put_data_error(p,num_student);
        }
        else
        {
            for(i=0; i<9; i++)
            {
                p->score_sum=p->score_sum+p->score[i];
            }
            for(i=0; i<3; i++)
            {
                p->position[i]=1 ;
            }
            if(check_in_data(sch,p))
            {
                sch_q=sch_p ;
                sch_p=(sch_data*)malloc(sizeof(sch_data));
                strcpy(sch_p->name,p->school);
                sch_p->average=p->score_sum ;
                sch_p->num_sum_students=1 ;
                sch_q->next=sch_p ;
                sch_p->next=NULL ;
            }
            q->next=p ;
        }
    }
    p->next=NULL ;
    printf("载入完成\n");
    data_county_ranking(head);
    data_school_ranking(head);
    data_class_ranking(head);
    put_data(head);
    printf("共%4d条学生数据\n有%4d条数据出错\n",num_student,flag_error);
    //4357
    average_school(sch);
    put_data_average(sch);
    free_data(head);
    if(flag_error)
    {
        return 1 ;
    }
    else
    {
        return 0 ;
    }
}
