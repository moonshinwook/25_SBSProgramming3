#pragma once

#include <iostream>

using namespace std;

// 어떤 데이터를 저장해야 하는가? 멤버 변수

// 어떤 기능을 처리하는가? withdraw(인출) deposit(저축)

// 클래스랑 함께 사용하면 좋은 키워드

// Getter(가져오게 해주는 것) Setter(변경할 수 있게 하는 것) 함수 표현
// 기본으로 주는 금액을  1000 -> 10000

// class 정의
class Account
{
private:
	static constexpr int default_currency = 10000;
	int currency;
	int* iptr;
public:		
	Account();								   // 초기화를 위한 생성자. default, no args (기본 생성자)
	Account(int money);						   // 중첩 정의 생성자 overloead constructor
	Account(const Account& other);			   // 복사 생성자 copy constructor 참조하여 다른 곳에 복제할 것이다. 복제용이니 const로 고정
	Account(Account&& other) noexcept;		   // RValue 타입, 이동 생성자 move
	~Account();								   // 소멸자(클래스 이름과 같은 이름) 선언
	
	// Getter Setter 함수를 만드세요.
	int get_currency() const 
	{
		return currency; 
	} // 함수를 const화 시키는 키워드
	void set_currency(int money)
	{ 
		currency = money; 
		if (currency < 0) { currency = 0;  }	// 보완 코드 
	}

	// (기능) 멤버 함수, 메소드(method)
	int  withDraw(int amount);
	void deposit(int amount);

	// 연산자 오버로딩
};






