#include <iostream> // cout(출력), cin(입력)
#include <cstdio>   // cpp 방식 호출 c언어에서 사용했던 라이브러리 사용하고 싶을 때는 호환용
// #include <stdio.h>  // c언어 방식 호출
#include <strstream>

using namespace std;

// 포인터란? 주소를 저장하는 변수
// (1) cpp 방식의 변수 선언.
// (2) 포인터의 동적 할당 변경 사항
// (3) 참조자

// int& a = b1; int& b = b2;
void MySwap(int& a, int& b)
{
	int  temp = b; // 새로운 주소에 a값을 저장
	b = a;
	a = temp; // temp는 함수 안에 존재하는 지역변수 main에서는 반영 x
}

void MySwap(int* a, int* b)
{
	int  temp = *b; // 새로운 주소에 a값을 저장
	*b = *a;
	*a = temp; // temp는 함수 안에 존재하는 지역변수 main에서는 반영 x
}

int& RefExample(int& mainRef)
{
	int temp = mainRef++;
	return temp;
}

struct Pos
{
	int x;
	int y;

};

void ChangePos(Pos& pos, int addXValue, int addYValue) // 임시로 가져올 값 - 그냥 임시 변수
{

	pos.x += addXValue;
	pos.y += addYValue;
}

// 포인터를 대체할 수 있는가? 
// 참조자로는 표현할 수 있는 내용이 있다. - 참조자가 null이 될 수 없다.

// fp* 폴더의 파일 이름이 없으면 실행하지마라.

// 함수 안에서 값을 변경하는 코드는 참조자를 쓰겠다. 코딩 스타일을 지켜야 한다. 참조자와 *을 혼용하면 다른 사람의 것을 인용한 것으로 오해받을 수 있음.

// 포인터를 사용하는 이유?
// 함수 안에서 데이터를 변경할 수 있게 한다.
// 효율적으로 데이터를 전달하고 사용할 수 있다.

void RefExample2(int*& makePtr) // 참조자를 이용한 함수는 반드시 없는 경우가 없어야 한다.
{
	if (makePtr == nullptr)
	{
		throw "참조자는 null이 될 수 없습니다.";
	}

	int* tempIntPtr{};
	tempIntPtr = new int;
}

void ShowPos(const Pos& pos) // const로 데이터 사용 목적만으로, const가 없으면 변경된 데이터를 참조하겠다.
{
	pos.x;
}

/*
*	아래 내용을 정리해보세요. 
* (1) 포인터를 사용하는 이유를 정리하세요.
* 포인터로 데이터를 주소의 크기 8바이트만큼만 불러와서 효율적으로 데이터 관리
* 함수 안의 데이터를 변경시키기 위해서
* *와 & 사용에서 빈번한 오류를 방지할 수 있음.
* 
* (2) 참조자를 사용할 때의 주의 사항. 
* 참조자 선언 때 주소 초기화를 해야 한다.
* 숫자를 참조하는 경우 const선언 필요.
* 
* 
* 
* (3) 포인터와 참조자를 같이 사용해야하는 이유.
* 참조자를 사용하는 경우 const없이 선언된 참조자는 변경된 값을 참조하는지 유무를 확인하기 위해 코드를 전부 읽어야하는 리스크가 필요함.
*
*/

// 참조자를 이용해서 값을 변경하는 예제를 구현해보세요. 
struct some {
	int e;
	int f;
};

// 참조자를 이용해서 값을 변경하지 않는 예제를 구현해보세요. 



int main()
{
	cout << "2강 포인터와 참조자" << endl;


	// ends << 무엇인가? 보충 설명
	ostrstream oss;
	oss << "Sample text: " << 42 << ends; // flush
	cout << "!!" << oss.str() << "!!" << endl;
	printf("%s \n", oss.str()); // 문자열은 끝이 널문자여야 한다.
	//
	
	cout << "\n2-1 cpp 방식의 변수 선언." << endl;

	int a = 10.5; // c언어 방식의 변수 초기화
	int a2(20.5); // cpp언어에서의 변수 초기화 방식. 
	int a3{ 30 }; // cpp언어에서의 변수 초기화 방식2. 제약 사항 존재(타입이 맞지 않으면 오류 발생).

	cout << a << endl;
	cout << a2 << endl;
	cout << a3 << endl;

	int* a_ptr = &a;
	int* a2_ptr{ nullptr };
	int* a3_ptr{};
	cout << a_ptr << endl;
	cout << a2_ptr << endl;
	cout << a3_ptr << endl;

	cout << "\n2-2 nullptr 주소에 주소 생성하기 런타임 시점에" << endl;


	a2_ptr = new int; // 메모리 주소 할당
	cout << a2_ptr << endl;
	*a2_ptr = 10; // 주소가 있기 때문에 10을 저장하여 출력가능 
	cout << *a2_ptr << endl;

	delete a2_ptr; // malloc에서 free의 역할

	cout << a2_ptr << endl;

	// 스마트 포인터 -> 포인터 할당 후 메모리 누수가 문제가 된다(프로그래머 실력에 따라서)

	cout << "\n2-3 swap함수 예제" << endl;

	/*int b1{3};
	int b2{5};
	cin >> b1;
	cin >> b2;
	cout << "b1의 값 : " << b1 << endl;
	cout << "b2의 값 : " << b2 << endl;
	MySwap(b1, b2);
	cout << "b1의 값 : " << b1 << endl;
	cout << "b2의 값 : " << b2 << endl;*/

	// 참조자가 어떤 원리여서 이러한 기능이 가능해지는가? int&로 *의 역할을 대신할 수 있는건가?

	cout << "\n2-4 참조자 " << endl;

	// 선언 방법
	int& aRef = a; // 선언과 동시에 변수 초기화 필요함. aRef별명 a이름의 변수에  홍길동 alias(별명)

	int* c_ptr{}; // new 키워드를 사용해서 주소를 할당.
	c_ptr = new int;
	int*& c_ptrRef = c_ptr;

	cout << "c의 값 : " << c_ptr << endl;
	delete c_ptrRef;
	cout << "c의 값 : " << c_ptrRef << endl; // 스택영역과 힙영역 

	// 둘의 주소를 출력해보세요.

	int* c2_ptr{};
	c2_ptr = new int;
	int* c2_ptr2 = c2_ptr; // 같은 주소를 가리키고 있는 상황. 복제 -> 깊게 이해
	cout << c2_ptr << endl;
	delete c2_ptr; // 지우더라도 같은 주소에 접근 가능.
	cout << c2_ptr2 << endl;

	// 주소를 생성할 때 복제를 할 수 있고, 참조를 할 수 있다.
	// cpp 매우 빠른 코드.

	// 참조자 사용 시 주의사항
	// 1. 참조자는 반드시 선언과 동시에 초기화를 해줘야 한다.

	//int& myRef;	   // 초기화 에러 발생
	//int& myRef = 10; // const없이 숫자 사용 x. const int& myRef = 10;은 사용 가능.   

	// 2. 함수에서 반환하는 값이 소멸되지 않도록 해야한다. 

	int mainNum = 10;
	int& refValue = RefExample(mainNum); // refValue RefExample함수 안에 있는 temp의 별명

	cout << refValue << endl; // 컴파일러 Undefined 정의되지 않은 코드는 알아서 수정하도록.
							  // dangling(매달려 있는) 포인터 : 임시 객체

	Pos myPos{};
	ChangePos(myPos, 2, 5);

	cout << " X : " << myPos.x << " Y : " << myPos.y << endl;
}