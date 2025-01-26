#include"grid.h"

grid::grid()
{
}
grid::~grid()
{
}
void grid::update()
{

}
void grid::show()
{
	for(int i=0;i<1000;i++)
	{
	
		glPushMatrix();
		glTranslated(-250,0,-250);
		if(i<500)
		{
			glTranslated(0,0,i);
		}
		if(i>=500)
		{
			glTranslated(i-500,0,0);
			glRotated(-90,0,1,0);
		}
			glLineWidth(0.2);
		glBegin(GL_LINES);
		glColor3f(1,1,1);
		glVertex3f(0,-0.1,0);
		glVertex3f(500,-0.1,0);
		glEnd();
		glPopMatrix();
	}
		
		
		glPushMatrix();
		glTranslated(25,1.0,25);
			glLineWidth(0.2);
		glBegin(GL_LINES);
		glColor3f(0.7,0.5,0.9);
		glVertex3f(-0.1,0,0);
		glVertex3f(-0.1,50,0);
		glEnd();
			glLineWidth(0.2);
		glBegin(GL_LINES);
		glColor3f(0.9,0.1,0.1);
		glVertex3f(0,-0.1,0);
		glVertex3f(50,-0.1,0);
		glEnd();
			glLineWidth(0.2);
		glBegin(GL_LINES);
		glColor3f(0.1,0.9,0.1);
		glVertex3f(0,-0.1,0);
		glVertex3f(0,-0.1,50);
		glEnd();
		glPopMatrix();
}
