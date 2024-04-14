#include "Labyrinth.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <stack>
#include <queue>

Labyrinth::Labyrinth(const size_t labSize_) : matrixSize{labSize_}, directions{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}} {
    if (labSize_ % 2 == 0) matrixSize += 1;
    rooms = (matrixSize - 1) / 2;

    setBoardToDefaults();
}

bool Labyrinth::isExitReached(HumanPlayer &human) {
    return labyrinth[human.getY()][human.getX()].getState() == CellState::EXIT;
}

bool Labyrinth::canMove(int posX, int posY, int dx, int dy) const {
    int newX = posX + dx;
    int newY = posY + dy;

    if (newX < 0 || newX >= matrixSize || newY < 0 || newY >= matrixSize)
        return false;

    const Cell &destinationCell = labyrinth[newY][newX];
    CellState state = destinationCell.getState();

    return state != CellState::TREE && state != CellState::BORDER;
}

void Labyrinth::setBoardToDefaults() {
    labyrinth.resize(matrixSize, std::vector<Cell>(matrixSize));

    for (size_t y = 0; y < matrixSize; ++y) {
        for (size_t x = 0; x < matrixSize; ++x) {
            labyrinth[y][x] = Cell(x, y);
            if (x == 0 || y == 0 || x == matrixSize - 1 || y == matrixSize - 1) {
                labyrinth[y][x].setState(CellState::BORDER);
            }
        }
    }
}

size_t Labyrinth::generateRandom(size_t start, size_t dest) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(start, dest);
    return distr(gen);
}

void Labyrinth::setRandomExit() {
    size_t rand_x = generateRandom(1, matrixSize - 2);
    size_t rand_y = matrixSize - 1;
    if (labyrinth[rand_y - 1][rand_x].getState() == CellState::TREE) {
        labyrinth[rand_y - 1][rand_x].setState(CellState::PATH);
    }
    labyrinth[rand_y][rand_x].setState(CellState::EXIT);
}

Labyrinth::UnvisitedNeighbours Labyrinth::getUnvisitedNeighbours(const size_t &curr_x, const size_t &curr_y) {
    UnvisitedNeighbours unvisitedNeighbors;

    for (const auto &dir: directions) {
        auto new_x = curr_x + 2 * dir.first;
        auto new_y = curr_y + 2 * dir.second;

        if (new_x > 0 && new_x < matrixSize - 1 && new_y > 0 && new_y < matrixSize - 1 &&
            !labyrinth[new_y][new_x].isVisited()) {
            unvisitedNeighbors.emplace_back(new_x, new_y);
        }
    }

    return unvisitedNeighbors;
}

void
Labyrinth::carvePathBetweenTrees(const size_t &curr_x, const size_t &curr_y, const size_t next_x, const size_t next_y) {
    labyrinth[(curr_y + next_y) / 2][(curr_x + next_x) / 2].setState(CellState::PATH);
    labyrinth[next_y][next_x].setState(CellState::PATH);
    labyrinth[next_y][next_x].setVisited(true);
}

void Labyrinth::generateViaDFS() {
    std::random_device rd;
    std::mt19937 gen(rd());

    auto initialX = 1;
    auto initialY = 1;
    labyrinth[initialY][initialX].setState(CellState::PATH);
    labyrinth[initialY][initialX].setVisited(true);

    std::stack<std::pair<size_t, size_t>> cellStack;
    cellStack.emplace(initialX, initialY);

    while (!cellStack.empty()) {
        auto [curr_x, curr_y] = cellStack.top();
        cellStack.pop();

        auto unvisitedNeighbors = getUnvisitedNeighbours(curr_x, curr_y);

        if (!unvisitedNeighbors.empty()) {
            cellStack.emplace(curr_x, curr_y);

            std::shuffle(unvisitedNeighbors.begin(), unvisitedNeighbors.end(), gen);
            auto [next_x, next_y] = unvisitedNeighbors.front();

            carvePathBetweenTrees(curr_x, curr_y, next_x, next_y);

            cellStack.emplace(next_x, next_y);
        }
    }
}

int Labyrinth::generateRandomCountdown() {
    return generateRandom(7, 10);
}

void Labyrinth::plantCellsRandomly() {
    PathCells emptyCells;

    for (size_t y = 0; y < matrixSize; ++y) {
        for (size_t x = 0; x < matrixSize; ++x) {
            if (labyrinth[y][x].getState() == CellState::PATH) {
                emptyCells.emplace_back(x, y);
            }
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(emptyCells.begin(), emptyCells.end(), gen);

    for (auto i = 0; i < std::min(3, static_cast<int>(emptyCells.size())); ++i) {
        auto [x, y] = emptyCells[i];
        labyrinth[y][x].makePlant();
        std::cout << x << " " << y << std::endl;
    }
}

void Labyrinth::leaveTail(int dx, int dy) {
    labyrinth[dy][dx].setState(CellState::TAIL);
}

void Labyrinth::turnPlantsToTrees(HumanPlayer &player) {
    for (auto &row: labyrinth) {
        for (auto &cell: row) {
            if (cell.getState() == CellState::PLANTED && cell.getX() != player.getX() && cell.getY() != player.getY()) {
                if (cell.getCountDown() == 0) {
                    cell.setState(CellState::TREE);
                } else {
                    cell.setCountDown(cell.getCountDown() - 1);
                }
            }
        }
    }
}
