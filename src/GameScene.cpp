#include "GameScene.h"
#include "UI.h"

GameScene::GameScene()
{
    
}

GameSceneItem *GameScene::findStory(std::string id)
{
    findID = id;

    if (isEmpty())
    {
        UI::dataEmpty();
        return NULL;
    }
    else
    {
        return findStoryCore(begin);
    }
}

GameSceneItem *GameScene::findStoryCore(GameSceneItem *node)
{
    if (node != NULL)
    {
        if (node->scene->id == findID)
        {
            return node;
        }

        return findStoryCore(node->next);
    }
    else
    {
        return NULL;
    }
}

bool GameScene::isEmpty()
{
    return begin == NULL;
}



