#ifndef DEF_EFFECT_HPP
#define DEF_EFFECT_HPP
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

class effects
{
	public:
		effects();
		~effects();
		void fog();
		bool getFog();
		void setFog(bool b);
		void setIntensity(float f);
		void startDensity(float f);
		void endDensity(float f);

		
	private:
		bool fog_;
		float intensity_fog;
		float start_density;
		float end_density;
};

#endif
