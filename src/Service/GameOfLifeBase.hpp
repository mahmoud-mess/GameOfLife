#ifndef GAME_OF_LIFE_BASE_HPP
#define GAME_OF_LIFE_BASE_HPP

#include <string>
#include "Grid.hpp"

class GameOfLifeBase {
protected:
    Grid grid;
    int cellSize;
    int maxIterations;
    int currentIteration;

public:
    GameOfLifeBase(const std::string& filename, int cell_size = 10, int max_iter = 3000);
    virtual ~GameOfLifeBase() = default;

    // Pure virtual method to be implemented by derived classes
    virtual void runSimulation() = 0;

    // Common utility methods
    virtual void updateGeneration();
    int getCurrentIteration() const;
    int getMaxIterations() const;
};

#endif // GAME_OF_LIFE_BASE_HPP
