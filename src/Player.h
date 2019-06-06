#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameScene.h"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

class Player
{
  private:
    GameScene gameScene;
    #ifdef WIN32
    HANDLE bgm = NULL;
    static DWORD WINAPI playBGM(void *threadParams);
    #endif
    std::string rootGame;
    static std::string currentBgm;
    void stopBGM();
    void playEffect(std::string source);
  public:
    Player(GameScene gameScene);
    void showScene(GameSceneItem *current);
    static std::string tempBGM;
};

#endif