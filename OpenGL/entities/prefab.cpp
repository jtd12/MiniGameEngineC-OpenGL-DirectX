#include"prefab.h"

prefab::prefab(const char * n,const std::string& filename,vector3d vec,vector3d r,vector3d s)
{
	loc=vec;
	mesh=obj.load(filename);
	r_.push_back(new roue("roue","data/roue.obj",loc));
	r_.push_back(new roue("roue","data/roue.obj",loc));
	r_.push_back(new roue("roue","data/roue.obj",loc));
	r_.push_back(new roue("roue","data/roue.obj",loc));
	p.push_back(new porte("porte","data/porte.obj",loc));
	p.push_back(new porte("porte","data/porte2.obj",loc));
	//p=new roue("porte","data/porte.obj",loc);
	name=n;
	rot.x=r.x;
	rot.y=r.y;
	rot.z=r.z;
	scale.x=s.x;
	scale.y=s.y;
	scale.z=s.z;
	speed=0.0f;
	maxSpeed=0.5f;
	acc=0.02f;
	dec=0.08f;
	angle=80;
	turnSpeed=0.4;
	b=new boundingbox();
	drive=false;
	dynamic=false;
	link=false;
}


prefab::~prefab()
{
	for(int i=0;i<p.size();i++)
	delete p[i];
	for(int i=0;i<r_.size();i++)
	delete r_[i];
	delete b;
}
void prefab::update()
{
}
void prefab::showB()
{
	glPushMatrix();
	glScaled(2,1,1);
		b->drawCube();
		glPopMatrix();
}
void prefab::show()
{
	
	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glRotated(rot.x,0.5,0,0);
	glRotated(rot.y,0.0,0.5,0);
	glRotated(rot.z,0.0,0,0.5);
	glScaled(scale.x,scale.y,scale.z);
	glCallList(mesh);
	showB();
	drawRoue();
	drawPorte();
	glPopMatrix();

}
void prefab::drawRoue()
{
	glPushMatrix();	
	glRotated(r_[0]->getRotation().z,0,0,0.5);
	r_[0]->show();
	glPopMatrix();
	glPushMatrix();	
	glRotated(r_[1]->getRotation().z,0,0,0.5);
	r_[1]->show();
	glPopMatrix();
	glPushMatrix();	
	glRotated(r_[2]->getRotation().z,0,0,0.5);
	r_[2]->show();
	glPopMatrix();
	glPushMatrix();	
	glRotated(r_[3]->getRotation().z,0,0,0.5);
	r_[3]->show();
	glPopMatrix();
}
void prefab::drawPorte()
{
	glPushMatrix();	
	glRotated(p[0]->getRotation().y,0,0.5,0);
	p[0]->show();
	glPopMatrix();
	glPushMatrix();	
	glRotated(p[1]->getRotation().y,0,0.5,0);
	p[1]->show();
	glPopMatrix();	
}
void prefab::setLocation(vector3d l)
{
	loc=l;
}
void prefab::setLocationIncrement()
{

	loc.x-=cos(rot.y*M_PI/180.0)*speed;
	loc.z+=sin(rot.y*M_PI/180.0)*speed;

}

void prefab::setLocationIncrement2(vector3d pos)
{
	loc+=pos;
}

vector3d prefab::getLocation()
{
	return loc;
}

void  prefab::setRotation(vector3d r)
{
	rot+=r*2.5f;
}
vector3d  prefab::getRotation()
{
	return rot;
}
void  prefab::setScale(vector3d r)
{
	scale+=r*2.5f;

}
vector3d  prefab::getScale()
{
	return scale;
}
bool prefab::getDrive()
{
	return drive;
}
void prefab::setDrive(bool b)
 {
 	drive=b;
 }
void prefab::movement(bool up,bool down, bool right, bool left)
{
	
				
			/*
			      vector3d newPos(loc);
			      	newPos.y-=0.2f;
		
			
			  setLocation(newPos);
			  if(newPos.y<0)
			loc.y=0;
			*/
		
			if(up==1 && speed<maxSpeed)
			{
			
				if(speed<0)
				{
					speed+=dec;
				}
				else
				{
					speed+=acc;
				}
			}
			if(down==1 && speed>-maxSpeed)
			{
				
				if(speed>0)
				{
					speed-=dec;
				}
				else
				{
					speed-=acc;
				}
				
			}
			
			if(up==0 && down==0)
			{
				if(speed-dec>0)
				{
					speed-=dec;
				}
				else if(speed+dec<0)
				{
					speed+=dec;
				}
				else
				{
					speed=0;
				}
			}
			if(right && speed!=0)
			{
				rot.y-=turnSpeed*speed/maxSpeed;
			}
				if(left && speed!=0)
			{
				rot.y+=turnSpeed*speed/maxSpeed;
			}
			
			
		
			setLocationIncrement();
			
	
}
void prefab::physics()
{

		vector3d newPos(loc);
			      	newPos.y-=0.2f;
			       setLocation(newPos);	
			   
}

void prefab::setDynamic(bool b)
{
	dynamic=b;
}
bool prefab::getDynamic()
{
	return dynamic;
}
 
void prefab::setLink(bool b)
{
	link=b;
}

