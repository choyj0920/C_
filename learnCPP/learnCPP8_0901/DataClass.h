#pragma once
template<typename T>
class DataClass
{private:
	T * _dataC;
	int _count;
public:
	/*DataClass(T dataC) :_dataC(dataC) {
	}*/
	DataClass(int count);
	void ShowInfo() {
		for (int i = 0; i < _count; i++) {
			cout << _dataC[i] << endl;
		}
	}
	~DataClass();
};

template<typename T>
inline DataClass<T>::DataClass(int count)
{
	_count = count;
	_dataC = new T[count];
	for (int i = 0; i < _count; i++) {
		_dataC[i] = (T)((float)(rand() % 12800) / 100);
	}
}

template<typename T>
inline DataClass<T>::~DataClass()
{
	if (_dataC) {
		delete[] _dataC;
		_dataC = NULL;
	}
}
