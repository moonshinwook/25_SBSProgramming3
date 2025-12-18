#include "Mystring.h"

Mystring::Mystring() : str(nullptr)
{
	str = new char[1];
	*str = '\0'; // std::ends와 같은 선언, null 문자
}

Mystring::Mystring(const char* source) : str(nullptr)
{
	str = new char[std::strlen(source) + 1]; // source의 길이 만큼 char 길이를 메모리에 저장하고 싶다, strlen() 길이 만큼 저장
	strcpy(str, source);				     // source 데이터를 str 복제 
}

Mystring::Mystring(const Mystring& other) : str(nullptr)
{
	str = new char[std::strlen(other.str) + 1]; // strlen은 11개를 사용할 시 마지막에 끝을 알려주는 
												//'/0' null 문자를 빼고 저장하여 +1을 하여 null 문자까지 저장
	strcpy(str, other.str);
}

Mystring::Mystring(Mystring&& rhs) noexcept : str(nullptr)  // nullptr로 초기화, 이동 생성자
{
	str = rhs.str;
	rhs.str = nullptr;
}

Mystring::~Mystring()
{
	delete[] str;  // 배열로 선언 시 제거도 배열로
}

Mystring Mystring::operator=(const Mystring& other)
{
	if (this == &other)
		return *this; // this가 주소이기 때문에 역참조 * 

	delete[] str;
	str = new char[std::strlen(other.str) + 1];
	std::strcpy(str, other.str);


	return *this;
} 
// return Mystring은 null문자를 넣어준 상태이기 때문에 "이순신" 문자가 저장이 안됌. 
// 복사 코드 선언을 통해서 이순신 문자 저장할 수 있도록 해결.

Mystring Mystring::operator=(Mystring&& rhs) noexcept
{
	if (this == &rhs)
		return *this; // this가 주소이기 때문에 역참조 * 

	delete[] str;
	str = rhs.str;
	rhs.str = nullptr;
	
	return *this;

}


Mystring Mystring::CopyAssignment(const Mystring& other)
{
	if (this == &other)
		return *this; // this가 주소이기 때문에 역참조 * 

	delete[] str;
	str = new char[std::strlen(other.str) + 1];
	std::strcpy(str, other.str);


	return *this;
}

ostream& operator<<(ostream& os, const Mystring& obj)
{
	os << obj.str;
	return os;
}

// friend 기능 구현 '+' 을 위해서
Mystring operator+(const Mystring& lhs, const Mystring rhs) // 인자를 왼쪽 오른쪽 받도록 구현
{
	// 새로운 문자의 길이 = this.str 길이 +  other.str 길이 + 널문자(1) 
	char* buffer = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];		// buffer 공간 정의
	strcpy(buffer, lhs.str); // buffer[시작 ~ A]
	strcat(buffer, rhs.str); // buffer[A ~ other길이]

	Mystring temp(buffer); // const char* 매개변수로 하는 생성자 호출, 새로운 객체 temp를 하나 선언,  
	delete[] buffer;	   // 사용을 다한 buffer 공간을 메모리 해제

	return temp;
}
