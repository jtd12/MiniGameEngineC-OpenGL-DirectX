#include"API_OPENGL.h"

APIOPENGL::APIOPENGL()
{


	
}

void APIOPENGL::initGL()
{
	
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
	view_=new view();	
	sky=new generateSkybox();
	data_=new datas(sky);
	gameMode_=new gameMode();
	loadToFile();
}

APIOPENGL::~APIOPENGL()
{
	for(int i=0;i<pref.size();i++)
	delete pref[i];
		for(int i=0;i<prefAnim.size();i++)
	delete prefAnim[i];
	delete g;
	delete p;
/*	for(int i=0;i<sky.size();i++)
	delete sky[i];*/
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

void APIOPENGL::loadToFile()
{
	data_->loadToFile();
	obj=data_->equalObj();
	obj2=data_->equalObj2();
	obj3=data_->equalObj3();
	obj4=data_->equalObj4();
	obj5=data_->equalObj5();
	Pobj=data_->equalPobj();
	Pobj2=data_->equalPobj2();
	Pobj3=data_->equalPobj3();
	Pobj4=data_->equalPobj4();
	Pobj5=data_->equalPobj5();
	Pobj6=data_->equalPobj6();
	Pobj7=data_->equalPobj7();
	Pobj8=data_->equalPobj8();
	Pobj9=data_->equalPobj9();
	Pobj10=data_->equalPobj10();
	pref=data_->equalPref();
	prefAnim=data_->equalPrefAnim();
	cam=data_->equalCam();
	sky=data_->equalSky();

}
 
void APIOPENGL::saveToFile()
{
      	data_->obj111=obj;
   		data_->saveToFile();
}
	
	

void APIOPENGL::update()
{
	

gameMode_->update();

}
void APIOPENGL::show()
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
	//fog();

  glDisable(GL_FOG);


g->show();
p->show(); 

  glEnable(GL_FOG);
/* 
  if(fog_)
  glEnable(GL_FOG);
	if(fog_==false)
{
glDisable(GL_FOG);

}
*/




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

//colorSky();
 //lighting();
//mode2D();
//clavier();


//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}
void APIOPENGL::show2()
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
//	fog();

  glDisable(GL_FOG);

g->show();
p->show(); 

  glEnable(GL_FOG);
/*
  if(fog_)
  glEnable(GL_FOG);
	if(fog_==false)
{
glDisable(GL_FOG);

}
*/

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

//colorSky();

//mode2D();
 //lighting();
//clavier();


//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}
void APIOPENGL::show3()
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

//	fog();

  glDisable(GL_FOG);

g->show();
p->show(); 
  glEnable(GL_FOG);
/*
  if(fog_)
  glEnable(GL_FOG);
	if(fog_==false)
{
glDisable(GL_FOG);

}
*/


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



//colorSky();

 //lighting();
//mode2D();
//clavier();


//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}
void APIOPENGL::show4()
{
	update();
//clavierActif(); 






glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice

//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
if(gameMode_->getLook()==false && gameMode_->getLook2()==false || gameMode_->getLook3())
{

	gluLookAt(40,8,10,5,0,0,0,1,0);


 
//p->setLocation(cam[0]->getLocation());

p->setLocation(cam[0]->getLocation());
cam[0]->update();
}
	for(int i=0;i<pref.size();i++)
if(gameMode_->getLook() && gameMode_->getLook2()==false && pref[i]->getDrive())
{


	
	vector3d camPos=vector3d(pref[i]->getLocation().x-cos(pref[i]->getRotation().y*M_PI/180)*-5,pref[i]->getLocation().y+3,pref[i]->getLocation().z+sin(pref[i]->getRotation().y*M_PI/180)*-5);
	vector3d lookAt = vector3d(pref[i]->getLocation().x,pref[i]->getLocation().y,pref[i]->getLocation().z);
	gluLookAt(camPos.x,camPos.y,camPos.z,lookAt.x,lookAt.y,lookAt.z,0,1,0);

}
	for(int i=0;i<prefAnim.size();i++)
if(gameMode_->getLook2() && gameMode_->getLook()==false && prefAnim[i]->getWalk())
{


	
	vector3d camPos=vector3d(prefAnim[i]->getLocation().x+cos(prefAnim[i]->getRotation().y*M_PI/180)*-5,prefAnim[i]->getLocation().y+3,prefAnim[i]->getLocation().z-sin(prefAnim[i]->getRotation().y*M_PI/180)*-5);
	vector3d lookAt = vector3d(prefAnim[i]->getLocation().x,prefAnim[i]->getLocation().y,prefAnim[i]->getLocation().z);
	gluLookAt(camPos.x,camPos.y,camPos.z,lookAt.x,lookAt.y,lookAt.z,0,1,0);

}


  glDisable(GL_FOG);

g->show();
p->show(); 
if(gameMode_->getTime()<25)
hud_[0]->show();
  glEnable(GL_FOG);

 /* 
  if(fog_)
  glEnable(GL_FOG);
 // 	fog();
	if(fog_==false)
{
glDisable(GL_FOG);

}

*/


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
for(int i=0;i<pref.size();i++)
pref[i]->show();
for(int i=0;i<prefAnim.size();i++)
prefAnim[i]->show();



//selectCam();


//colorSky();

 //lighting();


//mode2D();
	


//clavier();

//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}


void APIOPENGL::reshape(int width,int height)
 {
 	view_->reshape(width,height);
 }
 
 
void APIOPENGL::reshapeOrtho(int width,int height)
 {
 	view_->reshapeOrtho(width,height);
 }

void APIOPENGL::controlKeyboard(char key,int x, int y)
{

switch (key)
	{
		case 32:
	
	if(value==1)
{

obj2.push_back(new object(vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));

}
		 if(gameMode_->getLanchGame()==false )
		 {
		 //	moveLight();
		//focal();
		//	 lightAmb();
	//	 lightDiffuse();
		// reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	/*	if(value==280)
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
		*/
		 
	/*	scaleObject(obj);
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

		translateObject(pref);
		translateObject(prefAnim);
		
	 	colorObject(obj);
	 	colorObject(obj2);
	 	colorObject(obj3);
	 	colorObject(obj4);
	 	colorObject(obj5);
	 	*/
	 	
		if(value==2100)
		data_->loadToFile();
	/*
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
*/
	/*	if(value==1400)
	reshapeOrtho(width_,height_);
if(value==1500)

	reshape(width_,height_);
*/
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

   

	//	 if(value==145)
	//sky.push_back(new skybox());
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
			
		//case 'b':
				//CopyFile ("Projet1.exe", fileName[11].c_str(), TRUE);
			
			case 'x':
if(gameMode_->getLanchGame()==false)
{

			/*	for(int i=0;i<obj2.size();i++)
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
	
		 if(value==145)
		 for(int i=0;i<sky.size();i++)
		 sky.erase(sky.begin()+i);
		 */
		 
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
void APIOPENGL::passiveKeyboard(char key,int x, int y)
{

}
void APIOPENGL::passiveSpecialKeyboard(int key,int x, int y)
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
void APIOPENGL::controlSpecialKeyboard(int key,int x, int y)
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

void APIOPENGL::mouseMotion(int x,int y)
{

cam[0]->control(x,y);
cam[0]->moveLateral(0.0f,x,y);

	
}
void APIOPENGL::mouseMotion2(int x,int y)
{
	


cam[1]->moveLateral(0.0f,x,y);
	
}
void APIOPENGL::mouseMotion3(int x,int y)
{
	


cam[2]->moveLateral(-90.0f,x,y);
	
}
void APIOPENGL::mouseMotion4(int x,int y)
{
	


cam[3]->moveLateral(-90.0f,x,y);
	
}
void APIOPENGL::passiveMotion(int x,int y)
{

}
void APIOPENGL::mouse(int button, int state, int x, int y)
{
	cam[0]->mouse(button,state,x,y);



//if(button==GLUT_LEFT_BUTTON)





}
void APIOPENGL::mouse2(int button, int state, int x, int y)
{

	cam[1]->mouse(button,state,x,y);

}
void APIOPENGL::mouse3(int button, int state, int x, int y)
{

	cam[2]->mouse(button,state,x,y);

}
void APIOPENGL::mouse4(int button, int state, int x, int y)
{

	cam[3]->mouse(button,state,x,y);

}
void APIOPENGL::mouseWheel(int x, int y, int z, int w)
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

void APIOPENGL::mouseWheel2(int x, int y, int z, int w)
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

void APIOPENGL::mouseWheel3(int x, int y, int z, int w)
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
void APIOPENGL::mouseWheel4(int x, int y, int z, int w)
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

bool APIOPENGL::startG()
{
	gameMode_->startG();
}

