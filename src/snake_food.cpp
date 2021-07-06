#include "snake_food.h"
#include "color.h"


SnakeFood::SnakeFood(const int _x,
                     const int _y,
                     const Color _color,
                     const int _display_interval,
                     const bool _decreases_snake_speed,
                     const bool _decreases_snake_body,
                     const bool _kills_snake)
                    : x(_x),
                      y(_y),
                      color(_color),
                      display_interval(_display_interval),
                      decreases_snake_speed(_decreases_snake_speed),
                      decreases_snake_body(_decreases_snake_body),
                      kills_snake(_kills_snake)
{
}

int SnakeFood::getDisplayInterval() const
{
    return display_interval;
}

Color SnakeFood::getColor() const
{
    return color;
}

bool SnakeFood::isSnakeFoodCell(const int new_x, const int new_y) const
{
    return x == new_x && y == new_y;
}

bool SnakeFood::decreasesSnakeSpeed() const
{
    return decreases_snake_speed;
}

bool SnakeFood::decreasesSnakeBody() const
{
    return decreases_snake_body;
}

bool SnakeFood::killsSnake() const
{
    return kills_snake;
}
