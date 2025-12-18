#pragma once

#include "Moveable.h"

class Moveable
{
private:
    Moveable* mov;
public:
    Moveable(); // 기본 생성자
    Moveable(const Moveable& other);
    Moveable(Moveable&& rhs);
    ~Moveable();

    void Move();
};

