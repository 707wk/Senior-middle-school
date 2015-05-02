//#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>
//#include "resource.h"
//#include "MainDlg.h"
#include <math.h>
#include <string.h>
#define PI 3.141593
BOOL A_Op=FALSE;
BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
    }

    return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{   
    return TRUE;
}


void TrimNumber(char a[])//�жϲ�ɾ��С��������õ���
{
	for(unsigned i=0;i<strlen(a);i++)
	{
		if(a[i]=='.')
		{
			for(unsigned j=strlen(a)-1;j>=i;j--)
			{
				if(a[j]=='0')
				{
					a[j]='\0';
				}
				else if(a[j]=='.')
				{
					a[j]='\0';
				}
				else break;
			}
		}
	}
}

double Operate(char Operator,double n1,double n2)  //�жϷ��ţ�������Ӧ������
{
	        if(Operator=='0')
			{
			}
			if(Operator=='+')
			{
				n2+=n1;
			}
			if(Operator=='-')
			{
				n2=n1-n2;
			}
			if(Operator=='*')
			{
				n2*=n1;
			}
			if(Operator=='/')
			{
				n2=n1/n2;
			}
			if(Operator=='^')
			{
				n2=pow(n1,n2);
			}
			
	return	n2;
}



////////////////////////
////////////////////////

void IntBinary(char a[],int n)
{
 if(n>1)IntBinary(a,n/2);
 sprintf(a,"%s%i",a,n%2);
}
void decimal(char a[],double m)
{
   if(m>0.000001)
   {
      m=m*2;
      sprintf(a,"%s%d",a,(long)m);
      decimal(a,m-(long)m);
   }
}
void Binary(char a[],double Num)
{
	char DecP[256]="";
	double x,y;
	double *iptr=&y;
	x=modf(Num,iptr);
	decimal(DecP,x);
	IntBinary(a,(int)y);
	strcat(a,".");
	strcat(a,DecP);
}

