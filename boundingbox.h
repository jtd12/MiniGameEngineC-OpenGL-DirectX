#ifndef DEF_BOUNDINGBOX_H
#define DEF_BOUNDINGBOX_H
#include"vector.h"
#include <gl/gl.h>
#include<gl/glu.h>
#include<vector>
class boundingbox
{
	public:
		boundingbox();
		~boundingbox();
		void drawCube();
		void setMin(vector3d m);
		void setMax(vector3d m);
		vector3d getMin();
		vector3d getMax();
		void setLocation(vector3d l);
		vector3d getLocation();
		vector3d loc;
		bool isCollision(vector3d playerPos,vector3d playerScale,vector3d bboxPos, vector3d bboxScale);
	
		
	private:

		vector3d max_;
		vector3d min_;
	
};

#endif

