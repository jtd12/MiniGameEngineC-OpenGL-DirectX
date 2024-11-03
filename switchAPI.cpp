#include"switchAPI.h"

 APIOPENGL g;
 APIOPENGL g2;
 APIOPENGL g3;
 APIOPENGL g4;
 APIOPENGL g5;
 windows win;
 windows win2;
 windows win3;
 windows win4;
 int windowName5;
 
API::API()
{
translate=vector3d(0,0,0);
rotate=vector3d(0,0,0);
scale=vector3d(1,1,1);
color=vector3d(0.5f,1.0f,0.5f);
specular=vector3d(0.5f,0.5f,0.5f);
ambiant=vector3d(0.5f,0.5f,0.5f);
emissive=vector3d(0.0f,0.0f,0.0f);
bg_color=vector3d(1,1,1);
alpha=0.5f;
power=50.0f;
incX=false;
incY=false;
incZ=false;
scale_x=false,scale_y=false,scale_z=false,rot_x=false,rot_y=false,rot_z=false,colorX=false,colorY=false,colorZ=false,ambiantX=false,ambiantY=false,
ambiantZ=false,specularX=false,specularY=false,specularZ=false,emmissiveX=false;
controlCam=false;
controlCamUp=false;
controlCamLateral=false;

}

API::~API()
{
	delete game;
	delete game2;
	delete game3;
	delete game4;
}

void API::initAPIOpenGL()
{


int argc = 1; // Nombre de paramètres. Minimum à 1 qui correspond au paramètre indiquant le nom de la commande
char *argv[2]; // Pointeur sur des char contenant les paramètres
char commande [] = "GLUT"; // Le premier est la commande (nom du programme). Les suivants devraient être des arguments, mais ici on s'en fiche...

// Construction d'un pseudo tableau de paramètres
argv[0] = &commande[0]; // Commande, il est obligatoire ce paramètre
argv[1] = 0; // Fin de la liste des paramètres



glutInit(&argc,argv);//initilisation de glut
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);//mode addfichage de glut
glutInitWindowPosition(0,0);
glutInitWindowSize(650,350);// taille de la fenetre
windowName =glutCreateWindow("VORA ENGINE 2.0 side view");// titre de l'application
g.initGL();
glutReshapeFunc(reshape);// configuration du mode de projection du pixel à l'ecran
glutSpecialFunc(specialKey);
glutSpecialUpFunc(passiveSpecialKeyboard);
glutKeyboardFunc(keyboardInput);
glutKeyboardUpFunc(passiveKeyboard);
glutMotionFunc(mouseMotion4);
glutPassiveMotionFunc(passiveMouse);
glutMouseFunc(mouse4);
glutMouseWheelFunc(mouseWheel4);
glutDisplayFunc(fenetre1);// fonction d'affichage du dessin à l'ecran

glutInitWindowPosition(650,0);
glutInitWindowSize(650,350);// taille de la fenetre
windowName2 =glutCreateWindow("top view");// titre de l'application
g2.initGL();
glutReshapeFunc(reshape);// configuration du mode de projection du pixel à l'ecran
glutSpecialFunc(specialKey);
glutSpecialUpFunc(passiveSpecialKeyboard);
glutKeyboardFunc(keyboardInput);
glutKeyboardUpFunc(passiveKeyboard);
glutMotionFunc(mouseMotion3);
glutPassiveMotionFunc(passiveMouse);
glutMouseFunc(mouse3);
glutMouseWheelFunc(mouseWheel3);
glutDisplayFunc(fenetre2);// fonction d'affichage du dessin à l'ecran

glutInitWindowPosition(0,350);
glutInitWindowSize(650,350);// taille de la fenetre
windowName3 =glutCreateWindow("front view");// titre de l'application
g3.initGL();
glutReshapeFunc(reshape);// configuration du mode de projection du pixel à l'ecran
glutSpecialFunc(specialKey);
glutSpecialUpFunc(passiveSpecialKeyboard);
glutKeyboardFunc(keyboardInput);
glutKeyboardUpFunc(passiveKeyboard);
glutMotionFunc(mouseMotion2);
glutPassiveMotionFunc(passiveMouse);
glutMouseFunc(mouse2);
glutMouseWheelFunc(mouseWheel2);
glutDisplayFunc(fenetre3);// fonction d'affichage du dessin à l'ecran

glutInitWindowPosition(650,350);
glutInitWindowSize(650,350);// taille de la fenetre
windowName4 =glutCreateWindow("perspective view");// titre de l'application
g4.initGL();
glutReshapeFunc(reshape);// configuration du mode de projection du pixel à l'ecran
glutSpecialFunc(specialKey);
glutSpecialUpFunc(passiveSpecialKeyboard);
glutKeyboardFunc(keyboardInput);
glutKeyboardUpFunc(passiveKeyboard);
glutMotionFunc(mouseMotion);
glutPassiveMotionFunc(passiveMouse);
glutMouseFunc(mouse);
glutMouseWheelFunc(mouseWheel);
glutDisplayFunc(fenetre4);// fonction d'affichage du dessin à l'ecran

