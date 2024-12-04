#include "GameOfLifeGraphic.hpp"

GameOfLifeGraphic::GameOfLifeGraphic(const std::string& filename, 
                                     int cell_size, 
                                     int max_iter)
    : GameOfLifeBase(filename, cell_size, max_iter),
      window(sf::VideoMode(grid.getWidth() * cell_size, 
                           grid.getHeight() * cell_size), 
             "Game of Life") {}

void GameOfLifeGraphic::runSimulation() {
    while (window.isOpen() && currentIteration < maxIterations) {
        handleEvents();
        renderGrid();
        
        updateGeneration();
        sf::sleep(sf::milliseconds(100));
    }
}

void GameOfLifeGraphic::renderGrid() {
    window.clear(sf::Color::Black);
    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1, cellSize - 1));
    cellShape.setFillColor(sf::Color::White);
    
    for (int x = 0; x < grid.getWidth(); ++x) {
        for (int y = 0; y < grid.getHeight(); ++y) {
            if (grid.getCellState(x, y)) {
                cellShape.setPosition(x * cellSize, y * cellSize);
                window.draw(cellShape);
            }
        }
    }
    window.display();
}

void GameOfLifeGraphic::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}