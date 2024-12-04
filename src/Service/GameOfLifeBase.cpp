#include "GameOfLifeBase.hpp"

GameOfLifeBase::GameOfLifeBase(const std::string& filename, int cell_size, int max_iter)
    : grid(Grid::fromFile(filename)), 
      cellSize(cell_size), 
      maxIterations(max_iter), 
      currentIteration(0) {}

void GameOfLifeBase::updateGeneration() {
    grid.nextGeneration();
    currentIteration++;
}

int GameOfLifeBase::getCurrentIteration() const {
    return currentIteration;
}

int GameOfLifeBase::getMaxIterations() const {
    return maxIterations;
}
