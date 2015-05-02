/***********WobbleWnd.c*****************/

#include <windows.h>

#define	DLG_MAIN 1
#define ICO_MAIN 0X1000


LRESULT CALLBACK DialogProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	HICON	  hIcon;
	HWND	  hDestWnd;

	RECT	  rc;
	int		  i=0;
	
	switch(uMsg)
	{
	case WM_INITDIALOG:
		hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(ICO_MAIN));
		SendMessage(hWnd,WM_SETICON,ICON_BIG,(long)hIcon);
		SetTimer(hWnd,0,10,NULL);
		return TRUE;
	case WM_TIMER:
		
		i=(rand()-rand())/1000;
		
		if((hDestWnd=GetForegroundWindow())!=NULL){
		GetWindowRect(hDestWnd,&rc);
		if(rc.top<0||rc.bottom>800)
			rc.top=100;
		if(rc.left<0||rc.right>1000)
			rc.left=100;
		
		MoveWindow(hDestWnd,rc.left+i,rc.top+i,rc.right-rc.left,rc.bottom-rc.top,TRUE);
		}
		//SendWindowMessage(
		return TRUE;
	case WM_CLOSE:
		KillTimer(hWnd,0);//取消定时器
		EndDialog(hWnd,0);
		return TRUE;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPreInstance,
				   LPSTR	 lpCmdline,
				   int		 nShowCmd)
{
	DialogBoxParam(hInstance,MAKEINTRESOURCE(DLG_MAIN),0,DialogProc,0);
	srand((unsigned)time(NULL));
	return 1;
}
