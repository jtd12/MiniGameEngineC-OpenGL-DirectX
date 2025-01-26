#include"effect.hpp"

effects::effects()
{
	intensity_fog=0.0f;
	start_density=5.0f;
	end_density=50.0f;
}

effects::~effects()
{
	
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
