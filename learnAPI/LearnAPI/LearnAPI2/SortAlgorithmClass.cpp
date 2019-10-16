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

void SortAlgorithmClass::ShowArray(HDC hdc, RECT pos,int first,int last)
{
	TCHAR str2[MAX_PATH] = { 0, }; //TCHAR는 가변으로 정의 되있어 유니코드, ㅇㅇ 다 쓸수 있음
	memset(str2, 0, MAX_PATH);
	swprintf_s(str2, MAX_PATH, L"[%d", arr[first]);
	for (int i = first + 1; i <= last; i++)
		swprintf_s(str2,MAX_PATH,L"%s, %d", str2, arr[i]);
	swprintf_s(str2, MAX_PATH, L"%s]", str2);

	TextOut(hdc, pos.left, pos.top, str2, lstrlen(str2));
	
}

void SortAlgorithmClass::SelectedSort(HDC hdc, RECT pos,bool isAcending)
{
	ShowArray(hdc, pos);
	for (int i = 0; i < 6 - 1; i++) {
		for (int j = i; j < 6; j++) {
			if (isAcending) {
				if (arr[j] < arr[i]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					pos.top += 20;
					ShowArray(hdc, pos);
				}
			}
			else {
				if (arr[j] > arr[i]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					pos.top += 20;
					ShowArray(hdc, pos);
				}
			}

		}
	}

}

void SortAlgorithmClass::InsertionSort(HDC hdc, RECT pos, bool isAcending)
{
	int size = sizeof(arr) / sizeof(int);
	ShowArray(hdc, pos);
	for (int i = 1; i < size; i++) {
		int key = arr[i], j; 
		for (j = i-1; j >= 0; j--) {
			if (isAcending) 
				if (arr[j] > key) 
					arr[j + 1] = arr[j];
				else
					break;
			
			else
				if (arr[j] < key)
					arr[j + 1] = arr[j];
				else
					break;
				
		}
		arr[j + 1] = key;
		
		pos.top += 20;
		ShowArray(hdc, pos);
	}



}

void SortAlgorithmClass::BubbleSort(HDC hdc, RECT pos, bool isAcending)
{
	int size = sizeof(arr) / sizeof(int);
	ShowArray(hdc, pos);
	for (int i = size; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (isAcending) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j+1] = temp;
					pos.top += 20;
					ShowArray(hdc, pos);
				}
			}
			else {
				if (arr[j] < arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					pos.top += 20;
					ShowArray(hdc, pos);
				}
			}
		}
	}
}

void SortAlgorithmClass::MergeSort(HDC hdc, RECT pos, bool isAcending)
{
	int size = sizeof(arr) / sizeof(int);
	this->hdc = hdc, this->pos = pos;
	ShowArray(hdc, pos);
	Merge(0, 5);
}

void SortAlgorithmClass::Merge(int first, int _final) {
	int n; //n 중간 인덱스
	if (first < _final) { //반갈라서 찾기
		n = (first + _final) / 2;
		Merge(first, n);
		Merge(n + 1, _final);
		pos.top += 20;
		ShowArray(hdc, pos, first,n);
		pos.left += 30*(n-first+1);
		ShowArray(hdc, pos, n+1, _final);
		pos.left -= 30 * (n - first + 1);
		Merge__sort(first, n, _final);
		pos.top += 20;
		ShowArray(hdc, pos, first, _final);
	}
}

void SortAlgorithmClass::Merge__sort(int first, int middle, int _final)
{
	//arr[i]~arr[middle] 와 arr[middle+1]~ arr[_final]비교
	int i  = first,k= first, j = middle +1;
	int temp[8]; 
	while (i <= middle && j <= _final) {
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= middle) temp[k++] = arr[i++]; //나머지 담기
	while (j <= _final) temp[k++] = arr[j++];
	for (int a = first; a <= _final; a++) arr[a] = temp[a]; //실제 값 저장
	
}

