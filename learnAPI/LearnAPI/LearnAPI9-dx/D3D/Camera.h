#pragma once
class Camera
{
	float _PositionX;
	float _PositionY;
	float _PositionZ;
	float _RotationX;
	float _RotationY;
	float _RotationZ;
	XMMATRIX _ViewMatix;

public:
	Camera();
	Camera(const Camera& copy);
	~Camera();

	void SetPosition(float X, float Y, float Z);
	void SetRotation(float X, float Y, float Z);

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetRotation();

	void Render();
	void GetViewMatrix(XMMATRIX&);
};

