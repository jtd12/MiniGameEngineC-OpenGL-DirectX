#include"gui.hpp"

gui::gui(std::vector<object*>obj_,  std::vector<object*>obj2_,  std::vector<object*>obj3_,  std::vector<object*>obj4_,
		  std::vector<object*>obj5_,std::vector<Pobject*> Pobj_,std::vector<Pobject*> Pobj2_,std::vector<Pobject*> Pobj3_,std::vector<Pobject*> Pobj4_,
		  std::vector<Pobject*> Pobj5_,std::vector<Pobject*> Pobj6_,std::vector<Pobject*> Pobj7_,std::vector<Pobject*> Pobj8_,
		  std::vector<Pobject*> Pobj9_,std::vector<Pobject*> Pobj10_,std::vector<prefab*> pref_,
		  std::vector<prefabAnim*> prefAnim_,pointer* pp)
{
	p=pp;
	obj=obj_;
	obj2=obj2_;
	obj3=obj3_;
	obj4=obj4_;
	obj5=obj5_;
	Pobj=Pobj_;
	Pobj2=Pobj2_;
	Pobj3=Pobj3_;
	Pobj4=Pobj4_;
	Pobj5=Pobj5_;
	Pobj6=Pobj6_;
	Pobj7=Pobj7_;
	Pobj8=Pobj8_;
	Pobj9=Pobj9_;
	Pobj10=Pobj10_;
	pref=pref_;
	prefAnim=prefAnim_;
	
}

gui::~gui()
{
	delete p;
}

bool gui::selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_)
{
	float dist=(sqrt(((objectPointer.x-objectReference.x)*(objectPointer.x-objectReference.x))+((objectPointer.y-objectReference.y)*(objectPointer.y-objectReference.y))+
	((objectPointer.z-objectReference.z)*(objectPointer.z-objectReference.z))));
	if(dist<dist_)
	{
		
		return true;
	}
	return false;
}



void gui:: drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void gui::mode2D()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.5,2,5,5);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	enable2D(960,540);
	enable2D(960,540,obj);
	enable2D(960,540,obj2);
	enable2D(960,540,obj3);
	enable2D(960,540,obj4);
	enable2D(960,540,obj5);
	enable2D(960,540,Pobj);
	enable2D(960,540,Pobj2);
	enable2D(960,540,Pobj3);
	enable2D(960,540,Pobj4);
	enable2D(960,540,Pobj5);
	enable2D(960,540,Pobj6);
	enable2D(960,540,Pobj7);
	enable2D(960,540,Pobj8);
	enable2D(960,540,Pobj9);
	enable2D(960,540,Pobj10);
	enable2D(960,540,pref);
	enable2D(960,540,prefAnim);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
std::string gui::vector2str(vector3d x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
std::string gui::float2str(float x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
void gui::enable2D(int width, int height){

	glPushMatrix();
/*	glColor3d(1.0,1.0,1.0);
  drawText(-1,-0.8,"time: "+float2str(time*0.05f)); 	
  drawText(-1,0.9,"translation: "); 
  drawText(-1,0.8,"rotation: "); 
  drawText(-1,0.7,"scale: "); 
  drawText(-1,0.6,"color: "); 
  drawText(-1,-0.2,"Angle View: "+float2str(angle)); 
  drawText(-1,-0.1,"Near Plane: "+float2str(nearPlane)); 
  drawText(-1,0.0,"Far Plane: "+float2str(farPlane)); 
  */
	glPopMatrix();
}
void gui::enable2D(int width, int height,std::vector<object*> obj_) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red

	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
      drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	  drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	  drawText(-0.7,0.6,vector2str(obj_[i]->getCouleur())); 
	 }
	 
	glPopMatrix();
}
void gui::enable2D(int width, int height,std::vector<prefab*> obj_) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red

	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
       drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	    drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	     
	 }
	 
	glPopMatrix();
}

void gui::enable2D(int width, int height,std::vector<prefabAnim*> obj_) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red

	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
       drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	    drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	    
	 }
	 
	glPopMatrix();
}
void gui::enable2D(int width, int height,std::vector<Pobject*> obj_) {
	
	glPushMatrix();
	glColor3d(1.0,1.0,1.0);
	for(int i=0;i<obj_.size();i++)
	if(selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0,0,0),5))
	{
	
      drawText(-0.7,0.9,vector2str(obj_[i]->getLocation())); 
       drawText(-0.7,0.8,vector2str(obj_[i]->getRotation()));
	    drawText(-0.7,0.7,vector2str(obj_[i]->getScale()));  
	     drawText(-0.7,0.6,vector2str(obj_[i]->getCouleur())); 
	 }
	 
	glPopMatrix();
}	



