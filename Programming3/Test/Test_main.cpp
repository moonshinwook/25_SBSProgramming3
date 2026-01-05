
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
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept> // std::stoi 예외 처리를 위해 포함

#include "GameObject.h"


// --- main 함수 시작 (JSON 파싱 및 출력) ---

int main()
{
    cout << "JSON 파일 읽기" << endl;

    string filepath = "Monster_data.json";
    ifstream ifs(filepath);

    if (!ifs.is_open()) {
        cerr << "오류: " << filepath << " 파일을 열 수 없습니다. 파일 경로를 확인해주세요." << endl;
        return 1;
    }

    IStreamWrapper isw(ifs);
    Document doc;
    doc.ParseStream(isw);

    if (doc.HasParseError()) {
        cerr << "오류: JSON 파싱 오류 발생" << endl;
        return 1;
    }

    // 파싱된 Monster 객체들을 저장할 벡터
    std::vector<Monster> monsters;

    if (doc.IsArray())
    {
        for (SizeType i = 0; i < doc.Size(); i++)
        {
            const Value& obj = doc[i];

            // JSON 데이터의 모든 필수 멤버 존재 여부 및 타입 확인
            if (obj.IsObject() &&
                obj.HasMember("NAME") && obj["NAME"].IsString() &&
                obj.HasMember("HP") && obj["HP"].IsInt() &&
                obj.HasMember("ATK") && obj["ATK"].IsInt() && // ATK가 int 타입이라고 가정
                obj.HasMember("DEF") && obj["DEF"].IsInt() &&
                obj.HasMember("DEBUFF") && obj["DEBUFF"].IsInt() &&
                obj.HasMember("GOLD") && obj["GOLD"].IsInt()
                )
            {
                // Monster 객체 생성 및 벡터에 추가
                monsters.emplace_back(
                    obj["NAME"].GetString(),
                    obj["HP"].GetInt(),
                    obj["ATK"].GetInt(),
                    obj["DEF"].GetInt(),
                    obj["DEBUFF"].GetInt(),
                    obj["GOLD"].GetInt()
                );
            }
            else {
                cerr << "경고: 유효하지 않은 JSON 객체 구조 또는 타입이 발견되어 스킵합니다 (인덱스: " << i << ")" << endl;
            }
        }
    }
    else {
        cerr << "오류: JSON 파일의 최상위 요소가 배열(Array)이 아닙니다." << endl;
        return 1;
    }

    // 4. 예제 출력 (저장된 모든 몬스터 정보 출력)
    cout << "\n--- 몬스터 데이터 로드 완료 및 출력 ---" << endl;
    for (const auto& m : monsters)
    {
        m.displayStats();
    }
    cout << "--------------------------------------" << endl;

    return 0;
}