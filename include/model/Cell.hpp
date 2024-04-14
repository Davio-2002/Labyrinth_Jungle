#ifndef CELL_HPP
#define CELL_HPP

enum class CellState {
    PATH,
    BORDER,
    TREE,
    TAIL,
    PLANTED,
    EXIT
};

class Cell final {
private:
    CellState state;
    size_t countDown{};
    size_t x{};
    size_t y{};
    size_t distance{};
    bool visited{false};

public:
    Cell() = default;

    explicit Cell(const size_t x_, const size_t y_) : state{CellState::TREE}, x{x_}, y{y_} {
    }

    void makePlant() {
        if (state == CellState::PATH) {
            state = CellState::PLANTED;
        }
    }

    bool isPlanted() const {
        return state == CellState::PLANTED;
    }

    //// Check if cell is already visited
    bool isVisited() const {
        return visited;
    }

    void setVisited(bool visited_) {
        Cell::visited = visited_;
    }

    //// Countdown for cell to become planted
    size_t getCountDown() const {
        return countDown;
    }

    void setCountDown(size_t countDown_) {
        Cell::countDown = countDown_;
    }

    //// State of cell
    CellState getState() const {
        return state;
    }

    void setState(CellState state_) {
        Cell::state = state_;
    }

    //// Actual coordinates
    size_t getX() const {
        return x;
    }

    size_t getY() const {
        return y;
    }

    size_t getDistance() const {
        return distance;
    }

    void setDistance(size_t distance_) {
        Cell::distance = distance_;
    }
};


#endif
