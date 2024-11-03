#include"object.h"

object::object()
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
	scale.x=5.0;
	scale.y=5.0;
	scale.z=5.0;
	dynamic=false;

	
}
object::object(vector3d l,vector3d couleur,vector3d r,vector3d s)
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
//	b=new boundingbox(vector3d(1,1,1),vector3d(-1,-1,-1));
	dynamic=false;
	b=new boundingbox();
	speed=0.0f;
	speed2=0.2f;
	maxSpeed=0.5f;
	acc=0.02f;
	dec=0.08f;
	angle=80;
	turnSpeed=0.4;
	drive=false;
//	link=false;
	walk=false;

}
object::~object()
{
	delete b;

}
void object::update()
{   

 
 
    
	p1=vector3d(b->getMax().x+loc.x,b->getMin().y+loc.y,b->getMin().z+loc.z);
	p2=vector3d(b->getMax().x+loc.x,b->getMin().y+loc.y,b->getMax().z+loc.z);
	p3=vector3d(b->getMax().x+loc.x,b->getMax().y+loc.y,b->getMax().z+loc.z);
	p4=vector3d(b->getMax().x+loc.x,b->getMax().y+loc.y,b->getMin().z+loc.z);
	
	p5=vector3d(b->getMin().x+loc.x,b->getMax().y+loc.y,b->getMin().z+loc.z);
	p6=vector3d(b->getMin().x+loc.x,b->getMax().y+loc.y,b->getMax().z+loc.z);
	p7=vector3d(b->getMin().x+loc.x,b->getMin().y+loc.y,b->getMax().z+loc.z);
	p8=vector3d(b->getMin().x+loc.x,b->getMin().y+loc.y,b->getMin().z+loc.z);
	
	p9=vector3d(b->getMax().x+loc.x,b->getMin().y+loc.y,b->getMax().z+loc.z);
	p10=vector3d(b->getMax().x+loc.x,b->getMax().y+loc.y,b->getMax().z+loc.z);
	p11=vector3d(b->getMin().x+loc.x,b->getMax().y+loc.y,b->getMax().z+loc.z);
	p12=vector3d(b->getMin().x+loc.x,b->getMin().y+loc.y,b->getMax().z+loc.z);
	
	p13=vector3d(b->getMax().x+loc.x,b->getMax().y+loc.y,b->getMin().z+loc.z);
	p14=vector3d(b->getMax().x+loc.x,b->getMin().y+loc.y,b->getMin().z+loc.z);
	p15=vector3d(b->getMin().x+loc.x,b->getMin().y+loc.y,b->getMin().z+loc.z);
	p16=vector3d(b->getMin().x+loc.x,b->getMax().y+loc.y,b->getMin().z+loc.z);
	
	p17=vector3d(b->getMax().x+loc.x,b->getMax().y+loc.y,b->getMin().z+loc.z);
	p18=vector3d(b->getMax().x+loc.x,b->getMax().y+loc.y,b->getMax().z+loc.z);
	p19=vector3d(b->getMin().x+loc.x,b->getMax().y+loc.y,b->getMax().z+loc.z);
	p20=vector3d(b->getMin().x+loc.x,b->getMax().y+loc.y,b->getMin().z+loc.z);
	
	p21=vector3d(b->getMin().x+loc.x,b->getMin().y+loc.y,b->getMin().z+loc.z);
	p22=vector3d(b->getMin().x+loc.x,b->getMin().y+loc.y,b->getMax().z+loc.z);
	p23=vector3d(b->getMax().x+loc.x,b->getMin().y+loc.y,b->getMax().z+loc.z);
	p24=vector3d(b->getMax().x+loc.x,b->getMin().y+loc.y,b->getMin().z+loc.z);
	
	b->setMin(vector3d(-scale.x*0.5,-scale.y*0.5,-scale.z*0.5));
	b->setMax(vector3d(scale.x*0.5,scale.y*0.5,scale.z*0.5));



}
void object::drawCube()
{



	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glRotated(rot.x,0.5,0,0);
	glRotated(rot.y,0.0,0.5,0);
	glRotated(rot.z,0.0,0,0.5);
	glScaled(scale.x,scale.y,scale.z);
	glColor3d(col.x,col.y,col.z);
	glutSolidCube(1);
	drawLines();
	glPopMatrix();
	
	
}
void object::drawTeapot()
{
	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glRotated(rot.x,0.5,0,0);
	glRotated(rot.y,0.0,0.5,0);
	glRotated(rot.z,0.0,0,0.5);
	glScaled(scale.x,scale.y,scale.z);
	glColor3d(col.x,col.y,col.z);

	glutSolidTeapot(1);
	drawLines();
	glPopMatrix();
}
void object::drawSphere()
{
	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glRotated(rot.x,0.5,0,0);
	glRotated(rot.y,0.0,0.5,0);
	glRotated(rot.z,0.0,0,0.5);
	glScaled(scale.x,scale.y,scale.z);
	glColor3d(col.x,col.y,col.z);

	glutSolidSphere(1,10,10);
	drawLines();
	glPopMatrix();
}
void object::drawTorus()
{
	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glRotated(rot.x,0.5,0,0);
	glRotated(rot.y,0.0,0.5,0);
	glRotated(rot.z,0.0,0,0.5);
	glScaled(scale.x,scale.y,scale.z);
	glColor3d(col.x,col.y,col.z);

	glutSolidTorus(0.1,1.0,10,10);
	drawLines();
	glPopMatrix();
}
void  object::drawBouding()
{
	glPushMatrix();
	glTranslated(loc.x,loc.y,loc.z);
	glScaled(scale.x,scale.y,scale.z);
	glColor3d(col.x,col.y,col.z);
	glutWireCube(1);
	glPopMatrix();
}
void object::drawLines()
{
		glPushMatrix();
		glLineWidth(1.5f);
		glBegin(GL_LINES);
		glColor3f(0.9,0.1,0.1);
		glVertex3f(0,0.0,0);
		glVertex3f(2,0.0,0);
		glEnd();
		glPopMatrix();
}
void object::setLocation(vector3d l)
{
	loc=l;
}
void object::setLocationIncrement()
{
	loc.x-=cos(rot.y*M_PI/180.0)*speed;
	loc.z+=sin(rot.y*M_PI/180.0)*speed;
}
vector3d object::getLocation()
{
	return loc;
}
void object::setCouleur(vector3d couleur)
{
	col=couleur;
}
void object::setCouleurInc(vector3d couleur)
{
	col+=couleur;
}
vector3d object::getCouleur()
{
	return col;
}
void object::setRotation(vector3d r)
{
	rot+=r*2.5f;
}
vector3d object::getRotation()
{
	return rot;
}
void  object::setScale(vector3d r)
{
	
	scale+=r*2.5f;

}
vector3d  object::getScale()
{
	return scale;
}

