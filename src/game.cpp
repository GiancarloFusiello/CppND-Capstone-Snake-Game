#include "color.h"
#include "game.h"
#include "snake_food.h"

#include "SDL.h"


Game::Game(const std::size_t grid_width,
           const std::size_t grid_height)
        : snake(grid_width, grid_height),
          engine(dev()),
          random_w(0, static_cast<int>(grid_width - 1)),
          random_h(0, static_cast<int>(grid_height - 1))
{
    int x = random_w(engine);
    int y = random_h(engine);
    SnakeFood food(x, y, Colors::yellow, 1, false);
    SnakeFood slow_down_food(-1, -1, Colors::cyan, 10, true);

    foods.push_back(food);
    foods.push_back(slow_down_food);
}

void Game::Run(const Controller &controller,
               Renderer &renderer,
               const std::size_t target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running) {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, snake);
        Update();
        renderer.Render(snake, foods);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(score, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::PlaceFood()
{
    int x, y;
    for (auto& food : foods) {
        if (score % food.getDisplayInterval() == 0) {
            while (true) {
                x = random_w(engine);
                y = random_h(engine);
                // Check that the location is not occupied by a snake item before placing
                // food.
                if (!snake.isSnakeCell(x, y)) {
                    food.x = x;
                    food.y = y;
                    break;
                }
            }
        } else {
            // place food off-screen when they are not ready to be displayed
            food.x = -1;
            food.y = -1;
        }
    }
}

void Game::Update()
{
    if (!snake.alive) return;

    snake.Update();

    int new_x = static_cast<int>(snake.head_x);
    int new_y = static_cast<int>(snake.head_y);

    for (auto& food : foods) {
        if (food.isSnakeFoodCell(new_x, new_y)) {
            score++;
            PlaceFood();
            snake.GrowBody();
            if (food.decreasesSnakeSpeed()) {
                snake.speed /= 1.3;
            } else {
                snake.speed += 0.02;
            }
            break;
        }
    }
}

int Game::GetScore() const { return score; }

int Game::GetSize() const { return snake.size; }