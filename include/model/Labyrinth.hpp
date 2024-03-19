#ifndef LABYRINTH_HPP
#define LABYRINTH_HPP

#include <vector>
#include "Cell.hpp"

class Labyrinth final {
public:
    explicit Labyrinth();

    void labyrinthGenerationLogic();

    bool isMoveValid();

private:
    using LabyrinthVector = std::vector<std::vector<Cell>>;

    LabyrinthVector labyrinth{};
    int height{};
    int width{};
};

#endif
