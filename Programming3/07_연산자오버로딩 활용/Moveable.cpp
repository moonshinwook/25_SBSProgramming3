#include "Moveable.h"


Moveable::Moveable() // 위임
{
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
}

void Moveable::Move(int x, int y)
{
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
