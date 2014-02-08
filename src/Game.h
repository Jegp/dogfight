#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <SDL/SDL.h>

#include "Environment.h"

/**
 * The main Game class.
 */
class Game {

private:
    int round;

public:
    Game(Environment* environment);
    void start();

};


#endif /* GAME_H */