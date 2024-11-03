#ifndef DEF_WINDOWS_H
#define DEF_WINDOWS_H
#include<windows.h>
#include <iostream>
#include<stdio.h>
#include"switchAPI.h"
#define IDM_FILE_ADD 0

#define IDM_FILE_TRANSLATE 2
#define IDM_T_Xplus 3
#define IDM_T_Yplus 4
#define IDM_T_Zplus 5
#define IDM_R_Xplus 6
#define IDM_R_Yplus 7
#define IDM_R_Zplus 8
#define IDM_S_Xplus 9
#define IDM_S_Yplus 10
#define IDM_S_Zplus 11

#define IDM_COL_Xplus 12
#define IDM_COL_Yplus 13
#define IDM_COL_Zplus 14

#define IDM_AMB_Xplus 15
#define IDM_AMB_Yplus 16
#define IDM_AMB_Zplus 17

#define IDM_SPECUL_Xplus 18
#define IDM_SPECUL_Yplus 19
#define IDM_SPECUL_Zplus 20

#define IDM_EMIS_Xplus 21
#define IDM_EMIS_Yplus 22
#define IDM_EMIS_Zplus 23

#define IDM_POWER_plus 24
#define IDM_ALPHA_plus 25

#define IDM_COLBG_Xplus 26
#define IDM_COLBG_Yplus 27
#define IDM_COLBG_Zplus 28


#define IDM_T_Xmoins 29
#define IDM_T_Ymoins 30
#define IDM_T_Zmoins 31
#define IDM_R_Xmoins 32
#define IDM_R_Ymoins 33
#define IDM_R_Zmoins 34
#define IDM_S_Xmoins 35
#define IDM_S_Ymoins 36
#define IDM_S_Zmoins 37

#define IDM_COL_Xmoins 38
#define IDM_COL_Ymoins 39
#define IDM_COL_Zmoins 40

#define IDM_AMB_Xmoins 41
#define IDM_AMB_Ymoins 42
#define IDM_AMB_Zmoins 43

#define IDM_SPECUL_Xmoins 44
#define IDM_SPECUL_Ymoins 45
#define IDM_SPECUL_Zmoins 46

#define IDM_EMIS_Xmoins 47
#define IDM_EMIS_Ymoins 48
#define IDM_EMIS_Zmoins 49

#define IDM_POWER_moins 50
#define IDM_ALPHA_moins 51

#define IDM_COLBG_Xmoins 52
#define IDM_COLBG_Ymoins 53
#define IDM_COLBG_Zmoins 54

#define IDM_T_CUBE 55
#define IDM_T_TEAPOT 56
#define IDM_T_SPHERE 57
#define IDM_T_CYLINDER 58
#define IDM_T_PLANE 59
#define IDM_DISTCURSOROBJECT 60
#define IDM_DISTCURSOROBJECT_MOINS 61
#define IDM_PHYSICSMODE 62
#define IDM_STARTGAME 63
#define IDM_QUITGAME 64
#define IDM_DYNAMICSMODE 65
#define IDM_STATICMODE 66
#define IDM_DRIVEMODE 67
#define IDM_CHARACTERMODE 68

#define WM_MOUSEWHEEL    0x020A
#define WM_MBUTTONDBLCLK 0x0209
#define WM_MBUTTONDOWN   0x0207
#define WM_MBUTTONUP     0x0208

class windows
{
	public:
		windows();
		~windows();
		bool init(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd);
		bool initDirectX(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd);
		void AddMenus(HWND hwnd);
		bool broadcast();
	    void onCreate();
		void onDestroy();
		void onUpdate();
		bool release();
		bool isrun();
		
		protected:
		HWND hwnd;	
		bool isrun_;
		bool isrun2_;
		
	
		
};


#endif
