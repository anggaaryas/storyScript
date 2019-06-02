#include "UI.h"

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

UI::UI()
{
    srand(time(0));
}

void UI::separator()
{
    std::cout << "----------------------------------\n";
}

void UI::typeWriter(const char x[], bool isBootAnimation)
{
    if (isBootAnimation)
        std::cout << "\t";
    for (int i = 0; i < strlen(x); i++)
    {
        std::cout << x[i];
        if (isBootAnimation)
            Sleep(150);
        else
            Sleep(33);
    }
    std::cout << "\n";
    Sleep(450);
}

void UI::glitch()
{
    system("CLS");
    std::cout << "\n\n";
    std::cout << "\t" << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << ' ' << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << "\n";
    std::cout << "\t" << (char)cc() << (char)cc() << (char)cc() << (char)cc() << ' ' << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << "\n";
    std::cout << "\t" << (char)cc() << ' ' << (char)cc() << '.' << (char)cc() << "\n\n";
}

void UI::openingGame(){
    system("CLS");
    std::cout << "Opening...";
    Sleep(300);
    system("CLS");
    PlaySound(TEXT("opening.wav"), NULL, SND_ASYNC);
    char t[] = "Story Script";
    char t2[] = "Game Engine";
    char t3[] = "v 0.1";

    std::cout << "    Made by:\n";
    std::cout << "\n";
    typeWriter(t, true);
    typeWriter(t2, true);
    typeWriter(t3,true);

    Sleep(400);
    for (int i = 0; i < 25; i++)
    {
        glitch();
        Sleep(30);
    }
    system("CLS");
    Sleep(1000);
}

void UI::letsPlay()
{
    system("CLS");
    std::cout << "##################################\n";
    std::cout << "##          Lets Play...        ##\n";
    std::cout << "##################################\n\n";
}

int UI::cc()
{
    return rand() % rand() % 94 + 32;
}

void UI::dataEmpty()
{
    std::cout << "Data is empty...";
}