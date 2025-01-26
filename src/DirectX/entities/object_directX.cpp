#include"object_directX.h"

objectX::objectX(vector3d t, vector3d r, vector3d s,vector3d c)
{	
	b=new boundingbox();
	dynamic=false;
	translate=t;
	rotate=r;
	scale=s;
	color=c;
	specular=vector3d(0.5f,0.5f,0.5f);
	ambiant=vector3d(0.5f,0.5f,0.5f);
	emissive=vector3d(0.0f,0.0f,0.0f);
	alpha=0.5f;
	power=50.0f;
	
}
objectX::~objectX()
{
meshTeapot->Release();
meshSphere->Release();
meshCylinder->Release();
}

void objectX::init_Teapot(LPDIRECT3DDEVICE9 d3ddev)
{
    // deleted all the cube code from here
    D3DXCreateTeapot(d3ddev, &meshTeapot, NULL);    // create the teapot
}

void objectX::init_Sphere(LPDIRECT3DDEVICE9 d3ddev)
{
    // deleted all the cube code from here
	D3DXCreateSphere(d3ddev, 2.0f, 40, 20, &meshSphere, NULL);
}
void objectX::init_Cylinder(LPDIRECT3DDEVICE9 d3ddev)
{
    // deleted all the cube code from here
	D3DXCreateCylinder(d3ddev, 1.5f, 1.5f, 7.0f, 20, 10, &meshCylinder, NULL);	
}

void objectX::init_Cube(LPDIRECT3DDEVICE9 d3ddev)
{

 CUSTOMVERTEX vertices[] =
    {
    	
    {-3.0f, -3.0f, 3.0f, 0.0f, 0.0f, 1.0f,}, // côté 1 
        {3.0f, -3.0f, 3.0f, 0.0f, 0.0f, 1.0f,}, 
        {-3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 1.0f,}, 
        {3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 1.0f,}, 

        {-3.0f, -3.0f, -3.0f, 0.0f, 0.0f, -1.0f,}, // côté 2 
        {-3.0f, 3.0f, -3.0f, 0.0f, 0.0f, -1.0f,}, 
        {3.0f, -3.0f, -3.0f, 0.0f, 0.0f, -1.0f,}, 
        {3.0f, 3.0f, -3.0f, 0.0f, 0.0f, -1.0f,}, 

        {-3.0f, 3.0f , -3.0f, 0.0f, 1.0f, 0.0f,}, // face 3 
        {-3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f,}, 
        {3.0f, 3.0f, - 3.0f, 0.0f, 1.0f, 0.0f,}, 
        {3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f,},

        {-3.0f, -3.0f, -3.0f, 0.0f, -1.0f, 0.0f,}, // côté 4 
        {3.0f, -3.0f, -3.0f, 0.0f, -1.0f, 0.0f ,}, 
        {-3.0f, -3.0f, 3.0f, 0.0f, -1.0f, 0.0f,}, 
        {3.0f, -3.0f, 3.0f, 0.0f, -1.0f, 0.0f,}, 

        {3.0f, -3.0f, -3.0f, 1.0f, 0.0f, 0.0f,}, // côté 5 
        {3.0f, 3.0f, -3.0f, 1.0f, 0.0f, 0.0f,}, 
        { 3.0f, -3.0f, 3.0f, 1.0f, 0.0f, 0.0f,}, 
        {3.0f, 3.0f, 3.0f, 1.0f, 0.0f, 0.0f,}, 

        {-3.0f, -3.0f , -3.0f, -1.0f, 0.0f, 0.0f,}, // côté 6 
        {-3.0f, -3.0f, 3.0f, -1.0f, 0.0f, 0.0f,}, 
        {-3.0f, 3.0f, -3.0f, -1.0f, 0.0f, 0.0f,}, 
        {-3.0f, 3.0f, 3.0f, -1.0f, 0.0f, 0.0f,},
        
       
                
    };

    // create a vertex buffer interface called v_buffer
    d3ddev->CreateVertexBuffer(24  * sizeof(CUSTOMVERTEX), 0, CUSTOMFVF, D3DPOOL_MANAGED, &vertexbuffer, NULL);

    VOID* pVoid;

    // lock v_buffer and load the vertices into it
    vertexbuffer->Lock(0, 0, (void**)&pVoid, 0);
    memcpy(pVoid, vertices, sizeof(vertices));
    vertexbuffer->Unlock();
      courts indices [] = 
    { 
        0, 1, 2, // côté 1 
        2, 1, 3,
        4, 5, 6, // côté 2 
        6, 5, 7, 
        8, 9, 10, // côté 3 
        10, 9, 11, 
        12, 13, 14, // côté 4 
        14, 13, 15, 
        16, 17, 18, // face 5 
        18, 17, 19, 
        20, 21, 22, // face 6 
        22, 21, 23,
    }; 

    // crée une interface de tampon d'index appelée i_buffer 
    d3ddev-> CreateIndexBuffer (36 * sizeof (short), 
                              0, 
                              D3DFMT_INDEX16, 
                              D3DPOOL_MANAGED, 
                              & i_buffer, 
                              NULL); 

    // verrouille i_buffer et charge les index dedans
    i_buffer-> Lock (0, 0, (void **) & pVoid, 0); 
    memcpy (pVoid, indices, sizeof (indices)); 
    i_buffer-> Unlock (); 

}

