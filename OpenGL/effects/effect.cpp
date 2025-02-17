#include"effect.hpp"

effects::effects()
{
	intensity_fog=0.0f;
	start_density=5.0f;
	end_density=50.0f;
	fog_=false;
}

effects::~effects()
{
	
}

void effects::setFog(bool b)
  {
  	fog_=b;
  }
  
  void effects::setIntensity(float f)
  {
  	intensity_fog+=f;
  	if(intensity_fog>=1.0f)
		 intensity_fog=1.0f;
		 
	if(intensity_fog<=0.0f)
		 intensity_fog=0.0f;
  }
  
  void effects::startDensity(float f)
  {
  	start_density+=f;
		 if(start_density>=100.0f)
		   start_density=100.0f;
		if(start_density<=5.0f)
		   start_density=5.0f;
  }
  
  void effects::endDensity(float f)
  {
 
		end_density+=f;
		 if(end_density>=5000.0f)
		 end_density=5000.0f;
		 //ef->end_density-=0.1f;
		 if(end_density<=50.0f)
		  end_density=50.0f;
  }
  

bool effects::getFog()
{
	return fog_;
}

void effects::fog()
{
glEnable(GL_FOG) ;
GLfloat fogcolor[4] = {0.5, 0.5, 0.5, 1} ;
GLint fogmode = GL_EXP ;
glFogi (GL_FOG_MODE, fogmode) ;
glFogfv(GL_FOG_COLOR, fogcolor) ;
glFogf(GL_FOG_DENSITY, intensity_fog) ;
glFogf(GL_FOG_START, start_density) ;
glFogf(GL_FOG_END, end_density) ;
}
