# Directories
PROJ_DIR := $(realpath $(CURDIR)/..)
INCLUDE := -I$(PROJ_DIR)/include 
INCLUDES := $(INCLUDE) $(sdl_include_path)
SRC_DIR := $(PROJ_DIR)src
BUILD_DIR := $(PROJ_DIR)build


# If SDL2 is in different location than this you need to change it
sdl_include_path = -IC:/dev/libraries/SDL2-VSCODE/x64
sdl_lib_path = -LC:/dev/libraries/SDL2-VSCODE/lib/x64

link_libraries = -lSDL2main -lSDL2 -lSDL2_image


# Output
EXEC = ./launcher


# Files 
FILES = $(wildcard $(SRC_DIR)/main.cpp) $(SRC_DIR)/game/*.*)


# Build Settings
CC = g++


# Execution
all: build

build:
	$(CC) $(INCLUDES) $(sdl_lib_path) -o $(EXEC) $(FILES) $(link_libraries)

run: build
	$(BUILD_DIR)/$(EXEC)

clean:
	del $(EXEC)

