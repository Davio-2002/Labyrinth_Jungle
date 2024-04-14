#include <iostream>
#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer() {
    initPlayerPos();
}

void HumanPlayer::initPlayerPos() {
    posX = 1;
    posY = 1;
}

bool HumanPlayer::canMove(int dx, int dy, const Labyrinth &labyrinth) const {
    return labyrinth.canMove(posX, posY, dx, dy);
}

void HumanPlayer::leaveTail(int dx, int dy, Labyrinth& labyrinth) {
    labyrinth.setLabyrinthState(dx, dy, CellState::TAIL);
}

void HumanPlayer::updatePosition(int dx, int dy, Labyrinth& labyrinth) {
    posX += dx;
    posY += dy;
    leaveTail(posX - dx, posY - dy, labyrinth);
}

void HumanPlayer::updateLabyrinth(Labyrinth &labyrinth) {
    labyrinth.plantCellsRandomly();
    labyrinth.turnPlantsToTrees(*this);
}

void HumanPlayer::move(int dx, int dy, Labyrinth &labyrinth) {
    if (canMove(dx, dy, labyrinth)) {
        updatePosition(dx, dy, labyrinth);
        updateLabyrinth(labyrinth);
    }
}

void HumanPlayer::cutTree() {

}