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

	//�Է� ���� ��ǥ�� ���� ���ؼ� ���� �浹�ߴ��� üũ
	bool CheckCollider(int x, int y,int sizex,int sizey,eObjectType type);
	void DrawMode1();
	

};

