 
#include <gtest/gtest.h>
#include "src/Components/Grid.hpp"

class GameOfLifeTest : public ::testing::Test {
protected:
    // Sample test grids
    Grid createGliderGrid() {
        Grid grid(6, 6);
        // Glider pattern
        grid.getCells()[1][2].setAlive(true);
        grid.getCells()[2][3].setAlive(true);
        grid.getCells()[3][1].setAlive(true);
        grid.getCells()[3][2].setAlive(true);
        grid.getCells()[3][3].setAlive(true);
        return grid;
    }
};

// Test Cases
TEST_F(GameOfLifeTest, TestLiveCellCounting) {
    Grid grid = createGliderGrid();
    
    // Validate initial live cell count
    EXPECT_EQ(grid.countLiveCells(), 5);
}

TEST_F(GameOfLifeTest, TestToroidalNeighborWrapAround) {
    Grid grid(5, 5);
    
    // Set cells at grid edges
    grid.getCells()[0][0].setAlive(true);  // Top-left corner
    grid.getCells()[4][4].setAlive(true);  // Bottom-right corner
    
    // Custom test condition to validate neighborhood
    auto neighborTest = [](const Grid& g) {
        // Count live neighbors for cells at edges
        // This test assumes the grid is toroidal (wraps around)
        int neighborsTopLeft = 0;
        int neighborsBottomRight = 0;
        
        // Simulate neighbor counting for (0,0)
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                
                int nx = (0 + dx + 5) % 5;
                int ny = (0 + dy + 5) % 5;
                
                if (g.getCellState(nx, ny)) {
                    neighborsTopLeft++;
                }
            }
        }
        
        // Verify that the diagonal corner is counted as a neighbor
        return neighborsTopLeft == 1;
    };
    
    EXPECT_TRUE(grid.validateGridState(neighborTest));
}

TEST_F(GameOfLifeTest, TestNextGenerationGlider) {
    Grid grid = createGliderGrid();
    Grid expectedNextGen(6, 6);
    
    // Set up expected next generation for glider
    expectedNextGen.getCells()[2][1].setAlive(true);
    expectedNextGen.getCells()[3][2].setAlive(true);
    expectedNextGen.getCells()[3][3].setAlive(true);
    expectedNextGen.getCells()[2][3].setAlive(true);
    expectedNextGen.getCells()[4][2].setAlive(true);
    
    grid.nextGeneration();
    
    EXPECT_TRUE(grid == expectedNextGen);
}

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
