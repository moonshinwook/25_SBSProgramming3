#include "Monster.h"

Monster::Monster() // 위임
{
    mov = new Moveable; // 플레이어는 항상 위치의 주소를 갖는다.
}

Monster::~Monster()
{
    delete mov;
}

void Monster::Move(int x, int y)
{
    mov->Move(x, y);
}

void Monster::Teleport(Pos* other)
{
    mov->Teleport(other);
}

void Monster::display_pos()
{
    cout << "몬스터의 좌표 : " << mov->get_pos();
}