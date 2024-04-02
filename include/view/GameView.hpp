#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "HumanPlayer.hpp"
#include "Cell.hpp"
#include "Labyrinth.hpp"

namespace {
    constexpr float CELLSIZE = 10.0f;
    constexpr float THICKNESS = 1.0f;
}

class GameView final : public sf::Drawable, public sf::Transformable {
public:
    explicit GameView(size_t dim);

    sf::RenderWindow &window() { return window_; }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void renderCell(sf::RenderTarget &target, const Cell &cell) const;

    void renderPlayer(sf::RenderTarget &target, const HumanPlayer &human) const;

    void renderLabyrinth(sf::RenderTarget &target) const;

    void resetGame() const;

    void init();

    void render();

    const std::shared_ptr<HumanPlayer>& getHuman() const {
        return human_;
    }

    const std::shared_ptr<Labyrinth>& getLabyrinth() const {
        return labyrinth_;
    }

private:
    std::shared_ptr<Labyrinth> labyrinth_{};
    std::shared_ptr<HumanPlayer> human_{};
    sf::RenderWindow window_;
};

#endif
