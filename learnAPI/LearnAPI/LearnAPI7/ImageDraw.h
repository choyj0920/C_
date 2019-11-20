#pragma once
class ImageDraw
{
private:
	ULONG_PTR _gdiplustoken;

public:
	ImageDraw();
	
	~ImageDraw();

	void TestDrawImage(HDC hdc,const TCHAR* szName, int x, int y);
};

