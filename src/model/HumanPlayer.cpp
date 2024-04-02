#include "HumanPlayer.hpp"

void HumanPlayer::move(size_t dx, size_t dy, Labyrinth& labyrinth) {
    auto restrictionCell = labyrinth.getLabyrinth()[posY + dy][posX + dx].getState();
    if ( restrictionCell != CellState::TREE && restrictionCell != CellState::BORDER) {
        posX += dx;
        posY += dy;
    }
}

void HumanPlayer::cutTree() {

}
