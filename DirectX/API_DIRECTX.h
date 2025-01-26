#ifndef DEf_APIDIRECTX9_H
#define DEF_APIDIRECTX9_H
#include <windows.h>
#include <windowsx.h>
#include<vector>
#include <d3d9.h>
#include <d3dx9.h>
#include"entities/object_directX.h"
#include"../OpenGL/mathsutils/functions.h"
#include"entities/cameraX.h"
#include"entities/pointerX.h"
#include"../OpenGL/mathsutils/collision.h"
#define SCREEN_POSX 0
#define SCREEN_POSY 0
#define SCREEN_WIDTH 650
#define SCREEN_HEIGHT 350
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
using namespace std;


class APIDIRECTX9
{
	public:
	APIDIRECTX9();
	~APIDIRECTX9();
	void initD3D(HWND hwnd,bool windowed);
	void init_graphics();
	void loadCUBE(vector3d t, vector3d r, vector3d s,vector3d c);
	void loadTeapot(vector3d t,vector3d r, vector3d s,vector3d c);
	void loadSphere(vector3d t,vector3d r, vector3d s,vector3d c);
	void loadCylinder(vector3d t,vector3d r, vector3d s,vector3d c);
	void loadPlane(vector3d t,vector3d r, vector3d s,vector3d c);
	void updateGameEditor();
	void Clear(D3DCOLOR color);
	void begin();
	void end();
	void present();
	void init_Light();
	void Callback();
	void render_frame();
	void render_frame2();
	void render_frame3();
	void render_frame4();
	void drawPrimitive();
	void Render_Circle();
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
	void setDist(float d);
	float getDist();
	bool getPhysicsMode();
	bool getStart();
	bool getQuit();
	bool getCharacterMode();
	bool getDriveMode();
	bool getDynamicMode();
	bool getStaticMode();
	void setPhysicsMode(bool b);
	void setStart(bool b);
	void setQuit(bool b);
	void setCharacterMode(bool b);
	void setDriveMode(bool b);
	void setDynamicMode(bool b);
	void setStaticMode(bool b);
	void GameMode(std::vector<objectX*> obj_,std::vector<objectX*> pref_,std::vector<objectX*> prefAnim_);
	void reinitialiseGame(std::vector<objectX*> obj_,std::vector<objectX*> pref_,std::vector<objectX*> prefAnim_);
	void collision(std::vector<objectX*> obj_,std::vector<objectX*> obj2_);
	std::vector<objectX *> cube;
	std::vector<objectX *> teapot;
	std::vector<objectX *> sphere;
	std::vector<objectX *> cylinder;
	std::vector<objectX *> plane;
	std::vector<objectX *> grid;
	std::vector<objectX *> pref;
	std::vector<objectX *> prefAnim;
	objectX *  cc;
	pointerX* pp;
  	std::vector<cameraX*> cam;
    
	private:

LPDIRECT3D9 d3d;		
D3DMATERIAL9 mat;						// the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;
POINT MousePos;    // globally defined mouse position
float dist;
bool lanchGame;
float time;
bool physicsMode,startGame,quitGame,characterMode,driveMode,dynamicsMode,staticMode;
bool up,down,right,left;

    //static float index = 0.0f; //index+=0.05f; // an ever-increasing float value


};
#endif

