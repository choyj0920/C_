#include "pch.h"
#include "itemObject.h"
#include "Object.h"


itemObject::itemObject(int x, int y, string modelshape, int sizeX, int sizeY, int color, int bgcolor) : Object()
{
	set_(x, y, sizeX, sizeY, modelshape,color, bgcolor);
	
}

itemObject::~itemObject()
{
	
}



