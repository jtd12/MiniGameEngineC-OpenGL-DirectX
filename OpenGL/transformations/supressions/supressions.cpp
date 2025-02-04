#include"supressions.hpp"

supression::supression()
{

}


supression::~supression()
{

}

void supression::update(
		std::vector<object*>& obj,
		std::vector<object*>& obj2,
		std::vector<object*>& obj3, 
		std::vector<object*>& obj4, 
		std::vector<object*>& obj5, 
		std::vector<Pobject*>& Pobj, 
		std::vector<Pobject*>& Pobj2,
		std::vector<Pobject*>& Pobj3,
		std::vector<Pobject*>& Pobj4,
		std::vector<Pobject*>& Pobj5,
		std::vector<Pobject*>& Pobj6,
		std::vector<Pobject*>& Pobj7,
		std::vector<Pobject*>& Pobj8,
		std::vector<Pobject*>& Pobj9,
		std::vector<Pobject*>& Pobj10,
		std::vector<prefab*>& pref,
		std::vector<prefabAnim*>& prefAnim
		)
{
		if(obj.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj.begin(); i != obj.end();++i)
					{
						if(count==obj.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj.pop_back();
		}
		
		
					
			if(obj2.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj2.begin(); i != obj2.end();++i)
					{
						if(count==obj2.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj2.pop_back();
		}
			 
					
			if(obj3.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj3.begin(); i != obj3.end();++i)
					{
						if(count==obj3.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj3.pop_back();
		}
		
		
					
			if(obj4.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj4.begin(); i != obj4.end();++i)
					{
						if(count==obj4.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj4.pop_back();
		}
		
					
			if(obj5.size()>0)
			{
					int count=0;
					for(std::vector<object*>::iterator i = obj5.begin(); i != obj5.end();++i)
					{
						if(count==obj5.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 obj5.pop_back();
		}
		
					
			if(pref.size()>0)
			{
					int count=0;
					for(std::vector<prefab*>::iterator i = pref.begin(); i != pref.end();++i)
					{
						if(count==pref.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 pref.pop_back();
		}
		
					
			if(prefAnim.size()>0)
			{
					int count=0;
					for(std::vector<prefabAnim*>::iterator i = prefAnim.begin(); i != prefAnim.end();++i)
					{
						if(count==prefAnim.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 prefAnim.pop_back();
		}
		
					
			if(Pobj.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj.begin(); i != Pobj.end();++i)
					{
						if(count==Pobj.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj.pop_back();
		}
				if(Pobj2.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj2.begin(); i != Pobj2.end();++i)
					{
						if(count==Pobj2.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj2.pop_back();
		}
				if(Pobj3.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj3.begin(); i != Pobj3.end();++i)
					{
						if(count==Pobj3.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj3.pop_back();
		}
		
				if(Pobj4.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj4.begin(); i != Pobj4.end();++i)
					{
						if(count==Pobj4.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj4.pop_back();
		}
				if(Pobj5.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj5.begin(); i != Pobj5.end();++i)
					{
						if(count==Pobj5.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj5.pop_back();
		}
		
				if(Pobj6.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj6.begin(); i != Pobj6.end();++i)
					{
						if(count==Pobj6.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj6.pop_back();
		}
				if(Pobj7.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj7.begin(); i != Pobj7.end();++i)
					{
						if(count==Pobj7.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj7.pop_back();
		}
		
				if(Pobj8.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj8.begin(); i != Pobj8.end();++i)
					{
						if(count==Pobj8.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj8.pop_back();
		}
		
				if(Pobj9.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj9.begin(); i != Pobj9.end();++i)
					{
						if(count==Pobj9.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj9.pop_back();
		}
		
				if(Pobj10.size()>0)
			{
					int count=0;
					for(std::vector<Pobject*>::iterator i = Pobj10.begin(); i != Pobj10.end();++i)
					{
						if(count==Pobj10.size())
						{
							delete (*i);
						}
						count++;
					}
		
			 Pobj10.pop_back();
		}
}
void supression::update(pointer* p,	std::vector<camera*>& cam_,
		std::vector<object*>& obj_,
		std::vector<object*>& obj2_,
		std::vector<object*>& obj3_, 
		std::vector<object*>& obj4_, 
		std::vector<object*>& obj5_, 
		std::vector<Pobject*>& Pobj_, 
		std::vector<Pobject*>& Pobj2_,
		std::vector<Pobject*>& Pobj3_,
		std::vector<Pobject*>& Pobj4_,
		std::vector<Pobject*>& Pobj5_,
		std::vector<Pobject*>& Pobj6_,
		std::vector<Pobject*>& Pobj7_,
		std::vector<Pobject*>& Pobj8_,
		std::vector<Pobject*>& Pobj9_,
		std::vector<Pobject*>& Pobj10_,
		std::vector<prefab*>& pref_,
		std::vector<prefabAnim*>& prefAnim_,
		generateSkybox* sky_)
{
		for(int i=0;i<obj2_.size();i++)
				if(value==900 && selectObject(obj2_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj2_.erase(obj2_.begin()+i);
		for(int i=0;i<obj_.size();i++)
		if(value==900 && selectObject(obj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))

	obj_.erase(obj_.begin()+i);
	
	for(int i=0;i<obj3_.size();i++)
	if(value==900 && selectObject(obj3_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj3_.erase(obj3_.begin()+i);
	for(int i=0;i<obj4_.size();i++)
		if(value==900 && selectObject(obj4_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj4_.erase(obj4_.begin()+i);
		for(int i=0;i<obj5_.size();i++)
		if(value==900 && selectObject(obj5_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	obj5_.erase(obj5_.begin()+i);
	for(int i=0;i<pref_.size();i++)
		if(value==900 && selectObject(pref_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	pref_.erase(pref_.begin()+i);
		for(int i=0;i<prefAnim_.size();i++)
		if(value==900 && selectObject(prefAnim_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	prefAnim_.erase(prefAnim_.begin()+i);

		
		for(int i=0;i<Pobj_.size();i++)
				if(value==900 && selectObject(Pobj_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj_.erase(Pobj_.begin()+i);
		for(int i=0;i<Pobj2_.size();i++)
		if(value==900 && selectObject(Pobj2_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))

	Pobj2_.erase(Pobj2_.begin()+i);
	
	for(int i=0;i<Pobj3_.size();i++)
	if(value==900 && selectObject(Pobj3_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj3_.erase(Pobj3_.begin()+i);
	for(int i=0;i<Pobj4_.size();i++)
		if(value==900 && selectObject(Pobj4_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj4_.erase(Pobj4_.begin()+i);
		for(int i=0;i<Pobj5_.size();i++)
		if(value==900 && selectObject(Pobj5_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj5_.erase(Pobj5_.begin()+i);
	for(int i=0;i<Pobj6_.size();i++)
		if(value==900 && selectObject(Pobj6_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj6_.erase(Pobj6_.begin()+i);
	for(int i=0;i<Pobj7_.size();i++)
		if(value==900 && selectObject(Pobj7_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj7_.erase(Pobj7_.begin()+i);
	for(int i=0;i<Pobj8_.size();i++)
		if(value==900 && selectObject(Pobj8_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj8_.erase(Pobj8_.begin()+i);
	for(int i=0;i<Pobj9_.size();i++)
		if(value==900 && selectObject(Pobj9_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj9_.erase(Pobj9_.begin()+i);
	for(int i=0;i<Pobj10_.size();i++)
		if(value==900 && selectObject(Pobj10_[i]->getLocation(),p->getLocation(),vector3d(0.2,0.5,0.5),5))
	Pobj10_.erase(Pobj10_.begin()+i);
	
		 if(value==145)
		 for(int i=0;i<sky_->skyb.size();i++)
		 sky_->skyb.erase(sky_->skyb.begin()+i);
		 
		
}

bool supression::selectObject(vector3d objectReference,vector3d objectPointer,vector3d color,float dist_)
{
	float dist=(sqrt(((objectPointer.x-objectReference.x)*(objectPointer.x-objectReference.x))+((objectPointer.y-objectReference.y)*(objectPointer.y-objectReference.y))+
	((objectPointer.z-objectReference.z)*(objectPointer.z-objectReference.z))));
	if(dist<dist_)
	{
		
		return true;
	}
	return false;
}

