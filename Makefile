CC=gcc

BUILD_DIR = ./build
INC_DIR = ./inc
LOW_DIR = ./low
MAIN_DIR = ./main
DATA_DIR = ./data

OBJ = $(BUILD_DIR)/*.o

.PONEY: clean clear

result: $(OBJ) 
	$(CC) $(OBJ) -o $(BUILD_DIR)/result -L$(DATA_DIR) -I${INC_DIR}


$(BUILD_DIR)/main.o: $(MAIN_DIR)/main.c 
	$(CC) $(CCFLAGS) $(MAIN_DIR)/main.c -I${INC_DIR} -o $(BUILD_DIR)/main.o 

$(BUILD_DIR)/*.o:$(INC_DIR)/*.h

all:main

clean:
	rm -rf *.o $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)/test*