#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer() {
    initPlayerPos();
}

void HumanPlayer::initPlayerPos() {
    posX = 1;
    posY = 1;
}

void HumanPlayer::move(int dx, int dy, IMoveValidator& validator) {
    if ( validator.canMove(posX, posY, dx, dy)) {
        posX += dx;
        posY += dy;
    }
}

void HumanPlayer::cutTree() {

}
