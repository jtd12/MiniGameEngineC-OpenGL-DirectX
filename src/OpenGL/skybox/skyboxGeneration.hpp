#ifndef DEF_SKYBOXGENERATION_HPP
#define DEF_SKYBOXGENERATION_HPP
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
#include"../entities/skybox.h"
#include"../menu/menu.h"


class generateSkybox
{
	public:
		generateSkybox();
		~generateSkybox();
		void colorSky();
		vector3d getCol();
		void setCol(vector3d color);
		
	private:
		std::vector<skybox*> sky;
		vector3d col;
		
		
};

#endif
