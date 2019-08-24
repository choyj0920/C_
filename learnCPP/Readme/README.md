---
typora-root-url: ./
---

# c++

## 1. 0810

### 입력,출력

std 라이브러리(iostream)  std::cout, std::cin

```c++
#include<iostream>
std::cout<<"hello world"; //helloworld 출력
std::cin>> n //입력값 n에 넣기 
std::cin>> n1 >>n2 //여러개 입력 가능 공백이나 엔터로 구분
```

:: 는 범위 지정 연산자 

헤더 파일이나 main위에   using namespace std; 를 쓰면 std::없이 사용 가능

```
using namespace std;
cin>>n
cout<<"sadfasdf"
```

cout.setprecision(자릿수n);  정해진 자릿수 만큼 나옴 printf의  %nd와 유사

cout.setf(ios::fixed); 를 선언하면  그 뒤부터는 setprecision함수가 소수자리만 셈

자릿수 부분은 printf가 한참 편함

### 오버 로딩

중복 정의, 기존에 만들어 놓은 함수와 이름은 같지만 매개 변수의 형태가 다른 함수가 있을 때 오버로딩 되었다 한다.

-매개변수의 개수가 다른경우

-매개변수의 자료형이 다른 경우

오버로딩은 일반 함수나 같은 클래스의 맴버함수간에 이루어진다.

#### 디폴트 매개변수

함수의 선언부에서 

void add(int a ,int b=0); 이런 식으로 매개변수의 기본 값을 주면 add(1); 로 하나의 값을 주지 않아도 자동으로 b=0 으로 들어감 , 

+규칙 = 매개변수가 여러개 일때 중간에 디폴트 값을 주면 그 값이후의 모든 매개변수는 모두 초기화를 해주어야 한다.

과제:

복습 차원에서 

입력함수를 만듭니다.

정수를 반환하고, 설명 문자열을 매개변수로 받습니다. 

사용할경우 사용예)

Int 00000000(const char*)

Int a= 000000000("숫자를 입력하세요 : ");

Cout <<a <<endl;

\>>screen

숫자를 입력하세요 : ##### 

```c++
#include<iostream>
#include<Windows.h>
 
using namespace std; 
 
int scan_num(const char* directive) {
    int num;
    cout << directive;
    cin >> num;
    return num;
}
 
int main() {
    cout << scan_num("숫자를 입력하세요 : ") << endl;
 
    system("pause");
    return 0;
}

```

![0810](/0810.PNG)

## 2.0811 C++

c++에서 0만 거짓 0아니면 모두 참(0만 유일하게 모든 비트가 0)

## 동적 할당 및 해제

```c++
int * ptr1; //주소 담을 변수
ptr1 =new int; //동적 할당 
int *ptr2 =new int[10]; //같이도 가능
delete ptr1; //동적할당해제
delete []ptr2; // 배열 동적할당해제
```

2차원 배열 할당 해제 -해제할때는 할당의 역순으로

```c++
int** arr;
arr =new int*[2];
for(int n=0;n<2;n++)
	arr[n] =new int[3];
arr[2][2];
for(int n =0;n<2;n++)
	delete []arr[n]
delete[] arr;
```

## 클래스

클래스 =빵틀

구조체와 크게 다르지 않음 구조체도 c++에서는 함수도 가질 수 있다.

클래스는 은닉성을 가지고 클래스 안 쉽게 접근x -구조체와 차이

클래스 생성시 헤더와 cpp에 선언과 정의를 따로 할 것!

효율성을 위해 룰

public, private, protected

생성자가 public이 아닌 경우 이 객체를 외부에서 만들 수 없다.

protected로 만들면 부모전용 생성자 

private로 만들면 외부에 존재하지 않고 내부에만 존재 -싱글톤

포인터 -> 

객체 .

```c++
class cl1{
private:
    char name[20];
public:
}
cl1 c1;
cl1 * c2;
cl.name;
c2-> name;
```

### 과제

과제 

Enum 성격{

난폭한 =0,

예민한,

평범한,

무난한,

게으른

}

Enum 종족{

인간 =0,

악마

}

Class Character{

_name

_whdwhr

_tjdrur

Public:

기본생성자에는 이름은 없고,종족은 인간, 성격은 평범한으로 설정

초기화 함수가 있습니다. 이름, 성격 종족을 매개 변수로 가지고있음. 

정보 출력 함수가 있습니다.

( 00족 0000은 000성격입니다)

}

 

실질적 화면 

<캐릭터를 만들겠습니다>

이름을 입력하세요 : 

1.인간.

2.악마.

종족을 선택하세요:

1.난폭한.

2.예민한.

3.평범한.

4.무난한.

5.게으른.

성격을 선택하세요:

<결과를 확인합니다>

( 00족 0000은 000성격입니다)

이름은 동적할당 클래스도 동적할당으로

캐릭터를 만들겠습니다 그다음에 몇명을 만들 까요 물어보게

character.h

