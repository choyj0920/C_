#include "framework.h"

bool TextObjectClass::InitializeSentence(SentenceType** sentence, int maxLength, ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;

	*sentence = new SentenceType;
	if (!*sentence)
		return false;

	//문장의 버퍼를 초기화.
	(*sentence)->vertexBuffer = NULL;
	(*sentence)->indexBuffer = NULL;

	//문장의 최대 길이 설정
	(*sentence)->maxLength = maxLength;

	//정점 배열의 정점 수를 설정
	(*sentence)->vertexCount = 6 * maxLength;
	
	//인덱스 배열의 인덱스 수 설정.
	(*sentence)->indexCount = (*sentence)->vertexCount;
	
	//버텍스 배열 만들기
	vertices = new VertexType[(*sentence)->vertexCount];
	if (!vertices)
		return false;

	//인덱스 배열 만들기.
	indices = new unsigned long[(*sentence)->indexCount];
	if (!indices)
		return false;

	//먼저 정점 배열을 0으로 초기화
	memset(vertices, 0, sizeof(VertexType) * (*sentence)->vertexCount);

	//인덱스 배열 초기화
	for (int i = 0; i < (*sentence)->indexCount; i++) {
		indices[i] = i;
	}

	//동적 정점 버퍼의 설명을 설정
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * (*sentence)->vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	//하위 리소스 구조에 정점데이터에 대한 포인터 부여.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	//버텍스 버퍼 만들기
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &(*sentence)->vertexBuffer);
	if (FAILED(result))
		return false;

	// 정적인덱스 버퍼에 대한 설명 설정.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * (*sentence)->indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	//하위 리소스 구조에 인덱스 데이터에 대한 포인터를 부여
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	//인덱스 버퍼 만들기
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &(*sentence)->indexBuffer);
	if (FAILED(result))
		return false;

	//더 이상 필요 없는 버텍스 배열 해제 
	delete[] vertices;
	vertices = NULL;

	//더 이상 필요 없는 인덱스 배열 해제 
	delete[] indices;
	indices = NULL;


	return true;
}

