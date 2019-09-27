#include "pch.h"
#include "Object.h"
Object::Object()
{
}


Object::~Object()
{
}

void Object::set_(int x, int y, int sizeX, int sizeY, string shape, int color, int bgcolor)
{
	_posX = x;
	_posY = y;
	_sizeX = sizeX;
	_sizeY = sizeY;
	_Shape = shape;
	this->color = color;
	this->bgcolor = bgcolor;
}

void Object::DrawMode1()
{
	DrawGraphics::setcolor(color, bgcolor);

	for (int i = 0; i < _sizeY; i++) {
		DrawGraphics::gotoxy(_posX, _posY + i);
		for (int j = 0; j < _sizeX; j++) {
			cout << " ";
		}

	}
	DrawGraphics::gotoxy(_posX + (_sizeX - _Shape.length()) / 2, _posY + _sizeY / 2);
	cout << _Shape;
	DrawGraphics::setcolor(15, 0);
}

bool Object::CheckCollider(const Object * obj)
{
	if (_posX + _sizeX <= obj->_posX || obj->_posX + obj->_sizeX <= _posX || _posY + _sizeY <= obj->_posY || obj->_posY + obj->_sizeY <= _posY)
		return false;
	else
		return true;
}

void Object::erase_shape()
{
	for (int i = 0; i < _sizeY; i++)
		for (int j = 0; j < _sizeX; j++) {
			DrawGraphics::gotoxy(_posX+ j, _posY + i);
			cout << " ";
		}

}

