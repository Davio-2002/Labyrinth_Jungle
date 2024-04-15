#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"

class HumanPlayer : public IPlayer {
public:
    explicit HumanPlayer();

    void initPlayerPos();

    void move(int dx, int dy, Labyrinth &, GameMode &) override;

    bool canCutTree(Labyrinth&, int dx, int dy, GameMode& mode) override;

    float getX() const { return posX; }

    float getY() const { return posY; }

private:
    int posX{};
    int posY{};

    void updatePosition(int dx, int dy, Labyrinth &);

    bool canMove(int dx, int dy, Labyrinth labyrinth, GameMode& mode);

    void leaveTail(int dx, int dy, Labyrinth &labyrinth);

};

#endif
