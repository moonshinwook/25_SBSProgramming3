#pragma once
#include <iostream>
#include <string>


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

// --- 클래스 정의 시작 (제공된 코드) ---

// 부모 클래스 (Parent/Base Class)
class GameObject
{
private:
    int HP;
    int ATK;
    int DEF;
    int DEBUFF;

public:
    GameObject(int hp, int atk, int def, int debuff)
        : HP(hp), ATK(atk), DEF(def), DEBUFF(debuff) {
    }

    // 기본 생성자 추가 (vector 사용 시 필요할 수 있음)
    GameObject() : HP(0), ATK(0), DEF(0), DEBUFF(0) {}

    int getHP() const { return HP; }
    int getATK() const { return ATK; }
    int getDEF() const { return DEF; }
    int getDEBUFF() const { return DEBUFF; }
};

// 자식 클래스 (Child/Derived Class) - Monster
class Monster : public GameObject
{
private:
    string monsterName;
    int Gold; // 몬스터 처치 시 얻는 골드

public:
    // Monster 생성자는 부모 클래스(GameObject)의 생성자를 호출하고 Gold를 초기화
    Monster(const string& name, int hp, int atk, int def, int debuff, int gold)
        : GameObject(hp, atk, def, debuff), monsterName(name), Gold(gold) {
    }

    // 기본 생성자 추가
    Monster() : GameObject(), monsterName(""), Gold(0) {}

    void displayStats() const {
        cout << "몬스터 종류 : " << monsterName
            << " | 체력 : " << getHP()
            << " | 공격력 : " << getATK()
            << " | 방어력 : " << getDEF()
            << " | 디버프 : " << getDEBUFF()
            << " | 골드 : " << Gold
            << endl;
    }
};

// --- 클래스 정의 끝 ---
