CXX         ?= g++
CFLAGS     ?= 

BIN_PATH   ?= bin
BUILD_PATH ?= .build
PREFIX     ?= /usr/local

prefix_bin = $(PREFIX)/bin

source_path = src

includes=include

sources=$(wildcard $(source_path)/**/*.cpp) $(wildcard src/*.cpp)
objects=$(patsubst $(source_path)/%.cpp,$(BUILD_PATH)/%.o,$(sources))

CFLAGS += -I $(includes)

all: $(BIN_PATH)/17
.PHONY: all


install: all
	mkdir -p $(prefix_bin)
	cp bin/* $(prefix_bin)/
.PHONY: install


$(BIN_PATH)/17: $(objects)
	mkdir -p $(@D)
	$(CXX) -o $(@) $(^)


$(BUILD_PATH)/%.o: $(source_path)/%.cpp
	mkdir -p $(@D)
	$(CXX) -fPIC -c -o $@ $(CFLAGS) $(^)


clean:
	rm -rf $(BIN_PATH)
	rm -rf $(BUILD_PATH)
.PHONY: clean
