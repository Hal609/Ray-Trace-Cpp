CC = g++-13
CFLAGS = -g -fopenmp -std=c++17 -I/usr/local/include -Isrc -Wall -Wextra -Wpedantic -Wno-unused-variable
LDFLAGS = -L/usr/local/lib -lSDL2 -lm -lpthread
SRC_DIR = src
OBJ_DIR = .
TARGET = main

# List of source files
SRCS = $(SRC_DIR)/light.cpp $(SRC_DIR)/pixel_buffer.cpp $(SRC_DIR)/ray.cpp $(SRC_DIR)/renderer.cpp $(SRC_DIR)/sdl_manager.cpp $(SRC_DIR)/sphere.cpp $(SRC_DIR)/vector3.cpp $(SRC_DIR)/color.cpp main.cpp

# Rule for making the final target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

.PHONY: clean

# Rule for cleaning the project
clean:
	rm -f $(TARGET)