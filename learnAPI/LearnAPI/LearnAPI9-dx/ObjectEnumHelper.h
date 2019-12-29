#pragma once

enum PlayerAnimationType
{
	ANI_WORK1,
	ANI_WORK2,
	ANI_WORK3,
	ANI_WORK4,
	ANI_MAX
};

typedef struct CharacterFIleInfo {
	TCHAR szFIleName[MAX_PATH];
	float fsizeU;
	float fsizeV;
	int aniMaxCnt[ANI_MAX];

	CharacterFIleInfo() {
		ZeroMemory(szFIleName, sizeof(szFIleName));
		fsizeU = fsizeV = 0.0f;
		memset(aniMaxCnt, 0, sizeof(aniMaxCnt));
	}

}_CHARACTERFILEINFO, * _LPCHARACTERFILEINFO;

