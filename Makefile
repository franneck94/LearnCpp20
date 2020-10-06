COMPILATION_MODE ?= Debug
ENABLE_WARNINGS ?= 1
WARNINGS_AS_ERRORS ?= 0
CPP_STANDARD ?= c++17

ifeq ($(OS), Windows_NT)
RM = rm -f # cygwin
#RM = del /Q /F # standard windows commands
else
RM = rm -f
endif

ifeq ($(COMPILATION_MODE), Debug)
CPP_COMPILER_FLAGS = -g -O0 -std=$(CPP_STANDARD)
EXECUTABLE_NAME = mainDebug
else
CPP_COMPILER_FLAGS = -O3 -std=$(CPP_STANDARD)
EXECUTABLE_NAME = mainRelease
endif

ifeq ($(ENABLE_WARNINGS), 1)
CPP_COMPILER_FLAGS += -Wall -Wextra -Wpedantic -Wconversion
endif

ifeq ($(WARNINGS_AS_ERRORS), 1)
CPP_COMPILER_FLAGS += -Werror
endif

CPP_COMPILER = g++
CPP_COMPILER_CALL = $(CPP_COMPILER) $(CPP_COMPILER_FLAGS)

INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build

CPP_SRCS = $(wildcard $(SOURCE_DIR)/*.cc)
CPP_OBJECTS = $(filter %.o, $(patsubst $(SOURCE_DIR)/%.cc, $(BUILD_DIR)/%.o, $(CPP_SRCS)))

build: $(BUILD_DIR)/$(EXECUTABLE_NAME)

$(BUILD_DIR)/$(EXECUTABLE_NAME): $(CPP_OBJECTS)
	$(CPP_COMPILER_CALL) $^ -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cc
	$(CPP_COMPILER_CALL) -I $(INCLUDE_DIR) -c $< -o $@

execute:
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)

clean:
	cd $(BUILD_DIR) && $(RM) *.o
