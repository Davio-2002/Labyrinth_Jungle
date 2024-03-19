#include "controller/GameController.hpp"

GameController::GameController(const std::shared_ptr<HumanPlayer> &player, const std::shared_ptr<GameView> &view) {
    player_ = player;
    view_ = view;
}

void GameController::handleEvents() const {
    sf::Event event;

    while( view_->window().isOpen() ) {
        while( view_->window().pollEvent(event) ) {
            if (event.type == sf::Event::Closed) view_->window().close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) view_->window().close();
            }
        }

        view_->window().clear();
        view_->render();
    }
}
