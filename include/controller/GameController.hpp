#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "GameView.hpp"

enum class GameState {
    INGAME,
    RESTART
};

// TODO -> we are not sure about this yet
struct Mode final {
    void treeoCalypseMode();

    void welcomeToTheJungleMode();
};

class GameController final {
public:
    explicit GameController();

    void handleKeyPress(sf::Keyboard::Key&);

    void handleEvents();

    void resetGame() const;

    GameState setToFinished() const;

private:
    mutable GameState playState;
    std::shared_ptr<GameView> view_{};
};

#endif
