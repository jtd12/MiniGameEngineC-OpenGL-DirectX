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
		void reinitialiseGame(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_);
		void GameMode(std::vector<object*> obj_,std::vector<prefab*> pref_,std::vector<prefabAnim*> prefAnim_);
		void collision(std::vector<object*> obj_,std::vector<object*> obj2_);
		void collision(std::vector<prefab*> obj_,std::vector<object*> obj2_);
		void collision(std::vector<prefabAnim*> obj_,std::vector<object*> obj2_);
		void update();
		bool getLook();
		bool getLook2();
		bool getLook3();
		bool getLanchGame();
		bool startG();
		float getTime();
		
	private:
		bool physicsMode;
		int look,look2,look3;
		bool lanchGame;
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
	bool keyup,keydown,keyright,keyleft,cc;
	int keyw;
	std::vector<prefab*> pref;
	std::vector<prefabAnim*> prefAnim;
	pointer *p;
	float time;
};

#endif
