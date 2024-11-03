#ifndef DEF_PROCEDURALOBJECT_H
#define DEF_PROCEDURALOBJECT_H
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include"vector.h"
#include<C:\library\freeglut\include\GL\freeglut.h>
#include"collisionplane.h"
#include<vector>
#include"boundingbox.h"
using namespace std;


class Pobject
{
	public:
		Pobject();
		Pobject(const char* c,unsigned int map ,vector3d l,vector3d couleur,vector3d r,vector3d s);
		~Pobject();
		
		void update();
		void drawObject();
		void setLocation(vector3d l);
		vector3d getLocation();
		void setCouleur(vector3d couleur);
	void 	setCouleurInc(vector3d couleur);
	void drawBouding();
		vector3d getCouleur();
		void setRotation(vector3d r);
		vector3d getRotation();
		void setScale(vector3d r);
		vector3d getScale();
		void setLocationIncrement(vector3d l);
		void dynamique();
		void statique();
		vector3d getP1();
		vector3d getP2();
		vector3d getP3();
		vector3d getP4();
		vector3d getP5();
		vector3d getP6();
		vector3d getP7();
		vector3d getP8();
		vector3d getP9();
		vector3d getP10();
		vector3d getP11();
		vector3d getP12();
		vector3d getP13();
		vector3d getP14();
		vector3d getP15();
		vector3d getP16();
 	 	vector3d getP17();
		vector3d getP18();
		vector3d getP19();
		vector3d getP20();
		vector3d getP21();
		vector3d getP22();
		vector3d getP23();
		vector3d getP24();
		
		void setP1(vector3d p1_);
		void setP2(vector3d p2_);
		void setP3(vector3d p3_);
		void setP4(vector3d p4_);
		void setCollision(bool b);
		bool getCollision();
		void setDynamic(bool b);
		bool getDynamic();
		
	private:
		unsigned int mesh;
		bool dynamic;
		bool collid;	
		vector3d loc;
		vector3d col;
		vector3d rot;
		vector3d scale;
		vector3d  p1;
 		vector3d  p2;
 		vector3d  p3;
 		vector3d  p4;
 		vector3d  p5;
 		vector3d  p6;
 		vector3d  p7;
 		vector3d  p8;
 		vector3d  p9;
 		vector3d  p10;
 		vector3d  p11;
 		vector3d  p12;
 		vector3d  p13;
 		vector3d  p14;
 		vector3d  p15;
 		vector3d  p16;
 		vector3d  p17;
 		vector3d  p18;
 		vector3d  p19;
 		vector3d  p20;
 		vector3d  p21;
 		vector3d  p22;
 		vector3d  p23;
 		vector3d  p24;
	std::string name;
		boundingbox* b;
};
#endif

