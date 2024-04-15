#ifndef LABYRINTH_HPP
#define LABYRINTH_HPP

#include <array>
#include <random>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Cell.hpp"
#include "HumanPlayer.hpp"
#include "GameFlowControl.hpp"

class HumanPlayer;

namespace {
    constexpr const size_t initialX = 1;
    constexpr const size_t initialY = 1;
}

class Labyrinth final {
public:
    using CellMatrix = std::vector<std::vector<Cell>>;
    using UnvisitedNeighbours = std::vector<std::pair<size_t, size_t>>;
    using DirectionsPairs = std::vector<std::pair<int, int>>;
    using PathCells = std::vector<std::pair<size_t, size_t>>;
    using ExitCoordinates = std::pair<size_t, size_t>;
    using ShortestPathCoordinates = std::vector<std::pair<size_t, size_t>>;

    bool canMove(int posX, int posY, int dx, int dy, GameMode& mode);

    explicit Labyrinth(size_t rooms_);

    void generateViaDFS();

    void setRandomExits();

    void setBoardToDefaults();

    bool isExitReached(HumanPlayer &human);

    void plantCellsRandomly(GameMode& mode);

    void turnPlantsToTrees(HumanPlayer &);

    void setLabyrinthState(size_t dx, size_t dy, CellState state);

    void updateLabyrinthAccordingToGameMode(HumanPlayer &player, GameMode& mode);

    size_t getRooms() const {
        return rooms;
    }

    CellMatrix getLabyrinth() const {
        return labyrinth;
    }

    size_t getMatrixSize() const {
        return matrixSize;
    }

    size_t getLabyrinthSize() const {
        return labyrinth.size();
    }

    const ExitCoordinates &getExitCoord() const {
        return exitCoord;
    }

    size_t getMoves() const;

    size_t getAxeCount() const {
        return axeCounter;
    }

    void setAxeCount(size_t axeCount) {
        axeCounter = axeCount;
    }

    void setShortestPath() {
        shortestPath = bfsForShortestPath(1, 1, getExitCoord().first, getExitCoord().second);
        moves = shortestPath.size() + 15;
    }

private:
    CellMatrix labyrinth{};
    DirectionsPairs directions;
    size_t rooms{};
    size_t matrixSize{};
    size_t moves{};
    size_t treeCounter{};
    size_t axeCounter{};
    ExitCoordinates exitCoord{};
    ShortestPathCoordinates shortestPath{};

private:

    UnvisitedNeighbours getUnvisitedNeighbours(const size_t &curr_x, const size_t &curr_y);

    void carvePathBetweenTrees(const size_t &curr_x, const size_t &curr_y, const size_t next_x, const size_t next_y);

    int generateRandomCountdown(size_t src, size_t dest);

    size_t generateRandom(size_t start, size_t dest);

    ShortestPathCoordinates bfsForShortestPath(size_t startX, size_t startY, size_t destX, size_t destY);

    void splitRandomTreeToPath();
};

#endif
