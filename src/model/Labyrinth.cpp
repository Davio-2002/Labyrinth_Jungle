#include "Labyrinth.hpp"

#include <algorithm>
#include <iostream>

Labyrinth::Labyrinth(const size_t dim_) : dim{dim_} {
    matrixSize = 2 * dim + 1;
    labyrinth = CellMatrix(matrixSize, std::vector<Cell>(matrixSize));
    for (size_t y = 0; y < matrixSize; ++y) {
        for (size_t x = 0; x < matrixSize; ++x) {
            labyrinth[y][x] = Cell(x, y);
            //// Coloring borders in brown for not confusing with trees
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

////Randomize iterative DFS, generates 'perfect' maze, with only one possible solution
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
