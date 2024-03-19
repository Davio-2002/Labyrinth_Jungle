#ifndef LABYRINTH_HPP
#define LABYRINTH_HPP

#include <vector>
#include <optional>
#include "Cell.hpp"

class Labyrinth final {
public:
    explicit Labyrinth();

    void generateLabyrinth();

    std::optional<std::pair<int, int>> findExit();

    // TODO: լիքը բան կա հլը ստե անելու

private:
    std::vector<std::vector<Cell> > labyrinth{};
    int height{};
    int width{};
};

#endif
