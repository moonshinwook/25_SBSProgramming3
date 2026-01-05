#pragma once

#include "GameObject.h"
#include <string>
#include "Player.h"


using namespace std;

class Monster : public BattleObject
{
private:
    string _name;
public:
    int GetStrength() const;

    bool operator>(const Monster& other); // 나의 _hp(Monster)other._hp

    Monster(int id, int hp, int atk, string name)
        : BattleObject(id, hp, atk), _name(name) {}

    // 접근 지정자.
    // 생성 - 소멸자
    // 상속 - 구성
    // 스마트 포인터 


    // BattleObject을(를) 통해 상속됨
    void Attack(BattleObject* other) override;

};



