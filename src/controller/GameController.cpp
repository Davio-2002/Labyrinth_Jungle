#include "GameController.hpp"

GameController::GameController() {
    view_ = std::make_shared<GameView>(30);
}

void GameController::handleEvents() const {
    sf::Event event;

    while (view_->window().isOpen()) {
        while (view_->window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) view_->window().close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    view_->window().close();
                } else if (event.key.code == sf::Keyboard::Right) {
                    view_->getHuman()->move(1, 0, *view_->getLabyrinth());
                } else if (event.key.code == sf::Keyboard::Left) {
                    view_->getHuman()->move(-1, 0, *view_->getLabyrinth());
                } else if (event.key.code == sf::Keyboard::Up) {
                    view_->getHuman()->move(0, -1, *view_->getLabyrinth());
                } else if (event.key.code == sf::Keyboard::Down) {
                    view_->getHuman()->move(0, 1, *view_->getLabyrinth());
                }
            }
        }

        view_->window().clear(sf::Color::Black);
        view_->render();
    }
}

void Mode::treeoCalypseMode() {

}

void Mode::welcomeToTheJungleMode() {

}
