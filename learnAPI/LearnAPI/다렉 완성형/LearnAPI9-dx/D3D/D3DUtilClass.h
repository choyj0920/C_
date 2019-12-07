#pragma once
#include "../framework.h"
void OutputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd,const TCHAR* shaderFilename) {
	char* compileErrors;
	unsigned long bufferSize, i;
	ofstream fout;

	//에러 메시지를 담고 있는 문자열의 버퍼의 포인터를 가져옵니다.
	compileErrors = (char*)(errorMessage->GetBufferPointer());

	//메시지의 길이를 가져옵니다.
	bufferSize = errorMessage->GetBufferSize();

	//파일을 열고 안에 메시지를 기록합니다.
	fout.open("shader-error.txt");

	//에러 메시지를 씁니다.
	for (i = 0; i < bufferSize; i++) {
		fout << compileErrors[i];
	}
	//파일을 닫습니다.
	fout.close();

	// 에러메세지를 반환합니다.
	errorMessage->Release();
	errorMessage = 0;

	//컴파일 에러가 있음을 팝업 메시지로 알려줍니다.
	MessageBox(hwnd, _T("Error compiling shader. Check shader-error.txt for message"), shaderFilename, MB_OK);

	return;
}