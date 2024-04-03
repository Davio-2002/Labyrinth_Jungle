#include "GameController.hpp"

GameController::GameController() : view_{std::make_shared<GameView>(20)}, playState{GameState::INGAME} {}

void GameController::handleEvents() {
    sf::Event event;
    while (view_->window().isOpen()) {
        while (view_->window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                view_->window().close();
            }

            if (event.type == sf::Event::KeyPressed) {
                handleKeyPress(event.key.code);
            }
        }
        resetGame();
        view_->window().clear(sf::Color::Black);
        view_->render();
    }
}

void GameController::handleKeyPress(sf::Keyboard::Key &keyCode) {
    if (keyCode == sf::Keyboard::Escape) {
        view_->window().close();
    } else {
        const auto human = view_->getHumanPtr();
        const auto labyrinth = view_->getLabyrinthPtr();

        if (keyCode == sf::Keyboard::Right) human->move(1, 0, *labyrinth);
        else if (keyCode == sf::Keyboard::Left) human->move(-1, 0, *labyrinth);
        else if (keyCode == sf::Keyboard::Up) human->move(0, -1, *labyrinth);
        else if (keyCode == sf::Keyboard::Down) human->move(0, 1, *labyrinth);
    }
}

void GameController::resetGame() const {
    if (setToFinished() == GameState::RESTART) {
        view_->resetBoard();
        playState = GameState::INGAME;
    }
}

GameState GameController::setToFinished() const {
    auto human = view_->getHumanPtr();
    auto labyrinth = view_->getLabyrinthPtr();
    if (labyrinth->isExitReached(*human)) {
        playState = GameState::RESTART;
    }
    return playState;
}

void Mode::treeoCalypseMode() {

}

void Mode::welcomeToTheJungleMode() {

}
