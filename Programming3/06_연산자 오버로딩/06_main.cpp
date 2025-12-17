#include <iostream>
#include <string>  
#include "Mystring.h"
using namespace std;

// std::string 클래스를 직접 구현하기

int main()
{
	std::cout << "string 클래스를 이해해보자" << std::endl;
	std::string str = "Hello World";
	//char* str2 = "Hello world"; // 리터럴 문자는 자체 주소를 가지고 있음. 안에 있는 값을 변경하지 못하게 막고 있음. 
	const char* str2 = "Hello world";
	str = "아무말";
	cout << str << endl;
	cout << str2 << endl;

	// string타입은 선언 후에 rvalue타입을 대입할 수 있다.
	// 왜 이게 가능한지 구현을 통해서 알아본다.
	std::cout << "Mystring 객체 구현" << std::endl;
	Mystring s1;
	Mystring s2("Hello World!");

	Mystring s3(s2); // copy
	Mystring s4(std::move(s3)); // s3 -> str은 null, s4는 s3의 str을 갖는다. (move)

	std::cout << "Mystring 연산자를 이용한 기능 구현 (연산자 오버로딩)" << std::endl;

	Mystring s5;	  // 다형성 "=" 내부적으로 실행되는 코드는 여러가지 실행된다.
	s4 = s2;
	s5 = "My string"; // copy assignment(복사 할당), ( = 연산자 오버로딩해서 구현) 
	s1.CopyAssignment("이순신");

	//s5 = std::move(s1);					// move assignment(이동 할당)

	string str3 = "홍길동";
	str =  "My Name : " + str3 ;

	s5 = s1 + "홍길동";

	s5 = "이름은 : " + s1; // 이름은 부분은 Mystring의 임시 객체에 해당

	cout << s5 << "\n다른 객체의 정보 : " << s1;
}