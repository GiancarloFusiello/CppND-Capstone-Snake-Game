#ifndef RENDERER_H
#define RENDERER_H

#include "snake.h"
#include "snake_food.h"

#include "SDL.h"

#include <vector>

// forward declarations
class SnakeFood;


class Renderer {
public:
    Renderer(const std::size_t screen_width,
             const std::size_t screen_height,
             const std::size_t grid_width,
             const std::size_t grid_height);

    ~Renderer();

    void Render(const Snake& snake, const std::vector<SnakeFood>& edibles);
    void UpdateWindowTitle(int score, int fps);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif