#ifndef LABYRINTH_HPP
#define LABYRINTH_HPP

#include <array>
#include <random>
#include <stack>
#include <vector>

#include "Cell.hpp"

class Labyrinth final {
public:
    using CellMatrix = std::vector<std::vector<Cell>>;
    using UnvisitedNeighbours = std::vector<std::pair<size_t, size_t>>;

    explicit Labyrinth(size_t dim);

    void generateViaDFS();

    void setRandomExit();

    void resetLabyrinth();

    void initializeBoard();

    size_t getDim() const {
        return dim;
    }

    CellMatrix getLabyrinth() const {
        return labyrinth;
    }

    size_t getMatrixSize() const {
        return matrixSize;
    }

private:
    static constexpr size_t DIRCOUNT = 4;
    CellMatrix labyrinth{};
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    size_t dim{};
    size_t matrixSize{};

    UnvisitedNeighbours getUnvisitedNeighbours(const size_t &curr_x, const size_t &curr_y);

    void carvePathBetweenTrees(const size_t &curr_x, const size_t &curr_y, const size_t next_x, const size_t next_y);

    size_t generateRandom(size_t start, size_t dest);
};

#endif
