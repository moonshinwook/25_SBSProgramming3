#pragma once
#include "Pos.h"

class Moveable 
{
private:
    Pos* pos;
public:
    Moveable(); // 기본 생성자
    Moveable(Pos* pos);
    Moveable(const Moveable& other);
    Moveable(Moveable&& rhs);
    ~Moveable();

    void Move(int x, int y);
    void Teleport(Pos* other);

    Pos& get_pos() const;     //      const Player ->  함수 실행
    void display_pos() const; //
};

