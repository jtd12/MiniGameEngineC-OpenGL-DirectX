#ifndef DEF_PREFAB_H
#define DEF_PREFAB_H
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include<string>
#include"../mathsutils/vector.h"
#include"../loader/objloader.h"
#include"roue.h"
#include"porte.h"
#include"object.h"
#include"boundingbox.h"
using namespace std;
class prefab
{
	public:
		prefab(const char *n,const std::string& filename,vector3d vec,vector3d r,vector3d s);
		~prefab();
		void update();
		void show();
		void showB();
		vector3d getLocation();
		void setLocation(vector3d l);
		void setRotation(vector3d r);
		vector3d getRotation();
		void setScale(vector3d r);
		vector3d getScale();
		void movement(bool up,bool down, bool right, bool left);
		void physics();
		void drawRoue();
		void drawPorte();
		void setLocationIncrement();
		void setDrive(bool b);
		bool getDrive();
		void setDynamic(bool b);
		bool getDynamic();
		void setLink(bool b);
		void setLocationIncrement2(vector3d pos);
	
	private:
		bool dynamic;
		unsigned int mesh;
		std::string name;
		vector3d loc;
		vector3d rot;
		vector3d scale;
		objloader obj;
		float speed;
		float maxSpeed;
		float dec;
		float acc;
		float angle;
		float turnSpeed;
		bool drive;
		std::vector<roue*> r_;
		std::vector<porte*> p;
		boundingbox* b;
		bool link;
};
#endif
