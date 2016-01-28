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

$(OBJ_DIR)setapi.o: $(SRC_DIR)setapi.cpp $(HEADER_DIR)setapi.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp $(HEADER_DIR)main.h $(OBJ_DIR)setapi.o
	$(CC) -c -o $@ $< $(CFLAGS)


#$(OBJ_FILES): $(SOURCE_FILES) $(HEADER_FILES) 
#	$(CC) $(CFLAGS) $< -o $(*F)
	
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o executable/$(EXECUTABLE)
	
.PHONY: clean
	
#%.o: %.c $(HEADER_FILES)
#	$(CC) -c -o $@ $< $(CFLAGS)

#$(EXECUTABLE): $(OBJ_FILES)
#	$(CC) $(LDFLAGS) $^ -o executable/$(EXECUTABLE)
	
#clean:
#	rm obj/*.o


#.cpp.o:
#	$(CC) $(CFLAGS) $< -o $@
