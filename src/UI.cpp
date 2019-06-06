#include "UI.h"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <unistd.h>
#endif

#include <stdlib.h>
#include <time.h>
#include <cstring>

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
            sleep(150);
        else
            sleep(33);
    }
    std::cout << "\n";
    sleep(450);
}

void UI::glitch()
{
    clear();
    std::cout << "\n\n";
    std::cout << "\t" << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << ' ' << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << "\n";
    std::cout << "\t" << (char)cc() << (char)cc() << (char)cc() << (char)cc() << ' ' << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << (char)cc() << "\n";
    std::cout << "\t" << (char)cc() << ' ' << (char)cc() << '.' << (char)cc() << "\n\n";
}

void UI::openingGame()
{
    clear();
    std::cout << "Opening...";
    sleep(300);
    clear();

#ifdef WIN32
    PlaySound(TEXT("opening.wav"), NULL, SND_ASYNC);
#endif

    char t[] = "Story Script";
    char t2[] = "Game Engine";
    char t3[] = "v 0.1";

    std::cout << "    Made by:\n";
    std::cout << "\n";
    typeWriter(t, true);
    typeWriter(t2, true);
    typeWriter(t3, true);

    sleep(400);
    for (int i = 0; i < 25; i++)
    {
        glitch();
        sleep(30);
    }
    clear();
    sleep(1000);
}

void UI::letsPlay()
{
    clear();
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

void UI::sleep(int ms)
{
#ifdef _WIN32
    Sleep(ms);
#endif

#ifdef __linux__
    fflush(stdout);
    usleep(ms * 1000);
#endif
}

void UI::clear()
{
#ifdef _WIN32
    system("CLS");
#endif

#ifdef __linux__
    system("clear");
#endif
}