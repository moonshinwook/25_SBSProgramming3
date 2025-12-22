#pragma once

// 상속을 표현하는 용어
// Parent - child 
// Base   - derived
// Super  - sub

// 상속을 왜 사용했는가? : 반복을 없애려고(클래스 멤버 구현을 할 때 반복되는 부분)
// 객체 안의 객체를 표현하기 위한 방법 중 1이다. (구성 composition)
// 둘 중에 무엇을 사용해야 되는가? "is - a" "Has-a"
// 상속 - 반드시 가지고 있어야 되는 정보
// 구성 - 가지고 있을 수도 있고 아닐 수도 있고

// 다형성. 같은 형태이지만 다른 기능을 실행할 수 있게 하는 것.
// 컴파일(compile)    - 함수 오버로딩, 연산자 오버로딩
// 런타임(run-time)   - virtual, 가상 함수



// 다형성을 썼을 때의 장점이 있는가? if-else if-else... 표현식을 간결화할 수 있다. 

#include <iostream>
using namespace std;

#include "Idisplayable.h" // idisplayeble 헤더를 추가해서. Base 클래스를 display가능하게 만들어보세요.

class Base : Idisplayable // Human
{
    int a;

public:
    virtual void display() const override {cout << "나는 Base 입니다.";}
};

class Derived : public Base  // police gun
{
    Base* base;  // 
public:  
    void display() const override { cout << "나는 derived 입니다."; }
};
// override는 const타입까지도 같아야 오류가 발생되지 않음.

void Example();
void Example2();
void Example4();

