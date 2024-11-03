#include"roue.h"



roue::roue(const char * n,const std::string& filename,vector3d vec)
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


roue::~roue()
{
	delete b;
}
void roue::update()
{
}
void roue::showB()
{
	glPushMatrix();
	glScaled(0.5,0.5,0.5);
		b->drawCube();
		glPopMatrix();
}
void roue::show()
{
	glPushMatrix();
	showB();
	glCallList(mesh);
	glPopMatrix();
}

void roue::setLocation(vector3d l)
{
	loc=l;
}
void roue::setLocationIncrement(vector3d l)
{
	loc+=l;
}
vector3d roue::getLocation()
{
	return loc;
}
void  roue::setRotation(vector3d r)
{
	rot=r;
}
void  roue::setRotationIncrement(vector3d r)
{
	rot+=r;
}
vector3d  roue::getRotation()
{
	return rot;
}
void  roue::setScale(vector3d r)
{
	scale=r;

}
vector3d  roue::getScale()
{
	return scale;
}

