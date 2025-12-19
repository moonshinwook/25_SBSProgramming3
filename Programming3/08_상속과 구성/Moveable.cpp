#include "Moveable.h"


Moveable::Moveable() // 위임
{
    cout << "Moveable 객체 생성" << endl;
    this->pos = new Pos; // 플레이어는 항상 위치의 주소를 갖는다.
}

Moveable::Moveable(Pos* pos)
{
    this->pos = new Pos; // 기본 타입; 
    *(this->pos) = *pos;
}

Moveable::~Moveable()
{
    delete pos;
    cout << "Moveable 소멸자 호출" << endl;
}

void Moveable::Move(int x, int y)
{
    cout << "Moveable의 이동이다." << endl;
    pos->Move(x, y);
}

void Moveable::Teleport(Pos* other_pos)
{
    pos->Teleport(other_pos);
}


Pos& Moveable::get_pos() const
{
    return *pos;
}

void Moveable::display_pos() const
{
    cout << "p1의 좌표 : " << get_pos();
}

Flyable::Flyable(int _flyWeight) : Moveable(), flyWeight(_flyWeight) 
//객체가 _flyWeight를 갖는 Flyable 생성, 상속되었있는 부모를 먼저 부르기
{
    cout << "Flyable 객체 생성" << endl;
}

Flyable::~Flyable()
{
    cout << "Flyable 소멸자 호출" << endl;
}

void Flyable::Move(int x, int y) 
{
    cout << "Flyable의 이동이다." << endl;
    Fly(3, 3);
}

void Flyable::Fly(int x, int y)
{
    // 몬스터의 y.pos 표현값을 - 3 ~ 6 
    
    //  인자를 받을 수 있는 Moveable의 Move를 쓰겠다. Flyable Move 인자가 없어도 실행 가능
    Moveable::Move(x * flyWeight, y * flyWeight); 
}
