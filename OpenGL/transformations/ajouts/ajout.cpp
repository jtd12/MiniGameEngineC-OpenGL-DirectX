#include"ajout.hpp"

ajout::ajout()
{
	pf=new pathFile();
}

ajout::~ajout()
{
	delete pf;
}

 void ajout::saisirPath()
 {
 	pf->saisirPath();
 }
 
void ajout::clavierTxt(char key,int x, int y){
	
	   	pf->clavierTxt(key,x,y);
}

bool ajout::selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_)
{
	float dist=(sqrt(((objectPointer.x-objectReference.x)*(objectPointer.x-objectReference.x))+((objectPointer.y-objectReference.y)*(objectPointer.y-objectReference.y))+
	((objectPointer.z-objectReference.z)*(objectPointer.z-objectReference.z))));
	if(dist<dist_)
	{
		
		return true;
	}
	return false;
}

void ajout::update(pointer* p,	
		std::vector<object*>& obj,
		std::vector<object*>& obj2,
		std::vector<object*>& obj3, 
		std::vector<object*>& obj4, 
		std::vector<object*>& obj5, 
		std::vector<Pobject*>& Pobj, 
		std::vector<Pobject*>& Pobj2,
		std::vector<Pobject*>& Pobj3,
		std::vector<Pobject*>& Pobj4,
		std::vector<Pobject*>& Pobj5,
		std::vector<Pobject*>& Pobj6,
		std::vector<Pobject*>& Pobj7,
		std::vector<Pobject*>& Pobj8,
		std::vector<Pobject*>& Pobj9,
		std::vector<Pobject*>& Pobj10,
		std::vector<prefab*>& pref,
		std::vector<prefabAnim*>& prefAnim,std::string fileName[15],std::string fileName2[15],std::string fileName3[15],
		std::string fileName4[15],std::string fileName5[15],std::string fileName6[15],std::string fileName7[15],std::string fileName8[15],
		std::string fileName9[15],std::string fileName10[15],objloader& objLoad
		)
{
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
fileName[10]=pf->getPathName();
unsigned int map=objLoad.load(fileName[10]);		
Pobj.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==12)
{
fileName2[9]="data/decor/map2.obj";
unsigned int map=objLoad.load(fileName2[9]);		
Pobj2.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==13)
{
fileName3[8]="data/decor/map3.obj";
unsigned int map=objLoad.load(fileName3[8]);		
Pobj3.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==14)
{
fileName4[7]="data/decor/map4.obj";
unsigned int map=objLoad.load(fileName4[7]);		
Pobj4.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==15)
{
fileName5[6]="data/decor/map5.obj";
unsigned int map=objLoad.load(fileName5[6]);		
Pobj5.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==16)
{
fileName6[5]="data/decor/map6.obj";
unsigned int map=objLoad.load(fileName6[5]);	
Pobj6.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==17)
{
fileName7[4]="data/decor/map7.obj";
unsigned int map=objLoad.load(fileName7[4]);	
Pobj7.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==18)
{
fileName8[3]="data/decor/map8.obj";
unsigned int map=objLoad.load(fileName8[3]);		
Pobj8.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==19)
{
fileName9[2]="data/decor/map9.obj";
unsigned int map=objLoad.load(fileName9[2]);		
Pobj9.push_back(new Pobject("decor",map,vector3d(p->getLocation()),vector3d(0.5,0.8,0.8),vector3d(0,0,0),vector3d(5,5,5)));
}
if(value==20)
{
fileName10[1]="data/decor/map10.obj";
unsigned int map=objLoad.load(fileName10[1]);		
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
}
