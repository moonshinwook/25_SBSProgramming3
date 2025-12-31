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

    shared_ptr<Police> p1 = make_shared<Police>(); // new Poliec() 대신 사용한다;
    shared_ptr <Gun> gun = make_shared<Gun>();
    p1->myGun = gun; // 경찰이 소유한 총이 Gun을 가리킨다.
    gun->owner = p1;

    cout << p1->myGun.use_count() << endl;
    cout << gun->owner.use_count() << endl;
}
