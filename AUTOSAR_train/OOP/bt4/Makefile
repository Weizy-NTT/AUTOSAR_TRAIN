# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR = Source
INC_DIR = Include
BUILD_DIR = build
OUTPUT_DIR = output

# Output executable
TARGET = $(OUTPUT_DIR)/main

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	@mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)

# Phony targets
.PHONY: all clean run
