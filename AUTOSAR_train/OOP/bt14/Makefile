# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -O2

# Folders
SRC_DIR = source
INC_DIR = include
BUILD_DIR = Build
OUTPUT_DIR = output

# Target executable
TARGET = $(OUTPUT_DIR)/recruitment_system

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	@mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run the program
run: $(TARGET)
	@./$(TARGET)

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)

# Rebuild the project
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild run
