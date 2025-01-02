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

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile .cpp to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(OUT_DIR)

# Run rule
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run