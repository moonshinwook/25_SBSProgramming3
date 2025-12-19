#include "Player.h"

Player::Player() // 위임
{ 
    this->pos = new Pos; // 플레이어는 항상 위치의 주소를 갖는다.
}

Player::Player(Pos* other)
{
    this->pos = new Pos; // 기본 타입; 
    *(this->pos) = *pos;
}

Player::~Player()
{
    delete pos;
}

void Player::Move(int x, int y)
{
    pos->Move(x, y);
}

void Player::Teleport(Pos* other_pos)
{
    pos->Teleport(other_pos);
}


Pos& Player::get_pos() const
{
    return *pos;
}

void Player::display_pos() const
{
    cout << "p1의 좌표 : " << get_pos();
}