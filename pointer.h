#ifndef DEF_POINTER_H
#define DEF_POINTER_H
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include"vector.h"

class pointer
{
	public:
		
	pointer();
	pointer(vector3d c);
	~pointer();
	void update();
	void show();
	void setLocationIncrement(vector3d l);
	void setLocation(vector3d l);
	vector3d getLocation();
	vector3d getRotation();
	void setRotation(vector3d r);
		void setScale(vector3d r);
		vector3d getScale();
		void setScaleIncrement(vector3d r);
	private:
		vector3d loc;
		vector3d rot;
		vector3d scale;
		
	
};
#endif
