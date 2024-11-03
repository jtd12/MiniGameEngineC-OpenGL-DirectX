#ifndef DEF_SETUP_H
#define DEF_SETUP_H
#include <windows.h>
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<F:\freeglut\include\GL\freeglut.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<time.h>
#include"grid.h"
#include"pointer.h"
#include"camera.h"
#include"menu.h"
#include"prefab.h"
#include"prefabAnim.h"
#include"hud.h"
#include"skybox.h"
#include"collision.h"
#include"objloader.h"
#include"proceduralObject.h"
using namespace std;

class setup
{
public:
	setup();
	~setup();
 void update();
 void passiveMotion(int x, int y);
 void show();
 void show2();
 void show3();
 void show4();
void reshape(int width,int height);
void reshapeOrtho(int width,int height);
 void passiveKeyboard(char key,int x,int y);
void clavierActif();
void initGL();
void controlKeyboard(char key,int x, int y);
void mouseMotion(int x,int y);
void controlSpecialKeyboard(int key,int x, int y);
void passiveSpecialKeyboard(int key,int x, int y);
void saveToFile();
void loadToFile();
void moveCamera(float dir);
void mouse(int button, int state, int x, int y);
void mouseWheel(int x, int y, int z, int w);
void mouseWheel2(int x, int y, int z, int w);
void mouseMotion2(int x,int y);
void mouseMotion3(int x,int y);
void mouseMotion4(int x,int y);
void mouseWheel3(int x, int y, int z, int w);
void mouseWheel4(int x, int y, int z, int w);
void mouse2(int button, int state, int x, int y);
void mouse3(int button, int state, int x, int y);
void mouse4(int button, int state, int x, int y);
void lighting();
void fog();
bool selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist);
void colorSky();
void selectCam();
void reinitialiseGame(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_);
void GameMode(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_);
void collision(std::vector<object*> obj_,std::vector<object*> obj2_);
void collision(std::vector<prefab*> obj_,std::vector<object*> obj2_);
void collision(std::vector<prefabAnim*> obj_,std::vector<object*> obj2_);
void scaleObject(std::vector<object*> obj_);
void scaleObject(std::vector<Pobject*> obj_);
void scaleObject(std::vector<prefab*> obj_);
void scaleObject(std::vector<prefabAnim*> obj_);
void rotateObject(std::vector<object*> obj_);
void rotateObject(std::vector<Pobject*> obj_);
void rotateObject(std::vector<prefab*> obj_);
void rotateObject(std::vector<prefabAnim*> obj_);
void colorObject(std::vector<object*> obj_);
void translateObject(std::vector<object*> obj_);
void translateObject(std::vector<Pobject*> obj_);
void translateObject(std::vector<prefab*> obj_);
void translateObject(std::vector<prefabAnim*> obj_);
bool startG();
void linkParentObject(std::vector<object*> obj_,std::vector<object*> obj2_);
void linkParentObject(std::vector<prefab*> obj_,std::vector<object*> obj2_);
void linkParentObject(std::vector<prefabAnim*> obj_,std::vector<object*> obj2_);
void drawText(float x, float y, std::string text);
void enable2D(int width, int height);
void enable2D(int width, int height,std::vector<object*> obj_);
void enable2D(int width, int height,std::vector<Pobject*> obj_);
void enable2D(int width, int height,std::vector<prefab*> obj_);
void enable2D(int width, int height,std::vector<prefabAnim*> obj_);
void mode2D();
std::string vector2str(vector3d x);
std::string float2str(float x);
std::string getFileName();
void lightDiffuse();
void lightAmb();
void focal();
void moveLight();

private:

bool mi;
bool fog_;
float intensity_fog;
float start_density;
float end_density;
 float mousevel;
 float camYaw;
 float camPitch;
 float pitch;
 float xpos,ypos,zpos;
 float angle;
float nearPlane;
float farPlane;
  int Nom;
int useStencil; 
	pointer *p;
  grid *g;
 bool space;
 bool mtouc;
  std::string fileName[15];	
	std::vector<camera*> cam;
	  std::vector<object*> obj;
	  std::vector<object*> obj2;	
	  std::vector<object*> obj3; 
	  std::vector<object*> obj4; 
	std::vector<object*> obj5; 
	std::vector<Pobject*> Pobj; 
	std::vector<Pobject*> Pobj2;
	std::vector<Pobject*> Pobj3;
	std::vector<Pobject*> Pobj4;
	std::vector<Pobject*> Pobj5;
	std::vector<Pobject*> Pobj6;
	std::vector<Pobject*> Pobj7;
	std::vector<Pobject*> Pobj8;
	std::vector<Pobject*> Pobj9;
	std::vector<Pobject*> Pobj10;		
	std::vector<Pobject*> Pobj11;
	std::vector<Pobject*> Pobj17;
	objloader objLoad;
	 vector3d col;
	 vector3d amb;
	 vector3d dif;
	 vector3d posLight;
int nTue;
bool keyup,keydown,keyright,keyleft,cc;
int keyw;
int width_;
int height_;
std::vector<prefab*> pref;
std::vector<prefabAnim*> prefAnim;
bool lanchGame;
std::vector<hud*> hud_;
std::vector<skybox*> sky;
float time;
objloader obj_;
bool physicsMode;
int look,look2,look3;
std::vector<unsigned int>anim;
bool link;

};


#endif

