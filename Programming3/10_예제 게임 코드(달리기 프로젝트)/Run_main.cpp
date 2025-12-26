#include "ConsoleRender.h"
#include "Run_GameObject.h"

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

int main()
{
    ConsoleRender console;

    string filepath = "C:\\Users\\Administrator\\Desktop\\25_SBSProgramming3\\Programming3\\10_예제 게임 코드(달리기 프로젝트)\\Run_object.json";
    
    Run_GameObject* goArray[7];
    
    goArray[0] = new Run_GameObject;
    goArray[1] = new Run_GameObject(80,6, "cpp run project", 5);
    goArray[2] = new Run_GameObject(80,6, "speedy", 1);
    goArray[3] = new jump_GameObject(80, 6, "jump", 1, 2);
    goArray[4] = new jump_GameObject(80, 10, "jump", 2, 3);
    goArray[5] = new jump_GameObject(50, 10, "aa", 3, 3);
    goArray[6] = new dash_GameObject(80, 6, "bb", 1, 8);

    ifstream ifs(filepath);

    // 2. 파일 읽기
    IStreamWrapper isw(ifs);
    Document doc;
    doc.ParseStream(isw);

    std::vector<Run_GameObject*> runObjects;

    // 3. 타입 변환(Parse)
        if (doc.IsArray())
        {
            for (int i = 0; i < doc.Size(); i++)
            {
                const Value& obj = doc[i];

                if (obj.IsObject())                 // josn에서 "{ }" 묶여있나?
                {
                    if (obj.HasMember("X") && obj["X"].IsInt() && // 데이터 체크 조건 1.x 좌표
                        obj.HasMember("Y") && obj["Y"].IsInt() &&
                        obj.HasMember("Shape") && obj["Shape"].IsString() &&
                        obj.HasMember("Speed ") && obj["Speed "].IsInt() &&
                        obj.HasMember("jumpPower") && obj["jumpPower"].IsInt() 
                        )
                    {
                        Run_GameObject* r;
                        if (obj["jumpPower"].GetInt() == 0)
                        {
                            r = new Run_GameObject(obj["X"].GetInt(), obj["Y"].GetInt(), obj["Shape"].GetString(), obj["Speed "].GetInt());
                        }
                        else
                        {
                            r = new jump_GameObject(obj["X"].GetInt(), obj["Y"].GetInt(), obj["Shape"].GetString(), obj["Speed "].GetInt()
                                , obj["jumpPower"].GetInt());
                        }
                        
                        // 만약에 r의 enum타입이 일반 타입이면 run_GameObject

                        //enum타입이 jump타입이면 new jump_gameonject(80, 6, "jump, 1, 2)

                        runObjects.push_back(r);
                    }
                }


            }
        }



    while (true)
    {
        // 플레이어 입력 player->update

        // player->update();

        // gameobject->Update

        //for (int i = 0; i < 4; i++)
        //{
        //    goArray[i]->update();
        //}
        //for (int i = 0; i < 4; i++)
        //{
        //    goArray[i]->draw(console);
        //}

        for (const auto& go : runObjects) // 복제를 자제시킴. 최적화
        {
            go->update();
        }
        console.ScreenClear();



   
        // Rendering
        // player->draw(console);

        for (const auto& go : runObjects)
        {
            go->draw(console);
        }
       
        // Flip
        console.ScreenFlipping();

        // 고정 대기 시간 Frame Per Second
        Sleep(17);  // 대략  60프레임.  1000 / 60 = 16.666
    }
    delete goArray;

}