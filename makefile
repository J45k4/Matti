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

$(OBJ_DIR)matrixconnection.o: $(SRC_DIR)matrixconnection.cpp $(HEADER_DIR)matrixconnection.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)setapi.o: $(SRC_DIR)setapi.cpp $(HEADER_DIR)setapi.h $(OBJ_DIR)matrixconnection.o
	$(CC) -c -o $@ $< $(CFLAGS)
    
$(OBJ_DIR)help.o: $(SRC_DIR)help.cpp $(HEADER_DIR)help.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp $(HEADER_DIR)main.h $(OBJ_DIR)setapi.o $(OBJ_DIR)help.o
	$(CC) -c -o $@ $< $(CFLAGS)

	
$(EXECUTABLE): $(OBJ_DIR)main.o
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o executable/$(EXECUTABLE)
    
run:
	./executable/$(EXECUTABLE) --docroot ./ --http-address 0.0.0.0 --http-port 8080   
    
debug: $(EXECUTABLE) run

clean:
	rm $(OBJ_DIR)*.o
    

	
.PHONY: clean
	