void objectX::init_Plane(LPDIRECT3DDEVICE9 d3ddev)
{

 CUSTOMVERTEX vertices[] =
    {
    	
   {-3.0f, 3.0f , -3.0f, 0.0f, 1.0f, 0.0f,}, // face 3 
        {-3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f,}, 
        {3.0f, 3.0f, - 3.0f, 0.0f, 1.0f, 0.0f,}, 
        {3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f,},
    };

    // create a vertex buffer interface called v_buffer
    d3ddev->CreateVertexBuffer(24  * sizeof(CUSTOMVERTEX), 0, CUSTOMFVF, D3DPOOL_MANAGED, &vertexbuffer, NULL);

    VOID* pVoid;

    // lock v_buffer and load the vertices into it
    vertexbuffer->Lock(0, 0, (void**)&pVoid, 0);
    memcpy(pVoid, vertices, sizeof(vertices));
    vertexbuffer->Unlock();
      courts indices [] = 
    { 
        0, 1, 2, // côté 1 
        2, 1, 3,
        4, 5, 6, // côté 2 
        6, 5, 7, 
        8, 9, 10, // côté 3 
        10, 9, 11, 
        12, 13, 14, // côté 4 
        14, 13, 15, 
        16, 17, 18, // face 5 
        18, 17, 19, 
        20, 21, 22, // face 6 
        22, 21, 23,
    }; 

    // crée une interface de tampon d'index appelée i_buffer 
    d3ddev-> CreateIndexBuffer (36 * sizeof (short), 
                              0, 
                              D3DFMT_INDEX16, 
                              D3DPOOL_MANAGED, 
                              & i_buffer, 
                              NULL); 

    // verrouille i_buffer et charge les index dedans
    i_buffer-> Lock (0, 0, (void **) & pVoid, 0); 
    memcpy (pVoid, indices, sizeof (indices)); 
    i_buffer-> Unlock (); 

}


void objectX::showTeapot(LPDIRECT3DDEVICE9 d3ddev)
{
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	// Set the RGBA for emissive color.
	mat.Emissive.r = emissive.x;
	mat.Emissive.g = emissive.y;
	mat.Emissive.b = emissive.z;
	mat.Emissive.a = alpha;

	D3DXMatrixTranslation(&matTranslateB, translate.x,translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateXB, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateYB, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZB, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleB,scale.x,scale.y,scale.z);
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateXB*matRotateYB*matRotateZB*matScaleB*matTranslateB );
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
  
    // tell Direct3D about each world transform, and then draw another triangle
   
 
    
	meshTeapot->DrawSubset(0);  

}

void objectX::showSphere(LPDIRECT3DDEVICE9 d3ddev)
{
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	// Set the RGBA for emissive color.
	mat.Emissive.r = emissive.x;
	mat.Emissive.g = emissive.y;
	mat.Emissive.b = emissive.z;
	mat.Emissive.a = alpha;

	D3DXMatrixTranslation(&matTranslateB, translate.x,translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateXB, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateYB, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZB, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleB,scale.x,scale.y,scale.z);
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateXB*matRotateYB*matRotateZB*matScaleB*matTranslateB );
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
  
    // tell Direct3D about each world transform, and then draw another triangle
   
 
    
	meshSphere->DrawSubset(0);  

}


void objectX::showCylinder(LPDIRECT3DDEVICE9 d3ddev)
{
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	// Set the RGBA for emissive color.
	mat.Emissive.r = emissive.x;
	mat.Emissive.g = emissive.y;
	mat.Emissive.b = emissive.z;
	mat.Emissive.a = alpha;

	D3DXMatrixTranslation(&matTranslateB, translate.x,translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateXB, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateYB, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZB, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleB,scale.x,scale.y,scale.z);
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateXB*matRotateYB*matRotateZB*matScaleB*matTranslateB );
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
  
    // tell Direct3D about each world transform, and then draw another triangle
   
 
    
	meshCylinder->DrawSubset(0);  

}



