#include "Pos.h"

Pos::Pos() : Pos(0,0){}
Pos::Pos(int x, int y) : x(x), y(y){}
Pos::Pos(const Pos& other) : Pos(other.x, other.y){}
Pos::Pos(Pos&& rhs) noexcept = default;
Pos::~Pos() = default;

bool Pos::operator==(const Pos& other)
{
    return (x == other.x && y == other.y);
}

bool Pos::operator!=(const Pos& other)
{
    return !(*this == other); // 나 자신과 다른 것과 비교, 같으면 반대되는 것을 반환하라
}

Pos Pos::operator=(const Pos& other)
{
    if (this == &other)
        return *this;

    x = other.x;
    y = other.y;

}

void Pos::Teleport(Pos* other)
{
    x = other->x;
    y = other->y;
}

void Pos::Move(int x, int y)
{
    this->x += x;
    this->y += y;
}

ostream& operator<<(ostream& os, const Pos& pos)
{
    os << "[ x : " << pos.x << "," << " y: " << pos.y << " ]" << endl;
    return os; // os를 저장해서 밖으로 보내겠다
}

istream& operator>>(istream& is, Pos& pos)
{
    int x = 0, y = 0;
    cout << "x의 값 : ";
    is >> x;
    // is >> pos.x; 주소로 접근할 시 오류가 발생할 수 있음.
    cout << "y의 값 : ";
    is >> y;
    pos = Pos{ x,y };


    return is;
}