vector3d object::getP1()
{
	return p1;
}
vector3d object::getP2()
{
	return p2;
}
vector3d object::getP3()
{
	return p3;
}
vector3d object::getP4()
{
	return p4;
}
vector3d object::getP5()
{
	return p5;
}
vector3d object::getP6()
{
	return p6;
}
vector3d object::getP7()
{
	return p7;
}
vector3d object::getP8()
{
	return p8;
}
vector3d object::getP9()
{
	return p9;
}
vector3d object::getP10()
{
	return p10;
}
vector3d object::getP11()
{
	return p11;
}
vector3d object::getP12()
{
	return p12;
}
vector3d object::getP13()
{
	return p13;
}
vector3d object::getP14()
{
	return p14;
}
vector3d object::getP15()
{
	return p15;
}
vector3d object::getP16()
{
	return p16;
}
vector3d object::getP17()
{
	return p17;
}
vector3d object::getP18()
{
	return p18;
}
vector3d object::getP19()
{
	return p19;
}
vector3d object::getP20()
{
	return p20;
}
vector3d object::getP21()
{
	return p21;
}
vector3d object::getP22()
{
	return p22;
}
vector3d object::getP23()
{
	return p23;
}
vector3d object::getP24()
{
	return p24;
}


void object:: movementWalk(bool up,bool down, bool right, bool left)
{
if(up)
{
		loc.x+=cos(rot.y*M_PI/180.0)*speed2;
	loc.z-=sin(rot.y*M_PI/180.0)*speed2;
	}	
	if(down)
	{
		loc.x-=cos(rot.y*M_PI/180.0)*speed2;
	loc.z+=sin(rot.y*M_PI/180.0)*speed2;
	}
	if(right)
	{
		rot.y-=1.5f;
	}
	if(left)
	{
		rot.y+=1.5f;
	}
}

void object::movement(bool up,bool down, bool right, bool left)
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
		
			
}
void object::dynamique()
{
	
					vector3d newPos(loc);
			      	newPos.y-=0.2f;
			       setLocation(newPos);
			      /* if(loc.y<0)
			       {
			       loc.y=0;
				   }*/
			       
			     
			       
}

void object::setDynamic(bool b)
{
	dynamic=b;
}
bool object::getDynamic()
{
	return dynamic;
}


bool object::getDrive()
{
	return drive;
}
void object::setDrive(bool b)
 {
 	drive=b;
 }

 bool object::getWalk()
{
	return walk;
}
void object::setWalk(bool b)
 {
 	walk=b;
 }