void objectX::showCube(LPDIRECT3DDEVICE9 d3ddev)
{
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = 8.495;
	mat.Diffuse.g = .5;
	mat.Diffuse.b = .5;


	// Set the RGBA for ambient reflection.

	
	
	D3DXMatrixTranslation(&matTranslateA, translate.x, translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateX, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateY, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZ, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleA,scale.x,scale.y,scale.z);
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateX*matRotateY*matRotateZ*matScaleA*matTranslateA );
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

 	d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
}





void objectX::showPlane(LPDIRECT3DDEVICE9 d3ddev)
{
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	// Set the RGBA for emissive color.
	mat.Emissive.r = emissive.x;
	mat.Emissive.g = emissive.y;
	mat.Emissive.b = emissive.z;
	mat.Emissive.a = alpha;
	
	
	D3DXMatrixTranslation(&matTranslateA, translate.x, translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateX, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateY, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZ, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleA,scale.x,scale.y,scale.z);
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateX*matRotateY*matRotateZ*matScaleA*matTranslateA );
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

 	d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
}

void objectX::showGrid(LPDIRECT3DDEVICE9 d3ddev)
{
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_WIREFRAME);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	// Set the RGBA for emissive color.
	mat.Emissive.r = emissive.x;
	mat.Emissive.g = emissive.y;
	mat.Emissive.b = emissive.z;
	mat.Emissive.a = alpha;
	
	
	D3DXMatrixTranslation(&matTranslateA, translate.x, translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateX, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateY, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZ, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleA,scale.x,scale.y,scale.z);
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateX*matRotateY*matRotateZ*matScaleA*matTranslateA );
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);

 	d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
}

void objectX::Line(int X, int Y, int radius, DWORD Color,LPDIRECT3DDEVICE9 d3ddev)
{
	
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_WIREFRAME);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	D3DXMatrixTranslation(&matTranslateA, translate.x, translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateX, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateY, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZ, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleA,scale.x,scale.y,scale.z);
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateX*matRotateY*matRotateZ*matScaleA*matTranslateA );
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);


	DrawLineHoriz(d3ddev,X,Y,radius,Color);
	DrawLineVert(d3ddev,X,Y,radius,Color);

}

void objectX::DrawLineHoriz(LPDIRECT3DDEVICE9 Device_Interface,int bx,int by,int bw,D3DCOLOR COLOR)
  {
  	Device_Interface->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	Device_Interface-> SetIndices (i_buffer);
	Device_Interface->SetRenderState(D3DRS_FILLMODE,D3DFILL_WIREFRAME);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	D3DXMatrixTranslation(&matTranslateA, translate.x, translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateX, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateY, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZ, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleA,scale.x,scale.y,scale.z);
    
    HRESULT hr;
	hr = Device_Interface->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateX*matRotateY*matRotateZ*matScaleA*matTranslateA );
    Device_Interface->SetTransform(D3DTS_WORLD, &matTemp);
    
    
    D3DRECT rec;
    rec.x1 = bx-bw;//makes line longer/shorter going lef
    rec.y1 = by;
    rec.x2 = bx+bw;//makes line longer/shorter going right
    rec.y2 = by+1;//makes line one pixel tall
    
    Device_Interface->Clear(1,&rec,D3DCLEAR_TARGET,COLOR,0,0);
 
  }
  
  
  void objectX::DrawLineVert(LPDIRECT3DDEVICE9 Device_Interface,int bx,int by,int bw,D3DCOLOR COLOR)
  {
  	Device_Interface->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	Device_Interface-> SetIndices (i_buffer);
	Device_Interface->SetRenderState(D3DRS_FILLMODE,D3DFILL_WIREFRAME);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;

	// Set the RGBA for ambient reflection.
	mat.Ambient.r = ambiant.x;
	mat.Ambient.g = ambiant.y;
	mat.Ambient.b = ambiant.z;
	mat.Ambient.a = alpha;
	
	// Set the color and sharpness of specular highlights.
	mat.Specular.r = specular.x;
	mat.Specular.g = specular.y;
	mat.Specular.b = specular.z;
	mat.Specular.a = alpha;
	mat.Power = power;
	
	D3DXMatrixTranslation(&matTranslateA, translate.x, translate.y, translate.z);
    D3DXMatrixRotationX(&matRotateX, rotate.x);    // the front side
    D3DXMatrixRotationY(&matRotateY, rotate.y);    // the front side
    D3DXMatrixRotationZ(&matRotateZ, rotate.z);    // the front side
    D3DXMatrixScaling(&matScaleA,scale.x,scale.y,scale.z);
    
    HRESULT hr;
	hr = Device_Interface->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp( matRotateX*matRotateY*matRotateZ*matScaleA*matTranslateA );
    Device_Interface->SetTransform(D3DTS_WORLD, &matTemp);
    
    
    D3DRECT rec;
    rec.y1 = by-bw;//makes line longer/shorter going lef
    rec.x1 = bx;
    rec.y2 = by+bw;//makes line longer/shorter going right
    rec.x2 = bx+1;//makes line one pixel tall
    
    Device_Interface->Clear(1,&rec,D3DCLEAR_TARGET,COLOR,0,0);
 
  }


