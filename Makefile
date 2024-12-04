# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -I$(SRC_DIR)/Components -I$(SRC_DIR)/Service -I$(SRC_DIR)/Interface -I/usr/include/gtest -I/usr/include/gmock
LDFLAGS = -lgtest -lgtest_main -lpthread
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR = src
BUILD_DIR = build
COMPONENTS_DIR = $(SRC_DIR)/Components
SERVICE_DIR = $(SRC_DIR)/Service
INTERFACE_DIR = $(SRC_DIR)/Interface
TEST_DIR = test

# Source and object files
SRCS = $(wildcard $(COMPONENTS_DIR)/*.cpp) \
       $(wildcard $(SERVICE_DIR)/*.cpp) \
       $(wildcard $(INTERFACE_DIR)/*.cpp) \
       $(SRC_DIR)/main.cpp
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Test files
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Test object files without main.cpp
TEST_OBJS_EXCLUDE_MAIN = $(filter-out $(BUILD_DIR)/src/main.o, $(OBJS))

# Executables
TARGET = game_of_life
TEST_TARGET = test_game_of_life

# Rules
all: directories $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Rule for building object files
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test target
test: directories $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS_EXCLUDE_MAIN) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(SFML_LIBS)

# Create necessary directories
directories:
	@mkdir -p $(BUILD_DIR)/src/Components
	@mkdir -p $(BUILD_DIR)/src/Service
	@mkdir -p $(BUILD_DIR)/src/Interface
	@mkdir -p $(BUILD_DIR)/test

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

.PHONY: all clean directories test
