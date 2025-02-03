#include"datas.hpp"

datas::datas()
{
	sky=new generateSkybox();
}

datas::datas(generateSkybox* sky_)
{
		sky=sky_;
}


datas::~datas()
{
	delete sky;
}

std::vector<object*> datas::ReadequalObj()
{
	return obj;
}

std::vector<object*> datas::ReadequalObj2()
{
	return obj2;
}

std::vector<object*> datas::ReadequalObj3()
{
	return obj3;
}


std::vector<object*> datas::ReadequalObj4()
{
	return obj4;
}

std::vector<object*> datas::ReadequalObj5()
{
	return obj5;
}

std::vector<Pobject*> datas::ReadequalPobj()
{
	return Pobj;
}

std::vector<Pobject*> datas::ReadequalPobj2()
{
	return Pobj2;
}

std::vector<Pobject*> datas::ReadequalPobj3()
{
	return Pobj3;
}

std::vector<Pobject*> datas::ReadequalPobj4()
{
	return Pobj4;
}

std::vector<Pobject*> datas::ReadequalPobj5()
{
	return Pobj5;
}

std::vector<Pobject*> datas::ReadequalPobj6()
{
	return Pobj6;
}

std::vector<Pobject*> datas::ReadequalPobj7()
{
	return Pobj7;
}

std::vector<Pobject*> datas::ReadequalPobj8()
{
	return Pobj8;
}

std::vector<Pobject*> datas::ReadequalPobj9()
{
	return Pobj9;
}

std::vector<Pobject*> datas::ReadequalPobj10()
{
	return Pobj8;
}

std::vector<prefab*> datas::ReadequalPref()
{
	return pref;
}

std::vector<prefabAnim*> datas::ReadequalPrefAnim()
{
	return prefAnim;
}


std::vector<camera*> datas::ReadequalCam()
{
	return cam;
}

camera* datas::ReadequalCam2()
{
	return cam[1];
}

camera* datas::ReadequalCam3()
{
	return cam[2];
}

camera* datas::ReadequalCam4()
{
	return cam[3];
}

generateSkybox* datas::ReadequalSky()
{
	return sky;
}


	void datas::WriteequalObj(std::vector<object*> obj)
	{
		obj_=obj;
	}
	 void datas::WriteequalObj2(std::vector<object*> obj)
	 {
	 	obj2_=obj;
	 }
	 void datas::WriteequalObj3(std::vector<object*> obj)
	 {
	 	obj3_=obj;
	 }
	 void datas::WriteequalObj4(std::vector<object*> obj)
	 {
	 	obj4_=obj;
	 }
	 void datas::WriteequalObj5(std::vector<object*> obj)
	 {
	 	obj5_=obj;
	 }
	 void datas::WriteequalPObj(std::vector<Pobject*> obj)
	 {
	 	Pobj_=obj;
	 }
	 void datas::WriteequalPObj2(std::vector<Pobject*> obj)
	 {
	 	Pobj2_=obj;
	 }
	 void datas::WriteequalPObj3(std::vector<Pobject*> obj)
	 {
	 	Pobj3_=obj;
	 }
	 void datas::WriteequalPObj4(std::vector<Pobject*> obj)
	 {
	 	Pobj4_=obj;
	 }
	 void datas::WriteequalPObj5(std::vector<Pobject*> obj)
	 {
	 	Pobj5_=obj;
	 }
	 void datas::WriteequalPObj6(std::vector<Pobject*> obj)
	 {
	 	Pobj6_=obj;
	 }
	 void datas:: WriteequalPObj7(std::vector<Pobject*> obj)
	 {
	 	Pobj7_=obj;
	 }
	 void datas::  WriteequalPObj8(std::vector<Pobject*> obj)
	 {
	 	Pobj8_=obj;
	 }
	 void datas::  WriteequalPObj9(std::vector<Pobject*> obj)
	 {
	 	Pobj9_=obj;
	 }
	 void datas:: WriteequalPObj10(std::vector<Pobject*> obj)
	 {
	 	Pobj10_=obj;
	 }
	 void datas:: WriteequalPrefab(std::vector<prefab*> obj)
	 {
	 	pref_=obj;
	 }
	 void datas:: WriteequalPrefabAnim(std::vector<prefabAnim*> obj)
	 {
	 	prefAnim_=obj;
	 }
	 void datas:: WriteequalCam(camera* obj)
	 {
	 	cam_[0]=obj;
	 }
	 
	  void datas:: WriteequalCam2(std::vector<camera*> obj)
	 {
	 	cam_[1]=obj[1];
	 }
	 
	  void datas:: WriteequalCam3(std::vector<camera*> obj)
	 {
	 	cam_[2]=obj[2];
	 }
	 
	  void datas:: WriteequalCam4(std::vector<camera*> obj)
	 {
	 	cam_[3]=obj[3];
	 }
	 
	 void datas:: WriteequalSky(generateSkybox* obj)
	 {
	 	sky_=obj;
	 }


	 
