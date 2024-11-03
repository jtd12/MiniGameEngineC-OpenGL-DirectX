#include"API_DIRECTX.h"

APIDIRECTX9::APIDIRECTX9()
{
		startGame=false;
		time=0.0f;
		lanchGame=false;
		quitGame=false;
		physicsMode=false;
		
		dist=5.0f;
     	cam.push_back(new cameraX());
     	cam.push_back(new cameraX());
     	cam.push_back(new cameraX());
     	cam.push_back(new cameraX());
     	cam[0]->setRotation(0.0f, 0.0f, 0.0f);
     	cam[1]->setRotation(0.0f, 1.5f, 0.0f);
     	cam[2]->setRotation(1.5f, 0.0f, 0.0f);
     	cam[3]->setRotation(0.5f, 0.0f, 0.0f);
     	cc=new objectX(vector3d(0,0,0),vector3d(0,0,0),vector3d(1,1,1),vector3d(220,220,200));
		pp=new pointerX();
		for(int i=0;i<40;i++)
		 for(int j=0;j<40;j++)
	     	grid.push_back(new objectX(vector3d(i*6,-5,j*6),vector3d(0,0,0),vector3d(1,1,1),vector3d(100,100,100)));
	
}
APIDIRECTX9::~APIDIRECTX9()
{
	 for(int i=0;i<cam.size();i++)
	   delete cam[i];
	delete pp;
	for(int i=0;i<cube.size();i++)
	 {
	 	delete cube[i];
	 }
	 	for(int i=0;i<teapot.size();i++)
	 {
	 	delete teapot[i];
	 }
	 	for(int i=0;i<cylinder.size();i++)
	 {
	 	delete cylinder[i];
	 }
	 	for(int i=0;i<sphere.size();i++)
	 {
	 	delete sphere[i];
	 }
	 	 	for(int i=0;i<plane.size();i++)
	 {
	 	delete plane[i];
	 }
	 	 	for(int i=0;i<grid.size();i++)
	 {
	 	delete grid[i];
	 }
	 
if(d3d)
{

    d3d->Release();			// close and release Direct3D
    d3d=NULL;
}
if(d3ddev)
{
	  d3ddev->Release();		// close and release the 3D device
	  d3ddev=NULL;
}

//delete cube[0];
/*
cube->vertexbuffer->Release();
cube->vertexbuffer=NULL;
cube->i_buffer->Release();
cube->i_buffer=NULL;
*/

}
void APIDIRECTX9::loadCUBE(vector3d t,vector3d r, vector3d s,vector3d c)
{
	cube.push_back(new objectX(t,r,s,c));
	for(int i=0;i<cube.size();i++)
	cube[i]->init_Cube(d3ddev);
}

void APIDIRECTX9::loadTeapot(vector3d t,vector3d r, vector3d s,vector3d c)
{
	teapot.push_back(new objectX(t,r,s,c));
	for(int i=0;i<teapot.size();i++)
	teapot[i]->init_Teapot(d3ddev);
}
void APIDIRECTX9::loadPlane(vector3d t,vector3d r, vector3d s,vector3d c)
{
	plane.push_back(new objectX(t,r,s,c));
	for(int i=0;i<plane.size();i++)
	plane[i]->init_Plane(d3ddev);
}
void APIDIRECTX9::loadSphere(vector3d t,vector3d r, vector3d s,vector3d c)
{
	sphere.push_back(new objectX(t,r,s,c));
	for(int i=0;i<sphere.size();i++)
	sphere[i]->init_Sphere(d3ddev);
}
void APIDIRECTX9::loadCylinder(vector3d t,vector3d r, vector3d s,vector3d c)
{
	cylinder.push_back(new objectX(t,r,s,c));
	for(int i=0;i<cylinder.size();i++)
	cylinder[i]->init_Cylinder(d3ddev);
}
void APIDIRECTX9::init_graphics()
{
   for(int i=0;i<grid.size();i++)
	 grid[i]->init_Plane(d3ddev);
	 pp->init_graphics(d3ddev);

 
}

