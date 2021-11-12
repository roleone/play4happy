#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <iostream>
#include <afxres.h>
#include <time.h>
#include <cstring>
#include <fstream>
using namespace std;
time_t start,end;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 
#define IDC_BUTTON1 106
#define MAX_LOADSTRING 100
HINSTANCE hInst;
HWND hWnd2;
HWND hWnd3;
HWND hWnd4;
int nCS;
int chengji;
int yongshi;
int yonghuming[32];
char id[32];
char grades[32];
char bijiao[32];
int k;
int z=0;
int y=0;
int w=0;
int x1=0;
int x2=0;
char wenti1[32];
char wenti2[32];
char wenti3[32];
char wenti4[32];
char wenti5[32];
char wenti6[32];
char wenti7[32];
char wenti8[32];
char wenti9[32];
char wenti10[32];
char biaoda1[32];
char biaoda2[32];
char biaoda3[32];
char biaoda4[32];
char biaoda5[32];
char biaoda6[32];
char biaoda7[32];
char biaoda8[32];
char biaoda9[32];
char biaoda10[32];
char huida1[32];
char huida2[32];
char huida3[32];
char huida4[32];
char huida5[32];
char huida6[32];
char huida7[32];
char huida8[32];
char huida9[32];
char huida10[32];
TCHAR szWindowClass[MAX_LOADSTRING]=_T("huhua");
TCHAR szWindowClass2[MAX_LOADSTRING] = _T("huhua2");
TCHAR szWindowClass3[MAX_LOADSTRING] = _T("huhua3");
TCHAR szWindowClass4[MAX_LOADSTRING] = _T("huhua4");
TCHAR szTitle[MAX_LOADSTRING]=_T("sign in");
TCHAR szTitle2[MAX_LOADSTRING] = _T("calculation");
TCHAR szTitle3[MAX_LOADSTRING] = _T("result");
TCHAR szTitle4[MAX_LOADSTRING] = _T("history");
ATOM	MyRegisterClass(HINSTANCE hInstance);
ATOM	MyRegisterClass2(HINSTANCE hInstance);
ATOM	MyRegisterClass3(HINSTANCE hInstance);
ATOM	MyRegisterClass4(HINSTANCE hInstance);
BOOL	InitInstance(HINSTANCE,int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc3(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc4(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	MSG msg;
	MyRegisterClass(hInst);
	MyRegisterClass2(hInst);
	MyRegisterClass3(hInst);
	MyRegisterClass4(hInst);
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 
		DispatchMessage(&msg);  
	}
	return msg.wParam;
}
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	return RegisterClassEx(&wcex);
}
ATOM MyRegisterClass2(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc2;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//
	wcex.lpszClassName = szWindowClass2;
	return RegisterClassEx(&wcex);
}
ATOM MyRegisterClass3(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc3;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//
	wcex.lpszClassName = szWindowClass3;
	return RegisterClassEx(&wcex);
}
ATOM MyRegisterClass4(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc4;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//
	wcex.lpszClassName = szWindowClass4;
	return RegisterClassEx(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance,int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance;
	nCS=nCmdShow;
	hWnd = CreateWindow(szWindowClass, szTitle, 
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, 
		hInstance, NULL);
	hWnd2= CreateWindow(szWindowClass2, szTitle2,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL,
		hInstance, NULL);
	hWnd3= CreateWindow(szWindowClass3, szTitle3,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL,
		hInstance, NULL);
	hWnd4= CreateWindow(szWindowClass4, szTitle4,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL,
		hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	UpdateWindow(hWnd2);
	UpdateWindow(hWnd3);
	UpdateWindow(hWnd4);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND q1, q2, q3, q4, q5;
	static TCHAR name[100];
	switch (message)
	{
	case WM_CREATE:
		q1 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			400,
			200,
			100,
			20,
			hWnd,
			NULL,
			NULL,
			NULL);
		q2 = CreateWindow(TEXT("BUTTON"),
			TEXT("Star a test"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			250,
			300,
			100,
			30,
			hWnd,
			NULL,
			NULL,
			NULL);
		q3 = CreateWindow(TEXT("BUTTON"),
			TEXT("Check Scores"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			400,
			300,
			100,
			30,
			hWnd,
			NULL,
			NULL,
			NULL);
		q4 = CreateWindow(TEXT("BUTTON"),
			TEXT("Exit"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			550,
			300,
			100,
			30,
			hWnd,
			NULL,
			NULL,
			NULL);
		q5 = CreateWindow(TEXT("STATIC"),
			TEXT("Please input your ID no："),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			200,
			188,
			200,
			40,
			hWnd,
			NULL,
			NULL,
			NULL);

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
	    if ((HWND)lParam == q2)
		{
			GetWindowText(q1, name, 7);
			k=0;
			z=0;
			char*p=name;
			for(int i=0;i<6;i++,p++)
   	        {
               if(i<2)
               {
               	if(*p>='A'&&*p<='Z') 
			    {
   				  k=k+1;
   				  yonghuming[i]=(int)*p;
   			    }
			    else
			    {
   				  MessageBox(hWnd, TEXT("ERROR"), TEXT("Tips"), 0);
   			      break;
	    	    }
               }
               else
			   {
   				if(*p>='0'&&*p<='9')
			    {
   				    k=k+1;
   				    yonghuming[i]=(int)*p;
	     	    }
	     	    else
			    {   
   	     	    	MessageBox(hWnd, TEXT("ERROR"), TEXT("Tips"), 0);
   	     	    	break;
   	     	    }
	    	   } 
      	    }
      	    if(k==6) 
      	    {
   	    	   chengji=100;
               ShowWindow(hWnd2,nCS);
  	        }
		}
		if ((HWND)lParam == q3)
		{
			GetWindowText(q1, name, 7);
			k=0;
			z=0;
			char*p=name;
			for(int i=0;i<6;i++,p++)
   	        {
               if(i<2)
               {
               	if(*p>='A'&&*p<='Z') 
			    {
   				  k=k+1;
   				  yonghuming[i]=(int)*p;
   			    }
			    else
			    {
   				  MessageBox(hWnd, TEXT("ERROR"), TEXT("Tips"), 0);
   			      break;
	    	    }
               }
               else
			   {
   				if(*p>='0'&&*p<='9')
			    {
   				    k=k+1;
   				    yonghuming[i]=(int)*p;
	     	    }
	     	    else
			    {   
   	     	    	MessageBox(hWnd, TEXT("ERROR"), TEXT("Tips"), 0);
   	     	    	break;
   	     	    }
	    	   } 
      	    }
      	    if(k==6) 
      	    {
  	    	   for(int i=0;i<32;i++)
  	    	   {
   	    	  	bijiao[i]=char(yonghuming[i]);
   	    	  }
               ShowWindow(hWnd4,nCS);
  	        }
		}
		if ((HWND)lParam == q4)
		{
			DestroyWindow(hWnd);
		}
		return 0;
	}
 
	return DefWindowProc(hWnd, message, wParam, lParam);

}
LRESULT CALLBACK WndProc2(HWND hWnd2, UINT message, WPARAM wParam, LPARAM lParam)
{
	srand(time(NULL));
    static HWND q1, q2, q3;
	static TCHAR answer[2];
	char temp[32];
	char atb[32]; 
	char kaishi[32];
	int daan;

	sprintf(kaishi,"START");
	while(w==y)
	{
		y=rand()%4;
	}
    if(y==0)
    {
   	  while(0>=x1+x2||x1+x2>=100)
   	  {
   	    x1=rand()%99+1;
	    x2=rand()%99+1;
      }
	  sprintf(temp,"%d+%d=",x1,x2);
	  daan=x1+x2;
    }
    if(y==1)
    {
      while(0>=x1-x2)
      {
   	    x1=rand()%99+1;
	    x2=rand()%99+1;
      }
	  sprintf(temp,"%d-%d=",x1,x2);
	  daan=x1-x2;
    }
    if(y==2)
    {
   	  while(0==x1*x2||x1*x2>=100)
   	  {
   	    x1=rand()%99+1;
	    x2=rand()%99+1;
      }
	  sprintf(temp,"%d*%d=",x1,x2);
	  daan=x1*x2;
    }
    if(y==3)
    {
   	  while(x1==0||x2==0||x1%x2!=0)
   	  {
   	    x1=rand()%99+1;
	    x2=rand()%99+1;
      }
	  sprintf(temp,"%d/%d=",x1,x2);
	  daan=x1/x2;
    }
    if(z==0)
    {
      for(int i=0;i<6;i++)
      {
      	wenti1[i]=temp[i];	
      }
      sprintf(biaoda1,"%d",daan);

      sprintf(atb,"NEXT");
    }
    if(z==1)
    {
      for(int i=0;i<6;i++)
      {
      	wenti2[i]=temp[i];
      }
      sprintf(biaoda2,"%d",daan);
  
   	  sprintf(atb,"NEXT");
    }
    if(z==2)
    {
      for(int i=0;i<6;i++)
      {
      	wenti3[i]=temp[i];
      }
      sprintf(biaoda3,"%d",daan);

      sprintf(atb,"NEXT");
    }
    if(z==3)
    {
      for(int i=0;i<6;i++)
      {
      	wenti4[i]=temp[i];    	
      }
      sprintf(biaoda4,"%d",daan);

      sprintf(atb,"NEXT");
    }
    if(z==4)
    {
      for(int i=0;i<6;i++)
      {
      	wenti5[i]=temp[i];    	
      }
      sprintf(biaoda5,"%d",daan);

      sprintf(atb,"NEXT");
    }
    if(z==5)
    {
      for(int i=0;i<6;i++)
      {
      	wenti6[i]=temp[i]; 	
      }
      sprintf(biaoda6,"%d",daan);
 
      sprintf(atb,"NEXT");
    }
    if(z==6)
    {
      for(int i=0;i<6;i++)
      {
      	wenti7[i]=temp[i];	
      }
      sprintf(biaoda7,"%d",daan);

      sprintf(atb,"NEXT");
    }
    if(z==7)
    {
      for(int i=0;i<6;i++)
      {
      	wenti8[i]=temp[i];     	
      }
      sprintf(biaoda8,"%d",daan);

      sprintf(atb,"NEXT");
    }
    if(z==8)
    {
      for(int i=0;i<6;i++)
      {
      	wenti9[i]=temp[i];      	
      }
      sprintf(biaoda9,"%d",daan);

      sprintf(atb,"NEXT");
    }
    if(z==9)
    {
      for(int i=0;i<6;i++)
      {
      	wenti10[i]=temp[i];     	
      }
      sprintf(biaoda10,"%d",daan);

      sprintf(atb,"END");
    }
	switch (message)
   {
		case WM_CREATE:
		q1 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			400,
			200,
			100,
			20,
			hWnd2,
			NULL,
			NULL,
			NULL);
        q2 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			330,
			200,
			60,
			20,
			hWnd2,
			NULL,
			NULL,
			NULL);
		q3 = CreateWindow(TEXT("BUTTON"),
			TEXT("START"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			400,
			300,
			100,
			30,
			hWnd2,
			NULL,
			NULL,
			NULL);
		return 0;
		case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
    	case WM_COMMAND:
         if ((HWND)lParam == q3)
		{
	        z=z+1;
	        if(z>0&&z<11)
	        {
        	  if(z==1)
        	  {
  	        	start=time(NULL);
  	          }
	          GetWindowText(q1, answer, 3);
  			  if(z==2)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida1[i]=answer[i]; 	
			    }
  			  }
  			  if(z==3)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida2[i]=answer[i]; 	
			    }
  			  }
  			  if(z==4)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida3[i]=answer[i]; 	
			    }
  			  }
  			  if(z==5)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida4[i]=answer[i]; 	
			    }	
  			  }
  			  if(z==6)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida5[i]=answer[i]; 	
			    }		
  			  }
  			  if(z==7)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida6[i]=answer[i]; 	
			    }	
  			  }
  			  if(z==8)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida7[i]=answer[i]; 	
			    }	
  			  }
  			  if(z==9)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida8[i]=answer[i]; 	
			    }	
  			  }
  			  if(z==10)
			  {
  				for(int i=0;i<3;i++)
  				{
				  huida9[i]=answer[i]; 	
			    }	
  			  }
			  SetWindowText(q2,temp);
			  SetWindowText(q3,atb);
			  SetWindowText(q1,NULL);
			  w=y;
			  x1=rand()%99+1;
              x2=rand()%99+1;
        	}
        	if(z>10)
        	{
        		end=time(NULL);
        		GetWindowText(q1, answer, 3);
        		for(int i=0;i<3;i++)
  				{
				  huida10[i]=answer[i]; 	
			    }
	            if(*biaoda1!=*huida1)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda2!=*huida2)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda3!=*huida3)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda4!=*huida4)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda5!=*huida5)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda6!=*huida6)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda7!=*huida7)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda8!=*huida8)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda9!=*huida9)
	            {
            		chengji=chengji-10;
            	}
            	if(*biaoda10!=*huida10)
	            {
            		chengji=chengji-10;
            	}
        		SetWindowText(q1,NULL);
        		SetWindowText(q2,NULL);
        		SetWindowText(q3,kaishi);
        		sprintf(grades,"%d",chengji);
        		yongshi=end-start;
        		MessageBox(hWnd2,grades,TEXT("your grades"),0);
        		HWND hWnd= GetForegroundWindow(); 
	        	ShowWindow(hWnd, SW_HIDE);
	        	ShowWindow(hWnd3,nCS);
	        }
		}
		return 0;
        default:
		return DefWindowProc(hWnd2, message, wParam, lParam);
		break;
    }
	return 0;
}
LRESULT CALLBACK WndProc3(HWND hWnd3, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,q13,q14,q15,q16,q17,q18,q19,q20,q21,q22,q23,q24,q25,q26,q27,q28,q29,q30,q31,q32,q33,q34,q35; 
	switch (message)
    {
    	case WM_CREATE:
    	q1 = CreateWindow(TEXT("BUTTON"),
			TEXT("CONFIRM"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			300,
			400,
			100,
			30,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q2 = CreateWindow(TEXT("BUTTON"),
			TEXT("View results"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			100,
			400,
			100,
			30,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q3 = CreateWindow(TEXT("STATIC"),
			TEXT("QUESTION："),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			20,
			60,
			100,
			30,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q4 = CreateWindow(TEXT("STATIC"),
			TEXT("ANSWER："),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			200,
			50,
			100,
			40,
			hWnd3,
			NULL,
			NULL,
			NULL);
        q5 = CreateWindow(TEXT("STATIC"),
			TEXT("your result："),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			350,
			50,
			100,
			40,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q6 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			100,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q7 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			100,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q8 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			100,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q9 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			125,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q10 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			125,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q11 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			125,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q12 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			150,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q13 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			150,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q14 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			150,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q15 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			175,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q16 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			175,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q17 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			175,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q18 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			200,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q19 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			200,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q20 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			200,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q21 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			225,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q22 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			225,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q23 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			225,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q24 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			250,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q25 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			250,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q26 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			250,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q27 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			275,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q28 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			275,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q29 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			275,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q30 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			300,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q31 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			300,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q32 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			300,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q33 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			30,
			325,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q34 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			200,
			325,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
	    q35 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			350,
			325,
			100,
			25,
			hWnd3,
			NULL,
			NULL,
			NULL);
		return 0;
		case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		case WM_COMMAND:
		 if ((HWND)lParam == q2)
		 {
		 	SetWindowText(q8,huida1);
		 	SetWindowText(q11,huida2);
		 	SetWindowText(q14,huida3);
		 	SetWindowText(q17,huida4);
		 	SetWindowText(q20,huida5);
		 	SetWindowText(q23,huida6);
		 	SetWindowText(q26,huida7);
		 	SetWindowText(q29,huida8);
		 	SetWindowText(q32,huida9);
		 	SetWindowText(q35,huida10);
            SetWindowText(q7,biaoda1);
            SetWindowText(q10,biaoda2);
            SetWindowText(q13,biaoda3);
            SetWindowText(q16,biaoda4);
            SetWindowText(q19,biaoda5);
            SetWindowText(q22,biaoda6);
            SetWindowText(q25,biaoda7);
            SetWindowText(q28,biaoda8);
            SetWindowText(q31,biaoda9);
            SetWindowText(q34,biaoda10);
            SetWindowText(q6,wenti1);
            SetWindowText(q9,wenti2);
            SetWindowText(q12,wenti3);
            SetWindowText(q15,wenti4);
            SetWindowText(q18,wenti5);
            SetWindowText(q21,wenti6);
            SetWindowText(q24,wenti7);
            SetWindowText(q27,wenti8);
            SetWindowText(q30,wenti9);
            SetWindowText(q33,wenti10);
 		 } 
         if ((HWND)lParam == q1)
 	      {
 	      	SetWindowText(q6,NULL);
 	      	SetWindowText(q7,NULL);
 	      	SetWindowText(q8,NULL);
 	      	SetWindowText(q9,NULL);
 	      	SetWindowText(q10,NULL);
 	      	SetWindowText(q11,NULL);
 	      	SetWindowText(q12,NULL);
 	      	SetWindowText(q13,NULL);
 	      	SetWindowText(q14,NULL);
 	      	SetWindowText(q15,NULL);
 	      	SetWindowText(q16,NULL);
 	      	SetWindowText(q17,NULL);
 	      	SetWindowText(q18,NULL);
 	      	SetWindowText(q19,NULL);
 	      	SetWindowText(q20,NULL);
 	      	SetWindowText(q21,NULL);
 	      	SetWindowText(q22,NULL);
	        SetWindowText(q23,NULL);
	        SetWindowText(q24,NULL);
	        SetWindowText(q25,NULL);
	        SetWindowText(q26,NULL);
	        SetWindowText(q27,NULL);
	        SetWindowText(q28,NULL);
	        SetWindowText(q29,NULL);
	        SetWindowText(q30,NULL);
	        SetWindowText(q31,NULL);
	        SetWindowText(q32,NULL);
	        SetWindowText(q33,NULL);
	        SetWindowText(q34,NULL);
	        SetWindowText(q35,NULL);
	        for(int i=0;i<32;i++)
	        {
        		id[i]=char(yonghuming[i]);
        	}			
            ofstream outfile("record.txt",ios::app);
            outfile<<id<<","<<chengji<<","<<yongshi<<endl;
            outfile.close();
 	      	HWND hWnd= GetForegroundWindow(); 
        	ShowWindow(hWnd, SW_HIDE);
		  } 
         return 0;
        default:
		return DefWindowProc(hWnd3, message, wParam, lParam);
		break;
  	} 
  	return 0; 
} 
LRESULT CALLBACK WndProc4(HWND hWnd4, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND q1,q2,q3,q4,q5,q6;
	switch (message)
	{
		case WM_CREATE:
    	q1 = CreateWindow(TEXT("BUTTON"),
			TEXT("CONFIRM"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			370,
			220,
			100,
			30,
			hWnd4,
			NULL,
			NULL,
			NULL);
		q2 = CreateWindow(TEXT("STATIC"),
			TEXT("Your previous records are:"),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			250,
			80,
			200,
			30,
			hWnd4,
			NULL,
			NULL,
			NULL);
		q3 = CreateWindow(TEXT("BUTTON"),
			TEXT("CHECK"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			230,
			220,
			100,
			30,
			hWnd4,
			NULL,
			NULL,
			NULL);
		q4 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			280,
			120,
			150,
			25,
			hWnd4,
			NULL,
			NULL,
			NULL);
		q5 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			280,
			150,
			150,
			25,
			hWnd4,
			NULL,
			NULL,
			NULL);
		q6 = CreateWindow(TEXT("EDIT"),
			TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			280,
			180,
			150,
			25,
			hWnd4,
			NULL,
			NULL,
			NULL);
		return 0;
		case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		case WM_COMMAND:
		if ((HWND)lParam == q3)
		{
			ifstream fin;
            char buff[30][80]; // 假定文件bai不超du过30行，每行不超过80字符zhi
            int s=0;
            int e=0;
            int f=0;
            char bijiao1[32];
            char bijiao2[32];
            char bijiao3[32];
            fin.open ("record.txt", ifstream::in);
            while (fin.good())
			{
              fin.getline(buff[s],200); // 每次读一行存入daobuff[k]
              char*w=buff[s];
              char*m=bijiao;
              int o;
              for(int i=0;i<6;i++,m++,w++)
              {
              	if(*w==*m)
              	{
	              e=e+1;	
                }
              }
              if(e==6)
              {
              	f=f+1;
              	o=s;
              }
              if(f==1)
              {
              	char*t=buff[o];
              	for(int i=0;i<32;i++,t++)
              	{
	              	bijiao1[i]=*t;
                }
                SetWindowText(q4,bijiao1);
              }
              if(f==2)
              {
              	char*t=buff[o];
              	for(int i=0;i<32;i++,t++)
              	{
	              	bijiao2[i]=*t;
                }
                SetWindowText(q5,bijiao2);
              }
              if(f==3)
              {
              	char*t=buff[o];
              	for(int i=0;i<32;i++,t++)
              	{
	              	bijiao3[i]=*t;
                }
               SetWindowText(q6,bijiao3);
              }
              e=0;
              s=s+1;
		    } 
		}
		if ((HWND)lParam == q1)
		{
			SetWindowText(q4,NULL);
			SetWindowText(q5,NULL);
			SetWindowText(q6,NULL);
			HWND hWnd= GetForegroundWindow(); 
        	ShowWindow(hWnd, SW_HIDE);
		}
		return 0;
        default:
		return DefWindowProc(hWnd4, message, wParam, lParam);
		break;
	}
	return 0;
}
