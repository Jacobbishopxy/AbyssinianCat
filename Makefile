# author:	Jacob Xie
# date:	2025/07/08 15:16:19 Tuesday
# brief:


include .env

PROJECT_VERSION := $(PROJ_VER)

include .env

PROJECT_VERSION := $(PROJ_VER)
INSTALL_PREFIX = /opt/AbyssinianCat-$(PROJECT_VERSION)

# Define the source and build directories
SOURCE_DIR = .
BUILD_DIR = build

# Compiler and tools
CMAKE = cmake
MAKE = make

# Targets

.PHONY: all configure build install clean test

# Default target: configure, build and install
all: configure build install

# Configure the project
configure:
	@echo "Configuring the project..."
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && $(CMAKE) $(SOURCE_DIR)

# Build the project
build:
	@echo "Building the project..."
	@cd $(BUILD_DIR) && $(MAKE)

# Install the project
install:
	@echo "Installing the project to $(INSTALL_PREFIX)..."
	@cd $(BUILD_DIR) && sudo $(MAKE) install

test:
	@echo "Building test directory... only works if `make install` executed"
	@sudo $(CMAKE) -B build -DBUILD_TESTS=ON .
	@sudo $(CMAKE) --build build

# Clean the build directory
clean:
	@echo "Cleaning the build directory..."
	@sudo rm -rf $(BUILD_DIR)

