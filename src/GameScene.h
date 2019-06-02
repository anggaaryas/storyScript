#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <iostream>

#include "SceneItem.h"
#include "GameSceneItem.h"

class GameScene
{
  private:
    std::string findID;
    GameSceneItem *findStoryCore(GameSceneItem *node);

  public:
    GameScene(/* args */);
    GameSceneItem *findStory(std::string id);
    bool isEmpty();

    GameSceneItem *begin, *end, *storyBegin;
};

#endif // __GAME_SCENE_H__