#include "Cell.hpp"

Cell::Cell(bool initial_state) : alive(initial_state) {}

bool Cell::isAlive() const { 
    return alive; 
}

void Cell::setAlive(bool state) { 
    alive = state; 
}

Cell::Cell(const Cell& other) : alive(other.alive) {}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        alive = other.alive;
    }
    return *this;
}
