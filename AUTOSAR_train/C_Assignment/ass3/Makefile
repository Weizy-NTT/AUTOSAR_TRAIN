# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
EX1_DIR = ex1
EX2_DIR = ex2
BUILD_EX1_DIR = $(EX1_DIR)/build
BUILD_EX2_DIR = $(EX2_DIR)/build
OUTPUT_EX1_DIR = $(EX1_DIR)/output
OUTPUT_EX2_DIR = $(EX2_DIR)/output
INCLUDE_EX1_DIR = $(EX1_DIR)/Include
INCLUDE_EX2_DIR = $(EX2_DIR)/Include
SOURCE_EX1_DIR = $(EX1_DIR)/Source
SOURCE_EX2_DIR = $(EX2_DIR)/Source

# Files for ex1
EX1_SRCS = $(SOURCE_EX1_DIR)/main.c $(SOURCE_EX1_DIR)/source.c $(SOURCE_EX1_DIR)/Userhandling.c
EX1_OBJS = $(BUILD_EX1_DIR)/main.o $(BUILD_EX1_DIR)/source.o $(BUILD_EX1_DIR)/Userhandling.o
EX1_TARGET = $(OUTPUT_EX1_DIR)/ex1_program

# Files for ex2
EX2_SRCS = $(SOURCE_EX2_DIR)/main.c $(SOURCE_EX2_DIR)/source.c $(SOURCE_EX2_DIR)/Userhandling.c
EX2_OBJS = $(BUILD_EX2_DIR)/main.o $(BUILD_EX2_DIR)/source.o $(BUILD_EX2_DIR)/Userhandling.o
EX2_TARGET = $(OUTPUT_EX2_DIR)/ex2_program

# Default rule to build both ex1 and ex2
all: $(EX1_TARGET) $(EX2_TARGET)

# Rule to build and run ex1
ex1: $(EX1_TARGET)
	@echo "Running ex1..."
	./$(EX1_TARGET)

$(EX1_TARGET): $(EX1_OBJS)
	@mkdir -p $(OUTPUT_EX1_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_EX1_DIR) $^ -o $@

$(BUILD_EX1_DIR)/%.o: $(SOURCE_EX1_DIR)/%.c
	@mkdir -p $(BUILD_EX1_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_EX1_DIR) -c $< -o $@

# Rule to build and run ex2
ex2: $(EX2_TARGET)
	@echo "Running ex2..."
	./$(EX2_TARGET)

$(EX2_TARGET): $(EX2_OBJS)
	@mkdir -p $(OUTPUT_EX2_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_EX2_DIR) $^ -o $@

$(BUILD_EX2_DIR)/%.o: $(SOURCE_EX2_DIR)/%.c
	@mkdir -p $(BUILD_EX2_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_EX2_DIR) -c $< -o $@

# Clean rule to remove all built files
clean:
	rm -rf $(BUILD_EX1_DIR) $(OUTPUT_EX1_DIR) $(BUILD_EX2_DIR) $(OUTPUT_EX2_DIR)
