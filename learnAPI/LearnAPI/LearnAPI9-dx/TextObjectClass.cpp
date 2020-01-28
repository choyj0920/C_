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

	//������ ���۸� �ʱ�ȭ.
	(*sentence)->vertexBuffer = NULL;
	(*sentence)->indexBuffer = NULL;

	//������ �ִ� ���� ����
	(*sentence)->maxLength = maxLength;

	//���� �迭�� ���� ���� ����
	(*sentence)->vertexCount = 6 * maxLength;
	
	//�ε��� �迭�� �ε��� �� ����.
	(*sentence)->indexCount = (*sentence)->vertexCount;
	
	//���ؽ� �迭 �����
	vertices = new VertexType[(*sentence)->vertexCount];
	if (!vertices)
		return false;

	//�ε��� �迭 �����.
	indices = new unsigned long[(*sentence)->indexCount];
	if (!indices)
		return false;

	//���� ���� �迭�� 0���� �ʱ�ȭ
	memset(vertices, 0, sizeof(VertexType) * (*sentence)->vertexCount);

	//�ε��� �迭 �ʱ�ȭ
	for (int i = 0; i < (*sentence)->indexCount; i++) {
		indices[i] = i;
	}

	//���� ���� ������ ������ ����
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * (*sentence)->vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	//���� ���ҽ� ������ ���������Ϳ� ���� ������ �ο�.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	//���ؽ� ���� �����
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &(*sentence)->vertexBuffer);
	if (FAILED(result))
		return false;

	// �����ε��� ���ۿ� ���� ���� ����.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * (*sentence)->indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	//���� ���ҽ� ������ �ε��� �����Ϳ� ���� �����͸� �ο�
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	//�ε��� ���� �����
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &(*sentence)->indexBuffer);
	if (FAILED(result))
		return false;

	//�� �̻� �ʿ� ���� ���ؽ� �迭 ���� 
	delete[] vertices;
	vertices = NULL;

	//�� �̻� �ʿ� ���� �ε��� �迭 ���� 
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

	//������ ���� ����
	sentence->red = red;
	sentence->green = green;
	sentence->blue = blue;

	//���忡�� ���ڼ� üũ
	numLetters = (int)strlen(text);

	//������ ���� ���� �÷ο� �˻�
	if (numLetters > sentence->maxLength)
		return false;

	//���ؽ� �迭 �����
	vertices = new VertexType[sentence->vertexCount];
	if (!vertices)
		return false;

	//���� ���� �迭�� 0���� �ʱ�ȭ..
	memset(vertices, 0, (sizeof(VertexType) * sentence->vertexCount));

	//�׸��⸦ ������ ȭ�鿡�� X�� Y �ȼ� ��ġ�� ���
	drawX = (float)(((_ScreenWidth / 2) * -1) + positionX);
	drawY = (float)((_screenHeight / 2) - positionY);

	//���� Ŭ���� �� ���� �׸��� ��ġ���� ���� �迭�� �ۼ��Ϸ��� �۲� Ŭ������ ���
	_Font->BuildVertexArray((void*)vertices, text, drawX, drawY);
	
	//���ؽ� ���۸� �� �� �ֵ��� ���.
	result = deviceContext->Map(sentence->vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	//���ؽ� ������ �����Ϳ� ���� ������ ��������
	verticesPtr = (VertexType*)mappedResource.pData;

	//�����͸� ���� ���ۿ� ����.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * sentence->vertexCount));

	//���ؽ� ���� ��� ����.
	deviceContext->Unmap(sentence->vertexBuffer, 0);

	//���ؽ� �迭�� ���̻� �ʿ����� �ʰ� ����
	delete[] vertices;
	vertices = 0;
	

	return true;
}

void TextObjectClass::ReleaseSentence(SentenceType** sentence)
{
	if (*sentence) {
		//���� ���ؽ� ���� ����
		if ((*sentence)->vertexBuffer) {
			(*sentence)->vertexBuffer->Release();
			(*sentence)->vertexBuffer = 0;
		}
		//���� ���� ���۸� ����
		if ((*sentence)->indexBuffer) {
			(*sentence)->indexBuffer->Release();
			(*sentence)->indexBuffer = 0;
		}
		//������ ����
		delete* sentence;
		sentence = 0;
	}
}

bool TextObjectClass::RenderSentence(ID3D11DeviceContext* deviceContext, SentenceType* sentence, XMMATRIX worldMatrix, XMMATRIX orthoMatirx)
{
	unsigned int stride, offset;
	XMFLOAT4 pixelColor;
	bool result;
	
	//���� ���� ���� �� ������ ����
	stride = sizeof(VertexType);
	offset = 0;

	//������ �� �� �ֵ��� �Է� ��� ������ ���� ���۸� Ȱ������ ����.
	deviceContext->IASetVertexBuffers(0, 1, &sentence->vertexBuffer, &stride, &offset);
	//������ �� �� �ֶǷ� �Է� ��������� �ε��� ���۸� Ȱ������ ����
	deviceContext->IASetIndexBuffer(sentence->indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	//�� ���� ����(�̰�� �ﰢ��)���� ������ �Ǿ���ϴ� ������Ƽ�� ������ ����
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//�Է� ���� ������ �ȼ� �� ���۸� ����.
	pixelColor = XMFLOAT4(sentence->red, sentence->green, sentence->blue, 1.0f);
	//�۲� ���̴��� ����Ͽ� �ؽ�Ʈ ������
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
		MessageBox(hwnd, L"��Ʈ �����Ͱ�ü �ʱ�ȭ ����..", L"Error", MB_OK);
		return false;
	}

	//ù��° ���� �ʱ�ȭ
	result = InitializeSentence(&_Sentence1, 20, device);
	if (!result)
		return false;
	// ���� ���� ���۸� ���ο� ���ڿ� ������ ������Ʈ.
	result = UpdateSentence(_Sentence1, "Final Fantasy III", 10, 10, 1.0f, 1.0f, 1.0f, deviceContext);
	if (!result)
		return false;

	//�ι��� ���� �ʱ�ȭ
	result = InitializeSentence(&_Sentence2, 20, device);
	if (!result)
		return false;
	// ���� ���� ���۸� ���ο� ���ڿ� ������ ������Ʈ.
	result = UpdateSentence(_Sentence2, "Vivi", 10, 580, 0.0f, 1.0f, 0.0f, deviceContext);
	if (!result)
		return false;


	return true;
}

void TextObjectClass::Release()
{
	//�� ���� ����
	ReleaseSentence(&_Sentence1);
	ReleaseSentence(&_Sentence2);

	//�۲� ���̴� ��ü ����
	if (_FontShader) {
		_FontShader->Release();
		delete _FontShader;
		_FontShader = NULL;
	}

	//�۲� ��ü ����
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
