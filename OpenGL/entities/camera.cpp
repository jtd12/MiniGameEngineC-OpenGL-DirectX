#include"camera.h"

camera::camera()
{
	camYaw=0.0f;
	mousevel=0.2f;
	movevel=0.5f;
	mi=false;
	mi2=false;
	MidX=320;
	MidY=240;
}
camera::~camera()
{
	
}
void camera::moveCamera(float dir)
{
	float rad=(camYaw+dir)*M_PI/180.0;

	
	loc.x-=cos(rad)*movevel;
	loc.z+=sin(rad)*movevel;


}
void camera::lockCamera()
{
	if(camPitch>90)
		camPitch=90;
	if(camPitch<-90)
		camPitch=-90;
	if(camYaw<0.0)
		camYaw+=360.0;
	if(camYaw>360.0)
		camYaw-=360;
}

void camera::moveLateral(float dir,float x,float y)
{

	if(mi2)
	{
		float rad=(camYaw+dir)*M_PI/180.0;

		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	

		
 		loc.x-=sin(rad)*(MidX-x)*mousevel*0.02f;
 		loc.z-=cos(rad)*(MidX-x)*mousevel*0.02f;
 		loc.y-=(MidY-y)*mousevel*0.02f;
 	
 
 

 	
 		 glutWarpPointer(MidX,MidY);
 }
}
void camera::moveCameraUp(float dir)
{
	float rad=(camPitch+dir)*M_PI/180.0;
	loc.y-=sin(rad)*movevel;
		
}

void camera::control(int x,int y)
{
		
if(mi)
{
		glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	lockCamera();
		camYaw+=mousevel*(MidX-x);
		camPitch+=mousevel*(MidY-y);
		 glutWarpPointer(MidX,MidY);
	}

	else
	{
	
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}
	
}
void camera::update()
{
	glRotated(-camPitch,0,0,1);
	glRotated(-camYaw,0,1,0);
	glTranslated(-loc.x,-loc.y,-loc.z);
	
}
void camera::setLocation(vector3d l)
{
	loc=l;
}
vector3d camera::getLocation()
{
	return loc;
}
void camera::mouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON)
	{
	mi=true;
	}
		else if(state==GLUT_DOWN && button==GLUT_RIGHT_BUTTON)
	{
	mi2=true;
	}
else
	{
		mi2=false;
		mi=false;
	
	}
	
	

	

}

void camera::setMouseVel(float speed)
{
	movevel+=speed;
	if(	movevel>2.0f)
	{
			movevel=2.0f;
	}
		if(	movevel<0.0f)
	{
			movevel=0.0f;
	}
}

	

float camera::getMouseVel()
{
	return mousevel;
}
