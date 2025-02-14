#include"API_OPENGL.h"

APIOPENGL::APIOPENGL()
{


	
}

void APIOPENGL::initGL()
{
	
	g=new grid();
	p=new pointer(vector3d(0,0,0));
	hud_.push_back(new hud("data/hud.bmp",593,321));
	for(int i=0;i<4;i++)
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
	light_=new light(p);
	data_=new datas(view_->sky);
	gameMode_=new gameMode();
	loadToFile();
	supp=new supression();
	trans=new transformation(p);
	add=new ajout();
	WIDTH=960;
 	HEIGHT=540;

}

APIOPENGL::~APIOPENGL()
{
	for(int i=0;i<pref.size();i++)
	delete pref[i];
		for(int i=0;i<prefAnim.size();i++)
	delete prefAnim[i];
	delete g;
	delete p;
	delete add;
	delete trans;
	delete supp;
	delete light_;
/*	for(int i=0;i<sky.size();i++)
	delete sky[i];*/
for(int i=0;i<cam.size();i++)
	delete cam[i];
	

}

void APIOPENGL::loadToFile()
{
	data_->loadToFile();
	loadToFile2();
	obj=data_->ReadequalObj();
	obj2=data_->ReadequalObj2();
	obj3=data_->ReadequalObj3();
	obj4=data_->ReadequalObj4();
	obj5=data_->ReadequalObj5();
	Pobj=data_->ReadequalPobj();
	Pobj2=data_->ReadequalPobj2();
	Pobj3=data_->ReadequalPobj3();
	Pobj4=data_->ReadequalPobj4();
	Pobj5=data_->ReadequalPobj5();
	Pobj6=data_->ReadequalPobj6();
	Pobj7=data_->ReadequalPobj7();
	Pobj8=data_->ReadequalPobj8();
	Pobj9=data_->ReadequalPobj9();
	Pobj10=data_->ReadequalPobj10();
	pref=data_->ReadequalPref();
	prefAnim=data_->ReadequalPrefAnim();
	view_->sky=data_->ReadequalSky();
	
}

