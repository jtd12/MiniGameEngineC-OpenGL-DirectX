#ifndef DEF_PREFABANIM_H
#define DEF_PREFABANIM_H
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include<string>
#include"vector.h"
#include"objloader.h"
#include"boundingbox.h"
using namespace std;

class prefabAnim
{
	public:
		prefabAnim(const char * n,vector3d vec,vector3d r,vector3d s);
		~prefabAnim();
		void update(bool up,bool down);
		void show();
			vector3d getLocation();
		void setLocation(vector3d l);
		void setRotation(vector3d r);
		vector3d getRotation();
		void setScale(vector3d r);
		vector3d getScale();
		void setLocationIncrement(vector3d l);
		void movement(bool up,bool down, bool right, bool left);
		void physics();
		boundingbox* b;
		void setWalk(bool b);
		bool getWalk();
		void setDynamic(bool b);
		bool getDynamic();
	
		
		private:
			bool dynamic;
			float curFrame;
			vector3d loc;
			std::vector<unsigned int>frames;
			std::string name;
		vector3d rot;
		vector3d scale;
		objloader obj;
		float speed;
			bool walk;
				bool link;
			
};

#endif
