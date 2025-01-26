#include"windows.h"

windows* w=NULL;
API *api=new API();
HWND button1;
HWND button2;
HWND button3;


LRESULT CALLBACK WindowProc1(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  {
    
	switch(message) {
		
		case WM_DESTROY: {
			w->onDestroy();
			PostQuitMessage(0);
		
			break;
		}
		
		case WM_CREATE:
		{
		
			button1=CreateWindow("button","Mode: OPENGL",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,20,20,200,200,hWnd,(HMENU) 0,GetModuleHandle(NULL),NULL);
			button2=CreateWindow("button","Mode: DIRECTX",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,220,20,200,200,hWnd,(HMENU) 1,GetModuleHandle(NULL),NULL);
		//	button3=CreateWindow("button","Mode: DIRECTX11",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,420,20,180,200,hWnd,(HMENU) 2,GetModuleHandle(NULL),NULL);
			w->onCreate();
			
			break;
		}
		case WM_COMMAND:
		{
		
			if(LOWORD(wParam)==0)
			{
				
				api->initAPIOpenGL();
			
			}
				if(LOWORD(wParam)==1)
			{
			
			api->initAPIDirectX();
		
		 }
		 	
		}
			
		default:
		return DefWindowProc (hWnd, message, wParam, lParam);
		
}

return NULL;
}


void windows::AddMenus(HWND hwnd) {

     HMENU hMenubar = CreateMenu();
    HMENU hMenu = CreateMenu();
    HMENU hSubMenu = CreatePopupMenu();
    HMENU hSubMenu1 = CreatePopupMenu();
    HMENU hSubMenu2 = CreatePopupMenu();
    HMENU hSubMenu3 = CreatePopupMenu();
    HMENU hSubMenu4 = CreatePopupMenu();
    HMENU hSubMenu5 = CreatePopupMenu();
    HMENU hSubMenu6 = CreatePopupMenu();
    HMENU hSubMenu7 = CreatePopupMenu();
    HMENU hSubMenu8 = CreatePopupMenu();
    HMENU hSubMenu9 = CreatePopupMenu();
    HMENU hSubMenu10 = CreatePopupMenu();
    HMENU hSubMenu11 = CreatePopupMenu();
    HMENU hSubMenu12 = CreatePopupMenu();
    HMENU hSubMenu13 = CreatePopupMenu();
    HMENU hSubMenu14 = CreatePopupMenu();
    HMENU hSubMenu15 = CreatePopupMenu();
    
    AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu14, L"&OTHER PARAMETER");
    AppendMenuW(hSubMenu14, MF_STRING, IDM_DISTCURSOROBJECT, L"DIST_CURSOR_OBJECT+");
    AppendMenuW(hSubMenu14, MF_STRING, IDM_DISTCURSOROBJECT_MOINS, L"DIST_CURSOR_OBJECT-");
    
    
    AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu15, L"&GAME MODE");
    AppendMenuW(hSubMenu15, MF_STRING, IDM_STARTGAME, L"START GAME");
    AppendMenuW(hSubMenu15, MF_STRING, IDM_QUITGAME, L"QUIT GAME");
    AppendMenuW(hSubMenu15, MF_STRING, IDM_PHYSICSMODE, L"PHYSICS MODE");
    AppendMenuW(hSubMenu15, MF_STRING, IDM_DYNAMICSMODE, L"DYNAMICS MODE");
    AppendMenuW(hSubMenu15, MF_STRING, IDM_STATICMODE, L"STATIC MODE");
    AppendMenuW(hSubMenu15, MF_STRING, IDM_DRIVEMODE, L"DRIVE MODE");
    AppendMenuW(hSubMenu15, MF_STRING, IDM_CHARACTERMODE, L"CHARACTER MODE");
    
    AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu1, L"&ADD PRIMITIVE");
    AppendMenuW(hSubMenu1, MF_STRING, IDM_T_CUBE, L"ADD CUBE");
    AppendMenuW(hSubMenu1, MF_STRING, IDM_T_TEAPOT, L"ADD TEAPOT");
    AppendMenuW(hSubMenu1, MF_STRING, IDM_T_SPHERE, L"ADD SPHERE");
    AppendMenuW(hSubMenu1, MF_STRING, IDM_T_CYLINDER, L"ADD CYLINDER");
    AppendMenuW(hSubMenu1, MF_STRING, IDM_T_PLANE, L"ADD PLANE");
    
    AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu, L"&TRANSFORMATION");
    
    AppendMenuW(hSubMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu2, L"&TRANSLATION");
    AppendMenuW(hSubMenu2, MF_STRING, IDM_T_Xplus, L"X+");
	AppendMenuW(hSubMenu2, MF_STRING, IDM_T_Yplus, L"Y+");
	AppendMenuW(hSubMenu2, MF_STRING, IDM_T_Zplus, L"Z+");
	AppendMenuW(hSubMenu2, MF_STRING, IDM_T_Xmoins, L"X-");
	AppendMenuW(hSubMenu2, MF_STRING, IDM_T_Ymoins, L"Y-");
	AppendMenuW(hSubMenu2, MF_STRING, IDM_T_Zmoins, L"Z-");
	
	AppendMenuW(hSubMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu3, L"&ROTATION");
    AppendMenuW(hSubMenu3, MF_STRING, IDM_R_Xplus, L"X+");
	AppendMenuW(hSubMenu3, MF_STRING, IDM_R_Yplus, L"Y+");
	AppendMenuW(hSubMenu3, MF_STRING, IDM_R_Zplus, L"Z+");
	AppendMenuW(hSubMenu3, MF_STRING, IDM_R_Xmoins, L"X-");
	AppendMenuW(hSubMenu3, MF_STRING, IDM_R_Ymoins, L"Y-");
	AppendMenuW(hSubMenu3, MF_STRING, IDM_R_Zmoins, L"Z-");
	
	AppendMenuW(hSubMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu4, L"&SCALING");
    AppendMenuW(hSubMenu4, MF_STRING, IDM_S_Xplus, L"X+");
	AppendMenuW(hSubMenu4, MF_STRING, IDM_S_Yplus, L"Y+");
	AppendMenuW(hSubMenu4, MF_STRING, IDM_S_Zplus, L"Z+");
	AppendMenuW(hSubMenu4, MF_STRING, IDM_S_Xmoins, L"X-");
	AppendMenuW(hSubMenu4, MF_STRING, IDM_S_Ymoins, L"Y-");
	AppendMenuW(hSubMenu4, MF_STRING, IDM_S_Zmoins, L"Z-");
	
	AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu5, L"&COLOR OBJECT");
	AppendMenuW(hSubMenu5, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu6, L"&COLOR");
    AppendMenuW(hSubMenu6, MF_STRING, IDM_COL_Xplus, L"R+");
	AppendMenuW(hSubMenu6, MF_STRING, IDM_COL_Yplus, L"G+");
	AppendMenuW(hSubMenu6, MF_STRING, IDM_COL_Zplus, L"B+");
	AppendMenuW(hSubMenu6, MF_STRING, IDM_COL_Xmoins, L"R-");
	AppendMenuW(hSubMenu6, MF_STRING, IDM_COL_Ymoins, L"G-");
	AppendMenuW(hSubMenu6, MF_STRING, IDM_COL_Zmoins, L"B-");
	
	AppendMenuW(hSubMenu5, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu7, L"&AMBIANT COLOR");
    AppendMenuW(hSubMenu7, MF_STRING, IDM_AMB_Xplus, L"R+");
	AppendMenuW(hSubMenu7, MF_STRING, IDM_AMB_Yplus, L"G+");
	AppendMenuW(hSubMenu7, MF_STRING, IDM_AMB_Zplus, L"B+");
	AppendMenuW(hSubMenu7, MF_STRING, IDM_AMB_Xmoins, L"R-");
	AppendMenuW(hSubMenu7, MF_STRING, IDM_AMB_Ymoins, L"G-");
	AppendMenuW(hSubMenu7, MF_STRING, IDM_AMB_Zmoins, L"B-");
	
	AppendMenuW(hSubMenu5, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu8, L"&SPECULAR");
    AppendMenuW(hSubMenu8, MF_STRING, IDM_SPECUL_Xplus, L"R+");
	AppendMenuW(hSubMenu8, MF_STRING, IDM_SPECUL_Yplus, L"G+");
	AppendMenuW(hSubMenu8, MF_STRING, IDM_SPECUL_Zplus, L"B+");
	AppendMenuW(hSubMenu8, MF_STRING, IDM_SPECUL_Xmoins, L"R-");
	AppendMenuW(hSubMenu8, MF_STRING, IDM_SPECUL_Ymoins, L"G-");
	AppendMenuW(hSubMenu8, MF_STRING, IDM_SPECUL_Zmoins, L"B-");
	
	AppendMenuW(hSubMenu5, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu9, L"&EMISSIVE");
    AppendMenuW(hSubMenu9, MF_STRING, IDM_EMIS_Xplus, L"R+");
	AppendMenuW(hSubMenu9, MF_STRING, IDM_EMIS_Yplus, L"G+");
	AppendMenuW(hSubMenu9, MF_STRING, IDM_EMIS_Zplus, L"B+");
	AppendMenuW(hSubMenu9, MF_STRING, IDM_EMIS_Xmoins, L"R-");
	AppendMenuW(hSubMenu9, MF_STRING, IDM_EMIS_Ymoins, L"G-");
	AppendMenuW(hSubMenu9, MF_STRING, IDM_EMIS_Zmoins, L"B-");
	
	AppendMenuW(hSubMenu5, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu10, L"&POWER");
    AppendMenuW(hSubMenu10, MF_STRING, IDM_POWER_plus, L"POWER+");
    AppendMenuW(hSubMenu10, MF_STRING, IDM_POWER_moins, L"POWER-");
    
    AppendMenuW(hSubMenu5, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu11, L"ALPHA");
    AppendMenuW(hSubMenu11, MF_STRING, IDM_ALPHA_plus, L"ALPHA+");
    AppendMenuW(hSubMenu11, MF_STRING, IDM_ALPHA_moins, L"ALPHA-");
    
	AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu12, L"&BACKGROUND COLOR");
    
    AppendMenuW(hSubMenu12, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu13, L"&COLOR");
    AppendMenuW(hSubMenu13, MF_STRING, IDM_COLBG_Xplus, L"R+");
	AppendMenuW(hSubMenu13, MF_STRING, IDM_COLBG_Yplus, L"G+");
	AppendMenuW(hSubMenu13, MF_STRING, IDM_COLBG_Zplus, L"B+");
	AppendMenuW(hSubMenu13, MF_STRING, IDM_COLBG_Xmoins, L"R-");
	AppendMenuW(hSubMenu13, MF_STRING, IDM_COLBG_Ymoins, L"G-");
	AppendMenuW(hSubMenu13, MF_STRING, IDM_COLBG_Zmoins, L"B-");
	
    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu, L"&MENU");
    SetMenu(hwnd, hMenubar);
}

