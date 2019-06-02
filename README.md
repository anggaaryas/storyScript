# storyScript
The storyScript is Game-Development tool for prototyping Game's story. Especially for visual novel Game. Please check the [Release](https://github.com/anggaaryas/storyScript/releases) section for compiled project.

## Feature
- [x] Create project
- [x] Save Game
- [x] Load Game
- [ ] Linux support
- [ ] Export to another Game Engine
- [ ] ...

## Install

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

Make sure use Windows Operating System to compile the project. Linux support will be coming soon.

How to compile:

```
cd $dir && g++ -std=c++14 *.cpp  -lwinmm $path_winmm.dll -o $compiled_name
```

## Usage

### The .StoryScript

```
* {
   "This is the first scene"
   
   b = "one.wav";
   c = "start" -> s1;
}

s1 {
    "This is the second scene"

    b = "STOP";
}
```

Param | Description
------|-------------
b | Add BGM sound. when b is "STOP", stop the BGM.
c | Add choose option. when when c is "NEXT", next Scene will be automaticaly choose.

## Additional Library

* [Dirent](https://github.com/tronkko/dirent) - C/C++ library for retrieving information on files and directories

## Authors

* **Angga Arya Saputra** - *Initial work* - [anggaaryas](https://github.com/anggaaryas)

## License

This project is licensed under the GNU GPL V3.0 License - see the [LICENSE.md](LICENSE.md) file for details