void objectX::setTranslate(vector3d t)
{
	translate+=t;
}
void objectX::setRotate(vector3d r)
{
	rotate+=r;
}
void objectX::setScaleInc(vector3d s)
{
	scale+=s;
}
void objectX::setColor(vector3d col)
{
	color=col;
}
void objectX::setColorInc(vector3d col)
{
	color+=col;
}
void objectX::setAmbiant(vector3d amb)
{
ambiant+=amb;	
}
void objectX::setSpecular(vector3d spec)
{
	specular+=spec;
}
void objectX::setEmissive(vector3d emiss)
{
	emissive+=emiss;
}
void objectX::setPower(float pow)
{
	power+=pow;
}
void objectX::setAlpha(float alph)
{
	alpha+=alph;
}
void objectX::setPosition(vector3d pos)
{
	translate=pos;
}
vector3d objectX::getPosition()
{
	return translate;
}
void objectX::setRotation(vector3d rot)
{
	rotate=rot;
}
vector3d objectX::getRotation()
{
	return rotate;
}
void objectX::setScale(vector3d s)
{
	scale=s;
}
vector3d objectX::getScale()
{
	return scale;
}


void objectX::update()
{   

 
 
    
	p1=vector3d(b->getMax().x+translate.x,b->getMin().y+translate.y,b->getMin().z+translate.z);
	p2=vector3d(b->getMax().x+translate.x,b->getMin().y+translate.y,b->getMax().z+translate.z);
	p3=vector3d(b->getMax().x+translate.x,b->getMax().y+translate.y,b->getMax().z+translate.z);
	p4=vector3d(b->getMax().x+translate.x,b->getMax().y+translate.y,b->getMin().z+translate.z);
	
	p5=vector3d(b->getMin().x+translate.x,b->getMax().y+translate.y,b->getMin().z+translate.z);
	p6=vector3d(b->getMin().x+translate.x,b->getMax().y+translate.y,b->getMax().z+translate.z);
	p7=vector3d(b->getMin().x+translate.x,b->getMin().y+translate.y,b->getMax().z+translate.z);
	p8=vector3d(b->getMin().x+translate.x,b->getMin().y+translate.y,b->getMin().z+translate.z);
	
	p9=vector3d(b->getMax().x+translate.x,b->getMin().y+translate.y,b->getMax().z+translate.z);
	p10=vector3d(b->getMax().x+translate.x,b->getMax().y+translate.y,b->getMax().z+translate.z);
	p11=vector3d(b->getMin().x+translate.x,b->getMax().y+translate.y,b->getMax().z+translate.z);
	p12=vector3d(b->getMin().x+translate.x,b->getMin().y+translate.y,b->getMax().z+translate.z);
	
	p13=vector3d(b->getMax().x+translate.x,b->getMax().y+translate.y,b->getMin().z+translate.z);
	p14=vector3d(b->getMax().x+translate.x,b->getMin().y+translate.y,b->getMin().z+translate.z);
	p15=vector3d(b->getMin().x+translate.x,b->getMin().y+translate.y,b->getMin().z+translate.z);
	p16=vector3d(b->getMin().x+translate.x,b->getMax().y+translate.y,b->getMin().z+translate.z);
	
	p17=vector3d(b->getMax().x+translate.x,b->getMax().y+translate.y,b->getMin().z+translate.z);
	p18=vector3d(b->getMax().x+translate.x,b->getMax().y+translate.y,b->getMax().z+translate.z);
	p19=vector3d(b->getMin().x+translate.x,b->getMax().y+translate.y,b->getMax().z+translate.z);
	p20=vector3d(b->getMin().x+translate.x,b->getMax().y+translate.y,b->getMin().z+translate.z);
	
	p21=vector3d(b->getMin().x+translate.x,b->getMin().y+translate.y,b->getMin().z+translate.z);
	p22=vector3d(b->getMin().x+translate.x,b->getMin().y+translate.y,b->getMax().z+translate.z);
	p23=vector3d(b->getMax().x+translate.x,b->getMin().y+translate.y,b->getMax().z+translate.z);
	p24=vector3d(b->getMax().x+translate.x,b->getMin().y+translate.y,b->getMin().z+translate.z);
	
	b->setMin(vector3d(-scale.x*0.5,-scale.y*0.5,-scale.z*0.5));
	b->setMax(vector3d(scale.x*0.5,scale.y*0.5,scale.z*0.5));



}


