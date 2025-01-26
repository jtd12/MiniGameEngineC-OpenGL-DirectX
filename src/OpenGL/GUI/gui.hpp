#ifndef DEF_GUI_HPP
#define DEF_GUI_HPP
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
#include"../entities/proceduralObject.h"
#include"../entities/prefab.h"
#include"../entities/prefabAnim.h"
#include"../entities/camera.h"
#include"../menu/menu.h"

class gui
{
	public:
		gui(  std::vector<object*>obj_,  std::vector<object*>obj2_,  std::vector<object*>obj3_,  std::vector<object*>obj4_,
		  std::vector<object*>obj5_,std::vector<Pobject*> Pobj_,std::vector<Pobject*> Pobj2_,std::vector<Pobject*> Pobj3_,std::vector<Pobject*> Pobj4_,
		  std::vector<Pobject*> Pobj5_,std::vector<Pobject*> Pobj6_,std::vector<Pobject*> Pobj7_,std::vector<Pobject*> Pobj8_,
		  std::vector<Pobject*> Pobj9_,std::vector<Pobject*> Pobj10_,std::vector<prefab*> pref_,
		  std::vector<prefabAnim*> prefAnim_,pointer* pp);
		~gui();
		void drawText(float x, float y, std::string text);
		void enable2D(int width, int height);
		void enable2D(int width, int height,std::vector<object*> obj_);
		void enable2D(int width, int height,std::vector<Pobject*> obj_);
		void enable2D(int width, int height,std::vector<prefab*> obj_);
		void enable2D(int width, int height,std::vector<prefabAnim*> obj_);
		void mode2D();
		bool selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_);
		std::string vector2str(vector3d x);
		std::string float2str(float x);
		
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
		pointer* p;
		
};
#endif
