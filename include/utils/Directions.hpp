#ifndef DIRECTIONS_HPP
#define DIRECTIONS_HPP
#include <utility>

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

constexpr std::pair<int, int> directionOffsets[] = {
    {-1, 0}, // Up -> by decreasing row number
    {1, 0}, // Down -> by increasing row number
    {0, -1}, // Left -> by decreasing column number
    {0, 1} // Right -> by increasing column number
};

#endif
