#ifndef DEF_AJOUT_HPP
#define DEF_AJOUT_HPP
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
#include"../../entities/pointer.h"
#include"../../entities/camera.h"
#include"../../menu/menu.h"
#include"../../entities/prefab.h"
#include"../../entities/prefabAnim.h"
#include"../../entities/proceduralObject.h"
#include"../../skybox/skyboxGeneration.hpp"
#include"../../entities/skybox.h"

class ajout
{
	public:
	  ajout();
	  ~ajout();
	  void update(pointer* p,
		std::vector<object*>& obj,
		std::vector<object*>& obj2,
		std::vector<object*>& obj3, 
		std::vector<object*>& obj4, 
		std::vector<object*>& obj5, 
		std::vector<Pobject*>& Pobj, 
		std::vector<Pobject*>& Pobj2,
		std::vector<Pobject*>& Pobj3,
		std::vector<Pobject*>& Pobj4,
		std::vector<Pobject*>& Pobj5,
		std::vector<Pobject*>& Pobj6,
		std::vector<Pobject*>& Pobj7,
		std::vector<Pobject*>& Pobj8,
		std::vector<Pobject*>& Pobj9,
		std::vector<Pobject*>& Pobj10,
		std::vector<prefab*>& pref,
		std::vector<prefabAnim*>& prefAnim,std::string fileName[15],objloader& objLoad
		);
		bool selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist);
	  
	private:
		
};
#endif
