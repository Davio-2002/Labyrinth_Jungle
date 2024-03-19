#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
    virtual ~Player() = default;

    virtual void move(int dx, int dy) = 0;

    virtual void cutTree() = 0;

protected:
    int posX{};
    int posY{};
};

#endif
