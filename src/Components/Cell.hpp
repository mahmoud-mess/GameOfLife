#ifndef CELL_HPP
#define CELL_HPP

class Cell {
private:
    bool alive;

public:
    Cell(bool initial_state = false);

    bool isAlive() const;
    void setAlive(bool state);

    // Explicit copy constructor and assignment operator
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
};

#endif // CELL_HPP
