#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <windows.h> 

void SetConsoleColor(int colorCode);
void PrintSlowly(const std::string& text, int delayMs);
void DisplayFadingTitle(const std::string& title, int durationMs = 3000);
void ClearScreen();

#endif // ANIMATION_H

