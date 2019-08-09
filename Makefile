# 
# Makefile for tilemap
# 

CPP := g++

CPPFLAGS := -std=c++11 -Wall -Wno-unused-variable -Wno-uninitialized
INCLUDES := -I include/ -I .
OPTIONS  := -lpng -O2

BUILD_DIR  := build/
SOURCE_DIR := src/
SOURCES    := $(wildcard $(SOURCE_DIR)*.cpp)

OBJS := $(SOURCES:.cpp=.o)

TARGET = tilemap

.PHONY: clean

all:    dir $(TARGET)
		@echo  Build success!

dir:
		mkdir -p $(BUILD_DIR)src

$(TARGET): $(OBJS)
		$(CPP) $(CPPFLAGS) $(INCLUDES) -o $(TARGET) $(addprefix $(BUILD_DIR), $(OBJS)) $(OPTIONS)

.cpp.o:
		$(CPP) $(CPPFLAGS) $(INCLUDES) -c $<  -o $(BUILD_DIR)$@

clean:
		$(RM) $(BUILD_DIR)src/*.o *~ $(TARGET)
		$(RM) -r build