void APIDIRECTX9::initD3D(HWND hwnd,bool windowed) {
	//cube.push_back( new objectX());
	 

	
    d3d = Direct3DCreate9(D3D_SDK_VERSION);

    D3DPRESENT_PARAMETERS d3dpp;

    ZeroMemory(&d3dpp, sizeof(d3dpp));
    
    d3dpp.Windowed 					= windowed;
    d3dpp.SwapEffect 				= D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow 			= hwnd;
    d3dpp.BackBufferFormat	 		= D3DFMT_X8R8G8B8;
    d3dpp.BackBufferWidth 			= SCREEN_WIDTH;
    d3dpp.BackBufferHeight 			= SCREEN_HEIGHT;
    d3dpp.EnableAutoDepthStencil 	= true;        // Manage SetDepthStencil for us
    d3dpp.AutoDepthStencilFormat 	= D3DFMT_D16;	// 16-bit pixel format for the z-buffer

    // create a device class using this information and the info from the d3dpp stuct
    d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_MIXED_VERTEXPROCESSING, &d3dpp, &d3ddev);

	// Create resources
   

    d3ddev->SetRenderState(D3DRS_LIGHTING, true);    		// turn off the 3D lighting
   // d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	// both sides of the triangles
    d3ddev->SetRenderState(D3DRS_ZENABLE,  true);			// turn on the z-buffer
    d3ddev->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_XRGB(50,50,50));
   
    
}


void APIDIRECTX9::Clear(D3DCOLOR color)
{
	  d3ddev->Clear(0, NULL, D3DCLEAR_TARGET,  color, 1.0f, 0);
    d3ddev->Clear(0, NULL, D3DCLEAR_ZBUFFER, color, 1.0f, 0);
}
void APIDIRECTX9::begin()
{
	
    d3ddev->BeginScene();
}
void APIDIRECTX9::end()
{
	   d3ddev->EndScene();
}
void APIDIRECTX9::present()
{
	  d3ddev->Present(NULL, NULL, NULL, NULL);
}
void APIDIRECTX9::init_Light()
{
	D3DLIGHT9 light;
	D3DLIGHT9 light2;
	ZeroMemory(&light,sizeof(light));
	light.Type=D3DLIGHT_DIRECTIONAL;
	light.Diffuse=D3DXCOLOR(0.8,0.8,1.0,1.0);
	light.Direction=D3DXVECTOR3(-2.0,-1.0,1.0);
	d3ddev->SetLight(0,&light);
	d3ddev->LightEnable(0,true);
	light2.Type=D3DLIGHT_DIRECTIONAL;
	light2.Diffuse=D3DXCOLOR(0.2,0.2,0.5,1.0);
	light2.Direction=D3DXVECTOR3(2.0,1.0,1.0);
	d3ddev->SetLight(1,&light2);
	d3ddev->LightEnable(1,true);
	
	
}
void APIDIRECTX9::Callback()
{
	 //cam->DetectInput(0.5f);
	 if(KEY_DOWN(VK_LEFT)) 
   pp->setTranslate(vector3d(-0.5,0,0.0));
if(KEY_DOWN(VK_RIGHT)) 
   pp->setTranslate(vector3d(0.5,0,0.0));
if(KEY_DOWN(VK_UP)) 
   pp->setTranslate(vector3d(0.0,0,0.5));
if(KEY_DOWN(VK_DOWN)) 
   pp->setTranslate(vector3d(0.0,0,-0.5));

	 if(KEY_DOWN(VK_LEFT)) 
   		left=true;
if(KEY_DOWN(VK_RIGHT)) 
   right=true;
if(KEY_DOWN(VK_UP)) 
   up=true;
if(KEY_DOWN(VK_DOWN)) 
   down=true;
   
   	 if(KEY_DOWN(VK_LEFT)==false) 
   		left=false;
if(KEY_DOWN(VK_RIGHT)==false) 
   right=false;
if(KEY_DOWN(VK_UP)==false) 
   up=false;
if(KEY_DOWN(VK_DOWN)==false) 
   down=false;

  
}


