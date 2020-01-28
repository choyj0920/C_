# 0905- CPP -기본 입출력

## 출력하기 : cout

표준 공간(std)에 정의 되어 있는 cout 사용

```c++
#include <iostream>
int main(void)
{
std::cout<<"Hello World!!"<<std::endl;
std::cout<<"Hello "<<"World!!"<<std::endl;
std::cout<<1<<'a'<<"String"<<std::endl;
return 0;
}

std::cout<<출력대상;

```

__#include <> 위치

C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\include namespace

##### -이름 공간- 공간에 이름을 주는 행위 

```c++
#include <iostream>
void function(void)
{
std::cout<<“A에서 정의한 함수"<<std::endl;
}
void function(void)
{
std::cout<<“B에서 정의한 함수"<<std::endl;
}
int main(void)
{
function(); //어떤 fuction()을 실행해야 할지 모름 -오류
return 0;
}

```

```c++
#include <iostream>
namespace A_COM {
void function(void)
{
std::cout<<“A에서 정의한 함수"<<std::endl;
}
}
// B_COM도 동일 한 형태로 선언
int main(void)
{
A_COM::function();
B_COM::function();
return 0;
}
```

### :: 범위 지정 연산자 기반 전역 변수접근

```c++
int val=100;
int main(void)
{
int val=100;
val+=1;
return 0;
}


//:: 사용
int val=100;
int main(void)
{
int val=100;
::val+=1;
return 0;
```

## using 구문 

```c++
#include <iostream>
namespace A_COM {
void function(void)
{
std::cout<<“A에서 정의한 함수"<<std::endl;
}
}
// B_COM도 동일 한 형태로 선언
using A_COM::function;
int main(void)
{
function();
B::function();
return 0;
}

```



```c++
#include <iostream>
using namespace std;  //std 를 생략하기 위해 
int main(void)
{
cout<<"Hello World!!"<<std::endl;
cout<<"Hello "<<"World!!"<<std::endl;
cout<<1<<'a'<<"String"<<std::endl;
return 0;
}
```

##  	

 헤더 파일 추가
– setw : 필드의 폭을 설정
– setfill : 공백을 특정 문자로 지정
– setprecision : 소수점 이하 자리수 지정
– left,right : 왼쪽,오른쪽 정렬
– showpoint : 0 포함 소수점 출력
– oct, hex : 8, 16진수 출력

### 문자열 &문자 

"*" 문자열

'*' 문자 

 C에서 printf의 포맷팅 문자열 사용
– E.g., “%6d”
• setw: 오른쪽 정렬된 출력 폭(width) 지정

```c++
for (int i = 1; i <= 1000; i *= 10 )
cout << setw( 6 ) << i << endl;
```

– setw는 그 효과가 1회에 그친다.

```c++
cout << setw( 6 );
for (int i = 1; i <= 1000; i *= 10 )
cout << i << endl;
```





## 문자열 입력  소문자 string

#### 공백 포함 문자열 getline(cin, string--)

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
string mystr;
cout << "What's your name? ";
getline(cin, mystr);
cout << "Hello " << mystr << ".\n";
cout << "What is your favorite team? ";
getline(cin, mystr);
cout << "I like " << mystr << " too!\n";
return 0;
}
```

# 0910

공백 포함 문자열 

getline(cin,string aa);

## 문자열 숫자값으로 변환 (stringstream)

```c++
int main(){
    string mystr;
	float price =0;
	int quantity =0;
	cout <<"Enter price :";
	getline(cin,mystr);
	stringstream(mystr)>>price;
	cout<<"Enter quantity: ";
	getline(cin, mystr);
	stringstream(mystr)>>quantity;
	cout<<"total price : "<< price *quantity<<endl;
}
```

## 변수와 상수

변수: 저장된 값의 변경이 가능한 공간

상수: 선언하면서 초기화를 꼭 해야하며 변경 불가

## 자료형의 종류



## 변수형 결정 (auto /decltype)

```c++
int foo =0;
auto bar =foo;  //sampe int bar =foo;

