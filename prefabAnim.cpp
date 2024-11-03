#include"prefabAnim.h"

prefabAnim::prefabAnim(const char * n,vector3d vec,vector3d r,vector3d s)
{
	curFrame=1;
	loc=vec;
	obj.loadAnimation(frames, "data/player/player",31);
	name=n;
	rot.x=r.x;
	rot.y=r.y;
	rot.z=r.z;
	scale.x=s.x;
	scale.y=s.y;
	scale.z=s.z;
	b=new boundingbox();
	speed=0.01f;
	walk=false;
	dynamic=false;
	link=false;
}
	prefabAnim::~prefabAnim()
	{
	delete b;
	}
	void prefabAnim::update(bool up,bool down)
	{
		if(up)
		{
		
	curFrame+=0.1f;
		if(curFrame>=31)
			curFrame=1;
		}
		else if(down)
		{
			curFrame+=0.1f;
		if(curFrame>=31)
			curFrame=1;
		}	
		
		else
		{
		  curFrame=1;
	}
	
	}
void prefabAnim::show()
{
		
		 
	

	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glRotated(rot.x,0.5,0,0);
	glRotated(rot.y,0.0,0.5,0);
	glRotated(rot.z,0.0,0,0.5);
	glScaled(scale.x,scale.y,scale.z);
	glCallList(frames[curFrame]);
	glTranslated(0,3,0);
	glScaled(2,5,2);
	b->drawCube();
	glPopMatrix();
}
void prefabAnim::setLocation(vector3d l)
{
	loc=l;
}
void prefabAnim::setLocationIncrement(vector3d l)
{
	loc+=l;
}

vector3d prefabAnim::getLocation()
{
	return loc;
}
void  prefabAnim::setRotation(vector3d r)
{
	rot+=r*2.5f;
}
vector3d  prefabAnim::getRotation()
{
	return rot;
}
void  prefabAnim::setScale(vector3d r)
{
	scale+=r*2.5f;

}
vector3d  prefabAnim::getScale()
{
	return scale;
}

void prefabAnim::physics()
{
		vector3d newPos(loc);
			      	newPos.y-=0.2f;
			       setLocation(newPos);	
}
void prefabAnim:: movement(bool up,bool down, bool right, bool left)
{
if(up)
{
		loc.x+=cos(rot.y*M_PI/180.0)*speed;
	loc.z-=sin(rot.y*M_PI/180.0)*speed;
	}	
	if(down)
	{
		loc.x-=cos(rot.y*M_PI/180.0)*speed;
	loc.z+=sin(rot.y*M_PI/180.0)*speed;
	}
	if(right)
	{
		rot.y-=0.05f;
	}
	if(left)
	{
		rot.y+=0.05f;
	}
}

bool prefabAnim::getWalk()
{
	return walk;
}
void prefabAnim::setWalk(bool b)
 {
 	walk=b;
 }

void prefabAnim::setDynamic(bool b)
{
	dynamic=b;
}
bool prefabAnim::getDynamic()
{
	return dynamic;
}

