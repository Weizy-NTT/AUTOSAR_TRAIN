# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -IUser_handling 

# Directories
BUILD_DIR = build
OUTPUT_DIR = output
EX1_DIR = exercise1
EX2_DIR = exercise2
EX3_DIR = exercise3
USER_HANDLING_DIR = User_handling
EX2_INCLUDE_DIR = $(EX2_DIR)/include
EX2_SOURCE_DIR = $(EX2_DIR)/source

# Sources and Objects
USER_HANDLING_SRCS = $(USER_HANDLING_DIR)/Userhandling.c
USER_HANDLING_OBJS = $(BUILD_DIR)/Userhandling.o

EX1_SRCS = $(EX1_DIR)/exercise1.c
EX1_OBJS = $(BUILD_DIR)/exercise1.o

EX2_SRCS = $(EX2_SOURCE_DIR)/exercise2.c $(EX2_SOURCE_DIR)/Allocate.c
EX2_OBJS = $(BUILD_DIR)/exercise2.o $(BUILD_DIR)/Allocate.o

EX3_SRCS = $(EX3_DIR)/exercise3.c
EX3_OBJS = $(BUILD_DIR)/exercise3.o

# Targets
EX1_TARGET = $(OUTPUT_DIR)/exercise1
EX2_TARGET = $(OUTPUT_DIR)/exercise2
EX3_TARGET = $(OUTPUT_DIR)/exercise3

# Default target
all: $(EX1_TARGET) $(EX2_TARGET) $(EX3_TARGET)

# Build and run exercise1
ex1: $(EX1_TARGET)
	@echo "Running exercise1..."
	./$(EX1_TARGET)

$(EX1_TARGET): $(EX1_OBJS) $(USER_HANDLING_OBJS)
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/exercise1.o: $(EX1_SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/Userhandling.o: $(USER_HANDLING_SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build and run exercise2
ex2: $(EX2_TARGET)
	@echo "Running exercise2..."
	./$(EX2_TARGET)

$(EX2_TARGET): $(EX2_OBJS)
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -I$(EX2_INCLUDE_DIR) $^ -o $@

$(BUILD_DIR)/exercise2.o: $(EX2_SOURCE_DIR)/exercise2.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(EX2_INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/Allocate.o: $(EX2_SOURCE_DIR)/Allocate.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(EX2_INCLUDE_DIR) -c $< -o $@

# Build and run exercise3
ex3: $(EX3_TARGET)
	@echo "Running exercise3..."
	./$(EX3_TARGET)

$(EX3_TARGET): $(EX3_OBJS) $(USER_HANDLING_OBJS)
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/exercise3.o: $(EX3_SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)