void APIOPENGL::loadToFile2()
{
	std::ifstream loadedFile("data/stagelayoutCamera.txt");
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
			  
			   else
			  {
			  if(currentType==typeObj)
			  {
			  	std::istringstream iss(line);
			  	vector3d tempPLocation12=vector3d(0,0,0);
			  	vector3d tempPLocation13=vector3d(0,0,0);
			  	vector3d tempPLocation14=vector3d(0,0,0);
			  	vector3d tempPLocation15=vector3d(0,0,0);
			  	
			  	std::string previousWord="";
			  	
			  		while(iss)
		  	{
		  		std::string word;
		  		iss>>word;
		  		
		  		
		  		
		  		
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
		  		
		  				if(previousWord=="PlocZ_12:")
		  		{
		  			
		  			tempPLocation12.z=atoi(word.c_str());
		  		
		  		//Pobj11.push_back(new Pobject("map",map,vector3d(tempPLocation12.x,tempPLocation12.y,tempPLocation12.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation12.x,tempPRotation12.y,tempPRotation12.z),vector3d(tempPScale12.x,tempPScale12.y,tempPScale12.z)));	
		  	for(int i=0;i<cam.size();i++)
		  				cam[0]->setLocation(vector3d(tempPLocation12.x,tempPLocation12.y,tempPLocation12.z));
		  		
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

	void APIOPENGL::saveToFile2()
{
      
      	std::ofstream loadedFile;
      	loadedFile.open("data/stagelayoutCamera.txt");
         loadedFile<<"Draw Object"<<std::endl;

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
		  
		  loadedFile<<"End Object"<<std::endl; 
	 	 
      	loadedFile.close();
      	std::cout<<"level saved"<<std::endl;
		   

}
 
void APIOPENGL::saveToFile()
{
      	data_->WriteequalObj(obj);
      	data_->WriteequalObj2(obj2);
      	data_->WriteequalObj3(obj3);
      	data_->WriteequalObj4(obj4);
      	data_->WriteequalObj5(obj5);
      	data_->WriteequalPObj(Pobj);
      	data_->WriteequalPObj(Pobj2);
      	data_->WriteequalPObj(Pobj3);
      	data_->WriteequalPObj(Pobj4);
      	data_->WriteequalPObj(Pobj5);
      	data_->WriteequalPObj(Pobj6);
      	data_->WriteequalPObj(Pobj7);
      	data_->WriteequalPObj(Pobj8);
      	data_->WriteequalPObj(Pobj9);
      	data_->WriteequalPObj(Pobj10);
	    data_->WriteequalPrefab(pref);
	    data_->WriteequalPrefabAnim(prefAnim);
	    data_->WriteequalSky(view_->sky);
   		data_->saveToFile();
   		saveToFile2();
}
	
	

void APIOPENGL::update()
{
	
trans->separateObjects(obj, 20, 7);
trans->separateObjects(obj2, 20, 7);
trans->separateObjects(obj3, 20, 7);
trans->separateObjects(obj4, 20, 7);
trans->separateObjects(obj5, 20, 7);

trans->separateObjects(Pobj, 10, 7);
trans->separateObjects(Pobj2, 10, 7);
trans->separateObjects(Pobj3, 10, 7);
trans->separateObjects(Pobj4, 10, 7);
trans->separateObjects(Pobj5, 10, 7);
trans->separateObjects(Pobj6, 10, 7);
trans->separateObjects(Pobj7, 10, 7);
trans->separateObjects(Pobj8, 10, 7);
trans->separateObjects(Pobj9, 10, 7);
trans->separateObjects(Pobj10, 20, 7);

trans->separateObjects(pref, 20, 7);
trans->separateObjects(prefAnim, 20, 7);


trans->separateObjects(obj, obj2, 20, 7);
trans->separateObjects(obj, obj3, 20, 7);
trans->separateObjects(obj, obj4, 20, 7);
trans->separateObjects(obj, obj5, 20, 7);

trans->separateObjects(obj2, obj, 20, 7);
trans->separateObjects(obj2, obj3, 20, 7);
trans->separateObjects(obj2, obj4, 20, 7);
trans->separateObjects(obj2, obj5, 20, 7);

trans->separateObjects(obj3, obj, 20, 7);
trans->separateObjects(obj3, obj2, 20, 7);
trans->separateObjects(obj3, obj4, 20, 7);
trans->separateObjects(obj3, obj5, 20, 7);

trans->separateObjects(obj4, obj, 20, 7);
trans->separateObjects(obj4, obj2, 20, 7);
trans->separateObjects(obj4, obj3, 20, 7);
trans->separateObjects(obj4, obj5, 20, 7);

trans->separateObjects(obj5, obj, 20, 7);
trans->separateObjects(obj5, obj2, 20, 7);
trans->separateObjects(obj5, obj3, 20, 7);
trans->separateObjects(obj5, obj4, 20, 7);

trans->separateObjects(obj, pref, 20, 7);
trans->separateObjects(obj, prefAnim, 20, 7);
trans->separateObjects(obj2, pref, 20, 7);
trans->separateObjects(obj2, prefAnim, 20, 7);
trans->separateObjects(obj3, pref, 20, 7);
trans->separateObjects(obj3, prefAnim, 20, 7);
trans->separateObjects(obj4, pref, 20, 7);
trans->separateObjects(obj4, prefAnim, 20, 7);
trans->separateObjects(obj5, pref, 20, 7);
trans->separateObjects(obj5, prefAnim, 20, 7);


trans->separateObjects(obj, Pobj, 10, 7);
trans->separateObjects(obj, Pobj2, 10, 7);
trans->separateObjects(obj, Pobj3, 10, 7);
trans->separateObjects(obj, Pobj4, 10, 7);
trans->separateObjects(obj, Pobj5, 10, 7);
trans->separateObjects(obj, Pobj6, 10, 7);
trans->separateObjects(obj, Pobj7, 10, 7);
trans->separateObjects(obj, Pobj8, 10, 7);
trans->separateObjects(obj, Pobj9, 10, 7);
trans->separateObjects(obj, Pobj10, 10, 7);

trans->separateObjects(obj2, Pobj, 10, 7);
trans->separateObjects(obj2, Pobj2, 10, 7);
trans->separateObjects(obj2, Pobj3, 10, 7);
trans->separateObjects(obj2, Pobj4, 10, 7);
trans->separateObjects(obj2, Pobj5, 10, 7);
trans->separateObjects(obj2, Pobj6, 10, 7);
trans->separateObjects(obj2, Pobj7, 10, 7);
trans->separateObjects(obj2, Pobj8, 10, 7);
trans->separateObjects(obj2, Pobj9, 10, 7);
trans->separateObjects(obj2, Pobj10, 10, 7);

trans->separateObjects(obj3, Pobj, 10, 7);
trans->separateObjects(obj3, Pobj2, 10, 7);
trans->separateObjects(obj3, Pobj3, 10, 7);
trans->separateObjects(obj3, Pobj4, 10, 7);
trans->separateObjects(obj3, Pobj5, 10, 7);
trans->separateObjects(obj3, Pobj6, 10, 7);
trans->separateObjects(obj3, Pobj7, 10, 7);
trans->separateObjects(obj3, Pobj8, 10, 7);
trans->separateObjects(obj3, Pobj9, 10, 7);
trans->separateObjects(obj3, Pobj10, 10, 7);

trans->separateObjects(obj4, Pobj, 10, 7);
trans->separateObjects(obj4, Pobj2, 10, 7);
trans->separateObjects(obj4, Pobj3, 10, 7);
trans->separateObjects(obj4, Pobj4, 10, 7);
trans->separateObjects(obj4, Pobj5, 10, 7);
trans->separateObjects(obj4, Pobj6, 10, 7);
trans->separateObjects(obj4, Pobj7, 10, 7);
trans->separateObjects(obj4, Pobj8, 10, 7);
trans->separateObjects(obj4, Pobj9, 10, 7);
trans->separateObjects(obj4, Pobj10, 10, 7);

trans->separateObjects(obj5, Pobj, 10, 7);
trans->separateObjects(obj5, Pobj2, 10, 7);
trans->separateObjects(obj5, Pobj3, 10, 7);
trans->separateObjects(obj5, Pobj4, 10, 7);
trans->separateObjects(obj5, Pobj5, 10, 7);
trans->separateObjects(obj5, Pobj6, 10, 7);
trans->separateObjects(obj5, Pobj7, 10, 7);
trans->separateObjects(obj5, Pobj8, 10, 7);
trans->separateObjects(obj5, Pobj9, 10, 7);
trans->separateObjects(obj5, Pobj10, 10, 7);

trans->separateObjects(pref, Pobj, 10, 7);
trans->separateObjects(pref, Pobj2, 10, 7);
trans->separateObjects(pref, Pobj3, 10, 7);
trans->separateObjects(pref, Pobj4, 10, 7);
trans->separateObjects(pref, Pobj5, 10, 7);
trans->separateObjects(pref, Pobj6, 10, 7);
trans->separateObjects(pref, Pobj7, 10, 7);
trans->separateObjects(pref, Pobj8, 10, 7);
trans->separateObjects(pref, Pobj9, 10, 7);
trans->separateObjects(pref, Pobj10, 10, 7);

trans->separateObjects(prefAnim, Pobj, 10, 7);
trans->separateObjects(prefAnim, Pobj2, 10, 7);
trans->separateObjects(prefAnim, Pobj3, 10, 7);
trans->separateObjects(prefAnim, Pobj4, 10, 7);
trans->separateObjects(prefAnim, Pobj5, 10, 7);
trans->separateObjects(prefAnim, Pobj6, 10, 7);
trans->separateObjects(prefAnim, Pobj7, 10, 7);
trans->separateObjects(prefAnim, Pobj8, 10, 7);
trans->separateObjects(prefAnim, Pobj9, 10, 7);
trans->separateObjects(prefAnim, Pobj10, 10, 7);

trans->separateObjects(prefAnim, pref, 20, 7);



gameMode_->update();

}

void APIOPENGL::show()
{
//clavierActif(); 

update();
light_->ShowLight();

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice
gluLookAt(1,1,10,1,0,0,0,1,0);
//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
p->setLocation(cam[0]->getLocation());
cam[3]->update();
	//fog();



g->show();
p->show(); 


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

view_->sky->colorSky();
light_->lighting();
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
light_->ShowLight();

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice

//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
gluLookAt(12,18,1,12,0,0,0,1,0);
	p->setLocation(cam[0]->getLocation());
cam[2]->update();
//	fog();


g->show();
p->show(); 


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

view_->sky->colorSky();

//mode2D();
  light_->lighting();
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
light_->ShowLight();

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glMatrixMode(GL_MODELVIEW);// choix du mode d'affichage en modelview
glLoadIdentity();// initialisation de la matrice

//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
gluLookAt(12,1,1,0,0,0,0,1,0);

p->setLocation(cam[0]->getLocation());	
cam[1]->update();

//	fog();


g->show();
p->show(); 

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



view_->sky->colorSky();

  light_->lighting();
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
 
light_->ShowLight();

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


g->show();
p->show(); 


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


view_->sky->colorSky();

light_->lighting();


//mode2D();
	


//clavier();

//theCube();
glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}



void APIOPENGL::reshape(int width,int height)
 {
 	WIDTH=width;
 	HEIGHT=height;
 	view_->reshape(WIDTH,HEIGHT);
 }
 
 
void APIOPENGL::reshapeOrtho(int width,int height)
 {
 	WIDTH=width;
 	HEIGHT=height;
 	view_->reshapeOrtho(WIDTH,HEIGHT);
 }

void APIOPENGL::controlKeyboard(char key,int x, int y)
{

switch (key)
	{
		case 32:
	
		 if(gameMode_->getLanchGame()==false )
		 {
		    light_->moveLight();
			view_->focal();
		    light_->lightAmb();
	        light_->lightDiffuse();
	        
		reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
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
		 
		trans->scaleObject(obj);
		trans->scaleObject(obj2);
		trans->scaleObject(obj3);
		trans->scaleObject(obj4);
		trans->scaleObject(obj5);
		
		trans->scaleObject(Pobj);
		trans->scaleObject(Pobj2);
		trans->scaleObject(Pobj3);
		trans->scaleObject(Pobj4);
		trans->scaleObject(Pobj5);
		trans->scaleObject(Pobj6);
		trans->scaleObject(Pobj7);
		trans->scaleObject(Pobj8);
		trans->scaleObject(Pobj9);
		trans->scaleObject(Pobj10);
		trans->scaleObject(pref);
		trans->scaleObject(prefAnim);
	
		trans->rotateObject(obj);
		trans->rotateObject(obj2);
		trans->rotateObject(obj3);
		trans->rotateObject(obj4);
		trans->rotateObject(obj5);
		
		
		trans->rotateObject(Pobj);
		trans->rotateObject(Pobj2);
		trans->rotateObject(Pobj3);
		trans->rotateObject(Pobj4);
		trans->rotateObject(Pobj5);
		trans->rotateObject(Pobj6);
		trans->rotateObject(Pobj7);
		trans->rotateObject(Pobj8);
		trans->rotateObject(Pobj9);
		trans->rotateObject(Pobj10);
		trans->rotateObject(pref);
		trans->rotateObject(prefAnim);
		
		
		
		trans->translateObject(obj);
		trans->translateObject(obj2);
		trans->translateObject(obj3);
		trans->translateObject(obj4);
		trans->translateObject(obj5);
		
		trans->translateObject(Pobj);
		trans->translateObject(Pobj2);
		trans->translateObject(Pobj3);
		trans->translateObject(Pobj4);
		trans->translateObject(Pobj5);
		trans->translateObject(Pobj6);
		trans->translateObject(Pobj7);
		trans->translateObject(Pobj8);
		trans->translateObject(Pobj9);
		trans->translateObject(Pobj10);

		trans->translateObject(pref);
		trans->translateObject(prefAnim);
		
	 	trans->colorObject(obj);
	 	trans->colorObject(obj2);
	 	trans->colorObject(obj3);
	 	trans->colorObject(obj4);
	 	trans->colorObject(obj5);
	 	
	 	
	if(value==2100)
		data_->loadToFile();


	if(value==1400)
	  reshapeOrtho(WIDTH,HEIGHT);
	
	if(value==1500)
	  reshape(WIDTH,HEIGHT);

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

add->update(p,obj,obj2,obj3,obj4,obj5,Pobj,Pobj2,Pobj3,Pobj4,Pobj5,Pobj6,Pobj7,Pobj8,Pobj9,Pobj10,pref,prefAnim,fileName,objLoad);
   

if(value==145)
	view_->sky->skyb.push_back(new skybox());
}

	break;
		case 'w':

			break;
			case 'f':
			cam[0]->setLocation(vector3d(0,0,0));
			supp->update(obj,obj2,obj3,obj4,obj5,Pobj,Pobj2,Pobj3,Pobj4,Pobj5,Pobj6,Pobj7,Pobj8,Pobj9,Pobj10,pref,prefAnim);
			 break;
			case 'm':

				saveToFile();
				break;
			
		//case 'b':
				//CopyFile ("Projet1.exe", fileName[11].c_str(), TRUE);
			
			case 'x':
if(gameMode_->getLanchGame()==false)
{
supp->update(p,cam,obj,obj2,obj3,obj4,obj5,Pobj,Pobj2,Pobj3,Pobj4,Pobj5,Pobj6,Pobj7,Pobj8,Pobj9,Pobj10,pref,prefAnim,view_->sky);
		 
		 
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

