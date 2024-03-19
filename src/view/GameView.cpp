#include "view/GameView.hpp"

GameView::GameView(const std::shared_ptr<HumanPlayer> &player) {
    human_ = player;
    init();
}

// #TODO -> Refactor function for labbyrinth business logic
void GameView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    const auto color = sf::Color(200, 100, 200);

    sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    target.draw(shape, states);
}

void GameView::init() {
    setPosition(50.f, 50.f);
    window_.create(sf::VideoMode(800, 600), "Welcome to the Jungle");
    window_.setFramerateLimit(60);

}

void GameView::render() {
    window_.clear();
    window_.draw(*this);
    window_.display();
}
