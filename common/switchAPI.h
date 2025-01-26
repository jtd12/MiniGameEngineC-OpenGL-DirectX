#ifndef DEF_SWITCHAPI
#define DEF_SWITCHAPI
#include <iostream>
#include<windows.h>
#include"../OpenGL/API_OPENGL.h"
#include"../OpenGL/menu/menu.h"
#include"../DirectX/API_DIRECTX.h"
#include"../MenuContext/windows.h"

void reshape(int width,int height);
void fenetre1();
void fenetre2();
void fenetre3();
void fenetre4();
void keyboardInput(unsigned char key,int x,int y);
void passiveKeyboard(unsigned char key,int x,int y);
void passiveMouse(int x,int y);
void mouseMotion(int x, int y);
void specialKey(int key,int x, int y);
void specialKey4(int key,int x, int y);
void mouse(int button, int state, int x, int y);
void mouseWheel(int, int, int, int);
void mouseWheel2(int, int, int, int);
void mouseWheel3(int, int, int, int);
void mouseWheel4(int, int, int, int);
void mouse2(int button, int state, int x, int y);
void mouse3(int button, int state, int x, int y);
void mouse4(int button, int state, int x, int y);
void mouseMotion2(int x, int y);
void mouseMotion3(int x, int y);
void mouseMotion4(int x, int y);
void passiveSpecialKeyboard(int key,int x, int y);




class API
{
public:
API();
~API();
void initAPIOpenGL();
bool initAPIDirectX();
bool initAPIDirectX11();
void update(float gameTime,APIDIRECTX9 * game);
void incrementerX(vector3d inc);
void incrementerY(vector3d inc);
void incrementerZ(vector3d inc);
void addCube();
void addTeapot();
void addSphere();
void addCylinder();
void addPlane();
bool getLoadCube();
void setLoadCube(bool l);
void scaleX(vector3d s);
void scaleY(vector3d s);
void scaleZ(vector3d s);
void rotX(vector3d r);
void rotY(vector3d r);
void rotZ(vector3d r);
void draw(APIDIRECTX9 * game,float gameTime);
void draw2(APIDIRECTX9 * game,float gameTime);
void draw3(APIDIRECTX9 * game,float gameTime);
void draw4(APIDIRECTX9 * game,float gameTime);
void setAmbiantX(vector3d amb);
void setAmbiantY(vector3d amb);
void setAmbiantZ(vector3d amb);
void setColorX(vector3d col);
void setColorY(vector3d col);
void setColorZ(vector3d col);
void setEmissiveX(vector3d emmis);
void setEmissiveY(vector3d emmis);
void setEmissiveZ(vector3d emmis);
void setSpecularX(vector3d spec);
void setSpecularY(vector3d spec);
void setSpecularZ(vector3d spec);
void setDist(float d);
void setPower(float pow);
void setAlpha(float alph);
void bg_colorX(float bg_cX);
void bg_colorY(float bg_cY);
void bg_colorZ(float bg_cZ);
void setIncX(bool b);
void setIncY(bool b);
void setIncZ(bool b);
void setRotX(bool b);
void setRotY(bool b);
void setRotZ(bool b);
void setRotXNeg(bool b);
void setRotYNeg(bool b);
void setRotZNeg(bool b);
void setIncXNeg(bool b);
void setIncYNeg(bool b);
void setIncZNeg(bool b);
void setScale_x(bool b);
void setScale_y(bool b);
void setScale_z(bool b);
void setScale_x_neg(bool b);
void setScale_y_neg(bool b);
void setScale_z_neg(bool b);
void setColorX_(bool b);
void setColorY_(bool b);
void setColorZ_(bool b);
void setColorX_neg(bool b);
void setColorY_neg(bool b);
void setColorZ_neg(bool b);
void setAmbiantX_(bool b);
void setAmbiantY_(bool b);
void setAmbiantZ_(bool b);
void setAmbiantX_neg(bool b);
void setAmbiantY_neg(bool b);
void setAmbiantZ_neg(bool b);
void setSpecularX_(bool b);
void setSpecularY_(bool b);
void setSpecularZ_(bool b);
void setSpecularX_neg(bool b);
void setSpecularY_neg(bool b);
void setSpecularZ_neg(bool b);
void setEmmissiveX_(bool b);
void setEmmissiveY_(bool b);
void setEmmissiveZ_(bool b);
void setEmmissiveX_neg(bool b);
void setEmmissiveY_neg(bool b);
void setEmmissiveZ_neg(bool b);
void setAlpha_(bool b);
void setPower_(bool b);
void setAlpha_neg(bool b);
void setPower_neg(bool b);
void setbg_colX(bool b);
void setbg_colY(bool b);
void setbg_colZ(bool b);
void setDist_(bool b);
void setDist_neg(bool b);
void setbg_colXNeg(bool b);
void setbg_colYNeg(bool b);
void setbg_colZNeg(bool b);
void controlCamera();
void setControlCamUp(bool b);
void init_input(HWND hWnd);
void setControlCam(bool b);
void setControlCamLateral(bool b);
void setControlScrollWithCamUP(float movementZ);
void setControlScrollWithCamUP2(float movementZ);
void setControlScrollWithCamUP3(float movementZ);
void setControlScrollWithCamUP4(float movementZ);
void operationTransformationObject();
void eraseObjectCube(APIDIRECTX9 * game);
void  setPhysicsMode(APIDIRECTX9 * game,bool b);
void  setStart(APIDIRECTX9 * game,bool b);
void  setQuit(APIDIRECTX9 * game,bool b);
void  setCharacterMode(APIDIRECTX9 * game,bool b);
void  setDriveMode(APIDIRECTX9 * game,bool b);
void  setDynamicMode(APIDIRECTX9 * g,bool b);
void  setStaticMode(APIDIRECTX9 * game,bool b);
bool  getControlCamUp();
bool  getControlCamLateral();
HWND  getHWND();
HWND  getHWND2();
HWND  getHWND3();
HWND  getHWND4();
APIDIRECTX9 * game;
APIDIRECTX9 * game2;
APIDIRECTX9 * game3;
APIDIRECTX9 * game4;

private:
vector3d bg_color;
vector3d translate;
vector3d rotate;
vector3d scale;
vector3d color;
vector3d ambiant;
vector3d specular;
vector3d emissive;
int windowName;
int windowName2;
int windowName3;
int windowName4;
HWND hwnd;
HWND hwnd2;
HWND hwnd3;
HWND hwnd4;
float alpha,power;
bool incX,incY,incZ,scale_x,scale_y,scale_z,scale_x_neg,scale_y_neg,scale_z_neg,rot_x,rot_y,rot_z,colorX,colorY,colorZ,colorX_neg,colorY_neg,colorZ_neg,ambiantX,ambiantY,ambiantZ,ambiantX_neg,ambiantY_neg,ambiantZ_neg,specularX,specularY,specularZ,
specularX_neg,specularY_neg,specularZ_neg,emmissiveX,dist,dist_neg,
emmissiveY,emmissiveZ,emmissiveX_neg,
emmissiveY_neg,emmissiveZ_neg,power_,power_neg,alpha_,alpha_neg,rot_xNeg,rot_yNeg,rot_zNeg,bg_colX,bg_colY,bg_colZ,bg_colXNeg,bg_colYNeg,bg_colZNeg,inc_xNeg,inc_yNeg,inc_zNeg;
bool controlCam;
bool controlCamUp;
bool controlCamLateral;
POINT MousePos;




			
};
#endif
