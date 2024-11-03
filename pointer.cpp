#include"pointer.h"

pointer::pointer()
{
	loc.x=0;
	loc.y=0;
	loc.z=0;
	scale.x=1.0;
	scale.y=1.0;
	scale.z=1.0;
	
}
pointer::pointer(vector3d c)
{
	loc.x=c.x;
	loc.y=c.y;
	loc.z=c.z;
	scale.x=1.0;
	scale.y=1.0;
	scale.z=1.0;
}
pointer::~pointer()
{
}
void pointer::update()
{
	glTranslated(-13,0,-45);
glRotated(40,1,1,0);
}
void pointer::show()
{
	glPushMatrix();
	glColor3f(0.2,0.4,1);
	glTranslated(loc.x,loc.y,loc.z);
//	glRotated(rot.x,0.5,0,0);
//	glRotated(rot.y,0,0.5,0);
	//glRotated(rot.z,0,0,0.5);
	//glScaled(scale.x,scale.y,scale.z);
	glColor3d(0.2,0.8,0.8);
	glutSolidCube(2.0f);
	glLineWidth(0.2);
	glBegin(GL_LINES);
		glColor3f(0.7,0.5,0.9);
		glVertex3f(-0.1,0,0);
		glVertex3f(-0.1,19,0);
		glEnd();
			glLineWidth(0.2);
		glBegin(GL_LINES);
		glColor3f(0.9,0.1,0.1);
		glLineWidth(50);
		glVertex3f(0,-0.1,0);
		glVertex3f(19,-0.1,0);
		glEnd();
			glLineWidth(0.2);
		glBegin(GL_LINES);
		glColor3f(0.1,0.9,0.1);
		glLineWidth(50);
		glVertex3f(0,-0.1,0);
		glVertex3f(0,-0.1,19);
		glEnd();
		glPopMatrix();

}
void pointer::setLocationIncrement(vector3d l)
{
	loc+=l;
}
void pointer::setLocation(vector3d l)
{
	loc=l;
}
vector3d pointer::getLocation()
{
	return loc;
}
void pointer::setRotation(vector3d r)
{
	rot+=r;
}
vector3d pointer::getRotation()
{
	return rot;
}
void  pointer::setScale(vector3d r)
{
	scale=r;

}
void  pointer::setScaleIncrement(vector3d r)
{
	scale+=r;

}

vector3d  pointer::getScale()
{
	return scale;
}
