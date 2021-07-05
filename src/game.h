#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "snake_food.h"

#include "SDL.h"

#include <random>
#include <vector>

// forward declarations
class Renderer;
class SnakeFood;


class Game {
public:
    Game(const std::size_t grid_width, const std::size_t grid_height);
    void Run(const Controller &controller,
             Renderer &renderer,
             const std::size_t target_frame_duration);
    int GetScore() const;
    int GetSize() const;

private:
    Snake snake;
    std::vector<SnakeFood> foods;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};

    void PlaceFood();
    void Update();
};

#endif