void datas::saveToFile()
{
      
      	std::ofstream loadedFile;
      	loadedFile.open("data/stagelayoutObjects.txt");
         loadedFile<<"Draw Object"<<std::endl;
      	loadedFile<<"---beginObj1-----"<<std::endl;
      	for(int i=0;i<obj_.size();i++)
      	
		  {
		  
      	loadedFile<<"Obj1pos locX: "<<obj_[i]->getLocation().x<<"Obj1pos locY1: "<<obj_[i]->getLocation().y<<"Obj1pos locY2: "<<obj_[i]->getScale().y<<"Obj1pos locY: "<<obj_[i]->getScale().x<<"Obj1pos locY3: "<<obj_[i]->getScale().z<<"Obj1pos locY5: "<<obj_[i]->getRotation().y<<"Obj1pos locY4: "<<obj_[i]->getRotation().x<<"Obj1pos locY6: "<<obj_[i]->getRotation().z<<"Obj1pos locY7: "<<obj_[i]->getCouleur().x<<"Obj1pos locY8: "<<obj_[i]->getCouleur().y<<"Obj1pos locY9: "<<obj_[i]->getCouleur().z<<"obj1pos locZ: "<<obj_[i]->getLocation().z<<std::endl; 
    
}
	  	loadedFile<<"----endObj1-----"<<std::endl;
      		loadedFile<<"---beginObj2-----"<<std::endl;
      	for(int i=0;i<obj2_.size();i++)
      	{
		  
      loadedFile<<"Obj1pos locX_2: "<<obj2_[i]->getLocation().x<<"Obj1pos locY1_2: "<<obj2_[i]->getLocation().y<<"Obj1pos locY2_2: "<<obj2_[i]->getScale().y<<"Obj1pos locY_2: "<<obj2_[i]->getScale().x<<"Obj1pos locY3_2: "<<obj2_[i]->getScale().z<<"Obj1pos locY5_2: "<<obj2_[i]->getRotation().y<<"Obj1pos locY4_2: "<<obj2_[i]->getRotation().x<<"Obj1pos locY6_2: "<<obj2_[i]->getRotation().z<<"Obj1pos locY7_2: "<<obj2_[i]->getCouleur().x<<"Obj1pos locY8_2: "<<obj2_[i]->getCouleur().y<<"Obj1pos locY9_2: "<<obj2_[i]->getCouleur().z<<"Obj1pos locZ_2: "<<obj2_[i]->getLocation().z<<std::endl; 
    
  }
	  	loadedFile<<"----endObj2-----"<<std::endl;
      		loadedFile<<"---beginObj3-----"<<std::endl;
      	for(int i=0;i<obj3_.size();i++)
      	{
	 loadedFile<<"Obj1pos locX_3: "<<obj3_[i]->getLocation().x<<"Obj1pos locY1_3: "<<obj3_[i]->getLocation().y<<"Obj1pos locY2_3: "<<obj3_[i]->getScale().y<<"Obj1pos locY_3: "<<obj3_[i]->getScale().x<<"Obj1pos locY3_3: "<<obj3_[i]->getScale().z<<"Obj1pos locY5_3: "<<obj3_[i]->getRotation().y<<"Obj1pos locY4_3: "<<obj3_[i]->getRotation().x<<"Obj1pos locY6_2: "<<obj3_[i]->getRotation().z<<"Obj1pos locY7_3: "<<obj3_[i]->getCouleur().x<<"Obj1pos locY8_3: "<<obj3_[i]->getCouleur().y<<"Obj1pos locY9_3: "<<obj3_[i]->getCouleur().z<<"Obj1pos locZ_3: "<<obj3_[i]->getLocation().z<<std::endl; 
	  }   loadedFile<<"----endObj3-----"<<std::endl;
      
      		loadedFile<<"---beginObj4-----"<<std::endl;
      	for(int i=0;i<obj4_.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_4: "<<obj4_[i]->getLocation().x<<"Obj1pos locY1_4: "<<obj4_[i]->getLocation().y<<"Obj1pos locY2_4: "<<obj4_[i]->getScale().y<<"Obj1pos locY_4: "<<obj4_[i]->getScale().x<<"Obj1pos locY3_4: "<<obj4_[i]->getScale().z<<"Obj1pos locY5_4: "<<obj4_[i]->getRotation().y<<"Obj1pos locY4_4: "<<obj4_[i]->getRotation().x<<"Obj1pos locY6_4: "<<obj4_[i]->getRotation().z<<"Obj1pos locY7_4: "<<obj4_[i]->getCouleur().x<<"Obj1pos locY8_4: "<<obj4_[i]->getCouleur().y<<"Obj1pos locY9_4: "<<obj4_[i]->getCouleur().z<<"Obj1pos locZ_4: "<<obj4_[i]->getLocation().z<<std::endl; 
    
	  }
		  loadedFile<<"----endObj4-----"<<std::endl;
		  
		  	loadedFile<<"---beginVehicule-----"<<std::endl;
      	for(int i=0;i<pref_.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_5: "<<pref_[i]->getLocation().x<<"Obj1pos locY1_5: "<<pref_[i]->getLocation().y<<"Obj1pos locY2_5: "<<pref_[i]->getScale().y<<"Obj1pos locY_5: "<<pref_[i]->getScale().x<<"Obj1pos locY3_5: "<<pref_[i]->getScale().z<<"Obj1pos locY5_5: "<<pref_[i]->getRotation().y<<"Obj1pos locY4_5: "<<pref_[i]->getRotation().x<<"Obj1pos locY6_5: "<<pref_[i]->getRotation().z<<"Obj1pos locZ_5: "<<pref_[i]->getLocation().z<<std::endl; 

      }
		  loadedFile<<"----endVehicule-----"<<std::endl;
		  
		 loadedFile<<"---beginCharacter-----"<<std::endl;
      	for(int i=0;i<prefAnim_.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_6: "<<prefAnim_[i]->getLocation().x<<"Obj1pos locY1_6: "<<prefAnim_[i]->getLocation().y<<"Obj1pos locY2_6: "<<prefAnim_[i]->getScale().y<<"Obj1pos locY_6: "<<prefAnim_[i]->getScale().x<<"Obj1pos locY3_6: "<<prefAnim_[i]->getScale().z<<"Obj1pos locY5_6: "<<prefAnim_[i]->getRotation().y<<"Obj1pos locY4_6: "<<prefAnim_[i]->getRotation().x<<"Obj1pos locY6_6: "<<prefAnim_[i]->getRotation().z<<"Obj1pos locZ_6: "<<prefAnim_[i]->getLocation().z<<std::endl; 

      }
		  loadedFile<<"----endCharacter-----"<<std::endl; 
      
     
	  	
	  	
			   
			   loadedFile<<"---beginObj5-----"<<std::endl;
      	for(int i=0;i<obj5_.size();i++)
      	{
		  
     loadedFile<<"Obj1pos locX_7: "<<obj5_[i]->getLocation().x<<"Obj1pos locY1_7: "<<obj5_[i]->getLocation().y<<"Obj1pos locY2_7: "<<obj5_[i]->getScale().y<<"Obj1pos locY_7: "<<obj5_[i]->getScale().x<<"Obj1pos locY3_7: "<<obj5_[i]->getScale().z<<"Obj1pos locY5_7: "<<obj5_[i]->getRotation().y<<"Obj1pos locY4_7: "<<obj5_[i]->getRotation().x<<"Obj1pos locY6_7: "<<obj5_[i]->getRotation().z<<"Obj1pos locZ_7: "<<obj5_[i]->getLocation().z<<std::endl; 

      }
		  loadedFile<<"----endObj5-----"<<std::endl;
		  
		  
		  
		  
      	loadedFile<<"---beginPobj1-----"<<std::endl;
      	for(int i=0;i<Pobj_.size();i++)
      	
		  {
		  
      	loadedFile<<"Pobj1pos PlocX: "<<Pobj_[i]->getLocation().x<<"Pobj1pos PlocY1: "<<Pobj_[i]->getLocation().y<<"Pobj1pos PlocY2: "<<Pobj_[i]->getScale().y<<"Pobj1pos PlocY: "<<Pobj_[i]->getScale().x<<"Pobj1pos PlocY3: "<<Pobj_[i]->getScale().z<<"Pobj1pos PlocY5: "<<Pobj_[i]->getRotation().y<<"Pobj1pos PlocY4: "<<Pobj_[i]->getRotation().x<<"Pobj1pos PlocY6: "<<Pobj_[i]->getRotation().z<<"Pobj1pos PlocY7: "<<Pobj_[i]->getCouleur().x<<"Pobj1pos PlocY8: "<<Pobj_[i]->getCouleur().y<<"Pobj1pos PlocY9: "<<Pobj_[i]->getCouleur().z<<"Pobj1pos PlocZ: "<<Pobj_[i]->getLocation().z<<"Pobj1pos filename_21: "<<fileName[10]<<std::endl; 
    
}
	  	loadedFile<<"----endPobj1-----"<<std::endl;
      		loadedFile<<"---beginPobj2-----"<<std::endl;
      	for(int i=0;i<Pobj2_.size();i++)
      	{
		  
      loadedFile<<"Pobj1pos PlocX_2: "<<Pobj2_[i]->getLocation().x<<"Pobj1pos PlocY1_2: "<<Pobj2_[i]->getLocation().y<<"Pobj1pos PlocY2_2: "<<Pobj2_[i]->getScale().y<<"Pobj1pos PlocY_2: "<<Pobj2_[i]->getScale().x<<"Pobj1pos PlocY3_2: "<<Pobj2_[i]->getScale().z<<"Pobj1pos PlocY5_2: "<<Pobj2_[i]->getRotation().y<<"Pobj1pos PlocY4_2: "<<Pobj2_[i]->getRotation().x<<"Pobj1pos PlocY6_2: "<<Pobj2_[i]->getRotation().z<<"Pobj1pos PlocY7_2: "<<Pobj2_[i]->getCouleur().x<<"Pobj1pos PlocY8_2: "<<Pobj2_[i]->getCouleur().y<<"Pobj1pos PlocY9_2: "<<Pobj2_[i]->getCouleur().z<<"Pobj1pos PlocZ_2: "<<Pobj2_[i]->getLocation().z<<"Pobj1pos filename_20: "<<fileName[9]<<std::endl; 
    
  }
	  	loadedFile<<"----endPobj2-----"<<std::endl;
      		loadedFile<<"---beginPobj3-----"<<std::endl;
      	for(int i=0;i<Pobj3_.size();i++)
      	{
	 loadedFile<<"Pobj1pos PlocX_3: "<<Pobj3_[i]->getLocation().x<<"Pobj1pos PlocY1_3: "<<Pobj3_[i]->getLocation().y<<"Pobj1pos PlocY2_3: "<<Pobj3_[i]->getScale().y<<"Pobj1pos PlocY_3: "<<Pobj3_[i]->getScale().x<<"Pobj1pos PlocY3_3: "<<Pobj3_[i]->getScale().z<<"Pobj1pos PlocY5_3: "<<Pobj3_[i]->getRotation().y<<"Pobj1pos PlocY4_3: "<<Pobj3_[i]->getRotation().x<<"Pobj1pos PlocY6_2: "<<Pobj3_[i]->getRotation().z<<"Pobj1pos PlocY7_3: "<<Pobj3_[i]->getCouleur().x<<"Pobj1pos PlocY8_3: "<<Pobj3_[i]->getCouleur().y<<"Pobj1pos PlocY9_3: "<<Pobj3_[i]->getCouleur().z<<"Pobj1pos PlocZ_3: "<<Pobj3_[i]->getLocation().z<<"Pobj1pos filename_19: "<<fileName[8]<<std::endl; 
	  }   loadedFile<<"----endPobj3-----"<<std::endl;
      
      		loadedFile<<"---beginPobj4-----"<<std::endl;
      	for(int i=0;i<Pobj4_.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_4: "<<Pobj4_[i]->getLocation().x<<"Pobj1pos PlocY1_4: "<<Pobj4_[i]->getLocation().y<<"Pobj1pos PlocY2_4: "<<Pobj4_[i]->getScale().y<<"Pobj1pos PlocY_4: "<<Pobj4_[i]->getScale().x<<"Pobj1pos PlocY3_4: "<<Pobj4_[i]->getScale().z<<"Pobj1pos PlocY5_4: "<<Pobj4_[i]->getRotation().y<<"Pobj1pos PlocY4_4: "<<Pobj4_[i]->getRotation().x<<"Pobj1pos PlocY6_4: "<<Pobj4_[i]->getRotation().z<<"Pobj1pos PlocY7_4: "<<Pobj4_[i]->getCouleur().x<<"Pobj1pos PlocY8_4: "<<Pobj4_[i]->getCouleur().y<<"Pobj1pos PlocY9_4: "<<Pobj4_[i]->getCouleur().z<<"Pobj1pos PlocZ_4: "<<Pobj4_[i]->getLocation().z<<"Pobj1pos filename_18: "<<fileName[7]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj4-----"<<std::endl;
		  
		 	loadedFile<<"---beginPobj5-----"<<std::endl;
      	for(int i=0;i<Pobj5_.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_5: "<<Pobj5_[i]->getLocation().x<<"Pobj1pos PlocY1_5: "<<Pobj5_[i]->getLocation().y<<"Pobj1pos PlocY2_5: "<<Pobj5_[i]->getScale().y<<"Pobj1pos PlocY_5: "<<Pobj5_[i]->getScale().x<<"Pobj1pos PlocY3_5: "<<Pobj5_[i]->getScale().z<<"Pobj1pos PlocY5_5: "<<Pobj5_[i]->getRotation().y<<"Pobj1pos PlocY4_5: "<<Pobj5_[i]->getRotation().x<<"Pobj1pos PlocY6_5: "<<Pobj5_[i]->getRotation().z<<"Pobj1pos PlocY7_5: "<<Pobj5_[i]->getCouleur().x<<"Pobj1pos PlocY8_5: "<<Pobj5_[i]->getCouleur().y<<"Pobj1pos PlocY9_5: "<<Pobj5_[i]->getCouleur().z<<"Pobj1pos PlocZ_5: "<<Pobj5_[i]->getLocation().z<<"Pobj1pos filename_17: "<<fileName[6]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj5-----"<<std::endl;
		   
		   	 	loadedFile<<"---beginPobj6-----"<<std::endl;
      	for(int i=0;i<Pobj6_.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_6: "<<Pobj6_[i]->getLocation().x<<"Pobj1pos PlocY1_6: "<<Pobj6_[i]->getLocation().y<<"Pobj1pos PlocY2_6: "<<Pobj6_[i]->getScale().y<<"Pobj1pos PlocY_6: "<<Pobj6_[i]->getScale().x<<"Pobj1pos PlocY3_6: "<<Pobj6_[i]->getScale().z<<"Pobj1pos PlocY5_6: "<<Pobj6_[i]->getRotation().y<<"Pobj1pos PlocY4_6: "<<Pobj6_[i]->getRotation().x<<"Pobj1pos PlocY6_6: "<<Pobj6_[i]->getRotation().z<<"Pobj1pos PlocY7_6: "<<Pobj6_[i]->getCouleur().x<<"Pobj1pos PlocY8_6: "<<Pobj6_[i]->getCouleur().y<<"Pobj1pos PlocY9_6: "<<Pobj6_[i]->getCouleur().z<<"Pobj1pos PlocZ_6: "<<Pobj6_[i]->getLocation().z<<"Pobj1pos filename_16: "<<fileName[5]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj6-----"<<std::endl;
		     
			 	loadedFile<<"---beginPobj7-----"<<std::endl;
      	for(int i=0;i<Pobj7_.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_7: "<<Pobj7_[i]->getLocation().x<<"Pobj1pos PlocY1_7: "<<Pobj7_[i]->getLocation().y<<"Pobj1pos PlocY2_7: "<<Pobj7_[i]->getScale().y<<"Pobj1pos PlocY_7: "<<Pobj7_[i]->getScale().x<<"Pobj1pos PlocY3_7: "<<Pobj7_[i]->getScale().z<<"Pobj1pos PlocY5_7: "<<Pobj7_[i]->getRotation().y<<"Pobj1pos PlocY4_7: "<<Pobj7_[i]->getRotation().x<<"Pobj1pos PlocY6_7: "<<Pobj7_[i]->getRotation().z<<"Pobj1pos PlocY7_7: "<<Pobj7_[i]->getCouleur().x<<"Pobj1pos PlocY8_7: "<<Pobj7_[i]->getCouleur().y<<"Pobj1pos PlocY9_7: "<<Pobj7_[i]->getCouleur().z<<"Pobj1pos PlocZ_7: "<<Pobj7_[i]->getLocation().z<<"Pobj1pos filename_15: "<<fileName[4]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj7-----"<<std::endl;
		    
		    	 	loadedFile<<"---beginPobj8-----"<<std::endl;
      	for(int i=0;i<Pobj8_.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_8: "<<Pobj8_[i]->getLocation().x<<"Pobj1pos PlocY1_8: "<<Pobj8_[i]->getLocation().y<<"Pobj1pos PlocY2_8: "<<Pobj8_[i]->getScale().y<<"Pobj1pos PlocY_8: "<<Pobj8_[i]->getScale().x<<"Pobj1pos PlocY3_8: "<<Pobj8_[i]->getScale().z<<"Pobj1pos PlocY5_8: "<<Pobj8_[i]->getRotation().y<<"Pobj1pos PlocY4_8: "<<Pobj8_[i]->getRotation().x<<"Pobj1pos PlocY6_8: "<<Pobj8_[i]->getRotation().z<<"Pobj1pos PlocY7_8: "<<Pobj8_[i]->getCouleur().x<<"Pobj1pos PlocY8_8: "<<Pobj8_[i]->getCouleur().y<<"Pobj1pos PlocY9_8: "<<Pobj8_[i]->getCouleur().z<<"Pobj1pos PlocZ_8: "<<Pobj8_[i]->getLocation().z<<"Pobj1pos filename_14: "<<fileName[3]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj8-----"<<std::endl;
		    
		    	 	loadedFile<<"---beginPobj9-----"<<std::endl;
      	for(int i=0;i<Pobj9_.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_9: "<<Pobj9_[i]->getLocation().x<<"Pobj1pos PlocY1_9: "<<Pobj9_[i]->getLocation().y<<"Pobj1pos PlocY2_9: "<<Pobj9_[i]->getScale().y<<"Pobj1pos PlocY_9: "<<Pobj9_[i]->getScale().x<<"Pobj1pos PlocY3_9: "<<Pobj9_[i]->getScale().z<<"Pobj1pos PlocY5_9: "<<Pobj9_[i]->getRotation().y<<"Pobj1pos PlocY4_9: "<<Pobj9_[i]->getRotation().x<<"Pobj1pos PlocY6_9: "<<Pobj9_[i]->getRotation().z<<"Pobj1pos PlocY7_9: "<<Pobj9_[i]->getCouleur().x<<"Pobj1pos PlocY8_9: "<<Pobj9_[i]->getCouleur().y<<"Pobj1pos PlocY9_9: "<<Pobj9_[i]->getCouleur().z<<"Pobj1pos PlocZ_9: "<<Pobj9_[i]->getLocation().z<<"Pobj1pos filename_13: "<<fileName[2]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj9-----"<<std::endl;
		    
		    	 	loadedFile<<"---beginPobj10-----"<<std::endl;
      	for(int i=0;i<Pobj10_.size();i++)
      	{
		  
     loadedFile<<"Pobj1pos PlocX_10: "<<Pobj10_[i]->getLocation().x<<"Pobj1pos PlocY1_10: "<<Pobj10_[i]->getLocation().y<<"Pobj1pos PlocY2_10: "<<Pobj10_[i]->getScale().y<<"Pobj1pos PlocY_10: "<<Pobj10_[i]->getScale().x<<"Pobj1pos PlocY3_10: "<<Pobj10_[i]->getScale().z<<"Pobj1pos PlocY5_10: "<<Pobj10_[i]->getRotation().y<<"Pobj1pos PlocY4_10: "<<Pobj10_[i]->getRotation().x<<"Pobj1pos PlocY6_10: "<<Pobj10_[i]->getRotation().z<<"Pobj1pos PlocY7_10: "<<Pobj10_[i]->getCouleur().x<<"Pobj1pos PlocY8_10: "<<Pobj10_[i]->getCouleur().y<<"Pobj1pos PlocY9_10: "<<Pobj10_[i]->getCouleur().z<<"Pobj1pos PlocZ_10: "<<Pobj10_[i]->getLocation().z<<"Pobj1pos filename_12: "<<fileName[1]<<std::endl; 
    
	  }
		  loadedFile<<"----endPobj10-----"<<std::endl;
		  
		  
		   	loadedFile<<"---beginColorScreen-----"<<std::endl;
     
		  
     loadedFile<<"Pobj1pos PlocX_16: "<<sky_->getCol().x<<"Pobj1pos PlocY1_16: "<<sky_->getCol().y<<"Pobj1pos PlocZ_16: "<<sky_->getCol().z<<std::endl; 
    
	  
		  loadedFile<<"----endColorScreen-----"<<std::endl;
		  

		loadedFile<<"End Object"<<std::endl; 
	 	 
      	loadedFile.close();
      	std::cout<<"level saved"<<std::endl;
      	//fileName[11]="data/projet1.exe";
      	
      	
	  }
	
	
void datas::loadToFile(	)
{
	
	std::ifstream loadedFile("data/stagelayoutObjects.txt");
	std::string line;
	enum ObjectType
	{
		typeNone,
		typeObj
	};
	int currentType=typeNone;
	
	if(loadedFile.is_open())
	{
		while(loadedFile.good())
		  {
		  	std::getline(loadedFile,line);
		  	
		  	if(line=="---beginVehicule-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginCharacter-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginObj1-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginObj2-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginObj3-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginObj4-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginObj5-----")
		  	{
		  		currentType=typeObj;
			  }
			  
			     	if(line=="---beginPobj1-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginPobj2-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginPobj3-----")
		  	{
		  		currentType=typeObj;
			  }
			    	if(line=="---beginPobj4-----")
		  	{
		  		currentType=typeObj;
			  }
			  	if(line=="---beginPobj5-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj6-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj7-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj8-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj9-----")
		  	{
		  		currentType=typeObj;
			  }
			   	if(line=="---beginPobj10-----")
		  	{
		  		currentType=typeObj;
			  }
			 
	
			   	if(line=="---beginColorScreen-----")
		  	{
		  		currentType=typeObj;
			  }
			     
			  else if(line=="----endVehicule-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj1-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj2-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj3-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endObj4-----")
			  {
			  	currentType=typeNone;
			  }
			   else if(line=="----endObj5-----")
			  {
			  	currentType=typeNone;
			  }
			  	  else if(line=="----endPobj1-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endPobj2-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endPobj3-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endPobj4-----")
			  {
			  	currentType=typeNone;
			  }
			   else if(line=="----endPobj5-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj6-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj7-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj8-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj9-----")
			  {
			  	currentType=typeNone;
			  }
			    else if(line=="----endPobj10-----")
			  {
			  	currentType=typeNone;
			  }
			 
			   else if(line=="----endColorScreen-----")
			  {
			  	currentType=typeNone;
			  }
			  else if(line=="----endCharacter-----")
			  {
			  	currentType=typeNone;
			  }
			  
			  else
			  {
			  if(currentType==typeObj)
			  {
			  

		  	std::istringstream iss(line);
		  	vector3d tempLocation=vector3d(0,0,0);
		  	vector3d tempLocation2=vector3d(0,0,0);
			vector3d tempLocation3=vector3d(0,0,0);
		  	vector3d tempLocation4=vector3d(0,0,0);
		  	vector3d tempLocation5=vector3d(0,0,0);
		  	vector3d tempLocation6=vector3d(0,0,0);
		  	vector3d tempLocation7=vector3d(0,0,0);
		  	vector3d tempPLocation=vector3d(0,0,0);
		  	vector3d tempPLocation2=vector3d(0,0,0);
			vector3d tempPLocation3=vector3d(0,0,0);
		  	vector3d tempPLocation4=vector3d(0,0,0);
		  	vector3d tempPLocation5=vector3d(0,0,0);
		  	vector3d tempPLocation6=vector3d(0,0,0);
		  	vector3d tempPLocation7=vector3d(0,0,0);
		  	vector3d tempPLocation8=vector3d(0,0,0);
		  	vector3d tempPLocation9=vector3d(0,0,0);
		  	vector3d tempPLocation10=vector3d(0,0,0);

			vector3d tempRotation=vector3d(0,0,0);
			vector3d tempRotation2=vector3d(0,0,0);
			vector3d tempRotation3=vector3d(0,0,0);
			vector3d tempRotation4=vector3d(0,0,0);
			vector3d tempRotation5=vector3d(0,0,0);
			vector3d tempRotation6=vector3d(0,0,0);
			vector3d tempRotation7=vector3d(0,0,0);
			vector3d tempPRotation=vector3d(0,0,0);
			vector3d tempPRotation2=vector3d(0,0,0);
			vector3d tempPRotation3=vector3d(0,0,0);
			vector3d tempPRotation4=vector3d(0,0,0);
			vector3d tempPRotation5=vector3d(0,0,0);
			vector3d tempPRotation6=vector3d(0,0,0);
			vector3d tempPRotation7=vector3d(0,0,0);
			vector3d tempPRotation8=vector3d(0,0,0);
			vector3d tempPRotation9=vector3d(0,0,0);
			vector3d tempPRotation10=vector3d(0,0,0);
			vector3d tempPRotation12=vector3d(0,0,0);
			
		  	vector3d tempScale=vector3d(0,0,0);
		  	vector3d tempScale2=vector3d(0,0,0);
		  	vector3d tempScale3=vector3d(0,0,0);
		  	vector3d tempScale4=vector3d(0,0,0);
		  	vector3d tempScale5=vector3d(0,0,0);
		  	vector3d tempScale6=vector3d(0,0,0);
		  	vector3d tempScale7=vector3d(0,0,0);
		  	vector3d tempPScale=vector3d(0,0,0);
		  	vector3d tempPScale2=vector3d(0,0,0);
		  	vector3d tempPScale3=vector3d(0,0,0);
		  	vector3d tempPScale4=vector3d(0,0,0);
		  	vector3d tempPScale5=vector3d(0,0,0);
		  	vector3d tempPScale6=vector3d(0,0,0);
		  	vector3d tempPScale7=vector3d(0,0,0);
		  	vector3d tempPScale8=vector3d(0,0,0);
		  	vector3d tempPScale9=vector3d(0,0,0);
		  	vector3d tempPScale10=vector3d(0,0,0);
		  	vector3d tempPScale12=vector3d(0,0,0);
		  	
		  	vector3d tempCol=vector3d(0,0,0);
		  	vector3d tempCol2=vector3d(0,0,0);
		  	vector3d tempCol3=vector3d(0,0,0);
		  	vector3d tempCol4=vector3d(0,0,0);
		  	vector3d tempColScreen=vector3d(0,0,0);
			std::string tempFileName;
			std::string tempFileName2;
			std::string tempFileName3;
			std::string tempFileName4;
			std::string tempFileName5;
			std::string tempFileName6;
			std::string tempFileName7;
			std::string tempFileName8;
			std::string tempFileName9;
			std::string tempFileName10;
			std::string tempFileName11;
			
		  	std::string previousWord="";
		  	
		  	while(iss)
		  	{
		  		std::string word;
		  		iss>>word;
		  if(previousWord=="PlocX_16:")
		  {
		  	tempColScreen.x=atof(word.c_str());
		  }
		  if(previousWord=="PlocY1_16:")
		  {
		  	tempColScreen.y=atof(word.c_str());
		  }
		  
		  	if(previousWord=="PlocZ_10:")
		  	{
			  
		  		tempPLocation10.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_9:")
		  	{
			  
		  		tempPLocation9.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_8:")
		  	{
			  
		  		tempPLocation8.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_7:")
		  	{
			  
		  		tempPLocation7.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_6:")
		  	{
			  
		  		tempPLocation6.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_5:")
		  	{
			  
		  		tempPLocation5.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_4:")
		  	{
			  
		  		tempPLocation4.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_3:")
		  	{
			  
		  		tempPLocation3.z=atoi(word.c_str());
		  	}
		  	if(previousWord=="PlocZ_2:")
		  	{
			  
		  		tempPLocation2.z=atoi(word.c_str());
		  	}
		  		if(previousWord=="PlocZ:")
		  	{
			  
		  		tempPLocation.z=atoi(word.c_str());
		  	}
		  	
		  		
				  	if(previousWord=="locX:")
		  		{
		  			tempLocation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
				  	if(previousWord=="locX_2:")
		  		{
		  			tempLocation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="locX_3:")
		  		{
		  			tempLocation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="locX_4:")
		  		{
		  			tempLocation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		  	if(previousWord=="locX_5:")
		  		{
		  			tempLocation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="locX_6:")
		  		{
		  			tempLocation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="locX_7:")
		  		{
		  			tempLocation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  			  	if(previousWord=="PlocX:")
		  		{
		  			tempPLocation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
				  	if(previousWord=="PlocX_2:")
		  		{
		  			tempPLocation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="PlocX_3:")
		  		{
		  			tempPLocation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			
				  	if(previousWord=="PlocX_4:")
		  		{
		  			tempPLocation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		  	if(previousWord=="PlocX_5:")
		  		{
		  			tempPLocation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_6:")
		  		{
		  			tempPLocation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_7:")
		  		{
		  			tempPLocation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_8:")
		  		{
		  			tempPLocation8.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_9:")
		  		{
		  			tempPLocation9.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			if(previousWord=="PlocX_10:")
		  		{
		  			tempPLocation10.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  			  	if(previousWord=="locY1:")
		  		{
		  			tempLocation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY1_2:")
		  		{
		  			tempLocation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_3:")
		  		{
		  			tempLocation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_4:")
		  		{
		  			tempLocation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_5:")
		  		{
		  			tempLocation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_6:")
		  		{
		  			tempLocation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY1_7:")
		  		{
		  			tempLocation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  	
		  	
		  		  	if(previousWord=="PlocY1:")
		  		{
		  			tempPLocation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY1_2:")
		  		{
		  			tempPLocation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_3:")
		  		{
		  			tempPLocation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_4:")
		  		{
		  			tempPLocation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_5:")
		  		{
		  			tempPLocation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_6:")
		  		{
		  			tempPLocation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_7:")
		  		{
		  			tempPLocation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY1_8:")
		  		{
		  			tempPLocation8.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_9:")
		  		{
		  			tempPLocation9.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  					  	if(previousWord=="PlocY1_10:")
		  		{
		  			tempPLocation10.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			
		  	
		  	
		  			  	if(previousWord=="locY:")
		  		{
		  			tempScale.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY_2:")
		  		{
		  			tempScale2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY_3:")
		  		{
		  			tempScale3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY_4:")
		  		{
		  			tempScale4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY_5:")
		  		{
		  			tempScale5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  					  	if(previousWord=="locY_6:")
		  		{
		  			tempScale6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY_7:")
		  		{
		  			tempScale7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY:")
		  		{
		  			tempPScale.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY_2:")
		  		{
		  			tempPScale2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY_3:")
		  		{
		  			tempPScale3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY_4:")
		  		{
		  			tempPScale4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_5:")
		  		{
		  			tempPScale5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  					  	if(previousWord=="PlocY_6:")
		  		{
		  			tempPScale6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_7:")
		  		{
		  			tempPScale7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_8:")
		  		{
		  			tempPScale8.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_9:")
		  		{
		  			tempPScale9.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY_10:")
		  		{
		  			tempPScale10.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY_12:")
		  		{
		  			tempPScale12.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
		  		
		  		
		  			  	if(previousWord=="locY2:")
		  		{
		  			tempScale.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_2:")
		  		{
		  			tempScale2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY2_3:")
		  		{
		  			tempScale3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY2_4:")
		  		{
		  			tempScale4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_5:")
		  		{
		  			tempScale5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_6:")
		  		{
		  			tempScale6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY2_7:")
		  		{
		  			tempScale7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  		  	if(previousWord=="PlocY2:")
		  		{
		  			tempPScale.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_2:")
		  		{
		  			tempPScale2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY2_3:")
		  		{
		  			tempPScale3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY2_4:")
		  		{
		  			tempPScale4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_5:")
		  		{
		  			tempPScale5.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_6:")
		  		{
		  			tempPScale6.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_7:")
		  		{
		  			tempPScale7.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  	
		  			  	if(previousWord=="PlocY2_8:")
		  		{
		  			tempPScale8.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_9:")
		  		{
		  			tempPScale9.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY2_10:")
		  		{
		  			tempPScale10.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY2_12:")
		  		{
		  			tempPScale12.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  	
		  			  	if(previousWord=="locY3:")
		  		{
		  			tempScale.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_2:")
		  		{
		  			tempScale2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_3:")
		  		{
		  			tempScale3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_4:")
		  		{
		  			tempScale4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_5:")
		  		{
		  			tempScale5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			  	if(previousWord=="locY3_6:")
		  		{
		  			tempScale6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY3_7:")
		  		{
		  			tempScale7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  		
		  			  	if(previousWord=="PlocY3:")
		  		{
		  			tempPScale.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_2:")
		  		{
		  			tempPScale2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_3:")
		  		{
		  			tempPScale3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_4:")
		  		{
		  			tempPScale4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_5:")
		  		{
		  			tempPScale5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			  	if(previousWord=="PlocY3_6:")
		  		{
		  			tempPScale6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_7:")
		  		{
		  			tempPScale7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_8:")
		  		{
		  			tempPScale8.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_9:")
		  		{
		  			tempPScale9.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY3_10:")
		  		{
		  			tempPScale10.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		 	if(previousWord=="PlocY3_12:")
		  		{
		  			tempPScale12.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  			  	if(previousWord=="locY4:")
		  		{
		  			tempRotation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY4_2:")
		  		{
		  			tempRotation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY4_3:")
		  		{
		  			tempRotation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY4_4:")
		  		{
		  			tempRotation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY4_5:")
		  		{
		  			tempRotation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY4_6:")
		  		{
		  			tempRotation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY4_7:")
		  		{
		  			tempRotation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			if(previousWord=="PlocY4:")
		  		{
		  			tempPRotation.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY4_2:")
		  		{
		  			tempPRotation2.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_3:")
		  		{
		  			tempPRotation3.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_4:")
		  		{
		  			tempPRotation4.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_5:")
		  		{
		  			tempPRotation5.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY4_6:")
		  		{
		  			tempPRotation6.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY4_7:")
		  		{
		  			tempPRotation7.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_8:")
		  		{
		  			tempPRotation8.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_9:")
		  		{
		  			tempPRotation9.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY4_10:")
		  		{
		  			tempPRotation10.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			  	if(previousWord=="PlocY4_12:")
		  		{
		  			tempPRotation12.x=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  			  	if(previousWord=="locY5:")
		  		{
		  			tempRotation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY5_2:")
		  		{
		  			tempRotation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY5_3:")
		  		{
		  			tempRotation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY5_4:")
		  		{
		  			tempRotation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY5_5:")
		  		{
		  			tempRotation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  			  	if(previousWord=="locY5_6:")
		  		{
		  			tempRotation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="locY5_7:")
		  		{
		  			tempRotation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  	
		  	
		  		if(previousWord=="PlocY5:")
		  		{
		  			tempPRotation.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY5_2:")
		  		{
		  			tempPRotation2.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY5_3:")
		  		{
		  			tempPRotation3.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY5_4:")
		  		{
		  			tempPRotation4.y=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY5_5:")
		  		{
		  			tempPRotation5.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  			  	if(previousWord=="PlocY5_6:")
		  		{
		  			tempPRotation6.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_7:")
		  		{
		  			tempPRotation7.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_8:")
		  		{
		  			tempPRotation8.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_9:")
		  		{
		  			tempPRotation9.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  		  	if(previousWord=="PlocY5_10:")
		  		{
		  			tempPRotation10.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	  
		  	 	if(previousWord=="PlocY5_12:")
		  		{
		  			tempPRotation12.y=atoi(word.c_str());
		  		
		  		
		  					
		  	}
		  	
		  		
		  				  	if(previousWord=="locY6:")
		  		{
		  			tempRotation.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY6_2:")
		  		{
		  			tempRotation2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY6_3:")
		  		{
		  			tempRotation3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY6_4:")
		  		{
		  			tempRotation4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY6_5:")
		  		{
		  			tempRotation5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="locY6_6:")
		  		{
		  			tempRotation6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="locY6_7:")
		  		{
		  			tempRotation7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  			if(previousWord=="PlocY6:")
		  		{
		  			tempPRotation.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY6_2:")
		  		{
		  			tempPRotation2.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY6_3:")
		  		{
		  			tempPRotation3.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY6_4:")
		  		{
		  			tempPRotation4.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="PlocY6_5:")
		  		{
		  			tempPRotation5.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  				  	if(previousWord=="PlocY6_6:")
		  		{
		  			tempPRotation6.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  			  	if(previousWord=="PlocY6_7:")
		  		{
		  			tempPRotation7.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		 	if(previousWord=="PlocY6_8:")
		  		{
		  			tempPRotation8.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		 	if(previousWord=="PlocY6_9:")
		  		{
		  			tempPRotation9.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		 	if(previousWord=="PlocY6_10:")
		  		{
		  			tempPRotation10.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  	
		  			if(previousWord=="PlocY6_12:")
		  		{
		  			tempPRotation12.z=atoi(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  		
		  		
		  				  	if(previousWord=="locY7:")
		  		{
		  			tempCol.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8:")
		  		{
		  			tempCol.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9:")
		  		{
		  			tempCol.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
		  		
		  			
		  				  	if(previousWord=="locY7_2:")
		  		{
		  			tempCol2.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8_2:")
		  		{
		  			tempCol2.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9_2:")
		  		{
		  			tempCol2.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
		  			
		  				  	if(previousWord=="locY7_3:")
		  		{
		  			tempCol3.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8_3:")
		  		{
		  			tempCol3.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9_3:")
		  		{
		  			tempCol3.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
				  	
		  				  	if(previousWord=="locY7_4:")
		  		{
		  			tempCol4.x=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY8_4:")
		  		{
		  			tempCol4.y=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}
		  				  	if(previousWord=="locY9_4:")
		  		{
		  			tempCol4.z=atof(word.c_str());
		  		
		  		
		  					
		  		
		  		}	
				  	
		  		
		  	
		  
		  			  	if(previousWord=="locZ:")
		  		{
		  			tempLocation.z=atoi(word.c_str());
		  		
		  		obj.push_back(new object(vector3d(tempLocation.x,tempLocation.y,tempLocation.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempRotation.x,tempRotation.y,tempRotation.z),vector3d(tempScale.x,tempScale.y,tempScale.z)));	
		  		
		  		
		  		}
		  		
		  		
		  			  	if(previousWord=="locZ_2:")
		  		{
		  			tempLocation2.z=atoi(word.c_str());
		  		
		  		obj2.push_back(new object(vector3d(tempLocation2.x,tempLocation2.y,tempLocation2.z),vector3d(tempCol2.x,tempCol2.y,tempCol2.z),vector3d(tempRotation2.x,tempRotation2.y,tempRotation2.z),vector3d(tempScale2.x,tempScale2.y,tempScale2.z)));	
		  		
		  		
		  		}
		  			  	if(previousWord=="locZ_3:")
		  		{
		  			tempLocation3.z=atoi(word.c_str());
		  		
		  		obj3.push_back(new object(vector3d(tempLocation3.x,tempLocation3.y,tempLocation3.z),vector3d(tempCol3.x,tempCol3.y,tempCol3.z),vector3d(tempRotation3.x,tempRotation3.y,tempRotation3.z),vector3d(tempScale3.x,tempScale3.y,tempScale3.z)));	
		  		
		  		
		  		}
		  			  	if(previousWord=="locZ_4:")
		  		{
		  			tempLocation4.z=atoi(word.c_str());
		  		
		  		obj4.push_back(new object(vector3d(tempLocation4.x,tempLocation4.y,tempLocation4.z),vector3d(tempCol4.x,tempCol4.y,tempCol4.z),vector3d(tempRotation4.x,tempRotation4.y,tempRotation4.z),vector3d(tempScale4.x,tempScale4.y,tempScale4.z)));	
		  		
		  		
		  		}
		  			  	if(previousWord=="locZ_5:")
		  		{
		  			tempLocation5.z=atoi(word.c_str());
		  			
			
					pref.push_back(new prefab("vehicule","data/vehicule.obj",vector3d(tempLocation5.x,tempLocation5.y,tempLocation5.z),vector3d(tempRotation5.x,tempRotation5.y,tempRotation5.z),vector3d(tempScale5.x,tempScale5.y,tempScale5.z)));
		  		}
		  		
		  			  	if(previousWord=="locZ_6:")
		  		{
		  			tempLocation6.z=atoi(word.c_str());
		  			
				
				prefAnim.push_back(new prefabAnim("character",vector3d(tempLocation6.x,tempLocation6.y,tempLocation6.z),vector3d(tempRotation6.x,tempRotation6.y,tempRotation6.z),vector3d(tempScale6.x,tempScale6.y,tempScale6.z)));
		  		}
		  		
		  		
		  		if(previousWord=="locZ_7:")
		  		{
		  		tempLocation7.z=atoi(word.c_str());
				 
		  			
				
				obj5.push_back(new object(vector3d(tempLocation7.x,tempLocation7.y,tempLocation7.z),vector3d(0.5,0.5,0.5),vector3d(tempRotation7.x,tempRotation7.y,tempRotation7.z),vector3d(tempScale7.x,tempScale7.y,tempScale7.z)));
		  		}
		  		
		  		
		  		
		  		 	if(previousWord=="filename_21:")
		  		{
		  			tempFileName11=word.c_str();
		  				fileName[10]=tempFileName11;
		  				unsigned int map=objLoad.load(fileName[10]);	
		  		Pobj.push_back(new Pobject("map",map,vector3d(tempPLocation.x,tempPLocation.y,tempPLocation.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation.x,tempPRotation.y,tempPRotation.z),vector3d(tempPScale.x,tempPScale.y,tempPScale.z)));	
		  		
		  		
		  		}
		  		
		  		 	if(previousWord=="filename_20:")
		  		{
		  				tempFileName10=word.c_str();
		  				fileName[9]=tempFileName10;
		  				unsigned int map=objLoad.load(fileName[9]);	
		  		Pobj2.push_back(new Pobject("map",map,vector3d(tempPLocation2.x,tempPLocation2.y,tempPLocation2.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation2.x,tempPRotation2.y,tempPRotation2.z),vector3d(tempPScale2.x,tempPScale2.y,tempPScale2.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_19:")
		  		{
		  			tempFileName9=word.c_str();
		  				fileName[8]=tempFileName9;
		  				unsigned int map=objLoad.load(fileName[8]);	
		  		Pobj3.push_back(new Pobject("map",map,vector3d(tempPLocation3.x,tempPLocation3.y,tempPLocation3.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation3.x,tempPRotation3.y,tempPRotation3.z),vector3d(tempPScale3.x,tempPScale3.y,tempPScale3.z)));	
		  		
		  		
		  		}
		  			if(previousWord=="filename_18:")
		  		{
		  			tempFileName8=word.c_str();
		  				fileName[7]=tempFileName8;
		  				unsigned int map=objLoad.load(fileName[7]);	
		  		Pobj4.push_back(new Pobject("map",map,vector3d(tempPLocation4.x,tempPLocation4.y,tempPLocation4.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation4.x,tempPRotation4.y,tempPRotation4.z),vector3d(tempPScale4.x,tempPScale4.y,tempPScale4.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_17:")
		  		{
		  				tempFileName7=word.c_str();
		  				fileName[6]=tempFileName7;
		  				unsigned int map=objLoad.load(fileName[6]);	
		  		Pobj5.push_back(new Pobject("map",map,vector3d(tempPLocation5.x,tempPLocation5.y,tempPLocation5.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation5.x,tempPRotation5.y,tempPRotation5.z),vector3d(tempPScale5.x,tempPScale5.y,tempPScale5.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_16:")
		  		{
		  			tempFileName6=word.c_str();
		  				fileName[5]=tempFileName6;
		  				unsigned int map=objLoad.load(fileName[5]);	
		  		Pobj6.push_back(new Pobject("map",map,vector3d(tempPLocation6.x,tempPLocation6.y,tempPLocation6.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation6.x,tempPRotation6.y,tempPRotation6.z),vector3d(tempPScale6.x,tempPScale6.y,tempPScale6.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_15:")
		  		{
		  			tempFileName5=word.c_str();
		  				fileName[4]=tempFileName5;
		  				unsigned int map=objLoad.load(fileName[4]);	
		  		Pobj7.push_back(new Pobject("map",map,vector3d(tempPLocation7.x,tempPLocation7.y,tempPLocation7.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation7.x,tempPRotation7.y,tempPRotation7.z),vector3d(tempPScale7.x,tempPScale7.y,tempPScale7.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_14:")
		  		{
		  				tempFileName4=word.c_str();
		  				fileName[3]=tempFileName4;
		  				unsigned int map=objLoad.load(fileName[3]);	
		  		Pobj8.push_back(new Pobject("map",map,vector3d(tempPLocation8.x,tempPLocation8.y,tempPLocation8.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation8.x,tempPRotation8.y,tempPRotation8.z),vector3d(tempPScale8.x,tempPScale8.y,tempPScale8.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_13:")
		  		{
		  			tempFileName3=word.c_str();
		  				fileName[2]=tempFileName3;
		  				unsigned int map=objLoad.load(fileName[2]);	
		  		Pobj9.push_back(new Pobject("map",map,vector3d(tempPLocation9.x,tempPLocation9.y,tempPLocation9.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation9.x,tempPRotation9.y,tempPRotation9.z),vector3d(tempPScale9.x,tempPScale9.y,tempPScale9.z)));	
		  		
		  		
		  		}
		  		
		  			if(previousWord=="filename_12:")
		  		{
		  			tempFileName2=word.c_str();
		  				fileName[1]=tempFileName2;
		  				unsigned int map=objLoad.load(fileName[1]);	
		  		Pobj10.push_back(new Pobject("map",map,vector3d(tempPLocation10.x,tempPLocation10.y,tempPLocation10.z),vector3d(tempCol.x,tempCol.y,tempCol.z),vector3d(tempPRotation10.x,tempPRotation10.y,tempPRotation10.z),vector3d(tempPScale10.x,tempPScale10.y,tempPScale10.z)));	
		  		
		  		
		  		}
		  	
		  		
		  		
		  		
		  		if(previousWord=="PlocZ_16:")
		  		{
		  			tempColScreen.z=atof(word.c_str());
		  			sky->setCol(vector3d(tempColScreen.x,tempColScreen.y,tempColScreen.z));
		  			//col=vector3d(tempColScreen.x,tempColScreen.y,tempColScreen.z);
		  		}
		  		

			
				  previousWord=word;
			  }
	}
	
		}
		  
		  }
	}
	else
	{
		std::cout<<"File not open"<<std::endl;
	}
}


