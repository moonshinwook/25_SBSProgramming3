
    // 컨셉 
    // 중세 판타지 RPG, 플랫포머, 선형적 스토리
    // 주인공은 몬스터왕국의 왕인 용을 처치하러 가는 용사
    // 제목 : Kill that monster
    // 주제 : 왕국의 독재자 타도, 몬스터란 무엇인가(인간과 몬스터의 경계)  
    // 4막 구성
    // 20년 전 실종된 왕자 -> 용의 피를 가지고 있음 -> 3막 황금룡
    // 130살의 국왕 -> 50년의 독재자 -> 용사에게 몬스터 왕국 토벌 명령
    // 왕국의 명을 받고 용을 처치하러 가는 용사
    // 
    // 연출 (된다면)
    // 어릴 적 아이들의 무언갈 때리는 소리, 피로 물들어가는 바닥, 쓰러져있는 새끼 몬스터, 그걸 멀리서 바라보는 어린 주인공 
    // 눈동자 페이드아웃 -> 쓰러져있는 용사 일어남 -> 튜토리얼 시작 
    // 1막 배경: 동굴,                화면에 Chapter 1. '왕자' 글자 서서히 나오다가 서서히 사라짐  전투 중간 왕자의 시점 스토리 
    // 2막 배경: 숲,                  화면에 Chapter 2. '용사' 글자 서서히 나오다가 서서히 사라짐  전투 중간 용사의 시점 스토리 
    // 3막 배경: 폐허가 된 성과 마을, 화면에 Chapter 3. '국왕' 글자 서서히 나오다가 서서히 사라짐, 전투 중간 국왕의 시점 스토리 
    // 황금룡과의 전투에서 이긴 경우, 황금룡의 목걸이를 보며 회상씬
    // 왕국에서 검술을 가르쳐줬던 왕자님의 목걸이와 일치, 용사 충격을 받음, 피를 흘리는 황금룡, 물끄러미 바라보는 황금룡
    // 숲을 벗어난 용사, 멀리서 그를 지켜보는 황금룡, 그리고 멀리 다가오는 왕국의 용병들, 4막 시작
    // 4막 왕국, '괴물' 글자 서서히 나오다가 서서히 사라짐
    // 보이지 않는 국왕, 국왕의 의자 뒤 나타나는 비밀 공간, 드래곤의 피를 대량 주입하고 있는 국왕, 검은 흑룡으로 변화, 보스전
    // 
    // 게임 플레이
    // 방향키로 이동, E키 상호작용, I키 인벤토리, TAB 퀘스트창 및 Map, ESC 메뉴, 공격 A키, 스킬 q, w, e, r 
    // 
    // 흑막은 국왕이라 4막은 왕국 스테이지, 히든보스 국왕
    // 1막 2막 3막 보스 존재 
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
#include <conio.h> // _getch()를 사용하여 키 입력을 바로 받기 위함 (Visual Studio 환경)
#include <thread>
#include <chrono>

#include "Animation.h" // 우리가 만든 애니메이션 모듈 포함
#include "GameObject.h"

using namespace std;

// --- main 함수 시작 (JSON 파싱 및 출력) ---

      // 편의상 main 함수 위로 시나리오 함수들을 배치합니다.
void runOpeningCinematic() {
    ClearScreen();
    PrintSlowly("게임 제목: Kill that monster", 50);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    ClearScreen();

    PrintSlowly("어릴 적 아이들이 무언가를 때리는 소리가 들립니다...", 70);
    // 피로 물드는 연출 (빨간색 텍스트)
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    PrintSlowly("피로 물들어가는 바닥, 쓰러져있는 새끼 몬스터...", 100);
    // 색상 복구
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    PrintSlowly("그걸 멀리서 바라보는 어린 주인공...", 70);

    PrintSlowly("주인공의 눈동자가 페이드아웃 됩니다...", 50);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void runChapter1() {
    // 1막 배경 동굴, 화면에 Chapter 1. '왕자' 글자 서서히 나오다가 서서히 사라짐
    DisplayFadingTitle("Chapter 1. '왕자'", 4000);

    PrintSlowly("깊은 동굴 속에서 용사가 눈을 뜹니다.", 50);
    PrintSlowly("튜토리얼을 시작합니다...", 50);
    PrintSlowly("[방향키로 이동, E키 상호작용, A키 공격 등 조작법 안내...]", 30);
    // 여기서부터 게임 플레이 루프 (전투, 이동 등) 시작
}

void runChapter2() {
    DisplayFadingTitle("Chapter 2. '용사'", 4000);
    PrintSlowly("동굴을 벗어나 숲으로 진입합니다.", 50);
    // 2막 스토리 진행 및 플레이
}

void runChapter3() {
    DisplayFadingTitle("Chapter 3. '국왕'", 4000);
    PrintSlowly("폐허가 된 성과 마을에 도착합니다. 황금룡과의 전투가 임박했습니다.", 50);
    // 3막 스토리 진행 및 플레이
}

void runChapter4() {
    DisplayFadingTitle("Chapter 4. '괴물'", 4000);
    PrintSlowly("왕국에 도착한 용사. 국왕의 진실을 마주합니다.", 50);
    // 4막 스토리 진행 및 플레이 (히든 보스 국왕)
}


int main()
{
    /*  cout << "JSON 파일 읽기" << endl;

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

      return 0; */
        // 콘솔 제목 설정 (선택 사항)
        SetConsoleTitle(L"Kill that monster - Medieval Fantasy RPG");

        // 초기 화면 색상 설정 (밝은 흰색 텍스트, 검은색 배경)
        SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        runOpeningCinematic();


        std::cout << "\n[계속하려면 아무 키나 누르십시오...]";
        _getch(); // 키 입력 대기

        runChapter1();

        std::cout << "\n[계속하려면 아무 키나 누르십시오...]";
        _getch();

        runChapter2();

        // ... 챕터 3, 4 이어서 호출 ...

        std::cout << "\n게임 종료." << std::endl;

        return 0;

    }
