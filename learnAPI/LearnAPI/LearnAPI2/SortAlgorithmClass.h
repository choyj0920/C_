#pragma once
class SortAlgorithmClass
{
	int arr[6];
	HDC hdc;
	RECT pos;
public:
	SortAlgorithmClass();
	~SortAlgorithmClass();
	
	void InitArrrayData();
	void ShowArray(HDC hdc, RECT pos, int first = 0, int last = 5);

public:
	void SelectedSort(HDC hdc, RECT pos,bool isAcending=true);
	void InsertionSort(HDC hdc, RECT pos, bool isAcending = true);
	void BubbleSort(HDC hdc, RECT pos, bool isAcending = true);
	void MergeSort(HDC hdc, RECT pos, bool isAcending = true);
	void Merge(int first, int _final);
	void Merge__sort(int first, int middle, int _final);
};

