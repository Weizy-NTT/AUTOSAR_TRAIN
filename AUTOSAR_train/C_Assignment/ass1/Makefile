# Executable file name
TARGET = output/assignment1.exe

# Directories for header files and source files
INCLUDE_DIR = include
SOURCE_DIR = source
BUILD_DIR = build
OUTPUT_DIR = output

# List of source files and corresponding object files
SRCS = $(wildcard $(SOURCE_DIR)/*.c)
OBJS = $(SRCS:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)

# Compiler and compiler flags
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -g

# Default rule
all: $(TARGET)

# Link the executable file
$(TARGET): $(OBJS)
	@mkdir -p $(OUTPUT_DIR)
	@echo "Linking..."
	$(CC) $(OBJS) -o $(TARGET)
	@echo "Build completed successfully."

# Compile each .c file into a .o file
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	@echo "Running program..."
	./$(TARGET)

# Clean up build files
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR) $(OUTPUT_DIR)
	@echo "All built files have been removed."
