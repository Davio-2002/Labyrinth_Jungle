#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"

class HumanPlayer : public IPlayer {
public:
    explicit HumanPlayer();

    void initPlayerPos();

    void move(int dx, int dy, IMoveValidator&) override;

    void cutTree() override;

    float getX() const { return posX; }
    float getY() const { return posY; }

private:
    int posX{};
    int posY{};
};

#endif
