#include"menu.h"


   int value=0; 
 int window=0;
 int nSousmenu1, nSousmenu2, nMenuprincipal,nSousmenu3,nSousmenu4,nSousmenu5,nSousmenu6,nSousmenu7,nSousmenu8,nSousmenu9,nSousmenu10,nSousmenu11,nSousmenu12,nSousmenu13;	

void menu(int num){
 
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
   value = num;
  }
  glutPostRedisplay();
 
} 
void menu2(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

} 
void menu3(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu4(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu5(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu6(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu7(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu8(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu9(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu10(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu11(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu12(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menu13(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void menuP(int num){
 if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
  

}
void createMenu(void){    


nSousmenu1 = glutCreateMenu(menu);
	glutAddMenuEntry("Teapot", 1);
	glutAddMenuEntry("Cube", 2);
	glutAddMenuEntry("Sphere", 3);
	glutAddMenuEntry("Torus", 4);
	glutAddMenuEntry("Vehicule", 5);
	glutAddMenuEntry("Character", 6);
	glutAddMenuEntry("CameraCar", 7);
	glutAddMenuEntry("CameraPlayer", 8);
	glutAddMenuEntry("CameraFree", 9);
	glutAddMenuEntry("BoundingBox", 10);
	
	nSousmenu11 = glutCreateMenu(menu11);
	glutAddMenuEntry("Road1", 11);
	glutAddMenuEntry("Road2", 12);
	glutAddMenuEntry("Road3", 13);
	glutAddMenuEntry("Road4", 14);
	glutAddMenuEntry("Road5", 15);
	glutAddMenuEntry("Road6", 16);
	glutAddMenuEntry("Road7", 17);
	glutAddMenuEntry("Road8", 18);
	glutAddMenuEntry("Road9", 19);
	glutAddMenuEntry("Road10", 20);
	
	nSousmenu3 = glutCreateMenu(menu3);
	glutAddMenuEntry("violet", 110);
	glutAddMenuEntry("blue", 120);
	glutAddMenuEntry("black", 130);
	glutAddMenuEntry("red", 140);
	glutAddMenuEntry("texture Skybox", 145);
	nSousmenu4 = glutCreateMenu(menu4);
	glutAddMenuEntry("x", 150);
	glutAddMenuEntry("y", 160);
	glutAddMenuEntry("z", 170);
	glutAddMenuEntry("free (x,y,z)", 180);
	nSousmenu6 = glutCreateMenu(menu6);
	glutAddMenuEntry("x+", 200);
	glutAddMenuEntry("y+", 210);
	glutAddMenuEntry("z+", 220);
	glutAddMenuEntry("free(x+,y+,z+)", 230);
	glutAddMenuEntry("x-", 240);
	glutAddMenuEntry("y-", 250);
	glutAddMenuEntry("z-", 260);
	glutAddMenuEntry("free(x-,y-,z-)", 270);
		nSousmenu7 = glutCreateMenu(menu7);
	glutAddMenuEntry("x+", 400);
	glutAddMenuEntry("y+", 410);
	glutAddMenuEntry("z+", 420);
	glutAddMenuEntry("free(x+,y+,z+)", 430);
	glutAddMenuEntry("x-", 440);
	glutAddMenuEntry("y-", 450);
	glutAddMenuEntry("z-", 460);
		glutAddMenuEntry("free(x-,y-,z-)", 470);
		nSousmenu8 = glutCreateMenu(menu8);
	glutAddMenuEntry("Enable FOG", 280);
		glutAddMenuEntry("Disable FOG", 290);
			glutAddMenuEntry("+ density", 300);
				glutAddMenuEntry("- density", 310);
					glutAddMenuEntry("+ startdensity", 320);
				glutAddMenuEntry("- startdensity", 330);
					glutAddMenuEntry("+ enddensity", 340);
				glutAddMenuEntry("- enddensity", 350);
				nSousmenu9 = glutCreateMenu(menu9);	
		glutAddMenuEntry("Start game", 1000);
			glutAddMenuEntry("Quit game", 1100);
			glutAddMenuEntry("Drive Car", 1200);
				glutAddMenuEntry("Static Car", 1230);
				glutAddMenuEntry("Walk Player", 1250);
					glutAddMenuEntry("Static Player", 1280);
				glutAddMenuEntry("Physics Mode", 1300);
				glutAddMenuEntry("Mode Dynamique", 1600);
					glutAddMenuEntry("Mode Statique", 1700);
				nSousmenu10 = glutCreateMenu(menu10);
	glutAddMenuEntry("x+", 500);
	glutAddMenuEntry("y+", 510);
	glutAddMenuEntry("z+", 520);
	glutAddMenuEntry("free(x+,y+,z+)", 530);
	glutAddMenuEntry("x-", 540);
	glutAddMenuEntry("y-", 550);
	glutAddMenuEntry("z-", 560);
	glutAddMenuEntry("free(x-,y-,z-)", 570);
	nSousmenu5 = glutCreateMenu(menu5);	
	glutAddMenuEntry("Delete Object ", 900);
	glutAddMenuEntry("Mode Orthographique",1400);
	glutAddMenuEntry("Mode Perspective", 1500);
	glutAddMenuEntry("Mouse Velocity+", 1800);
	glutAddMenuEntry("Mouse Velocity-", 1900);
	glutAddMenuEntry("Refresh Scene", 2100);
	nSousmenu12 = glutCreateMenu(menu12);	
	glutAddMenuEntry("Angle+ ", 2200);
	glutAddMenuEntry("Angle- ", 2250);
	glutAddMenuEntry("Near Plane+",2300);
	glutAddMenuEntry("Near Plane-",2350);
	glutAddMenuEntry("Far Plane+", 2400);
	glutAddMenuEntry("Far Plane-", 2450);
	nSousmenu13 = glutCreateMenu(menu13);	
	glutAddMenuEntry("Ambiant X+ ", 2500);
	glutAddMenuEntry("Ambiant X- ", 2550);
	glutAddMenuEntry("Ambiant Y+",2600);
	glutAddMenuEntry("Ambiant Y-",2650);
	glutAddMenuEntry("Ambiant Z+",2700);
	glutAddMenuEntry("Ambiant Z-",2750);
	glutAddMenuEntry("Diffuse X+",2800);
	glutAddMenuEntry("Diffuse X-", 2850);
	glutAddMenuEntry("Diffuse Y+", 2900);
	glutAddMenuEntry("Diffise Y-",2950);
	glutAddMenuEntry("Diffise Z+",3000);
	glutAddMenuEntry("Diffise Z-",3050);
	glutAddMenuEntry("X LightPos",3100);
	glutAddMenuEntry("Y LightPos",3200);
	glutAddMenuEntry("Z LightPos",3300);
	glutAddMenuEntry("X,y,Z LightPos",3400);
	nMenuprincipal = glutCreateMenu(menuP);
	
	

	
		
		glutAddSubMenu("Add Primitive", nSousmenu1);
		glutAddSubMenu("Add Procedural Mesh", nSousmenu11);
		glutAddSubMenu("Color screen", nSousmenu3);
		glutAddSubMenu("translation", nSousmenu4);
		glutAddSubMenu("rotation", nSousmenu6);
		glutAddSubMenu("scale", nSousmenu7);
		glutAddSubMenu("Add Fog", nSousmenu8);
		glutAddSubMenu("Adjust Focal", nSousmenu12);
		glutAddSubMenu("Game Mode", nSousmenu9);	
		glutAddSubMenu("color object", nSousmenu10);
		glutAddSubMenu("lighting", nSousmenu13);
		glutAddSubMenu("Other Mode", nSousmenu5);
	
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	


} 


