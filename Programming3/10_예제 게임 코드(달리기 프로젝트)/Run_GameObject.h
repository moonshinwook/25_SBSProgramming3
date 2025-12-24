#pragma once

#include <string>
#include "ConsoleRender.h"

using namespace std;

class Run_GameObject
{
private:
  
    string shape;
    int speed;
    int movetick;
protected:
    int x;
    int y;
public:
    Run_GameObject(int x, int y, string shape, int speed, int movetick = 0);
    Run_GameObject(); // default

    void update();
    void draw(ConsoleRender& console);
    virtual void move(); // 상속하는 다른 move를 실행하겠다.
};

class jump_GameObject : public Run_GameObject
{
private:
    int jumpPower;
    bool isGround;
    int jumpTime;
    int jumptick;
public:
    jump_GameObject(int x, int y, string shape, int speed, int jumpPower, int movetick = 0);
    jump_GameObject();
    virtual void move() override;
};

class dash_GameObject : public Run_GameObject
{
private:
    int dashPower;
    int dashTime;
    int dashtick;
public:
    dash_GameObject(int x, int y, string shape, int speed, int dashPower, int movetick = 0);
    dash_GameObject();
    void move() override;

    void dash();
};

