#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "GameView.hpp"

enum class GameState {
    PLAYING,
    RESTART
};

struct Mode final {
    void treeoCalypseMode();

    void welcomeToTheJungleMode();
};

class GameController final {
public:
    explicit GameController();

    void handleEvents() const;

    void resetGameOnExit() const;

    GameState setToFinished() const;

private:
    mutable GameState playState;
    std::shared_ptr<GameView> view_{};
};

#endif
