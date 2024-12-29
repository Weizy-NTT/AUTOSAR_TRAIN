# Compiler and flags
CC = gcc
CFLAGS = -IEX2/Include -Wall -g

# Directories for Ex2
SOURCE_DIR = EX2/Source
BUILD_DIR = EX2/build
OUTPUT_DIR = EX2/output

# Targets for Ex1
EX1_SRC = EX1/ex1.c
EX1_EXEC = EX1/ex1.exe

# Targets for Ex2
EX2_SRCS = $(wildcard $(SOURCE_DIR)/*.c)
EX2_OBJS = $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(EX2_SRCS))
EX2_EXEC = $(OUTPUT_DIR)/main_program.exe

# Default rule (build both programs without running)
all: $(EX1_EXEC) $(EX2_EXEC)

# Rule to build and run Ex1
ex1: $(EX1_EXEC)
	@echo "Running Ex1..."
	./$(EX1_EXEC)

$(EX1_EXEC): $(EX1_SRC)
	$(CC) $(CFLAGS) $< -o $@

# Rule to build and run Ex2
ex2: $(EX2_EXEC)
	@echo "Running Ex2..."
	./$(EX2_EXEC)

$(EX2_EXEC): $(EX2_OBJS)
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $(EX2_OBJS) -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR) $(OUTPUT_DIR) $(EX1_EXEC)
