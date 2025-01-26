#include"gameMode.hpp"

gameMode::gameMode()
{
	keyup=false;
	keydown=false;
	keyright=false;
	keyleft=false;
	lanchGame=false;
	look=false;	
	time=0.0f;
}

float gameMode::getTime()
{
	return time;
}

bool gameMode::startG()
{
	return lanchGame;
}

bool gameMode::getLanchGame()
{
	return lanchGame;
}

bool gameMode::getLook()
{
	return look;
}

bool gameMode::getLook2()
{
	return look2;	
}

bool gameMode::getLook3()
{
	return look3;
}
		
		
void gameMode::update()
{

time+=0.1f;
	
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
}

void gameMode::selectCam()
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

void gameMode:: reinitialiseGame(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_)
{
	for(int i=0;i<pref.size();i++)

pref_[i]->setLocation(vector3d(pref_[i]->getLocation().x,p->getLocation().y,pref_[i]->getLocation().z));

for(int i=0;i<prefAnim.size();i++)

prefAnim_[i]->setLocation(vector3d(prefAnim_[i]->getLocation().x,p->getLocation().y,prefAnim[i]->getLocation().z));

for(int i=0;i<obj_.size();i++)
if(obj_[i]->getDynamic())
obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,p->getLocation().y,obj_[i]->getLocation().z));


}
void gameMode::GameMode(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_)
{
	

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

void gameMode::collision(std::vector<object*> obj_,std::vector<object*> obj2_)
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
void gameMode::collision(std::vector<prefab*> obj_,std::vector<object*> obj2_)
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
void gameMode::collision(std::vector<prefabAnim*> obj_,std::vector<object*> obj2_)
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
 

