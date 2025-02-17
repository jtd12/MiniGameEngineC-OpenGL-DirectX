#ifndef DEF_PATHFILE_HPP
#define dEF_PATHFILE_HPP
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

class pathFile
{
	public:
		pathFile();
		~pathFile();
	  void saisirPath();
	  void clavierTxt(char key,int x, int y);
	  void afficherTexte(float x, float y, char *texte) ;
	  char * getPathName();
	  
	private:
		char pathName[260]; // Assez grand pour stocker "add" + texte
		int position;     // Position actuelle dans le texte
		
};
#endif
