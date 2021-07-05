#include "renderer.h"
#include "snake_food.h"

#include <iostream>
#include <string>
#include <vector>


Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width,
                   const std::size_t grid_height)
                : screen_width(screen_width),
                  screen_height(screen_height),
                  grid_width(grid_width),
                  grid_height(grid_height)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Snake Game",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  screen_width,
                                  screen_height,
                                  SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(const Snake& snake, const std::vector<SnakeFood>& foods)
{
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer,
                           Colors::charcoal.red_channel_value,
                           Colors::charcoal.green_channel_value,
                           Colors::charcoal.blue_channel_value,
                           Colors::charcoal.alpha_channel_value);
    SDL_RenderClear(sdl_renderer);

    // Render food
    for (auto& food : foods) {
        SDL_SetRenderDrawColor(sdl_renderer,
                               food.getColor().red_channel_value,
                               food.getColor().green_channel_value,
                               food.getColor().blue_channel_value,
                               food.getColor().alpha_channel_value);
        block.x = food.x * block.w;
        block.y = food.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer,
                           Colors::white.red_channel_value,
                           Colors::white.green_channel_value,
                           Colors::white.blue_channel_value,
                           Colors::white.alpha_channel_value);
    for (SDL_Point const &point : snake.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if (snake.alive) {
        SDL_SetRenderDrawColor(sdl_renderer,
                               Colors::blue.red_channel_value,
                               Colors::blue.green_channel_value,
                               Colors::blue.blue_channel_value,
                               Colors::blue.alpha_channel_value);
    } else {
        SDL_SetRenderDrawColor(sdl_renderer,
                               Colors::red.red_channel_value,
                               Colors::red.green_channel_value,
                               Colors::red.blue_channel_value,
                               Colors::red.alpha_channel_value);
    }
    SDL_RenderFillRect(sdl_renderer, &block);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps)
{
    std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
