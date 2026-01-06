#include <iostream>
#include <vector>
#include <algorithm>
#include <String>
#include "Player.h"
#include "Monster.h"
#include <Windows.h> // Sleep();


using namespace std;

class Player;
class Monster;

// STL c++ 개발자(게임) - STL 잘 아는가?
// Standard Template Library (신뢰할 수 있는 라이브러리)
// 자료구조 - 알고리즘

// 컨테이너 알고리즘(Algorithm) 반복자(iterator)



// Room 게임 등장하는 게임 요소를 인카운트 시키는 객체이다. 
// iterator<Room> iterator++

struct CompareStrength
{
    bool operator()(const Monster* a, const Monster* b)
    {
        return a->GetStrength() < b->GetStrength();
    }
};


// 반복이 계속되는 것을 피하고 싶다.
// 조금더 최적화된 코드를 작성하고 싶다. 어떤 기준으로 판별할 것인가? 자료구조, 알고리즘.

class Room
{
private:
    vector<GameObject*> roomObjects;

    // roomObjects 안에 있는 데이터 중에서 몬스터 타입인 녀석들만 뽑아서 AvailableMonsters 재정렬을 하세요.

    vector<Monster*> AvailableMonsters; // 랜덤한 몬스터들이 배정되어 있다. 
    vector<Monster*> settingMonsters; // 약한 몬스터가  0번 배열에 저장이 되어 있다.

    vector<TreasureObject*> roomTreasures; // 방에서 생성될 수 있는 보물 정보
public:
    void Initialize(const vector<Monster*>& copyMonsters) 
    {
        AvailableMonsters = copyMonsters;
    }

    void SetTreasureRoom(TreasureObject* tr)
    {
        roomTreasures.push_back(tr);
    }

    // 몬스터 들의 강함 순위를 정해서 약한 몬스터가 앞에서 등장하게 구현하고 싶다. (순서를 재정렬하고 싶다.)

    void SetOrder()  // 알고리즘 라이브럴리를 가져와서 코드를 실행하겠다. 
    {
        settingMonsters = AvailableMonsters;
        sort(settingMonsters.begin(), settingMonsters.end(), CompareStrength());

        for (const auto& go : settingMonsters)
        {

            roomObjects.push_back(go);
        }

        for (const auto& go : roomTreasures)
        {
            roomObjects.push_back(go);
        }
    }

    int RoomCount() { return roomObjects.size(); }

    GameObject* Encount(int roomIndex) { return roomObjects[roomIndex]; }
    //int arr[5]  arr(주소) + 1      [i0] [i1] [i2] [3] [4]
    // int* arr;
};

// player, battleManager


class BattleManager 
{
private:                                             // GameObject->virtual void RoomEntryEvent(); // 몬스터방->전투, 보물상자->상자획득, 함정->함정,....
    void Battle(Player* player, BattleObject* other) // * 주의, player와 monster가 싸우는 버전.
    {
        // 턴
        while (true)
        {


            int playerIndex = 0;
            cout << "플레이어 턴" << endl;

            // ----------------턴마다 일어나야 하는 일 : 마나 수정 1, 빈 마나 수정 -> 최대 개수만큼 채워준다.
            // 내가 먼저 공격 
            cin >> playerIndex; // 잠시 대기
            player->Attack(other);


            // ....
            cout << "적의 턴!" << endl;
            other->Attack(player); // & 주소연산자를 사용하지 않기 위해 위에 Player에 *을 사용해서 -> 사용

            Sleep(1000);
            cout << " 모든 적의 턴 끝날 때까지 대기 중... " << endl;

            if (player->IsDeath() || other->IsDeath())
            {
                break;
            }
        }

        // 몬스터가 죽었으면 다음 전투 진행.
        // 플레이어가 죽었으면 게임 종료
        if (player->IsDeath()) 
        {
            return;
        }

        // 몬스터가 사망했을 때 
        if (other->IsDeath())
        {
            // 몬스터를 처치했습니다.

            // 보상을 얻었습니다.

            // 

            // 잠시 기다렸다가 나가세요.
            Sleep(1000);
        }
    }

    void GetTreasure(TreasureObject* tr)
    {
        tr->GetTreasure();
    }

public:

    void PlayRoom(Player* player, Room& room);
};

inline void BattleManager::PlayRoom(Player* player, Room& room)
{
    int battleCount = room.RoomCount();

    for (int i = 0; i < battleCount; i++)
    {
        // 전투

        cout << i + 1 << "번째 방에서 플레이어가 진입했습니다." << endl;

        // 첫번째 방에 있는 오브젝트[몬스터]와 조우했다. 

        // i번방에 있는 요소가 몬스터 이외의 정보도 가질 수 있으면 좋겠어.
        GameObject* obj = room.Encount(i);

        if (BattleObject* mon = dynamic_cast<BattleObject*>(obj))/*obj 만약에 BattleObject* 타입이면*/
        {
            //Battle함수를 실행할거예요.
            // 타입을 변경하는 문법 Type Casting. 
            Battle(player, mon);
        }
        else if (TreasureObject* tr = dynamic_cast<TreasureObject*>(obj))
        {
            // 플레이어가 getTreasure 실제로 Get했다.
            //player->GetItem(Item);
            tr->GetTreasure(); // money, string -> Item 클래스 다시 재정의
            //Item* tempItem = new Item(tr->money, tr->contents);
            //player->GetItem(tempItem);  // TreasureItem, WeaponItem, UseItem, BuffItem.........
            
            // TODO (나중에 추가할 내용)

            cout << "아이템을 저장하고 있습니다." << endl;
            Sleep(1000);
        }


        // obj -> Type : 3가지. 행동을 할 수 있다.
        // 배틀 : Battle();
        // 보물 : GetTreasure();
        // 휴식 : Rest();

        if (player->IsDeath())
        {
            cout << i + 1 << "번째 방에서 플레이어가 사망했습니다." << endl;
            return;
        }

        system("cls");
    }
}
int main ()
{

    cout << "16강 STL 예제" << endl;

    Room room0;
    vector<Monster*> copyMonsters;

    copyMonsters.push_back(new Monster(2, RoomObjectType::BATTLE, 700, 7, "C"));
    copyMonsters.push_back(new Monster(1, RoomObjectType::BATTLE, 500, 5, "A"));
    copyMonsters.push_back(new Monster(4, RoomObjectType::BATTLE, 600, 6, "B"));
    copyMonsters.push_back(new Monster(3, RoomObjectType::BATTLE, 800, 8, "D"));

    room0.SetTreasureRoom(new TreasureObject(10001, RoomObjectType::TREASURE, 500, "보물상자"));
    
    room0.Initialize(copyMonsters);
    room0.SetOrder();

    // stage 클래스. 클래스 vector Room타입을 가지고 있고, 클래스가 모든 Room 다 클리어하면 해당 stage 끝

    

    Player* player= new Player;
    // room에 있는 몬스터와 만났다. 
    BattleManager _bm;

    Room room1;
    Room room2;
    Room room3;


    //Stage.push_back(room0);
    //Stage.push_back(room1);
    //Stage.push_back(room2);
    //Stage.push_back(room3);

    // --------------------------------------------------------- 데이터 설정 --------------------------------- // 
    
    while (true)
    {
        // 입력

        // 갱신

        // 렌더링
    }

    string stageName = "room" + 0;

    // Type이름을 이용해서 Room 클래스로 형변환
    _bm.PlayRoom(player,room0); // 스테이지 -> 1 2 3 4 5 
    //stageIndex++;
    // 렌더링
}

