//#define WIN32_LEAN_AND_MEAN
#define HEIGHT 20
#define WIDE 76
#define ICO "*"

int flage;
int time_interval;

struct node
{
    int x;
    int y;
    struct node* next;
};

void getpos(HANDLE hOut,COORD *pos)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo( hOut , &info );
    *pos = info.dwCursorPosition;
}
void gotopos(HANDLE hOut,COORD pos)
{
    SetConsoleCursorPosition(hOut, pos);
}

void put_logo()
{
    int i;
    for(i=0; i<8; i++)
    {
        printf("\n");
    }
    for(i=0; i<35; i++)
    {
        printf(" ");
    }
    printf("snake");
    Sleep(2000);
    system("cls");
}

void start_map()
{
    int i;
    int j;
    for(i=0; i<HEIGHT+3; i++)
    {
        for(j=0; j<WIDE+3; j++)
        {
            if(i==0||i==HEIGHT+2)
            {
                printf("=");
            }
            else if(j==0||j==WIDE+2)
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

struct node* clear_last(HANDLE hOut,COORD pos,struct node* p,int x,int y)
{
    pos.X = p->x;
    pos.Y = p->y;
    gotopos(hOut,pos);
    printf(" ");
    p->x=x;
    p->y=y;
    return p->next;
}

int check_ways(struct node* q,int x,int y,int len)
{
    int i;
    if(x<1||x>WIDE+1)
    {
        return 1;
    }
    if(y<1||y>HEIGHT+1)
    {
        return 1;
    }
    for(i=0; i<len; i++)
    {
        if(q->x==x&&q->y==y)
        {
            return 1;
        }
        q=q->next;
    }
    return 0;
}

DWORD WINAPI  snake()
{
    struct node snakes;
    struct node* head;
    struct node* p;
    struct node* q;
    HANDLE hOut;
    COORD pos;
    int i;
    int len;
    len=10;
    snakes.x=1;
    snakes.y=1;
    snakes.next=NULL;
    pos.X=snakes.x;
    pos.Y=snakes.y;
    start_map();
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    gotopos(hOut,pos);
    head=p=q=malloc(sizeof(struct node));
    p->x=snakes.x++;
    p->y=snakes.y;
    printf(ICO);
    p->next=q;
    for(i=0; i<len-1; i++)
    {
        q=p;
        p=malloc(sizeof(struct node));
        p->x=snakes.x++;
        p->y=snakes.y;
        printf(ICO);
        p->next=head;
        q->next=p;
    }
    printf(ICO);
    snakes.x=snakes.x-1;
    p=head;
    for(;; Sleep(time_interval*50))
    {
        switch(flage)
        {
        case 1:
            snakes.y--;
            break;
        case 2:
            snakes.y++;
            break;
        case 3:
            snakes.x--;
            break;
        case 4:
            snakes.x++;
            break;
        default :
            goto _NEXT;
            break;
        }
        if(check_ways(head,snakes.x,snakes.y,len))
        {
            goto _END;
        }
        p=clear_last(hOut,pos,p,snakes.x,snakes.y);
        pos.X=snakes.x;
        pos.Y=snakes.y;
        gotopos(hOut,pos);
        printf(ICO);
        printf("\b");
_NEXT:
        ;
    }
_END:
    ;
    pos.X=25;
    pos.Y=10;
    gotopos(hOut,pos);
    printf("game over!you have %d long snakes\b",len);
}
