# Makefile of matrixserver project 

CC = g++

CFLAGS = -Iheader/ -Iheader/proto/ -lpthread -lwebsockets -std=c++11
LDFLAGS = -lpthread -lwebsockets -lprotobuf

OBJ = obj/$(FILES:.cpp=.o)
#FILES = main setapi

HEADER_DIR = header/
SRC_DIR = src/
OBJ_DIR = obj/

HEADER_FILES = $(HEADER_DIR)*.h
SOURCE_FILES = $(SRC_DIR)*.cpp
OBJ_FILES = $(OBJ_DIR)*.o


#CFLAGS= -c -std=c++11 -Iheader/ -lwebsockets
#LDFLAGS = -lboost_signals -lwthttp -lwt -std=c++11


EXECUTABLE = matti

all: $(EXECUTABLE)	

$(OBJ_DIR)MattiRequest.pb.o: $(SRC_DIR)proto/MattiRequest.pb.cc $(HEADER_DIR)proto/MattiResponse.pb.h $(OBJ_DIR)VideoConnection.pb.o $(OBJ_DIR)KwmConnection.pb.o \
$(OBJ_DIR)MatrixProto.pb.o $(OBJ_DIR)Timer.pb.o $(OBJ_DIR)Program.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)MattiResponse.pb.o: $(SRC_DIR)proto/MattiResponse.pb.cc $(HEADER_DIR)proto/MattiResponse.pb.h $(OBJ_DIR)VideoConnection.pb.o $(OBJ_DIR)VideoConnections.pb.o \
$(OBJ_DIR)KwmConnection.pb.o $(OBJ_DIR)KwmConnections.pb.o $(OBJ_DIR)MatrixProto.pb.o $(OBJ_DIR)Matrixs.pb.o $(OBJ_DIR)Program.pb.o $(OBJ_DIR)Programs.pb.o \
$(OBJ_DIR)Timer.pb.o $(OBJ_DIR)Timers.pb.o $(OBJ_DIR)AllConnections.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)AllConnections.pb.o: $(SRC_DIR)proto/AllConnections.pb.cc $(HEADER_DIR)proto/AllConnections.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)VideoConnection.pb.o: $(SRC_DIR)proto/VideoConnection.pb.cc $(HEADER_DIR)proto/VideoConnection.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)VideoConnections.pb.o: $(SRC_DIR)proto/VideoConnections.pb.cc $(HEADER_DIR)proto/VideoConnections.pb.h $(OBJ_DIR)VideoConnection.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)KwmConnection.pb.o: $(SRC_DIR)proto/KwmConnection.pb.cc $(HEADER_DIR)proto/KwmConnection.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)KwmConnections.pb.o: $(SRC_DIR)proto/KwmConnections.pb.cc $(HEADER_DIR)proto/KwmConnections.pb.h $(OBJ_DIR)KwmConnection.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)MatrixProto.pb.o: $(SRC_DIR)proto/Matrix.pb.cc $(HEADER_DIR)proto/Matrix.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)Matrixs.pb.o: $(SRC_DIR)proto/Matrixs.pb.cc $(HEADER_DIR)proto/Matrixs.pb.h $(OBJ_DIR)MatrixProto.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)Program.pb.o: $(SRC_DIR)proto/Program.pb.cc $(HEADER_DIR)proto/Program.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)Programs.pb.o: $(SRC_DIR)proto/Programs.pb.cc $(HEADER_DIR)proto/Programs.pb.h $(OBJ_DIR)Program.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)Timer.pb.o: $(SRC_DIR)proto/Timer.pb.cc $(HEADER_DIR)proto/Timer.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)Timers.pb.o: $(SRC_DIR)proto/Timers.pb.cc $(HEADER_DIR)proto/Timers.pb.h $(OBJ_DIR)Timer.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)matrix.o: $(SRC_DIR)matrix.cpp $(HEADER_DIR)matrix.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)client.o: $(SRC_DIR)client.cpp $(HEADER_DIR)client.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)matti.o: $(SRC_DIR)matti.cpp $(HEADER_DIR)matti.h $(OBJ_DIR)MattiRequest.pb.o $(OBJ_DIR)MattiResponse.pb.o \
$(OBJ_DIR)matrix.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp $(HEADER_DIR)main.h $(OBJ_DIR)client.o $(OBJ_DIR)matrix.o $(OBJ_DIR)matti.o
	$(CC) -c -o $@ $< $(CFLAGS)

	
$(EXECUTABLE): $(OBJ_DIR)main.o
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o executable/$(EXECUTABLE)
    
run:
	./executable/$(EXECUTABLE)
    
debug: $(EXECUTABLE) run

clean:
	rm $(OBJ_DIR)*.o
    

	
.PHONY: clean
	

#./executable/$(EXECUTABLE) --docroot ./ --http-address 0.0.0.0 --http-port 8080  
