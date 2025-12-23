#pragma once
#include <Windows.h>
#include <string>

class ConsoleRender
{
    public:
        ConsoleRender(int width = 80, int height = 25);
        ~ConsoleRender();

        void ScreenFlipping();
        void ScreenClear();
        void ScreenPrint(int x, int y, const std::string& str);

    private:
        HANDLE m_hScreen[2];
        int m_nScreenIndex;
        int m_nWidth;
        int m_nHeight;

        void ScreenInit();

};

