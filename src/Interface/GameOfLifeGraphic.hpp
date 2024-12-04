#ifndef GAME_OF_LIFE_GRAPHIC_HPP
#define GAME_OF_LIFE_GRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include "GameOfLifeBase.hpp"

class GameOfLifeGraphic : public GameOfLifeBase {
private:
    sf::RenderWindow window;

public:
    GameOfLifeGraphic(const std::string& filename, int cell_size = 10, int max_iter = 3000);

    // Override the base class run method
    void runSimulation() override;

private:
    void renderGrid();
    void handleEvents();
};

#endif // GAME_OF_LIFE_GRAPHIC_HPP
