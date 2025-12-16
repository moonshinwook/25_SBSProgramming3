#include "Account.h"

// delegate 생성자

Account::Account() : Account{ default_currency }  // 시작 금액을 1000으로 ,:: 범위를 나타내는 스코프
{ 


}

Account::Account(int money) : currency(money)  // 멤버(currency) 변수 초기화
{
	iptr = new int;
}

Account::Account(const Account& other) : Account{ other.currency } 
{
	cout << "복사 생성자 호출" << endl;

	*iptr = *other.iptr; 
}

Account::Account(Account&& other) noexcept : currency(other.currency)
{
	cout << "이동 생성자 호출" << endl;
	//delete iptr;				// 이전 주소 지우기
	iptr = other.iptr;			// 다른 주소의 포인터로 옮기겠다.
	other.iptr = nullptr;		// 주소를 가르키지 말라.

}

Account::~Account()
{
	delete iptr;
}

int Account::withDraw(int amount)
{
	// 현재 내가 가진 돈 + amount 
	int temp = get_currency() - amount;
	set_currency(temp);
	int real = 0;
	if (get_currency() < amount)
	{
		real = get_currency();
	}
	set_currency(temp);

	return real;
}

void Account::deposit(int amount)
{
	if (amount < 0)
	{
		cout << "음수 금액을 예금할 수 없습니다. " << endl;
		return;
	}

	int temp = get_currency() + amount;

	set_currency(temp);
}
