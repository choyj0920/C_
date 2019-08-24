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



기본 pch.h 모든 코드에 사용

```c++

#ifndef PCH_H
#include<iostream>
#include<Windows.h>
#include<iomanip>   //streamsize setprecision(streamsize size);



using namespace std; //이걸 쓰면 std:: 안써도 ㄱㅊ

#define PCH_H


#endif //PCH_H
```

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

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0810.PNG?raw=true)

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

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0811.PNG?raw=true)

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

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0817.PNG?raw=true)

## 4.0818

### 연습 문제 파티

### 예제1. 문자열 받아서 문자열 저장, 문자열 출력하는 클래스

### 예제2. 둘레와 면적을 계산해서 출력하는 원, 직사각형 클래스 



```c++
//예제1.
//printer.h
 
#pragma once
class Printer
{
    char *_str;
public:
    void scanf_str(const char* str);
    void print_str();
 
    Printer();
    ~Printer();
};
 
//printer.cpp
#include "pch.h"
#include "Printer.h"
 
 
void Printer::scanf_str(const char * str)
{
    int len = strlen(str) + 1;
    if (_str) {
        delete[]_str;
        _str = NULL;
    }
    _str = new char[len];
 
    sprintf_s(_str, len, str);
}
 
void Printer::print_str()
{
    cout << _str << endl;
}
 
Printer::Printer()
{
 
}
 
 
Printer::~Printer()
{
}
 
//예제 2.
 
//Rectangle2.h
 
#pragma once
#include <iostream>
 
class Rectangle2
{
    double _a, _b;
 
public:
 
    Rectangle2(double a, double b);
    double print_nul();
    double print_dool();
    ~Rectangle2();
};
 
//Rectangle2.cpp
 
#include "pch.h"
#include "Rectangle2.h"
 
 
Rectangle2::Rectangle2(double a, double b)
{
    _a = a;
    _b = b;
}
 
 
double Rectangle2::print_nul()
{
    return _a * _b;
}
 
double Rectangle2::print_dool()
{
    return (_a + _b) * 2;
 
}
 
Rectangle2::~Rectangle2()
{
}
 
//CIrcle.h
 
#pragma once
#define RADIAN 3.1415
#include<iostream>
class Circle
{
    double _r;
 
public:
    double print_nul();
    double print_dool();
    Circle(double r);
    ~Circle();
};
 
 
 
//CIrcle.cpp
 
#include "pch.h"
#include "CIrcle.h"
#include<iostream>
 
 
double Circle::print_nul()
{
    return _r * _r*RADIAN;
}
 
double Circle::print_dool()
{
    return _r * 2 * RADIAN;
 
}
 
Circle::Circle(double r)
{
    _r = r;
}
 
 
 
Circle::~Circle()
{
}
 
 
//main.cpp
 
 
#include "pch.h"
#include <iostream>
#include"Printer.h"
#include "Rectangle2.h"
#include "CIrcle.h"
int main()
{
    //예제 1
    Printer p1;
    p1.scanf_str("Hello World!!");
 
    p1.print_str();
    p1.scanf_str("I LOVE C++");
    p1.print_str();
 
    //예제 2
    Rectangle2 rec1(4.5, 12.3);
    Circle cir1(8.5);
 
    printf(" 둘레 : %.2lf\n", rec1.print_dool());
    printf(" 면적 : %.2lf\n", rec1.print_nul());
    printf(" 둘레 : %.2lf\n", cir1.print_dool());
    printf(" 면적 : %.2lf\n", cir1.print_nul());
 
}
```

### 예제3. 명함  클래스  .초기화생성자

이름, 번호 ,주소, enum으로 직급을 받음

### 예제4. 위 명함 클래스에 포인터 배열로 5명의 명함 생성, 출력 기본생성자에 + 초기화 함수 사용

