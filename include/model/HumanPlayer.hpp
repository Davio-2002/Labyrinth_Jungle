#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"

class HumanPlayer final : public IPlayer {
public:
    explicit HumanPlayer() : IPlayer() {
        posX = 0;
        posY = 0;
    }

    void move(Direction directions) override;

    void cutTree() override;

    int getX() const { return posX; }
    int getY() const { return posY; }

private:
    int posX{};
    int posY{};
};

#endif
