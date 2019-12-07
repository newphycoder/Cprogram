CC=gcc

INC_DIR = ./inc
MAIN_DIR = ./main
DATA_DIR = ./data

result: $(MAIN_DIR) 
	$(CC) $(MAIN_DIR)/main.c -o result -I${INC_DIR}

run : result
	./result

.PONEY:clear

clear:
	rm result