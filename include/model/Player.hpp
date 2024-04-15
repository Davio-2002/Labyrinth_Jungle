#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Labyrinth.hpp"
#include "GameFlowControl.hpp"

class Labyrinth;

class IPlayer {
public:
    virtual void move(int, int, Labyrinth &, GameMode &) = 0;

    virtual bool canCutTree(Labyrinth &, int, int, GameMode &) = 0;

    virtual ~IPlayer() = default;
};

#endif
