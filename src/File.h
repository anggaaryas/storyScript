#ifndef __FILE_H__
#define __FILE_H__

#include "FileItem.h"
#include "SceneItem.h"

#include <iostream>
#include <vector>

#define DEFAULT_STRING "ANGGA"

class File
{
private:
    static std::string rootDirectory;
public:
    static std::string getExePath();
    static std::string getExeFileName();
    static std::vector<FileItem> fileChooser(const char *path);
    static void createProject(std::string name);
    static std::string findFile(std::string number, std::vector<FileItem> content);
    static int saveGame(std::string id);
    static SceneItem *loadGame();
};

#endif