void APIDIRECTX9::GameMode(std::vector<objectX*> obj_,std::vector<objectX*> pref_,std::vector<objectX*> prefAnim_)
{
	
time+=0.1f;


if(quitGame)
{
	lanchGame=false;
	physicsMode=false;
	
			
}

if(lanchGame==false && quitGame)
{
reinitialiseGame(cube,pref,prefAnim);
reinitialiseGame(plane,pref,prefAnim);
reinitialiseGame(teapot,pref,prefAnim);
reinitialiseGame(sphere,pref,prefAnim);
reinitialiseGame(cylinder,pref,prefAnim);
reinitialiseGame(grid,pref,prefAnim);

}

if(lanchGame==false)
{
	physicsMode=false;


		for(int i=0;i<obj_.size();i++)
{
	obj_[i]->update();
}
	
}

if(startGame)
{
	lanchGame=true;
	quitGame=false;
	
}
if(lanchGame && physicsMode)
{

startGame=false;
			for(int i=0;i<obj_.size();i++)
		
						if(obj_[i]->getDynamic())
			{
						obj_[i]->physics();
					
			}
				
				
						for(int i=0;i<pref_.size();i++)
			if(pref_[i]->getDynamic())
			{
					
						pref_[i]->physics();	
				}
				
						for(int i=0;i<prefAnim_.size();i++)
			if(prefAnim_[i]->getDynamic())
			{
					
						prefAnim_[i]->physics();
				}			
}

		for(int i=0;i<pref_.size();i++)
if(lanchGame && pref_[i]->getDrive() && physicsMode)
{
	

	
	pref_[i]->movement(up,down,right,left);

	
	
	
	/*
		
		for(int i=0;i<pref.size();i++)
			for(int j=0;j<obj.size();j++)
		if(obj[j]->getRotation().x!=0 || obj[j]->getRotation().y!=0 || obj[j]->getRotation().z!=0)
		 obj[j]->setRotation(vector3d(0,0,0));
		 */
		 

}
		for(int i=0;i<obj_.size();i++)
if(lanchGame && obj_[i]->getDrive() && physicsMode)
{
	

	
	obj_[i]->movement(up,down,right,left);

	
	
	
	/*
		
		for(int i=0;i<pref.size();i++)
			for(int j=0;j<obj.size();j++)
		if(obj[j]->getRotation().x!=0 || obj[j]->getRotation().y!=0 || obj[j]->getRotation().z!=0)
		 obj[j]->setRotation(vector3d(0,0,0));
		 */
		 

}
	for(int i=0;i<obj_.size();i++)
if(lanchGame && obj_[i]->getWalk() && physicsMode)
{
	

	
	obj_[i]->movementCharacter(up,down,right,left);

	
	
	
	/*
		
		for(int i=0;i<pref.size();i++)
			for(int j=0;j<obj.size();j++)
		if(obj[j]->getRotation().x!=0 || obj[j]->getRotation().y!=0 || obj[j]->getRotation().z!=0)
		 obj[j]->setRotation(vector3d(0,0,0));
		 */
		 

}
	
	for(int i=0;i<prefAnim_.size();i++)
if(lanchGame && prefAnim_[i]->getWalk() && physicsMode)
{
		
//	prefAnim_[i]->update(up,down);
	
	
	prefAnim_[i]->movementCharacter(up,down,right,left);	
}
/*
	for(int i=0;i<obj5.size();i++)
		obj5[i]->setCollision(true);
		*/
}

void APIDIRECTX9::collision(std::vector<objectX*> obj_,std::vector<objectX*> obj2_)
{

	for(int i=0;i<obj_.size();i++)
				{
			for(int j=0;j<obj2_.size();j++)
{


if(obj_[i]->getDynamic())
{
	if(obj2_[j]->getDynamic()==false)
	{
	

vector3d posobj=obj_[i]->getLocation();
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP1(),obj2_[j]->getP2(),obj2_[j]->getP3(),obj2_[j]->getP4(),0.9);
collision::sphereplane(posobj,vector3d(4,0,0),obj2_[j]->getP5(),obj2_[j]->getP6(),obj2_[j]->getP7(),obj2_[j]->getP8(),0.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP9(),obj2_[j]->getP10(),obj2_[j]->getP11(),obj2_[j]->getP12(),0.9);
collision::sphereplane(posobj,vector3d(0,0,4),obj2_[j]->getP13(),obj2_[j]->getP14(),obj2_[j]->getP15(),obj2_[j]->getP16(),0.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP17(),obj2_[j]->getP18(),obj2_[j]->getP19(),obj2_[j]->getP20(),0.9);
collision::sphereplane(posobj,vector3d(0,2.5,0),obj2_[j]->getP21(),obj2_[j]->getP22(),obj2_[j]->getP23(),obj2_[j]->getP24(),0.9);
obj_[i]->setLocation(posobj);




}
}
}
}
}