```c++
//NameCard.h
 
#pragma once
enum position {
    인턴 = 1,
    대리,
    과장,
    부장,
    사장
};
 
class NameCard
{
    char *_name = 0;
    char *_num = 0;
    char *_adr = 0;
    int _grad;
public:
    NameCard();
    NameCard(const char* name, const char* num,const char* adr,int grad);
    void setName();
    void setNum();
    void setAdr();
    void setgrad();
    void print_info();
 
 
    ~NameCard()
    {
        if (_name) {
            delete[] _name;
            _name = 0;
        }
        if (_num) {
            delete[] _num;
            _num = 0;
        }
        if (_adr) {
            delete[] _adr;
            _adr = 0;
        }
    }
};
 
//NameCard.cpp
 
#include "pch.h"
#include "NameCard.h"
 
 
NameCard::NameCard()
{
    _name = new char[200];
    _adr = new char[200];
    _num = new char[20];
}
 
NameCard::NameCard(const char * name, const char * num, const char * adr, int grad)
{
    int len_name = strlen(name) + 1;
    int len_num = strlen(num) + 1;
    int len_adr = strlen(adr) + 1;
 
    _name = new char[len_name];
    _num = new char[len_num];
    _adr = new char[len_adr];
    sprintf_s(_name, len_name, name);
    sprintf_s(_num, len_num, num);
    sprintf_s(_adr, len_adr, adr);
    _grad = grad;
 
}
 
void NameCard::setName()
{
    char name[200];
    int len;
    if (_name) {
        delete[] _name;
        _name = 0;
    }
    cout << " 이름 : ";
    scanf_s(" %[^\n]",name,200);
    len = strlen(name) + 1;
    _name = new char[len];
    sprintf_s(_name, len, name);
    
}
 
void NameCard::setNum()
{
    char num[20];
    int len;
    if (_num) {
        delete[] _num;
        _num = 0;
    }
    cout << " 전화번호 : ";
    scanf_s(" %[^\n]s", num,20);
    len = strlen(num) + 1;
    _num = new char[len];
    sprintf_s(_num, len, num);
 
}
 
void NameCard::setAdr()
{
    char adr[200];
    int len;
    if (_adr) {
        delete[] _adr;
        _adr = 0;
    }
    cout << " 주소 : ";
    scanf_s(" %[^\n]s", adr,200);
    len = strlen(adr) + 1;
    _adr = new char[len];
    sprintf_s(_adr, len, adr);
}
 
void NameCard::setgrad()
{
    cout << "1. 인턴 \n2. 대리\n3. 과장\n4. 부장\n5. 사장\n 직급을 입력하세요 : ";
    cin >> _grad;
 
}
 
void NameCard::print_info()
{
    cout << "이    름 : " << _name << endl;
    cout << "전화 번호 : "<<_num <<endl;
    cout << "주    소 : " << _adr << endl;
    cout << "직    급 : ";
 
 
    switch (_grad)
    {
    case 인턴:
        cout << "인턴";
        break;
    case 대리:
        cout << "대리";
        break;
    case 과장:
        cout << "과장";
        break;
    case 부장:
        cout << "부장";
        break;
    case 사장:
        cout << "사장";
        break;
    }
    cout << endl;
 
}
 
 
//main.cpp
 
#include "pch.h"
#include <iostream>
#include "NameCard.h"
int main()
{
    //예제 3
    NameCard nc("Lee Ji Sun", "333-333", "www.ezsun.net", 3);
    nc.print_info();
    
    cout << endl;
    cout << endl;
 
    //예제4
    NameCard * human[5];  //포인터 배열
    int n = 2;
    for (int i = 0; i < n; i++) {
        human[i] = new NameCard();
        cout << i + 1 << "번 째 명함 생성! \n정보를 입력하세요\n";
        human[i]->setName();
        human[i]->setNum();    
        human[i]->setAdr();
        human[i]->setgrad();
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "번 째 명함 : \n";
        human[i]->print_info();
        delete human[i];
    }
    
    
}
```

예제3.

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0818_3.PNG?raw=true)

예제4.

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0818_4.PNG?raw=true)



### 예제 5. inline 함수 오류 고치기

inline함수는 '컴파일러'가 그대로 그 내용을 복사 해오기 때문에 main함수의 실행 전 실행하게 되는 헤더 부분에서 정의 되어야 함! 사용하지 않아도 실행되기 때문에 비교적 짧은 함수만 inline으로 사용
    

