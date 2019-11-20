#include "framework.h"
#include "ImageDraw.h"

ImageDraw::ImageDraw()
{
	GdiplusStartupInput gdiplusStartupInput;
	
	GdiplusStartup(&_gdiplustoken, &gdiplusStartupInput, NULL);

	
}

ImageDraw::~ImageDraw()
{
	GdiplusShutdown(_gdiplustoken);
}

void ImageDraw::TestDrawImage(HDC hdc,const TCHAR* szName, int x, int y)
{
	Graphics grapics(hdc);
	Image img(szName);
	grapics.DrawImage(&img, x, y);
}
