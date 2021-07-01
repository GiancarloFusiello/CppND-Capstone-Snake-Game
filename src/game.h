#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "renderer.h"
#include "snake.h"

#include "SDL.h"

#include <random>


class Game {
public:
    Game(std::size_t grid_width, std::size_t grid_height);
    void Run(Controller const &controller,
             Renderer &renderer,
             std::size_t target_frame_duration);
    int GetScore() const;
    int GetSize() const;

private:
    Snake snake;
    SDL_Point food;
    SDL_Point slow_down_food;  // when eaten decreases the snake speed

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};
    int slow_down_food_interval{8};  // number of points until shown

    void PlaceFood();
    void PlaceSlowDownFood();
    void Update();
};

#endif