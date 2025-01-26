#ifndef DEF_HUD_H
#define DEF_HUD_H
#include <iostream>
#include<vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
 #ifndef GL_UNSIGNED_SHORT_5_6_5
 #define GL_UNSIGNED_SHORT_5_6_5 0x8363
 #endif
 #ifndef GL_CLAMP_TO_EDGE
 #define GL_CLAMP_TO_EDGE 0x812F
 #endif
 
class hud
{
public:
hud(const char *filename,int w, int h);
~hud();
void update();
void show();
unsigned int loadTexture(const char * filename, int w, int h);
private:
unsigned int hudTex;
};
#endif
