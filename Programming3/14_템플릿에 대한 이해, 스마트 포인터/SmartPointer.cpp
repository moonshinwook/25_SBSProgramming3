#include "SmartPointer.h"

// 몬스터.
// 클래스(drop, stat...)

void Example1()
{
    cout << endl;
    cout << "Smart Point : Unique Example" << endl;


    UEx unique;
    unique.setPointer(std::make_unique<int>(20));
    unique.getValue();
    unique.setPointer(10);
    unique.getValue();
}

void Example2()
{
    cout << endl;
    cout << "Smart Point : Shared Example" << endl;
    Sharedptr shared;
    Sharedptr shared2;

    shared.setPointer(10);
    shared2.setPointer(shared.sptr);
    shared.getValue();
    shared2.getValue();

    cout << "공유 포인터가 가리키고 있는 수 : " << shared.sptr.use_count() << endl;      // 2
    shared.sptr.reset();
    cout << "공유 포인터가 가리키고 있는 수 : " << shared.sptr.use_count() << endl;      // 0
    cout << "공유 포인터가 가리키고 있는 수 : " << shared2.sptr.use_count() << endl;
    

}

void Example3()
{
    cout << endl;
    cout << "Smart Point : Weak Example" << endl;

    Police p1;
    Gun gun;
    p1.myGun = make_shared<Gun>(gun);
    gun.owner = make_shared<Police>(p1);

    gun.owner.reset();
    p1.myGun.reset();
    cout << p1.myGun.use_count() << endl;
    cout << gun.owner.use_count() << endl;
}
