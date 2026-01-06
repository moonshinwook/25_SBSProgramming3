#include "Player.h"


Player::Player(int id, RoomObjectType TYPE, int hp, int atk) : BattleObject(id, TYPE, hp, atk) {}

Player::Player()
    : Player{ 1001, RoomObjectType::BATTLE, 1000, 100 } {}

void Player::Attack(BattleObject* mon)
{
    cout << "몬스터에게" << _atk << "만큼 데미지를 주었습니다!" << endl;

    mon->Damage(_atk);
}

