#include"proceduralObject.h"

Pobject::Pobject()
{
	loc.x=0;
	loc.y=0;
	loc.z=0;
	col.x=0.5;
	col.y=0.8;
	col.z=0.8;
	rot.x=0;
	rot.y=0;
	rot.z=0;
	scale.x=1.0;
	scale.y=1.0;
	scale.z=1.0;
	dynamic=false;
	collid=false;

}
Pobject::Pobject(const char* c,unsigned int map , vector3d l,vector3d couleur,vector3d r,vector3d s)
{
	scale.x=s.x;
	scale.y=s.y;
	scale.z=s.z;
	rot.x=r.x;
	rot.y=r.y;
	rot.z=r.z;
	loc.x=l.x;
	loc.y=l.y;
	loc.z=l.z;
	col.x=couleur.x;
	col.y=couleur.y;
	col.z=couleur.z;
	mesh=map;
	name=c;
//	b=new boundingbox(vector3d(1,1,1),vector3d(-1,-1,-1));
	dynamic=false;
	b=new boundingbox();

	collid=false;

}
Pobject::~Pobject()
{
delete b;

}
void Pobject::update()
{   

 



}
void Pobject::drawObject()
{



	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glRotated(rot.x,0.5,0,0);
	glRotated(rot.y,0.0,0.5,0);
	glRotated(rot.z,0.0,0,0.5);
	glScaled(scale.x,scale.y,scale.z);
	glCallList(mesh);
	glPopMatrix();
	
}


void Pobject::setLocation(vector3d l)
{
	loc=l;
}
void Pobject::setLocationIncrement(vector3d l)
{
	loc+=l;
}
vector3d Pobject::getLocation()
{
	return loc;
}
void Pobject::setCouleur(vector3d couleur)
{
	col=couleur;
}
void Pobject::setCouleurInc(vector3d couleur)
{
	col+=couleur;
}
vector3d Pobject::getCouleur()
{
	return col;
}
void Pobject::setRotation(vector3d r)
{
	rot+=r;
}
vector3d Pobject::getRotation()
{
	return rot;
}
void  Pobject::setScale(vector3d r)
{
	
	scale+=r;

}
vector3d  Pobject::getScale()
{
	return scale;
}

vector3d Pobject::getP1()
{
	return p1;
}
vector3d Pobject::getP2()
{
	return p2;
}
vector3d Pobject::getP3()
{
	return p3;
}
vector3d Pobject::getP4()
{
	return p4;
}
vector3d Pobject::getP5()
{
	return p5;
}
vector3d Pobject::getP6()
{
	return p6;
}
vector3d Pobject::getP7()
{
	return p7;
}
vector3d Pobject::getP8()
{
	return p8;
}
vector3d Pobject::getP9()
{
	return p9;
}
vector3d Pobject::getP10()
{
	return p10;
}
vector3d Pobject::getP11()
{
	return p11;
}
vector3d Pobject::getP12()
{
	return p12;
}
vector3d Pobject::getP13()
{
	return p13;
}
vector3d Pobject::getP14()
{
	return p14;
}
vector3d Pobject::getP15()
{
	return p15;
}
vector3d Pobject::getP16()
{
	return p16;
}
vector3d Pobject::getP17()
{
	return p17;
}
vector3d Pobject::getP18()
{
	return p18;
}
vector3d Pobject::getP19()
{
	return p19;
}
vector3d Pobject::getP20()
{
	return p20;
}
vector3d Pobject::getP21()
{
	return p21;
}
vector3d Pobject::getP22()
{
	return p22;
}
vector3d Pobject::getP23()
{
	return p23;
}
vector3d Pobject::getP24()
{
	return p24;
}
void Pobject::setP1(vector3d p1_)
{
	p1=p1_;
}
void Pobject::setP2(vector3d p2_)
{
	p2=p2_;
}
void Pobject::setP3(vector3d p3_)
{
	p3=p3_;
}
void Pobject::setP4(vector3d p4_)
{
	p4=p4_;
}
void Pobject::dynamique()
{
	
					vector3d newPos(loc);
			      	newPos.y-=0.2f;
			       setLocation(newPos);
			       
			     
			       
}

void Pobject::setDynamic(bool b)
{
	dynamic=b;
}
bool Pobject::getDynamic()
{
	return dynamic;
}
void Pobject::setCollision(bool b)
{
	collid=b;
}
bool Pobject::getCollision()
{
	return collid;
}