void APIDIRECTX9:: reinitialiseGame(std::vector<objectX*> obj_,std::vector<objectX*> pref_,std::vector<objectX*> prefAnim_)
{
	for(int i=0;i<pref.size();i++)

pref_[i]->setLocation(vector3d(pref_[i]->getLocation().x,pp->getPosition().y,pref_[i]->getLocation().z));

for(int i=0;i<prefAnim.size();i++)

prefAnim_[i]->setLocation(vector3d(prefAnim_[i]->getLocation().x,pp->getPosition().y,prefAnim[i]->getLocation().z));

for(int i=0;i<obj_.size();i++)
obj_[i]->setLocation(vector3d(obj_[i]->getLocation().x,pp->getPosition().y,obj_[i]->getLocation().z));


}

void APIDIRECTX9::updateGameEditor()
 {
 	
collision( cube,plane);
collision( cube,teapot);
collision( cube,sphere);
collision( cube,cylinder);


collision( teapot,plane);
collision( teapot,cube);
collision( teapot,sphere);
collision( teapot,cylinder);


collision( sphere,plane);
collision( sphere,teapot);
collision( sphere,cube);
collision( sphere,cylinder);


collision( plane,sphere);
collision( plane,teapot);
collision( plane,cube);
collision( plane,cylinder);


collision( pref,sphere);
collision( pref,teapot);
collision( pref,cube);
collision( pref,cylinder);
collision( pref,plane);

collision( prefAnim,sphere);
collision( prefAnim,teapot);
collision( prefAnim,cube);
collision( prefAnim,cylinder);
collision( prefAnim,plane);

GameMode(cube,pref,prefAnim);
GameMode(sphere,pref,prefAnim);
GameMode(plane,pref,prefAnim);
GameMode(cylinder,pref,prefAnim);
GameMode(teapot,pref,prefAnim);

 }

void APIDIRECTX9::render_frame() {
D3DXMATRIX matView;
//loadCUBE();
    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

    // set the view transform

   cam[0]->update( d3ddev);

	
    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
                               D3DXToRadian(45),			// the vertical field of view
                               800.0f/600.0f,			// aspect ratio
                               1.0f,						// the near view-plane
                               1000.0f);						// the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);
 
 	
   // if(KEY_DOWN(VK_RIGHT)) pp->setTranslate();

    // handle 'D' key
		   
pp->show(d3ddev);
	for(int i=0;i<teapot.size();i++)
 teapot[i]->showTeapot(d3ddev);
 	for(int i=0;i<sphere.size();i++)
 sphere[i]->showSphere(d3ddev);
   for(int i=0;i<cylinder.size();i++)
cylinder[i]->showCylinder(d3ddev);  
for(int i=0;i<cube.size();i++)	
 cube[i]->showCube(d3ddev);
 for(int i=0;i<plane.size();i++)	
plane[i]->showPlane(d3ddev);
for(int i=0;i<grid.size();i++)
 grid[i]->showGrid(d3ddev);
 Render_Circle();

Callback();

 /*
   D3DXMatrixTranslation(&matTranslateB, 0.0f, 0.0f, 1.0f);
	matTemp = matTranslateB;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
*/


  
}

void APIDIRECTX9::render_frame2() {


    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

    // set the view transform
   cam[1]->update( d3ddev);

    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
                               D3DXToRadian(45),			// the vertical field of view
                               800.0f/600.0f,			// aspect ratio
                               1.0f,						// the near view-plane
                               1000.0f);						// the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);