int foo =0;
decltype(foo) bar; // same int bar;
```

## 문자열 타입

문자열의 비교는 == 연산자로 가능

s1 == s2

### 리터럴 상수 

```
75
0113
0x
```

### 포인터 변수 초기화

```c++
int *p =nullptr
```

### 기호 상수

#define 의 경우 에러도 찾기 힘들고,  타입 지정도 안돼서 되도록 사용x

const type name;

# 0917_cpp

switch문에서 블락{}없을때에는 선언문 사용 안됨 . 블락으로 묶었을 경우 선언 가능

## 과제 관련 

system("pause")와 system("cls") , cin 에러 

```c++
//메뉴 출력 입력 부
int main(){
	while (menu != 4) {
        system("cls");
		cout << "1) 과제1   2) 과제2   3) 과제3   4) 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
        int menu;
		cin>>menu;
        if(cin.fail()){
            cin.clear();  //cin 에러 발생 클리어
            cin.ignore(1000,"\n");  //cin 버퍼 제거
            continue;
        }

		switch (menu)
		{
		case 1:
			_HW01();
			break;
		case 2:
			_HW02();
			break;
		case 3:
			_HW03();
			break;
		case 4:
			break;

		}
	}

}

```

## 배열..

인덱스: 원소의 배열 순서

### 배열 선언

int grade[10];

배열 크기 지정에  변수 못 들어감   하지만 동적할당에서는 가능~

배열의 크기는 고정 불변 런타임에 그 크기를 변경 할수 없다 

### 배열 복사, 배열 비교

```c++
int grade[SIZE];
int b[SIZE];

grade= b; //오류!
방대 방으로 복사 


```

```c++
int num[12];
//num은 첫번째 방의 주소
num == &num[0];
&num[4]==  (num+4);
```

그러면 num과 &num[0]은 완전히 똑같을까 X



## 이차원 배열

```c++
int num[4][3];

num ==&num[0]
num[0] =&num[0][0]

//이차원 배열의 이름은 층의 시작 주소!(&num[0])
num[a][b] == *(*(num+a)+b)
```

# 0919_CPP

## 이차원 배열 

```c++
int [3][5] num;

//간략표현  
num [3][5] =&num[0];
num[0] =&num[0][0];
num[2] =&num[2][0];
num[0][0] = 0;

//포인터 표현
num[2][3] =*(*(num+2)+3)
```

```c++
//이차원 배열은 선언할 떄 초기화 하더라도 가장 고차원의 정보만 생략 할수 있다
int s[][3]={
    {1,2,3},{1,2,3},{112,2,2}
};
int s2[][2][2] ={
    {{1,2},{1,2}},
    {{1,4},{4,5}}
};
//왜 why? 배열에 연속적인 값으로 초기화 할수도 있기 때문에
int n[][5]={
    0,1,2,3,4,
    5,6,7,8,9
}
```

# 0924-CPP

## 포인터배열



## 레퍼런스(참조) 변수 

무조건 선언하면서 반드시 초기화가 되어야 함.

완전히 동일해짐

```cpp
int num1= 1020;
int &num2 = num1;
int &num3 =num2;

// int &ref =NULL 포인터 처럼 null초기화 안됨
```

#### 함수 인자 전달에 사용! 레퍼런스로  아주유용해여ㅕㅕ

상수에대해서 참조자 선언 x

```cpp
//포인터 변수를 참조하는거는
int ar =12;
int *par = &ar;
int **ppar =&par;
int *(&refpar) = par;
int** (&refppar)=ppar;
//배열 참조할 때는 크기 주어야한다.
int *(&ref)[SIZE] = parr;

```

## 함수 오버로딩

#### 함수 이름 은 동일하나 매개변수의 개수나 타입에 차이를 두어 같은 이름의 함수를 여러개 정의

#### 매개변수에 설정하는 디폴트 값의 의미

디폴트 값은 함수의 선언에만 위치

```cpp
int sum(int num1 =10, int num2= 20);

