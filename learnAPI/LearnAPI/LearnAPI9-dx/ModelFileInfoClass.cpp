#include "framework.h"



bool ModelFileInfoClass::LoadFile(const TCHAR* filename)
{
	if (_FileInfo == NULL) {
		_FileInfo = new CharacterFIleInfo;
	}

	ifstream fin;
	char input[MAX_PATH] = { 0, };
	char buff[MAX_PATH] = { 0, };
	char data[MAX_PATH] = { 0, };

	// modelinfo 파일을 엽니다.
	fin.open(filename);

	//파일을 열수 없으면 종료.
	if (fin.fail())
		return false;
	while (!fin.getline(input, sizeof(input)).eof()) {
		sscanf_s(input, "%s", buff, MAX_PATH);
		
		if (!_stricmp(buff, "FILENAME")) {
			sscanf_s(input, "%s %s", buff, MAX_PATH, data, MAX_PATH);
			ExtractName(_FileInfo->szFIleName, data);
		}
		
		if (!_stricmp(buff, "SIZE_U")) {
			sscanf_s(input, "%s %f", buff, MAX_PATH, &_FileInfo->fsizeU);
		}

		if (!_stricmp(buff, "SIZE_V")) {
			sscanf_s(input, "%s %f", buff, MAX_PATH, &_FileInfo->fsizeV);
		}

		if (!_stricmp(buff, "ANISTATE_CNT_1")) {
			sscanf_s(input, "%s %d", buff, MAX_PATH, &_FileInfo->aniMaxCnt[0]);
		}
		if (!_stricmp(buff, "ANISTATE_CNT_2")) {
			sscanf_s(input, "%s %d", buff, MAX_PATH, &_FileInfo->aniMaxCnt[1]);
		}
		if (!_stricmp(buff, "ANISTATE_CNT_3")) {
			sscanf_s(input, "%s %d", buff, MAX_PATH, &_FileInfo->aniMaxCnt[2]);
		}
		if (!_stricmp(buff, "ANISTATE_CNT_4")) {
			sscanf_s(input, "%s %d", buff, MAX_PATH, &_FileInfo->aniMaxCnt[3]);
		}
		if (!_stricmp(buff, "ANISTATE_CNT_5")) {
			sscanf_s(input, "%s %d", buff, MAX_PATH, &_FileInfo->aniMaxCnt[4]);
		}
		if (!_stricmp(buff, "ANISTATE_CNT_6")) {
			sscanf_s(input, "%s %d", buff, MAX_PATH, &_FileInfo->aniMaxCnt[5]);
		}		
	}
	fin.close();

	return true;
}

ModelFileInfoClass::ModelFileInfoClass()
{
	_FileInfo = NULL;
}

ModelFileInfoClass::ModelFileInfoClass(const ModelFileInfoClass& copy)
{
}

ModelFileInfoClass::~ModelFileInfoClass()
{
}

bool ModelFileInfoClass::InitializeInfo(const TCHAR* filename)
{
	if (!LoadFile(filename)) {
		return false;
	}
	return true;
}

void ModelFileInfoClass::ReleaseInfo()
{
	//캐릭터파일 인포 객체 해제
	if (_FileInfo != NULL) {
		delete _FileInfo;
		_FileInfo = NULL;
	}
}
