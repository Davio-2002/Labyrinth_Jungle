#include <iostream>
#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer() {
    initPlayerPos();
}

void HumanPlayer::initPlayerPos() {
    posX = 1;
    posY = 1;
}

bool HumanPlayer::canMove(int dx, int dy, Labyrinth labyrinth, GameMode &mode) {
    return labyrinth.canMove(posX, posY, dx, dy, mode);
}

void HumanPlayer::leaveTail(int dx, int dy, Labyrinth &labyrinth) {
    labyrinth.setLabyrinthState(dx, dy, CellState::TAIL);
}

void HumanPlayer::updatePosition(int dx, int dy, Labyrinth &labyrinth) {
    posX += dx;
    posY += dy;
    leaveTail(posX - dx, posY - dy, labyrinth);
}

void HumanPlayer::move(int dx, int dy, Labyrinth &labyrinth, GameMode &mode) {
    if (canCutTree(labyrinth, dx, dy, mode)) {
        updatePosition(dx, dy, labyrinth);
        labyrinth.updateLabyrinthAccordingToGameMode(*this, mode);
    }
}

bool HumanPlayer::canCutTree(Labyrinth &labyrinth, int dx, int dy, GameMode &mode) {
    return canMove(dx, dy, labyrinth, mode);
}