sum(); (O)
sum(20);
sum(10,20);
위의 3가지 함수 오버로딩 불가!
```

#### 부분적 디폴트 값 설정



매개변수가 여러개 일경우 디폴트값을 하나 정하면 그뒤의 매개는 모두 디폴트 값을 주어야한다.

## 매크로 함수

```cpp
#define SQUARE(x) ((x)*(X)) 
```

얘는 장점보다는 단점이 더 많이질 수도 있어여.. 그러니까 inline 쓰셍

## inline함수

```cpp
inline int SQUARE(int x){
    return x*x;
}
```

define과 달리 타입부분의 오류를 명확하게 체크가능

컴파일러에서 코드상에 넣어줌 inline은 컴파일러에서 처리됨 너무 길면 inline정의 여부에 상관없이 inline화 하지않고 , 간결한 함수는 자동으로 inline으로 만든다.

# 1001- CPP.

## 동적 할당-

new가 나오면 힙역역에 할당하고 주소알려주고 반드시 delete 해주어야함



## 클래스

c++에서의 구조체

자바는 클래스안에 다정의 되있는데 cpp는 헤더와 cpp로 나뉘는 이유.



### 접근제어 지시자. 

public, protected, private.

# 1008_CPP

## 객체 지향 프로그래밍



## 클래스의 완성

### 정보 은닉

CPP 의 생성자 소멸자.. 

### const멤버 함수 

```cpp
int GetX() const;
int GetY() const;
//이 멤버 함수에서는 이 멤버 변수를  변경할수 없다. 
    
```

#### +const는 오버로딩 대상 const로 함수를 오버로딩 할수 있다 . 서로 다른 함수. 

#### const함수는 const가 아닌 함수를 호출 하지 못한다. - 간접적인 멤버의 변경 가능성 차단.

const로 상수화된 객체를 대상으로는 const멤버함수만 호출이 가능하다.

```cpp
void InitNum(const EasyClass &easy){
	num =easy.getnum() //만약 getnum이 const함수가 아니면 컴파일 오류
}
```

# 1010_CPP

## 생성자 

- 객체의 멤버 변수를 초기화,하고 할당등, 객체가 처음에 만들어졌을 때 수행할 내용등을 담음
- 일반 메소드처럼 오버로딩,으로 여러 생성자를 정의 할수 있다.
- 또한 디폴트 값으로, 미리 설정할수도 있음- 

## 이니셜라이저

```cpp
//어떤 객체가 만들어질 때 객체 멤버변수로 기본생성자를 가지지 않는 객체를 가지면 생성자 정의부에,
생성자(ㅁㅁㅁㅁㅁㅁ,ㅁㅁㅁㅁ,ㅁㅁ) : upleft(x1,y1),right(x2,y2)// 이니셜라이저
{
    
}
//.h
class ddd{
private:
	aaa upleft;
    bbb right;
}
```

물론 당연히 헤더에서 클래스가 그 변수를 포함함을 정의 해야함

#### const로 선언하는 멤버 변수도 무조건 생성자 블록 안이 아닌 객체생성과 동시에 정의되어야하므로 이니셜라이저 부분에서 해야함!

### 멤버변수로 참조자를 선언할때는?

#### 이아이도 선언과 동시에 초기화 되어야하므로 꼭 이니셜라이저로..

## 소멸자.

- #### 객체가 소멸할 때 객체를 풀 때 자동으로 사용되는 함수. 오버로딩x 인자x

- #### 객체가 가지고 있는 동적 할당이나, 객체를 소멸 시킬때 변수 바꾸는 등, 객체가 소멸할 때 필요한 구문 실행. 

# 1015_CPP

## 객체 배열과 포인터 배열 --시험에 나올듯

## this포인터  

### this는 해당 클래스의 포인터 타입! 그래서 엑세스 할 때

```cpp
this->aaa ;
이런식으로 사용
```

### 자기 자신 객체 반환 레퍼런스

```cpp
class aaa{
private: 
    int num;
public:
    aaa& Adder(int n){
        num += n;
        return *this
    }
}
```

## ++스타일의 초기화

```cpp
//c언어 스타일 초기화
int num = 20;
int &ref= num;
//c++ 스타일 초기화
int num(20);
int &ref(num);
//똑같
soSimple sim2 =sim1;
soSimple sim2(sim1);
```

### 

## 복사 생성자 객체 복사해주는 함수

class A

```cpp
class A{
    A(const A& a){
        
    }
}
```

#### 복사 생성자 호출경우

- 객체의 복사본 생성

  ```cpp
  cmyclass a;
  cmyclass b(a);	
  ```

- 함수의 인자 전달

  ```cpp
  void myfunc(cmyclass param){}
  int main(){
  	cmyclass a;
      myfunc(a);
  }
  ```

- 반환 데이터 타입

  ```
  return a;
  ```

### 키워드 explicit

```cpp
explicit cmyclass(const Sosimple &copy)
```

```cpp
cmyclass a(10); 
cmyclass b(a);//는 되지만
cmyclass b = a; // 를 안되게 할수 있다.
```



### default 복사 생성자- 틀자체를 복사하기 때문에 , 틀안에 주소변수가 있었으면 그 주소 변수값을 그대로 가져오기 ㄸㅐ문에 그 주소 변수가 의미하는 데이터를 공유한다. --얕은 복사

```cpp
class A{
    int* a;
    A(cons int& aa){
        this->a = new int(aa);
        
    }
};

