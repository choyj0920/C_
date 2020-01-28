#include "framework.h"

bool Mal_with_text::rightwork = true;


Mal_with_text::Mal_with_text()
{
	_posX = -8;
	_posY = 2;
	_MoveSpeed = 5.0f;
	_posU = 0;
	_posV = 0;
	_sizeU = 0;
	_sizeV = 0;
	_CheckTime = 0.0f;
	_ani_count = 0;
	_AniType = ANI_WORK2;
	rightwork = true;
	_Model = NULL;

	target = NULL;

	_Font = NULL;
	_FontShader = NULL;
	_Sentence1 = NULL;
}

Mal_with_text::Mal_with_text(const Mal_with_text& copy)
{
}

Mal_with_text::~Mal_with_text()
{
}

void Mal_with_text::setPos(float& posU, float& posV, int index)
{
	int i = 1 / _sizeU;
	posU = index % i;

	posV = index / i;
	return;
}

bool Mal_with_text::Initialize(HWND _hwnd, ID3D11Device* device, ID3D11DeviceContext* deviceContext,
	int screenx, int screeny, int bitx, int bity, const TCHAR* filepath,int textscreenW,int textscreenH, XMMATRIX baseViewMatrix)
{
	bool result;
	_Model = new SpriteClass;
	if (!_Model)
		return false;

	InitializeInfo(filepath);

	_sizeU = _FileInfo->fsizeU;
	_sizeV = _FileInfo->fsizeV;

	_ani_count = _FileInfo->aniMaxCnt[_AniType];
	setPos(_posU, _posV, _ani_count);

	target = new enermyObject;

	target->Initialize(_hwnd, device, screenx, screeny, 2, 2);


	result = _Model->Initialize(device, screenx, screeny, _FileInfo->szFIleName, bitx, bity);
	if (!result) {
		MessageBox(_hwnd, _T("�ؽ��� �ʱ�ȭ ����..����"), _T("Error"), MB_OK);
		return false;
	}

	// �ؽ�Ʈ �̴ϼ� ������
	_ScreenWidth = screenx;
	_screenHeight = screeny;

	_BaseViewMatrix = baseViewMatrix;

	_Font = new FontClass;
	if (!_Font)
		return false;

	result = _Font->Initialize(device, L"fontdata\\testfontdata.txt", L"fontdata\\testfont.dds");

	if (!result) {
		MessageBox(_hwnd, L"Could not initialize the font Object.", L"Error", MB_OK);
		return false;
	}

	_FontShader = new FontShader;
	if (!_FontShader)
		return false;

	result = _FontShader->Initiallize(device, _hwnd);
	if (!result) {
		MessageBox(_hwnd, L"��Ʈ �����Ͱ�ü �ʱ�ȭ ����..", L"Error", MB_OK);
		return false;
	}

	//ù��° ���� �ʱ�ȭ
	result = InitializeSentence(&_Sentence1, 20, device);
	if (!result)
		return false;
	// ���� ���� ���۸� ���ο� ���ڿ� ������ ������Ʈ.
	result = UpdateSentence(_Sentence1, "Mal~", (5 + _posX) * 70, (2.5 - _posY) * 70, 1.0f, 1.0f, 1.0f, deviceContext);


	if (!result)
		return false;

	return true;
}

void Mal_with_text::Release()
{
	if (_Model) {
		_Model->Release();
		delete _Model;
		_Model = 0;
	}

	ReleaseSentence(&_Sentence1);

	if (target) {
		target->Release();
		delete target;
		target = NULL;
	}

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
bool isNULL(SpriteObjectClass* pp) {
	bool isout = pp->isoutboundry();
	if (isout) {
		pp->Release();
		delete pp;
	}
	return isout;

}

bool Mal_with_text::Process(float deltatime, float mx, float my, ID3D11DeviceContext* deviceContext)
{
	if (mx > 0) {
		rightwork = true;
	}
	else if (mx < 0)
		rightwork = false;

	double dis = (mx * mx) + (my * my);
	dis = sqrt(dis);
	if (dis != 0) {
		_posX += mx / dis * deltatime * _MoveSpeed;
		_posY += my / dis * deltatime * _MoveSpeed;
		
		bool result;
		result = UpdateSentence(_Sentence1, "moving Mal~", (5+_posX)*70, (2.5-_posY)*70, 1.0f, 1.0f, 1.0f, deviceContext);
		if (!result)
			return false;
	}
	bool havenull = false;
	for (SpriteObjectClass* soc : catshot) {
		if (soc != nullptr) {
			soc->Process(deltatime);
			if (target != NULL) {
				if (target->istriger(soc)) {
					target->isupspeed();
					/*target->Release();
					delete target;
					target = NULL;*/
					soc->Release();
					delete soc;
					catshot.remove(soc);
					break;
				}
			}
		}
	}
	if (target != NULL) {
		target->Process(deltatime);
	}
	catshot.remove_if(isNULL);
	_CheckTime += deltatime;
	
	if (_CheckTime >= 0.1f) {
		_CheckTime = 0;
		_ani_count++;
		if (_ani_count >= _FileInfo->aniMaxCnt[_AniType + 1]) {
			_ani_count = _FileInfo->aniMaxCnt[_AniType];
		}
		setPos(_posU, _posV, _ani_count);

	}
	return true;
}

bool Mal_with_text::Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, XMMATRIX textorthoM, TextureShader* pTexShader)
{
	if (!_Model->Render(deviceContext, _posX, _posY, _sizeU, _sizeV, _posU * _sizeU, _posV * _sizeV)) {
		return false;
	}

	if (!pTexShader->Render(deviceContext, _Model->GetIndexCount(),
		world, view, orthoM, _Model->GetTexture())) {
		return false;
	}
	if (target != NULL)
		target->Render(deviceContext, world, view, orthoM, pTexShader);

	bool result;

	result = RenderSentence(deviceContext, _Sentence1, world, textorthoM);
	if (!result)
		return false;
	for (SpriteObjectClass* soc : catshot) {
		if (soc != nullptr) {
			soc->Render(deviceContext, world, view, orthoM, pTexShader);
		}
	}

	return true;
}

void Mal_with_text::shotcat(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity)
{
	if (catshot.size() > 5)
		return;

	SpriteObjectClass* cat = new SpriteObjectClass();
	cat->Initialize(_hwnd, device, screenx, screeny, bitx, bity, _posX+(rightwork?1:-1)*2, _posY, rightwork);
	catshot.push_back(cat);
	
}

bool Mal_with_text::InitializeSentence(SentenceType** sentence, int maxLength, ID3D11Device* device)
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

bool Mal_with_text::UpdateSentence(SentenceType* sentence, const char* text, int positionX, int positionY, float red, float green, float blue, ID3D11DeviceContext* deviceContext)
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
	drawY = (float)((_screenHeight / 2) - positionY) - 3;

	//���� Ŭ���� �� ���� �׸��� ��ġ���� ���� �迭�� �ۼ��Ϸ��� �۲� Ŭ������ ���
	_Font->BuildVertexArray((void*)vertices, text, drawX, drawY);

	//drawX = (float)(((_ScreenWidth / 2) * -1) + positionX) - (_Font->getsizeX() / 2);
	//_Font->BuildVertexArray((void*)vertices, text, drawX, drawY);

	

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

void Mal_with_text::ReleaseSentence(SentenceType** sentence)
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

bool Mal_with_text::RenderSentence(ID3D11DeviceContext* deviceContext, SentenceType* sentence, XMMATRIX worldMatrix, XMMATRIX orthoMatirx)
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
