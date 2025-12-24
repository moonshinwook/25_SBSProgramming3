#include "ConsoleRender.h"
#include "Run_GameObject.h"

int main()
{
    ConsoleRender console;

    Run_GameObject* goArray[7];
    
    goArray[0] = new Run_GameObject;
    goArray[1] = new Run_GameObject(80,6, "cpp run project", 5);
    goArray[2] = new Run_GameObject(80,6, "speedy", 1);
    goArray[3] = new jump_GameObject(80, 6, "jump", 1, 2);
    goArray[4] = new jump_GameObject(80, 10, "jump", 2, 3);
    goArray[5] = new jump_GameObject(50, 10, "aa", 3, 3);
    goArray[6] = new dash_GameObject(80, 6, "bb", 1, 8);

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

        for (const auto& go : goArray) // 복제를 자제시킴. 최적화
        {
            go->update();
        }
        console.ScreenClear();



   
        // Rendering
        // player->draw(console);

        for (const auto& go : goArray)
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