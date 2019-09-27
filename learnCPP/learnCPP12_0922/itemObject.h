#pragma once
#include "Object.h"
class itemObject :public Object
{

	bool _isEnable;

public:
	itemObject(int x,int y,string modelshape, int sizeX,int sizeY,int color,int bgcolor);
	~itemObject();

	
	

};

