#include "Parser.h"
#include "UI.h"

#ifdef WIN32
#include <windows.h>
#endif

#include <cstring>
#include <fstream>
#include <string>
#include <ctype.h>

Parser::Parser(GameScene &gameScene)
{
    this->gameScene = &gameScene;
}

void Parser::intialize()
{
    gameScene->begin = NULL;
    gameScene->end = gameScene->begin;
}

std::string Parser::trim(std::string text)
{
    /*
        ' '     =   space               0x20
        '\t'    =   tab                 0x09
        '\n'    =   newline             0x0a
        '\v'    =   vertical tab        0x0b
        '\f'    =   feed                0x0c
        '\r'    =   carriage return     0x0d
    */
   
    auto xTmp = text.find_first_not_of(" \t\v\f\r");
    auto yTmp = text.find_last_not_of(" \t\v\f\r");

    return text.substr(xTmp, (yTmp - xTmp) + 1);
}

void Parser::createGame(const char *project)
{
    intialize();

    std::cout << trim("    b") << "\n";

    std::string input = "";
    std::ifstream myFile;
    myFile.open(project);
    if (myFile.is_open())
    {
        std::string tmp;
        while (std::getline(myFile, tmp))
        {
            input.append(tmp);
        }
    }

    auto stScene = 0U;
    auto edScene = input.find(SCENE_OPEN);
    while (edScene != std::string::npos)
    {
        // TODO: Get Id Scene
        SceneItem *node = new SceneItem;
        node->id = trim(input.substr(stScene, edScene - stScene));

        // TODO: Get Story from that scene
        auto stDesc = edScene + std::strlen(SCENE_OPEN);
        auto edDesc = input.find(DESC, stDesc);
        stDesc = edDesc + std::strlen(DESC);
        edDesc = input.find(DESC, stDesc);
        node->desc = input.substr(stDesc, edDesc - stDesc);

        auto stParam = edDesc + std::strlen(DESC);
        auto edParam = input.find(PARAM, stParam);
        while (edParam < input.find(SCENE_CLOSE, stParam))
        {
            std::string parameter = trim(input.substr(stParam, edParam - stParam));

            if (parameter == CHOICE)
            {
                auto stChoice = edParam + std::strlen(PARAM);
                auto edChoice = input.find(DESC, stChoice);
                stChoice = edChoice + std::strlen(DESC);
                edChoice = input.find(DESC, stChoice);
                node->choiceText.push_back(input.substr(stChoice, edChoice - stChoice));

                auto stDestination = edChoice + std::strlen(DESC);
                auto edDestination = input.find(DESTINATION_CHOICE, stDestination);
                stDestination = edDestination + std::strlen(DESTINATION_CHOICE);
                edDestination = input.find(END_PARAM, stDestination);
                node->choiceDestination.push_back(trim(input.substr(stDestination, edDestination - stDestination)));
            }
            else if (parameter == BGM)
            {
                auto stBgm = edParam + std::strlen(PARAM);
                auto edBgm = input.find(DESC, stBgm);
                stBgm = edBgm + std::strlen(DESC);
                edBgm = input.find(DESC, stBgm);
                node->bgm = input.substr(stBgm, edBgm - stBgm);
            }
            else if (parameter == EFFECT)
            {
                auto stBgm = edParam + std::strlen(PARAM);
                auto edBgm = input.find(DESC, stBgm);
                stBgm = edBgm + std::strlen(DESC);
                edBgm = input.find(DESC, stBgm);
                node->sfx = input.substr(stBgm, edBgm - stBgm);
            }

            stParam = input.find(END_PARAM, stParam) + std::strlen(END_PARAM);
            edParam = input.find(PARAM, stParam);
        }

        // TODO: Save current Scene to Linked List
        saveNode(node);

        // TODO: Next scene
        stScene = edDesc + std::strlen(DESC);
        edScene = input.find(SCENE_CLOSE, stScene);
        stScene = edScene + std::strlen(SCENE_CLOSE);
        edScene = input.find(SCENE_OPEN, stScene);
    }

    myFile.close();

    constructStory();
}

void Parser::saveNode(SceneItem *scene)
{
    GameSceneItem *nb = new GameSceneItem;
    nb->scene = scene;
    nb->next = NULL;

    if (gameScene->isEmpty())
    {
        gameScene->begin = nb;
        gameScene->end = gameScene->begin;
    }
    else
    {
        gameScene->end->next = nb;
        gameScene->end = nb;
    }
}

void Parser::constructStory()
{
    UI::clear();
    std::cout << "MASUK Story play...\n";
    gameScene->storyBegin = gameScene->findStory(START_POINT);
    constructStoryCore(gameScene->storyBegin);
}

void Parser::constructStoryCore(GameSceneItem *item)
{
    std::cout << "MASUK Story play Flow... " << item->scene->id << "\n";
    for (auto next : item->scene->choiceDestination)
    {
        std::cout << "\tSearch: " << next << " From: " << item->scene->id << "\n";
        GameSceneItem *temp = gameScene->findStory(next);

        item->storyNext.push_back(temp);
        if (temp->storyNext.empty())
            constructStoryCore(temp);
    }
}