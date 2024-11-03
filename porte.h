#ifndef DEF_porte_H
#define DEF_porte_H
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include<string>
#include"vector.h"
#include"objloader.h"
#include"boundingbox.h"
class porte
{
	public:
		porte(const char *n,const std::string& filename,vector3d vec);
		~porte();
		void update();
		void show();
		void showB();
		vector3d getLocation();
		void setLocation(vector3d l);
		void setRotation(vector3d r);
		void setRotationIncrement(vector3d r);
		vector3d getRotation();
		void setScale(vector3d r);
		vector3d getScale();
		void setLocationIncrement(vector3d l);
	
				
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