pp->show(d3ddev);

for(int i=0;i<teapot.size();i++)	
 teapot[i]->showTeapot(d3ddev);
 	for(int i=0;i<sphere.size();i++)
 sphere[i]->showSphere(d3ddev);
for(int i=0;i<cube.size();i++)
cube[i]->showCube(d3ddev);
  for(int i=0;i<cylinder.size();i++)
cylinder[i]->showCylinder(d3ddev);  
  for(int i=0;i<plane.size();i++)	
plane[i]->showPlane(d3ddev);
for(int i=0;i<grid.size();i++)
 grid[i]->showGrid(d3ddev);
  Render_Circle();
Callback();


  
}


void APIDIRECTX9::render_frame3() {


    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

    // set the view transform
    cam[2]->update( d3ddev);

    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
                               D3DXToRadian(45),			// the vertical field of view
                               800.0f/600.0f,			// aspect ratio
                               1.0f,						// the near view-plane
                               1000.0f);						// the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);
pp->show(d3ddev);

for(int i=0;i<teapot.size();i++)	
 teapot[i]->showTeapot(d3ddev);
 	for(int i=0;i<sphere.size();i++)
 sphere[i]->showSphere(d3ddev);
 	  for(int i=0;i<cylinder.size();i++)
cylinder[i]->showCylinder(d3ddev);  
for(int i=0;i<cube.size();i++)
  cube[i]->showCube(d3ddev);
   for(int i=0;i<plane.size();i++)	
plane[i]->showPlane(d3ddev);

for(int i=0;i<grid.size();i++)
 grid[i]->showGrid(d3ddev);
    // build MULTIPLE matrices to translate the model and one to rotate
 Render_Circle();
Callback();

	 

  
}
void APIDIRECTX9::render_frame4() {


    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

    // set the view transform
    cam[3]->update( d3ddev);
    
    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
                               D3DXToRadian(45),			// the vertical field of view
                               800.0f/600.0f,			// aspect ratio
                               1.0f,						// the near view-plane
                               1000.0f);						// the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);
pp->show(d3ddev);	

for(int i=0;i<teapot.size();i++)	
 teapot[i]->showTeapot(d3ddev);
 	for(int i=0;i<sphere.size();i++)
 sphere[i]->showSphere(d3ddev);
   for(int i=0;i<cylinder.size();i++)
cylinder[i]->showCylinder(d3ddev);  
for(int i=0;i<cube.size();i++)
   cube[i]->showCube(d3ddev);
    for(int i=0;i<plane.size();i++)	
plane[i]->showPlane(d3ddev);
for(int i=0;i<grid.size();i++)
 grid[i]->showGrid(d3ddev);
 Render_Circle();

    // select the vertex buffer to display
  
   Callback();  
    // build MULTIPLE matrices to translate the model and one to rotate
   
 /*
 D3DXMATRIX matTranslateB;    // a matrix to store the translation for triangle A
 D3DXMatrixTranslation(&matTranslateB, 0.0, 0.0, 10);
  D3DMATRIX matTemp2(matTranslateB * matRotateX*matRotateY*matRotateZ*matScaleA);
  
      d3ddev->SetTransform(D3DTS_WORLD, &matTemp2);
      D3DMATERIAL9 mat2;
       ZeroMemory(&mat2,sizeof(D3DMATERIAL9));
    mat2.Diffuse.r = 0.05f;
	mat2.Diffuse.g = 100.25f;
	mat2.Diffuse.b = 12.95f;
	mat2.Diffuse.a = 0.5f;
HRESULT hr2;
	hr2= d3ddev->SetMaterial(&mat2);
 d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
 */

    
	 

  
}

void APIDIRECTX9::Render_Circle()
{
	cc->Line(250, 200, dist+1, D3DCOLOR_XRGB(200,200,200),d3ddev);
}

  
void APIDIRECTX9::setDist(float d)
{
	dist+=d;
	
	if(dist<0.1)
	 dist=0.1;
	if(dist>100)
	 dist=100;
}

