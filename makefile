# Makefile of matrixserver project 

CC = g++

OBJ = obj/$(SRC_FILES:.cpp=.o)
SRC_FILES = src/*.cpp
HEADER_FILES = header/*.h

CFLAGS= -c -std==c11
LDFLAGS = -lboost_signals -lwthttp -lwt -std=c++11


EXECUTABLE = matti

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@