#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameScene.h"

#include <iostream>
#include <windows.h>

class Player
{
  private:
    GameScene gameScene;
    HANDLE bgm = NULL;
    std::string rootGame;
    static std::string currentBgm;
    static DWORD WINAPI playBGM(void *threadParams);
    void stopBGM();
    void playEffect(std::string source);
  public:
    Player(GameScene gameScene);
    void showScene(GameSceneItem *current);
    static std::string tempBGM;
};

#endif