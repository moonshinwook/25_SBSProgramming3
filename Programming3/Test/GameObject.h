#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;


using namespace std;

// 부모 클래스 (Parent/Base Class)
class GameObject
{
private:
    int HP;
    int ATK;
    int DEF;
    int DEBUFF;

public:
    // 편의를 위해 GameObject에 간단한 생성자와 getter/setter를 추가했습니다.
    GameObject(int hp, int atk, int def, int debuff)
        : HP(hp), ATK(atk), DEF(def), DEBUFF(0) {}
    GameObject(); // default

    int getHP() const { return HP; }
    void setHP(int hp) { HP = hp; }
    int getATK() const { return ATK; }
    void setATK(int atk) { ATK = atk; }
    int getDEF() const { return DEF; }
    void setDEF(int def) { DEF = def; }
    int getDEBUFF() const { return DEBUFF; }
    void setDEBUFF(int def) { DEBUFF = 0; }

    // ... 다른 getter/setter 생략 ...
};

// 자식 클래스 (Child/Derived Class) - Player
// public 상속을 사용하여 GameObject의 public 인터페이스를 상속받습니다.
class Player : public GameObject
{
private:
    string playerName;
    int gold;

public:
    // Player 생성자는 부모 클래스(GameObject)의 생성자를 호출해야 합니다.
    Player(const string& name, int hp, int atk, int def, int debuff, int gold)
        : GameObject(hp, atk, def, debuff), playerName(name), gold(gold) {
    }

    void displayStats() const {
        cout << "플레이어 이름: " << playerName << 
             " HP: " << getHP() << "ATK: " << getATK() << "DEF :" << getDEF() << 
            " 소지금: " << gold
            << endl;
    }
};

// 자식 클래스 (Child/Derived Class) - Monster
// public 상속을 사용하여 GameObject의 public 인터페이스를 상속받습니다.
class Monster : public GameObject
{
private:
    string monsterName;
    int Gold; // 몬스터 처치 시 얻는 경험치

public:
    // Monster 생성자는 부모 클래스(GameObject)의 생성자를 호출해야 합니다.
    Monster(const string& name, int hp, int atk, int def, int debuff, int gold)
        : GameObject(hp, atk, def, debuff), monsterName(name), Gold(gold) {
    }

    void displayStats() const {
        // hp 대신 부모의 getter 함수인 getHP() 사용
        cout << "몬스터 종류 : " << monsterName
            << " | 체력 : " << getHP() // getHP() 함수 호출
            << " | 공격력 : " << getATK() // 다른 정보도 추가 가능
            << " | 방어력 : " << getDEF()
            << " | 디버프 : " << getDEBUFF()
            << endl;
    }

    void Monsterappeared() const {
        cout << monsterName << " 이(가) 나타났습니다." << endl;
    }
};



