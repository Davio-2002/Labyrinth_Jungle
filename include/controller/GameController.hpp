#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "GameView.hpp"
#include "GameFlowControl.hpp"

class GameController final {
public:
    explicit GameController();

    void handleKeyPress(sf::Keyboard::Key &);

    void handleEvents();

    void resetGame();

    void setMode();

    GameState setToFinished() const;

private:
    mutable GameState playState;
    mutable GameMode gameMode;
    std::shared_ptr<GameView> view_{};
};

#endif
