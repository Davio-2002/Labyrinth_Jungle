#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer() {
    initPlayerPos();
}

void HumanPlayer::initPlayerPos() {
    posX = 1;
    posY = 1;
}

void HumanPlayer::move(size_t dx, size_t dy, Labyrinth& labyrinth) {
    auto restrictionCell = labyrinth.getLabyrinth()[posY + dy][posX + dx].getState();
    if ( restrictionCell != CellState::TREE && restrictionCell != CellState::BORDER) {
        posX += dx;
        posY += dy;
    }
}

void HumanPlayer::cutTree() {

}
