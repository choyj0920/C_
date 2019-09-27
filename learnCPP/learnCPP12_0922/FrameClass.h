#pragma once
class FrameClass
{
	int _frameColor;
	int _frameBGColor;
public:
	FrameClass(int color,int bgcolor);
	~FrameClass();

	void DrawFrame();
	void Drawboard();
};

