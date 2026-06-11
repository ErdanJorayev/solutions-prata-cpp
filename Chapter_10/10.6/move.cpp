#include "move.h"
#include <iostream>
Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';
}

Move Move::add(const Move & m) const
{
    double n_x = x + m.x;
    double n_y = y + m.y;
    return Move(n_x, n_y);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}