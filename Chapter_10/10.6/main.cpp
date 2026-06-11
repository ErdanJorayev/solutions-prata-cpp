#include <iostream>
#include "move.h"

int main()
{
    Move mv(23, 45);
    Move lol(11, 11);
    
    mv.showmove();
    Move kek = mv.add(lol);
    kek.showmove();
    kek.reset(1, 1);
    kek.showmove();

    return 0;
}