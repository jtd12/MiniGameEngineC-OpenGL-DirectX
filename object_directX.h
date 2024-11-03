#ifndef DEF_DIRECTX_H
#define DEF_DIRECTX_H
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include"functions.h"
#include"pointerX.h"
#include"vector.h"
#include"vertexDeclaration.h"
#include"boundingbox.h"
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL)




class objectX
{
	public:
	objectX(vector3d t, vector3d r, vector3d s,vector3d c);
	~objectX();
	void init_Cube(LPDIRECT3DDEVICE9 d3ddev);
	void update();
	void showCube(LPDIRECT3DDEVICE9 d3ddev);
	void setPosition(vector3d pos);
	vector3d getPosition();
	void setRotation(vector3d rot);
	vector3d getRotation();
	void setScale(vector3d s);
	vector3d getScale();
	void setColor(vector3d col);
	void setAmbiant(vector3d amb);
	void setEmissive(vector3d emmiss);
	void setSpecular(vector3d spec);
	void setPower(float pow);
	void setAlpha(float alph);
	void setTranslate(vector3d t);
	void setRotate(vector3d r);
	void setColorInc(vector3d col);
	void setScaleInc(vector3d s);
	void init_Teapot(LPDIRECT3DDEVICE9 d3ddev);
	void init_Sphere(LPDIRECT3DDEVICE9 d3ddev);
	void init_Cylinder(LPDIRECT3DDEVICE9 d3ddev);
	void init_Plane(LPDIRECT3DDEVICE9 d3ddev);
	void showTeapot(LPDIRECT3DDEVICE9 d3ddev);
	void showSphere(LPDIRECT3DDEVICE9 d3ddev);
	void showCylinder(LPDIRECT3DDEVICE9 d3ddev);
	void showGrid(LPDIRECT3DDEVICE9 d3ddev);
	void showPlane(LPDIRECT3DDEVICE9 d3ddev);
	void Line(int X, int Y, int radius,  DWORD Color,LPDIRECT3DDEVICE9 d3ddev);
	void DrawLineHoriz(LPDIRECT3DDEVICE9 Device_Interface,int bx,int by,int bw,D3DCOLOR COLOR);
	void DrawLineVert(LPDIRECT3DDEVICE9 Device_Interface,int bx,int by,int bw,D3DCOLOR COLOR);
	void movement(bool up,bool down, bool right, bool left);
	void movementCharacter(bool up,bool down, bool right, bool left);
	void setDrive(bool b);
	bool getDrive();
	void setDynamic(bool b);
	bool getDynamic();
	void setWalk(bool b);
	bool getWalk();
	void physics();
	void dynamique();
	void statique();
		void setLocation(vector3d l);
		vector3d getLocation();
		void setLocationIncrement();
		vector3d getP1();
		vector3d getP2();
		vector3d getP3();
		vector3d getP4();
		vector3d getP5();
		vector3d getP6();
		vector3d getP7();
		vector3d getP8();
		vector3d getP9();
		vector3d getP10();
		vector3d getP11();
		vector3d getP12();
		vector3d getP13();
		vector3d getP14();
		vector3d getP15();
		vector3d getP16();
 	 	vector3d getP17();
		vector3d getP18();
		vector3d getP19();
		vector3d getP20();
		vector3d getP21();
		vector3d getP22();
		vector3d getP23();
		vector3d getP24();
	
	private:

	D3DXMATRIX matScaleA;    // a matrix to store the rotation for each triangle
	D3DXMATRIX matTranslateA;    // a matrix to store the translation for triangle A
	D3DXMATRIX matRotateX;    // a matrix to store the rotation for each triangle
	D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle
	D3DXMATRIX matRotateZ;    // a matrix to store the rotation for each triangle
	D3DXMATRIX matScaleB;    // a matrix to store the rotation for each triangle
	D3DXMATRIX matTranslateB;    // a matrix to store the translation for triangle A
	D3DXMATRIX matRotateXB;    // a matrix to store the rotation for each triangle
	D3DXMATRIX matRotateYB;    // a matrix to store the rotation for each triangle
	D3DXMATRIX matRotateZB;    // a matrix to store the rotation for each triangle
	LPDIRECT3D9 d3d;		
	D3DMATERIAL9 mat;							// the pointer to the device class
	LPDIRECT3DVERTEXBUFFER9 vertexbuffer = NULL;	// the pointer to the vertex buffer
	LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;	
	LPD3DXMESH meshTeapot;    // define the mesh pointer
	LPD3DXMESH meshSphere;    // define the mesh pointer
	LPD3DXMESH meshCylinder;    // define the mesh pointer
	vector3d translate;
	vector3d rotate;
	vector3d scale;
	vector3d color;
	vector3d ambiant;
	vector3d specular;
	vector3d emissive;
		vector3d  p1;
 		vector3d  p2;
 		vector3d  p3;
 		vector3d  p4;
 		vector3d  p5;
 		vector3d  p6;
 		vector3d  p7;
 		vector3d  p8;
 		vector3d  p9;
 		vector3d  p10;
 		vector3d  p11;
 		vector3d  p12;
 		vector3d  p13;
 		vector3d  p14;
 		vector3d  p15;
 		vector3d  p16;
 		vector3d  p17;
 		vector3d  p18;
 		vector3d  p19;
 		vector3d  p20;
 		vector3d  p21;
 		vector3d  p22;
 		vector3d  p23;
 		vector3d  p24;
 		boundingbox* b;
		float alpha,power;
		float speed;
		float speed2;
		float maxSpeed;
		float dec;
		float acc;
		float angle;
		float turnSpeed;
		bool dynamic;
		bool drive;
		bool walk;

	
};
#endif
