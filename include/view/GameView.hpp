#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "HumanPlayer.hpp"
#include "Cell.hpp"
#include "Labyrinth.hpp"

namespace {
    constexpr float CELLSIZE = 20.0f;
    constexpr float THICKNESS = 1.0f;

    const sf::Color COLOR_MOSS_GREEN(112, 128, 105); //path
    const sf::Color COLOR_DARK_CHARCOAL(28, 28, 28); //border
    const sf::Color COLOR_OLIVE_DRAB(107, 142, 35); //planting
    const sf::Color COLOR_GOLD_FUSION(103, 95, 77); //player
    const sf::Color COLOR_EBONY(33, 36, 33); //tree
}

class GameView final : public sf::Drawable {
public:
    explicit GameView(size_t labSize);

    sf::RenderWindow &window() { return window_; }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void renderCell(sf::RenderTarget &target, const Cell &cell) const;

    void renderPlayer(sf::RenderTarget &target, const HumanPlayer &human) const;

    void renderLabyrinth(sf::RenderTarget &target) const;

    void init();

    void render();

    void defaultGenerationLogicHandler();

    void resetBoard();

    const std::shared_ptr<HumanPlayer> &getHumanPtr() const {
        return human_;
    }

    const std::shared_ptr<Labyrinth> &getLabyrinthPtr() const {
        return labyrinth_;
    }

private:
    std::shared_ptr<Labyrinth> labyrinth_{};
    std::shared_ptr<HumanPlayer> human_{};
    sf::RenderWindow window_;
};

#endif
