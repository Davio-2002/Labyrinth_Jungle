#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <memory>

#include "view/GameView.hpp"

class GameController final {
public:
    explicit GameController(const std::shared_ptr<HumanPlayer> &player, const std::shared_ptr<GameView> &view);

    void handleEvents() const;

    // #TODO -> still thinking...
    void updateGameMode();
private:

    std::shared_ptr<HumanPlayer> player_{};
    std::shared_ptr<GameView> view_{};

    // void treeocalypseMode();
    // void welcomeToTheJungleMode();
};

#endif
