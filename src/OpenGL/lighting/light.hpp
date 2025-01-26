#ifndef DEF_LIGHT_HPP
#define DEF_LIGHT_HPP
#include <windows.h>
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include"C:\library\freeglut\include\GL\freeglut.h"
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<time.h>
#include"../entities/pointer.h"
#include"../entities/camera.h"
#include"../menu/menu.h"


class light
{
	public:
		light(pointer* pp);
		~light();
		void moveLight();
		void lightDiffuse();
		void lightAmb();
		void lighting();
		bool selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist);
		
	private:
		
	 vector3d col;
	 vector3d amb;
	 vector3d dif;
	 vector3d posLight;
	 pointer *p;
};

#endif
