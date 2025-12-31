#include "Skill.h"
#include <conio.h>

bool Passive_Skill::IsAvailable()
{
    // Update 구조.   Timetick 4씩, 4초마다 실행되는 패시브.

    return false;
}

void Passive_Skill::Execute()
{
    if (IsAvailable())
    {
        // 로직을 실행하라
    }
}

bool Active_Skill::IsAvailable()
{
    // 플레이어가 입력을 했을 때.
    // 쿨타임이 아닐 때.

    return false;
}



void Active_Skill::Execute()
{
    if (IsAvailable())
    {

    }
}

void Garen_Passive::Execute()
{ 
    cout << "가렌이 8초 동안 피해를 입지 않거나 적의 스킬에 맞지 않으면 5초마다 최대 체력의 일정 비율을 레벨만큼 회복합니다." << endl;
}

bool Garen_Q::IsAvailable()
{
    timeTick++; // 시간 체크
    if (timeTick >= coolcheck)
    {
        timeTick = 0;
        return true;
    }

    return false;
}


void Garen_Q::Execute()
{
    if (IsAvailable())
    {
        cout << "가렌에게 적용된 모든 둔화 효과가 제거되고 일정 시간 동안 이동 속도가 35% 상승합니다." << endl;
        cout << "다음 기본 공격은 1.5초 동안 군중제어 침묵시키고 추가 물리 피해를 입힙니다." << endl;

        coolcheck = coolTime;
    }
}

bool Garen_W::IsAvailable()
{
    timeTick++; // 시간 체크
    if (timeTick >= coolTime)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_W::Execute()
{
    if (IsAvailable())
    {
        cout << "기본 지속 효과: 유닛을 처치하면 영구적으로 0.2의 방어력과 0.2의 마법 저항력이 부여되어 최대 30까지 증가합니다." << endl;
        cout << "사용 시: 가렌이 4초 동안 용기백배하여 받는 피해가 감소합니다. 또한 0.75초 동안 일정 피해를 흡수하는 보호막과 60%의 강인함을 얻습니다." << endl;

        coolcheck = coolTime;
    }
}

bool Garen_E::IsAvailable()
{
    timeTick++; // 시간 체크
    if (timeTick >= coolTime)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_E::Execute()
{
    if (IsAvailable())
    {
        cout << "가렌이 3초 동안 검을 들고 빠르게 회전하여 물리 피해를 여러 차례 입힙니다.가장 가까운 적을 대상으로는 25 % 의 추가 피해를 입힙니다." << endl;
        cout << "공격에 6번 맞은 챔피언은 6초 동안 방어력이 25% 감소합니다." << endl;

        coolcheck = coolTime;
    }
}

bool Garen_R::IsAvailable()
{
    timeTick++; // 시간 체크
    if (timeTick >= coolTime)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_R::Execute()
{
    if (IsAvailable())
    {
        cout << "가렌이 적을 처단할 데마시아의 힘을 소환하여 잃은 체력의 일정 비율에 해당하는 고정 피해를 입힙니다." << endl;
        cout << "150 / 250 / 350 (+대상이 잃은 체력의 25% / 30% / 35%)" << endl;

        coolcheck = coolTime;
    }
}

void Player::update()
{
    // keyavailable
    // kbhit()
    // 'q', 'w', 'e', 'r' key값

    char key = _getch();
        // 입력된 키에 따른 처리
    switch (key) {
    case 'q': case 'Q': useSkill(1); break;
    case 'w': case 'W': useSkill(2); break;
    case 'e': case 'E': useSkill(3); break;
    case 'r': case 'R': useSkill(4); break;
    default:
        // q, w, e, r 이외의 키 처리 (필요시)
        break;
    }


    useSkill(0);
}

// 스킬을 습득.
void Player::setSkill(unique_ptr<Skill> skill)
{
    skills.push_back(move(skill));    // copy
}

void Player::useSkill(int index)
{
    //skills['q']->Execute();
    //skills['w'];

    skills[index]->Execute();
}
