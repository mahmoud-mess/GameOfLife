# Game of Life Simulation

## Overview

Conway's Game of Life is a cellular automaton simulation crafted as a deep dive into modern C++ object-oriented programming (OOP) principles. This project serves as a practical exploration of advanced C++ concepts.
By implementing the Game of Life, the project demonstrates key OOP paradigms:

- **Inheritance**: Creating flexible, extensible class hierarchies.
  
- **Encapsulation**: Protecting data integrity through controlled access.

- **Polymorphism**: Designing adaptable interfaces for different simulation modes.

The simulation is built using an HMI (Human-Machine Interface) architecture, as shown in the diagram below. This layered design promotes separation of concerns, flexibility, and extensibility.

- The **Components Layer** contains the core game logic, including the `Cell` and `Grid` classes.
- The **Service Layer** provides the `GameOfLifeBase` class, which serves as the connection between the components and the higher-level interfaces.
- The **Interface Layer** includes the `GameOfLifeConsole` and `GameOfLifeGraphic` classes, which implement the console-based and graphical user interfaces, respectively.

## Rules

1. **Underpopulation**: A live cell with fewer than two live neighbors dies.
2. **Overpopulation**: A live cell with more than three live neighbors dies.
3. **Reproduction**: A dead cell with exactly three live neighbors becomes alive.
4. **Survival**: A live cell with two or three live neighbors remains alive.

## Features

- Toroidal grid with wraparound edges
- Console-based and graphical simulation modes
- Custom initial pattern configurations
- Comprehensive unit testing

## Prerequisites

- C++17 or later
- SFML (Simple and Fast Multimedia Library)
- Google Test (GTest)

## Dependencies

On Debian-based systems, install dependencies:

```bash
sudo apt-get install libsfml-dev libgtest-dev
```

## Build and Run Instructions

### Clone the Repository

```bash
git clone https://github.com/mahmoud-mess/GameOfLife.git
cd GameOfLife
```

### Compilation

Build the project using the Makefile:

```bash
make
```

### Running the Simulation

Usage:
```bash
./game_of_life <input_file> <mode> [output_dir]
```

Parameters:
- `<input_file>`: Path to the initial grid configuration file
- `<mode>`: Simulation display mode
  - `console`: Text-based grid display
  - `graphic`: Graphical window simulation
- `[output_dir]`: Optional. Directory to save output files

### Input File Format

The input file should contain the initial configuration of the grid. The format is as follows:

1. **First Line**: Specifies the grid size as two integers separated by a space: `<rows> <columns>` (e.g., `40 60` for a 40x60 grid).
2. **Subsequent Lines**: Represent the grid's initial cell states, where:
   - `0` indicates a dead cell.
   - `1` indicates a live cell.
3. **Unspeciified States**: Setting the grid size to values larger than the provided number of rows and columns sets the unspecified cells to a dead state by default. Alternatively, settign the grid size to values smaller than provided ignores the additional rows and columns.
  - Example :
 ```
4 4
0 0 0 0
0 0 0 0
0 1 1 0
0 1 1 0
```

### Running Unit Tests

```bash
make test
./test_game_of_life
```
#### Test Coverage
Unit tests validate critical aspects of the simulation:
- Toroidal grid wrap-around functionality
  - Verify edge cells correctly count neighbors across grid boundaries
  - Ensure wrap-around logic maintains consistent cell neighborhood rules
- Grid iteration verification
  - Compare generated grid states against pre-computed expected iterations
  - Validate that cellular evolution follows Game of Life rules precisely
