#ifndef DEF_POINTERX_H
#define DEF_POINTERX_H
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include"vector.h"
#include"vertexDeclaration.h"
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL)




class pointerX
 {
 	public:
 		pointerX();
 		~pointerX();
 		void init_graphics(LPDIRECT3DDEVICE9 d3ddev);
		void update();
		void show(LPDIRECT3DDEVICE9 d3ddev);
		void setPosition(vector3d pos);
		vector3d getPosition();
		void setRotation(vector3d rot);
		vector3d getRotation();
		void setScale(vector3d s);
		vector3d getScale();
		void setColor(vector3d col);
		void setTranslate(vector3d t);
		void setLocation(vector3d t);
		D3DXMATRIX matTranslateD;    // a matrix to store the translation for triangle A
		D3DXMATRIX matTranslateA;    // a matrix to store the translation for triangle A
		private:
	
		D3DXMATRIX matScaleA;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matScaleB;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matScaleC;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matScaleD;    // a matrix to store the rotation for each triangle
	
		
		D3DXMATRIX matTranslateB;    // a matrix to store the translation for triangle A
		D3DXMATRIX matTranslateC;    // a matrix to store the translation for triangle A
		D3DXMATRIX matRotateX;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateZ;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateX_2;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateY_2;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateZ_2;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateX_3;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateY_3;    // a matrix to store the rotation for each triangle
		D3DXMATRIX matRotateZ_3;    // a matrix to store the rotation for each triangle
		LPDIRECT3D9 d3d;		
		D3DMATERIAL9 mat;
		D3DMATERIAL9 mat2;
		D3DMATERIAL9 mat3;						// the pointer to our Direct3D interface
		LPDIRECT3DDEVICE9 d3ddev;						// the pointer to the device class
		LPDIRECT3DVERTEXBUFFER9 vertexbuffer = NULL;	// the pointer to the vertex buffer
		LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;	
		vector3d translate;
		vector3d translate2;
		vector3d translate3;
		vector3d translate4;
		vector3d rotate;
		vector3d rotate2;
		vector3d rotate3;
		vector3d scale;
		vector3d scale2;
		vector3d scale3;
		vector3d scale4;
		vector3d color;
		vector3d color2;
		vector3d color3;
		float alpha;
 		float alpha2;
 		float alpha3;
 };
 #endif
