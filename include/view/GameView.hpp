#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "model/HumanPlayer.hpp"

class GameView final : public sf::Drawable, public sf::Transformable {
public:

    explicit GameView(const std::shared_ptr<HumanPlayer> &);

    sf::RenderWindow& window() { return window_; }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void init();

    void render();

private:
    std::shared_ptr<HumanPlayer> human_{};
    sf::RenderWindow window_;
};

#endif