LRESULT CALLBACK WindowProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  {
    
  
	switch(message) {
		
		case WM_DESTROY: {
			w->onDestroy();
			PostQuitMessage(0);
		
			break;
		}
		   
		   case  WM_MOUSEWHEEL :
		   	{
			  
		     float zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    	
		 
		  	if(GetActiveWindow()==api->getHWND())
		   	 	api->setControlScrollWithCamUP(zDelta*0.05f);
		   	if(GetActiveWindow()==api->getHWND2())
		   	 	api->setControlScrollWithCamUP2(zDelta*0.05f);
		   	if(GetActiveWindow()==api->getHWND3())
		   	 	api->setControlScrollWithCamUP3(zDelta*0.05f);
		   	if(GetActiveWindow()==api->getHWND4())
		   	 	api->setControlScrollWithCamUP4(zDelta*0.05f);
		 		
		   	
		   
		   break;
	}
   case WM_MBUTTONDOWN :
   	{
   	api->setControlCamLateral(true);
	   
   	break;
   }
	 case WM_MBUTTONUP:
   	{
   	api->setControlCamLateral(false);
	   
   	break;
   }	
		  case WM_INPUT:
            {
                RAWINPUT InputData;

                UINT DataSize = sizeof(RAWINPUT);
                GetRawInputData((HRAWINPUT)lParam,
                                RID_INPUT,
                                &InputData,
                                &DataSize,
                                sizeof(RAWINPUTHEADER));

                // set the mouse button status
                static BOOL MouseDown;
                if(InputData.data.mouse.usButtonFlags == RI_MOUSE_LEFT_BUTTON_DOWN)
                    MouseDown = TRUE;
                if(InputData.data.mouse.usButtonFlags == RI_MOUSE_LEFT_BUTTON_UP)
                    MouseDown = FALSE;
                
                static BOOL MouseDownRight;
                if(InputData.data.mouse.usButtonFlags == RI_MOUSE_RIGHT_BUTTON_DOWN)
                    MouseDownRight = TRUE;
                if(InputData.data.mouse.usButtonFlags == RI_MOUSE_RIGHT_BUTTON_UP)
                    MouseDownRight = FALSE;
				
				
				
                // rotate the teapot
                if(MouseDown)
                    api->setControlCam(true);
                else
                  api->setControlCam(false);
                
                if(MouseDownRight )
                {
                
                	api->setControlCamUp(true);
               		
				}
				
				else
				{
					api->setControlCamUp(false);
					
				}

                return 0;
            } break;
            
		case WM_CREATE:
		{
			

		
	     
			w->onCreate();
			w->AddMenus(hWnd);
			break;
		}
		case WM_COMMAND:
		{
		//++++//
			if(LOWORD(wParam)==3)
			{
				api->setIncX(true);
			
			}
				if(LOWORD(wParam)!=3)
			{
				api->setIncX(false);
			
			}
				if(LOWORD(wParam)==4)
			{
				api->setIncY(true);
			
			}
				if(LOWORD(wParam)!=4)
			{
				api->setIncY(false);
			
			}
				if(LOWORD(wParam)==5)
			{
			api->setIncZ(true);
			
			}
				if(LOWORD(wParam)!=5)
			{
			api->setIncZ(false);
			
			}
			
				if(LOWORD(wParam)==6)
			{
				api->setRotX(true);
			
			}
				if(LOWORD(wParam)!=6)
			{
				api->setRotX(false);
			
			}
				if(LOWORD(wParam)==7)
			{
				api->setRotY(true);
			
			}
				if(LOWORD(wParam)!=7)
			{
				api->setRotY(false);
			
			}
				if(LOWORD(wParam)==8)
			{
				api->setRotZ(true);
			
			}
				if(LOWORD(wParam)!=8)
			{
				api->setRotZ(false);
			
			}
		 
		 	if(LOWORD(wParam)==9)
			{
				api->setScale_x(true);
			
			}
			if(LOWORD(wParam)!=9)
			{
				api->setScale_x(false);
			
			}
				if(LOWORD(wParam)==10)
			{
				api->setScale_y(true);
			
			}
					if(LOWORD(wParam)!=10)
			{
				api->setScale_y(false);
			
			}
				if(LOWORD(wParam)==11)
			{
				api->setScale_z(true);
			
			}
				if(LOWORD(wParam)!=11)
			{
				api->setScale_z(false);
			
			}
				if(LOWORD(wParam)==12)
			{
				api->setColorX_(true);
			
			}
				if(LOWORD(wParam)!=12)
			{
				api->setColorX_(false);
			
			}
				if(LOWORD(wParam)==13)
			{
				api->setColorY_(true);
			
			}
				if(LOWORD(wParam)!=13)
			{
				api->setColorY_(false);
			
			}
				if(LOWORD(wParam)==14)
			{
				api->setColorZ_(true);
			
			}
				if(LOWORD(wParam)!=14)
			{
				api->setColorZ_(false);
			
			}
				if(LOWORD(wParam)==15)
			{
				api->setAmbiantX_(true);
			
			}
			if(LOWORD(wParam)!=15)
			{
				api->setAmbiantX_(false);
			
			}
				if(LOWORD(wParam)==16)
			{
				api->setAmbiantY_(true);
			
			}
				if(LOWORD(wParam)!=16)
			{
				api->setAmbiantY_(false);
			
			}
				if(LOWORD(wParam)==17)
			{
				api->setAmbiantZ_(true);
			
			}
				if(LOWORD(wParam)!=17)
			{
				api->setAmbiantZ_(false);
			
			}
				if(LOWORD(wParam)==18)
			{
				api->setSpecularX_(true);
			
			}
				if(LOWORD(wParam)!=18)
			{
				api->setSpecularX_(false);
			
			}
				if(LOWORD(wParam)==19)
			{
				api->setSpecularY_(true);
			
			}
			if(LOWORD(wParam)!=19)
			{
				api->setSpecularY_(false);
			
			}
				if(LOWORD(wParam)==20)
			{
				api->setSpecularZ_(true);
			
			}
				if(LOWORD(wParam)!=20)
			{
				api->setSpecularZ_(false);
			
			}
				if(LOWORD(wParam)==21)
			{
				api->setEmmissiveX_(true);
			
			}
					if(LOWORD(wParam)!=21)
			{
				api->setEmmissiveX_(false);
			
			}
				if(LOWORD(wParam)==22)
			{
				api->setEmmissiveY_(true);
			
			}
				if(LOWORD(wParam)!=22)
			{
				api->setEmmissiveY_(false);
			
			}
				if(LOWORD(wParam)==23)
			{
				api->setEmmissiveZ_(true);
			
			}
				if(LOWORD(wParam)!=23)
			{
				api->setEmmissiveZ_(false);
			
			}
				if(LOWORD(wParam)==24)
			{
				api->setPower_(true);
			
			}
					if(LOWORD(wParam)!=24)
			{
				api->setPower_(false);
			
			}
				if(LOWORD(wParam)==25)
			{
				api->setAlpha_(true);
			
			}
				if(LOWORD(wParam)!=25)
			{
				api->setAlpha_(false);
			
			}
				if(LOWORD(wParam)==26)
			{
				api->setbg_colX(true);
			
			}
				if(LOWORD(wParam)!=26)
			{
				api->setbg_colX(false);
			
			}
				if(LOWORD(wParam)==27)
			{
				api->setbg_colY(true);
			
			}
				if(LOWORD(wParam)!=27)
			{
				api->setbg_colY(false);
			
			}
				if(LOWORD(wParam)==28)
			{
				api->setbg_colZ(true);
			
			}
				if(LOWORD(wParam)!=28)
			{
				api->setbg_colZ(false);
			
			}
			//----neg//
			
					if(LOWORD(wParam)==29)
			{
				api->setIncXNeg(true);
			
			}
				if(LOWORD(wParam)!=29)
			{
				api->setIncXNeg(false);
			}
				if(LOWORD(wParam)==30)
			{
				api->setIncYNeg(true);
			}
				if(LOWORD(wParam)!=30)
			{
				api->setIncYNeg(false);
			}
				if(LOWORD(wParam)==31)
			{
				api->setIncZNeg(true);
			
			}
					if(LOWORD(wParam)!=31)
			{
				api->setIncZNeg(false);
			
			}
			
			
		
			
				if(LOWORD(wParam)==32)
			{
				api->setRotXNeg(true);
			
			}
				if(LOWORD(wParam)!=32)
			{
				api->setRotXNeg(false);
			}
				if(LOWORD(wParam)==33)
			{
				api->setRotYNeg(true);
			}
				if(LOWORD(wParam)!=33)
			{
				api->setRotYNeg(false);
			}
				if(LOWORD(wParam)==34)
			{
				api->setRotZNeg(true);
			
			}
					if(LOWORD(wParam)!=34)
			{
				api->setRotZNeg(false);
			
			}
		 
		 	if(LOWORD(wParam)==35)
			{
			
			api->setScale_x_neg(true);
			}
				if(LOWORD(wParam)!=35)
			{
			
			api->setScale_x_neg(false);
			}
				if(LOWORD(wParam)==36)
			{
				api->setScale_y_neg(true);
			
			}
				if(LOWORD(wParam)!=36)
			{
		
				api->setScale_y_neg(false);
			}
				if(LOWORD(wParam)==37)
			{
			api->setScale_z_neg(true);
			
			}
				if(LOWORD(wParam)!=37)
			{
			
				api->setScale_z_neg(false);
			}
			
				if(LOWORD(wParam)==38)
			{
			
			api->setColorX_neg(true);
			}
			
					if(LOWORD(wParam)!=38)
			{
			
			api->setColorX_neg(false);
			}
			
				if(LOWORD(wParam)==39)
			{
			
			api->setColorY_neg(true);
			}
			
					if(LOWORD(wParam)!=39)
			{
			
			api->setColorY_neg(false);
			}
			
				if(LOWORD(wParam)==40)
			{
			
			api->setColorZ_neg(true);
			}
			
					if(LOWORD(wParam)!=40)
			{
			
			api->setColorZ_neg(false);
			}
				if(LOWORD(wParam)==41)
			{
			api->setAmbiantX_neg(true);
			
			}
				if(LOWORD(wParam)!=41)
			{
		
			api->setAmbiantX_neg(false);
			}
				if(LOWORD(wParam)==42)
			{
			
				api->setAmbiantY_neg(true);
			}
					if(LOWORD(wParam)!=42)
			{
			
				api->setAmbiantY_neg(false);
			}
				if(LOWORD(wParam)==43)
			{
	
				api->setAmbiantZ_neg(true);
			}
				if(LOWORD(wParam)!=43)
			{
		api->setAmbiantZ_neg(false);
			
			}
				if(LOWORD(wParam)==44)
			{
		api->setSpecularX_neg(true);
			
			}
				if(LOWORD(wParam)!=44)
			{
			api->setSpecularX_neg(false);
			
			}
				if(LOWORD(wParam)==45)
			{
			api->setSpecularY_neg(true);
			
			}
				if(LOWORD(wParam)!=45)
			{
		
				api->setSpecularY_neg(false);
			}
				if(LOWORD(wParam)==46)
			{
			api->setSpecularZ_neg(true);
			
			}
				if(LOWORD(wParam)!=46)
			{
		
				api->setSpecularZ_neg(false);
			}
			
				if(LOWORD(wParam)==47)
			{
				api->setEmmissiveX_neg(true);
			
			}
				if(LOWORD(wParam)!=47)
			{
				api->setEmmissiveX_neg(false);
			
			}
				if(LOWORD(wParam)==48)
			{
					api->setEmmissiveY_neg(true);
			
			}
				if(LOWORD(wParam)!=48)
			{
					api->setEmmissiveY_neg(false);
			
			}
				if(LOWORD(wParam)==49)
			{
			
					api->setEmmissiveZ_neg(true);
			}
				if(LOWORD(wParam)!=49)
			{
			
					api->setEmmissiveZ_neg(false);
			}
				if(LOWORD(wParam)==50)
			{
			api->setPower_(true);
			
			}
				if(LOWORD(wParam)!=50)
			{
			api->setPower_(false);
			
			}
				if(LOWORD(wParam)==51)
			{
		
				api->setAlpha_(true);
			}
				if(LOWORD(wParam)!=51)
			{
		
				api->setAlpha_(false);
			}
				if(LOWORD(wParam)==52)
			{
				api->setbg_colXNeg(true);
			
			}
					if(LOWORD(wParam)!=52)
			{
				api->setbg_colXNeg(false);
			
			}
				if(LOWORD(wParam)==53)
			{
				api->setbg_colYNeg(true);
			
			}
				if(LOWORD(wParam)!=53)
			{
				api->setbg_colYNeg(false);
			
			}
				if(LOWORD(wParam)==54)
			{
				api->setbg_colZNeg(true);
			
			}
				if(LOWORD(wParam)!=54)
			{
				api->setbg_colZNeg(false);
			
			}
					if(LOWORD(wParam)==55)
			{
				api->addCube();
		
			}
					if(LOWORD(wParam)==56)
			{
				api->addTeapot();
		
			}
					if(LOWORD(wParam)==57)
			{
				api->addSphere();
		
			}
					if(LOWORD(wParam)==58)
			{
				api->addCylinder();
		
			}
					if(LOWORD(wParam)==59)
			{
				api->addPlane();
		
			}
					if(LOWORD(wParam)==60)
			{
				api->setDist_(true);
		
			}
					if(LOWORD(wParam)!=60)
			{
				api->setDist_(false);
		
			}
					if(LOWORD(wParam)==61)
			{
				api->setDist_neg(true);
		
			}
					if(LOWORD(wParam)!=61)
			{
				api->setDist_neg(false);
		
			}
				if(LOWORD(wParam)==62)
			{
				api->setPhysicsMode(api->game,true);
			
					api->setPhysicsMode(api->game2,true);
			
				api->setPhysicsMode(api->game3,true);
			
					api->setPhysicsMode(api->game4,true);
			
			}
			
		
			
				if(LOWORD(wParam)==65)
			{
				
		
					api->setDynamicMode(api->game,true);
					
					
					
		
					api->setDynamicMode(api->game2,true);
					
		
		
					api->setDynamicMode(api->game3,true);
					
					
				
		
					api->setDynamicMode(api->game4,true);
			
				
			}
			
			/*
				if(LOWORD(wParam)!=65);
			{
					api->setDynamicMode(api->game->cube,false);
			
					api->setDynamicMode(api->game2->cube,false);
			
					api->setDynamicMode(api->game3->cube,false);
		
					api->setDynamicMode(api->game4->cube,false);
					
					api->setDynamicMode(api->game->teapot,false);
			
					api->setDynamicMode(api->game2->teapot,false);
			
					api->setDynamicMode(api->game3->teapot,false);
		
					api->setDynamicMode(api->game4->teapot,false);
					
					
					api->setDynamicMode(api->game->plane,false);
			
					api->setDynamicMode(api->game2->plane,false);
			
					api->setDynamicMode(api->game3->plane,false);
		
					api->setDynamicMode(api->game4->plane,false);
					
					
					api->setDynamicMode(api->game->cylinder,false);
			
					api->setDynamicMode(api->game2->cylinder,false);
			
					api->setDynamicMode(api->game3->cylinder,false);
		
					api->setDynamicMode(api->game4->cylinder,false);
			
				
			}
			*/
			
			
				if(LOWORD(wParam)==63)
			{
					api->setStart(api->game,true);
			
					api->setStart(api->game2,true);
			
					api->setStart(api->game3,true);
			
					api->setStart(api->game4,true);
			
			}
			
		
			
				if(LOWORD(wParam)==64)
			{
					api->setQuit(api->game,true);
			
					api->setQuit(api->game2,true);
			
					api->setQuit(api->game3,true);
			
					api->setQuit(api->game4,true);
			}
			
		
				if(LOWORD(wParam)==66)
			{
					
		
					api->setDynamicMode(api->game,false);
					
					
				
		
					api->setDynamicMode(api->game2,false);
					
					
		
					api->setDynamicMode(api->game3,false);
					
			
		
					api->setDynamicMode(api->game4,false);
			
			}
			
			
				if(LOWORD(wParam)==67)
			{
				
			}
			
			
				if(LOWORD(wParam)==68)
			{
				
			}
			
			
		}
			
		default:
		return DefWindowProc (hWnd, message, wParam, lParam);
		
}

return NULL;
}


