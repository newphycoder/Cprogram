CC=gcc

INC_DIR = ./inc
MAIN_DIR = ./main
DATA_DIR = ./data

result: $(MAIN_DIR) 
	$(CC) -g $(MAIN_DIR)/main.c -o result -I${INC_DIR}

.PONEY:clear

clear:
	rm result