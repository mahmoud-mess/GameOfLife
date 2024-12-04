#include "Grid.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

Grid::Grid(int w, int h) : width(w), height(h) {
    cells.resize(width, std::vector<Cell>(height));
}

Grid::Grid(const Grid& other) 
    : width(other.width), height(other.height), cells(other.cells) {}

Grid& Grid::operator=(const Grid& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        cells = other.cells;
    }
    return *this;
}

int Grid::countLiveNeighbors(int x, int y) const {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            
            // Toroidal wraparound calculation
            int nx = (x + dx + width) % width;
            int ny = (y + dy + height) % height;
            
            if (cells[nx][ny].isAlive()) {
                ++count;
            }
        }
    }
    return count;
}

Grid Grid::fromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    int width, height;
    file >> width >> height;

    Grid grid(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int state;
            file >> state;
            grid.cells[x][y].setAlive(state == 1);
        }
    }
    return grid;
}

bool Grid::validateGridState(std::function<bool(const Grid&)> testCondition) const {
    return testCondition(*this);
}

void Grid::nextGeneration() {
    std::vector<std::vector<Cell>> nextGen = cells;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int liveNeighbors = countLiveNeighbors(x, y);
            
            if (!cells[x][y].isAlive()) {
                // Dead cell with exactly 3 live neighbors becomes alive
                if (liveNeighbors == 3) {
                    nextGen[x][y].setAlive(true);
                }
            } else {
                // Live cell with 2 or 3 live neighbors survives
                // Otherwise, it dies
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    nextGen[x][y].setAlive(false);
                }
            }
        }
    }

    cells = nextGen;
}

int Grid::getWidth() const { 
    return width; 
}

int Grid::getHeight() const { 
    return height; 
}

bool Grid::getCellState(int x, int y) const { 
    return cells[x][y].isAlive(); 
}

int Grid::countLiveCells() const {
    int count = 0;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (cells[x][y].isAlive()) {
                ++count;
            }
        }
    }
    return count;
}

bool Grid::operator==(const Grid& other) const {
    if (width != other.width || height != other.height) {
        return false;
    }

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (cells[x][y].isAlive() != other.cells[x][y].isAlive()) {
                return false;
            }
        }
    }
    return true;
}
