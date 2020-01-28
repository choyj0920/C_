#include "../framework.h"

bool FontClass::Initialize(ID3D11Device* device, const TCHAR* fontFilename, const TCHAR* textureFilename)
{
	bool result;
	result = LoadFontData(fontFilename);
	if (!result) {
		return false;
	}

	result = LoadTexture(device, textureFilename);

	if (!result) {
		return false;
	}
	return true;
}

void FontClass::Release()
{
	ReleaseTexture();
	
	ReleaseFontData();
}

ID3D11ShaderResourceView* FontClass::GetTexture()
{
	return _TextureC->GetTexture();
}

void FontClass::BuildVertexArray(void* vertices, const char* sentence, float drawX, float drawY)
{
	VertexType* vertexPtr;
	int numLetters, index, letter;

	//입력정점을 vertextype구조로 강제 변환합니다.
	vertexPtr = (VertexType*)vertices;

	//문장에서 글자 수를 구하십시오.
	numLetters = (int)strlen(sentence);

	//정점 배열에 대한 인덱스를 초기화 합니다.
	index = 0;

	float firstdrawX = drawX;

	//글자를 각 쿼드 위에 그립니다.
	for (int n = 0; n < numLetters; n++) {
		letter = ((int)sentence[n] - 32);

		//글자가 공백이면 3픽셀이상 움직여야합니다.
		if (letter == 0) {
			drawX = drawX + 3;			
		}
		else {
			//쿼드의 첫 번째 삼각형
			//Topleft
			vertexPtr[index].position
				= XMFLOAT3(drawX, drawY, 0.0f);
			vertexPtr[index].texture = XMFLOAT2(_Font[letter].left, 0.0f);
			index++;
			//bottom right
			vertexPtr[index].position
				= XMFLOAT3((drawX+_Font[letter].size), drawY-16, 0.0f);
			vertexPtr[index].texture = XMFLOAT2(_Font[letter].right, 1.0f);
			index++;
			//bottom left
			vertexPtr[index].position
				= XMFLOAT3(drawX , drawY - 16, 0.0f);
			vertexPtr[index].texture = XMFLOAT2(_Font[letter].left, 1.0f);
			index++;
			//쿼드의 두번째 삼각형
			//Top left
			vertexPtr[index].position
				= XMFLOAT3(drawX, drawY, 0.0f);
			vertexPtr[index].texture = XMFLOAT2(_Font[letter].left, 0.0f);
			index++;
			//Top right
			vertexPtr[index].position
				= XMFLOAT3((drawX + _Font[letter].size), drawY, 0.0f);
			vertexPtr[index].texture = XMFLOAT2(_Font[letter].right, 0.0f);
			index++;
			// Bottom rigth
			vertexPtr[index].position
				= XMFLOAT3((drawX + _Font[letter].size), drawY - 16, 0.0f);
			vertexPtr[index].texture = XMFLOAT2(_Font[letter].right, 1.0f);
			index++;

			//문자의 크기와 한 픽셀의 크기로 도면의 x위치를 업데이트
			drawX = drawX + _Font[letter].size + 1.0f;
		}

	}
	sizeX = drawX - firstdrawX;
}

bool FontClass::LoadFontData(const TCHAR* filename)
{
	ifstream fin;
	int i;
	char temp;

	//글꼴 간격 버퍼 만들기
	_Font = new FontType[95];
	if (!_Font) {
		return false;
	}

	//문자 사이의 글꼴 크기 및 간격 읽기
	fin.open(filename);
	if (fin.fail())
		return false;

	//텍스트에 사용된 아스키문자 95개를 읽습니다.
	for (int i = 0; i < 95; i++) {
		fin.get(temp);
		while (temp!=' ')
		{
			fin.get(temp);
		}
		fin.get(temp);
		while (temp != ' ') {
			fin.get(temp);
		}
		fin >> _Font[i].left;
		fin >> _Font[i].right;
		fin >> _Font[i].size;
	}
	
	//파일닫기
	fin.close();

	return true;
}

void FontClass::ReleaseFontData()
{
	if (_Font) {
		delete[] _Font;
		_Font = NULL;
	}
}

bool FontClass::LoadTexture(ID3D11Device* device, const TCHAR* filename)
{
	bool result;

	//텍스처 객체 만들기
	_TextureC = new TextureClass;
	if (!_TextureC)
		return false;

	//텍스처 오브젝트를 초기화합니다.
	result = _TextureC->Initialize(device, filename);
	if (!result)
		return false;

	return true;
}

void FontClass::ReleaseTexture()
{
	//텍스처 객체 release
	if (_TextureC) {
		_TextureC->Release();
		delete _TextureC;
		_TextureC = NULL;
	}
}

FontClass::FontClass()
{
	_Font = NULL;
	_TextureC = NULL;
}

FontClass::FontClass(const FontClass& copy)
{
}

FontClass::~FontClass()
{
}

float FontClass::getsizeX()
{
	return sizeX;
}

float FontClass::getsizeY()
{
	return sizeY;
}
