#ifndef DEF_ROUE_H
#define DEF_ROUE_H
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include<string>
#include"../mathsutils/vector.h"
#include"../loader/objloader.h"
#include"boundingbox.h"
class roue
{
	public:
		roue(const char *n,const std::string& filename,vector3d vec);
		~roue();
		void update();
		void show();
		vector3d getLocation();
		void setLocation(vector3d l);
		void setRotation(vector3d r);
		vector3d getRotation();
		void setScale(vector3d r);
		vector3d getScale();
		void showB();
		void setLocationIncrement(vector3d l);
			void setRotationIncrement(vector3d r);
				
	private:
		int mesh;
		std::string name;
		vector3d loc;
		vector3d rot;
		vector3d scale;
		objloader obj;
			boundingbox* b;
};
#endif