createMenu(); 

glutMainLoop();// fonction d'appel en continue d'affichage dans main()
	
}
 
void API::init_input(HWND hWnd)
{
    RAWINPUTDEVICE Mouse;
    Mouse.usUsage = 0x02;    // register mouse
    Mouse.usUsagePage = 0x01;    // top-level mouse
    Mouse.dwFlags = NULL;    // flags
    Mouse.hwndTarget = hWnd;    // handle to a window

    RegisterRawInputDevices(&Mouse, 1, sizeof(RAWINPUTDEVICE));    // register the device
}
bool API::initAPIDirectX()
{
	
       HINSTANCE hInstance;
       HINSTANCE hPrevInstance;
       LPSTR lpCmdLine;
       int nCmdShow;
       game=new APIDIRECTX9();
       game2=new APIDIRECTX9();
       game3=new APIDIRECTX9();
       game4=new APIDIRECTX9();
      
	if( win.initDirectX(hInstance,nCmdShow,"DIRECTX9!","DIRECT X9!",SCREEN_POSX,SCREEN_POSY,SCREEN_WIDTH,SCREEN_HEIGHT,hwnd))
 	{
 			if( win2.initDirectX(hInstance,nCmdShow,"DIRECTX9_2!","DIRECT X9_2!",SCREEN_POSX+600,SCREEN_POSY+0,SCREEN_WIDTH,SCREEN_HEIGHT,hwnd2))
 	{
 			if( win3.initDirectX(hInstance,nCmdShow,"DIRECTX9_3!","DIRECT X9_3!",SCREEN_POSX+0,SCREEN_POSY+300,SCREEN_WIDTH,SCREEN_HEIGHT,hwnd3))
 	{
 	if( win4.initDirectX(hInstance,nCmdShow,"DIRECTX9_4!","DIRECT X9_4!",SCREEN_POSX+600,SCREEN_POSY+300,SCREEN_WIDTH,SCREEN_HEIGHT,hwnd4))
 	{
 		  MSG msg;
 	
 	
 		     
 		 game->initD3D( hwnd,true);
 		 game2->initD3D( hwnd2,true);
 		 game3->initD3D( hwnd3,true);
 		 game4->initD3D( hwnd4,true);
 		 init_input(hwnd4);

 		 game->init_graphics();
 		 
 		 game->init_Light();
 		 game2->init_graphics();
 		 game2->init_Light();
 		 game3->init_graphics();
 		 game3->init_Light();
 	     game4->init_graphics();
 		 game4->init_Light();
 		 
 		    while(true) {
        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        if(msg.message==WM_QUIT) break;
        else
        {
        
  

 		
        update(0.0f,game);
        update(0.0f,game2);
        update(0.0f,game3);
        update(0.0f,game4);
        draw(game,0.0f);
        draw2(game2,0.0f);
        draw3(game3,0.0f);
        draw4(game4,0.0f);
        	
        if(KEY_DOWN(VK_ESCAPE))
            PostMessage(hwnd, WM_DESTROY, 0, 0);
		}
	}

	
	 return msg.wParam;

}
}
}
}
}

