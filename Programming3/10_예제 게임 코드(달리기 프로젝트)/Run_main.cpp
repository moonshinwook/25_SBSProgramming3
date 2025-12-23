#include "ConsoleRender.h"
#include "Run_GameObject.h"

int main()
{
    ConsoleRender console;

    Run_GameObject* goArray[4];

    Run_GameObject* go1 = new Run_GameObject;
    Run_GameObject* go2 = new Run_GameObject(80,6, "cpp run project", 5);
    Run_GameObject* go3 = new Run_GameObject(80,6, "speedy", 1);
    Run_GameObject* go4 = new jump_GameObject(80, 6, "jump", 1, 2);

    while (true)
    {
        // 플레이어 입력 player->update

        // gameobject->Update

        //for (int i = 0; i < 4; i++)
        //{
        //    goArray[i]->update();
        //}
        //for (int i = 0; i < 4; i++)
        //{
        //    goArray[i]->draw(console);
        //}

        go1->update();
        go2->update();
        go3->update();
        go4->update();

        
        // Rendering
        console.ScreenClear();
        go1->draw(console);
        go2->draw(console);
        go3->draw(console);
        go4->draw(console);
       
        // Flip
        console.ScreenFlipping();

        // 고정 대기 시간 Frame Per Second
        Sleep(17);  // 대략  60프레임.  1000 / 60 = 16.666
    }
    delete go1;
    delete go2;
    delete go3;
    delete go4;
}