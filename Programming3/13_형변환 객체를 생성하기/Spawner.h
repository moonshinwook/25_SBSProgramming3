#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>  // 스마트 포인터, 포인터를 객체화했다.

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

// 1. Factory 클래스 ( 열거형을 읽어서 자신의 타입에 맞는 클래스를 생성해주는 클래스) 
// 2. Spawner 클래스는 Factory클래스를 사용해서 클래스를 생성한다. 
// 특정 클래스를 사용하는 클래스를 만들어라. 
// 포인터를 사용하는 클래스. 스마트 포인터
// gameObject

enum class moveType
{
    Normal = 0, Jump = 1, Dash = 2,
};

class Run
{
public:
    int x;
    int y;
    string shape;
    int speed;
    Run(int x, int y, string shape, int speed) : x(x), y(y), shape(shape), speed(speed) {}
    Run() = default;
    virtual ~Run() = default;
    virtual void move() { cout << "run합니다."; }
};

class Dash : public Run
{
public:
    int dashpower;
    Dash(int x, int y, string shape, int speed, int dashpower) : Run(x, y, shape, speed), dashpower(dashpower) {}
    void move() override { cout << "Dash합니다."; }
};

class Jump : public Run
{
public:
    int jumppower;
    Jump(int x, int y, string shape, int speed, int jumppower) : Run(x, y, shape, speed), jumppower(jumppower) {}
    void move() override { cout << "jump합니다."; }
};

class RunFactory {
public:
    // JSON Document를 입력받아 적절한 Run 파생 클래스 포인터를 반환하는 팩토리 메서드
    static std::unique_ptr<Run> createRunObjectFromJson(const Document& doc) {
        // 필수 필드 존재 및 유효성 검사
        if (!doc.HasMember("moveType") || !doc["moveType"].IsInt() ||
            !doc.HasMember("x") || !doc["x"].IsInt() ||
            !doc.HasMember("y") || !doc["y"].IsInt() ||
            !doc.HasMember("shape") || !doc["shape"].IsString() ||
            !doc.HasMember("speed") || !doc["speed"].IsInt()) {
            std::cerr << "Error: 필수 JSON 필드가 누락되었거나 유효하지 않습니다." << std::endl;
            return nullptr;
        }

        // int 값을 Enum 타입으로 형변환 (C++ cast 사용)
        moveType type = static_cast<moveType>(doc["moveType"].GetInt());

        // 공통 데이터 추출
        int x = doc["x"].GetInt();
        int y = doc["y"].GetInt();
        std::string shape = doc["shape"].GetString();
        int speed = doc["speed"].GetInt();

        // moveType 값에 따라 다른 생성자 호출 (조건문 사용)
        switch (type) {
        case moveType::Normal:
            std::cout << "Factory: Normal 타입 Run 객체 생성." << std::endl;
            return std::make_unique<Run>(x, y, shape, speed);

        case moveType::Jump:
            if (doc.HasMember("jumpPower") && doc["jumpPower"].IsInt()) {
                std::cout << "Factory: Jump 타입 객체 생성." << std::endl;
                int jumpPower = doc["jumpPower"].GetInt();
                return std::make_unique<Jump>(x, y, shape, speed, jumpPower);
            }
            else {
                std::cerr << "Error: Jump 타입에 필요한 jumpPower 필드가 없습니다." << std::endl;
                return nullptr;
            }

        case moveType::Dash:
            if (doc.HasMember("dashPower") && doc["dashPower"].IsInt()) {
                std::cout << "Factory: Dash 타입 객체 생성." << std::endl;
                int dashPower = doc["dashPower"].GetInt();
                return std::make_unique<Dash>(x, y, shape, speed, dashPower);
            }
            else {
                std::cerr << "Error: Dash 타입에 필요한 dashPower 필드가 없습니다." << std::endl;
                return nullptr;
            }

        default:
            std::cerr << "Error: 알 수 없는 moveType 값입니다." << std::endl;
            return nullptr;
        }
    }
};

// RunFactory클래스를 이용해서 run객체를 vector(가변변환)에 저장해서 사용하는 Spawner 클래스를 만들어라. 

// 정의한 게임 객체를 생성하는 객체
class Spawner {
private:
    // Run 객체들을 저장할 벡터. unique_ptr로 메모리 관리를 자동화합니다.
    std::vector<std::unique_ptr<Run>> entities; // Run* 저장하는 배열이다.


}
