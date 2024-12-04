#include "GameOfLifeConsole.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

GameOfLifeConsole::GameOfLifeConsole(const std::string& filename, 
                                     const std::string& output_dir, 
                                     int cell_size, 
                                     int max_iter)
    : GameOfLifeBase(filename, cell_size, max_iter), 
      outputDirectory(output_dir) {
    std::filesystem::create_directory(outputDirectory);
}

void GameOfLifeConsole::runSimulation() {
    while (currentIteration < maxIterations) {
        printIterationToConsole(currentIteration);
        saveIterationToFile(currentIteration);
        
        updateGeneration();
    }
    std::cout << "Simulation complete. Results saved in directory: " 
              << outputDirectory << std::endl;
}

void GameOfLifeConsole::saveIterationToFile(int iteration) {
    std::string outFile = outputDirectory + "/iteration_" + 
                          std::to_string(iteration) + ".txt";
    std::ofstream file(outFile);
    
    file << grid.getWidth() << " " << grid.getHeight() << std::endl;
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            bool cellState = grid.getCellState(x, y);
            file << (cellState ? 1 : 0) << " ";
        }
        file << std::endl;
    }
    file.close();
}

void GameOfLifeConsole::printIterationToConsole(int iteration) {
    std::cout << "Iteration " << iteration + 1 << "/" 
              << maxIterations << ":" << std::endl;
    
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            bool cellState = grid.getCellState(x, y);
            std::cout << (cellState ? "1" : "0");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}