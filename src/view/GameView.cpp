#include "GameView.hpp"

GameView::GameView(const size_t rooms) {
    labyrinth_ = std::make_shared<Labyrinth>(rooms);
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

    switch (cell.getState()) {
        case CellState::TREE:
            cellRect.setFillColor(sf::Color(COLOR_EBONY));
            break;
        case CellState::BORDER:
            cellRect.setFillColor(sf::Color(COLOR_DARK_CHARCOAL));
            break;
        case CellState::PLANTED:
            cellRect.setFillColor(sf::Color(COLOR_OLIVE_DRAB));
            break;
        case CellState::EXIT:
            cellRect.setFillColor(sf::Color(COLOR_MOSS_GREEN));
            break;
        case CellState::TAIL:
            cellRect.setFillColor(sf::Color::Red);
            break;
        default:
            cellRect.setFillColor(sf::Color(COLOR_MOSS_GREEN));
    }

    target.draw(cellRect);
}

void GameView::renderPlayer(sf::RenderTarget &target, const HumanPlayer &human) const {
    sf::RectangleShape playerShape(sf::Vector2f(CELLSIZE - THICKNESS, CELLSIZE - THICKNESS));
    playerShape.setOutlineColor(sf::Color::Black);
    playerShape.setOutlineThickness(THICKNESS);
    playerShape.setFillColor(sf::Color(255, 156, 54));
    playerShape.setPosition(human.getX() * CELLSIZE, human.getY() * CELLSIZE);
    target.draw(playerShape);
}

void GameView::renderLabyrinth(sf::RenderTarget &target) const {
    const auto &lab = labyrinth_->getLabyrinth();
    for (const auto &row: lab) {
        for (const auto &cell: row) {
            renderCell(target, cell);
        }
    }
}

void GameView::init() {
    defaultGenerationLogicHandler();
    size_t matrixSize = labyrinth_->getMatrixSize();
    window_.create(sf::VideoMode((CELLSIZE) * (matrixSize),
                                 (CELLSIZE) * (matrixSize)),
                   "Labyrinth");
    window_.setFramerateLimit(60);
}

void GameView::render() {
    window_.clear();
    window_.draw(*this);
    window_.display();
}

void GameView::defaultGenerationLogicHandler() {
    labyrinth_->generateViaDFS();
    labyrinth_->setRandomExit();
}

void GameView::resetBoard() {
    labyrinth_->setBoardToDefaults();
    human_->initPlayerPos();
    defaultGenerationLogicHandler();
    render();
}
