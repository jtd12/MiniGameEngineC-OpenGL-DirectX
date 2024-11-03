#include"setup.h"

setup::setup()
{


	
}

void setup::initGL()
{
	time=0.0f;
	lanchGame=false;
	look=false;
	g=new grid();
	p=new pointer(vector3d(0,0,0));
	hud_.push_back(new hud("data/hud.bmp",593,321));
	cam.push_back(new camera());
	cam.push_back(new camera());
	cam.push_back(new camera());
	cam.push_back(new camera());
	camYaw=0.0f;
	mousevel=0.1f;
	mi=false;
	nTue=0;
	keyup=false;
	keydown=false;
	keyright=false;
	keyleft=false;
	intensity_fog=0.0f;
	start_density=5.0f;
	end_density=50.0f;
	nearPlane=0.1f;
	farPlane=1500.0f;
	angle=60.0f;
	col=vector3d(0,0,0);
	amb=vector3d(0.5,0.5,0.5);
	dif=vector3d(0.5,0.5,0.5);
	loadToFile();	
	posLight=vector3d(20.0f,5.0f,20.0f);


}
setup::~setup()
{
	for(int i=0;i<pref.size();i++)
	delete pref[i];
		for(int i=0;i<prefAnim.size();i++)
	delete prefAnim[i];
	delete g;
	delete p;
	for(int i=0;i<sky.size();i++)
	delete sky[i];
	for(int i=0;i<obj.size();i++)
	delete obj[i];
		for(int i=0;i<obj2.size();i++)
	delete obj2[i];
		for(int i=0;i<obj3.size();i++)
	delete obj3[i];
		for(int i=0;i<obj4.size();i++)
	delete obj4[i];
		for(int i=0;i<obj5.size();i++)
	delete obj5[i];
for(int i=0;i<cam.size();i++)
	delete cam[i];
	

}
void setup::linkParentObject(std::vector<object*> obj_,std::vector<object*> obj2_)
{

for(int i=0;i<obj_.size();i++)
 		for(int j=0;j<obj2_.size();j++)
	if(value==2000 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5) )
	{
		obj_[i]->setLink(true);
	}

for(int i=0;i<obj_.size();i++)
if(physicsMode==false && value==1100)
{
	obj_[i]->setLink(false);
}
if(physicsMode)
{

for(int i=0;i<obj_.size();i++)
 		for(int j=0;j<obj2_.size();j++)
	if(	obj_[i]->getLink() &&   selectObject(obj_[i]->getLocation(),obj2_[j]->getLocation(),vector3d(0,0,0),12))
	{

		obj_[i]->setLocation(obj2_[j]->getLocation()+vector3d(0,0,5));
	}
}
}


void setup::linkParentObject(std::vector<prefab*> obj_,std::vector<object*> obj2_)
{

for(int i=0;i<obj_.size();i++)
 		for(int j=0;j<obj2_.size();j++)
	if(value==2000 && selectObject(obj2_[j]->getLocation(),p->getLocation(),vector3d(0,0,0),7) )
	{
		obj2_[j]->setLink(true);
	}


if(physicsMode==false && value==1100)
{

}
if(physicsMode)
{

for(int i=0;i<obj_.size();i++)
 		for(int j=0;j<obj2_.size();j++)
	if(	obj2_[j]->getLink() &&   selectObject(obj_[i]->getLocation(),obj2_[j]->getLocation(),vector3d(0,0,0),12))
	{

		obj2_[j]->setLocation(obj_[i]->getLocation()+vector3d(0,0,5));
	}
}
}

void setup::linkParentObject(std::vector<prefabAnim*> obj_,std::vector<object*> obj2_)
{

for(int i=0;i<obj_.size();i++)
 		for(int j=0;j<obj2_.size();j++)
	if(value==2000 && selectObject(obj2_[j]->getLocation(),p->getLocation(),vector3d(0,0,0),7) )
	{
		obj2_[j]->setLink(true);
	}


if(physicsMode==false && value==1100)
{

}
if(physicsMode)
{

for(int i=0;i<obj_.size();i++)
 		for(int j=0;j<obj2_.size();j++)
	if(	obj2_[j]->getLink() &&   selectObject(obj_[i]->getLocation(),obj2_[j]->getLocation(),vector3d(0,0,0),12))
	{

		obj2_[j]->setLocation(obj_[i]->getLocation()+vector3d(0,-2,0));
	}
}
}


void setup:: reinitialiseGame(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_)
{
	for(int i=0;i<pref.size();i++)

pref_[i]->setLocation(vector3d(pref_[i]->getLocation().x,p->getLocation().y,pref_[i]->getLocation().z));

for(int i=0;i<prefAnim.size();i++)

prefAnim_[i]->setLocation(vector3d(prefAnim_[i]->getLocation().x,p->getLocation().y,prefAnim[i]->getLocation().z));

for(int i=0;i<obj_.size();i++)
if(obj_[i]->getDynamic())
obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,p->getLocation().y,obj_[i]->getLocation().z));


}
void setup::GameMode(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_)
{
	
time+=0.1f;
if(value==1000)
lanchGame=true;

if(lanchGame && value==1100)
{

lanchGame=false;
	physicsMode=false;
reinitialiseGame(obj,pref,prefAnim);
reinitialiseGame(obj2,pref,prefAnim);
reinitialiseGame(obj3,pref,prefAnim);
reinitialiseGame(obj4,pref,prefAnim);
}

if(lanchGame==false)
{
	physicsMode=false;

		for(int i=0;i<obj_.size();i++)
{
	obj_[i]->update();
}
	
}
if(lanchGame && value==1300)
{
		physicsMode=true;
	}
	if(physicsMode)
	{
	
		

			for(int i=0;i<obj_.size();i++)
			if(obj_[i]->getDynamic())
			{
					
						obj_[i]->dynamique();
				}	
				
						for(int i=0;i<pref_.size();i++)
			if(pref_[i]->getDynamic())
			{
					
						pref_[i]->physics();	
				}
				
						for(int i=0;i<prefAnim_.size();i++)
			if(prefAnim_[i]->getDynamic())
			{
					
						prefAnim_[i]->physics();
				}			
}

		for(int i=0;i<pref_.size();i++)
if(lanchGame && pref_[i]->getDrive() && physicsMode)
{
	

	
	pref_[i]->movement(keyup,keydown,keyright,keyleft);

	
	
	
	/*
		
		for(int i=0;i<pref.size();i++)
			for(int j=0;j<obj.size();j++)
		if(obj[j]->getRotation().x!=0 || obj[j]->getRotation().y!=0 || obj[j]->getRotation().z!=0)
		 obj[j]->setRotation(vector3d(0,0,0));
		 */
		 

}
		for(int i=0;i<obj_.size();i++)
if(lanchGame && obj_[i]->getDrive() && physicsMode)
{
	

	
	obj_[i]->movement(keyup,keydown,keyright,keyleft);

	
	
	
	/*
		
		for(int i=0;i<pref.size();i++)
			for(int j=0;j<obj.size();j++)
		if(obj[j]->getRotation().x!=0 || obj[j]->getRotation().y!=0 || obj[j]->getRotation().z!=0)
		 obj[j]->setRotation(vector3d(0,0,0));
		 */
		 

}
	for(int i=0;i<obj_.size();i++)
if(lanchGame && obj_[i]->getWalk() && physicsMode)
{
	

	
	obj_[i]->movementWalk(keyup,keydown,keyright,keyleft);

	
	
	
	/*
		
		for(int i=0;i<pref.size();i++)
			for(int j=0;j<obj.size();j++)
		if(obj[j]->getRotation().x!=0 || obj[j]->getRotation().y!=0 || obj[j]->getRotation().z!=0)
		 obj[j]->setRotation(vector3d(0,0,0));
		 */
		 

}
	
	for(int i=0;i<prefAnim_.size();i++)
if(lanchGame && prefAnim_[i]->getWalk() && physicsMode)
{
		
	prefAnim_[i]->update(keyup,keydown);
	
	
	prefAnim_[i]->movement(keyup,keydown,keyright,keyleft);	
}
/*
	for(int i=0;i<obj5.size();i++)
		obj5[i]->setCollision(true);
		*/
}

void setup::collision(std::vector<object*> obj_,std::vector<object*> obj2_)
{

	for(int i=0;i<obj_.size();i++)
				{
			for(int j=0;j<obj2_.size();j++)
{


if(obj_[i]->getDynamic())
{
	if(obj2_[j]->getDynamic()==false)
	{
	

vector3d posobj=obj_[i]->getLocation();
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP1(),obj2_[j]->getP2(),obj2_[j]->getP3(),obj2_[j]->getP4(),0.9);
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP5(),obj2_[j]->getP6(),obj2_[j]->getP7(),obj2_[j]->getP8(),0.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP9(),obj2_[j]->getP10(),obj2_[j]->getP11(),obj2_[j]->getP12(),0.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP13(),obj2_[j]->getP14(),obj2_[j]->getP15(),obj2_[j]->getP16(),0.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP17(),obj2_[j]->getP18(),obj2_[j]->getP19(),obj2_[j]->getP20(),0.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP21(),obj2_[j]->getP22(),obj2_[j]->getP23(),obj2_[j]->getP24(),0.9);
obj_[i]->setLocation(posobj);




}
}
}
}
}
void setup::collision(std::vector<prefab*> obj_,std::vector<object*> obj2_)
{
	for(int i=0;i<obj_.size();i++)
				{
			for(int j=0;j<obj2_.size();j++)
{


if(obj_[i]->getDynamic())
{
	if(obj2_[j]->getDynamic()==false)
	{
	

vector3d posobj=obj_[i]->getLocation();
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP1(),obj2_[j]->getP2(),obj2_[j]->getP3(),obj2_[j]->getP4(),0.9);
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP5(),obj2_[j]->getP6(),obj2_[j]->getP7(),obj2_[j]->getP8(),0.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP9(),obj2_[j]->getP10(),obj2_[j]->getP11(),obj2_[j]->getP12(),0.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP13(),obj2_[j]->getP14(),obj2_[j]->getP15(),obj2_[j]->getP16(),0.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP17(),obj2_[j]->getP18(),obj2_[j]->getP19(),obj2_[j]->getP20(),0.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP21(),obj2_[j]->getP22(),obj2_[j]->getP23(),obj2_[j]->getP24(),0.9);
obj_[i]->setLocation(posobj);




}
}
}
}
}
void setup::collision(std::vector<prefabAnim*> obj_,std::vector<object*> obj2_)
{

	for(int i=0;i<obj_.size();i++)
				{
			for(int j=0;j<obj2_.size();j++)
{


if(obj_[i]->getDynamic())
{
	if(obj2_[j]->getDynamic()==false)
	{
	

vector3d posobj=obj_[i]->getLocation();
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP1(),obj2_[j]->getP2(),obj2_[j]->getP3(),obj2_[j]->getP4(),1.9);
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP5(),obj2_[j]->getP6(),obj2_[j]->getP7(),obj2_[j]->getP8(),1.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP9(),obj2_[j]->getP10(),obj2_[j]->getP11(),obj2_[j]->getP12(),1.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP13(),obj2_[j]->getP14(),obj2_[j]->getP15(),obj2_[j]->getP16(),1.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP17(),obj2_[j]->getP18(),obj2_[j]->getP19(),obj2_[j]->getP20(),1.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP21(),obj2_[j]->getP22(),obj2_[j]->getP23(),obj2_[j]->getP24(),1.9);
obj_[i]->setLocation(posobj);




}
}

}
}


}	

void setup::update()
{
collision( obj2,obj);
collision( obj2,obj2);
collision( obj2,obj3);
collision( obj2,obj4);
collision( obj2,obj5);

collision( obj,obj);
collision( obj,obj2);
collision( obj,obj3);
collision( obj,obj4);
collision( obj,obj5);

collision( obj3,obj);
collision( obj3,obj2);
collision( obj3,obj3);
collision( obj3,obj4);
collision( obj3,obj5);

collision( obj4,obj);
collision( obj4,obj2);
collision( obj4,obj3);
collision( obj4,obj4);
collision( obj4,obj5);

collision( pref,obj);
collision( pref,obj2);
collision( pref,obj3);
collision( pref,obj4);
collision( pref,obj5);

collision( prefAnim,obj);
collision( prefAnim,obj2);
collision( prefAnim,obj3);
collision( prefAnim,obj4);
collision( prefAnim,obj5);

GameMode(obj,pref,prefAnim);
GameMode(obj2,pref,prefAnim);
GameMode(obj3,pref,prefAnim);
GameMode(obj4,pref,prefAnim);
GameMode(obj5,pref,prefAnim);

linkParentObject(obj,obj2);
linkParentObject(obj,obj3);
linkParentObject(obj,obj4);

linkParentObject(obj2,obj);
linkParentObject(obj2,obj3);
linkParentObject(obj2,obj4);

linkParentObject(obj3,obj);
linkParentObject(obj3,obj2);
linkParentObject(obj3,obj4);

linkParentObject(obj4,obj);
linkParentObject(obj4,obj2);
linkParentObject(obj4,obj3);

linkParentObject(pref,obj);
linkParentObject(pref,obj2);
linkParentObject(pref,obj3);
linkParentObject(pref,obj4);


linkParentObject(prefAnim,obj);
linkParentObject(prefAnim,obj2);
linkParentObject(prefAnim,obj3);
linkParentObject(prefAnim,obj4);


}
void setup::show()
{
//clavierActif(); 
	update();
int LightPos[4] = {0,10,-50,1};
GLfloat shininess = 10.0F ;
int MatSpec [4] = {1,1,1,1};
glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,MatSpec);//fonction d'affichage d'un materiau qui gere la specularite
glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,10);//fonction 
glMaterialf(GL_FRONT,GL_SHININESS,shininess);
 


glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice
gluLookAt(1,1,10,1,0,0,0,1,0);
//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
		p->setLocation(cam[0]->getLocation());
cam[3]->update();
	fog();

  glDisable(GL_FOG);


g->show();
p->show(); 

  glEnable(GL_FOG);
 
  if(fog_)
  glEnable(GL_FOG);
	if(fog_==false)
{
glDisable(GL_FOG);

}




for(int i=0;i<obj.size();i++)
obj[i]->drawCube();


for(int i=0;i<obj2.size();i++)
obj2[i]->drawTeapot();

for(int i=0;i<obj3.size();i++)
obj3[i]->drawSphere();

for(int i=0;i<obj4.size();i++)
obj4[i]->drawTorus();

for(int i=0;i<obj5.size();i++)
obj5[i]->drawBouding();
for(int i=0;i<pref.size();i++)
pref[i]->show();
for(int i=0;i<prefAnim.size();i++)
prefAnim[i]->show();

for(int i=0;i<Pobj.size();i++)
Pobj[i]->drawObject();
for(int i=0;i<Pobj2.size();i++)
Pobj2[i]->drawObject();
for(int i=0;i<Pobj3.size();i++)
Pobj3[i]->drawObject();
for(int i=0;i<Pobj4.size();i++)
Pobj4[i]->drawObject();
for(int i=0;i<Pobj5.size();i++)
Pobj5[i]->drawObject();
for(int i=0;i<Pobj6.size();i++)
Pobj6[i]->drawObject();
for(int i=0;i<Pobj7.size();i++)
Pobj7[i]->drawObject();
for(int i=0;i<Pobj8.size();i++)
Pobj8[i]->drawObject();
for(int i=0;i<Pobj9.size();i++)
Pobj9[i]->drawObject();
for(int i=0;i<Pobj10.size();i++)
Pobj10[i]->drawObject();
for(int i=0;i<Pobj11.size();i++)
Pobj11[i]->drawObject();
colorSky();
 lighting();
mode2D();
//clavier();


//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}
void setup::show2()
{
//clavierActif(); 
	update();
int LightPos[4] = {0,10,-50,1};
GLfloat shininess = 10.0F ;
int MatSpec [4] = {1,1,1,1};
glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,MatSpec);//fonction d'affichage d'un materiau qui gere la specularite
glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,10);//fonction 
glMaterialf(GL_FRONT,GL_SHININESS,shininess);
 


glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice

//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
gluLookAt(12,18,1,12,0,0,0,1,0);
	p->setLocation(cam[0]->getLocation());
cam[2]->update();
	fog();

  glDisable(GL_FOG);

g->show();
p->show(); 

  glEnable(GL_FOG);

  if(fog_)
  glEnable(GL_FOG);
	if(fog_==false)
{
glDisable(GL_FOG);

}


for(int i=0;i<obj.size();i++)
obj[i]->drawCube();


for(int i=0;i<obj2.size();i++)
obj2[i]->drawTeapot();

for(int i=0;i<obj3.size();i++)
obj3[i]->drawSphere();

for(int i=0;i<obj4.size();i++)
obj4[i]->drawTorus();
for(int i=0;i<obj5.size();i++)
obj5[i]->drawBouding();
for(int i=0;i<pref.size();i++)
pref[i]->show();
for(int i=0;i<prefAnim.size();i++)
prefAnim[i]->show();

for(int i=0;i<Pobj.size();i++)
Pobj[i]->drawObject();
for(int i=0;i<Pobj2.size();i++)
Pobj2[i]->drawObject();
for(int i=0;i<Pobj3.size();i++)
Pobj3[i]->drawObject();
for(int i=0;i<Pobj4.size();i++)
Pobj4[i]->drawObject();
for(int i=0;i<Pobj5.size();i++)
Pobj5[i]->drawObject();
for(int i=0;i<Pobj6.size();i++)
Pobj6[i]->drawObject();
for(int i=0;i<Pobj7.size();i++)
Pobj7[i]->drawObject();
for(int i=0;i<Pobj8.size();i++)
Pobj8[i]->drawObject();
for(int i=0;i<Pobj9.size();i++)
Pobj9[i]->drawObject();
for(int i=0;i<Pobj10.size();i++)
Pobj10[i]->drawObject();
for(int i=0;i<Pobj11.size();i++)
Pobj11[i]->drawObject();
colorSky();

mode2D();
 lighting();
//clavier();


//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}
void setup::show3()
{
//clavierActif(); 
	update();
int LightPos[4] = {0,10,-50,1};
GLfloat shininess = 10.0F ;
int MatSpec [4] = {1,1,1,1};
glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,MatSpec);//fonction d'affichage d'un materiau qui gere la specularite
glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,10);//fonction 
glMaterialf(GL_FRONT,GL_SHININESS,shininess);
 


glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice

//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
gluLookAt(12,1,1,0,0,0,0,1,0);

p->setLocation(cam[0]->getLocation());	
cam[1]->update();

	fog();

  glDisable(GL_FOG);

g->show();
p->show(); 
  glEnable(GL_FOG);

  if(fog_)
  glEnable(GL_FOG);
	if(fog_==false)
{
glDisable(GL_FOG);

}



for(int i=0;i<obj.size();i++)
obj[i]->drawCube();


for(int i=0;i<obj2.size();i++)
obj2[i]->drawTeapot();

for(int i=0;i<obj3.size();i++)
obj3[i]->drawSphere();

for(int i=0;i<obj4.size();i++)
obj4[i]->drawTorus();
for(int i=0;i<obj5.size();i++)
obj5[i]->drawBouding();
for(int i=0;i<pref.size();i++)
pref[i]->show();
for(int i=0;i<prefAnim.size();i++)
prefAnim[i]->show();
for(int i=0;i<Pobj.size();i++)
Pobj[i]->drawObject();
for(int i=0;i<Pobj2.size();i++)
Pobj2[i]->drawObject();
for(int i=0;i<Pobj3.size();i++)
Pobj3[i]->drawObject();
for(int i=0;i<Pobj4.size();i++)
Pobj4[i]->drawObject();
for(int i=0;i<Pobj5.size();i++)
Pobj5[i]->drawObject();
for(int i=0;i<Pobj6.size();i++)
Pobj6[i]->drawObject();
for(int i=0;i<Pobj7.size();i++)
Pobj7[i]->drawObject();
for(int i=0;i<Pobj8.size();i++)
Pobj8[i]->drawObject();
for(int i=0;i<Pobj9.size();i++)
Pobj9[i]->drawObject();
for(int i=0;i<Pobj10.size();i++)
Pobj10[i]->drawObject();
for(int i=0;i<Pobj11.size();i++)
Pobj11[i]->drawObject();


colorSky();

 lighting();
mode2D();
//clavier();