bool TextObjectClass::UpdateSentence(SentenceType* sentence, const char* text, int positionX, int positionY, float red, float green, float blue, ID3D11DeviceContext* deviceContext)
{
	int numLetters;
	VertexType* vertices;
	float drawX;
	float drawY;
	HRESULT result;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType* verticesPtr;

	//문장의 색을 저장
	sentence->red = red;
	sentence->green = green;
	sentence->blue = blue;

	//문장에서 글자수 체크
	numLetters = (int)strlen(text);

	//가능한 버퍼 오버 플로우 검사
	if (numLetters > sentence->maxLength)
		return false;

	//버텍스 배열 만들기
	vertices = new VertexType[sentence->vertexCount];
	if (!vertices)
		return false;

	//먼저 정점 배열을 0으로 초기화..
	memset(vertices, 0, (sizeof(VertexType) * sentence->vertexCount));

	//그리기를 시작할 화면에서 X및 Y 픽셀 위치를 계산
	drawX = (float)(((_ScreenWidth / 2) * -1) + positionX);
	drawY = (float)((_screenHeight / 2) - positionY);

	//문장 클래스 및 문장 그리기 위치에서 정점 배열을 작성하려면 글꼴 클래스를 사용
	_Font->BuildVertexArray((void*)vertices, text, drawX, drawY);
	
	//버텍스 버퍼를 쓸 수 있도록 잠금.
	result = deviceContext->Map(sentence->vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	//버텍스 버퍼의 데이터에 대한 포인터 가져오기
	verticesPtr = (VertexType*)mappedResource.pData;

	//데이터를 정점 버퍼에 복사.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * sentence->vertexCount));

	//버텍스 버퍼 잠금 해제.
	deviceContext->Unmap(sentence->vertexBuffer, 0);

	//버텍스 배열을 더이상 필요하지 않게 해제
	delete[] vertices;
	vertices = 0;
	

	return true;
}

void TextObjectClass::ReleaseSentence(SentenceType** sentence)
{
	if (*sentence) {
		//문장 버텍스 버퍼 해제
		if ((*sentence)->vertexBuffer) {
			(*sentence)->vertexBuffer->Release();
			(*sentence)->vertexBuffer = 0;
		}
		//문장 색인 버퍼를 해제
		if ((*sentence)->indexBuffer) {
			(*sentence)->indexBuffer->Release();
			(*sentence)->indexBuffer = 0;
		}
		//문장을 해제
		delete* sentence;
		sentence = 0;
	}
}

bool TextObjectClass::RenderSentence(ID3D11DeviceContext* deviceContext, SentenceType* sentence, XMMATRIX worldMatrix, XMMATRIX orthoMatirx)
{
	unsigned int stride, offset;
	XMFLOAT4 pixelColor;
	bool result;
	
	//정점 버퍼 보폭 및 오프셋 설정
	stride = sizeof(VertexType);
	offset = 0;

	//렌더링 할 수 있도록 입력 어셈 블러에서 정점 버퍼를 활성으로 설정.
	deviceContext->IASetVertexBuffers(0, 1, &sentence->vertexBuffer, &stride, &offset);
	//렌더링 될 수 있또록 입력 어셈블러에서 인덱스 버퍼를 활성으로 설정
	deviceContext->IASetIndexBuffer(sentence->indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	//이 정점 버퍼(이경우 삼각형)에서 렌더링 되어야하는 프리미티브 유형을 설정
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//입력 문장 색으로 픽셀 색 버퍼를 만듬.
	pixelColor = XMFLOAT4(sentence->red, sentence->green, sentence->blue, 1.0f);
	//글꼴 셰이더를 사용하여 텍스트 렌더링
	result = _FontShader->Render(deviceContext, sentence->indexCount, worldMatrix, _BaseViewMatrix, orthoMatirx, _Font->GetTexture(), pixelColor);

	if (!result) {
		return false;
	}

	return true;
}


TextObjectClass::TextObjectClass()
{
	_Font = NULL;
	_FontShader = NULL;
	_Sentence1 = NULL;
	_Sentence2 = NULL;
}

TextObjectClass::TextObjectClass(const TextObjectClass& copy)
{
}

TextObjectClass::~TextObjectClass()
{
}

bool TextObjectClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, HWND hwnd, int screenWidth, int screenHeight, XMMATRIX baseViewMatrix)
{
	bool result;

	_ScreenWidth = screenWidth;
	_screenHeight = screenHeight;

	_BaseViewMatrix = baseViewMatrix;

	_Font = new FontClass;
	if (!_Font)
		return false;

	result = _Font->Initialize(device, L"fontdata\\testfontdata.txt", L"fontdata\\testfont.dds");

	if (!result) {
		MessageBox(hwnd, L"Could not initialize the font Object.", L"Error", MB_OK);
		return false;
	}

	_FontShader = new FontShader;
	if (!_FontShader)
		return false;

	result = _FontShader->Initiallize(device, hwnd);
	if (!result) {
		MessageBox(hwnd, L"폰트 쉐이터객체 초기화 실패..", L"Error", MB_OK);
		return false;
	}

	//첫번째 문장 초기화
	result = InitializeSentence(&_Sentence1, 20, device);
	if (!result)
		return false;
	// 문장 정점 버퍼를 새로운 문자열 정보로 업데이트.
	result = UpdateSentence(_Sentence1, "Final Fantasy III", 10, 10, 1.0f, 1.0f, 1.0f, deviceContext);
	if (!result)
		return false;

	//두번쨰 문장 초기화
	result = InitializeSentence(&_Sentence2, 20, device);
	if (!result)
		return false;
	// 문장 정점 버퍼를 새로운 문자열 정보로 업데이트.
	result = UpdateSentence(_Sentence2, "Vivi", 10, 580, 0.0f, 1.0f, 0.0f, deviceContext);
	if (!result)
		return false;


	return true;
}

void TextObjectClass::Release()
{
	//두 문장 해제
	ReleaseSentence(&_Sentence1);
	ReleaseSentence(&_Sentence2);

	//글꼴 쉐이더 객체 해제
	if (_FontShader) {
		_FontShader->Release();
		delete _FontShader;
		_FontShader = NULL;
	}

	//글꼴 객체 해제
	if (_Font) {
		_Font->Release();
		delete _Font;
		_Font = NULL;
	}


}

bool TextObjectClass::Render(ID3D11DeviceContext* deviceContext, XMMATRIX worldMatrix, XMMATRIX orthoMatirx)
{
	bool result;

	result = RenderSentence(deviceContext, _Sentence1, worldMatrix, orthoMatirx);
	if (!result)
		return false;

	result = RenderSentence(deviceContext, _Sentence2, worldMatrix, orthoMatirx);
	if (!result)
		return false;

	return true;
}