```c++
//SUM.h
 
#pragma once
class SUM
{
public:
   
 
    inline int Hab(int a, int b)
    {
 
        return a + b;
    }
 
    inline float Hab(float a, float b)
    {
        return a + b;
    }
 
    inline int ToHab(int a)
    {
        int tot = 0;
        for (int n = 1; n <= a; tot += n++);
        return tot;
    }
 
    inline int ToHab(int a, int b)
    {
        int tot = 0;
        for (int n = a; n <= b; tot += n++);
 
        return tot;
    }
    SUM(){}
    ~SUM(){}
};
 
 
//main.cpp
 
 
#include "pch.h"
#include <iostream>
#include "SUM.h"
 
int main()
{
    SUM Ssum;
    cout << Ssum.Hab(12, 56) << endl;
    cout << Ssum.Hab(2.4f, 32.7f) << endl;
    cout << Ssum.ToHab(10) << endl;
    cout << Ssum.ToHab(11, 50) << endl;
}
```

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0818_5.PNG?raw=true)

### 예제6. 점수가 담겨있는 클래스 

국영수 점수, 평균 ,이름을 맴버로 가지고 있으며 기본 생성자로 이름을 받고 점수초기화 함수에서 평균 지정, 점수 출력함수를 가지고 있다 

```c++
//GRADE.h
 
#pragma once
class GRADE
{
    char _name[100] = { 0, };
    int korean_score;
    int english_score;
    int math_score;
    double aver_score;
public:
    GRADE(const char*name);
    void set_score(int ks,int es,int ms);
    void print_score();
    ~GRADE();
};
 
//GRADE.CPP
 
#include "pch.h"
#include "GRADE.h"
  
GRADE::GRADE(const char * name)
{
    int len = strlen(name)+1;
    sprintf_s(_name, len, name);
 
}
 
void GRADE::set_score(int ks, int es, int ms)
{
    korean_score = ks;
    english_score = es;
    math_score = ms;
    aver_score = (ks + es + ms) / (double)3;
}
 
void GRADE::print_score()
{
    cout << "이름 : " << _name << endl;
    cout << "국어 : " << korean_score << "점" << endl;
    cout << "영어 : " << english_score << "점" << endl;
    cout << "수학 : " << math_score << "점" << endl;
    printf("평균 : %.1lf점\n", aver_score);
}
 
 
GRADE::~GRADE()
{
}
 
//MAIN.CPP
 
#include "pch.h"
#include "GRADE.h"
 
 
 
GRADE::GRADE(const char * name)
{
    int len = strlen(name)+1;
    sprintf_s(_name, len, name);
 
}
 
void GRADE::set_score(int ks, int es, int ms)
{
    korean_score = ks;
    english_score = es;
    math_score = ms;
    aver_score = (ks + es + ms) / (double)3;
}
 
void GRADE::print_score()
{
    cout << "이름 : " << _name << endl;
    cout << "국어 : " << korean_score << "점" << endl;
    cout << "영어 : " << english_score << "점" << endl;
    cout << "수학 : " << math_score << "점" << endl;
    printf("평균 : %.1lf점\n", aver_score);
}
 
GRADE::~GRADE()
{
}
```

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0818_6.PNG?raw=true)

### 예제7. 헤더 부분만 보고 클래스 완성하기 

```c++
class ADDClass
{
    int a, b;
    void Hap();
public:
    ADDClass();
    void Set(int a1, int b1);
    static void Disp1(ADDClass *p);
};
```

보고 클래스 완성

```c++
//ADDClass.h
 
#pragma once
class ADDClass
{
    int a, b;
    void Hap();
public:
    ADDClass();
    void Set(int a1, int b1);
    static void Disp1(ADDClass *p);
};
 
//ADDClass.cpp
 
#include "pch.h"
#include "ADDClass.h"
 
 
void ADDClass::Hap()
{
    cout << a + b << endl;
}
 
ADDClass::ADDClass()
{
 
}
 
void ADDClass::Set(int a1, int b1)
{
    a = a1;
    b = b1;
}
 
void ADDClass::Disp1(ADDClass * p)
{
    printf("%d + %d = ", p->a, p->b);
    p->Hap();
}
 
 
//main.cpp
 
#include "pch.h"
#include <iostream>
#include "ADDClass.h"
int main()
{
    ADDClass adc;
    adc.Set(10, 40);
    ADDClass::Disp1(&adc);
    adc.Set(40, 100);
    ADDClass::Disp1(&adc);
 
}
```

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0818_7.PNG?raw=true)

