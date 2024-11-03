#include"porte.h"



porte::porte(const char * n,const std::string& filename,vector3d vec)
{
	loc=vec;
	mesh=obj.load(filename);
	name=n;
	rot.x=0;
	rot.y=0;
	rot.z=0;
	scale.x=1.0;
	scale.y=1.0;
	scale.z=1.0;
	b=new boundingbox();
}


porte::~porte()
{
	delete b;
	
}
void porte::update()
{
}
void porte::showB()
{
	glPushMatrix();
	glScaled(0.9,0.5,0.5);
		b->drawCube();
		glPopMatrix();
}
void porte::show()
{
	glPushMatrix();
	showB();
	glCallList(mesh);
	glPopMatrix();
}

void porte::setLocation(vector3d l)
{
	loc=l;
}
void porte::setLocationIncrement(vector3d l)
{
	loc+=l;
}
vector3d porte::getLocation()
{
	return loc;
}
void  porte::setRotation(vector3d r)
{
	rot=r;
}
void  porte::setRotationIncrement(vector3d r)
{
	rot+=r;
}
vector3d  porte::getRotation()
{
	return rot;
}
void  porte::setScale(vector3d r)
{
	scale=r;

}
vector3d  porte::getScale()
{
	return scale;
}

