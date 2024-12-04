#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <string>
#include <functional>
#include "Cell.hpp"

class Grid {
private:
    std::vector<std::vector<Cell>> cells;
    int width;
    int height;

    int countLiveNeighbors(int x, int y) const;

public:
    Grid(int w, int h);
    
    // Copy constructor and assignment operator
    Grid(const Grid& other);
    Grid& operator=(const Grid& other);

    // File input method
    static Grid fromFile(const std::string& filename);

    // Grid state validation
    bool validateGridState(std::function<bool(const Grid&)> testCondition) const;

    // Advance to next generation
    void nextGeneration();

    // Getters and utility methods
    int getWidth() const;
    int getHeight() const;
    bool getCellState(int x, int y) const;
    int countLiveCells() const;

    // Comparison operator
    bool operator==(const Grid& other) const;

    // Direct cell access for test setup
    std::vector<std::vector<Cell>>& getCells() { return cells; }
    const std::vector<std::vector<Cell>>& getCells() const { return cells; }
};

#endif // GRID_HPP