void APIDIRECTX9::setTranslate(vector3d t)
{	
for(int i=0;i<cube.size();i++)
{

	if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	

		pp->setPosition(cube[i]->getPosition());
		 cube[i]->setTranslate(t);
	}
}

for(int i=0;i<teapot.size();i++)
{
        	if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        pp->setPosition(teapot[i]->getPosition());
        teapot[i]->setTranslate(t);
    }
        
    }
    
    for(int i=0;i<sphere.size();i++)
{
        	if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	
            pp->setPosition(sphere[i]->getPosition());
        sphere[i]->setTranslate(t);
    }
}
        
         for(int i=0;i<cylinder.size();i++)
{
        	if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist) 
        	{
			  pp->setPosition(cylinder[i]->getPosition());
       cylinder[i]->setTranslate(t);
   }
}
       
       	for(int i=0;i<plane.size();i++)
       	{
		   
       		if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist) 
        	{
        			  pp->setPosition(plane[i]->getPosition()+vector3d(0,4,0));
       plane[i]->setTranslate(t);
   }
}
       
      
}
void APIDIRECTX9::setRotate(vector3d r)
{
		for(int i=0;i<cube.size();i++)


	if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        cube[i]->setRotate(r);
    }
    
        
        for(int i=0;i<teapot.size();i++)
        
        	if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        teapot[i]->setRotate(r);
    }
    
         for(int i=0;i<sphere.size();i++)
         
        	if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        sphere[i]->setRotate(r);
    }
        for(int i=0;i<cylinder.size();i++)
        
        	if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        cylinder[i]->setRotate(r);
 }
        
         for(int i=0;i<plane.size();i++)
         if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        plane[i]->setRotate(r);
    }
       
}
void APIDIRECTX9::setColorInc(vector3d col)
{
		for(int i=0;i<cube.size();i++)
		   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        cube[i]->setColorInc(col);
    }
        	for(int i=0;i<teapot.size();i++)
        	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        teapot[i]->setColorInc(col);
    }
               	for(int i=0;i<sphere.size();i++)
               	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        sphere[i]->setColorInc(col);
    }
               	for(int i=0;i<cylinder.size();i++)
               	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        cylinder[i]->setColorInc(col);
    }
         	for(int i=0;i<plane.size();i++)
         	if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        plane[i]->setColorInc(col);
    }
        
        
}

void APIDIRECTX9::setScaleInc(vector3d s)
{
		for(int i=0;i<cube.size();i++)
		    	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        cube[i]->setScaleInc(s);
    }
        	for(int i=0;i<teapot.size();i++)
        	    	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        teapot[i]->setScaleInc(s);
    }
        	for(int i=0;i<sphere.size();i++)
        	    	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        sphere[i]->setScaleInc(s);
    }
        
        	for(int i=0;i<cylinder.size();i++)
        	    	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        cylinder[i]->setScaleInc(s);
    }
        for(int i=0;i<plane.size();i++)
            	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        plane[i]->setScaleInc(s);
    }
        
}

void APIDIRECTX9::setColor(vector3d col)
{
	for(int i=0;i<cube.size();i++)
	    	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cube[i]->setColor(col);
}
		for(int i=0;i<teapot.size();i++)
		    	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        teapot[i]->setColor(col);
    }
        	for(int i=0;i<sphere.size();i++)
        	    	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        sphere[i]->setColor(col);
    }
        
        for(int i=0;i<cylinder.size();i++)
            	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        cylinder[i]->setColor(col);
    }
        
        for(int i=0;i<plane.size();i++)
            	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
        plane[i]->setColor(col);
    }
}
void APIDIRECTX9::setAmbiant(vector3d amb)
{
	for(int i=0;i<cube.size();i++)
	    	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
cube[i]->setAmbiant(amb);	
}
	for(int i=0;i<teapot.size();i++)
	    	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
teapot[i]->setAmbiant(amb);
}
	for(int i=0;i<sphere.size();i++)
	    	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
sphere[i]->setAmbiant(amb);
}

	for(int i=0;i<cylinder.size();i++)
	    	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
cylinder[i]->setAmbiant(amb);
}

	for(int i=0;i<plane.size();i++)
	    	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
