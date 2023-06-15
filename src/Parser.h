#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>

#include "GameScene.h"
#include "SceneItem.h"

#define SCENE_OPEN "{"
#define SCENE_CLOSE "}"
#define DESC "\""
#define PARAM "="
#define END_PARAM ";"
#define DESTINATION_CHOICE "->"
#define CHOICE "c"
#define BGM "b"
#define EFFECT "e"
#define END_CHOICE_ARRAY ","

#define START_POINT "*"

class Parser
{
private:
    GameScene *gameScene;
    void saveNode(SceneItem *scene);
    void intialize();
    void constructStory();
    void constructStoryCore(GameSceneItem *item);

public:
    static std::string trim(std::string text);
    Parser(GameScene &gameScene);
    void createGame(const char *project);
};

#endif