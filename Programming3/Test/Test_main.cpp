#include <iostream>

using namespace std;

    // 컨셉 왕국의 명을 받고 용을 처치하러 가는 용사
    // 흑막은 국왕이라 4막은 왕국 스테이지, 히든보스 국왕
    // 1막 2막 3막 각각 용이 보스로 존재 
    // 가지치기 형식의 길, 상점 존재, 갈림길 선택으로 
    // 플레이어, 몬스터 클래스 각각 체력, 공격력, 방어력 선언
    // 몬스터 종류 노멀, 엘리트, 보스
    // 몬스터 행동 종류 : 공격, 다중공격, 수비, 보호, 버프, 디버프, 디버프&공격
    // 엘리트, 보스 몬스터 : 특수기술 1개 이상 가짐. 2페이즈 존재
    // 
    // 
    // 
// 사용 예시
#include "GameObject.h"
#include <vector>

int main() {
    // 1. Player 객체 생성 및 상속 테스트
    cout << "--- 플레이어 객체 테스트 ---" << endl;
    Player p1("Hero", 200, 30, 20, 0, 100);
    p1.displayStats();
    cout << endl;

    // 2. JSON 파일에서 몬스터 데이터 로드 및 Monster 객체 생성 테스트
    cout << "--- JSON 파일 로드 및 몬스터 객체 테스트 ---" << endl;

    // 파일 경로 설정 (질문에서 제공된 경로 사용)
    const string filePath = "C:\\Users\\msw47\\OneDrive\\바탕 화면\\25_SBSProgramming3\\Programming3\\Test\\Monster_data.json";

    ifstream ifs(filePath);
    if (!ifs.is_open()) {
        cerr << "Error: JSON 파일을 열 수 없습니다. 경로를 확인하세요: " << filePath << endl;
        // 디버깅을 위해 현재 작업 디렉토리도 출력해볼 수 있습니다.
        // cerr << "Current working directory might be relevant if path is relative." << endl;
        return 1;
    }

    IStreamWrapper isw(ifs);
    Document doc;
    doc.ParseStream(isw);

    if (doc.HasParseError()) {
        cerr << "Error: JSON 파싱 실패." << endl;
        return 1;
    }

    if (doc.HasMember("monsters") && doc["monsters"].IsArray()) {
        const Value& monsters = doc["monsters"];
        vector<Monster> monsterList;

        for (SizeType i = 0; i < monsters.Size(); i++) {
            const Value& m = monsters[i];
            Monster newMonster(
                m["name"].GetString(),
                m["hp"].GetInt(),
                m["atk"].GetInt(),
                m["defense"].GetInt(),
                m["debuff"].GetInt(),
                m["gold"].GetInt()
            );
            monsterList.push_back(newMonster);
        }

        // 로드된 몬스터 정보 출력
        for (const auto& mon : monsterList) {
            mon.displayStats();
            mon.Monsterappeared();
        }
    }
    else {
        cerr << "Error: 'monsters' 배열을 JSON 파일에서 찾을 수 없습니다." << endl;
    }

    return 0;
}

  