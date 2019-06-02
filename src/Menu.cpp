#include "Menu.h"
#include "UI.h"
#include "Player.h"

#include <stdlib.h>
#include <string>

std::string Menu::root_game = "";
std::string Menu::current_game = "";
std::string Menu::compiledName = "";

Menu::Menu()
{
    system("CLS");
    std::string menu;

    std::cout << "Location  : " << File::getExePath() << "\n\n";
    std::cout << "1. Create a game\n";
    std::cout << "2. Play a game\n";
    std::cout << "3. Exit\n"; 
    std::cout << "\n> I choose number: ";
    std::getline(std::cin, menu);

    getFunction(std::stoi(menu));
}

void Menu::getFunction(int menu)
{
    if (menu == 1)
    {
        createGame();
    }
    else if (menu == 2)
    {
        playGame();
    }
    else if (menu == 3)
    {
        exit(0);
    }
}

void Menu::createGame()
{
    system("CLS");

    std::string menu;
    int temp;
    goto create;

    std::cout << "Lets make a game!\n";
    std::cout << "1. New Project\n";
    std::cout << "2. Compile a Project\n";
    std::cout << "\n> Now, I will choose number: ";
    std::getline(std::cin, menu);

    temp = std::stoi(menu);
    if (temp == 1)
    {
    create:
        std::string name;
        system("CLS");
        std::cout << "Create new project!\n\n";
        std::cout << "Name Project / Story : ";
        std::getline(std::cin, name);
        File::createProject(name);
    }
    else if (temp == 2)
    {
    }
}

void Menu::playGame()
{
    system("CLS");
    std::string menu;

    std::cout << "Ready to compile a project? choose the project name.\n\n";

    std::string project = File::getExePath();
    project.append("\\project");

    UI::separator();
    std::vector<FileItem> content = File::fileChooser(project.c_str());
    UI::separator();

    std::cout << "> Hmm, i choose number: ";
    std::getline(std::cin, menu);

    std::string path = "project\\";
    compiledName = File::findFile(menu, content);
    path.append(compiledName);

    root_game = path;
    current_game = compiledName;

    path.append("\\main.StoryScript");

    parser.createGame(path.c_str());
    UI::openingGame();
    UI::letsPlay();
    
    Player player(gameScene);
}

Menu::~Menu()
{
    std::cout << "Something Happened!";
}
