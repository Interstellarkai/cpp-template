.PHONY: all deps build test run clean help
.DEFAULT_GOAL := help

define BROWSER_PYSCRIPT
import os, webbrowser, sys

try:
	from urllib import pathname2url
except:
	from urllib.request import pathname2url

webbrowser.open("file://" + pathname2url(os.path.abspath(sys.argv[1])))
endef
export BROWSER_PYSCRIPT

define PRINT_HELP_PYSCRIPT
import re, sys

for line in sys.stdin:
	match = re.match(r'^([a-zA-Z_-]+):.*?## (.*)$$', line)
	if match:
		target, help = match.groups()
		print("%-20s %s" % (target, help))
endef
export PRINT_HELP_PYSCRIPT

BROWSER := python -c "$$BROWSER_PYSCRIPT"
INSTALL_LOCATION := ~/.local

help:
	@python -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

test: ## run tests quickly with ctest
	rm -rf build/
	cmake -Bbuild -DCMAKE_INSTALL_PREFIX=$(INSTALL_LOCATION) -Dmodern-cpp-template_ENABLE_UNIT_TESTING=1 -DCMAKE_BUILD_TYPE="Release"
	cmake --build build --config Release
	cd build/ && ctest -C Release -VV

coverage: ## check code coverage quickly GCC
	rm -rf build/
	cmake -Bbuild -DCMAKE_INSTALL_PREFIX=$(INSTALL_LOCATION) -Dmodern-cpp-template_ENABLE_CODE_COVERAGE=1
	cmake --build build --config Release
	cd build/ && ctest -C Release -VV
	cd .. && (bash -c "find . -type f -name '*.gcno' -exec gcov -pb {} +" || true)

docs: ## generate Doxygen HTML documentation, including API docs
	rm -rf docs/
	rm -rf build/
	cmake -Bbuild -DCMAKE_INSTALL_PREFIX=$(INSTALL_LOCATION) -DProject_ENABLE_DOXYGEN=1
	cmake --build build --config Release
	cmake --build build --target doxygen-docs
	$(BROWSER) docs/html/index.html

install: ## install the package to the `INSTALL_LOCATION`
	rm -rf build/
	cmake -Bbuild -DCMAKE_INSTALL_PREFIX=$(INSTALL_LOCATION)
	cmake --build build --config Release
	cmake --build build --target install --config Release

format: ## format the project sources
	rm -rf build/
	cmake -Bbuild -DCMAKE_INSTALL_PREFIX=$(INSTALL_LOCATION)
	cmake --build build --target clang-format

# Advent of Code specific targets
.PHONY: build-advent test-advent run-day clean-advent deps

# Build configuration
WARNINGS ?= off

# Convert warnings option to CMake flag
ifeq ($(WARNINGS),on)
    WARNINGS_FLAG := -DCMAKE_CXX_FLAGS="-Wall -Wextra -Wpedantic"
else
    WARNINGS_FLAG := -DCMAKE_CXX_FLAGS="-w"
endif

# Default target that builds everything
all: build

# Install dependencies only if build directory doesn't exist
deps:
	@if [ ! -d "build" ]; then \
		echo "First time setup: Creating build directory and configuring CMake..."; \
		mkdir -p build; \
		cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug $(WARNINGS_FLAG); \
	else \
		echo "Build directory exists, skipping CMake configuration..."; \
	fi

# Build the project
build: deps
	@echo "Building project..."
	@cmake --build build -- -j$(shell sysctl -n hw.ncpu)

# Run all tests
test: build
	@echo "Running tests..."
	@if [ -d build ]; then \
		cd build && ctest -C Debug -V || echo "No tests found or tests failed."; \
	else \
		echo "Build directory not found. Please run make build first."; \
	fi

# Run a specific day's solution
run-day: build
	@if [ -z "$(day)" ]; then \
		echo "Usage: make run-day day=2015_day01"; \
		exit 1; \
	fi
	@echo "Running $(day)..."
	@if [ ! -f "./build/bin/Debug/$(day)" ]; then \
		echo "Error: Executable ./build/bin/Debug/$(day) not found"; \
		echo "Available executables:"; \
		ls -1 ./build/bin/Debug/ | grep -E '^[0-9]{4}_day[0-9]{2}$$'; \
		exit 1; \
	fi
	@if [ ! -f "./src/advent_of_code/$(word 1,$(subst _, ,$(day)))/$(word 2,$(subst _, ,$(day)))/input.txt" ]; then \
		echo "Warning: Input file not found at ./src/advent_of_code/$(word 1,$(subst _, ,$(day)))/$(word 2,$(subst _, ,$(day)))/input.txt"; \
		echo "Please create the input file before running the solution."; \
		exit 1; \
	fi
	@cd ./src/advent_of_code/$(word 1,$(subst _, ,$(day)))/$(word 2,$(subst _, ,$(day))) && \
	../../../../build/bin/Debug/$(day)

# Clean everything
clean:
	@echo "Cleaning build..."
	@rm -rf build

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build everything (dependencies + project)"
	@echo "  deps         - Install/update dependencies (only if build directory doesn't exist)"
	@echo "  build        - Build the project"
	@echo "  test         - Run all tests"
	@echo "  run-day      - Run a specific day's solution (e.g., make run-day day=2015_day01)"
	@echo "  clean        - Clean build directory"
	@echo ""
	@echo "Build options:"
	@echo "  WARNINGS     - Enable/disable compiler warnings (default: off)"
	@echo "                 Usage: make build WARNINGS=on"
	@echo "                 or:    make test WARNINGS=on"
	@echo ""
	@echo "Examples:"
	@echo "  make build              # Build with warnings disabled (default)"
	@echo "  make build WARNINGS=on  # Build with warnings enabled"
	@echo "  make test WARNINGS=on   # Run tests with warnings enabled"
	@echo "  make run-day day=2015_day01 # Run day 1 of 2015"
	@echo ""
	@echo "Note: Input files must be placed at src/advent_of_code/YYYY/dayXX/input.txt"