```c++
#pragma once
 
class character {
    char* _name;
    int _pers;
    int _trib;
    void print_pers();
    void print_trib();
public:
    character();
    void SetInfo(const char* name,int pers, int trib);
    void ShowInfo();
    
    ~character();
 
};
```

 character.cpp

```c++

#include "pch.h"
#include <iostream>
#include "character.h"
 
typedef enum  personality
{
    난폭한 = 1,
    예민한,
    평범한,
    무난한,
    게으른
}personality;
 
typedef enum tribe {
    인간 = 1,
    악마
}tribe;
 
character::character() {
    _name = 0;
    _pers = 평범한;
    _trib = 인간;
}
 
void character::SetInfo(const char* name, int pers, int trib) {
    int len = strlen(name) + 1;
    _name = new char[len];
    sprintf_s(_name, len, name);
    _pers = pers;
    _trib = trib;
}
 
 
 
void character::ShowInfo() {
    print_trib();
    cout << "족 " << _name << "은 ";
    print_pers();
    cout<<" 성격입니다" << endl;
}
 
void character::print_pers() {
    switch (_pers) {
    case 난폭한: 
        cout << "난폭한";
        break;
    case 예민한:
        cout << "예민한";
        break;
    case 평범한:
        cout << "평범한";
        break;
    case 무난한:
        cout << "무난함";
        break;
    case 게으른:
        cout << "게으른";
        break;
    }
}
void character::print_trib() {
    switch(_trib) {
    case 인간:
        cout << "인간";
        break;
    case 악마:
        cout << "악마";
        break;
    }
    
}
 
character::~character() {
    cout << _name << " 소멸자 호출!" << endl;
    delete(_name);
    _name = NULL;
}
```

main.cpp

![0811](/0811.PNG)

## 3. 0817 c++

### 복사 생성자

#### 얕은 복사

값만 복사 맴버별 복사가 이루어 지는 방식을 말한다

#### 깊은 복사

값만 복사가 아닌 값이 있는 주소를 공유 

### 정적 맴버 변수

static 고야한 저장공간 class 안에서 만들어도 

c#은 클래스객체로 접근 불가 c++은 그냥 클래스로든 클래스 객체로든 접근 가능

### inline과 #define 

```c++
#define GOB3(x) ((x)*(x)*(x))
Using namespace std;
Int main(){
	Cout <<GOB3(7) <<endl;
    CU(7); 
	Return 0;
    
}

Inline int CU(int x){
	Return x*x*x;
}
```

inline c언어 에서의 매크로 와 비슷  일반함수에 비해 실행 속도가 빠르다는 장점 하지만 많이 사용하면 프로그램의 크기가 커짐 비교적 짧은 줄 의 함수 만 사용

inline이 더 빠름 

### friend 키워드 클래스

friend로 지정한 클래스는 해당 클래스의 private 맴버에 직접 접근 가능

클래스 선언부 내부 어디에든 선언 해줄수있다

객체지향언어의 핵심중 하나인 정보 은닉 을 깨는 행위로 특별한 경우가 아니고는 잘 사용x

```c++
class B; //a에게 B가 있다는것을 알림
Class a{
	Friend class B;  
}; 
```

 B는 A의 맴버 사용 가능

과제 :

클래스 거지와 사과나무 생성 사과개수 알 수있는 사과클래스안에 함수 거지클래스의 사과따는 함수 사과는 거지를 친구 클래스로 선언

```c++
// main.cpp
#include "pch.h"
#include <iostream>
#include "apple.h"
#include "Beggar.h"
int main()
{
    apple appletree;
    Beggar b;
    appletree.print_Count();
    for (int i = 0; i <= 15; i++) {
        b.ddagi(&appletree);
    }
    system("pause");
    return 0;
}
 
 
//apple.h
#pragma once
class Beggar;
class apple
{
    int apple_count;
public:
    apple();
    friend class Beggar;
    void print_Count();
    ;
    ;
};
 
//apple.cpp
 
#include "pch.h"
#include "apple.h"
#include "Beggar.h"
apple::apple()
{
    apple_count = 15;
}
void apple::print_Count()
{
    cout << "현재 사과의 갯수는 " << apple_count << "입니다\n";
}
 
 
// Beggar.h
#pragma once
class apple;
class Beggar
{
public:
    Beggar();
    ~Beggar();
    void ddagi(apple* A);
};
 
 
//beggar.cpp
#include "pch.h"
#include "Beggar.h"
#include "apple.h"
Beggar::Beggar()
{
}
Beggar::~Beggar()
{
}
void Beggar::ddagi(apple* A)
{
    if (A->apple_count == 0) {
        cout << "더이상 사과를 딸수 없습니다 사과가 0개에요 ㅠ\n"; return ;
    }
    A->apple_count --;
    cout << "사과를 얻었습니다 !! \n";
    cout << "사과 나무에 사과 갯수 : " << A->apple_count << endl;
}
 

```

![0817](/0817.PNG)