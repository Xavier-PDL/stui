SRC_DIR = src
STUI_DIR = src/stui
BIN_DIR = bin
OBJ_DIR = bin/obj

CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Iinclude

LIBS = -lcurses -lpthread -ldl
DEF=-D_DEBUG

HDR_FILES = $(wildcard include/%.hpp)
SRC_FILES = $(wildcard $(STUI_DIR)/*.cpp)
OBJS = $(patsubst $(STUI_DIR)/%.cpp, $(OBJ_DIR)/%.o,$(SRC_FILES))
MAIN_OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o,$(SRC_DIR)/main.cpp)

all: stui

$(OBJ_DIR)/%.o: $(STUI_DIR)/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(DEF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDR_FILES)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(DEF)

stui: $(OBJS) $(MAIN_OBJ) 
	$(CXX) -o $(BIN_DIR)/$@ $^ $(CXXFLAGS) $(DEF) $(LIBS)


.PHONY: test
test:
	./bin/stui

.PHONY: clean
clean:
	rm -f bin/stui bin/obj/*
