#include <iostream>
#include "GameController.hpp"

GameController::GameController() : playState{GameState::INGAME} {
    size_t boardSize;
    std::cout << "Enter the size of the board -> ";
    std::cin >> boardSize;
    std::cout << "Your board size is " << boardSize << std::endl << std::endl;
    std::cout
            << "Please choose game mode...\n 1) Press T for `TreeoCalypse`\n 2) Press W for `Welcome to the Jungle`\n";
    setMode();

    view_ = std::make_shared<GameView>(boardSize);
}

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

        if (keyCode == sf::Keyboard::Right) human->move(1, 0, *labyrinth, gameMode);
        else if (keyCode == sf::Keyboard::Left) human->move(-1, 0, *labyrinth, gameMode);
        else if (keyCode == sf::Keyboard::Up) human->move(0, -1, *labyrinth, gameMode);
        else if (keyCode == sf::Keyboard::Down) human->move(0, 1, *labyrinth, gameMode);
    }
}

void GameController::resetGame(){
    if (view_->getLabyrinthPtr()->getMoves() == 0) {
        std::cout << "YOU LOST, YOU HAVE DONE TOO MANY MOVES...\n";
        playState = GameState::RESTART;
    }

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

void GameController::setMode() {
    char mode;
    std::cin >> mode;

    if (mode == 'T') {
        std::cout << "RUN RUN RUN !!!!!" << std::endl;
        gameMode = GameMode::TREEOCALYPSE;
    }

    if (mode == 'W') {
        std::cout << "CUT OR DIE !!!!!" << std::endl;
        gameMode = GameMode::WELCOME_TO_THE_JUNGLE;
    }
}
