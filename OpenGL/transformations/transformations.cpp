#include"transformations.hpp"

transformation::transformation()
{
	p=new pointer(vector3d(0,0,0));
	
}
transformation::transformation(pointer* pp)
{
	p=pp;
}

transformation::~transformation()
{
	delete p;
}

bool transformation::selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_)
{
	float dist=(sqrt(((objectPointer.x-objectReference.x)*(objectPointer.x-objectReference.x))+((objectPointer.y-objectReference.y)*(objectPointer.y-objectReference.y))+
	((objectPointer.z-objectReference.z)*(objectPointer.z-objectReference.z))));
	if(dist<dist_)
	{
		
		return true;
	}
	return false;
}


void transformation::scaleObject(std::vector<object*> obj_)
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
void transformation::scaleObject(std::vector<Pobject*> obj_)
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

void transformation::scaleObject(std::vector<prefab*> obj_)
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
void transformation::scaleObject(std::vector<prefabAnim*> obj_)
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
void transformation::rotateObject(std::vector<object*> obj_)
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
void transformation::rotateObject(std::vector<Pobject*> obj_)
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
void transformation::rotateObject(std::vector<prefab*> obj_)
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

void transformation::rotateObject(std::vector<prefabAnim*> obj_)
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

void transformation::colorObject(std::vector<object*> obj_)
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






void transformation::translateObject(std::vector<object*> obj_)
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
void transformation::translateObject(std::vector<Pobject*> obj_)
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
void transformation::translateObject(std::vector<prefab*> obj_)
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

void transformation::translateObject(std::vector<prefabAnim*> obj_)
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


void transformation::separateObjects(std::vector<object*>& objects, float minDistance, float separationFactor) {
    for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = i + 1; j < objects.size(); j++) {
            float dx = objects[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<Pobject*>& objects, float minDistance, float separationFactor) {
    for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = i + 1; j < objects.size(); j++) {
            float dx = objects[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<prefab*>& objects, float minDistance, float separationFactor) {
    for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = i + 1; j < objects.size(); j++) {
            float dx = objects[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<prefabAnim*>& objects, float minDistance, float separationFactor) {
    for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = i + 1; j < objects.size(); j++) {
            float dx = objects[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<object*>& objects,std::vector<object*>& objects2, float minDistance, float separationFactor)
{
	   for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = 0; j < objects2.size(); j++) {
            float dx = objects2[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects2[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects2[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects2[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<object*>& objects,std::vector<prefab*>& objects2, float minDistance, float separationFactor)
{
	   for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = 0; j < objects2.size(); j++) {
            float dx = objects2[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects2[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects2[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects2[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<object*>& objects,std::vector<prefabAnim*>& objects2, float minDistance, float separationFactor)
{
	   for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = 0; j < objects2.size(); j++) {
            float dx = objects2[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects2[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects2[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects2[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<object*>& objects,std::vector<Pobject*>& objects2, float minDistance, float separationFactor)
{
	   for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = 0; j < objects2.size(); j++) {
            float dx = objects2[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects2[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects2[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects2[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<prefab*>& objects,std::vector<Pobject*>& objects2, float minDistance, float separationFactor)
{
	   for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = 0; j < objects2.size(); j++) {
            float dx = objects2[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects2[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects2[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects2[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<prefabAnim*>& objects,std::vector<Pobject*>& objects2, float minDistance, float separationFactor)
{
	   for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = 0; j < objects2.size(); j++) {
            float dx = objects2[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects2[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects2[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects2[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}

void transformation::separateObjects(std::vector<prefabAnim*>& objects,std::vector<prefab*>& objects2, float minDistance, float separationFactor)
{
	   for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = 0; j < objects2.size(); j++) {
            float dx = objects2[j]->getLocation().x - objects[i]->getLocation().x;
            float dy = objects2[j]->getLocation().y - objects[i]->getLocation().y;
            float dz = objects2[j]->getLocation().z - objects[i]->getLocation().z;
            
            float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < minDistance && distance > 0.0f) {
                // Normalisation du vecteur de séparation
                float invDist = 1.0f / distance;
                dx *= invDist;
                dy *= invDist;
                dz *= invDist;

                // Appliquer une petite séparation
                float moveAmount = (minDistance - distance) * separationFactor;
                objects[i]->setLocationIncrement2(vector3d(-dx*moveAmount,-dy*moveAmount,-dz*moveAmount));
				objects2[j]->setLocationIncrement2(vector3d(dx*moveAmount,dy*moveAmount,dz*moveAmount));
             
            }
        }
    }
}


