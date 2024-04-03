#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "IMoveValidator.hpp"

class IPlayer {
public:
    virtual void move(int, int, IMoveValidator&) = 0;

    virtual void cutTree() = 0;

    virtual ~IPlayer() = default;
};

#endif