#include "Moveable.h"

Moveable::Moveable() // 위임
{
    this->mov = new mov; // 플레이어는 항상 위치의 주소를 갖는다.
}

Moveable::Moveable(mov* other)
{
    this->mov = new mov; // 기본 타입; 
    *(this->mov = *mov;
}

Moveable::~Moveable()
{
    delete mov;
}

void Moveable::Move(int x, int y)
{
    mov->Move(x, y);
}

void Moveable::Teleport(mov* mov)
{
    mov->Teleport(other_pos);
}

void Moveable::display_pos() const
{
    cout << "p1의 좌표 : " << get_pos();
}

Pos& Moveable::get_pos() const
{
    return *pos;
}
