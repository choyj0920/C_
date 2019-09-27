#include "pch.h"
#include "itemObject.h"


//modelshape는 한개의 글자(알파벳,숫자)로 한다.
itemObject::itemObject(int x, int y, string modelshape, int sizeX, int sizeY, int color, int bgcolor) : _posX(x),_posY(y),_sizeX(sizeX),_sizeY(sizeY),_modelColor(color),_modelBGColor(bgcolor)
{
	_myType = OBJ_item;
	_modelShape = modelshape;
}

itemObject::~itemObject()
{
}

bool itemObject::CheckCollider(int x, int y, int sizex, int sizey, eObjectType type)
{
	if (type == OBJ_player) {
		
	}
	else if (type == OBJ_item) {

	}


	return false;
}

void itemObject::DrawMode1()
{
	DrawGraphics::setcolor(_modelColor, _modelBGColor);
	/*
	for (int n = 0; n < _sizeY; n++) {
		int rol = (n + 1) / 2;
		int x, y;
		if (n % 2 == 1)
			y = _posY + rol;
		else
			y = _posY - rol;

		for (int m = 0; m < _sizeX; m++) {
			int val = (m+1) / 2;
			
			if (m % 2 == 1) {
				//홀수 일 경우 더하기
				x = _posX + val;
			}
			else { //짝수 일 경우 빼기
				x = _posX - val;
			}
			//최종위치 연산
			if (m == 0 && n == 0) {
				DrawGraphics::gotoxy(_posX, _posY);
				cout << _modelShape;
			}
			else {
				DrawGraphics::gotoxy(x, y);
				cout << " ";
			}
		}
	}  */
	//pos x,y =객체 맨왼쪽위점으로..
	for (int i = 0; i < _sizeY; i++) {
		DrawGraphics::gotoxy(_posX, _posY + i);
		for (int j = 0; j < _sizeX; j++) {
			cout << " ";
		}
		
	}

	DrawGraphics::gotoxy(_posX + (_sizeX - _modelShape.length()) / 2, _posY + _sizeY / 2);
	cout << _modelShape;
	DrawGraphics::setcolor(15, 0);
}
