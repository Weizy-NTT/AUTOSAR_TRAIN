# Compiler
CC = gcc

# Directories
BUILD_DIR = build
OUTPUT_DIR = output
INCLUDE_DIR = Include
SRC_DIR = Source

# Files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/readfile.c $(SRC_DIR)/valid.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
EXE = $(OUTPUT_DIR)/program

# Flags
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra
LDFLAGS =

# Default target
all: $(EXE)

# Create build and output directories if not exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Rule to build the executable
$(EXE): $(BUILD_DIR) $(OUTPUT_DIR) $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Rule to compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(EXE)
	$(EXE)

# Clean up build and output directories
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)

# Phony targets
.PHONY: all clean run
