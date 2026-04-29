#include "game.h"

int game(char p1, char p2)
{
    if (p1 == p2)
        return -1;

    else if (p1 == 's' && p2 == 'p') return 0;
    else if (p1 == 'p' && p2 == 's') return 1;

    else if (p1 == 's' && p2 == 'c') return 1;
    else if (p1 == 'c' && p2 == 's') return 0;

    else if (p1 == 'p' && p2 == 'c') return 0;
    else if (p1 == 'c' && p2 == 'p') return 1;

    return -2;
}