#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

// 캡슐화 - 캡슐(약 성분) - 먹는다.

// 생성자 : 객체의 데이터(속성)를 초기화 하기 위한 함수 - 문법

// Person(5, "홍길동", "부산"); int age = 5,std::string name = "홍길동" , std::string home = "부산" 

// deepcopy 기능 구현하기 : 객체 간의 대입을 할 때 (복제) 주소는 복제가 안된다. 주소는 동적 할당을 해서 넘겨줘야 된다. 

class Person
{
private:
	// 속성 attribute
	int money;
	int age; 
	std::string name;
	std::string home;
	char* symbol;

public:
	// 생성자
	Person() = default; // 복사생성자, 이동 생성자. 자기 자신 초기화 
	Person(int _age, std::string _name, std::string _home) : age(_age), name(_name), home(_home), money(100000) {}// class 안의 매개변수 != 생성자 안의 매개변수
	Person(int _money, int _age, std::string _name, std::string _home) : money(_money), age(_age), name(_name), home(_home){}
	Person(int _money, int _age, std::string _name, std::string _home, const char* _symbol) : money(_money), age(_age), name(_name), home(_home)
	{
		symbol = new char[100];
		strcpy(symbol, _symbol); // symbol에 _symbol의 값을 복사하여 넘겨주겠다. 

	}

	// 소멸자
	~Person()
	{
		std::cout << "소멸자 호출" << std::endl;
		delete[] symbol;
	}


	// 기능 method
	void ToString() // 문자열로 바꿔라, FromPerson 생략 -> class Person 안에 만들었기 때문
	{
		std::cout << "이름 : " << name << std::endl;
		std::cout << "나이 : " << age << std::endl;
		std::cout << "거주지 : " << home << std::endl;
		std::cout << "소지금 : " << money << std::endl;
	}
};

