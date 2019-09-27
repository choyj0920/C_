#pragma once
class Object
{
protected:
	int color, bgcolor;
	int _posX;
	int _posY;
	string _Shape;
	int _sizeX;
	int _sizeY;
	eObjectType _myType;


public:
	Object();
	~Object();
	void set_(int x, int y, int sizeX, int sizeY, string shape, int color, int bgcolor);
	void DrawMode1();
	bool CheckCollider(const Object* obj);
	void erase_shape();
};

