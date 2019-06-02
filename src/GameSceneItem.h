#ifndef __GAME_SCENE_ITEM_H__
#define __GAME_SCENE_ITEM_H__

#include "SceneItem.h"

class GameSceneItem
{
  public:
    SceneItem *scene;
    GameSceneItem *next;
    std::vector<GameSceneItem*> storyNext;
};

#endif