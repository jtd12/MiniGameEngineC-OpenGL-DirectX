#include"projections.hpp"

view::view()
{
	sky=new generateSkybox();
	nearPlane=0.1f;
	farPlane=1500.0f;
	angle=60.0f;
}

view::~view()
{
	delete sky;
}

float view::getAngle()
{
	return angle;
}

float view::getNearPlane()
{
	return nearPlane;
}
float view::getFarPlane()
{
	return farPlane;
}
void view::focal()
{
	if(value==2200)
	{
		angle+=1.0f;
	}
	if(value==2250)
	{
		angle-=1.0f;
	}
	if(value==2300)
	{
		nearPlane+=0.5f;
	}
	if(value==2350)
	{
		nearPlane-=0.5f;
	}
	if(value==2400)
	{
		farPlane+=0.5f;
	}
	if(value==2450)
	{
		farPlane-=0.5f;
	}
}

void view::reshape(int width,int height)
{

width_=width;
height_=height;
glViewport(0,0,width_,height_);// definition de la taille d'affichage de l'angle de la camera
glMatrixMode(GL_PROJECTION);// on chosit le mode projection de la matrice 
glLoadIdentity();// on initialise la matrice
gluPerspective(angle,float (width_)/float (height_),nearPlane,farPlane); // on dit qu'on travaille en mode perspective avec une focale et un point de vue
//gluOrtho2D(-1.0*(width/height), 1.0*(width/height), -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);// on change de mode d'affichage, on reload une nouvelle matrice de transformation de modelisation
glEnable(GL_DEPTH_TEST);	//Active le depth test
glClearColor(sky->getCol().x,sky->getCol().y,sky->getCol().z,1.0);	//Change la couleur du fond
 
}

void view::reshapeOrtho(int width,int height)
{

glViewport(0,0,width_,height_);// definition de la taille d'affichage de l'angle de la camera
glMatrixMode(GL_PROJECTION);// on chosit le mode projection de la matrice 
glLoadIdentity();// on initialise la matrice
glOrtho(-40,40,-40,40,0.1,4000);
glMatrixMode(GL_MODELVIEW);// on change de mode d'affichage, on reload une nouvelle matrice de transformation de modelisation
glEnable(GL_DEPTH_TEST);	//Active le depth test
glClearColor(sky->getCol().x,sky->getCol().y,sky->getCol().z,1.0);	//Change la couleur du fond
}

