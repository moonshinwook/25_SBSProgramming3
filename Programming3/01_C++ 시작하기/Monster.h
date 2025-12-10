#pragma once

// typedef을 사용하지 않아도 사용 가능
// 접근 제어 지시자 
// public	: 공공의, 누구나 사용할 수 있는 
// private	: 사적인, 숨겨진, 함부로 사용할 수 없는

// struct vs class 둘의 차이점이 무엇인가요? 문법적인 언어마다 다르다 Sementic 다른 방식으로 이해한다.
// struct를 이용해서 게임 데이터를 메인 함수에 출력하기

#include <string>

using namespace std; // std::을 생략할 수 있도록 명시

class Monster // 클래스로 선언한 객체의 접근 제어 지시자를 명시하지 않으면 private로 선언된다.
{
public: //영역 레이블을 하지 않으면 private
	string name;	// 문자열을 표현하는 타입은 string
	int HP;			// 이름
	int UID;		// UID	0000_0001	0 ~ 1000 몬스터 데이터 0001_0000
};

struct MonsterStruct // 구조체로 선언한 객체의 접근 제어 지시자를 명시하지 않으면 public로 선언된다.
{
	int a;
	int b;
};



