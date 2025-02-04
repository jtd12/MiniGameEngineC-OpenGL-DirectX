#ifndef DEF_PROJECTIONS_HPP
#define dEF_PROJECTION_HPP
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
#include"../skybox/skyboxGeneration.hpp"

class view
{
	public:
		view();
		~view();
		void reshape(int width,int height);
		void reshapeOrtho(int width,int height);
		void focal();
		generateSkybox* sky;
		
	private:
		 float angle;
		 float nearPlane;
		 float farPlane;
		 int width_;
		 int height_;
		 	
};

#endif