//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}
void setup::show4()
{
	update();
//clavierActif(); 






glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice

//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
if(look==false && look2==false || look3)
{

	gluLookAt(40,8,10,5,0,0,0,1,0);


 
//p->setLocation(cam[0]->getLocation());

p->setLocation(cam[0]->getLocation());
cam[0]->update();
}
	for(int i=0;i<pref.size();i++)
if(look && look2==false && pref[i]->getDrive())
{


	
	vector3d camPos=vector3d(pref[i]->getLocation().x-cos(pref[i]->getRotation().y*M_PI/180)*-5,pref[i]->getLocation().y+3,pref[i]->getLocation().z+sin(pref[i]->getRotation().y*M_PI/180)*-5);
	vector3d lookAt = vector3d(pref[i]->getLocation().x,pref[i]->getLocation().y,pref[i]->getLocation().z);
	gluLookAt(camPos.x,camPos.y,camPos.z,lookAt.x,lookAt.y,lookAt.z,0,1,0);

}
	for(int i=0;i<prefAnim.size();i++)
if(look2 && look==false && prefAnim[i]->getWalk())
{


	
	vector3d camPos=vector3d(prefAnim[i]->getLocation().x+cos(prefAnim[i]->getRotation().y*M_PI/180)*-5,prefAnim[i]->getLocation().y+3,prefAnim[i]->getLocation().z-sin(prefAnim[i]->getRotation().y*M_PI/180)*-5);
	vector3d lookAt = vector3d(prefAnim[i]->getLocation().x,prefAnim[i]->getLocation().y,prefAnim[i]->getLocation().z);
	gluLookAt(camPos.x,camPos.y,camPos.z,lookAt.x,lookAt.y,lookAt.z,0,1,0);

}


  glDisable(GL_FOG);

g->show();
p->show(); 
if(time<25)
hud_[0]->show();
  glEnable(GL_FOG);

  
  if(fog_)
  glEnable(GL_FOG);
  	fog();
	if(fog_==false)
{
glDisable(GL_FOG);

}





for(int i=0;i<obj.size();i++)
obj[i]->drawCube();


for(int i=0;i<obj2.size();i++)
obj2[i]->drawTeapot();

for(int i=0;i<obj3.size();i++)
obj3[i]->drawSphere();

for(int i=0;i<obj4.size();i++)
obj4[i]->drawTorus();

for(int i=0;i<obj5.size();i++)
obj5[i]->drawBouding();

for(int i=0;i<Pobj.size();i++)
Pobj[i]->drawObject();
for(int i=0;i<Pobj2.size();i++)
Pobj2[i]->drawObject();
for(int i=0;i<Pobj3.size();i++)
Pobj3[i]->drawObject();
for(int i=0;i<Pobj4.size();i++)
Pobj4[i]->drawObject();
for(int i=0;i<Pobj5.size();i++)
Pobj5[i]->drawObject();
for(int i=0;i<Pobj6.size();i++)
Pobj6[i]->drawObject();
for(int i=0;i<Pobj7.size();i++)
Pobj7[i]->drawObject();
for(int i=0;i<Pobj8.size();i++)
Pobj8[i]->drawObject();
for(int i=0;i<Pobj9.size();i++)
Pobj9[i]->drawObject();
for(int i=0;i<Pobj10.size();i++)
Pobj10[i]->drawObject();
for(int i=0;i<Pobj11.size();i++)
Pobj11[i]->drawObject();
for(int i=0;i<pref.size();i++)
pref[i]->show();
for(int i=0;i<prefAnim.size();i++)
prefAnim[i]->show();



selectCam();


colorSky();

 lighting();


mode2D();
	


//clavier();

//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}



void setup::saveToFile()
      {
      	std::ofstream loadedFile;
      	loadedFile.open("data/stagelayout.txt");
  
      	loadedFile<<"---beginObj1-----"<<std::endl;
      	for(int i=0;i<obj.size();i++)
      	
		  {
		  
      	loadedFile<<"Obj1pos locX: "<<obj[i]->getLocation().x<<"Obj1pos locY1: "<<obj[i]->getLocation().y<<"Obj1pos locY2: "<<obj[i]->getScale().y<<"Obj1pos locY: "<<obj[i]->getScale().x<<"Obj1pos locY3: "<<obj[i]->getScale().z<<"Obj1pos locY5: "<<obj[i]->getRotation().y<<"Obj1pos locY4: "<<obj[i]->getRotation().x<<"Obj1pos locY6: "<<obj[i]->getRotation().z<<"Obj1pos locY7: "<<obj[i]->getCouleur().x<<"Obj1pos locY8: "<<obj[i]->getCouleur().y<<"Obj1pos locY9: "<<obj[i]->getCouleur().z<<"obj1pos locZ: "<<obj[i]->getLocation().z<<std::endl; 
    
}
	  	loadedFile<<"----endObj1-----"<<std::endl;
      		loadedFile<<"---beginObj2-----"<<std::endl;
      	for(int i=0;i<obj2.size();i++)
      	{
		  
      loadedFile<<"Obj1pos locX_2: "<<obj2[i]->getLocation().x<<"Obj1pos locY1_2: "<<obj2[i]->getLocation().y<<"Obj1pos locY2_2: "<<obj2[i]->getScale().y<<"Obj1pos locY_2: "<<obj2[i]->getScale().x<<"Obj1pos locY3_2: "<<obj2[i]->getScale().z<<"Obj1pos locY5_2: "<<obj2[i]->getRotation().y<<"Obj1pos locY4_2: "<<obj2[i]->getRotation().x<<"Obj1pos locY6_2: "<<obj2[i]->getRotation().z<<"Obj1pos locY7_2: "<<obj2[i]->getCouleur().x<<"Obj1pos locY8_2: "<<obj2[i]->getCouleur().y<<"Obj1pos locY9_2: "<<obj2[i]->getCouleur().z<<"Obj1pos locZ_2: "<<obj2[i]->getLocation().z<<std::endl; 
    
  }
	  	loadedFile<<"----endObj2-----"<<std::endl;
      		loadedFile<<"---beginObj3-----"<<std::endl;
      	for(int i=0;i<obj3.size();i++)
      	{
	 loadedFile<<"Obj1pos locX_3: "<<obj3[i]->getLocation().x<<"Obj1pos locY1_3: "<<obj3[i]->getLocation().y<<"Obj1pos locY2_3: "<<obj3[i]->getScale().y<<"Obj1pos locY_3: "<<obj3[i]->getScale().x<<"Obj1pos locY3_3: "<<obj3[i]->getScale().z<<"Obj1pos locY5_3: "<<obj3[i]->getRotation().y<<"Obj1pos locY4_3: "<<obj3[i]->getRotation().x<<"Obj1pos locY6_2: "<<obj3[i]->getRotation().z<<"Obj1pos locY7_3: "<<obj3[i]->getCouleur().x<<"Obj1pos locY8_3: "<<obj3[i]->getCouleur().y<<"Obj1pos locY9_3: "<<obj3[i]->getCouleur().z<<"Obj1pos locZ_3: "<<obj3[i]->getLocation().z<<std::endl; 
	  }   loadedFile<<"----endObj3-----"<<std::endl;
      
      		loadedFile<<"---beginObj4-----"<<std::endl;
      	for(int i=0;i<obj4.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_4: "<<obj4[i]->getLocation().x<<"Obj1pos locY1_4: "<<obj4[i]->getLocation().y<<"Obj1pos locY2_4: "<<obj4[i]->getScale().y<<"Obj1pos locY_4: "<<obj4[i]->getScale().x<<"Obj1pos locY3_4: "<<obj4[i]->getScale().z<<"Obj1pos locY5_4: "<<obj4[i]->getRotation().y<<"Obj1pos locY4_4: "<<obj4[i]->getRotation().x<<"Obj1pos locY6_4: "<<obj4[i]->getRotation().z<<"Obj1pos locY7_4: "<<obj4[i]->getCouleur().x<<"Obj1pos locY8_4: "<<obj4[i]->getCouleur().y<<"Obj1pos locY9_4: "<<obj4[i]->getCouleur().z<<"Obj1pos locZ_4: "<<obj4[i]->getLocation().z<<std::endl; 
    
	  }
		  loadedFile<<"----endObj4-----"<<std::endl;
		  
		  	loadedFile<<"---beginVehicule-----"<<std::endl;
      	for(int i=0;i<pref.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_5: "<<pref[i]->getLocation().x<<"Obj1pos locY1_5: "<<pref[i]->getLocation().y<<"Obj1pos locY2_5: "<<pref[i]->getScale().y<<"Obj1pos locY_5: "<<pref[i]->getScale().x<<"Obj1pos locY3_5: "<<pref[i]->getScale().z<<"Obj1pos locY5_5: "<<pref[i]->getRotation().y<<"Obj1pos locY4_5: "<<pref[i]->getRotation().x<<"Obj1pos locY6_5: "<<pref[i]->getRotation().z<<"Obj1pos locZ_5: "<<pref[i]->getLocation().z<<std::endl; 

      }
		  loadedFile<<"----endVehicule-----"<<std::endl;
		  
		 loadedFile<<"---beginCharacter-----"<<std::endl;
      	for(int i=0;i<prefAnim.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_6: "<<prefAnim[i]->getLocation().x<<"Obj1pos locY1_6: "<<prefAnim[i]->getLocation().y<<"Obj1pos locY2_6: "<<prefAnim[i]->getScale().y<<"Obj1pos locY_6: "<<prefAnim[i]->getScale().x<<"Obj1pos locY3_6: "<<prefAnim[i]->getScale().z<<"Obj1pos locY5_6: "<<prefAnim[i]->getRotation().y<<"Obj1pos locY4_6: "<<prefAnim[i]->getRotation().x<<"Obj1pos locY6_6: "<<prefAnim[i]->getRotation().z<<"Obj1pos locZ_6: "<<prefAnim[i]->getLocation().z<<std::endl; 

      }
		  loadedFile<<"----endCharacter-----"<<std::endl; 
      
     
	  	
	  	
			   
			   loadedFile<<"---beginObj5-----"<<std::endl;
      	for(int i=0;i<obj5.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_7: "<<obj5[i]->getLocation().x<<"Obj1pos locY1_7: "<<obj5[i]->getLocation().y<<"Obj1pos locY2_7: "<<obj5[i]->getScale().y<<"Obj1pos locY_7: "<<obj5[i]->getScale().x<<"Obj1pos locY3_7: "<<obj5[i]->getScale().z<<"Obj1pos locY5_7: "<<obj5[i]->getRotation().y<<"Obj1pos locY4_7: "<<obj5[i]->getRotation().x<<"Obj1pos locY6_7: "<<obj5[i]->getRotation().z<<"Obj1pos locZ_7: "<<obj5[i]->getLocation().z<<std::endl; 

      }
		  loadedFile<<"----endObj5-----"<<std::endl;
		  
		  
		  
		  
      	loadedFile<<"---beginPobj1-----"<<std::endl;
      	for(int i=0;i<Pobj.size();i++)
      	
		  {
		  
      	loadedFile<<"Pobj1pos PlocX: "<<Pobj[i]->getLocation().x<<"Pobj1pos PlocY1: "<<Pobj[i]->getLocation().y<<"Pobj1pos PlocY2: "<<Pobj[i]->getScale().y<<"Pobj1pos PlocY: "<<Pobj[i]->getScale().x<<"Pobj1pos PlocY3: "<<Pobj[i]->getScale().z<<"Pobj1pos PlocY5: "<<Pobj[i]->getRotation().y<<"Pobj1pos PlocY4: "<<Pobj[i]->getRotation().x<<"Pobj1pos PlocY6: "<<Pobj[i]->getRotation().z<<"Pobj1pos PlocY7: "<<Pobj[i]->getCouleur().x<<"Pobj1pos PlocY8: "<<Pobj[i]->getCouleur().y<<"Pobj1pos PlocY9: "<<Pobj[i]->getCouleur().z<<"Pobj1pos PlocZ: "<<Pobj[i]->getLocation().z<<"Pobj1pos filename_21: "<<fileName[11]<<std::endl; 
    
}
	  	loadedFile<<"----endPobj1-----"<<std::endl;
      		loadedFile<<"---beginPobj2-----"<<std::endl;
      	for(int i=0;i<Pobj2.size();i++)
      	{
		  
      loadedFile<<"Pobj1pos PlocX_2: "<<Pobj2[i]->getLocation().x<<"Pobj1pos PlocY1_2: "<<Pobj2[i]->getLocation().y<<"Pobj1pos PlocY2_2: "<<Pobj2[i]->getScale().y<<"Pobj1pos PlocY_2: "<<Pobj2[i]->getScale().x<<"Pobj1pos PlocY3_2: "<<Pobj2[i]->getScale().z<<"Pobj1pos PlocY5_2: "<<Pobj2[i]->getRotation().y<<"Pobj1pos PlocY4_2: "<<Pobj2[i]->getRotation().x<<"Pobj1pos PlocY6_2: "<<Pobj2[i]->getRotation().z<<"Pobj1pos PlocY7_2: "<<Pobj2[i]->getCouleur().x<<"Pobj1pos PlocY8_2: "<<Pobj2[i]->getCouleur().y<<"Pobj1pos PlocY9_2: "<<Pobj2[i]->getCouleur().z<<"Pobj1pos PlocZ_2: "<<Pobj2[i]->getLocation().z<<"Pobj1pos filename_20: "<<fileName[10]<<std::endl; 
    
  }
	  	loadedFile<<"----endPobj2-----"<<std::endl;
      		loadedFile<<"---beginPobj3-----"<<std::endl;
      	for(int i=0;i<Pobj3.size();i++)
      	{
	 loadedFile<<"Pobj1pos PlocX_3: "<<Pobj3[i]->getLocation().x<<"Pobj1pos PlocY1_3: "<<Pobj3[i]->getLocation().y<<"Pobj1pos PlocY2_3: "<<Pobj3[i]->getScale().y<<"Pobj1pos PlocY_3: "<<Pobj3[i]->getScale().x<<"Pobj1pos PlocY3_3: "<<Pobj3[i]->getScale().z<<"Pobj1pos PlocY5_3: "<<Pobj3[i]->getRotation().y<<"Pobj1pos PlocY4_3: "<<Pobj3[i]->getRotation().x<<"Pobj1pos PlocY6_2: "<<Pobj3[i]->getRotation().z<<"Pobj1pos PlocY7_3: "<<Pobj3[i]->getCouleur().x<<"Pobj1pos PlocY8_3: "<<Pobj3[i]->getCouleur().y<<"Pobj1pos PlocY9_3: "<<Pobj3[i]->getCouleur().z<<"Pobj1pos PlocZ_3: "<<Pobj3[i]->getLocation().z<<"Pobj1pos filename_19: "<<fileName[8]<<std::endl; 
	  }   loadedFile<<"----endPobj3-----"<<std::endl;
      
      		loadedFile<<"---beginPobj4-----"<<std::endl;
      	for(int i=0;i<Pobj4.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_4: "<<Pobj4[i]->getLocation().x<<"Pobj1pos PlocY1_4: "<<Pobj4[i]->getLocation().y<<"Pobj1pos PlocY2_4: "<<Pobj4[i]->getScale().y<<"Pobj1pos PlocY_4: "<<Pobj4[i]->getScale().x<<"Pobj1pos PlocY3_4: "<<Pobj4[i]->getScale().z<<"Pobj1pos PlocY5_4: "<<Pobj4[i]->getRotation().y<<"Pobj1pos PlocY4_4: "<<Pobj4[i]->getRotation().x<<"Pobj1pos PlocY6_4: "<<Pobj4[i]->getRotation().z<<"Pobj1pos PlocY7_4: "<<Pobj4[i]->getCouleur().x<<"Pobj1pos PlocY8_4: "<<Pobj4[i]->getCouleur().y<<"Pobj1pos PlocY9_4: "<<Pobj4[i]->getCouleur().z<<"Pobj1pos PlocZ_4: "<<Pobj4[i]->getLocation().z<<"Pobj1pos filename_18: "<<fileName[7]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj4-----"<<std::endl;
		  
		 	loadedFile<<"---beginPobj5-----"<<std::endl;
      	for(int i=0;i<Pobj5.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_5: "<<Pobj5[i]->getLocation().x<<"Pobj1pos PlocY1_5: "<<Pobj5[i]->getLocation().y<<"Pobj1pos PlocY2_5: "<<Pobj5[i]->getScale().y<<"Pobj1pos PlocY_5: "<<Pobj5[i]->getScale().x<<"Pobj1pos PlocY3_5: "<<Pobj5[i]->getScale().z<<"Pobj1pos PlocY5_5: "<<Pobj5[i]->getRotation().y<<"Pobj1pos PlocY4_5: "<<Pobj5[i]->getRotation().x<<"Pobj1pos PlocY6_5: "<<Pobj5[i]->getRotation().z<<"Pobj1pos PlocY7_5: "<<Pobj5[i]->getCouleur().x<<"Pobj1pos PlocY8_5: "<<Pobj5[i]->getCouleur().y<<"Pobj1pos PlocY9_5: "<<Pobj5[i]->getCouleur().z<<"Pobj1pos PlocZ_5: "<<Pobj5[i]->getLocation().z<<"Pobj1pos filename_17: "<<fileName[6]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj5-----"<<std::endl;
		   
		   	 	loadedFile<<"---beginPobj6-----"<<std::endl;
      	for(int i=0;i<Pobj6.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_6: "<<Pobj6[i]->getLocation().x<<"Pobj1pos PlocY1_6: "<<Pobj6[i]->getLocation().y<<"Pobj1pos PlocY2_6: "<<Pobj6[i]->getScale().y<<"Pobj1pos PlocY_6: "<<Pobj6[i]->getScale().x<<"Pobj1pos PlocY3_6: "<<Pobj6[i]->getScale().z<<"Pobj1pos PlocY5_6: "<<Pobj6[i]->getRotation().y<<"Pobj1pos PlocY4_6: "<<Pobj6[i]->getRotation().x<<"Pobj1pos PlocY6_6: "<<Pobj6[i]->getRotation().z<<"Pobj1pos PlocY7_6: "<<Pobj6[i]->getCouleur().x<<"Pobj1pos PlocY8_6: "<<Pobj6[i]->getCouleur().y<<"Pobj1pos PlocY9_6: "<<Pobj6[i]->getCouleur().z<<"Pobj1pos PlocZ_6: "<<Pobj6[i]->getLocation().z<<"Pobj1pos filename_16: "<<fileName[5]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj6-----"<<std::endl;
		     
			 	loadedFile<<"---beginPobj7-----"<<std::endl;
      	for(int i=0;i<Pobj7.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_7: "<<Pobj7[i]->getLocation().x<<"Pobj1pos PlocY1_7: "<<Pobj7[i]->getLocation().y<<"Pobj1pos PlocY2_7: "<<Pobj7[i]->getScale().y<<"Pobj1pos PlocY_7: "<<Pobj7[i]->getScale().x<<"Pobj1pos PlocY3_7: "<<Pobj7[i]->getScale().z<<"Pobj1pos PlocY5_7: "<<Pobj7[i]->getRotation().y<<"Pobj1pos PlocY4_7: "<<Pobj7[i]->getRotation().x<<"Pobj1pos PlocY6_7: "<<Pobj7[i]->getRotation().z<<"Pobj1pos PlocY7_7: "<<Pobj7[i]->getCouleur().x<<"Pobj1pos PlocY8_7: "<<Pobj7[i]->getCouleur().y<<"Pobj1pos PlocY9_7: "<<Pobj7[i]->getCouleur().z<<"Pobj1pos PlocZ_7: "<<Pobj7[i]->getLocation().z<<"Pobj1pos filename_15: "<<fileName[4]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj7-----"<<std::endl;
		    
		    	 	loadedFile<<"---beginPobj8-----"<<std::endl;
      	for(int i=0;i<Pobj8.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_8: "<<Pobj8[i]->getLocation().x<<"Pobj1pos PlocY1_8: "<<Pobj8[i]->getLocation().y<<"Pobj1pos PlocY2_8: "<<Pobj8[i]->getScale().y<<"Pobj1pos PlocY_8: "<<Pobj8[i]->getScale().x<<"Pobj1pos PlocY3_8: "<<Pobj8[i]->getScale().z<<"Pobj1pos PlocY5_8: "<<Pobj8[i]->getRotation().y<<"Pobj1pos PlocY4_8: "<<Pobj8[i]->getRotation().x<<"Pobj1pos PlocY6_8: "<<Pobj8[i]->getRotation().z<<"Pobj1pos PlocY7_8: "<<Pobj8[i]->getCouleur().x<<"Pobj1pos PlocY8_8: "<<Pobj8[i]->getCouleur().y<<"Pobj1pos PlocY9_8: "<<Pobj8[i]->getCouleur().z<<"Pobj1pos PlocZ_8: "<<Pobj8[i]->getLocation().z<<"Pobj1pos filename_14: "<<fileName[3]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj8-----"<<std::endl;
		    
		    	 	loadedFile<<"---beginPobj9-----"<<std::endl;
      	for(int i=0;i<Pobj9.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_9: "<<Pobj9[i]->getLocation().x<<"Pobj1pos PlocY1_9: "<<Pobj9[i]->getLocation().y<<"Pobj1pos PlocY2_9: "<<Pobj9[i]->getScale().y<<"Pobj1pos PlocY_9: "<<Pobj9[i]->getScale().x<<"Pobj1pos PlocY3_9: "<<Pobj9[i]->getScale().z<<"Pobj1pos PlocY5_9: "<<Pobj9[i]->getRotation().y<<"Pobj1pos PlocY4_9: "<<Pobj9[i]->getRotation().x<<"Pobj1pos PlocY6_9: "<<Pobj9[i]->getRotation().z<<"Pobj1pos PlocY7_9: "<<Pobj9[i]->getCouleur().x<<"Pobj1pos PlocY8_9: "<<Pobj9[i]->getCouleur().y<<"Pobj1pos PlocY9_9: "<<Pobj9[i]->getCouleur().z<<"Pobj1pos PlocZ_9: "<<Pobj9[i]->getLocation().z<<"Pobj1pos filename_13: "<<fileName[2]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj9-----"<<std::endl;
		    
		    	 	loadedFile<<"---beginPobj10-----"<<std::endl;
      	for(int i=0;i<Pobj10.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_10: "<<Pobj10[i]->getLocation().x<<"Pobj1pos PlocY1_10: "<<Pobj10[i]->getLocation().y<<"Pobj1pos PlocY2_10: "<<Pobj10[i]->getScale().y<<"Pobj1pos PlocY_10: "<<Pobj10[i]->getScale().x<<"Pobj1pos PlocY3_10: "<<Pobj10[i]->getScale().z<<"Pobj1pos PlocY5_10: "<<Pobj10[i]->getRotation().y<<"Pobj1pos PlocY4_10: "<<Pobj10[i]->getRotation().x<<"Pobj1pos PlocY6_10: "<<Pobj10[i]->getRotation().z<<"Pobj1pos PlocY7_10: "<<Pobj10[i]->getCouleur().x<<"Pobj1pos PlocY8_10: "<<Pobj10[i]->getCouleur().y<<"Pobj1pos PlocY9_10: "<<Pobj10[i]->getCouleur().z<<"Pobj1pos PlocZ_10: "<<Pobj10[i]->getLocation().z<<"Pobj1pos filename_12: "<<fileName[1]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj10-----"<<std::endl;
		  
		  
		  	    	 	loadedFile<<"---beginPobj11-----"<<std::endl;
      	for(int i=0;i<Pobj11.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_11: "<<Pobj11[i]->getLocation().x<<"Pobj1pos PlocY1_11: "<<Pobj11[i]->getLocation().y<<"Pobj1pos PlocY2_11: "<<Pobj11[i]->getScale().y<<"Pobj1pos PlocY_11: "<<Pobj11[i]->getScale().x<<"Pobj1pos PlocY3_11: "<<Pobj11[i]->getScale().z<<"Pobj1pos PlocY5_11: "<<Pobj11[i]->getRotation().y<<"Pobj1pos PlocY4_11: "<<Pobj11[i]->getRotation().x<<"Pobj1pos PlocY6_11: "<<Pobj11[i]->getRotation().z<<"Pobj1pos PlocY7_11: "<<Pobj11[i]->getCouleur().x<<"Pobj1pos PlocY8_11: "<<Pobj11[i]->getCouleur().y<<"Pobj1pos PlocY9_11: "<<Pobj11[i]->getCouleur().z<<"Pobj1pos PlocZ_11: "<<Pobj11[i]->getLocation().z<<"Pobj1pos filename_11: "<<fileName[0]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj11-----"<<std::endl;
		  
		  
		  	    	 	loadedFile<<"---beginPobj12-----"<<std::endl;
      for(int i=0;i<cam.size();i++)
		  
     loadedFile<<"Pobj1pos PlocX_12: "<<cam[0]->getLocation().x<<"Pobj1pos PlocY1_12: "<<cam[0]->getLocation().y<<"Pobj1pos PlocZ_12: "<<cam[0]->getLocation().z<<std::endl; 
    
	  
		  loadedFile<<"----endPobj12-----"<<std::endl;
		   
		   	    	 	loadedFile<<"---beginPobj13-----"<<std::endl;
      for(int i=0;i<cam.size();i++)
		  
     loadedFile<<"Pobj1pos PlocX_13: "<<cam[1]->getLocation().x<<"Pobj1pos PlocY1_13: "<<cam[1]->getLocation().y<<"Pobj1pos PlocZ_13: "<<cam[1]->getLocation().z<<std::endl; 
    
	  
		  loadedFile<<"----endPobj13-----"<<std::endl;
		      
			  
			  	    	 	loadedFile<<"---beginPobj14-----"<<std::endl;
      for(int i=0;i<cam.size();i++)
		  
     loadedFile<<"Pobj1pos PlocX_14: "<<cam[2]->getLocation().x<<"Pobj1pos PlocY1_14: "<<cam[2]->getLocation().y<<"Pobj1pos PlocZ_14: "<<cam[2]->getLocation().z<<std::endl; 
    
	  
		  loadedFile<<"----endPobj14-----"<<std::endl;
		      
			  	    	 	loadedFile<<"---beginPobj15-----"<<std::endl;
      for(int i=0;i<cam.size();i++)
		  
     loadedFile<<"Pobj1pos PlocX_15: "<<cam[3]->getLocation().x<<"Pobj1pos PlocY1_15: "<<cam[3]->getLocation().y<<"Pobj1pos PlocZ_15: "<<cam[3]->getLocation().z<<std::endl; 
    
	  
		  loadedFile<<"----endPobj15-----"<<std::endl;
		  
		   	loadedFile<<"---beginColorScreen-----"<<std::endl;
     
		  
     loadedFile<<"Pobj1pos PlocX_16: "<<col.x<<"Pobj1pos PlocY1_16: "<<col.y<<"Pobj1pos PlocZ_16: "<<col.z<<std::endl; 
    
	  
		  loadedFile<<"----endColorScreen-----"<<std::endl;
		         
		    	 
      	loadedFile.close();
      	std::cout<<"level saved"<<std::endl;
      	
	  }
	  
	  
void setup::loadToFile()
{
	std::ifstream loadedFile("data/stagelayout.txt");
	std::string line;
	enum ObjectType
	{
		typeNone,
		typeObj
	};
	int currentType=typeNone;
	
	if(loadedFile.is_open())
	{
		while(loadedFile.good())
		  {
		  	std::getline(loadedFile,line);
		  	
		  	if(line=="---beginVehicule-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginCharacter-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginObj1-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginObj2-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginObj3-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginObj4-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginObj5-----")
		  	{
		  		currentType=typeObj;
			  }
			  
			     	if(line=="---beginPobj1-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginPobj2-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginPobj3-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginPobj4-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginPobj5-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj6-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj7-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj8-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj9-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj10-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginPobj11-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginPobj12-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginPobj13-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginPobj14-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginPobj15-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginColorScreen-----")
		  	{
		  		currentType=typeObj;
			  }
			  else if(line=="----endVehicule-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj1-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj2-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj3-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj4-----")
			  {
			  	currentType=typeNone;
			  }
			   else if(line=="----endObj5-----")
			  {
			  	currentType=typeNone;
			  }
			  	  else if(line=="----endPobj1-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endPobj2-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endPobj3-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endPobj4-----")
			  {
			  	currentType=typeNone;
			  }
			   else if(line=="----endPobj5-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj6-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj7-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj8-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj9-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj10-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj11-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj12-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj13-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj14-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj15-----")
			  {
			  	currentType=typeNone;
			  }
			   else if(line=="----endColorScreen-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endCharacter-----")
			  {
			  	currentType=typeNone;
			  }
			 
			   
			  else
			  {
			  if(currentType==typeObj)
			  {
			  

		  	std::istringstream iss(line);
		  	vector3d tempLocation=vector3d(0,0,0);
		  	vector3d tempLocation2=vector3d(0,0,0);
			vector3d tempLocation3=vector3d(0,0,0);
		  	vector3d tempLocation4=vector3d(0,0,0);
		  	vector3d tempLocation5=vector3d(0,0,0);
		  	vector3d tempLocation6=vector3d(0,0,0);
		  	vector3d tempLocation7=vector3d(0,0,0);
		  	vector3d tempPLocation=vector3d(0,0,0);
		  	vector3d tempPLocation2=vector3d(0,0,0);
			vector3d tempPLocation3=vector3d(0,0,0);
		  	vector3d tempPLocation4=vector3d(0,0,0);
		  	vector3d tempPLocation5=vector3d(0,0,0);
		  	vector3d tempPLocation6=vector3d(0,0,0);
		  	vector3d tempPLocation7=vector3d(0,0,0);
		  	vector3d tempPLocation8=vector3d(0,0,0);
		  	vector3d tempPLocation9=vector3d(0,0,0);
		  	vector3d tempPLocation10=vector3d(0,0,0);
		  	vector3d tempPLocation11=vector3d(0,0,0);
		  	vector3d tempPLocation12=vector3d(0,0,0);
		  	vector3d tempPLocation13=vector3d(0,0,0);
		    vector3d tempPLocation14=vector3d(0,0,0);
		  	vector3d tempPLocation15=vector3d(0,0,0);
		  	
			vector3d tempRotation=vector3d(0,0,0);
			vector3d tempRotation2=vector3d(0,0,0);
			vector3d tempRotation3=vector3d(0,0,0);
			vector3d tempRotation4=vector3d(0,0,0);
			vector3d tempRotation5=vector3d(0,0,0);
			vector3d tempRotation6=vector3d(0,0,0);
			vector3d tempRotation7=vector3d(0,0,0);
			vector3d tempPRotation=vector3d(0,0,0);
			vector3d tempPRotation2=vector3d(0,0,0);
			vector3d tempPRotation3=vector3d(0,0,0);
			vector3d tempPRotation4=vector3d(0,0,0);
			vector3d tempPRotation5=vector3d(0,0,0);
			vector3d tempPRotation6=vector3d(0,0,0);
			vector3d tempPRotation7=vector3d(0,0,0);
			vector3d tempPRotation8=vector3d(0,0,0);
			vector3d tempPRotation9=vector3d(0,0,0);
			vector3d tempPRotation10=vector3d(0,0,0);
			vector3d tempPRotation11=vector3d(0,0,0);
			vector3d tempPRotation12=vector3d(0,0,0);
			
		  	vector3d tempScale=vector3d(0,0,0);
		  	vector3d tempScale2=vector3d(0,0,0);
		  	vector3d tempScale3=vector3d(0,0,0);
		  	vector3d tempScale4=vector3d(0,0,0);
		  	vector3d tempScale5=vector3d(0,0,0);
		  	vector3d tempScale6=vector3d(0,0,0);
		  	vector3d tempScale7=vector3d(0,0,0);
		  	vector3d tempPScale=vector3d(0,0,0);
		  	vector3d tempPScale2=vector3d(0,0,0);
		  	vector3d tempPScale3=vector3d(0,0,0);
		  	vector3d tempPScale4=vector3d(0,0,0);
		  	vector3d tempPScale5=vector3d(0,0,0);
		  	vector3d tempPScale6=vector3d(0,0,0);
		  	vector3d tempPScale7=vector3d(0,0,0);
		  	vector3d tempPScale8=vector3d(0,0,0);
		  	vector3d tempPScale9=vector3d(0,0,0);
		  	vector3d tempPScale10=vector3d(0,0,0);
		  	vector3d tempPScale11=vector3d(0,0,0);
		  	vector3d tempPScale12=vector3d(0,0,0);
		  	
		  	vector3d tempCol=vector3d(0,0,0);
		  	vector3d tempCol2=vector3d(0,0,0);
		  	vector3d tempCol3=vector3d(0,0,0);
		  	vector3d tempCol4=vector3d(0,0,0);
		  	vector3d tempColScreen=vector3d(0,0,0);
			std::string tempFileName;
			std::string tempFileName2;
			std::string tempFileName3;
			std::string tempFileName4;
			std::string tempFileName5;
			std::string tempFileName6;
			std::string tempFileName7;
			std::string tempFileName8;
			std::string tempFileName9;
			std::string tempFileName10;
			std::string tempFileName11;
		
		  	std::string previousWord="";
		  	
		  	while(iss)
		  	{
		  		std::string word;
		  		iss>>word;
		  if(previousWord=="PlocX_16:")
		  {
		  	tempColScreen.x=atof(word.c_str());
		  }
		  if(previousWord=="PlocY1_16:")
		  {
		  	tempColScreen.y=atof(word.c_str());
		  }
		  	if(previousWord=="PlocZ_11:")
		  	{
			  
		  		tempPLocation11.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_10:")
		  	{
			  
		  		tempPLocation10.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_9:")
		  	{
			  
		  		tempPLocation9.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_8:")
		  	{
			  
		  		tempPLocation8.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_7:")
		  	{
			  
		  		tempPLocation7.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_6:")
		  	{
			  
		  		tempPLocation6.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_5:")
		  	{
			  
		  		tempPLocation5.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_4:")
		  	{
			  
		  		tempPLocation4.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_3:")
		  	{
			  
		  		tempPLocation3.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_2:")
		  	{
			  
		  		tempPLocation2.z=atoi(word.c_str());
		  	}
		  		if(previousWord=="PlocZ:")
		  	{
			  
		  		tempPLocation.z=atoi(word.c_str());
		  	}
		  	
		  		
				  	if(previousWord=="locX:")
		  		{
		  			tempLocation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
				  	if(previousWord=="locX_2:")
		  		{
		  			tempLocation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="locX_3:")
		  		{
		  			tempLocation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="locX_4:")
		  		{
		  			tempLocation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		  	if(previousWord=="locX_5:")
		  		{
		  			tempLocation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="locX_6:")
		  		{
		  			tempLocation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="locX_7:")
		  		{
		  			tempLocation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  			  	if(previousWord=="PlocX:")
		  		{
		  			tempPLocation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
				  	if(previousWord=="PlocX_2:")
		  		{
		  			tempPLocation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="PlocX_3:")
		  		{
		  			tempPLocation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="PlocX_4:")
		  		{
		  			tempPLocation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		  	if(previousWord=="PlocX_5:")
		  		{
		  			tempPLocation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_6:")
		  		{
		  			tempPLocation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_7:")
		  		{
		  			tempPLocation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_8:")
		  		{
		  			tempPLocation8.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_9:")
		  		{
		  			tempPLocation9.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_10:")
		  		{
		  			tempPLocation10.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				if(previousWord=="PlocX_11:")
		  		{
		  			tempPLocation11.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					if(previousWord=="PlocX_12:")
		  		{
		  			tempPLocation12.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  						if(previousWord=="PlocX_13:")
		  		{
		  			tempPLocation13.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  						if(previousWord=="PlocX_14:")
		  		{
		  			tempPLocation14.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  						if(previousWord=="PlocX_15:")
		  		{
		  			tempPLocation15.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY1:")
		  		{
		  			tempLocation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY1_2:")
		  		{
		  			tempLocation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_3:")
		  		{
		  			tempLocation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_4:")
		  		{
		  			tempLocation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_5:")
		  		{
		  			tempLocation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_6:")
		  		{
		  			tempLocation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_7:")
		  		{
		  			tempLocation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  	
		  	
		  		  	if(previousWord=="PlocY1:")
		  		{
		  			tempPLocation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY1_2:")
		  		{
		  			tempPLocation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_3:")
		  		{
		  			tempPLocation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_4:")
		  		{
		  			tempPLocation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_5:")
		  		{
		  			tempPLocation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_6:")
		  		{
		  			tempPLocation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_7:")
		  		{
		  			tempPLocation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_8:")
		  		{
		  			tempPLocation8.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_9:")
		  		{
		  			tempPLocation9.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_10:")
		  		{
		  			tempPLocation10.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_11:")
		  		{
		  			tempPLocation11.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_12:")
		  		{
		  			tempPLocation12.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_13:")
		  		{
		  			tempPLocation13.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_14:")
		  		{
		  			tempPLocation14.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_15:")
		  		{
		  			tempPLocation15.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  					  	if(previousWord=="PlocY1_12:")
		  		{
		  			tempPLocation12.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				
		  	
		  	
		  			  	if(previousWord=="locY:")
		  		{
		  			tempScale.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY_2:")
		  		{
		  			tempScale2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY_3:")
		  		{
		  			tempScale3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY_4:")
		  		{
		  			tempScale4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY_5:")
		  		{
		  			tempScale5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  					  	if(previousWord=="locY_6:")
		  		{
		  			tempScale6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY_7:")
		  		{
		  			tempScale7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY:")
		  		{
		  			tempPScale.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY_2:")
		  		{
		  			tempPScale2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY_3:")
		  		{
		  			tempPScale3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY_4:")
		  		{
		  			tempPScale4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_5:")
		  		{
		  			tempPScale5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  					  	if(previousWord=="PlocY_6:")
		  		{
		  			tempPScale6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_7:")
		  		{
		  			tempPScale7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_8:")
		  		{
		  			tempPScale8.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_9:")
		  		{
		  			tempPScale9.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_10:")
		  		{
		  			tempPScale10.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_11:")
		  		{
		  			tempPScale11.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_12:")
		  		{
		  			tempPScale12.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
		  		
		  		
		  			  	if(previousWord=="locY2:")
		  		{
		  			tempScale.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_2:")
		  		{
		  			tempScale2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY2_3:")
		  		{
		  			tempScale3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY2_4:")
		  		{
		  			tempScale4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_5:")
		  		{
		  			tempScale5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_6:")
		  		{
		  			tempScale6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_7:")
		  		{
		  			tempScale7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  		  	if(previousWord=="PlocY2:")
		  		{
		  			tempPScale.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_2:")
		  		{
		  			tempPScale2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY2_3:")
		  		{
		  			tempPScale3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY2_4:")
		  		{
		  			tempPScale4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_5:")
		  		{
		  			tempPScale5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_6:")
		  		{
		  			tempPScale6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_7:")
		  		{
		  			tempPScale7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  	
		  			  	if(previousWord=="PlocY2_8:")
		  		{
		  			tempPScale8.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_9:")
		  		{
		  			tempPScale9.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_10:")
		  		{
		  			tempPScale10.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY2_11:")
		  		{
		  			tempPScale11.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY2_12:")
		  		{
		  			tempPScale12.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  	
		  			  	if(previousWord=="locY3:")
		  		{
		  			tempScale.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_2:")
		  		{
		  			tempScale2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_3:")
		  		{
		  			tempScale3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_4:")
		  		{
		  			tempScale4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_5:")
		  		{
		  			tempScale5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			  	if(previousWord=="locY3_6:")
		  		{
		  			tempScale6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_7:")
		  		{
		  			tempScale7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  		
		  			  	if(previousWord=="PlocY3:")
		  		{
		  			tempPScale.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_2:")
		  		{
		  			tempPScale2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_3:")
		  		{
		  			tempPScale3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_4:")
		  		{
		  			tempPScale4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_5:")
		  		{
		  			tempPScale5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			  	if(previousWord=="PlocY3_6:")
		  		{
		  			tempPScale6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_7:")
		  		{
		  			tempPScale7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_8:")
		  		{
		  			tempPScale8.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_9:")
		  		{
		  			tempPScale9.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_10:")
		  		{
		  			tempPScale10.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_11:")
		  		{
		  			tempPScale11.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		 	if(previousWord=="PlocY3_12:")
		  		{
		  			tempPScale12.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  			  	if(previousWord=="locY4:")
		  		{
		  			tempRotation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY4_2:")
		  		{
		  			tempRotation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY4_3:")
		  		{
		  			tempRotation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY4_4:")
		  		{
		  			tempRotation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY4_5:")
		  		{
		  			tempRotation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY4_6:")
		  		{
		  			tempRotation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY4_7:")
		  		{
		  			tempRotation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			if(previousWord=="PlocY4:")
		  		{
		  			tempPRotation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY4_2:")
		  		{
		  			tempPRotation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_3:")
		  		{
		  			tempPRotation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_4:")
		  		{
		  			tempPRotation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_5:")
		  		{
		  			tempPRotation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY4_6:")
		  		{
		  			tempPRotation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY4_7:")
		  		{
		  			tempPRotation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_8:")
		  		{
		  			tempPRotation8.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_9:")
		  		{
		  			tempPRotation9.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_10:")
		  		{
		  			tempPRotation10.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY4_11:")
		  		{
		  			tempPRotation11.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY4_12:")
		  		{
		  			tempPRotation12.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			  	if(previousWord=="locY5:")
		  		{
		  			tempRotation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY5_2:")
		  		{
		  			tempRotation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY5_3:")
		  		{
		  			tempRotation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY5_4:")
		  		{
		  			tempRotation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY5_5:")
		  		{
		  			tempRotation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  			  	if(previousWord=="locY5_6:")
		  		{
		  			tempRotation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="locY5_7:")
		  		{
		  			tempRotation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  	
		  	
		  		if(previousWord=="PlocY5:")
		  		{
		  			tempPRotation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY5_2:")
		  		{
		  			tempPRotation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY5_3:")
		  		{
		  			tempPRotation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY5_4:")
		  		{
		  			tempPRotation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY5_5:")
		  		{
		  			tempPRotation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  			  	if(previousWord=="PlocY5_6:")
		  		{
		  			tempPRotation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_7:")
		  		{
		  			tempPRotation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_8:")
		  		{
		  			tempPRotation8.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_9:")
		  		{
		  			tempPRotation9.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_10:")
		  		{
		  			tempPRotation10.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	  	if(previousWord=="PlocY5_11:")
		  		{
		  			tempPRotation11.y=atoi(word.c_str());
		  		
		  		
		  		
				  			
		  	}
		  	 	if(previousWord=="PlocY5_12:")
		  		{
		  			tempPRotation12.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  		
		  				  	if(previousWord=="locY6:")
		  		{
		  			tempRotation.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY6_2:")
		  		{
		  			tempRotation2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY6_3:")
		  		{
		  			tempRotation3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY6_4:")
		  		{
		  			tempRotation4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY6_5:")
		  		{
		  			tempRotation5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY6_6:")
		  		{
		  			tempRotation6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY6_7:")
		  		{
		  			tempRotation7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  			if(previousWord=="PlocY6:")
		  		{
		  			tempPRotation.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY6_2:")
		  		{
		  			tempPRotation2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY6_3:")
		  		{
		  			tempPRotation3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY6_4:")
		  		{
		  			tempPRotation4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY6_5:")
		  		{
		  			tempPRotation5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY6_6:")
		  		{
		  			tempPRotation6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY6_7:")
		  		{
		  			tempPRotation7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		 	if(previousWord=="PlocY6_8:")
		  		{
		  			tempPRotation8.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		 	if(previousWord=="PlocY6_9:")
		  		{
		  			tempPRotation9.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		 	if(previousWord=="PlocY6_10:")
		  		{
		  			tempPRotation10.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocY6_11:")
		  		{
		  			tempPRotation11.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocY6_12:")
		  		{
		  			tempPRotation12.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  				  	if(previousWord=="locY7:")
		  		{
		  			tempCol.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8:")
		  		{
		  			tempCol.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9:")
		  		{
		  			tempCol.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
		  		
		  			
		  				  	if(previousWord=="locY7_2:")
		  		{
		  			tempCol2.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8_2:")
		  		{
		  			tempCol2.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9_2:")
		  		{
		  			tempCol2.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
		  			
		  				  	if(previousWord=="locY7_3:")
		  		{
		  			tempCol3.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8_3:")
		  		{
		  			tempCol3.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9_3:")
		  		{
		  			tempCol3.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
				  	
		  				  	if(previousWord=="locY7_4:")
		  		{
		  			tempCol4.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8_4:")
		  		{
		  			tempCol4.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9_4:")
		  		{
		  			tempCol4.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
				  	
		  		
		  	
		  
		  			  	if(previousWord=="locZ:")
		  		{
		  			tempLocation.z=atoi(word.c_str());
		  		
		  		obj.push_back(new object(vector3d(tempLocation.x,tempLocation.y,tempLocation.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempRotation.x,tempRotation.y,tempRotation.z),vector3d(tempScale.x,tempScale.y,tempScale.z)));	
		  		
		  		
		  		}
		  		
		  		
		  			  	if(previousWord=="locZ_2:")
		  		{
		  			tempLocation2.z=atoi(word.c_str());
		  		
		  		obj2.push_back(new object(vector3d(tempLocation2.x,tempLocation2.y,tempLocation2.z),vector3d(tempCol2.x,tempCol2.y,tempCol2.z),vector3d(tempRotation2.x,tempRotation2.y,tempRotation2.z),vector3d(tempScale2.x,tempScale2.y,tempScale2.z)));	
		  		
		  		
		  		}
		  			  	if(previousWord=="locZ_3:")
		  		{
		  			tempLocation3.z=atoi(word.c_str());
		  		
		  		obj3.push_back(new object(vector3d(tempLocation3.x,tempLocation3.y,tempLocation3.z),vector3d(tempCol3.x,tempCol3.y,tempCol3.z),vector3d(tempRotation3.x,tempRotation3.y,tempRotation3.z),vector3d(tempScale3.x,tempScale3.y,tempScale3.z)));	
		  		
		  		
		  		}
		  			  	if(previousWord=="locZ_4:")
		  		{
		  			tempLocation4.z=atoi(word.c_str());
		  		
		  		obj4.push_back(new object(vector3d(tempLocation4.x,tempLocation4.y,tempLocation4.z),vector3d(tempCol4.x,tempCol4.y,tempCol4.z),vector3d(tempRotation4.x,tempRotation4.y,tempRotation4.z),vector3d(tempScale4.x,tempScale4.y,tempScale4.z)));	
		  		
		  		
		  		}
		  			  	if(previousWord=="locZ_5:")
		  		{
		  			tempLocation5.z=atoi(word.c_str());
		  			
			
					pref.push_back(new prefab("vehicule","data/vehicule.obj",vector3d(tempLocation5.x,tempLocation5.y,tempLocation5.z),vector3d(tempRotation5.x,tempRotation5.y,tempRotation5.z),vector3d(tempScale5.x,tempScale5.y,tempScale5.z)));
		  		}
		  		
		  			  	if(previousWord=="locZ_6:")
		  		{
		  			tempLocation6.z=atoi(word.c_str());
		  			
				
				prefAnim.push_back(new prefabAnim("character",vector3d(tempLocation6.x,tempLocation6.y,tempLocation6.z),vector3d(tempRotation6.x,tempRotation6.y,tempRotation6.z),vector3d(tempScale6.x,tempScale6.y,tempScale6.z)));
		  		}
		  		
		  		
		  		if(previousWord=="locZ_7:")
		  		{
		  		tempLocation7.z=atoi(word.c_str());
				 
		  			
				
				obj5.push_back(new object(vector3d(tempLocation7.x,tempLocation7.y,tempLocation7.z),vector3d(0.5,0.5,0.5),vector3d(tempRotation7.x,tempRotation7.y,tempRotation7.z),vector3d(tempScale7.x,tempScale7.y,tempScale7.z)));
		  		}
		  		
		  		
		  		
		  		 	if(previousWord=="filename_21:")
		  		{
		  			tempFileName11=word.c_str();
		  				fileName[10]=tempFileName11;
		  				unsigned int map=objLoad.load(fileName[10]);	
		  		Pobj.push_back(new Pobject("map",map,vector3d(tempPLocation.x,tempPLocation.y,tempPLocation.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation.x,tempPRotation.y,tempPRotation.z),vector3d(tempPScale.x,tempPScale.y,tempPScale.z)));	
		  		
		  		
		  		}
		  		
		  		 	if(previousWord=="filename_20:")
		  		{
		  				tempFileName10=word.c_str();
		  				fileName[9]=tempFileName10;
		  				unsigned int map=objLoad.load(fileName[9]);	
		  		Pobj2.push_back(new Pobject("map",map,vector3d(tempPLocation2.x,tempPLocation2.y,tempPLocation2.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation2.x,tempPRotation2.y,tempPRotation2.z),vector3d(tempPScale2.x,tempPScale2.y,tempPScale2.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_19:")
		  		{
		  			tempFileName9=word.c_str();
		  				fileName[8]=tempFileName9;
		  				unsigned int map=objLoad.load(fileName[8]);	
		  		Pobj3.push_back(new Pobject("map",map,vector3d(tempPLocation3.x,tempPLocation3.y,tempPLocation3.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation3.x,tempPRotation3.y,tempPRotation3.z),vector3d(tempPScale3.x,tempPScale3.y,tempPScale3.z)));	
		  		
		  		
		  		}
		  			if(previousWord=="filename_18:")
		  		{
		  			tempFileName8=word.c_str();
		  				fileName[7]=tempFileName8;
		  				unsigned int map=objLoad.load(fileName[7]);	
		  		Pobj4.push_back(new Pobject("map",map,vector3d(tempPLocation4.x,tempPLocation4.y,tempPLocation4.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation4.x,tempPRotation4.y,tempPRotation4.z),vector3d(tempPScale4.x,tempPScale4.y,tempPScale4.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_17:")
		  		{
		  				tempFileName7=word.c_str();
		  				fileName[6]=tempFileName7;
		  				unsigned int map=objLoad.load(fileName[6]);	
		  		Pobj5.push_back(new Pobject("map",map,vector3d(tempPLocation5.x,tempPLocation5.y,tempPLocation5.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation5.x,tempPRotation5.y,tempPRotation5.z),vector3d(tempPScale5.x,tempPScale5.y,tempPScale5.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_16:")
		  		{
		  			tempFileName6=word.c_str();
		  				fileName[5]=tempFileName6;
		  				unsigned int map=objLoad.load(fileName[5]);	
		  		Pobj6.push_back(new Pobject("map",map,vector3d(tempPLocation6.x,tempPLocation6.y,tempPLocation6.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation6.x,tempPRotation6.y,tempPRotation6.z),vector3d(tempPScale6.x,tempPScale6.y,tempPScale6.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_15:")
		  		{
		  			tempFileName5=word.c_str();
		  				fileName[4]=tempFileName5;
		  				unsigned int map=objLoad.load(fileName[4]);	
		  		Pobj7.push_back(new Pobject("map",map,vector3d(tempPLocation7.x,tempPLocation7.y,tempPLocation7.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation7.x,tempPRotation7.y,tempPRotation7.z),vector3d(tempPScale7.x,tempPScale7.y,tempPScale7.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_14:")
		  		{
		  				tempFileName4=word.c_str();
		  				fileName[3]=tempFileName4;
		  				unsigned int map=objLoad.load(fileName[3]);	
		  		Pobj8.push_back(new Pobject("map",map,vector3d(tempPLocation8.x,tempPLocation8.y,tempPLocation8.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation8.x,tempPRotation8.y,tempPRotation8.z),vector3d(tempPScale8.x,tempPScale8.y,tempPScale8.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_13:")
		  		{
		  			tempFileName3=word.c_str();
		  				fileName[2]=tempFileName3;
		  				unsigned int map=objLoad.load(fileName[2]);	
		  		Pobj9.push_back(new Pobject("map",map,vector3d(tempPLocation9.x,tempPLocation9.y,tempPLocation9.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation9.x,tempPRotation9.y,tempPRotation9.z),vector3d(tempPScale9.x,tempPScale9.y,tempPScale9.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_12:")
		  		{
		  			tempFileName2=word.c_str();
		  				fileName[1]=tempFileName2;
		  				unsigned int map=objLoad.load(fileName[1]);	
		  		Pobj10.push_back(new Pobject("map",map,vector3d(tempPLocation10.x,tempPLocation10.y,tempPLocation10.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation10.x,tempPRotation10.y,tempPRotation10.z),vector3d(tempPScale10.x,tempPScale10.y,tempPScale10.z)));	
		  		
		  		
		  		}
		  			if(previousWord=="PlocZ_12:")
		  		{
		  			
		  			tempPLocation12.z=atoi(word.c_str());
		  		
		  		//Pobj11.push_back(new Pobject("map",map,vector3d(tempPLocation12.x,tempPLocation12.y,tempPLocation12.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation12.x,tempPRotation12.y,tempPRotation12.z),vector3d(tempPScale12.x,tempPScale12.y,tempPScale12.z)));	
		  	for(int i=0;i<cam.size();i++)
		  				cam[0]->setLocation(vector3d(tempPLocation12.x,tempPLocation12.y,tempPLocation12.z));
		  		
		  	}
		  		
		  				if(previousWord=="filename_11:")
		  		{
		  		
		  				tempFileName=word.c_str();
		  				fileName[0]=tempFileName;
		  				unsigned int map=objLoad.load(fileName[0]);
		  			//for(int i=0;i<cam.size();i++)
		  				//cam[0]->setLocation(vector3d(tempPLocation11.x,tempPLocation11.y,tempPLocation11.z));
		  		//unsigned int map=objLoad.load("data/decor/map10.obj");	
		  		//Pobj10.push_back(new Pobject("map",map,vector3d(tempPLocation10.x,tempPLocation10.y,tempPLocation10.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation10.x,tempPRotation10.y,tempPRotation10.z),vector3d(tempPScale10.x,tempPScale10.y,tempPScale10.z)));	
		  		Pobj11.push_back(new Pobject("map",map,vector3d(tempPLocation11.x,tempPLocation11.y,tempPLocation11.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation11.x,tempPRotation11.y,tempPRotation11.z),vector3d(tempPScale11.x,tempPScale11.y,tempPScale11.z)));	
		  		
		  		
		  		}
				  
				  			if(previousWord=="PlocZ_13:")
		  		{
		  			tempPLocation13.z=atoi(word.c_str());
		  			for(int i=0;i<cam.size();i++)
		  				cam[1]->setLocation(vector3d(tempPLocation13.x,tempPLocation13.y,tempPLocation13.z));
		  		//unsigned int map=objLoad.load("data/decor/map10.obj");	
		  		//Pobj10.push_back(new Pobject("map",map,vector3d(tempPLocation10.x,tempPLocation10.y,tempPLocation10.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation10.x,tempPRotation10.y,tempPRotation10.z),vector3d(tempPScale10.x,tempPScale10.y,tempPScale10.z)));	
		  		
		  		
		  		}	 
				  
				  			if(previousWord=="PlocZ_14:")
		  		{
		  			tempPLocation14.z=atoi(word.c_str());
		  			for(int i=0;i<cam.size();i++)
		  				cam[2]->setLocation(vector3d(tempPLocation14.x,tempPLocation14.y,tempPLocation14.z));
		  		//unsigned int map=objLoad.load("data/decor/map10.obj");	
		  		//Pobj10.push_back(new Pobject("map",map,vector3d(tempPLocation10.x,tempPLocation10.y,tempPLocation10.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation10.x,tempPRotation10.y,tempPRotation10.z),vector3d(tempPScale10.x,tempPScale10.y,tempPScale10.z)));	
		  		
		  		
		  		}	 
				  
				  			if(previousWord=="PlocZ_15:")
		  		{
		  			tempPLocation15.z=atoi(word.c_str());
		  			for(int i=0;i<cam.size();i++)
		  				cam[3]->setLocation(vector3d(tempPLocation15.x,tempPLocation15.y,tempPLocation15.z));
		  		//unsigned int map=objLoad.load("data/decor/map10.obj");	
		  		//Pobj10.push_back(new Pobject("map",map,vector3d(tempPLocation10.x,tempPLocation10.y,tempPLocation10.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation10.x,tempPRotation10.y,tempPRotation10.z),vector3d(tempPScale10.x,tempPScale10.y,tempPScale10.z)));	
		  		
		  		
		  		}	 	 
		  		
		  		
		  		if(previousWord=="PlocZ_16:")
		  		{
		  			tempColScreen.z=atof(word.c_str());
		  			col=vector3d(tempColScreen.x,tempColScreen.y,tempColScreen.z);
		  		}
		  		
				
				 
				 
		  		
		  		
		
				 
				
		  		
		  	
		  					
		  		
		  		
			 	
			
				  previousWord=word;
			  }
	}
	
		}
		  
		  }
	}
	else
	{
		std::cout<<"File not open"<<std::endl;
	}
}


void setup:: drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void setup::mode2D()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.5,2,5,5);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	enable2D(960,540);
	enable2D(960,540,obj);
	enable2D(960,540,obj2);
	enable2D(960,540,obj3);
	enable2D(960,540,obj4);
	enable2D(960,540,obj5);
	enable2D(960,540,Pobj);
	enable2D(960,540,Pobj2);
	enable2D(960,540,Pobj3);
	enable2D(960,540,Pobj4);
	enable2D(960,540,Pobj5);
	enable2D(960,540,Pobj6);
	enable2D(960,540,Pobj7);
	enable2D(960,540,Pobj8);
	enable2D(960,540,Pobj9);
	enable2D(960,540,Pobj10);
	enable2D(960,540,pref);
	enable2D(960,540,prefAnim);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
std::string setup::vector2str(vector3d x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
std::string setup::float2str(float x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
void setup::enable2D(int width, int height){

	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
  drawText(-1,-0.8,"time: "+float2str(time*0.05f)); 	
  drawText(-1,0.9,"translation: "); 
  drawText(-1,0.8,"rotation: "); 
  drawText(-1,0.7,"scale: "); 
  drawText(-1,0.6,"color: "); 
	drawText(-1,-0.2,"Angle View: "+float2str(angle)); 
	  drawText(-1,-0.1,"Near Plane: "+float2str(nearPlane)); 
	    drawText(-1,0.0,"Far Plane: "+float2str(farPlane)); 
	glPopMatrix();
}
void setup::enable2D(int width, int height,std::vector<object*> obj_) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red

	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
       drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	    drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	     drawText(-0.7,0.6,vector2str(obj_[i]->getCouleur())); 
	 }
	glPopMatrix();
}
void setup::enable2D(int width, int height,std::vector<prefab*> obj_) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red

	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
       drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	    drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	     
	 }
	glPopMatrix();
}
void setup::enable2D(int width, int height,std::vector<prefabAnim*> obj_) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red

	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
       drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	    drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	    
	 }
	glPopMatrix();
}
void setup::enable2D(int width, int height,std::vector<Pobject*> obj_) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red

	
	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
       drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	    drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	     drawText(-0.7,0.6,vector2str(obj_[i]->getCouleur())); 
	 }
	glPopMatrix();
}	


void setup::colorSky()
{
		if(value==110)
{
	col=vector3d(0.8,0.7,0.7);

}     
if(value==120)
{
	col=vector3d(0.2,0.5,0.5);
	
}
if(value==130)
{
	col=vector3d(0,0,0);

}
if(value==140)
{
	col=vector3d(1.0,0.7,0.8);

}

	for(int i=0;i<sky.size();i++)
sky[i]->drawSkybox(500);


}
void setup::selectCam()
{

	if(value==7)
{
	look=true;
	look2=false;
	look3=false;
}
if(value==8)
{
look=false;
look2=true;
look3=false;
}
if(value==9)
{
	look=false;
	look2=false;
	look3=true;
}


}
bool setup::selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_)
{
	float dist=(sqrt(((objectPointer.x-objectReference.x)*(objectPointer.x-objectReference.x))+((objectPointer.y-objectReference.y)*(objectPointer.y-objectReference.y))+
	((objectPointer.z-objectReference.z)*(objectPointer.z-objectReference.z))));
	if(dist<dist_)
	{
		
		return true;
	}
	return false;
}
void setup::lightAmb()
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
void setup::lightDiffuse()
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
void setup::focal()
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
void setup::moveLight()
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
void setup::fog()
{
glEnable(GL_FOG) ;
GLfloat fogcolor[4] = {0.5, 0.5, 0.5, 1} ;
GLint fogmode = GL_EXP ;
glFogi (GL_FOG_MODE, fogmode) ;
glFogfv(GL_FOG_COLOR, fogcolor) ;
glFogf(GL_FOG_DENSITY, intensity_fog) ;
glFogf(GL_FOG_START, start_density) ;
glFogf(GL_FOG_END, end_density) ;
}
void setup::lighting()
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
void setup::reshape(int width,int height)
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
glClearColor(col.x,col.y,col.z,1.0);	//Change la couleur du fond
 



}
void setup::reshapeOrtho(int width,int height)
{



glViewport(0,0,width_,height_);// definition de la taille d'affichage de l'angle de la camera
glMatrixMode(GL_PROJECTION);// on chosit le mode projection de la matrice 
glLoadIdentity();// on initialise la matrice
glOrtho(-40,40,-40,40,0.1,4000);
glMatrixMode(GL_MODELVIEW);// on change de mode d'affichage, on reload une nouvelle matrice de transformation de modelisation
glEnable(GL_DEPTH_TEST);	//Active le depth test







}
void setup::scaleObject(std::vector<object*> obj_)
{
	
		for(int i=0;i<obj_.size();i++)
	 if(value==400 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==410 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==420 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==430 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0.1,0.1));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==440 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==450 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,-0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==460 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,-0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==470 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,-0.1,-0.1));
	 
	
}
void setup::scaleObject(std::vector<Pobject*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==400 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==410 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==420 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==430 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0.1,0.1));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==440 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==450 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,-0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==460 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,-0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==470 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,-0.1,-0.1));
	 
		
		
		
}

void setup::scaleObject(std::vector<prefab*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==400 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==410 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==420 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==430 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0.1,0.1));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==440 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==450 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,-0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==460 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,-0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==470 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,-0.1,-0.1));
	 
		
		
		
}
void setup::scaleObject(std::vector<prefabAnim*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==400 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==410 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==420 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==430 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0.1,0.1,0.1));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==440 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==450 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,-0.1,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==460 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(0,0,-0.1));
	 
	  
	  	for(int i=0;i<obj_.size();i++)
	   if(value==470 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setScale(vector3d(-0.1,-0.1,-0.1));
	 
		
		
		
}
void setup::rotateObject(std::vector<object*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==200 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==210 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0.5,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==220 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==230 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0.5,0.5));


	for(int i=0;i<obj_.size();i++)
	 if(value==240 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==250 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,-0.5,0));
	

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==260 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,-0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==270 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,-0.5,-0.5));
	 	
	 
}
void setup::rotateObject(std::vector<Pobject*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==200 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==210 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0.5,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==220 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==230 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0.5,0.5));


	for(int i=0;i<obj_.size();i++)
	 if(value==240 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==250 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,-0.5,0));
	

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==260 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,-0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==270 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,-0.5,-0.5));
	 	
	 
}
void setup::rotateObject(std::vector<prefab*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==200 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==210 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0.5,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==220 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==230 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0.5,0.5));


	for(int i=0;i<obj_.size();i++)
	 if(value==240 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==250 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,-0.5,0));
	

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==260 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,-0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==270 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,-0.5,-0.5));
	 	
	 
}

void setup::rotateObject(std::vector<prefabAnim*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==200 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==210 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0.5,0));
	 

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==220 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==230 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0.5,0.5,0.5));


	for(int i=0;i<obj_.size();i++)
	 if(value==240 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==250 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,-0.5,0));
	

	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==260 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(0,0,-0.5));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==270 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setRotation(vector3d(-0.5,-0.5,-0.5));
	 	
	 
}

void setup::colorObject(std::vector<object*> obj_)
{
		for(int i=0;i<obj_.size();i++)
	 if(value==500 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(0.1f,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==510 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(0,0.1f,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==520 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(0,0,0.1f));
	

	  	for(int i=0;i<obj_.size();i++)
	   if(value==530 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(0.1f,0.1f,0.1f));
	 
	 
	 	for(int i=0;i<obj_.size();i++)
	 if(value==540 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(-0.1f,0,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==550 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(0,-0.1f,0));


	 	for(int i=0;i<obj_.size();i++)
	 	 if(value==560 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(0,0,-0.1f));
	

	  	for(int i=0;i<obj_.size();i++)
	   if(value==570 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	 obj_[i]->setCouleurInc(vector3d(-0.1f,-0.1f,-0.1f));
	 
}






void setup::translateObject(std::vector<object*> obj_)
{
	
	for(int i=0;i<obj_.size();i++)	
	if( value==150 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,obj_[i]->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if(  value==160 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,p->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==170 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,obj_[i]->getLocation().y,p->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==180 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,p->getLocation().y,p->getLocation().z));
		
}
void setup::translateObject(std::vector<Pobject*> obj_)
{
	
	for(int i=0;i<obj_.size();i++)	
	if( value==150 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,obj_[i]->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if(  value==160 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,p->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==170 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,obj_[i]->getLocation().y,p->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==180 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,p->getLocation().y,p->getLocation().z));
		
}
void setup::translateObject(std::vector<prefab*> obj_)
{

	for(int i=0;i<obj_.size();i++)	
	if( value==150 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,obj_[i]->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if(  value==160 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,p->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==170 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,obj_[i]->getLocation().y,p->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==180 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,p->getLocation().y,p->getLocation().z));
		
}

void setup::translateObject(std::vector<prefabAnim*> obj_)
{
	

	for(int i=0;i<obj_.size();i++)	
	if( value==150 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,obj_[i]->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if(  value==160 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,p->getLocation().y,obj_[i]->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==170 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,obj_[i]->getLocation().y,p->getLocation().z));
				for(int i=0;i<obj_.size();i++)	
	if( value==180 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
		obj_[i]->setLocation(vector3d(p->getLocation().x,p->getLocation().y,p->getLocation().z));
}




void setup::controlKeyboard(char key,int x, int y)
{

switch (key)
	{
		case 32:
	
		 if(lanchGame==false )
		 {
		 	moveLight();
		focal();
			 lightAmb();
		 lightDiffuse();
		 reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		if(value==280)
		fog_=true;
			if(value==290)
		fog_=false;
		if(value==300)
		 intensity_fog+=0.001f;
		 if(intensity_fog>=1.0f)
		 intensity_fog=1.0f;
		 	if(value==310)
		 intensity_fog-=0.001f;
		 if(intensity_fog<=0.0f)
		 intensity_fog=0.0f;
		 
		 	if(value==320)
		start_density+=0.1f;
		 if(start_density>=100.0f)
		 start_density=100.0f;
		 	if(value==330)
		 start_density-=0.1f;
		 if(start_density<=5.0f)
		 start_density=5.0f;
		 
		 
		 	if(value==340)
		end_density+=0.1f;
		 if(end_density>=5000.0f)
		 end_density=5000.0f;
		 	if(value==350)
		 end_density-=0.1f;
		 if(end_density<=50.0f)
		end_density=50.0f;
		 
		scaleObject(obj);
		scaleObject(obj2);
		scaleObject(obj3);
		scaleObject(obj4);
		scaleObject(obj5);
		
		scaleObject(Pobj);
		scaleObject(Pobj2);
		scaleObject(Pobj3);
		scaleObject(Pobj4);
		scaleObject(Pobj5);
		scaleObject(Pobj6);
		scaleObject(Pobj7);
		scaleObject(Pobj8);
		scaleObject(Pobj9);
		scaleObject(Pobj10);
		scaleObject(Pobj11);
		scaleObject(pref);
		scaleObject(prefAnim);
	
		rotateObject(obj);
		rotateObject(obj2);
		rotateObject(obj3);
		rotateObject(obj4);
		rotateObject(obj5);
		
		
		rotateObject(Pobj);
		rotateObject(Pobj2);
		rotateObject(Pobj3);
		rotateObject(Pobj4);
		rotateObject(Pobj5);
		rotateObject(Pobj6);
		rotateObject(Pobj7);
		rotateObject(Pobj8);
		rotateObject(Pobj9);
		rotateObject(Pobj10);
		rotateObject(Pobj11);
		rotateObject(pref);
		rotateObject(prefAnim);
		
		
		
		translateObject(obj);
		translateObject(obj2);
		translateObject(obj3);
		translateObject(obj4);
		translateObject(obj5);
		
		translateObject(Pobj);
		translateObject(Pobj2);
		translateObject(Pobj3);
		translateObject(Pobj4);
		translateObject(Pobj5);
		translateObject(Pobj6);
		translateObject(Pobj7);
		translateObject(Pobj8);
		translateObject(Pobj9);
		translateObject(Pobj10);
		translateObject(Pobj11);
		translateObject(pref);
		translateObject(prefAnim);
		
	 	colorObject(obj);
	 	colorObject(obj2);
	 	colorObject(obj3);
	 	colorObject(obj4);
	 	colorObject(obj5);
	 	
		if(value==2100)
		loadToFile();
	
		for(int i=0;i<obj.size();i++)
if(value==1600 && selectObject(obj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj[i]->setDynamic(true);
}
		for(int i=0;i<obj.size();i++)
if(value==1700 && selectObject(obj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj[i]->setDynamic(false);
}


		for(int i=0;i<obj2.size();i++)
if(value==1600 && selectObject(obj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj2[i]->setDynamic(true);
}
		for(int i=0;i<obj2.size();i++)
if(value==1700 && selectObject(obj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj2[i]->setDynamic(false);
}

		for(int i=0;i<obj3.size();i++)
if(value==1600 && selectObject(obj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj3[i]->setDynamic(true);
}
		for(int i=0;i<obj3.size();i++)
if(value==1700 && selectObject(obj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj3[i]->setDynamic(false);
}


		for(int i=0;i<obj4.size();i++)
if(value==1600 && selectObject(obj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj4[i]->setDynamic(true);
}
		for(int i=0;i<obj4.size();i++)
if(value==1700 && selectObject(obj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj4[i]->setDynamic(false);
}
		for(int i=0;i<pref.size();i++)
if(value==1600 && selectObject(pref[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	pref[i]->setDynamic(true);
}
		for(int i=0;i<pref.size();i++)
if(value==1700 && selectObject(pref[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	pref[i]->setDynamic(false);
}

		for(int i=0;i<prefAnim.size();i++)
if(value==1600 && selectObject(prefAnim[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	prefAnim[i]->setDynamic(true);
}
		for(int i=0;i<prefAnim.size();i++)
if(value==1700 && selectObject(prefAnim[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	prefAnim[i]->setDynamic(false);
}

	for(int i=0;i<obj.size();i++)
if(value==1200 && selectObject(obj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj[i]->setDrive(true);
}
	for(int i=0;i<obj2.size();i++)
if(value==1200 && selectObject(obj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj2[i]->setDrive(true);
}

	for(int i=0;i<obj3.size();i++)
if(value==1200 && selectObject(obj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj3[i]->setDrive(true);
}
	for(int i=0;i<obj4.size();i++)
if(value==1200 && selectObject(obj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj4[i]->setDrive(true);
}

	for(int i=0;i<obj.size();i++)
if(value==1230 && selectObject(obj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj[i]->setDrive(false);
}
	for(int i=0;i<obj2.size();i++)
if(value==1230 && selectObject(obj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj2[i]->setDrive(false);
}

	for(int i=0;i<obj3.size();i++)
if(value==1230 && selectObject(obj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj3[i]->setDrive(false);
}
	for(int i=0;i<obj4.size();i++)
if(value==1230 && selectObject(obj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj4[i]->setDrive(false);
}


	for(int i=0;i<obj.size();i++)
if(value==1250 && selectObject(obj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj[i]->setWalk(true);
}
	for(int i=0;i<obj2.size();i++)
if(value==1250 && selectObject(obj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj2[i]->setWalk(true);
}

	for(int i=0;i<obj3.size();i++)
if(value==1250 && selectObject(obj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj3[i]->setWalk(true);
}
	for(int i=0;i<obj4.size();i++)
if(value==1250 && selectObject(obj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj4[i]->setWalk(true);
}



	for(int i=0;i<obj.size();i++)
if(value==1280 && selectObject(obj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj[i]->setWalk(false);
}
	for(int i=0;i<obj2.size();i++)
if(value==1280 && selectObject(obj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj2[i]->setWalk(false);
}

	for(int i=0;i<obj3.size();i++)
if(value==1280 && selectObject(obj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj3[i]->setWalk(false);
}
	for(int i=0;i<obj4.size();i++)
if(value==1280 && selectObject(obj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	obj4[i]->setWalk(false);
}

	for(int i=0;i<pref.size();i++)
if(value==1200 && selectObject(pref[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	pref[i]->setDrive(true);
}
	for(int i=0;i<pref.size();i++)
if(value==1230 && pref[i]->getDrive() && selectObject(pref[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	pref[i]->setDrive(false);
}
	for(int i=0;i<prefAnim.size();i++)
if(value==1250 && selectObject(prefAnim[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	prefAnim[i]->setWalk(true);
}
	for(int i=0;i<prefAnim.size();i++)
if(value==1280 && prefAnim[i]->getWalk() && selectObject(prefAnim[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
{
	prefAnim[i]->setWalk(false);
}
		if(value==1400)
	reshapeOrtho(width_,height_);
if(value==1500)

	reshape(width_,height_);

if(value==1800)
{
	for(int i=0;i<cam.size();i++)
	cam[i]->setMouseVel(0.1f);
}
if(value==1900)
{
	for(int i=0;i<cam.size();i++)
	cam[i]->setMouseVel(-0.1f);
}
if(value==1)
{

obj2.push_back(new object(vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));

}

if(value==2)
obj.push_back(new object(vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
if(value==3)
obj3.push_back(new object(vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
if(value==4)
obj4.push_back(new object(vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
if(value==10)
obj5.push_back(new object(vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
if(value==11)
{
fileName[10]="data/decor/map.obj";
unsigned int map=objLoad.load(fileName[10]);		
Pobj.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==12)
{
fileName[9]="data/decor/map2.obj";
unsigned int map=objLoad.load(fileName[9]);		
Pobj2.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==13)
{
fileName[8]="data/decor/map3.obj";
unsigned int map=objLoad.load(fileName[8]);		
Pobj3.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==14)
{
fileName[7]="data/decor/map4.obj";
unsigned int map=objLoad.load(fileName[7]);		
Pobj4.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==15)
{
fileName[6]="data/decor/map5.obj";
unsigned int map=objLoad.load(fileName[6]);		
Pobj5.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==16)
{
fileName[5]="data/decor/map6.obj";
unsigned int map=objLoad.load(fileName[5]);	
Pobj6.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==17)
{
fileName[4]="data/decor/map7.obj";
unsigned int map=objLoad.load(fileName[4]);	
Pobj7.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==18)
{
fileName[3]="data/decor/map8.obj";
unsigned int map=objLoad.load(fileName[3]);		
Pobj8.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==19)
{
fileName[2]="data/decor/map9.obj";
unsigned int map=objLoad.load(fileName[2]);		
Pobj9.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==20)
{
fileName[1]="data/decor/map10.obj";
unsigned int map=objLoad.load(fileName[1]);		
Pobj10.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==5)
{

pref.push_back(new prefab("vehicule","data/vehicule.obj",p->getLocation(),vector3d(0,0,0),vector3d(1,1,1)));

}
if(value==6)
{



prefAnim.push_back(new prefabAnim("character",p->getLocation(),vector3d(0,0,0),vector3d(1,1,1)));


}
if(value==21)
{
	
fileName[0]="data/stade2.obj";
unsigned int map=objLoad.load(fileName[0]);	
Pobj11.push_back(new Pobject("stade",map,p->getLocation(),vector3d(0,0,0),vector3d(0,0,0),vector3d(1,1,1)));
}
   
   

		 if(value==145)
	sky.push_back(new skybox());
}

	break;
		case 'w':

			break;
			case 'f':
			cam[0]->setLocation(vector3d(0,0,0));
			if(obj.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj.begin(); i != obj.end();++i)
					{
						if(count==obj.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj.pop_back();
		}
		
		
					
			if(obj2.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj2.begin(); i != obj2.end();++i)
					{
						if(count==obj2.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj2.pop_back();
		}
			 
					
			if(obj3.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj3.begin(); i != obj3.end();++i)
					{
						if(count==obj3.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj3.pop_back();
		}
		
		
					
			if(obj4.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj4.begin(); i != obj4.end();++i)
					{
						if(count==obj4.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj4.pop_back();
		}
		
					
			if(obj5.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj5.begin(); i != obj5.end();++i)
					{
						if(count==obj5.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj5.pop_back();
		}
		
					
			if(pref.size()>0)
			{
					int count=0;
					for(std::vector<prefab*>::iterator i = pref.begin(); i != pref.end();++i)
					{
						if(count==pref.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 pref.pop_back();
		}
		
					
			if(prefAnim.size()>0)
			{
					int count=0;
					for(std::vector<prefabAnim*>::iterator i = prefAnim.begin(); i != prefAnim.end();++i)
					{
						if(count==prefAnim.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 prefAnim.pop_back();
		}
		
					
			if(Pobj.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj.begin(); i != Pobj.end();++i)
					{
						if(count==Pobj.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj.pop_back();
		}
				if(Pobj2.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj2.begin(); i != Pobj2.end();++i)
					{
						if(count==Pobj2.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj2.pop_back();
		}
				if(Pobj3.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj3.begin(); i != Pobj3.end();++i)
					{
						if(count==Pobj3.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj3.pop_back();
		}
		
				if(Pobj4.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj4.begin(); i != Pobj4.end();++i)
					{
						if(count==Pobj4.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj4.pop_back();
		}
				if(Pobj5.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj5.begin(); i != Pobj5.end();++i)
					{
						if(count==Pobj5.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj5.pop_back();
		}
		
				if(Pobj6.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj6.begin(); i != Pobj6.end();++i)
					{
						if(count==Pobj6.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj6.pop_back();
		}
				if(Pobj7.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj7.begin(); i != Pobj7.end();++i)
					{
						if(count==Pobj7.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj7.pop_back();
		}
		
				if(Pobj8.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj8.begin(); i != Pobj8.end();++i)
					{
						if(count==Pobj8.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj8.pop_back();
		}
		
				if(Pobj9.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj9.begin(); i != Pobj9.end();++i)
					{
						if(count==Pobj9.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj9.pop_back();
		}
		
				if(Pobj10.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj10.begin(); i != Pobj10.end();++i)
					{
						if(count==Pobj10.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj10.pop_back();
		}
			 break;
			case 'm':
				saveToFile();
				break;
			
			
			
			case 'x':
if(lanchGame==false)
{

				for(int i=0;i<obj2.size();i++)
				if(value==900 && selectObject(obj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj2.erase(obj2.begin()+i);
		for(int i=0;i<obj.size();i++)
		if(value==900 && selectObject(obj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))

	obj.erase(obj.begin()+i);
	
	for(int i=0;i<obj3.size();i++)
	if(value==900 && selectObject(obj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj3.erase(obj3.begin()+i);
	for(int i=0;i<obj4.size();i++)
		if(value==900 && selectObject(obj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj4.erase(obj4.begin()+i);
		for(int i=0;i<obj5.size();i++)
		if(value==900 && selectObject(obj5[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj5.erase(obj5.begin()+i);
	for(int i=0;i<pref.size();i++)
		if(value==900 && selectObject(pref[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	pref.erase(pref.begin()+i);
		for(int i=0;i<prefAnim.size();i++)
		if(value==900 && selectObject(prefAnim[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	prefAnim.erase(prefAnim.begin()+i);
		
		
		
		
		
		for(int i=0;i<Pobj.size();i++)
				if(value==900 && selectObject(Pobj[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj.erase(Pobj.begin()+i);
		for(int i=0;i<Pobj2.size();i++)
		if(value==900 && selectObject(Pobj2[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))

	Pobj2.erase(Pobj2.begin()+i);
	
	for(int i=0;i<Pobj3.size();i++)
	if(value==900 && selectObject(Pobj3[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj3.erase(Pobj3.begin()+i);
	for(int i=0;i<Pobj4.size();i++)
		if(value==900 && selectObject(Pobj4[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj4.erase(Pobj4.begin()+i);
		for(int i=0;i<Pobj5.size();i++)
		if(value==900 && selectObject(Pobj5[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj5.erase(Pobj5.begin()+i);
	for(int i=0;i<Pobj6.size();i++)
		if(value==900 && selectObject(Pobj6[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj6.erase(Pobj6.begin()+i);
	for(int i=0;i<Pobj7.size();i++)
		if(value==900 && selectObject(Pobj7[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj7.erase(Pobj7.begin()+i);
	for(int i=0;i<Pobj8.size();i++)
		if(value==900 && selectObject(Pobj8[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj8.erase(Pobj8.begin()+i);
	for(int i=0;i<Pobj9.size();i++)
		if(value==900 && selectObject(Pobj9[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj9.erase(Pobj9.begin()+i);
	for(int i=0;i<Pobj10.size();i++)
		if(value==900 && selectObject(Pobj10[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj10.erase(Pobj10.begin()+i);
		for(int i=0;i<Pobj11.size();i++)
		if(value==900 && selectObject(Pobj11[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj11.erase(Pobj11.begin()+i);
	
		 if(value==145)
		 for(int i=0;i<sky.size();i++)
		 sky.erase(sky.begin()+i);
		 
		 
	}
				break;
	
				
		case 's' :
		case 'S' :
			glutDetachMenu(GLUT_RIGHT_BUTTON);
		
			if (nTue==0)
			{
				printf ("\nMenu detache.\n");
				printf ("Pour le reattacher\n");
				printf ("\tau bouton gauche, taper g ou G\n\tau bouton droit, taper d ou D\n\tau bouton du milieu, taper m ou M\n\n");
				nTue=1;
			}
			break;

		case 'g' :
			
		case 'G' :
			
		
			glutSetMenu ( nMenuprincipal ); // Choisit le menu courant
			glutAttachMenu(GLUT_RIGHT_BUTTON); // Attache le menu au bouton gauche
			nTue=0;
			break;
	
				
		
		}
	
	
}
void setup::passiveKeyboard(char key,int x, int y)
{

}
void setup::passiveSpecialKeyboard(int key,int x, int y)
{
switch(key)
{
	case GLUT_KEY_UP:
		keyup=false;
		break;
		case GLUT_KEY_DOWN:
			keydown=false;
			break;
			case GLUT_KEY_LEFT:
				keyleft=false;
				break;
				case GLUT_KEY_RIGHT:
					keyright=false;
					break;
}

}
void setup::controlSpecialKeyboard(int key,int x, int y)
{
switch(key)
{
	case GLUT_KEY_UP:
		keyup=true;
	
		break;
		case GLUT_KEY_DOWN:
			keydown=true;
			
			break;
			case GLUT_KEY_LEFT:
				keyleft=true;
			
				break;
				case GLUT_KEY_RIGHT:
					keyright=true;
					
					break;
}

}

void setup::mouseMotion(int x,int y)
{

cam[0]->control(x,y);
cam[0]->moveLateral(0.0f,x,y);

	
}
void setup::mouseMotion2(int x,int y)
{
	


cam[1]->moveLateral(0.0f,x,y);
	
}
void setup::mouseMotion3(int x,int y)
{
	


cam[2]->moveLateral(-90.0f,x,y);
	
}
void setup::mouseMotion4(int x,int y)
{
	


cam[3]->moveLateral(-90.0f,x,y);
	
}
void setup::passiveMotion(int x,int y)
{

}
void setup::mouse(int button, int state, int x, int y)
{
	cam[0]->mouse(button,state,x,y);



//if(button==GLUT_LEFT_BUTTON)





}
void setup::mouse2(int button, int state, int x, int y)
{

	cam[1]->mouse(button,state,x,y);

}
void setup::mouse3(int button, int state, int x, int y)
{

	cam[2]->mouse(button,state,x,y);

}
void setup::mouse4(int button, int state, int x, int y)
{

	cam[3]->mouse(button,state,x,y);

}
void setup::mouseWheel(int x, int y, int z, int w)
{
	if(y<0)
	{

	cam[0]->moveCamera(180.0f);
	
	}
	else
	{

	cam[0]->moveCamera(0.0f);
	}

}

void setup::mouseWheel2(int x, int y, int z, int w)
{
	if(y<0)
	{

	cam[1]->moveCamera(180.0f);
	
	}
	else
	{

	cam[1]->moveCamera(0.0f);
	}

}

void setup::mouseWheel3(int x, int y, int z, int w)
{
	if(y<0)
	{

	cam[2]->moveCamera(90.0f);
	
	}
	else
	{

	cam[2]->moveCamera(-90.0f);
	}

}
void setup::mouseWheel4(int x, int y, int z, int w)
{
	if(y<0)
	{

	cam[3]->moveCamera(90.0f);
	
	}
	else
	{

	cam[3]->moveCamera(-90.0f);
	}

}

bool setup::startG()
{
	return lanchGame;
}
