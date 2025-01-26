#ifndef DEF_DATAS_HPP
#define DEF_DATAS_HPP
#include <windows.h>
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include <gl\glaux.h>         // fonctions AUX Library
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<time.h>
#include"../entities/grid.h"
#include"../entities/pointer.h"
#include"../entities/camera.h"
#include"../menu/menu.h"
#include"../entities/prefab.h"
#include"../entities/prefabAnim.h"
#include"../menu/hud.h"
#include"../entities/skybox.h"
#include"../mathsutils/collision.h"
#include"../entities/boundingbox.h"
#include"../loader/objloader.h"
#include"../entities/proceduralObject.h"
#include"../skybox/skyboxgeneration.hpp"

class datas
{
	public:
	 datas();
	 datas(generateSkybox* sky_);
	 ~datas();
	 void saveToFile();
	 void loadToFile();
	 std::vector<object*> equalObj();
	 std::vector<object*> equalObj2();
	 std::vector<object*> equalObj3();
	 std::vector<object*> equalObj4();
	 std::vector<object*> equalObj5();
	 std::vector<Pobject*> equalPobj();
	 std::vector<Pobject*> equalPobj2();
	 std::vector<Pobject*> equalPobj3();
	 std::vector<Pobject*> equalPobj4();
	 std::vector<Pobject*> equalPobj5();
	 std::vector<Pobject*> equalPobj6();
	 std::vector<Pobject*> equalPobj7();
	 std::vector<Pobject*> equalPobj8();
	 std::vector<Pobject*> equalPobj9();
	 std::vector<Pobject*> equalPobj10();
	 std::vector<prefab*> equalPref();
	 std::vector<prefabAnim*> equalPrefAnim();
	 std::vector<camera*> equalCam();
	 generateSkybox* equalSky();
	 std::vector<object*> obj111;
	 
	private:
	    std::vector<object*> obj;
	    std::vector<object*> obj2;	
	    std::vector<object*> obj3; 
	    std::vector<object*> obj4; 
		std::vector<object*> obj5; 
		std::vector<Pobject*> Pobj; 
		std::vector<Pobject*> Pobj2;
		std::vector<Pobject*> Pobj3;
		std::vector<Pobject*> Pobj4;
		std::vector<Pobject*> Pobj5;
		std::vector<Pobject*> Pobj6;
		std::vector<Pobject*> Pobj7;
		std::vector<Pobject*> Pobj8;
		std::vector<Pobject*> Pobj9;
		std::vector<Pobject*> Pobj10;
		std::vector<prefab*> pref;
		std::vector<prefabAnim*> prefAnim;
		std::vector<camera*> cam;
		std::string fileName[15];	
		objloader objLoad;
		generateSkybox* sky;
		
};
#endif
