#include "GameController.hpp"

GameController::GameController() : view_{std::make_shared<GameView>(5)}, playState{GameState::PLAYING} {}

void GameController::handleEvents() const {
    sf::Event event;
    while (view_->window().isOpen()) {
        while (view_->window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) view_->window().close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    view_->window().close();
                } else if (event.key.code == sf::Keyboard::Right) {
                    view_->getHumanPtr()->move(1, 0, *view_->getLabyrinthPtr());
                } else if (event.key.code == sf::Keyboard::Left) {
                    view_->getHumanPtr()->move(-1, 0, *view_->getLabyrinthPtr());
                } else if (event.key.code == sf::Keyboard::Up) {
                    view_->getHumanPtr()->move(0, -1, *view_->getLabyrinthPtr());
                } else if (event.key.code == sf::Keyboard::Down) {
                    view_->getHumanPtr()->move(0, 1, *view_->getLabyrinthPtr());
                }
            }
        }
        resetGameOnExit();
        view_->window().clear(sf::Color::Black);
        view_->render();
    }
}

void GameController::resetGameOnExit() const {
    if (setToFinished() == GameState::RESTART) {
        view_->resetBoard();
        playState = GameState::PLAYING;
    }
}

GameState GameController::setToFinished() const{
    auto human = view_->getHumanPtr();
    auto labyrinth = view_->getLabyrinthPtr()->getLabyrinth();
    if (labyrinth[human->getY()][human->getX()].getState() == CellState::EXIT) {
        playState = GameState::RESTART;
    }

    return playState;
}

void Mode::treeoCalypseMode() {

}

void Mode::welcomeToTheJungleMode() {

}
