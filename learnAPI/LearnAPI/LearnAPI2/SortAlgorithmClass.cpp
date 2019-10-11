#include "stdafx.h"
#include "SortAlgorithmClass.h"


SortAlgorithmClass::SortAlgorithmClass()
{
	memset(arr, 0, sizeof(arr));
}


SortAlgorithmClass::~SortAlgorithmClass()
{
}

void SortAlgorithmClass::InitArrrayData()
{
	for (int i = 0; i < 6; i++) {
		arr[i] = rand() %100+1;
		for (int j = 0; j < i; j++)
			if (arr[j] == arr[i]) {
				i--;
				break;
			}
	}
}

void SortAlgorithmClass::ShowArray(HDC hdc, RECT pos)
{
	TCHAR str2[MAX_PATH] = { 0, };
	memset(str2, 0, MAX_PATH);
	swprintf_s(str2, MAX_PATH, L"[%d ", arr[0]);
	for (int i = 1; i < 6; i++)
		swprintf_s(str2,MAX_PATH,L"%s, %d", str2, arr[i]);
	swprintf_s(str2, MAX_PATH, L"%s]", str2);

	TextOut(hdc, pos.left, pos.top, str2, lstrlen(str2));
	
}

void SortAlgorithmClass::SelectedSort(HDC hdc, RECT pos)
{
	ShowArray(hdc, pos);
	for (int i = 0; i < 6 - 1; i++) {
		for (int j = i; j < 6; j++) 
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				pos.top += 20;
				ShowArray(hdc, pos);
			}
		
	}

}
