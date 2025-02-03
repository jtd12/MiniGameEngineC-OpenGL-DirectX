#include"skyboxGeneration.hpp"

generateSkybox::generateSkybox()
{
	col=vector3d(0,0,0);
}
generateSkybox::~generateSkybox()
{
		for(int i=0;i<skyb.size();i++)
	delete skyb[i];
}

vector3d generateSkybox::getCol()
{
	return col;
}
void generateSkybox::setCol(vector3d color)
{
col=vector3d(color.x,color.y,color.z);
}

void generateSkybox::colorSky()
{
		if(value==110)
{
	col=vector3d(0.8,0.7,0.7);

}     
if(value==120)
{
	col=vector3d(0.2,0.5,0.5);
	
}
if(value==130)
{
	col=vector3d(0,0,0);

}
if(value==140)
{
	col=vector3d(1.0,0.7,0.8);

}

	for(int i=0;i<skyb.size();i++)
skyb[i]->drawSkybox(500);

}



