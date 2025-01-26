#include"cameraX.h"

cameraX::cameraX()
{
	yaw=0.0f;
	pitch=0.0f;
	roll=0.0f;
	movevel=0.5f;
	camerapos=D3DXVECTOR3(0,20,10);
	up=D3DXVECTOR3(0,1,0);
}
cameraX::~cameraX()
{
	
}
void cameraX::setRotation(float yaw_,float pitch_,float roll_)
{
	yaw=yaw_;
	pitch=pitch_;
	roll=roll_;
}
void cameraX::update(LPDIRECT3DDEVICE9 d3ddev)
{

D3DXMATRIX matView,
           matLook;

D3DXMatrixRotationYawPitchRoll(&matLook,yaw,pitch,roll);

D3DXVECTOR3 lookdir;
// yaw,pitch,roll are assumed to be absolute, for deltas you must save the lookdir
lookdir = D3DXVECTOR3(0.0,0.0,1.0);
D3DXVec3TransformCoord(&lookdir,&lookdir,&matLook);

D3DXVECTOR3 at;
at = camerapos + lookdir;

D3DXMatrixLookAtLH(&matView,&camerapos,&at,&up);

d3ddev->SetTransform(D3DTS_VIEW, &matView);




}
void cameraX::lockCamera()
{
	if(pitch>1.0)
		pitch=1.0;
	if(pitch<-1.0)
		pitch=-1.0;
	
}
void cameraX::moveCamera(float speed)
{

	
	
	camerapos.x+=sin(yaw)*movevel*speed;
    camerapos.z+=cos(yaw)*movevel*speed;
}
void cameraX::moveCameraback()
{

	
	
	camerapos.x-=sin(yaw)*movevel;
    camerapos.z-=cos(yaw)*movevel;
}
void cameraX::moveCameraLateral()
{
	camerapos.x+=cos(yaw)*-movevel;
    camerapos.z-=sin(yaw)*-movevel;


}
void cameraX::moveCameraLateralInverse()
{

	camerapos.x+=cos(yaw)*movevel;
    camerapos.z-=sin(yaw)*movevel;

}
void cameraX::moveCameraUp(float my)
{

	camerapos.y-=my;
}
void cameraX::moveCameraLeft(float my)
{

	camerapos.x+=cos(yaw)*-my;
    camerapos.z-=sin(yaw)*-my;
  
  
}
void cameraX::controlCamera()
{


                    
  
			            
 if(KEY_DOWN(0x57))
 {
moveCamera(0.5f);
 
}
if(KEY_DOWN(0x53))
 {
 
 moveCameraback();
}
if(KEY_DOWN(0x41))
 {
 
 moveCameraLateral();
}
if(KEY_DOWN(0x44))
 {
 
 moveCameraLateralInverse();
}
lockCamera();



}

void cameraX::setYaw(float y)
{
	yaw-=y;
}
void cameraX::setPitch(float p)
{
	pitch-=p;
}
