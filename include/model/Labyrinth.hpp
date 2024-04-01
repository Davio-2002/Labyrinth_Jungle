#ifndef LABYRINTH_HPP
#define LABYRINTH_HPP

#include <array>
#include <vector>
#include <stack>
#include <random>

#include "Cell.hpp"

namespace {
    using LabyrinthVector = std::vector<std::vector<Cell> >;
    using UnvisitedNeighbourVector = std::vector<std::pair<size_t, size_t>>;
}

class Labyrinth final {
public:
    explicit Labyrinth(size_t dim);

    void generateViaDFS();

    void setRandomExit();

    size_t getDim() const {
        return dim;
    }

    LabyrinthVector getLabyrinth() const {
        return labyrinth;
    }

private:
    static constexpr size_t DIRCOUNT = 4;
    LabyrinthVector labyrinth{};
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    size_t dim{};
    size_t matrixSize{};

    UnvisitedNeighbourVector getUnvisitedNeighbours(const size_t& curr_x, const size_t& curr_y);

    void carvePathBetweenTrees(const size_t &curr_x, const size_t &curr_y, const size_t next_x, const size_t next_y);

    size_t generateRandom(size_t start, size_t dest);
};

#endif
