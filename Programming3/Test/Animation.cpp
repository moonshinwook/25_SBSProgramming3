#include "Animation.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

// 콘솔 출력을 위한 핸들을 가져옵니다.
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetConsoleColor(int colorCode) {
    SetConsoleTextAttribute(hConsole, colorCode);
}

void PrintSlowly(const std::string& text, int delayMs) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

void ClearScreen() {
    system("cls");
}

void DisplayFadingTitle(const std::string& title, int durationMs) {
    ClearScreen();

    int steps = 15;
    int delayPerStep = durationMs / (steps * 2 + 1);

    // 페이드 인
    for (int i = 0; i <= steps; ++i) {
        int color = static_cast<int>((static_cast<double>(i) / steps) * 15);
        SetConsoleColor(color);
        std::cout << title << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayPerStep));
        std::cout << "\r" << std::string(title.length(), ' ') << "\r";
    }

    // 유지
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << title << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delayPerStep * 2));
    std::cout << "\r" << std::string(title.length(), ' ') << "\r";

    // 페이드 아웃
    for (int i = steps; i >= 0; --i) {
        int color = static_cast<int>((static_cast<double>(i) / steps) * 15);
        SetConsoleColor(color);
        std::cout << title << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayPerStep));
        std::cout << "\r" << std::string(title.length(), ' ') << "\r";
    }

    // 초기화
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << std::endl;
}