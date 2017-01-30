CC = gcc
BIN_FOLDER = ./bin
INCLUDE_FOLDER = ./include
SRC_FOLDER = ./src
BIN = main
TEST_FOLDER = ./tests
TEST_FILE = test01.in

all:
	@-mkdir -p bin	
	@-$(CC) $(SRC_FOLDER)/*.c -o $(BIN_FOLDER)/$(BIN) -I $(INCLUDE_FOLDER) -std=c99

run:
	@$(BIN_FOLDER)/main

test:
	@$(BIN_FOLDER)/main < $(TEST_FOLDER)/$(TEST_FILE)

clean:
	@-rm -r $(BIN_FOLDER)

