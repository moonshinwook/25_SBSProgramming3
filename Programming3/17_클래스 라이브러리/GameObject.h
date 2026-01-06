#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class RoomObjectType
{
   BATTLE = 0, TREASURE = 1, REST
};

class GameObject
{
protected:
    int _id;
    RoomObjectType R_TYPE;
    // int instanceID;
public:
    GameObject(int id, RoomObjectType TYPE);             // 숫자 -> casting Enum

    void SetRoomType(RoomObjectType r) { R_TYPE = r; }   // Set함수. BattleObject 생성되는 위치에서..하나씩 타입을 지정을 해줘야 한다. 

    virtual GameObject* GetObjectType() = 0;
};

class BattleObject : public GameObject // public 명시 필요, 명시하지 않을 시 private로 명시됌.
{
protected:
    int _hp;
    int _atk;
public:
    BattleObject(int id, RoomObjectType Type, int hp, int atk);

    void Damage(int amount);
    bool IsDeath();

    virtual void Attack(BattleObject* other) = 0;

    virtual GameObject* GetObjectType() override; // override로 virtual코드의 오류 방지
};

class TreasureObject : public GameObject
{
protected:
    int _gold;
    string _content;
public:
    TreasureObject(int id, RoomObjectType TYPE, int gold, string content);

    void GetTreasure();

    virtual GameObject* GetObjectType() override;
};


// 엑셀 시트
// 몬스터 (전투) + (드랍) + (스킬)
// 고블린 클래스. 고유한 몬스터?
// 고블린 3마리랑 전투.  (A) = 1 B = 2 C = 3...
// 아이템. 집행검