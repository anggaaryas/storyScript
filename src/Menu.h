#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>

#include "File.h"
#include "Parser.h"

class Menu
{
  private:
    void getFunction(int menu);
    void createGame();
    void playGame();

    GameScene gameScene;
    Parser parser = Parser(gameScene);

    

  public:
    Menu(/* args */);
    ~Menu();

    static std::string root_game;
    static std::string current_game;
    static std::string compiledName;
};

#endif // __MENU_H__