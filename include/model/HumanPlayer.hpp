#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP
#include "Player.hpp"

class HumanPlayer final : public Player {
public:
    explicit HumanPlayer() : Player() {
        posX = 0;
        posY = 0;
    }

    void move(int dx, int dy) override;

    void cutTree() override;

    int getX() const { return posX; }
    int getY() const { return posY; }
};

#endif
