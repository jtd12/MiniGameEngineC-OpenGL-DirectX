#include"boundingbox.h"

boundingbox::boundingbox()
{

	max_=vector3d(1,1,1);
	min_=vector3d(-1,-1,-1);

	
}
boundingbox::~boundingbox()
{
	
}

void boundingbox::drawCube()
{
	
	glPushMatrix();

	glBegin(GL_LINE_LOOP);
    glVertex3f(max_.x,min_.y,min_.z);
    glVertex3f(max_.x,min_.y,max_.z);
    glVertex3f(max_.x,max_.y,max_.z);
    glVertex3f(max_.x,max_.y,min_.z);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(min_.x,max_.y,min_.z);
    glVertex3f(min_.x,max_.y,max_.z);
    glVertex3f(min_.x,min_.y,max_.z);
    glVertex3f(min_.x,min_.y,min_.z);
    glEnd();
    
    
    glBegin(GL_LINE_LOOP);
    glVertex3f(max_.x,min_.y,max_.z);
    glVertex3f(max_.x,max_.y,max_.z);
    glVertex3f(min_.x,max_.y,max_.z);
    glVertex3f(min_.x,min_.y,max_.z);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glVertex3f(max_.x,max_.y,min_.z);
    glVertex3f(max_.x,min_.y,min_.z);
    glVertex3f(min_.x,min_.y,min_.z);
    glVertex3f(min_.x,max_.y,min_.z);
    glEnd();
    

    glBegin(GL_LINE_LOOP);
    glVertex3f(max_.x,max_.y,min_.z);
    glVertex3f(max_.x,max_.y,max_.z);
    glVertex3f(min_.x,max_.y,max_.z);
    glVertex3f(min_.x,max_.y,min_.z);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(min_.x,min_.y,min_.z);
    glVertex3f(min_.x,min_.y,max_.z);
    glVertex3f(max_.x,min_.y,max_.z);
    glVertex3f(max_.x,min_.y,min_.z);
    glEnd();
    
    
 
    
    glPopMatrix();
}

bool boundingbox::isCollision(vector3d playerPos,vector3d playerScale,vector3d bboxPos, vector3d bboxScale)
{
	if((playerPos.x<=(bboxScale.x+bboxScale.y+bboxScale.z) + bboxPos.x) && (playerScale.x+playerScale.y+playerScale.z) + playerPos.x>=bboxPos.x
	&& (playerPos.z<=(bboxScale.x+bboxScale.y+bboxScale.z) + bboxPos.z && (playerScale.x+playerScale.y+playerScale.z) + playerPos.z>=bboxPos.z ))
	{
		return true;
	}
	return false;
}	
 
 vector3d boundingbox::getMin()
 {
 	return min_;
 }
 vector3d boundingbox::getMax()
 {
 	return max_;
 }
 void boundingbox::setMin(vector3d m)
 {
 	min_=m;
 }
 void boundingbox::setMax(vector3d m)
 {
 	max_=m;
 }



 

