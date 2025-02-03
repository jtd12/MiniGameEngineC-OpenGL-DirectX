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
	 std::vector<object*> ReadequalObj();
	 std::vector<object*> ReadequalObj2();
	 std::vector<object*> ReadequalObj3();
	 std::vector<object*> ReadequalObj4();
	 std::vector<object*> ReadequalObj5();
	 std::vector<Pobject*> ReadequalPobj();
	 std::vector<Pobject*> ReadequalPobj2();
	 std::vector<Pobject*> ReadequalPobj3();
	 std::vector<Pobject*> ReadequalPobj4();
	 std::vector<Pobject*> ReadequalPobj5();
	 std::vector<Pobject*> ReadequalPobj6();
	 std::vector<Pobject*> ReadequalPobj7();
	 std::vector<Pobject*> ReadequalPobj8();
	 std::vector<Pobject*> ReadequalPobj9();
	 std::vector<Pobject*> ReadequalPobj10();
	 std::vector<prefab*> ReadequalPref();
	 std::vector<prefabAnim*> ReadequalPrefAnim();
	 std::vector<camera*> ReadequalCam();
	 camera* ReadequalCam2();
	 camera* ReadequalCam3();
	 camera* ReadequalCam4();
	 generateSkybox* ReadequalSky();
	 
	 void WriteequalObj(std::vector<object*> obj);
	 void WriteequalObj2(std::vector<object*> obj);
	 void WriteequalObj3(std::vector<object*> obj);
	 void WriteequalObj4(std::vector<object*> obj);
	 void WriteequalObj5(std::vector<object*> obj);
	 void WriteequalPObj(std::vector<Pobject*> obj);
	 void WriteequalPObj2(std::vector<Pobject*> obj);
	 void WriteequalPObj3(std::vector<Pobject*> obj);
	 void WriteequalPObj4(std::vector<Pobject*> obj);
	 void WriteequalPObj5(std::vector<Pobject*> obj);
	 void WriteequalPObj6(std::vector<Pobject*> obj);
	 void WriteequalPObj7(std::vector<Pobject*> obj);
	 void WriteequalPObj8(std::vector<Pobject*> obj);
	 void WriteequalPObj9(std::vector<Pobject*> obj);
	 void WriteequalPObj10(std::vector<Pobject*> obj);
	 void WriteequalPrefab(std::vector<prefab*> obj);
	 void WriteequalPrefabAnim(std::vector<prefabAnim*> obj);
	 void WriteequalCam(camera* obj);
	 void WriteequalCam2(std::vector<camera*> obj2);
	 void WriteequalCam3(std::vector<camera*> obj3);
	 void WriteequalCam4(std::vector<camera*> obj4);
	 void WriteequalSky(generateSkybox* obj);
	 
	 
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
		generateSkybox* sky;
		std::string fileName[15];	
		objloader objLoad;

		std::vector<object*> obj_;
	    std::vector<object*> obj2_;	
	    std::vector<object*> obj3_; 
	    std::vector<object*> obj4_; 
		std::vector<object*> obj5_; 
		std::vector<Pobject*> Pobj_; 
		std::vector<Pobject*> Pobj2_;
		std::vector<Pobject*> Pobj3_;
		std::vector<Pobject*> Pobj4_;
		std::vector<Pobject*> Pobj5_;
		std::vector<Pobject*> Pobj6_;
		std::vector<Pobject*> Pobj7_;
		std::vector<Pobject*> Pobj8_;
		std::vector<Pobject*> Pobj9_;
		std::vector<Pobject*> Pobj10_;
		std::vector<prefab*> pref_;
		std::vector<prefabAnim*> prefAnim_;
		std::vector<camera*> cam_;
		generateSkybox* sky_;
	
		
};
#endif
