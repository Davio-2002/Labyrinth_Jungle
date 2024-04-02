#ifndef LABYRINTH_JUNGLE_2024_IMOVEVALIDATOR_HPP
#define LABYRINTH_JUNGLE_2024_IMOVEVALIDATOR_HPP

/*
     * This is an interface to validate move of player in labyrinth.
     * Main purpose of this interface is to prevent circular dependencies or any hardcoded class forward declarations to avoid them.
     * It acts as mediator between Labyrinth and HumanPlayer classes to reduce tight coupling between them
*/

class IMoveValidator {
public:
    virtual ~IMoveValidator() = default;

    virtual bool canMove(int posX, int posY, int dx, int dy) const = 0;
};

#endif