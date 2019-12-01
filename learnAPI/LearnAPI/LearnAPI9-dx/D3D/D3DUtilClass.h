#pragma once
#include "../framework.h"
void OutputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd,const TCHAR* shaderFilename) {
	char* compileErrors;
	unsigned long bufferSize, i;
	ofstream fout;

	//���� �޽����� ��� �ִ� ���ڿ��� ������ �����͸� �����ɴϴ�.
	compileErrors = (char*)(errorMessage->GetBufferPointer());

	//�޽����� ���̸� �����ɴϴ�.
	bufferSize = errorMessage->GetBufferSize();

	//������ ���� �ȿ� �޽����� ����մϴ�.
	fout.open("shader-error.txt");

	//���� �޽����� ���ϴ�.
	for (i = 0; i < bufferSize; i++) {
		fout << compileErrors[i];
	}
	//������ �ݽ��ϴ�.
	fout.close();

	// �����޼����� ��ȯ�մϴ�.
	errorMessage->Release();
	errorMessage = 0;

	//������ ������ ������ �˾� �޽����� �˷��ݴϴ�.
	MessageBox(hwnd, _T("Error compiling shader. Check shader-error.txt for message"), shaderFilename, MB_OK);

	return;
}