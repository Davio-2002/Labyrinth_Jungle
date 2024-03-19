#include <iostream>
#include "view/GameView.hpp"
#include "controller/GameController.hpp"
#include "model/HumanPlayer.hpp"

int main() {
    auto game = std::make_shared<HumanPlayer>();
    const auto render = std::make_shared<GameView>(game);

    const GameController controller(game, render);
    controller.handleEvents();

    return 0;
}