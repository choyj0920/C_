#pragma once
class itemObject
{
	int _posX;
	int _posY;
	string _modelShape;
	int _sizeX;
	int _sizeY;
	bool _isEnable;
	int _modelColor;
	int _modelBGColor;
	eObjectType _myType;

public:
	itemObject(int x,int y,string modelshape, int sizeX,int sizeY,int color,int bgcolor);
	~itemObject();

	//입력 받은 좌표와 나를 비교해서 나와 충돌했는지 체크
	bool CheckCollider(int x, int y,int sizex,int sizey,eObjectType type);
	void DrawMode1();
	

};

