#include <iostream>
#include<windows.h>
#include"windows.h"

   
   windows app;

  
int main()
{

  HWND hwnd;
HINSTANCE hInstance;
 HINSTANCE hPrevInstance;
  LPSTR lpCmdLine;
   int nCmdShow;
 
 if( app.init(hInstance,nCmdShow,"V-Engine","V-Engine",0,0,450,320,hwnd))
{
	while(app.isrun())
	{
		app.broadcast();
	}
}

 	 return 0;
 }
 
 




