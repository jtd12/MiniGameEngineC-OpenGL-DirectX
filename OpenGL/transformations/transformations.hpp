#ifndef DEF_TRANSFORMATIONS_HPP
#define DEF_TRANSFORMATIONS_HPP
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
#include"../entities/prefab.h"
#include"../entities/prefabAnim.h"
#include"../entities/proceduralObject.h"

class transformation
{
	public:
	transformation();
	transformation(pointer* pp);
	~transformation();
	void scaleObject(std::vector<object*> obj_);
	void scaleObject(std::vector<Pobject*> obj_);
	void scaleObject(std::vector<prefab*> obj_);
	void scaleObject(std::vector<prefabAnim*> obj_);
	void rotateObject(std::vector<object*> obj_);
	void rotateObject(std::vector<Pobject*> obj_);
	void rotateObject(std::vector<prefab*> obj_);
	void rotateObject(std::vector<prefabAnim*> obj_);
	void colorObject(std::vector<object*> obj_);
	void translateObject(std::vector<object*> obj_);
	void translateObject(std::vector<Pobject*> obj_);
	void translateObject(std::vector<prefab*> obj_);
	void translateObject(std::vector<prefabAnim*> obj_);
	bool selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist);
	void separateObjects(std::vector<object*>& objects, float minDistance, float separationFactor);
	void separateObjects(std::vector<object*>& objects,std::vector<object*>& objects2, float minDistance, float separationFactor);
	void separateObjects(std::vector<object*>& objects,std::vector<prefab*>& objects2, float minDistance, float separationFactor);
	void separateObjects(std::vector<object*>& objects,std::vector<prefabAnim*>& objects2, float minDistance, float separationFactor);
	void separateObjects(std::vector<object*>& objects,std::vector<Pobject*>& objects2, float minDistance, float separationFactor);
	void separateObjects(std::vector<prefab*>& objects,std::vector<Pobject*>& objects2, float minDistance, float separationFactor);
	void separateObjects(std::vector<prefabAnim*>& objects,std::vector<Pobject*>& objects2, float minDistance, float separationFactor);
	void separateObjects(std::vector<prefabAnim*>& objects,std::vector<prefab*>& objects2, float minDistance, float separationFactor);
	void separateObjects(std::vector<Pobject*>& objects, float minDistance, float separationFactor);
	void separateObjects(std::vector<prefab*>& objects, float minDistance, float separationFactor);
	void separateObjects(std::vector<prefabAnim*>& objects, float minDistance, float separationFactor);
	private:
		pointer *p;
};
#endif
