# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR = source
BUILD_DIR = build
OUT_DIR = output

# Output executable
TARGET = $(OUT_DIR)/main

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default rule: Build everything
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile .cpp files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean build and output directories
clean:
	rm -rf $(BUILD_DIR) $(OUT_DIR)

# Rule to run the program
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run
