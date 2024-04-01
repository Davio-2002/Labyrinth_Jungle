#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "HumanPlayer.hpp"
#include "Cell.hpp"
#include "Labyrinth.hpp"

namespace {
    constexpr float CELLSIZE = 12.0f;
    constexpr float THICKNESS = 1.0f;
}

class GameView final : public sf::Drawable, public sf::Transformable {
public:
    explicit GameView(size_t dim);

    sf::RenderWindow &window() { return window_; }

    // TODO -> remove this in the end, this is just a test method to ensure something is being drawn
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    // TODO -> add Node (Cell) list as an argument
    void renderCell(sf::RenderTarget &target, const Cell &cell) const;

    void renderLabyrinth(sf::RenderTarget &target) const;

    // TODO -> adjust step by step animation
    void animateGeneration();

    void init();

    void render();

private:

    std::shared_ptr<Labyrinth> labyrinth_{};
    std::shared_ptr<HumanPlayer> human_{};
    sf::RenderWindow window_;
};

#endif
