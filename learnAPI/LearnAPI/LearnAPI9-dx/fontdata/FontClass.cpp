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

	//�Է������� vertextype������ ���� ��ȯ�մϴ�.
	vertexPtr = (VertexType*)vertices;

	//���忡�� ���� ���� ���Ͻʽÿ�.
	numLetters = (int)strlen(sentence);

	//���� �迭�� ���� �ε����� �ʱ�ȭ �մϴ�.
	index = 0;

	float firstdrawX = drawX;

	//���ڸ� �� ���� ���� �׸��ϴ�.
	for (int n = 0; n < numLetters; n++) {
		letter = ((int)sentence[n] - 32);

		//���ڰ� �����̸� 3�ȼ��̻� ���������մϴ�.
		if (letter == 0) {
			drawX = drawX + 3;			
		}
		else {
			//������ ù ��° �ﰢ��
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
			//������ �ι�° �ﰢ��
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

			//������ ũ��� �� �ȼ��� ũ��� ������ x��ġ�� ������Ʈ
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

	//�۲� ���� ���� �����
	_Font = new FontType[95];
	if (!_Font) {
		return false;
	}

	//���� ������ �۲� ũ�� �� ���� �б�
	fin.open(filename);
	if (fin.fail())
		return false;

	//�ؽ�Ʈ�� ���� �ƽ�Ű���� 95���� �н��ϴ�.
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
	
	//���ϴݱ�
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

	//�ؽ�ó ��ü �����
	_TextureC = new TextureClass;
	if (!_TextureC)
		return false;

	//�ؽ�ó ������Ʈ�� �ʱ�ȭ�մϴ�.
	result = _TextureC->Initialize(device, filename);
	if (!result)
		return false;

	return true;
}

void FontClass::ReleaseTexture()
{
	//�ؽ�ó ��ü release
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