A c1(2);
A c2= c1;
//c2.a c2.b 
```



### 그래서 *깊은 복사* 를 수행하는 복사 생성자 정의

```cpp
class A{
    int* a;
    A(cons int& aa){
        this->a = new int(aa);
    }
    A(const A& aa){ //이렇게 깊은 복사 생성자로 만듬
        a= new int;
        *a= *(aa.a);
    }
};
```

복사 생성자 호출

- 객체 복사 생성
- 인자 전달 호출
- 반환에 의한 호출





## 클래스의 friend 선언

friend 선은 private 멤버까지도 접근을 허용하는 선언 이다

```cpp
class Boy{
private:
    int height;
    friend class Girl;
public:
    Boy(int len): height(len){}
}
class Girl{
private:
    char phnum[20];
public:
    void adasd(boy &frn){
        cout<<frn.height;
    }
}
```

#### 함수 프렌드 선언 클래스의 헤더파일을 friend 함수의 프로토 타입

하여 프렌드 선언

static 

static 멤버 변수 (클래스 변수)

static 



# 1017_CPP

## const static 멤버와 mutable

### const static 멤버 변수는 클래스가 정의 될 때 지정된 값이 유지되는 상수이기 때문에 처음에 정의되어야 한다 

### const 함수는 멤버의 값을 변경할수 없는 함수- 하지만 mutable 변수는  변경할수 있다 

```

```



## r-value 참조

- r-value

  - 단순 대입 연산자의 오른쪽 항
  - 연산에 따라 생성된 임시 객체

- r-value

  - 변수가 아닌 대상에 참조 변수:

    ```cpp
    int && data =3+4;
    data++;
    ```

#### 레퍼런스로 받을 수 있는것은 변수

```
TestFunc(int &&){

}
int x=3;
TestFunc(3);
TestFunc(3+4);
TestFunc(x+4);
```

## 이동 생성자 -

- ### r-value 참조 이용 새로운 객체를 생성 할때 얕은 복사를 수행하는 생성자

  - ### 이름이 없는 임시 객체 때문에 프로그램의 성능저하를 막기위한 생성자

r-value참조를 이용하여 새로운 객체를 새엉할때 얕은 복사를 수행하는 생성자때 얕은 복사를 하는 생성자 

이동할때 굳이 깊은 복사 할 이유가 없는것들을 해결 

```cpp
//이런식의 구성
ArrayData::ArrayData(ArrayData&& copy) :capacity(copy.capacity), used(copy.used), data(copy.data)
{
	cout << this->capacity << "이동 생성자\n";
	copy.data = nullptr;
}

ArrayData ArrayData::getCopyInstance(const ArrayData& copy)
{
	ArrayData arr(copy);
	return arr;
}

