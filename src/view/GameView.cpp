#include "GameView.hpp"

GameView::GameView(const size_t dim) {
    labyrinth_ = std::make_shared<Labyrinth>(dim);
    human_ = std::make_shared<HumanPlayer>();
    init();
}

void GameView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    renderLabyrinth(target);
    renderPlayer(target, *human_);
}

void GameView::renderCell(sf::RenderTarget &target, const Cell &cell) const {
    sf::RectangleShape cellRect(sf::Vector2f(CELLSIZE, CELLSIZE));
    cellRect.setPosition(static_cast<float>(cell.getX()) * CELLSIZE, static_cast<float>(cell.getY()) * CELLSIZE);
    cellRect.setOutlineColor(sf::Color::Black);
    cellRect.setOutlineThickness(THICKNESS);

    switch (cell.getState()) {
        case CellState::TREE:
            cellRect.setFillColor(sf::Color(47, 117, 0));
            break;
        case CellState::BORDER:
            cellRect.setFillColor(sf::Color(92, 73, 40));
            break;
        case CellState::PLANTED:
            cellRect.setFillColor(sf::Color::Magenta);
            break;
        case CellState::EXIT:
            cellRect.setFillColor(sf::Color(136, 156, 54));
            break;
        default:
            cellRect.setFillColor(sf::Color(136, 156, 54));
    }

    target.draw(cellRect);
}

void GameView::renderLabyrinth(sf::RenderTarget &target) const {
    const auto &lab = labyrinth_->getLabyrinth();// Use a reference to avoid unnecessary copies
    for (const auto &row: lab) {
        for (const auto &cell: row) {
            renderCell(target, cell);
        }
    }
}

void GameView::init() {
    labyrinth_->generateViaDFS();
    labyrinth_->setRandomExit();

    size_t dim = labyrinth_->getDim();
    window_.create(sf::VideoMode(static_cast<unsigned int>(CELLSIZE) * (2 * dim + 1),
                                 static_cast<unsigned int>(CELLSIZE) * (2 * dim + 1)),
                   "Labyrinth");
    window_.setFramerateLimit(60);
}

void GameView::render() {
    window_.clear();
    window_.draw(*this);
    window_.display();
}

void GameView::renderPlayer(sf::RenderTarget &target, const HumanPlayer &human) const {
    sf::RectangleShape playerShape(sf::Vector2f(CELLSIZE - THICKNESS, CELLSIZE - THICKNESS));
    playerShape.setOutlineColor(sf::Color::Black);
    playerShape.setOutlineThickness(THICKNESS);
    playerShape.setFillColor(sf::Color(232, 188, 14));
    playerShape.setPosition(human.getX() * CELLSIZE, human.getY() * CELLSIZE);
    target.draw(playerShape);
}

void GameView::resetGame() const {

}
