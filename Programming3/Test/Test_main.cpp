#include <iostream>

using namespace std;

    // 컨셉 왕국의 명을 받고 용을 처치하러 가는 용사
    // 흑막은 국왕이라 4막은 왕국 스테이지, 히든보스 국왕
    // 1막 2막 3막 각각 용이 보스로 존재 
    // 플레이어, 몬스터 클래스 각각 체력, 공격력, 방어력 선언
    // 몬스터 종류 노멀, 엘리트, 보스
    // 몬스터 행동 종류 : 공격, 다중공격, 수비, 보호, 버프, 디버프, 디버프&공격
    // 엘리트, 보스 몬스터 : 특수기술 1개 이상 가짐. 2페이즈 존재
    // 
// 사용 예시
int main() {
    // Player 클래스 객체 생성
    Player p("용사 킴", 100, 20, 10, 5);
    p.displayStats();

    // Monster 클래스 객체 생성
    Monster m("슬라임", 30, 5, 2, 10);
    m.attackTarget();
    std::cout << "슬라임 HP: " << m.getHP() << std::endl;

    return 0;
}

  