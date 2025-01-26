#ifndef DEF_CAMERAX_H
#define DEF_CAMERAX_H
//#include"vector.h"
#include <windows.h>
#include <windowsx.h>
#include<vector>
#include <d3d9.h>
#include <d3dx9.h>
#include<stdio.h>
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)


class cameraX
{
	public:
		cameraX();
		~cameraX();
		void controlCamera();
		void lockCamera();
		void setRotation(float yaw_,float pitch_,float roll_);
		void update(LPDIRECT3DDEVICE9 d3ddev);
		void moveCamera(float speed);
		void moveCameraLeft(float my);
		void moveCameraback();
		void moveCameraLateral();
		void moveCameraLateralInverse();
		void moveCameraUp(float my);
		void setPitch(float p);
		void setYaw(float y);
		
		private:
		  
		    float yaw;
	  		float pitch;
			float roll;
			D3DXVECTOR3 camerapos;
			D3DXVECTOR3 up;
			float movevel;
			
			
			
		
			
			

};
#endif
