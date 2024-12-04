#include <iostream>
#include "GameOfLifeConsole.hpp"
#include "GameOfLifeGraphic.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] 
                  << " <input_file> <mode> [output_dir]" << std::endl;
        std::cerr << "Modes: console, graphic" << std::endl;
        return 1;
    }

    try {
        std::string inputFile = argv[1];
        std::string mode = argv[2];

        if (mode == "console") {
            std::string outputDir = (argc > 3) ? 
                argv[3] : inputFile + "_out";
            GameOfLifeConsole game(inputFile, outputDir);
            game.runSimulation();
        } 
        else if (mode == "graphic") {
            GameOfLifeGraphic game(inputFile);
            game.runSimulation();
        } 
        else {
            throw std::runtime_error(
                "Invalid mode. Use 'console' or 'graphic'.");
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}