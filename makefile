# Makefile of matrixserver project 

CC = g++

CFLAGS = -Iheader/ -lpthread -lwebsockets -std=c++11
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

$(OBJ_DIR)mattiapi.o: $(SRC_DIR)mattiapi.cpp $(HEADER_DIR)mattiapi.h $(OBJ_DIR)ValueMessage.pb.o $(OBJ_DIR)RequestValue.pb.o $(OBJ_DIR)MattiResponse.pb.o \
 $(OBJ_DIR)MattiRequest.pb.o $(OBJ_DIR)MakeConnectionRequest.pb.o $(OBJ_DIR)ValueMessage.pb.o
	$(CC) -c -o $@ $< $(CFLAGS)
	
	

$(OBJ_DIR)ValueMessage.pb.o: $(SRC_DIR)ValueMessage.pb.cc $(HEADER_DIR)ValueMessage.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)		

$(OBJ_DIR)RequestValue.pb.o: $(SRC_DIR)RequestValue.pb.cc $(HEADER_DIR)RequestValue.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)	
	
$(OBJ_DIR)MattiResponse.pb.o: $(SRC_DIR)MattiResponse.pb.cc $(HEADER_DIR)MattiResponse.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)	
	
$(OBJ_DIR)MattiRequest.pb.o: $(SRC_DIR)MattiRequest.pb.cc $(HEADER_DIR)MattiRequest.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)	
	
$(OBJ_DIR)MakeConnectionRequest.pb.o: $(SRC_DIR)MakeConnectionRequest.pb.cc $(HEADER_DIR)MakeConnectionRequest.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)	
	
$(OBJ_DIR)ValueMessage.pb.o: $(SRC_DIR)ValueMessage.pb.cc $(HEADER_DIR)ValueMessage.pb.h
	$(CC) -c -o $@ $< $(CFLAGS)	

	

$(OBJ_DIR)matrixconnection.o: $(SRC_DIR)matrixconnection.cpp $(HEADER_DIR)matrixconnection.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)setapi.o: $(SRC_DIR)setapi.cpp $(HEADER_DIR)setapi.h $(OBJ_DIR)matrixconnection.o
	$(CC) -c -o $@ $< $(CFLAGS)
    
$(OBJ_DIR)help.o: $(SRC_DIR)help.cpp $(HEADER_DIR)help.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJ_DIR)matrix.o: $(SRC_DIR)matrix.cpp $(HEADER_DIR)matrix.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)client.o: $(SRC_DIR)client.cpp $(HEADER_DIR)client.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp $(HEADER_DIR)main.h $(OBJ_DIR)MattiRequest.pb.o $(OBJ_DIR)client.o $(OBJ_DIR)matrix.o
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
