COMPILATION_MODE ?= Debug
ENABLE_WARNINGS ?= 1
WARNINGS_AS_ERRORS ?= 0
CPP_COMPILER ?= g++ # g++, clang++
CPP_STANDARD ?= c++2a # c++11, c++14, c++17, c++2a
EXECUTABLE_NAME ?= main

ifeq ($(OS), Windows_NT)
RM = rm -f # RM = del /Q /F # if cygwin is not installed
else
RM = rm -f
endif

ifeq ($(COMPILATION_MODE), Debug)
CPP_COMPILER_FLAGS = -g -std=$(CPP_STANDARD) # -fopenmp
else ifeq ($(COMPILATION_MODE), Release)
CPP_COMPILER_FLAGS = -O3 -std=$(CPP_STANDARD) # -fopenmp
endif

ifeq ($(ENABLE_WARNINGS), 1)
CPP_COMPILER_FLAGS += -Wall -Wextra -Wpedantic
endif

ifeq ($(WARNINGS_AS_ERRORS), 1)
CPP_COMPILER_FLAGS += -Werror
endif

CPP_COMPILER_CALL = $(CPP_COMPILER) $(CPP_COMPILER_FLAGS)

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build
TEST_DIR = test

CPP_SRCS = $(wildcard $(SOURCE_DIR)/*.cc)
CPP_OBJECTS = $(filter %.o, $(patsubst $(SOURCE_DIR)/%.cc, $(BUILD_DIR)/%.o, $(CPP_SRCS)))

build: $(BUILD_DIR)/$(EXECUTABLE_NAME)

$(BUILD_DIR)/$(EXECUTABLE_NAME): $(CPP_OBJECTS)
	$(CPP_COMPILER_CALL) $^ -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cc
	$(CPP_COMPILER_CALL) -I $(INCLUDE_DIR) -c $< -o $@

testPair:
	$(CPP_COMPILER_CALL) -I $(INCLUDE_DIR) $(TEST_DIR)/test_pair.cc -o testPairMain

execute:
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)

clean:
	cd $(BUILD_DIR) && $(RM) *.o
