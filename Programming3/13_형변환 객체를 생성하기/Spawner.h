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
    static std::vector<unique_ptr<Run>> CreateFromValue(const rapidjson::Value& dataArray) {
        std::vector<std::unique_ptr<Run>>tempObjects;

        if (!dataArray.IsArray()) return tempObjects;

        for (auto& item : dataArray.GetArray()) {
            if (!item.HasMember("type")) continue;

                // int 값을 Enum 타입으로 형변환 (C++ cast 사용) (int->enum)
                moveType mType = static_cast<moveType>(item["moveType"].GetInt());

                // 공통 데이터 추출
                int x = item["x"].GetInt();
                int y = item["y"].GetInt();
                std::string shape = item["shape"].GetString();
                int speed = item["speed"].GetInt();

                if (mType == moveType::Normal) {
                    tempObjects.push_back(std::make_unique<Run>(x, y, shape, speed));
                }
                else if (mType == moveType::Jump) {
                    tempObjects.push_back(std::make_unique<Run>(x, y, shape, speed, item["jumppower"].GetInt()));
                }
                else if(mType == moveType::Dash) {
                    tempObjects.push_back(std::make_unique<Run>(x, y, shape, speed, item["dashpower"].GetInt()));
                }
    };

    // RunFactory클래스를 이용해서 run객체를 vector(가변변환)에 저장해서 사용하는 Spawner 클래스를 만들어라. 

    // 정의한 게임 객체를 생성하는 객체
    class Spawner
    {
    private:
        // Run 객체들을 저장할 벡터. unique_ptr로 메모리 관리를 자동화합니다.
        std::vector<std::unique_ptr<Run>> spawnedObjects; // Run* 저장하는 배열이다.
    public:
        void SetObjects(std::vector<std::unique_ptr<Run>> newObjects) {
            spawnedObjects = std::move(newObjects);
        }

        void Display()
        {
            for (auto& r : spawnedObjects)
            {
                r->move();
            } 
        }
    };