void objectX::movement(bool up,bool down, bool right, bool left)
{
	
				
			/*
			      vector3d newPos(loc);
			      	newPos.y-=0.2f;
		
			
			  setLocation(newPos);
			  if(newPos.y<0)
			loc.y=0;
			*/
		
			if(up==1 && speed<maxSpeed)
			{
			
				if(speed<0)
				{
					speed+=dec;
				}
				else
				{
					speed+=acc;
				}
			}
			if(down==1 && speed>-maxSpeed)
			{
				
				if(speed>0)
				{
					speed-=dec;
				}
				else
				{
					speed-=acc;
				}
				
			}
			
			if(up==0 && down==0)
			{
				if(speed-dec>0)
				{
					speed-=dec;
				}
				else if(speed+dec<0)
				{
					speed+=dec;
				}
				else
				{
					speed=0;
				}
			}
			if(right && speed!=0)
			{
				rotate.y-=turnSpeed*speed/maxSpeed;
			}
				if(left && speed!=0)
			{
				rotate.y+=turnSpeed*speed/maxSpeed;
			}
			
			
		
			setLocationIncrement();
			
	
}
void objectX:: movementCharacter(bool up,bool down, bool right, bool left)
{
if(up)
{
	translate.x+=cos(rotate.y*M_PI/180.0)*speed2;
	translate.z-=sin(rotate.y*M_PI/180.0)*speed2;
	}	
	if(down)
	{
		translate.x-=cos(rotate.y*M_PI/180.0)*speed2;
	translate.z+=sin(rotate.y*M_PI/180.0)*speed2;
	}
	if(right)
	{
		rotate.y-=1.5f;
	}
	if(left)
	{
		rotate.y+=1.5f;
	}
}
void objectX::physics()
{
		vector3d newPos(translate);
			      	newPos.y-=0.2f;
			       setLocation(newPos);	
}

void objectX::setDynamic(bool b)
{
	   
		 dynamic=b;
	

}
bool objectX::getDynamic()
{
	return dynamic;
}


vector3d objectX::getP1()
{
	return p1;
}
vector3d objectX::getP2()
{
	return p2;
}
vector3d objectX::getP3()
{
	return p3;
}
vector3d objectX::getP4()
{
	return p4;
}
vector3d objectX::getP5()
{
	return p5;
}
vector3d objectX::getP6()
{
	return p6;
}
vector3d objectX::getP7()
{
	return p7;
}
vector3d objectX::getP8()
{
	return p8;
}
vector3d objectX::getP9()
{
	return p9;
}
vector3d objectX::getP10()
{
	return p10;
}
vector3d objectX::getP11()
{
	return p11;
}
vector3d objectX::getP12()
{
	return p12;
}
vector3d objectX::getP13()
{
	return p13;
}
vector3d objectX::getP14()
{
	return p14;
}
vector3d objectX::getP15()
{
	return p15;
}
vector3d objectX::getP16()
{
	return p16;
}
vector3d objectX::getP17()
{
	return p17;
}
vector3d objectX::getP18()
{
	return p18;
}
vector3d objectX::getP19()
{
	return p19;
}
vector3d objectX::getP20()
{
	return p20;
}
vector3d objectX::getP21()
{
	return p21;
}
vector3d objectX::getP22()
{
	return p22;
}
vector3d objectX::getP23()
{
	return p23;
}
vector3d objectX::getP24()
{
	return p24;
}

void objectX::setLocation(vector3d l)
{
	translate=l;
}
void objectX::setLocationIncrement()
{
	translate.x-=cos(rotate.y*M_PI/180.0)*speed;
	translate.z+=sin(rotate.y*M_PI/180.0)*speed;
}
vector3d objectX::getLocation()
{
	return translate;
}


bool objectX::getDrive()
{
	return drive;
}
void objectX::setDrive(bool b)
 {
 	drive=b;
 }
 bool objectX::getWalk()
{
	return walk;
}
void objectX::setWalk(bool b)
 {
 	walk=b;
 }