plane[i]->setAmbiant(amb);
}

}
void APIDIRECTX9::setSpecular(vector3d spec)
{
	for(int i=0;i<cube.size();i++)
	    	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cube[i]->setSpecular(spec);
}
	for(int i=0;i<teapot.size();i++)
	    	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	teapot[i]->setSpecular(spec);
}
	
	for(int i=0;i<sphere.size();i++)
	    	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	sphere[i]->setSpecular(spec);
}
	
		for(int i=0;i<cylinder.size();i++)
		    	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cylinder[i]->setSpecular(spec);
}
	
		for(int i=0;i<plane.size();i++)
		    	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
plane[i]->setSpecular(spec);
}
}
void APIDIRECTX9::setEmissive(vector3d emiss)
{
	for(int i=0;i<cube.size();i++)
	    	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cube[i]->setEmissive(emiss);
}
	for(int i=0;i<teapot.size();i++)
	    	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	teapot[i]->setEmissive(emiss);
}
		for(int i=0;i<sphere.size();i++)
		    	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	sphere[i]->setEmissive(emiss);
}
		for(int i=0;i<cylinder.size();i++)
		    	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cylinder[i]->setEmissive(emiss);
}
	
		for(int i=0;i<plane.size();i++)
		    	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	plane[i]->setEmissive(emiss);
}
}
void APIDIRECTX9::setPower(float pow)
{
	for(int i=0;i<cube.size();i++)
	    	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cube[i]->setPower(pow);
}
		for(int i=0;i<teapot.size();i++)
		    	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	teapot[i]->setPower(pow);
}
		for(int i=0;i<sphere.size();i++)
		    	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	sphere[i]->setPower(pow);
}
	
	for(int i=0;i<cylinder.size();i++)
	    	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cylinder[i]->setPower(pow);
}
	
		for(int i=0;i<plane.size();i++)
		    	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	plane[i]->setPower(pow);
}
}
void APIDIRECTX9::setAlpha(float alph)
{
	for(int i=0;i<cube.size();i++)
	    	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cube[i]->setAlpha(alph);
}
		for(int i=0;i<teapot.size();i++)
		    	   if(distance(teapot[i]->getPosition().x,pp->getPosition().x,teapot[i]->getPosition().y,pp->getPosition().y,teapot[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	teapot[i]->setAlpha(alph);
}
	for(int i=0;i<sphere.size();i++)
	    	   if(distance(sphere[i]->getPosition().x,pp->getPosition().x,sphere[i]->getPosition().y,pp->getPosition().y,sphere[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	sphere[i]->setAlpha(alph);
}
	for(int i=0;i<cylinder.size();i++)
    	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	cylinder[i]->setAlpha(alph);
}
	for(int i=0;i<plane.size();i++)
	    	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	plane[i]->setAlpha(alph);
}
}
void APIDIRECTX9::setPosition(vector3d pos)
{
	for(int i=0;i<cube.size();i++)
	cube[i]->setPosition(pos);
	
		for(int i=0;i<teapot.size();i++)
	teapot[i]->setPosition(pos);
		for(int i=0;i<sphere.size();i++)
	sphere[i]->setPosition(pos);
	
	for(int i=0;i<cylinder.size();i++)
	cylinder[i]->setPosition(pos);
	
	for(int i=0;i<plane.size();i++)
	plane[i]->setPosition(pos);
}
vector3d APIDIRECTX9::getPosition()
{
	for(int i=0;i<cube.size();i++)
	return cube[i]->getPosition();
	
	for(int i=0;i<teapot.size();i++)
	return teapot[i]->getPosition();
	for(int i=0;i<sphere.size();i++)
	return sphere[i]->getPosition();
		for(int i=0;i<cylinder.size();i++)
	return cylinder[i]->getPosition();
	
		for(int i=0;i<plane.size();i++)
	return plane[i]->getPosition();
}
void APIDIRECTX9::setRotation(vector3d rot)
{
	for(int i=0;i<cube.size();i++)
	cube[i]->setRotation(rot);
	
		for(int i=0;i<teapot.size();i++)
	teapot[i]->setRotation(rot);
	
		for(int i=0;i<sphere.size();i++)
	sphere[i]->setRotation(rot);
	
		for(int i=0;i<cylinder.size();i++)
	cylinder[i]->setRotation(rot);
	
	for(int i=0;i<plane.size();i++)
	plane[i]->setRotation(rot);
}
vector3d APIDIRECTX9::getRotation()
{
	for(int i=0;i<cube.size();i++)
	return cube[i]->getRotation();
	
	for(int i=0;i<teapot.size();i++)
	return teapot[i]->getRotation();
	
	for(int i=0;i<sphere.size();i++)
	return sphere[i]->getRotation();
	
	for(int i=0;i<cylinder.size();i++)
	return cylinder[i]->getRotation();
	
		for(int i=0;i<plane.size();i++)
	return plane[i]->getRotation();
}
void APIDIRECTX9::setScale(vector3d s)
{
	for(int i=0;i<cube.size();i++)
	cube[i]->setScale(s);
	
		for(int i=0;i<teapot.size();i++)
	teapot[i]->setScale(s);
	
		for(int i=0;i<sphere.size();i++)
	sphere[i]->setScale(s);
	
		for(int i=0;i<cylinder.size();i++)
	cylinder[i]->setScale(s);
		for(int i=0;i<plane.size();i++)
	plane[i]->setScale(s);
}
vector3d APIDIRECTX9::getScale()
{
	for(int i=0;i<cube.size();i++)
	return cube[i]->getScale();
	
		for(int i=0;i<teapot.size();i++)
	return teapot[i]->getScale();
	
	
		for(int i=0;i<sphere.size();i++)
	return sphere[i]->getScale();
	
		for(int i=0;i<cylinder.size();i++)
	return cylinder[i]->getScale();
	
	
		for(int i=0;i<plane.size();i++)
	return plane[i]->getScale();
	
}

	bool APIDIRECTX9::getPhysicsMode()
	{
		return physicsMode;
	}
	bool APIDIRECTX9::getStart()
	{
		return startGame;
	}
	bool APIDIRECTX9::getQuit()
	{
		return quitGame;
	}
	bool APIDIRECTX9::getCharacterMode()
	{
		return characterMode;
	}
	bool APIDIRECTX9::getDriveMode()
	{
		return driveMode;
	}
	bool APIDIRECTX9::getDynamicMode()
	{
		return dynamicsMode;
	}
	bool APIDIRECTX9::getStaticMode()
	{
		return staticMode;
	}
	
	void APIDIRECTX9::setPhysicsMode(bool b)
	{
		 physicsMode=b;
	}
	void APIDIRECTX9::setStart(bool b)
	{
	startGame=b;
	}
	void APIDIRECTX9::setQuit(bool b)
	{
	 quitGame=b;
	}
	void APIDIRECTX9::setCharacterMode(bool b)
	{
	 characterMode=b;
	}
	void APIDIRECTX9::setDriveMode(bool b)
	{
		 driveMode=b;
	}
	void APIDIRECTX9::setDynamicMode(bool b)
	{
		for(int i=0;i<cylinder.size();i++)
	 	   if(distance(cylinder[i]->getPosition().x,pp->getPosition().x,cylinder[i]->getPosition().y,pp->getPosition().y,cylinder[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	
	
	
		 cylinder[i]->setDynamic(b);
	
}

	for(int i=0;i<plane.size();i++)
	 	   if(distance(plane[i]->getPosition().x,pp->getPosition().x,plane[i]->getPosition().y,pp->getPosition().y,plane[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	
	
	
		 plane[i]->setDynamic(b);
	
}

			for(int i=0;i<cube.size();i++)
	 	   if(distance(cube[i]->getPosition().x,pp->getPosition().x,cube[i]->getPosition().y,pp->getPosition().y,cube[i]->getPosition().z,pp->getPosition().z
	)<dist)
	{
	
	
	
		 cube[i]->setDynamic(b);
	
}

	}
	void APIDIRECTX9::setStaticMode(bool b)
	{
		 staticMode=b;
	}
	float APIDIRECTX9::getDist()
	{
		return dist;
	}




