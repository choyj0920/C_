#include "../framework.h"
#include "Camera.h"

Camera::Camera()
{
	_PositionX = 0.0f;
	_PositionY = 0.0f;
	_PositionZ = 0.0f;
	_RotationX = 0.0f;
	_RotationY = 0.0f;
	_RotationZ = 0.0f;
}

Camera::Camera(const Camera& copy)
{
}

Camera::~Camera()
{
}

void Camera::SetPosition(float X, float Y, float Z)
{
	_PositionX = X;
	_PositionY = Y;
	_PositionZ = Z;
}

void Camera::SetRotation(float X, float Y, float Z)
{
	_RotationX = X;
	_RotationY = Y;
	_RotationZ = Z;
}

XMFLOAT3 Camera::GetPosition()
{
	return XMFLOAT3(_PositionX,_PositionY,_PositionZ);
}

XMFLOAT3 Camera::GetRotation()
{
	return XMFLOAT3(_RotationX, _RotationY, _RotationZ);
}



void Camera::GetViewMatrix(XMMATRIX& viewMatrix)
{
	viewMatrix = _ViewMatix;
}

void Camera::Render()
{
	XMFLOAT3 up;
	XMFLOAT3 position;
	XMFLOAT3 lookAt;

	float yaw;
	float pitch;
	float roll;
	
	XMMATRIX rotationMatrix;

	//������ ����Ű�� ���͸� ����

	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	//���忡�� ī�޶� ��ġ ����
	position.x = _PositionX;
	position.y = _PositionY;
	position.z = _PositionZ;

	//�⺻������ ī�޶� �ٶ󺸴� ���� ����
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	//yaw(y��) pitch(x��),�� roll(z��)ȸ���� ���� ������ �����մϴ�.
	pitch = _RotationX * 0.0174532925f;
	yaw = _RotationY * 0.0174532925f;
	roll = _RotationZ * 0.0174532925f;

	//yaw,pitch,roll ������ ȸ�� ����� ����ϴ�.
	rotationMatrix = XMMatrixRotationRollPitchYaw(yaw, pitch, roll);

	// lookAt �� up���͸� ȸ�� ��ķ� ��ȯ�Ͽ� �䰡 �������� ȸ��.
	XMVECTOR LOOKat, UP, POSItion;
	LOOKat = XMVector3TransformCoord(XMLoadFloat3(&lookAt), rotationMatrix);
	UP = XMVector3TransformCoord(XMLoadFloat3(&up), rotationMatrix);
	POSItion = XMLoadFloat3(&position);

	//ȸ���� ī�޶� ��ġ�� ��� ��ġ�� ��ȯ
	LOOKat = XMVectorAdd(POSItion, LOOKat);

	//���������� ������Ʈ�� �� ���ͷ� ���� ������� ����
	_ViewMatix = XMMatrixLookAtLH(POSItion, LOOKat, UP);


}