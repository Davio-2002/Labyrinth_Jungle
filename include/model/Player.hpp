#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "utils/Directions.hpp"

class IPlayer {
public:
    virtual ~IPlayer() = default;

    virtual void move(Direction) = 0;

    virtual void cutTree() = 0;
};

#endif