windows::windows()
{
	
}
windows::~windows()
{
	
}


bool windows::init(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd)
{
WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = className;
	wc.lpszMenuName = "";
	wc.style = NULL;
	wc.lpfnWndProc = &WindowProc1;

	if (!::RegisterClassEx(&wc)) // If the registration of class will fail, the function will return false
		return false;

	/*if (!window)
		window = this;*/

	//Creation of the window
	hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, className, windowTitle, WS_THICKFRAME, x, y, width, height,
		NULL, NULL, NULL, this);

	//if the creation fail return false
	if (!hwnd) 
		return false;

	//show up the window
	::ShowWindow(hwnd, SW_SHOW);
	::UpdateWindow(hwnd);


	

	//set this flag to true to indicate that the window is initialized and running
	isrun_ = true;



	return true;
}


bool windows::initDirectX(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd)
{
WNDCLASSEX wc;

	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = className;
	wc.lpszMenuName = "";
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = &WindowProc2;

	if (!::RegisterClassEx(&wc)) // If the registration of class will fail, the function will return false
		return false;

	/*if (!window)
		window = this;*/

	//Creation of the window
	hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, className, windowTitle, WS_OVERLAPPEDWINDOW, x, y, width, height,
		NULL, NULL, NULL, this);

	//if the creation fail return false
	if (!hwnd) 
		return false;

	//show up the window
	::ShowWindow(hwnd, SW_SHOW);
	::UpdateWindow(hwnd);


	

	//set this flag to true to indicate that the window is initialized and running
	isrun_ = true;



	return true;
}
void windows::onUpdate()
{
	
}
void windows::onCreate()
{
	
}
bool windows::broadcast()
{
	MSG msg;
	while(PeekMessage(&msg,NULL,0,0,PM_REMOVE)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	w->onUpdate();
	Sleep(0);
	return true;
}
bool windows::release()
{

		if(!DestroyWindow(hwnd))
		{
			return false;
		}
	
	return true;
}
bool windows::isrun()
{
	return isrun_;
}
void windows::onDestroy()
{
	isrun_=false;
}


