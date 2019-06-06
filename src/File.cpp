#include "File.h"
#include "UI.h"
#include "Menu.h"
#include "Player.h"

#include "include/dirent.h"

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <unistd.h>
#endif

#include <fstream>
#include <sstream>

std::string File::rootDirectory = "";

std::string File::getExePath()
{
    std::string f = getExeFileName();
    rootDirectory = f.substr(0, f.find_last_of("\\/"));
    return rootDirectory;
}

std::string File::getExeFileName()
{
    std::string path = "NOPE";

#ifdef WIN32
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    path =  std::string(buffer);
#endif

#ifdef __linux__
    char buff[PATH_MAX];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff) - 1);
    if (len != -1)
    {
        buff[len] = '\0';
        path =  std::string(buff);
    }
#endif

    return path;
}

std::vector<FileItem> File::fileChooser(const char *path)
{
    std::cout << path << "\n";
    std::vector<FileItem> content;
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        UI::dataEmpty();
    }
    else
    {
        int x = 1;
        int index = 1;
        while ((entry = readdir(dir)) != NULL)
        {
            if (x++ < 0) //windows < 3 
            {
            }
            else
            {
                FileItem temp;
                temp.i = index;
                temp.name = entry->d_name;
                content.push_back(temp);

                std::cout << index++ << ". " << entry->d_name << "\n";
            }
        }

        closedir(dir);
    }
    return content;
}

void File::createProject(std::string name)
{
    std::string path = "project/";
    path.append(name);

    std::string main = path;

    {
        std::string x = "mkdir \"";
        x.append(rootDirectory);
        x.append("/");

        std::string z = x;
        z.append("savedGame/");
        z.append(name);
        z.append("\"");
        system(z.c_str());

        x.append(path);

        std::string y = x;
        y.append("\"");
        system(y.c_str());

        x.append("/music\"");
        system(x.c_str());
    }

    main.append("/main.StoryScript");

    std::ofstream o;
    o.open(main);
    o.close();

    UI::clear();
    std::cout << "Project created!";

    UI::sleep(1000);

    Menu();
}

std::string File::findFile(std::string number, std::vector<FileItem> content)
{
    int i = std::stoi(number);

    for (auto x : content)
    {
        if (x.i == i)
        {
            return x.name;
        }
    }

    return DEFAULT_STRING;
}

int File::saveGame(std::string id)
{
    std::string path = "savedGame/" + Menu::compiledName + "/";
    int i = 1;

    fileChooser(path.c_str());

    std::string title;
    std::cout << "\nName a save file: ";
    std::getline(std::cin, title);

    std::stringstream ss;
    ss << path << title;

    std::ifstream myFile(ss.str().c_str());
    while (myFile.good())
    {
        UI::clear();

        std::string q;
        std::cout << "already exist. Overwrite (y/n)? ";
        std::getline(std::cin, q);
        if (q == "y" || q == "Y")
            break;
        else if (q == "n" || q == "N")
        {
        }
        else
            continue;

        std::cout << "Name a save file: ";
        std::getline(std::cin, title);

        std::stringstream ss;
        ss << path << title;

        myFile = std::ifstream(ss.str().c_str());
    }

    myFile.close();

    try
    {
        std::stringstream ss;
        ss << path << title;

        std::ofstream myFile;
        myFile.open(ss.str().c_str());

        std::cout << "\nSaved!"
                  << "\n\n";
        myFile << id << "\n"
               << Player::tempBGM;
        myFile.close();

        UI::sleep(1250);
        UI::clear();

        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n\n";
        return 0;
    }
}

SceneItem *File::loadGame()
{
    std::string path = "savedGame/" + Menu::compiledName + "/";
    std::string menu, result;

    std::cout << "choose load file: \n";
    std::vector<FileItem> list = fileChooser(path.c_str());
    std::cout << "\n> Hmm, i choose number: ";
    std::getline(std::cin, menu);
    result = findFile(menu, list);

    std::stringstream ss;
    ss << path << result;
    std::ifstream myFile(ss.str().c_str());
    if (myFile.good())
    {
        SceneItem *item = new SceneItem;
        getline(myFile, item->id);
        getline(myFile, item->bgm);
        myFile.close();

        std::cout << "\nGame loaded!\n\n";
        UI::sleep(1250);
        UI::clear();

        return item;
    }
    else
        return NULL;
}