#include "Run_GameObject.h"

Run_GameObject::Run_GameObject(int x, int y, string shape, int speed, int movetick)
    : x(x), y(y), shape(shape), speed(speed), movetick(movetick)
{
}

Run_GameObject::Run_GameObject() : Run_GameObject(80, 5, "This is example", 3) // 기본으로 하겠다. 
{
}

void Run_GameObject::update()
{
    // 속도 변수(3). 속도를 체크하는 tick(0)
    movetick++;
    if (speed <= movetick) // 내가 움직이고 싶은 속도에 도달했을 때 
    {
        // 움직여라 코드. (다형성을 가지게 만들어라)
        move();

        movetick = 0; // 초기화 필요. 다음 실행에서 수행하도록
    }




}

void Run_GameObject::draw(ConsoleRender& console)
{
    console.ScreenPrint(x, y, shape);
}

void Run_GameObject::move()
{
    x--;
    if (x <= 0) { x = 80; }
}

jump_GameObject::jump_GameObject(int x, int y, string shape, int speed, int jumpPower, int movetick)
    : Run_GameObject(x, y, shape, speed), jumpPower(jumpPower)
{
    jumpTime = 15;    // 30장 -> 0.5초
    jumptick = 0;
    isGround = true;
}

jump_GameObject::jump_GameObject() : Run_GameObject(), jumpPower(2)
{
    jumpTime = 15;
    isGround = true;
}

void jump_GameObject::move()
{
    jumptick++;
    if (jumpTime <= jumptick) // 내가 움직이고 싶은 속도에 도달했을 때 
    {
        if (isGround)
        {
            y -= jumpPower;
        }
        else
        {
            y += jumpPower;
        }
        isGround = !isGround;
        jumptick = 0;
    }

    Run_GameObject::move();

    //     x--;
    // if (x <= 0) { x = 80; } 를 복사한 것
}

dash_GameObject::dash_GameObject(int x, int y, string shape, int speed, int dashPower, int movetick)
    : Run_GameObject(x, y, shape, speed), dashPower(dashPower)
{
    dashTime = 10;    // 30장 -> 0.5초
    dashtick = 3;
}

dash_GameObject::dash_GameObject() : Run_GameObject(), dashPower(1)
{
    dashTime = 10;
}

void dash_GameObject::move()
{
    dashtick++;
    if (dashTime <= dashtick) // 내가 움직이고 싶은 속도에 도달했을 때 
    {
        dash();

        dashtick = 0;
    }

    Run_GameObject::move();
}

void dash_GameObject::dash()
{
    x -= dashPower;
}