### 예제8.

dog클래스 이름,나이를 변수로 가지고있다 생성자 초기화 

bon클래스 살이 붙어있는 양을 변수로 가지고 있다 살이 붙어있는 양은 enum으로 많이 적당히 적게 

bon은 dog를 friend로 선언

변수는 모두 private로 선언

bonclass는 맴버변수와 초기화 함수만 존재 

```c++
//BON.h
 
#pragma once
class DOG;
enum sal { 많이 = 1, 적당히, 적게};
class BON
{
    friend class  DOG;
private:
    int sal_q;
    
public:
    BON(int n);
    
};
 
//BON.cpp
 
#include "pch.h"
#include "BON.h"
 
 
BON::BON(int n)
{
    sal_q = n;
}
 
 
//DOG.h
 
#pragma once
#include "BON.h"
 
class DOG
{
private:
    char _name[20];
    int _age;
public:
    DOG(const char * name,int age);
    void print_info();
    void eat_bone(BON bon);
};
 
//DOG.cpp
 
#include "pch.h"
#include "DOG.h"
 
DOG::DOG(const char * name, int age)
{
    int len = strlen(name) + 1;
    sprintf_s(_name, len, name);
    _age = age;
}
 
void DOG::print_info()
{
    cout << _name << "의 나이는 " << _age << "살 이다.\n";
}
 
void DOG::eat_bone(BON bon)
{
    cout << _name << "는 살이 ";
    switch (bon.sal_q)
    {
    case 많이:
        cout << "많이";
        break;
    case 적당히:
        cout << "적당히";
        break;
    case 적게:
        cout << "적게";
        break;
    }
    cout << " 붙은 뼈다귀를 먹고 있다\n";
}
 
 
 
//main.cpp

#include "pch.h"
#include <iostream>
#include "BON.h"
#include "DOG.h"
int main()
{
    DOG puppy("멍뭉이", 3);
    BON Bo1(적게);
    BON Bo2(많이);
    
    puppy.print_info();
    puppy.eat_bone(Bo1);
    puppy.eat_bone(Bo2);
}
```

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0818_8.PNG?raw=true)

## 5.0824 c++

### 클래스 상속 

하위에 있는 클래스가 상위에 있는 클래스의 자원들을 별다른 정의나 선언없이 사용할 수있게 하는 방법이라 할 수있습니다. 이런 상속은 작성해야하는 코드의 양을 줄일 뿐만 아니라 프로그램의 유연성이 높아 지는 장점이 있습니다. 상위 클래스가 기능의 버그와 기능의 변경 등으로 변화가 생겼을 떄 상위 클래스를 상속 받은 하위 클래스가 정상 동작지를 예측하기 어려워진다. 하위 클래스는 상위 클래스의 부분 집합 이기 때문에 상위 클래스가 변경이 일어나면 하위 클래스도 변형되기 때문인데 이처럼 상속 구조가 복잡해지면 변화에 대한 영향도를 예측하기 어려워져 다중 상속 프로그램은 프로그래밍에서 지양하는 편이다 

```c++
class cla1{

}
class cla2:public cla1
{

}
```

protected 상속 받는 애들만 사용 가능 외부에서도 사용 x

```c++
Student::Student(int _age, const char * _name, const char* _school )  :Human(_age,_name){
		
		}
```

이런 식으로 자식의 생성자 정의부에 부모 생성자 써서 자식생성자가 생성될때 두 클래스의 객체가 생성 되도록 함

### this

매개변수와 맴버 명이 같을 때 함수 안에서 자동으로 매개변수를 의미하게 되기 때문에  this를 사용한다

```c++
this->age  //클래스 맴버를 의미 
```

### 클래스 객체 배열 -기본 생성자가 없을때

초기화 생성자가 있는 형태의 클래스 객체배열을 생성할 떄

```c++
Student stu[3]={Student("김철수", 14, "SBS학원",12), Student("김철수", 14, "SBS학원",12), Student("김철수", 14, "SBS학원",12)}
```

이와 같이 배열로 

### 클래스에서 의 포인터

