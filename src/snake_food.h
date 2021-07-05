#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include "color.h"
#include "game.h"

#include "SDL.h"


class SnakeFood
{
public:
    SnakeFood(const int _x,
              const int _y,
              const Color _color,
              const int _display_interval,
              const bool _decreases_snake_speed);

    int getDisplayInterval() const;
    Color getColor() const;
    bool isSnakeFoodCell(int x, int y) const;
    bool decreasesSnakeSpeed() const;

    int x;
    int y;

private:
    int display_interval;
    bool decreases_snake_speed = false;
    Color color;
};

#endif
