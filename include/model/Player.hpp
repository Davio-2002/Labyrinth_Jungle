#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Labyrinth.hpp"

class Labyrinth;

class IPlayer {
public:
    virtual void move(int, int, Labyrinth &) = 0;

    virtual void cutTree() = 0;

    virtual ~IPlayer() = default;
};

#endif
