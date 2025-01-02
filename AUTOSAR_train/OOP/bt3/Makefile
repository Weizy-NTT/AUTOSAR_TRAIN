# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR = source
OUT_DIR = output

# Output executable
TARGET = $(OUT_DIR)/main

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Default rule
all:
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean rule
clean:
	rm -rf $(OUT_DIR)

# Phony targets
.PHONY: all clean