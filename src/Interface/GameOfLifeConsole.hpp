#ifndef GAME_OF_LIFE_CONSOLE_HPP
#define GAME_OF_LIFE_CONSOLE_HPP

#include "GameOfLifeBase.hpp"
#include <string>

class GameOfLifeConsole : public GameOfLifeBase {
private:
    std::string outputDirectory;

public:
    GameOfLifeConsole(const std::string& filename, const std::string& output_dir, 
                      int cell_size = 10, int max_iter = 3000);

    // Override the base class run method
    void runSimulation() override;

private:
    void saveIterationToFile(int iteration);
    void printIterationToConsole(int iteration);
};

#endif // GAME_OF_LIFE_CONSOLE_HPP
