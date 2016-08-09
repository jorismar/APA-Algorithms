CC = gcc
BIN_FOLDER = ./bin
INCLUDE_FOLDER = ./include
SRC_FOLDER = ./src
EXEC1 = selection
EXEC2 = insertion
EXEC3 = merge
EXEC4 = quick
EXEC5 = heap
UTILS = list

all:
	@-mkdir -p bin	
	@-$(CC) $(SRC_FOLDER)/$(EXEC1).c $(SRC_FOLDER)/$(UTILS).c -o $(BIN_FOLDER)/$(EXEC1) -I $(INCLUDE_FOLDER) -std=c99
	@-$(CC) $(SRC_FOLDER)/$(EXEC2).c $(SRC_FOLDER)/$(UTILS).c -o $(BIN_FOLDER)/$(EXEC2) -I $(INCLUDE_FOLDER) -std=c99
	@-$(CC) $(SRC_FOLDER)/$(EXEC3).c $(SRC_FOLDER)/$(UTILS).c -o $(BIN_FOLDER)/$(EXEC3) -I $(INCLUDE_FOLDER) -std=c99
	@-$(CC) $(SRC_FOLDER)/$(EXEC4).c $(SRC_FOLDER)/$(UTILS).c -o $(BIN_FOLDER)/$(EXEC4) -I $(INCLUDE_FOLDER) -std=c99
	@-$(CC) $(SRC_FOLDER)/$(EXEC5).c $(SRC_FOLDER)/$(UTILS).c -o $(BIN_FOLDER)/$(EXEC5) -I $(INCLUDE_FOLDER) -std=c99

clean:
	@-rm -r ./bin

