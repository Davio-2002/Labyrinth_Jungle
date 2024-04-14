#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"

class HumanPlayer : public IPlayer {
public:
    explicit HumanPlayer();

    void initPlayerPos();

    void move(int dx, int dy, Labyrinth &) override;

    void cutTree() override;

    float getX() const { return posX; }

    float getY() const { return posY; }

private:
    int posX{};
    int posY{};

    void updateLabyrinth(Labyrinth &labyrinth);

    void updatePosition(int dx, int dy, Labyrinth&);

    bool canMove(int dx, int dy, const Labyrinth &labyrinth) const;

    void leaveTail(int dx, int dy, Labyrinth &labyrinth);
};

#endif
