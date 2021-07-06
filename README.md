# CPPND: Capstone Snake Game

For the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213)
I decided to extend the [Snake Game](https://github.com/udacity/CppND-Capstone-Snake-Game) example code
that was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) 
excellent StackOverflow post and set of responses.

![snake game gif](images/snake_game.gif)

I have extended the game by adding new foods that have different effects. They are as follows:

![cyan colored food](images/cyan-snake-food.png) 
appears after every 10 points scored and decreases the snakes speed when eaten

![green colored food](images/green-snake-food.png)
appears after every 13 points scored and decreases the snakes body size when eaten

![magenta colored food](images/magenta-snake-food.png)
appears after every 15 points scored and kills the snake when eaten

## Rubric points
**The project demonstrates an understanding of C++ functions and control structures** - This can be found in
`src/game.cpp` between lines 71-93 and 95-128.

**The project uses Object Oriented Programming techniques** - class `SnakeFood` in `src/snake_food.h` 
replaces `Game.food` (line 20 in `src/game.h` commit beginning a4457ef) which encapsulates properties 
of snake food.

**Classes use appropriate access specifiers for class members** - This can be found in `src/snake_food.h`
on lines 12, 31.

**Class constructors utilize member initialization lists** - This can be found in `src/snake_food.cpp` 
on lines 5-18.

**Classes abstract implementation details from their interfaces** - This can found through `src/snake_food.cpp`
where member functions are used to get private attributes that should be not mutable by the calling class/function.

**Classes encapsulate behavior** - This can be seen in `src/snake_food.h` and `src/color.h` where the `SnakeFood`
 and `Color` types where added to encapsulate the relevant data. The `Game`, `Snake` and `Renderer` classes
where modified to utilize these new types.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
