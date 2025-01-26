#include"pointerX.h"

pointerX::pointerX()
{
	


	
	translate=vector3d(1,0,0.0);
	translate2=vector3d(0,1,0);
	translate3=vector3d(0,0,1);
	translate4=vector3d(0,0,0);
	rotate=vector3d(0,0,0);
	rotate2=vector3d(0,0,0);
	rotate3=vector3d(0,0,0);
	scale=vector3d(0.1,0.1,1);
	scale2=vector3d(0.1,1,0.1);
	scale3=vector3d(1,0.1,0.1);
	scale4=vector3d(1,1,1);
	color=vector3d(0.8f,0.05f,0.05f);
	color2=vector3d(0.01f,0.01f,0.9f);
	color3=vector3d(0.01f,0.9f,0.01f);
	
}
pointerX::~pointerX()
{

}
void pointerX::init_graphics(LPDIRECT3DDEVICE9 d3ddev)
{

 CUSTOMVERTEX vertices[] =
    {
    	
    {-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,}, // côté 1 
        {1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,}, 
        {-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,}, 
        {1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,}, 

        {-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f,}, // côté 2 
        {-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f,}, 
        {1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f,}, 
        {1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f,}, 

        {-1.0f, 1.0f , -1.0f, 0.0f, 1.0f, 0.0f,}, // face 3 
        {-1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,}, 
        {1.0f, 1.0f, - 1.0f, 0.0f, 1.0f, 0.0f,}, 
        {1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,},

        {-1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f,}, // côté 4 
        {1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f ,}, 
        {-1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f,}, 
        {1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f,}, 

        {1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,}, // côté 5 
        {1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f,}, 
        { 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f,}, 
        {1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,}, 

        {-1.0f, -1.0f , -1.0f, -1.0f, 0.0f, 0.0f,}, // côté 6 
        {-1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 0.0f,}, 
        {-1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f,}, 
        {-1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,},
        
       
                
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
void pointerX::show(LPDIRECT3DDEVICE9 d3ddev)
{
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer);
	d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
	
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = color.x;
	mat.Diffuse.g = color.y;
	mat.Diffuse.b = color.z;
	mat.Diffuse.a = alpha;
	mat2.Diffuse.r = color2.x;
	mat2.Diffuse.g = color2.y;
	mat2.Diffuse.b = color2.z;
	mat2.Diffuse.a = alpha2;
	mat3.Diffuse.r = color3.x;
	mat3.Diffuse.g = color3.y;
	mat3.Diffuse.b = color3.z;
	mat3.Diffuse.a = alpha3;

    

	
	D3DXMatrixTranslation(&matTranslateD, translate4.x, translate4.y, translate4.z);
	
	D3DXMatrixTranslation(&matTranslateA, translate.x, translate.y, translate.z);
 
    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp(matTranslateD*matTranslateA );
   
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

 	d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
 	
 
    
 	
 	
	D3DXMatrixTranslation(&matTranslateB, translate2.x, translate2.y, translate2.z);
 
 	HRESULT hr2;
	hr2 = d3ddev->SetMaterial(&mat2);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp2(matTranslateD*matTranslateB);
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp2);
    

 	d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
 	
 	
 	
 	D3DXMatrixTranslation(&matTranslateC, translate3.x, translate3.y, translate3.z);
      // the front side

 	HRESULT hr3;
	hr3 = d3ddev->SetMaterial(&mat3);
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp3(matTranslateD*matTranslateC);
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp3);
    

 	d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
 

}


void pointerX::setTranslate(vector3d t)
{
	translate4+=t;
}
void pointerX::setLocation(vector3d t)
{
	translate4=t;
}
void pointerX::setColor(vector3d col)
{
	color=col;
}

void pointerX::setPosition(vector3d pos)
{
	translate4=pos;
}
vector3d pointerX::getPosition()
{
	return translate4;
}
void pointerX::setRotation(vector3d rot)
{
	rotate=rot;
}
vector3d pointerX::getRotation()
{
	return rotate;
}
void pointerX::setScale(vector3d s)
{
	scale=s;
}
vector3d pointerX::getScale()
{
	return scale;
}

