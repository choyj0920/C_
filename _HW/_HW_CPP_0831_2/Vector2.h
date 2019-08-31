#pragma once
class Vector2
{
	float x;
	float y;
public:
	Vector2();
	Vector2(float x, float y);
	void setVector2(float x, float y);
	void showinfo();
	Vector2 operator+(Vector2 &ref);
	Vector2 operator-(Vector2 &ref);
	Vector2 operator*(float);
	float Distance();
	Vector2 Normalize();
	~Vector2();
};

