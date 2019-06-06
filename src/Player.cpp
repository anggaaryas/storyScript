#include "Player.h"
#include "UI.h"
#include "Menu.h"
#include "GameSceneItem.h"
#include "File.h"
#include "Parser.h"

#include <cstring>

std::string Player::currentBgm = "";
std::string Player::tempBGM = "";

Player::Player(GameScene gameScene)
{
    this->gameScene = gameScene;
    showScene(gameScene.storyBegin);
}

void Player::showScene(GameSceneItem *current)
{
    bool autonext = false;
    int i = 1;

    if (current->scene->bgm != "")
        tempBGM = current->scene->bgm;
    if (current->scene->bgm != "" && current->scene->bgm != "STOP")
    {
        currentBgm = Menu::root_game;
        currentBgm.append("\\music\\");
        currentBgm.append(tempBGM);

#ifdef WIN32
        bgm = CreateThread(
            NULL,    /* default security attributes.   */
            0,       /* use default stack size.        */
            playBGM, /* thread function name.          */
            NULL,    /* argument to thread function.   */
            0,       /* use default creation flags.    */
            NULL);
#endif
    }
    else if (current->scene->bgm == "STOP")
        stopBGM();

    if (current->scene->sfx != "")
    {
        playEffect(current->scene->sfx);
    }

    UI::typeWriter(current->scene->desc.c_str(), false);

    UI::separator();
    for (auto p : current->scene->choiceText)
    {
        if (p == "NEXT")
        {
            autonext = true;
            std::cout << "> Press any enter to ";
        }
        else
            std::cout << i++ << ". ";
        std::cout << p << "\n";
    }
    if (!autonext)
    {
        std::cout << "\n77. Save";
        std::cout << "\n88. Load";
        std::cout << "\n99. Exit\n";
    }
    UI::separator();

    if (!autonext)
    {
        std::string ch;
        std::cout << "\nYour choice\t: ";
        std::getline(std::cin, ch);

        int ch_ = std::stoi(ch);
        if (ch_ > 0 && ch_ < i)
        {
            UI::clear();
            showScene(current->storyNext.at(ch_ - 1));
        }
        else if (ch_ == 77)
        {
            UI::clear();
            File::saveGame(current->scene->id);
            showScene(current);
        }
        else if (ch_ == 88)
        {
            UI::clear();
            stopBGM();
            SceneItem *item = File::loadGame();

            item -> id = Parser::trim(item -> id);

            GameSceneItem *story = gameScene.findStory(item->id);
            story->scene->bgm = item->bgm;

            showScene(story);
        }
        else if (ch_ == 99)
        {
            stopBGM();
            Menu();
        }
        else
        {
        }
    }
    else
    {
        getchar();
        UI::clear();
        showScene(current->storyNext.at(0));
    }
}

void Player::stopBGM()
{
#ifdef _WIN32
    PlaySound(NULL, NULL, SND_LOOP | SND_ASYNC);
#endif
}

#ifdef _WIN32
DWORD WINAPI Player::playBGM(void *threadParams)
{
    PlaySound(TEXT(currentBgm.c_str()), NULL, SND_LOOP | SND_ASYNC);
    return 0;
}

#endif

void Player::playEffect(std::string source)
{
}