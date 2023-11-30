CC = g++
CFLAGS = -g -lSDL2 -lm -lpthread -Isrc -Wall -Wextra -Wpedantic -Wno-unused-variable
SRC_DIR = src
OBJ_DIR = .
TARGET = main

# List of source files
SRCS = $(SRC_DIR)/light.cpp $(SRC_DIR)/pixel_buffer.cpp $(SRC_DIR)/ray.cpp $(SRC_DIR)/renderer.cpp $(SRC_DIR)/scene.cpp $(SRC_DIR)/sdl_manager.cpp $(SRC_DIR)/sphere.cpp $(SRC_DIR)/vector3D.cpp main.cpp

# Rule for making the final target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

.PHONY: clean

# Rule for cleaning the project
clean:
	rm -f $(TARGET)