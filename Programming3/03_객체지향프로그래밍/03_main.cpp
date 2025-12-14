#include <iostream>
#include "Person.h"

using namespace std;

// c vs cpp 차이점
// c언어 - 절차 지향 언어 - 함수들로 구성되어 진 프로그램
// cpp - 객체 지향 언어 - 객체들로 구성된 프로그램

// c언어 프로그래밍을 하면서 겪었던 문제점
// 구조체 안의 데이터를 추가해서 사용을 해야한다.
// 프로그래밍의 확장이 어려워진다.
// 모든 객체의 정보를 알고 있어야 함수를 다룰 수 있다. 
// 프로그램이 커지면 커질수록 다루기가 어려워진다.

// 주소 복사를 하는 경우 delete 시 주소 전부 삭제로 복사한 부분에 문제 발생. (얕은 복사 문제)  
// 얕은 복사(shallow copy), 깊은 복사 (deep copy)






int main()
{
	cout << "3강" << endl;

	Person p1{};
	Person p2(20, "홍길동", "부산");

	p1.ToString();
	p2.ToString();

	Person p3(1000, 20, "김김김", "서울");
	p3.ToString();

	Person p4(500, 30, "춘향이", "조선", "미인"); 

	// 직접 클래스를 동적할당 해보자.
	Person* p_ptr{} = new Person(500, 30, "몽룡이", "조선", "양반");
	delete p_ptr;

}