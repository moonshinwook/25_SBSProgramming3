#pragma once
#include "Pos.h"

class Moveable 
{
private:
    Pos* pos;
public:
    Moveable(); // 기본 생성자
    Moveable(Pos* pos);
    Moveable(const Moveable& other);
    Moveable(Moveable&& rhs);
    ~Moveable();

    virtual void Move(int x, int y); // virtual을 통해 다형성 재현
    void Teleport(Pos* other);

    Pos& get_pos() const;     //      const Player ->  함수 실행
    void display_pos() const; //
};

// A 'is' B 관계 : Moveable 은 Flyable인가요? 상속(Inheritance) 같은
// A 'has' B 관계 : Monster has Moveable 구성 (composition) 가지고 있는

// 접근 지정자
// public : 공개 가능한
// protected : 나를 상속한 녀석(자식(child), 파생(derived)) 공개할 수 있게 만들어라.
// private : 자기 자신만 사용 가능

// 다형성(polymorphism) : 형태는 같지만 다양한 의미를 소유하고 있는 상태
// Runtime      : 동적 할당, 프로그램 실행 도중에 함수가 변화한다. 클래스의 상속의 다형성. 
// Compile Time : 함수 오버로딩, 연산자 오버로딩

class Flyable : public Moveable
{
private:  // Fly 이동하는 거리보다 더 많이 움직인다.
    int flyWeight;

public:
    Flyable(int _flyWeight);
    ~Flyable();

    void Move(int x, int y) override; // 함수의 형태가 다르면 에러를 일으키는 override
    void Fly(int x, int y);
};

