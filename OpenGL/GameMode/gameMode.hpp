#ifndef DEF_GAMEMODE_HPP
#define DEF_GAMEMODE_HPP
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
#include"../menu/menu.h"
#include"../entities/prefab.h"
#include"../entities/prefabAnim.h"
#include"../menu/hud.h"
#include"../entities/skybox.h"
#include"../mathsutils/collision.h"
#include"../entities/boundingbox.h"
#include"../loader/objloader.h"
#include"../entities/proceduralObject.h"

class gameMode
{
	public:
		gameMode();
		~gameMode();
		void selectCam();
		void reinitialiseGame(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_,pointer* p);
		void GameMode(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_,pointer* p,bool keyup, bool keydown,bool keyright, 
bool keyleft);
		void collision(std::vector<object*> obj_,std::vector<object*> obj2_);
		void collision(std::vector<prefab*> obj_,std::vector<object*> obj2_);
		void collision(std::vector<prefabAnim*> obj_,std::vector<object*> obj2_);
		void update(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_,pointer* p,bool keyup, bool keydown,bool keyright, 
bool keyleft);
		bool getLook();
		bool getLook2();
		bool getLook3();
		bool getLanchGame();
		bool selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_);
		void applyDynamic(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_,pointer* p);
		bool startG();
		float getTime();
		
	private:
		bool physicsMode;
		int look,look2,look3;
		bool lanchGame;
	bool cc;
	int keyw;
	float time;
};

#endif
