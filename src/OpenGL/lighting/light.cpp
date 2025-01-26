#include"light.hpp"

light::light(pointer* pp)
{
	p=pp;
	amb=vector3d(0.5,0.5,0.5);
	dif=vector3d(0.5,0.5,0.5);
	posLight=vector3d(20.0f,5.0f,20.0f);
}
light::~light()
{
	delete p;
}

void light::lighting()
{
			GLfloat ambient[] = {amb.x,amb.y,amb.z};
            GLfloat diffuse[] = {dif.x,dif.y,dif.z};
            GLfloat light0_position [] = {posLight.x, posLight.y, posLight.z};
            GLfloat specular_reflexion[] = {0.8f,0.8f,0.8f,1.0f};
            
			glPushMatrix();
			glTranslated(posLight.x,posLight.y,posLight.z);
            glLineWidth(2.9);
			glBegin(GL_LINES);
			glColor3f(0.8,0.8,0.0);
			glVertex3f(-0.1,0,0);
			glVertex3f(-0.1,10,0);
			glEnd();
            glPopMatrix();
            GLubyte shiny_obj = 128;           //positionnement de la lumière avec les différents paramètres
            glEnable(GL_LIGHTING);
            glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
            glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
            glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
            glEnable(GL_LIGHT0);

                         //spécification de la réflexion sur les matériaux
            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular_reflexion);
            glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,shiny_obj);
            
}

void light::lightAmb()
{
	if(value==2500)
	{
		amb.x+=0.05f;
	}
	if(value==2550)
	{
		amb.x-=0.05f;
	}
	if(value==2600)
	{
		amb.y+=0.05f;
	}
	if(value==2650)
	{
		amb.y-=0.05f;
	}
	if(value==2700)
	{
		amb.z+=0.05f;
	}
	if(value==2750)
	{
		amb.z-=0.05f;
	}
}
void light::lightDiffuse()
{
	if(value==2500)
	{
		dif.x+=0.05f;
	}
	if(value==2550)
	{
		dif.x-=0.05f;
	}
	if(value==2600)
	{
		dif.y+=0.05f;
	}
	if(value==2650)
	{
		dif.y-=0.05f;
	}
	if(value==2700)
	{
	dif.z+=0.05f;
	}
	if(value==2750)
	{
		dif.z-=0.05f;
	}
}

void light::moveLight()
{
	if(value==3100 && selectObject(p->getLocation(),posLight,vector3d(0.5,0.5,0.5),5))
	{
		 posLight=vector3d(p->getLocation().x,posLight.y,posLight.z);
	}
	if(value==3200 && selectObject(p->getLocation(),posLight,vector3d(0.5,0.5,0.5),5))
	{
		 posLight=vector3d(posLight.x,p->getLocation().y,posLight.z);
	}
	if(value==3300 && selectObject(p->getLocation(),posLight,vector3d(0.5,0.5,0.5),5))
	{
		 posLight=vector3d(posLight.x,posLight.y,p->getLocation().z);
	}
		if(value==3400 && selectObject(p->getLocation(),posLight,vector3d(0.5,0.5,0.5),5))
	{
		 posLight=vector3d(p->getLocation().x,p->getLocation().y,p->getLocation().z);
	}
}

bool light::selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_)
{
	float dist=(sqrt(((objectPointer.x-objectReference.x)*(objectPointer.x-objectReference.x))+((objectPointer.y-objectReference.y)*(objectPointer.y-objectReference.y))+
	((objectPointer.z-objectReference.z)*(objectPointer.z-objectReference.z))));
	if(dist<dist_)
	{
		
		return true;
	}
	return false;
}

