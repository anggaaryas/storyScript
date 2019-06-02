#ifndef __SCENE_ITEM_H__
#define __SCENE_ITEM_H__

#include <iostream>
#include <vector>

class SceneItem
{
  private:
  
  public:
    Scene(/* args */);

    std::string desc = "", id = "", bgm = "", sfx = "";
    std::vector<std::string> choiceText, choiceDestination;
};

#endif // __SCENE_ITEM_H__