#include "ConsoleRender.h"

ConsoleRender::ConsoleRender(int width, int height)
    : m_nScreenIndex(0), m_nWidth(width), m_nHeight(height) {
    ScreenInit();
}

ConsoleRender::~ConsoleRender() {
    CloseHandle(m_hScreen[0]);
    CloseHandle(m_hScreen[1]);
}

void ConsoleRender::ScreenInit() {
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;

    for (int i = 0; i < 2; ++i) {
        m_hScreen[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        SetConsoleCursorInfo(m_hScreen[i], &cci);
    }
}

void ConsoleRender::ScreenFlipping() {
    // 현재 인덱스의 버퍼를 활성화
    SetConsoleActiveScreenBuffer(m_hScreen[m_nScreenIndex]);
    // 다음 프레임을 위해 인덱스 교체 (0 -> 1, 1 -> 0)
    m_nScreenIndex = !m_nScreenIndex;
}

void ConsoleRender::ScreenClear() {
    COORD coor = { 0, 0 };
    DWORD dw;
    // 설정된 너비와 높이만큼 공백으로 채움
    FillConsoleOutputCharacter(m_hScreen[m_nScreenIndex], ' ', m_nWidth * m_nHeight, coor, &dw);
}

void ConsoleRender::ScreenPrint(int x, int y, const std::string& str) {
    DWORD dw;
    COORD cursorPosition = { static_cast<SHORT>(x), static_cast<SHORT>(y) };

    // 해당 버퍼의 커서 위치 설정 후 출력
    SetConsoleCursorPosition(m_hScreen[m_nScreenIndex], cursorPosition);
    WriteFile(m_hScreen[m_nScreenIndex], str.c_str(), static_cast<DWORD>(str.length()), &dw, NULL);
}