//실행
ArrayData arr(10);
ArrayData arr2 = ArrayData::getCopyInstance(arr);
```

인스 턴스 멤버 변수에 포인터(배열등), 의  주소 값이 담겨 깊은 복사가 필요한 클래스 의 경우 깊은 복사를 위해 깊은 복사 생성자를 둔다. 하지만 임시로 만든 객체를 복사할때는 같은 주소값을 그냥 담아도 상관이 없기 때문에 r-value참조를 이용한 '이동 생성자'를 사용하여 임시 클래스 객체를 객체에 복사(이동)한다.



```cpp
ArrayData arr2 = ArrayData::getCopyInstance(arr);
```

```cpp
//Arraydata.h
#pragma once
class ArrayData
{
private:
	double* data;
	int capacity;
	int used;
	static int count;
public:
	static int getCount();
	ArrayData(const int& capacity);
	ArrayData(const ArrayData& arr);
	ArrayData(ArrayData&& arr);
	
	ArrayData();
	~ArrayData();
	void addElement(double num);
	bool full() const;
	int getCapacity() const;
	int getUsed() const ;
	void emptyArray();
	void showData() const;
	friend double getArraySum(const ArrayData& arr);
	ArrayData getObject() {
		return *this;
	}

	static ArrayData getCopyInstance(const ArrayData&copy) ;
};
//Arraydata.cpp
#include "ArrayData.h"
#include<iostream>
using namespace std;
int ArrayData::getCount()
{
	return count;
}
ArrayData::ArrayData(const int& capacity):capacity(capacity), used(0)
{
	cout << this->capacity << "배열 생성\n";
	count++;
	this->data = new double[capacity];
}

ArrayData::ArrayData(const ArrayData& arr) : capacity(arr.capacity),used(arr.used)
{
	cout << this->capacity << "배열 복사\n";
	count++;
	this->data = new double[this->capacity];
	for (int i = 0; i < used; i++)
		data[i] = arr.data[i];
}

ArrayData::ArrayData(ArrayData&& copy) :capacity(copy.capacity), used(copy.used), data(copy.data)
{
	cout << this->capacity << "이동 생성자\n";
	copy.data = nullptr;
}

ArrayData::ArrayData() :ArrayData(5)
{
}

int ArrayData::count = 0;


ArrayData::~ArrayData()
{
	
	cout << this->capacity << "배열 삭제\n";
	count--;
	if (data != nullptr) {
		delete[] this->data;
		data = nullptr;
	}
	
}

void ArrayData::addElement(double num)
{
	if (!full())
		this->data[used++] = num;
	else
		cout << "빈 공간이 없음\n";
		
}

bool ArrayData::full() const
{
	return capacity==used;
}

int ArrayData::getCapacity() const
{
	return this->capacity;
}

int ArrayData::getUsed() const
{
	return this->used;
}

void ArrayData::emptyArray()
{
	this->used = 0;
}

void ArrayData::showData() const
{
	double* p = this->data;
	double* endp = p  + this->used;
	cout << "배열 출력 :";
	while (p < endp) {
		cout << *(p++)<<"  ";
		
	}
	cout << endl;
}

ArrayData ArrayData::getCopyInstance(const ArrayData& copy)
{
	ArrayData arr(copy);
	return arr;
}

//main.cpp
#include <iostream>
#include <string>
#include "ArrayData.h"
using namespace std;

void showArray(ArrayData arr) { //여기서도 복사 생성자
	arr.showData();
}
double getArraySum(const ArrayData& arr) {
	double total = 0;
	for (int i = 0; i < arr.getUsed(); i++) {
		total += arr.data[i];
	}
	return total;
}

int main()
{
	//cout << "201810754 조윤직\n";
	//ArrayData arr1(3);
	//arr1.addElement(1.1);
	//arr1.addElement(3.1);

	//ArrayData arr2 = arr1.getObject();
	//ArrayData arr3 = ArrayData(10);

	/*ArrayData arr[] = { 
		ArrayData(10),ArrayData(20),ArrayData(30) 
	};*/
	ArrayData arr(10);
    ArrayData arr2 = ArrayData::getCopyInstance(arr);
	system("pause");
}
```


