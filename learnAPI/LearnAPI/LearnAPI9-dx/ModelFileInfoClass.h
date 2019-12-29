#pragma once

void ExtractName(TCHAR* pOut, char* pIn);

class ModelFileInfoClass
{
private:
	bool LoadFile(const TCHAR*);
protected:
	CharacterFIleInfo* _FileInfo;
public:
	
	ModelFileInfoClass();
	ModelFileInfoClass(const ModelFileInfoClass& copy);
	~ModelFileInfoClass();

	bool InitializeInfo(const TCHAR* filename);
	void ReleaseInfo();

	
};