////////////////////////////////////
void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	static DELTIMES=0;
	static char str[256];
	static char Operator='0';
	static double RNum[3];
    switch(id)
    {
	    case IDC_BUTTONN1://����1
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"1");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN2://����2
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"2");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN3://����3
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"3");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN4://����4
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"4");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN5://����5
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"5");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN6://����6
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"6");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN7://����7
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"7");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN8://����8
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"8");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN9://����9
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"9");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONN0://����0
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			strcat(str,"0");
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			RNum[1]=atof(str);
			A_Op=FALSE;
		}
		break;
		case IDC_BUTTONDEL://С����.del
		{
			if(A_Op)
			{
				SetDlgItemText(hwnd,IDC_EDIT,NULL);
			}
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			if(DELTIMES==0)
			{
			      strcat(str,".");
			}
			DELTIMES++;
			
	        SetDlgItemText(hwnd,IDC_EDIT,str);
			A_Op=FALSE;
		}
		break;
		



		case IDC_BUTTONADD:   //�ӷ�����
		{
			RNum[1]=atof(str);
			RNum[0]=RNum[1];
			RNum[1]=RNum[2];
			RNum[2]=Operate(Operator,RNum[1],RNum[0]);
			sprintf(str,"%f",RNum[2]);
			TrimNumber(str);
			SetDlgItemText(hwnd,IDC_EDIT,str);
			Operator='+';
			DELTIMES=0;
			A_Op=TRUE;
		}
		break;
		case IDC_BUTTONSUB:   //��������
			{
			RNum[1]=atof(str);
			RNum[0]=RNum[1];
			RNum[1]=RNum[2];
			RNum[2]=Operate(Operator,RNum[1],RNum[0]);
			sprintf(str,"%f",RNum[2]);
			TrimNumber(str);
			SetDlgItemText(hwnd,IDC_EDIT,str);	
			
			DELTIMES=0;A_Op=TRUE;
			Operator='-';
			
		}
		break;
		case IDC_BUTTONMUL:   //�˷�����
		{
			RNum[1]=atof(str);
			RNum[0]=RNum[1];
			RNum[1]=RNum[2];
			RNum[2]=Operate(Operator,RNum[1],RNum[0]);
			sprintf(str,"%f",RNum[2]);
			TrimNumber(str);
			SetDlgItemText(hwnd,IDC_EDIT,str);
			Operator='*';
			DELTIMES=0;
			A_Op=TRUE;
		}
		break;
		case IDC_BUTTONDIV:   //��������
		{
			RNum[1]=atof(str);
			RNum[0]=RNum[1];
			RNum[1]=RNum[2];
			RNum[2]=Operate(Operator,RNum[1],RNum[0]);
			sprintf(str,"%f",RNum[2]);
			TrimNumber(str);
			SetDlgItemText(hwnd,IDC_EDIT,str);
			Operator='/';
			DELTIMES=0;
			A_Op=TRUE;
		}
		break;
			case IDC_BUTTONXY://x��y�η�
			{GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			RNum[1]=atof(str);
			RNum[0]=RNum[1];
			RNum[1]=RNum[2];
			RNum[2]=Operate(Operator,RNum[1],RNum[0]);
			sprintf(str,"%f",RNum[2]);
			TrimNumber(str);
			SetDlgItemText(hwnd,IDC_EDIT,str);
			Operator='^';
			DELTIMES=0;
			}
			break;



		case IDC_BUTTONPI:    //Բ����PI������
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				if(atof(str)!=0)
				{
					RNum[2]=atof(str)*PI;
					sprintf(str,"%f",RNum[2]);
					TrimNumber(str);
					SetDlgItemText(hwnd,IDC_EDIT,str);
				}
				else
				{
					sprintf(str,"%f",PI);
					SetDlgItemText(hwnd,IDC_EDIT,str);
				}
				A_Op=TRUE;
			}
			break;
		case IDC_BUTTONSQRT:  //������
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=sqrt(atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
		case IDC_BUTTONSIN:  //���Ǻ���sin����
			{	
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=sin(atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONCOS://���Ǻ���cos����
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=cos(atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONTAN://���Ǻ���tan����
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=tan(atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONSQ:  //ƽ��
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=atof(str)*atof(str);
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONCUBE://���η�
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=atof(str)*atof(str)*atof(str);
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONEX://e��x�η�
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=exp(atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTON10X://10��x�η�
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=pow(10,atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONLN:            //ln x 
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=log(atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONLOG10:          //log10 
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=log10(atof(str));
				sprintf(str,"%f",RNum[2]);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;
			case IDC_BUTTONBINARY:          //ʮ����ת��Ϊ������ 
			{
				char a[256]="";
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				RNum[2]=atof(str);
				Binary(a,RNum[2]);
				strcpy(str,a);
				TrimNumber(str);
				SetDlgItemText(hwnd,IDC_EDIT,str);
				A_Op=TRUE;
			}
			break;




			case IDC_BUTTONCLEAR://�������
		{
			DELTIMES=0;
	        Operator='0';
	        RNum[0]=RNum[1]=RNum[2]=0;
			memset(str,0,sizeof(str));
	        SetDlgItemText(hwnd,IDC_EDIT,NULL);
			A_Op=FALSE;
		}
		break;

			case IDC_BUTTONBACKSPACE://�˸��
			{
				GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
				int i=strlen(str);
				str[i-1]='\0';
				SetDlgItemText(hwnd,IDC_EDIT,str);
			}
				break;
        case IDC_ENTER://Enter��
		{
			GetDlgItemText(hwnd,IDC_EDIT,str,sizeof(str));
			RNum[1]=atof(str);
			RNum[0]=RNum[1];
			RNum[1]=RNum[2];
			RNum[2]=Operate(Operator,RNum[1],RNum[0]);
			sprintf(str,"%f",RNum[2]);
			TrimNumber(str);
			SetDlgItemText(hwnd,IDC_EDIT,str);
			Operator='0';
			DELTIMES=0;
		}
        break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}