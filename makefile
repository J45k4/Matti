# Makefile of matrixserver project 

CC = g++

OBJ = obj/$(FILES:.cpp=.o)
#FILES = main setapi

HEADER_DIR = header/
SRC_DIR = src/
OBJ_DIR = obj/

HEADER_FILES = $(HEADER_DIR)*.h
SOURCE_FILES = $(SRC_DIR)*.cpp
OBJ_FILES = $(OBJ_DIR)*.o

CFLAGS= -c -std=c++11 -Iheader/
LDFLAGS = -lboost_signals -lwthttp -lwt -std=c++11


EXECUTABLE = matti

all: $(EXECUTABLE)

$(OBJ_DIR)matrixconn.o: $(SRC_DIR)matrixconn.cpp $(HEADER_DIR)matrixconn.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)setapi.o: $(SRC_DIR)setapi.cpp $(HEADER_DIR)setapi.h $(OBJ_DIR)matrixconn.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp $(HEADER_DIR)main.h $(OBJ_DIR)setapi.o
	$(CC) -c -o $@ $< $(CFLAGS)

	
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o executable/$(EXECUTABLE)
    
debug: $(EXECUTABLE) run
    
run:
	./$(EXECUTABLE) --docroot ./ --http-address 0.0.0.0 --http-port 80
	
.PHONY: clean
	

