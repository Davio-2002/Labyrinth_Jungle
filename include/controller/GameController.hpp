#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "GameView.hpp"

struct Mode final {
    void treeoCalypseMode();

    void welcomeToTheJungleMode();
};

class GameController final {
public:
    explicit GameController();

    void handleEvents() const;

private:
    std::shared_ptr<Labyrinth> labyrinth_{};
    std::shared_ptr<HumanPlayer> player_{};
    std::shared_ptr<GameView> view_{};
};

#endif
