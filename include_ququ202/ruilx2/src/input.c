#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "getch.h"
#include "checkdate.h"
#define CLEARLINE printf("\e8")

void inputnumstr(char *a, int len){
        int i=0; char b;
getchnumstr:
        while((b=getch())!=13){
                if(b==3){       /* KILL THE PROGRAM */
                        exit(0);
                }
                if(b!=127){
                        if(i > len){
                                goto getchnumstr;
                        }
			if(b >= '0' && b <= '9'){
                        	putchar(b);
                        	a[i]=b;
                        	i++;
			}
                }else{
                        if(i>0){
                                i--;
                                putchar('\b');
                                putchar(' ');
                                putchar('\b');
                        }
                }
        }
        if(i == 0){
                goto getchnumstr;
        }
        a[i]='\0';
        putchar('\n');
}

void inputstr(char *a, int len){
        int i=0; char b;
getchstr:
        while((b=getch())!=13){
                if(b==3){       /* KILL THE PROGRAM */
                        exit(0);
                }
                if(b!=127){
                        if(i > len){
                                goto getchstr;
                        }
                                putchar(b);
                                a[i]=b;
                                i++;
                }else{
                        if(i>0){
                                i--;
                                putchar('\b');
                                putchar(' ');
                                putchar('\b');
                        }
                }
        }
        if(i == 0){
                goto getchstr;
        }
        a[i]='\0';
        putchar('\n');
}

void inputdate(int *y, int *m, int *d){
        int c=1; char b;
        (*y)=2000; (*m)=1; (*d)=1;
        puts("\nUse 'W', 'S' to change, 'A', 'D' to select, 'Enter' accept");
        printf("\e7");
        printf("Date: \e[31m> %04d <\e[39m %02d %02d",*y,*m,*d);
choosedate:
        fflush(stdin);
        while((b=getch())!=13){
                if(b==3){
                        exit(0);
                }
                switch(c){
                        case 1:
                                //CLEARLINE;
                                //printf("Date: \e[31m> %04d <\e[39m %02d %02d",*y,*m,*d);
                                switch(b){
                                        case 115:               /* press S */
                                                if(*y>1970){
                                                        (*y)--;
                                                        CLEARLINE;
                                                        printf("Date: \e[31m> %04d <\e[39m %02d %02d",*y,*m,*d);
                                                }
                                                break;
                                        case 119:               /* press W */
                                                if(*y<2100){
                                                        (*y)++;
                                                        CLEARLINE;
                                                        printf("Date: \e[31m> %04d <\e[39m %02d %02d",*y,*m,*d);
                                                }
                                                break;
                                        case 97:                /* press A */
                                                c=3;
                                                CLEARLINE;
                                                printf("Date: %04d %02d \e[31m> %02d <\e[39m",*y,*m,*d);
                                                break;
                                        case 100:
                                                c=2;
                                                CLEARLINE;
                                                printf("Date: %04d \e[31m> %02d <\e[39m %02d",*y,*m,*d);
                                                break;
                                        default: goto choosedate;
                                }
                                //CLEARLINE;
                                //printf("Date: \e[31m> %04d <\e[39m %02d %02d",*y,*m,*d);
                                break;
                        case 2:
                                //CLEARLINE;
                                //printf("Date: %04d \e[31m> %02d <\e[39m %02d",*y,*m,*d);
                                switch(b){
                                        case 115:               /* press S */
                                                if(*m>1){
                                                        (*m)--;
                                                        switch(*m){
                                                                case 4: case 6: case 9: case 11:
                                                                        if(*d>30){
                                                                                *d=30;
                                                                        }
                                                                        break;
                                                                case 2:
                                                                        if(*d>Dayinmonth(2,*y)){
                                                                                *d=Dayinmonth(2,*y);
                                                                        }
                                                                        break;
                                                        }
                                                }
                                                CLEARLINE;
                                                printf("Date: %04d \e[31m> %02d <\e[39m %02d",*y,*m,*d);
                                                break;
                                        case 119:               /* press W */
                                                if(*m<12){
                                                        (*m)++;
                                                        switch(*m){
                                                                case 4: case 6: case 9: case 11:
                                                                        if(*d>30){
                                                                                *d=30;
                                                                        }
                                                                        break;
                                                                case 2:
                                                                        if(*d>Dayinmonth(2,*y)){
                                                                                *d=Dayinmonth(2,*y);
                                                                        }
                                                                        break;
                                                        }
                                                }
                                                CLEARLINE;
                                                printf("Date: %04d \e[31m> %02d <\e[39m %02d",*y,*m,*d);
                                                break;
                                        case 97:                /* press A */
                                                c=1;
                                                CLEARLINE;
                                                printf("Date: \e[31m> %04d <\e[39m %02d %02d",*y,*m,*d);
                                                break;
                                        case 100:
                                                c=3;
                                                CLEARLINE;
                                                printf("Date: %04d %02d \e[31m> %02d <\e[39m",*y,*m,*d);
                                                break;
                                        default: goto choosedate;
                                }
                                //CLEARLINE;
                                //printf("Date: %04d \e[31m> %02d <\e[39m %02d",*y,*m,*d);
                                break;
                        case 3:
                                //CLEARLINE;
                                //printf("Date: %04d %02d \e[31m> %02d <\e[39m",*y,*m,*d);
                                switch(b){
                                        case 115:               /* press S */
                                                if(*d>1){
                                                        (*d)--;
                                                        CLEARLINE;
                                                        printf("Date: %04d %02d \e[31m> %02d <\e[39m",*y,*m,*d);
                                                }
                                                break;
                                        case 119:               /* press W */
                                                if(*d<Dayinmonth(*m,*y)){
                                                        (*d)++;
                                                        CLEARLINE;
                                                        printf("Date: %04d %02d \e[31m> %02d <\e[39m",*y,*m,*d);
                                                }
                                                break;
                                        case 97:                /* press A */
                                                c=2;
                                                CLEARLINE;
                                                printf("Date: %04d \e[31m> %02d <\e[39m %02d",*y,*m,*d);
                                                break;
                                        case 100:
                                                c=1;
                                                CLEARLINE;
                                                printf("Date: \e[31m> %04d <\e[39m %02d %02d",*y,*m,*d);
                                                break;
                                        default: goto choosedate;
                                }
                                //CLEARLINE;
                                //printf("Date: %04d %02d \e[31m> %02d <\e[39m",*y,*m,*d);
                                break;
                        default:
                                c=1;break;
                }
        }
        putchar('\n');
}

