#include"hud.h"

hud::hud(const char *filename,int w, int h)
{
	hudTex=loadTexture(filename,w,h);
}
hud::~hud()
{
	
}
unsigned int hud::loadTexture(const char * filename,int w, int h)
{
 GLuint texture;

  int width, height;
  
  unsigned char * data;

  FILE * file;

  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  width=w;
  height=h;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

 for(int i = 0; i < width * height ; ++i)
{
   int index = i*3;
   unsigned char B,R;
   B = data[index];
   R = data[index+2];

   data[index] = R;
   data[index+2] = B;

}


glGenTextures( 1, &texture );
glBindTexture( GL_TEXTURE_2D, texture );
glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
free( data );

return texture;
}
void hud::update()
 {
 	
	 	


	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0,0,0);
	glScaled(0.5,0.5,0.5);
	glBindTexture(GL_TEXTURE_2D,hudTex);
	glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
 
glTexCoord2i(1,0);glVertex3i(-1,-1,-1);
glTexCoord2i(0,0);glVertex3i(+1,-1,-1);
glTexCoord2i(0,1);glVertex3i(+1,+1,-1); 
glTexCoord2i(1,1);glVertex3i(-1,+1,-1);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
 }

 void hud::show()
  {
  	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(2,2,1,1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	update();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

  }