```c++
Student *stu[3];
char name[20];
int age, studentID;
for (int n = 0; n < 3; n++) {
	cin >> name >> age >> studentID;
	stu[n] = new Student(age, name, "SBS아카", studentID);
	}
for (int n = 0; n < 3; n++) {
	stu[n]->GetInfo();	}
delete[] stu; //역순 동적할당 해제
```

### 만약  객체의 갯수를 바꾸고 싶다면

```c++
Student** stu =NULL;
char name[20];
int age, studentID;
int k;
k=3
stu = new Student*[k];
for (int n = 0; n < 3; n++) {
	cin >> name >> age >> studentID;
	stu[n] = new Student(age, name, "SBS아카", studentID);
}
for (int n = 0; n < 3; n++) {
	stu[n]->GetInfo();
}
for (int n = 0; n < 3; n++) {
	delete stu[n];
}
delete[] stu;
```

### 과제:

스테이터스 클래스를 만든다.

스테이터스 클래스에는 이름 생명력 공격력 방어력 성격 타입을 만든다.

성격은 enum 성격 타입을 만든다. 성격의 가지수는 난폭함,조급함,평범함,느긋함,조용함이다.

몬스터 클래스를 만든다.

몬스터 클래스에는 종족타입과 종족명이 있다.

Enum종족타입을 만든다 종족은 언데드 악마 야수 정령이다. 

```c++
//Status.h
#pragma once
typedef enum personal {
난폭함 = 1, 조급함, 평범함, 느긋함, 조용함
}pers;
 
class Status
{
char name[20];
int hp;
int att;
int def;
int perso;
public:
Status(const char *name,int hp,int att,int def,int perso);
 
~Status();
void getperso();
void showInfo();
};
 
//Status.cpp
 
#include "pch.h"
#include "Status.h"
 
Status::Status(const char * name, int hp, int att, int def, int perso)
{
strcpy_s(this->name, strlen(name) + 1, name);
this->hp = hp;
this->att = att;
this->def = def;
this->perso = perso;
 
}
 
Status::~Status()
{
}
 
void Status::getperso()
{
switch (this->perso)
{
case 난폭함:
cout << "난폭함\n";
break;
case 조급함:
cout << "조급함\n";
break;
case 느긋함:
cout << "느긋함\n";
break;
case 평범함:
cout << "평범함\n";
break;
case 조용함:
cout << "조용함\n";
break;
}
}
 
void Status::showInfo()
{
cout << "이름 : " << name << endl;
cout << "스텟 \n";
cout << "생명력 : " << hp << "\t공격력 : " << att << "\t방어력 : " << def << endl;
 
cout << "성격 : ";
getperso();
}
 
//Monster.h
#pragma once
#include "Status.h"
typedef enum tribe {
언데드=1,
악마, 
야수,
정령
}tribe;
class Monster :public Status
{
int trib;
char tribname[20];
public:
Monster(const char * name, int hp, int att, int def, int perso,int trib);
~Monster();
void Settribname();
void showMonster();
 
};
 
//Monster.cpp
 
#include "pch.h"
#include "Monster.h"
 
Monster::Monster(const char * name, int hp, int att, int def, int perso, int trib) :Status( name,hp,att,def,perso)
{
this->trib = trib;
Settribname();
}
Monster::~Monster()
{
}
void Monster::Settribname()
{
switch (trib) {
case 언데드:
strcpy_s(tribname, sizeof(tribname), "언데드");
break;
case 악마:
strcpy_s(tribname, sizeof(tribname), "악마");
break;
case 야수:
strcpy_s(tribname, sizeof(tribname), "야수");
break;
case 정령:
strcpy_s(tribname, sizeof(tribname), "정령");
break;
 
}
}
void Monster::showMonster()
{
showInfo(); 
cout << "이 몬스터는 " << tribname << "족 입니다.\n";
}
 
Main.cpp
 
#include "pch.h"
#include <iostream>
 
#include "Monster.h"
#include "Status.h"
int main()
{
int hp, att, def,pers,trib;
char name[20];
Status stat =  Status("Uz",10,10,10,평범함);
stat.showInfo();
Monster mon("HY", 20, 20, 20, 난폭함, 악마);
mon.showMonster();
 
 
return 0;
}
```

![](https://github.com/choyj0920/SBS_academy_unreal_engine/blob/master/learnCPP/Readme/0824.PNG?raw=true)



## 6.0825 C++