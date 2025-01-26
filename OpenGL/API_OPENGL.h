#ifndef DEF_SETUP_H
#define DEF_SETUP_H
#include <windows.h>
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include <gl\glaux.h>         // fonctions AUX Library
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<time.h>
#include"entities/grid.h"
#include"entities/pointer.h"
#include"entities/camera.h"
#include"menu/menu.h"
#include"entities/prefab.h"
#include"entities/prefabAnim.h"
#include"menu/hud.h"
#include"entities/skybox.h"
#include"mathsutils/collision.h"
#include"entities/boundingbox.h"
#include"loader/objloader.h"
#include"entities/proceduralObject.h"
#include"projections/projections.hpp"
#include"Data/datas.hpp"
#include"skybox/skyboxGeneration.hpp"
#include"gameMode/gameMode.hpp"
using namespace std;

class APIOPENGL
{
	
public:
 APIOPENGL();
 ~APIOPENGL();
 void update();
 void reshape(int width,int height);
 void reshapeOrtho(int width,int height);
 void passiveMotion(int x, int y);
 void show();
 void show2();
 void show3();
 void show4();
 void passiveKeyboard(char key,int x,int y);
void clavierActif();
void initGL();
void controlKeyboard(char key,int x, int y);
void mouseMotion(int x,int y);
void controlSpecialKeyboard(int key,int x, int y);
void passiveSpecialKeyboard(int key,int x, int y);
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
bool startG();
std::string getFileName();
bool copyFile(const char *SRC, const char* DEST);
bool copy();
void saveToFile();
void loadToFile();


private:

bool mi;
 float mousevel;
 float camYaw;
 float camPitch;
 float pitch;
 float xpos,ypos,zpos;
  int Nom;
int useStencil; 
	pointer *p;
  grid *g;
 bool space;
 bool mtouc;
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
	 boundingbox * b;
	 std::string fileName[15];
int nTue;
bool keyup,keydown,keyright,keyleft,cc;
int keyw;
std::vector<prefab*> pref;
std::vector<prefabAnim*> prefAnim;
std::vector<hud*> hud_;
objloader objLoad;
objloader obj_;
std::vector<unsigned int>anim;
view* view_;
datas* data_;
vector3d col;
generateSkybox* sky;
gameMode* gameMode_;

};


#endif