void API::controlCamera()
{
	 if(GetActiveWindow()==hwnd)
        {
		
    if(controlCamUp)
	       {
	       	GetCursorPos(&MousePos);    // get the mouse data
		    SetCursorPos((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
	       	game->cam[0]->moveCameraUp(((SCREEN_HEIGHT / 2) - MousePos.y)*0.02f);
		   }
 if(controlCamLateral)
           {
          
           	GetCursorPos(&MousePos);    // get the mouse data
		 SetCursorPos((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
           	game->cam[0]->moveCameraLeft(((SCREEN_WIDTH/ 2) - MousePos.x)*0.02f);
		   }
           game->cam[0]->controlCamera();
    }
     if(GetActiveWindow()==hwnd2)
        {
		
    if(controlCamUp)
	       {
	       	GetCursorPos(&MousePos);    // get the mouse data
		    SetCursorPos(600+(SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
	       	game2->cam[1]->moveCameraUp(((SCREEN_HEIGHT / 2) - MousePos.y)*0.02f);
		   }
 if(controlCamLateral)
           {
          
           	GetCursorPos(&MousePos);    // get the mouse data
		 SetCursorPos(600+(SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
           	game2->cam[1]->moveCameraLeft(((600+SCREEN_WIDTH/ 2) - MousePos.x)*0.02f);
		   }
           game2->cam[1]->controlCamera();
    }
     if(GetActiveWindow()==hwnd3)
        {
		
    if(controlCamUp)
	       {
	       	GetCursorPos(&MousePos);    // get the mouse data
		    SetCursorPos((SCREEN_WIDTH / 2), 300+(SCREEN_HEIGHT / 2));
	       	game3->cam[2]->moveCameraUp(((300+SCREEN_HEIGHT / 2) - MousePos.y)*0.02f);
		   }
 if(controlCamLateral)
           {
          
           	GetCursorPos(&MousePos);    // get the mouse data
		 SetCursorPos((SCREEN_WIDTH / 2), 300+(SCREEN_HEIGHT / 2));
           	game3->cam[2]->moveCameraLeft(((SCREEN_WIDTH/ 2) - MousePos.x)*0.02f);
		   }
           game3->cam[2]->controlCamera();
    }
    
     if(GetActiveWindow()==hwnd4)
        {
          
            if(controlCam)
            {
			
		//game4->cam[3]->camYaw+=0.001f;
   		   GetCursorPos(&MousePos);    // get the mouse data
		   SetCursorPos(600+(SCREEN_WIDTH / 2), 300+(SCREEN_HEIGHT / 2)); 
		   game4->cam[3]->setYaw(((600+SCREEN_WIDTH / 2) - MousePos.x)*0.002f);
		   game4->cam[3]->setPitch(((300+SCREEN_HEIGHT / 2) - MousePos.y)*0.002f);
	 }
	 
	       if(controlCamUp)
	       {
	     
	       	GetCursorPos(&MousePos);    // get the mouse data
		    SetCursorPos(600+(SCREEN_WIDTH / 2), 300+(SCREEN_HEIGHT / 2));
	       	game4->cam[3]->moveCameraUp(((300+SCREEN_HEIGHT / 2) - MousePos.y)*0.02f);
		   }
         
           
          if(controlCamLateral)
           {
          
           	GetCursorPos(&MousePos);    // get the mouse data
		 SetCursorPos(600+(SCREEN_WIDTH / 2), 300+(SCREEN_HEIGHT / 2));
           	game4->cam[3]->moveCameraLeft(((600+SCREEN_WIDTH/ 2) - MousePos.x)*0.02f);
		   }
       	  game4->cam[3]->controlCamera();
		
    }
}



HWND  API::getHWND()
{
	return hwnd;
}
HWND  API::getHWND2()
{
	return hwnd2;
}
HWND  API::getHWND3()
{
	return hwnd3;
}
HWND  API::getHWND4()
{
	return hwnd4;
}
void API::setControlCam(bool b)
{
	controlCam=b;
}
void API::setControlCamLateral(bool b)
{
	controlCamLateral=b;
}
bool API::getControlCamUp()
{
return controlCamUp;	
}
bool API::getControlCamLateral()
{
return controlCamLateral;	
}
void API::setControlCamUp(bool b)
{
	controlCamUp=b;
}
void API::setControlScrollWithCamUP(float movementZ)
{
	game->cam[0]->moveCamera(movementZ);

}
void API::setControlScrollWithCamUP2(float movementZ)
{
	game2->cam[1]->moveCamera(movementZ);

}
void API::setControlScrollWithCamUP3(float movementZ)
{
	game3->cam[2]->moveCamera(movementZ);

}
void API::setControlScrollWithCamUP4(float movementZ)
{
	game4->cam[3]->moveCamera(movementZ);

}


void API::setPhysicsMode(APIDIRECTX9 * game,bool b)
	{
	
			game->setPhysicsMode(b);
		
	}
void API::setStart(APIDIRECTX9 * game,bool b)
	{
	
		
			game->setStart(b);
	
	}
	void API::setQuit(APIDIRECTX9 * game,bool b)
	{
	
		
		game->setQuit(b);
	
	}
void API::setCharacterMode(APIDIRECTX9 * game,bool b)
	{
	
		
		game->setCharacterMode(b);
	
	}
	void API::setDriveMode(APIDIRECTX9 * game,bool b)
	{
	
		
			game->setDriveMode(b);
	
	}
	void API::setDynamicMode(APIDIRECTX9 * g,bool b)
	{
		
	  g->setDynamicMode(b);
	
	}
	void API::setStaticMode(APIDIRECTX9 * game,bool b)
	{
		
	
		game->setStaticMode(b);
	
	}
	
	
void API::update(float gameTime,APIDIRECTX9 * game)
{
	
controlCamera();
operationTransformationObject();
eraseObjectCube(game);
game->updateGameEditor();


}

void API::eraseObjectCube(APIDIRECTX9 * game)
{
   for(int i=0;i<game->cube.size();i++)
	if( KEY_DOWN(0xA2) && distance(game->cube[i]->getPosition().x,game->pp->getPosition().x,game->cube[i]->getPosition().y,game->pp->getPosition().y,
	game->cube[i]->getPosition().z,game->pp->getPosition().z)<5.0f)
	   game->cube.erase(game->cube.begin()+i);
	   
     for(int i=0;i<game->teapot.size();i++)
	if( KEY_DOWN(0xA2) && distance(game->teapot[i]->getPosition().x,game->pp->getPosition().x,game->teapot[i]->getPosition().y,game->pp->getPosition().y,
	game->teapot[i]->getPosition().z,game->pp->getPosition().z)<5.0f)
	   game->teapot.erase(game->teapot.begin()+i);
	   
	  for(int i=0;i<game->sphere.size();i++)
	if( KEY_DOWN(0xA2) && distance(game->sphere[i]->getPosition().x,game->pp->getPosition().x,game->sphere[i]->getPosition().y,game->pp->getPosition().y,
	game->sphere[i]->getPosition().z,game->pp->getPosition().z)<5.0f)
	   game->sphere.erase(game->sphere.begin()+i);   
	
	     for(int i=0;i<game->cylinder.size();i++)
	if( KEY_DOWN(0xA2) && distance(game-> cylinder[i]->getPosition().x,game->pp->getPosition().x,game-> cylinder[i]->getPosition().y,game->pp->getPosition().y,
	game-> cylinder[i]->getPosition().z,game->pp->getPosition().z)<5.0f)
	   game->cylinder.erase(game->cylinder.begin()+i); 
	   
	     for(int i=0;i<game->plane.size();i++)
	if( KEY_DOWN(0xA2) && distance(game-> plane[i]->getPosition().x,game->pp->getPosition().x,game-> plane[i]->getPosition().y,game->pp->getPosition().y,
	game-> plane[i]->getPosition().z,game->pp->getPosition().z)<5.0f)
	   game->plane.erase(game->plane.begin()+i);  
	
}

void API::operationTransformationObject()
{
	 if(KEY_DOWN(VK_SPACE) && incX) 
 {
   	incrementerX(vector3d(0.05f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && incY) 
 {
    incrementerY(vector3d(0,0.05f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && incZ) 
 {
   incrementerZ(vector3d(0,0,0.05f));

	
}

	 if(KEY_DOWN(VK_SPACE) && rot_x) 
 {
   rotX(vector3d(0.05f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && rot_y) 
 {
  rotY(vector3d(0,0.05f,0));

	
}

	 if(KEY_DOWN(VK_SPACE) && rot_z) 
 {
 rotZ(vector3d(0,0,0.05f));

	
}

	 if(KEY_DOWN(VK_SPACE) && rot_xNeg) 
 {
   rotX(vector3d(-0.05f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && rot_yNeg) 
 {
  rotY(vector3d(0,-0.05f,0));

	
}

	 if(KEY_DOWN(VK_SPACE) && rot_zNeg) 
 {
 rotZ(vector3d(0,0,-0.05f));

	
}

	 if(KEY_DOWN(VK_SPACE) && inc_xNeg) 
 {
   incrementerX(vector3d(-0.05f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && inc_yNeg) 
 {
  incrementerY(vector3d(0,-0.05f,0));

	
}

	 if(KEY_DOWN(VK_SPACE) && inc_zNeg) 
 {
 incrementerZ(vector3d(0,0,-0.05f));

	
}


	 if(KEY_DOWN(VK_SPACE) && scale_x) 
 {
scaleX(vector3d(0.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && scale_y) 
 {
scaleY(vector3d(0,0.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && scale_z) 
 {
scaleZ(vector3d(0,0,0.5f));

	
}

	 if(KEY_DOWN(VK_SPACE) && scale_x_neg) 
 {
scaleX(vector3d(-0.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && scale_y_neg) 
 {
scaleY(vector3d(0,-0.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && scale_z_neg) 
 {
scaleZ(vector3d(0,0,-0.5f));

	
}


	 if(KEY_DOWN(VK_SPACE) && colorX) 
 {
setColorX(vector3d(1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && colorY) 
 {
setColorY(vector3d(0,1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && colorZ) 
 {
setColorZ(vector3d(0,0,1.5f));

	
}

	 if(KEY_DOWN(VK_SPACE) && colorX_neg) 
 {
setColorX(vector3d(-1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && colorY_neg) 
 {
setColorY(vector3d(0,-1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && colorZ_neg) 
 {
setColorZ(vector3d(0,0,-1.5f));

	
}
	 if(KEY_DOWN(VK_SPACE) && ambiantX) 
 {
setAmbiantX(vector3d(1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && ambiantY) 
 {
setAmbiantY(vector3d(0,1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && ambiantZ) 
 {
setAmbiantZ(vector3d(0,0,1.5f));

	
}

	 if(KEY_DOWN(VK_SPACE) && ambiantX_neg) 
 {
setAmbiantX(vector3d(-1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && ambiantY_neg) 
 {
setAmbiantY(vector3d(0,-1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && ambiantZ_neg) 
 {
setAmbiantZ(vector3d(0,0,-1.5f));

	
}


	 if(KEY_DOWN(VK_SPACE) && specularX) 
 {
setSpecularX(vector3d(1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && specularY) 
 {
setSpecularY(vector3d(0,1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && specularZ) 
 {
setSpecularZ(vector3d(1.5f,0,0));

	
}

	 if(KEY_DOWN(VK_SPACE) && specularX_neg) 
 {
setSpecularX(vector3d(-1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && specularY_neg) 
 {
setSpecularY(vector3d(0,-1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && specularZ_neg) 
 {
setSpecularZ(vector3d(-1.5f,0,0));

	
}

	 if(KEY_DOWN(VK_SPACE) && emmissiveX) 
 {
setEmissiveX(vector3d(1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && emmissiveY) 
 {
setEmissiveY(vector3d(0,1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && emmissiveZ) 
 {
setEmissiveZ(vector3d(0,0,1.5f));

	
}

	 if(KEY_DOWN(VK_SPACE) && emmissiveX_neg) 
 {
setEmissiveX(vector3d(-1.5f,0,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && emmissiveY_neg) 
 {
setEmissiveY(vector3d(0,-1.5f,0));

	
}
	 if(KEY_DOWN(VK_SPACE) && emmissiveZ_neg) 
 {
setEmissiveZ(vector3d(0,0,-1.5f));

	
}

	 if(KEY_DOWN(VK_SPACE) && power_) 
 {
setPower(1.5f);

	
}
	 if(KEY_DOWN(VK_SPACE) && alpha_) 
 {
setAlpha(1.5f);

	
}
	 if(KEY_DOWN(VK_SPACE) && power_neg) 
 {
setPower(-1.5f);

	
}
	 if(KEY_DOWN(VK_SPACE) && alpha_neg) 
 {
setAlpha(-1.5f);

	
}
	 if(KEY_DOWN(VK_SPACE) && bg_colX) 
 {
bg_colorX(1.5f);

	
}
	 if(KEY_DOWN(VK_SPACE) && bg_colY) 
 {
bg_colorY(1.5f);

	
}

	 if(KEY_DOWN(VK_SPACE) && bg_colZ) 
 {
bg_colorZ(1.5f);

	
}


	 if(KEY_DOWN(VK_SPACE) && bg_colXNeg) 
 {
bg_colorX(-1.5f);

	
}
	 if(KEY_DOWN(VK_SPACE) && bg_colYNeg) 
 {
bg_colorY(-1.5f);

	
}

	 if(KEY_DOWN(VK_SPACE) && bg_colZNeg) 
 {
bg_colorZ(-1.5f);

	
}
	 if(KEY_DOWN(VK_SPACE) && dist) 
 {
setDist(1.0f);

	
}
	 if(KEY_DOWN(VK_SPACE) && dist_neg) 
 {
setDist(-1.0f);

	
}
}
	
	//game->setTranslate();
	//game->setPosition(vector3d(translate.x,translate.y,translate.z));
	/*
	game->setRotation(vector3d(rotate.x,rotate.y,rotate.z));
	game->setScale(vector3d(scale.x,scale.y,scale.z));
	game->setColor(vector3d(color.x,color.y,color.z));
	game->setSpecular(vector3d(specular.x,specular.y,specular.z));
	game->setEmissive(vector3d(emissive.x,emissive.y,emissive.z));
	game->setAmbiant(vector3d(ambiant.x,ambiant.y,ambiant.z));
	game->setPower(power);
	game->setAlpha(alpha);
	*/
 	
void API::setDist_(bool b)
{
	dist=b;
}

void API::setDist_neg(bool b)
{
	dist_neg=b;
}
void API::setIncX(bool b)
{
	incX=b;
}
void API::setIncY(bool b)
{
	incY=b;
}
void API::setIncZ(bool b)
{
	incZ=b;
}
void API::setRotX(bool b)
{
	rot_x=b;
}
void API::setRotY(bool b)
{
	rot_y=b;
}
void API::setRotZ(bool b)
{
	rot_z=b;
}

void API::setRotXNeg(bool b)
{
	rot_xNeg=b;
}
void API::setRotYNeg(bool b)
{
	rot_yNeg=b;
}
void API::setRotZNeg(bool b)
{
	rot_zNeg=b;
}
void API::setIncXNeg(bool b)
{
	inc_xNeg=b;
}
void API::setIncYNeg(bool b)
{
	inc_yNeg=b;
}
void API::setIncZNeg(bool b)
{
	inc_zNeg=b;
}
void API::setScale_x(bool b)
{
	scale_x=b;
}
void API::setScale_y(bool b)
{
	scale_y=b;
}
void API::setScale_z(bool b)
{
	scale_z=b;
}
void API::setScale_x_neg(bool b)
{
	scale_x_neg=b;
}
void API::setScale_y_neg(bool b)
{
	scale_y_neg=b;
}
void API::setScale_z_neg(bool b)
{
	scale_z_neg=b;
}
void API::setColorX_(bool b)
{
	colorX=b;
}
void API::setColorY_(bool b)
{
	colorY=b;
}
void API::setColorZ_(bool b)
{
	colorZ=b;
}
void API::setColorX_neg(bool b)
{
	colorX_neg=b;
}
void API::setColorY_neg(bool b)
{
	colorY_neg=b;
}
void API::setColorZ_neg(bool b)
{
	colorZ_neg=b;
}
void API::setAmbiantX_(bool b)
{
	ambiantX=b;
}
void API::setAmbiantY_(bool b)
{
	ambiantY=b;
}
void API::setAmbiantZ_(bool b)
{
	ambiantZ=b;
}
void API::setAmbiantX_neg(bool b)
{
	ambiantX_neg=b;
}
void API::setAmbiantY_neg(bool b)
{
	ambiantY_neg=b;
}
void API::setAmbiantZ_neg(bool b)
{
	ambiantZ_neg=b;
}
void API::setSpecularX_(bool b)
{
	specularX=b;
}
void API::setSpecularY_(bool b)
{
	specularY=b;
}
void API::setSpecularZ_(bool b)
{
	specularZ=b;
}
void API::setSpecularX_neg(bool b)
{
	specularX_neg=b;
}
void API::setSpecularY_neg(bool b)
{
	specularY_neg=b;
}
void API::setSpecularZ_neg(bool b)
{
	specularZ_neg=b;
}
void API::setEmmissiveX_(bool b)
{
	emmissiveX=b;
}
void API::setEmmissiveY_(bool b)
{
	emmissiveY=b;
}
void API::setEmmissiveZ_(bool b)
{
	emmissiveZ=b;
}
void API::setEmmissiveX_neg(bool b)
{
	emmissiveX_neg=b;
}
void API::setEmmissiveY_neg(bool b)
{
	emmissiveY_neg=b;
}
void API::setEmmissiveZ_neg(bool b)
{
	emmissiveZ_neg=b;
}
void API::setAlpha_(bool b)
{
	alpha_=b;
}
void API::setPower_(bool b)
{
	power_=b;
}
void API::setAlpha_neg(bool b)
{
	alpha_neg=b;
}
void API::setPower_neg(bool b)
{
	power_neg=b;
}
void API::setbg_colX(bool b)
{
	bg_colX=b;
}
void API::setbg_colY(bool b)
{
	bg_colY=b;
}

void API::setbg_colZ(bool b)
{
	bg_colZ=b;
}

void API::setbg_colXNeg(bool b)
{
	bg_colXNeg=b;
}
void API::setbg_colYNeg(bool b)
{
	bg_colYNeg=b;
}

void API::setbg_colZNeg(bool b)
{
	bg_colZNeg=b;
}

void API::addCube()
{

	   game->loadCUBE(game->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
	   game2->loadCUBE(game2->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
	   game3->loadCUBE(game3->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
	   game4->loadCUBE(game4->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
	   
}

void API::addPlane()
{

	   game->loadPlane(game->pp->getPosition()+vector3d(0,-4,0),vector3d(0,0,0),vector3d(5,1,5),vector3d(0.2,0.7,1.0));
	   game2->loadPlane(game2->pp->getPosition()+vector3d(0,-4,0),vector3d(0,0,0),vector3d(5,1,5),vector3d(0.2,0.7,1.0));
	   game3->loadPlane(game3->pp->getPosition()+vector3d(0,-4,0),vector3d(0,0,0),vector3d(5,1,5),vector3d(0.2,0.7,1.0));
	   game4->loadPlane(game4->pp->getPosition()+vector3d(0,-4,0),vector3d(0,0,0),vector3d(5,1,5),vector3d(0.2,0.7,1.0));
	   
}

void API::addSphere()
{
	
		 game->loadSphere(game->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
 		 game2->loadSphere(game2->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
 		 game3->loadSphere(game3->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
 		 game4->loadSphere(game4->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
}
void API::addTeapot()
{
	
		 game->loadTeapot(game->pp->getPosition(),vector3d(0,0,0),vector3d(2,2,2),vector3d(0.2,0.7,1.0));
 		 game2->loadTeapot(game2->pp->getPosition(),vector3d(0,0,0),vector3d(2,2,2),vector3d(0.2,0.7,1.0));
 		 game3->loadTeapot(game3->pp->getPosition(),vector3d(0,0,0),vector3d(2,2,2),vector3d(0.2,0.7,1.0));
 		 game4->loadTeapot(game4->pp->getPosition(),vector3d(0,0,0),vector3d(2,2,2),vector3d(0.2,0.7,1.0));
}
void API::addCylinder()
{
	
		 game->loadCylinder(game->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
 		 game2->loadCylinder(game2->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
 		 game3->loadCylinder(game3->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
 		 game4->loadCylinder(game4->pp->getPosition(),vector3d(0,0,0),vector3d(1,1,1),vector3d(0.2,0.7,1.0));
}

void API::setDist(float d)
{
	game->setDist(d);
	game2->setDist(d);
	game3->setDist(d);
	game4->setDist(d);
}

void API::setColorX(vector3d col)
{
	game->setColorInc(vector3d(col.x,0,0));
	game2->setColorInc(vector3d(col.x,0,0));
	game3->setColorInc(vector3d(col.x,0,0));
	game4->setColorInc(vector3d(col.x,0,0));
}
void API::setColorY(vector3d col)
{
	game->setColorInc(vector3d(0,col.y,0));
	game2->setColorInc(vector3d(0,col.y,0));
	game3->setColorInc(vector3d(0,col.y,0));
	game4->setColorInc(vector3d(0,col.y,0));
}
void API::setColorZ(vector3d col)
{
	game->setColorInc(vector3d(0,0,col.z));
	game2->setColorInc(vector3d(0,0,col.z));
	game3->setColorInc(vector3d(0,0,col.z));
	game4->setColorInc(vector3d(0,0,col.z));
}
void API::setAmbiantX(vector3d amb)
{
	game->setAmbiant(vector3d(amb.x,0,0));
	game2->setAmbiant(vector3d(amb.x,0,0));
	game3->setAmbiant(vector3d(amb.x,0,0));
	game4->setAmbiant(vector3d(amb.x,0,0));	
}
void API::setAmbiantY(vector3d amb)
{
	game->setAmbiant(vector3d(0,amb.y,0));
	game2->setAmbiant(vector3d(0,amb.y,0));
	game3->setAmbiant(vector3d(0,amb.y,0));
	game4->setAmbiant(vector3d(0,amb.y,0));	
}
void API::setAmbiantZ(vector3d amb)
{
	game->setAmbiant(vector3d(0,0,amb.z));
	game2->setAmbiant(vector3d(0,0,amb.z));
	game3->setAmbiant(vector3d(0,0,amb.z));
	game4->setAmbiant(vector3d(0,0,amb.z));		
}
void API::setSpecularX(vector3d spec)
{
	game->setSpecular(vector3d(spec.x,0,0));
	game2->setSpecular(vector3d(spec.x,0,0));
	game3->setSpecular(vector3d(spec.x,0,0));
	game4->setSpecular(vector3d(spec.x,0,0));	
}
void API::setSpecularY(vector3d spec)
{
	game->setSpecular(vector3d(0,spec.y,0));
	game2->setSpecular(vector3d(0,spec.y,0));
	game3->setSpecular(vector3d(0,spec.y,0));
	game4->setSpecular(vector3d(0,spec.y,0));
}
void API::setSpecularZ(vector3d spec)
{
	game->setSpecular(vector3d(0,0,spec.z));
	game2->setSpecular(vector3d(0,0,spec.z));
	game3->setSpecular(vector3d(0,0,spec.z));
	game4->setSpecular(vector3d(0,0,spec.z));
}
void API::setEmissiveX(vector3d emmis)
{
	game->setEmissive(vector3d(emmis.x,0,0));
	game2->setEmissive(vector3d(emmis.x,0,0));
	game3->setEmissive(vector3d(emmis.x,0,0));
	game4->setEmissive(vector3d(emmis.x,0,0));
}
void API::setEmissiveY(vector3d emmis)
{
	game->setEmissive(vector3d(0,emmis.y,0));
	game2->setEmissive(vector3d(0,emmis.y,0));
	game3->setEmissive(vector3d(0,emmis.y,0));
	game4->setEmissive(vector3d(0,emmis.y,0));
}
void API::setEmissiveZ(vector3d emmis)
{
	game->setEmissive(vector3d(0,0,emmis.z));
	game2->setEmissive(vector3d(0,0,emmis.z));
	game3->setEmissive(vector3d(0,0,emmis.z));
	game4->setEmissive(vector3d(0,0,emmis.z));
}
void API::setPower(float pow)
{
	game->setPower(pow);
	game2->setPower(pow);
	game3->setPower(pow);
	game4->setPower(pow);
}
void API::setAlpha(float alph)
{
	game->setAlpha(alph);
	game2->setAlpha(alph);
	game3->setAlpha(alph);
	game4->setAlpha(alph);
}
void API::incrementerX(vector3d inc)
{

	game->setTranslate(vector3d(inc.x,0,0));
 
	game2->setTranslate(vector3d(inc.x,0,0));

	game3->setTranslate(vector3d(inc.x,0,0));

	game4->setTranslate(vector3d(inc.x,0,0));

}
void API::incrementerY(vector3d inc)
{

	game->setTranslate(vector3d(0,inc.y,0));
	game2->setTranslate(vector3d(0,inc.y,0));
	game3->setTranslate(vector3d(0,inc.y,0));
	game4->setTranslate(vector3d(0,inc.y,0));

}
void API::incrementerZ(vector3d inc)
{
	
	game->setTranslate(vector3d(0,0,inc.z));
	game2->setTranslate(vector3d(0,0,inc.z));
	game3->setTranslate(vector3d(0,0,inc.z));
	game4->setTranslate(vector3d(0,0,inc.z));

}

void API::rotX(vector3d r)
{
	
	game->setRotate(vector3d(r.x,0,0));
	game2->setRotate(vector3d(r.x,0,0));
	game3->setRotate(vector3d(r.x,0,0));
	game4->setRotate(vector3d(r.x,0,0));
	
}
void API::rotY(vector3d r)
{
	game->setRotate(vector3d(0,r.y,0));
	game2->setRotate(vector3d(0,r.y,0));
	game3->setRotate(vector3d(0,r.y,0));
	game4->setRotate(vector3d(0,r.y,0));
	
}
void API::rotZ(vector3d r)
{
	game->setRotate(vector3d(0,0,r.z));
	game2->setRotate(vector3d(0,0,r.z));
	game3->setRotate(vector3d(0,0,r.z));
	game4->setRotate(vector3d(0,0,r.z));
	
}

void API::scaleX(vector3d s)
{
	game->setScaleInc(vector3d(s.x,0,0));
	game2->setScaleInc(vector3d(s.x,0,0));
	game3->setScaleInc(vector3d(s.x,0,0));
	game4->setScaleInc(vector3d(s.x,0,0));
}
void API::scaleY(vector3d s)
{
	game->setScaleInc(vector3d(0,s.y,0));
	game2->setScaleInc(vector3d(0,s.y,0));
	game3->setScaleInc(vector3d(0,s.y,0));
	game4->setScaleInc(vector3d(0,s.y,0));
}
void API::scaleZ(vector3d s)
{
	game->setScaleInc(vector3d(0,0,s.z));
	game2->setScaleInc(vector3d(0,0,s.z));
	game3->setScaleInc(vector3d(0,0,s.z));
	game4->setScaleInc(vector3d(0,0,s.z));
}
void API::bg_colorX(float bg_X)
{
	bg_color.x+=bg_X;
}
void API::bg_colorY(float bg_Y)
{
	bg_color.y+=bg_Y;
}
void API::bg_colorZ(float bg_Z)
{
	bg_color.z+=bg_Z;
}

void API::draw(APIDIRECTX9 * game,float gameTime)
{
	game->Clear(  D3DCOLOR_XRGB((int)bg_color.x, (int)bg_color.y, (int)bg_color.z));
	game->begin();
	game->render_frame();
	game->end();
	game->present();
	
}
void API::draw2(APIDIRECTX9 * game,float gameTime)
{
	game->Clear(  D3DCOLOR_XRGB((int)bg_color.x, (int)bg_color.y, (int)bg_color.z));
	game->begin();
	game->render_frame2();
	game->end();
	game->present();
	
}

void API::draw3(APIDIRECTX9 * game,float gameTime)
{
	game->Clear( D3DCOLOR_XRGB((int)bg_color.x, (int)bg_color.y, (int)bg_color.z));
	game->begin();
	game->render_frame3();
	game->end();
	game->present();
	
}

void API::draw4(APIDIRECTX9 * game,float gameTime)
{
	game->Clear(  D3DCOLOR_XRGB((int)bg_color.x, (int)bg_color.y, (int)bg_color.z));
	game->begin();
	game->render_frame4();
	//game->Render_Circle(game);
	game->end();
	game->present();
	
}


void reshape(int width,int height)
{
	
	g.reshape(width,height); 

}
void fenetre1()
{
	g.show();
}
void fenetre2()              
{
	g.show2();
}
void fenetre3()
{
	g.show3();
}
void fenetre4()
{
							    
	g.show4();
}


void keyboardInput(unsigned char key,int x,int y)
{

g.controlKeyboard(key,x,y);


switch(key)
 	{
 		
 	
 		case 'p':
 			
 
 	if(g.startG())
 		{
		 
 glutInitWindowPosition(0,0);
glutInitWindowSize(960,540);	//Optionnel
windowName5 = glutCreateWindow("V-Engine 4.0 Perspective view");
g5.initGL();
glutReshapeFunc(reshape);// configuration du mode de projection du pixel à l'ecran
 glutDisplayFunc(fenetre4);
 glutKeyboardFunc(keyboardInput);
 glutKeyboardUpFunc(passiveKeyboard);
  glutMouseWheelFunc(mouseWheel);
   glutMotionFunc(mouseMotion);
 glutMouseFunc(mouse);
 glutSpecialFunc(specialKey);
 glutSpecialUpFunc(passiveSpecialKeyboard);



}
 break;
case 127:
	if(g.startG())
 		{
		 
	glutDestroyWindow(windowName5);
}
 	break;
	 }
	 
	 
}
void passiveKeyboard(unsigned char key,int x,int y)
{
g.passiveKeyboard(key,x,y);
}
void passiveMouse(int x,int y)
{
	g.passiveMotion(x,y);
}
void mouseMotion(int x, int y)
{
	g.mouseMotion(x,y);
}
void mouseMotion2(int x, int y)
{
	g.mouseMotion2(x,y);
}
void mouseMotion3(int x, int y)
{
	g.mouseMotion3(x,y);
}
void mouseMotion4(int x, int y)
{
	g.mouseMotion4(x,y);
}
void passiveSpecialKeyboard(int key,int x, int y)
{
	g.passiveSpecialKeyboard( key, x,  y);
}
void specialKey(int key,int x, int y)
{
	g.controlSpecialKeyboard( key, x,  y);
}
void mouse(int button, int state, int x, int y)
{
	g.mouse(button,state,x,y);
}
void mouse2(int button, int state, int x, int y)
{
	g.mouse2(button,state,x,y);
}
void mouse3(int button, int state, int x, int y)
{
	g.mouse3(button,state,x,y);
}
void mouse4(int button, int state, int x, int y)
{
	g.mouse4(button,state,x,y);
}

void mouseWheel(int x, int y, int z,int w)
{
	g.mouseWheel( x,  y,  z,  w);
}
void mouseWheel2(int x, int y, int z,int w)
{
	g.mouseWheel2( x,  y,  z,  w);
}
void mouseWheel3(int x, int y, int z,int w)
{
	g.mouseWheel3( x,  y,  z,  w);
}
void mouseWheel4(int x, int y, int z,int w)
{
	g.mouseWheel4( x,  y,  z,  w);
}
