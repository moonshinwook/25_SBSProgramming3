#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;


enum class moveType
{
    Normal = 0,
    Dash = 1,
    Jump = 2,

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

class RunFactory
{
public:
    static vector<unique_ptr<Run>> CreatFromValue(const Value& dataArray) {
        std::vector<unique_ptr<Run>> tempObjects;

        if (!dataArray.IsArray()) return tempObjects;

        for (auto& item : dataArray.GetArray()) {
            if (!item.HasMember("type")) continue;

            moveType mType = static_cast<moveType>(item["type"].GetInt());
            int x = item["x"].GetInt();
            int y = item["y"].GetInt();
            string shape = item["shape"].GetString();
            int speed = item["speed"].GetInt();

            if (mType == moveType::Normal) {
                tempObjects.push_back(make_unique<Run>(x, y, shape, speed));
            }
            else if (mType == moveType::Jump) {
                tempObjects.push_back(make_unique<Jump>(x, y, shape, speed, item["jumppower"].GetInt()));
            }
            else if (mType == moveType::Dash) {
                tempObjects.push_back(make_unique<Dash>(x, y, shape, speed, item["dashpower"].GetInt()));
            }
        }
        return tempObjects;
    }
};


class Spawner
{
private:
    vector<unique_ptr<Run>> spawnedObjects;
public:
    void SetObjects(vector<std::unique_ptr<Run>> newObjects){

        spawnedObjects = move(newObjects);
    }

    void Display() const
    {
        for (auto& r : spawnedObjects)
        {
            r->move();
        }
    }
};