#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Labyrinth.hpp"

class IPlayer {
public:
    virtual void move(size_t, size_t, Labyrinth& labyrinth) = 0;

    virtual void cutTree() = 0;

    virtual ~IPlayer() = default;
};

#endif