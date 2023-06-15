# storyScript
The storyScript is Game-Development tool for prototyping Game's story. Especially for visual novel Game. Please check the [Release](https://github.com/anggaaryas/storyScript/releases) section for compiled project.

## Feature
- [x] Create project
- [x] Save Game
- [x] Load Game
- [x] Linux support (but no sound. will fix later)
- [ ] Export to another Game Engine
- [ ] ...

## Install

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

How to compile:

```
cd $dir && g++ -std=c++14 *.cpp  -lwinmm $path_winmm.dll -o $compiled_name
```


## * .StoryScript Documentation

The * .StoryScript format is a scripting language designed to create interactive scenes or narratives. This documentation explains the usage and syntax of the format.

### Scene Definition

A scene is defined using the `*` symbol followed by the scene label. The scene label represents a specific section or moment in the narrative. The first scene defined using `*` will always be called first.

**Syntax:**
```
* <scene_label> {
    <scene_description>
    <scene_actions>
}
```

### Scene Description

The scene description includes narrative text or character dialogue that represents the content of the scene. It helps to set the stage and provide context for the player or reader.

**Syntax:**
```
"<scene_description>"
```

### Scene Actions

Scene actions define additional elements within the scene, such as background music and transitions.

#### Adding Background Music (BGM)

To add background music to a scene, use the `b` parameter. Assign the file name of the background music track to the variable `b`. The BGM will play while the scene is active.

**Syntax:**
```
b = "<bgm_file_name>";
```

To stop the background music for a specific scene, assign the value `"STOP"` to the variable `b`.

**Syntax:**
```
b = "STOP";
```

#### Transitions

Transitions allow the story to progress based on choices or conditions. Use the `c` parameter to define choose options and their corresponding scene transitions.

**Syntax:**
```
c = "<option_1>" -> <next_scene_1>,
    "<option_2>" -> <next_scene_2>,
    ...
```

The `c` parameter assigns a chosen option to the variable `c`. When the assigned option is selected, the story will transition to the corresponding next scene.

### Example Usage

Here's an example of a "* .StoryScript" file with multiple scenes, including background music and transitions:

```plaintext
* {
   "Welcome to the mysterious forest!"

   b = "forest.wav";
   c = "continue" -> s1;
}

s1 {
   "You encounter a fork in the path."

   b = "STOP";
   c = "Go left" -> s2,
       "Go right" -> s3;
}

s2 {
   "You follow the left path and find a hidden treasure chest."

   b = "chest.wav";
   c = "Open the chest" -> s4,
       "Ignore the chest" -> s5;
}

s3 {
   "You take the right path and come across a fierce monster."

   b = "monster.wav";
   c = "Fight the monster" -> s6,
       "Run away" -> s7;
}

s4 {
   "Congratulations! You found a rare gemstone in the chest."

   b = "STOP";
}

s5 {
   "You decide to ignore the chest and continue your journey."

   b = "STOP";
}

s6 {
   "You bravely engage in a battle with the monster."

   b = "battle.wav";
   c = "Attack" -> s8,
       "Defend" -> s9;
}

s7 {
   "You choose to run away and escape from the monster's grasp."

   b = "STOP";
}

s8 {
   "With your strong attack, you defeat the monster!"

   b = "victory.wav";
}

s9 {
   "You defend against the monster's attack and manage to survive."

   b = "STOP";
}
```

This example showcases a narrative where the player or reader explores a mysterious forest, encounters choices at forks in the path, finds a treasure chest, confronts a monster, and engages in battles. Background music and transitions are used to enhance the storytelling experience.

## Additional Library

* [Dirent](https://github.com/tronkko/dirent) - C/C++ library for retrieving information on files and directories

## Authors

* **Angga Arya Saputra** - *Initial work* - [anggaaryas](https://github.com/anggaaryas)

## License

This project is licensed under the GNU GPL V3.0 License - see the [LICENSE.md](LICENSE.md) file for details
