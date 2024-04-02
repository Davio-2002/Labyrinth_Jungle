#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"

class HumanPlayer final : public IPlayer {
public:
    explicit HumanPlayer();

    void initPlayerPos();

    void move(size_t dx, size_t dy, Labyrinth& labyrinth) override;

    void cutTree() override;

    float getX() const { return posX; }
    float getY() const { return posY; }

private:
    int posX{};
    int posY{};
};

#endif
