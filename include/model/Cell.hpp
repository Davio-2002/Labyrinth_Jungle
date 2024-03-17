#ifndef CELL_HPP
#define CELL_HPP

enum class CellType {
    EMPTY = 0,
    TREE = 1,
    PLANTED = 2,
    EXIT = 3
};

struct Cell final {
    CellType type;
    int countdown{};

    explicit Cell(const CellType &type_ = CellType::EMPTY, const int countdown_ = 0) : type(type_),
        countdown(countdown_) {
    }
};

#endif
