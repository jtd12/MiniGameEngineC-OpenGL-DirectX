#include"pathFile.hpp"

pathFile::pathFile()
{
position=0;
strcpy(pathName, "data/");  // Copie "add" dans resultat
strcat(pathName, "decor/map.obj");  // Concatène texte

}

pathFile::~pathFile()
{
	
}

char * pathFile::getPathName()
{
	return pathName;
}

void pathFile::clavierTxt(char key,int x, int y)
{
if (key == 13) { // Touche "Entrée" (ASCII 13)
        position = 0;
        pathName[0] = '\0'; // Réinitialise le texte
    } else if (key == 8) { // Touche "Backspace" (ASCII 8)
        if (position > 0) {
            position--;
            pathName[position] = '\0';
        }
    } else if (position < 255) { // Ajoute le caractère s'il reste de la place
        pathName[position++] = key;
        pathName[position] = '\0';
    }
    	
}


void pathFile::saisirPath()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.5,2,5,5);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0); // Texte en blanc
	char resultat[260]; // Assez grand pour stocker "add" + texte
	strcpy(resultat, "add Object path: ");  // Copie "add" dans resultat
	strcat(resultat, pathName);  // Concatène texte
	afficherTexte(-0.1, 0.8,resultat);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void pathFile::afficherTexte(float x, float y, char *texte) {
    glRasterPos2f(x, y);
    for (int i = 0; texte[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texte[i]);
    }
}

