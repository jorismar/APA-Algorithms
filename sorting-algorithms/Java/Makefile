# Compiler Options
CC = javac
BIN_FILE = Main
BIN_FOLDER = ./build
SRC_FOLDER = ./src
PACKAGE_FOLDER = Sorting

# Testing Options (Trabalho: Ordenação 01)
TEST_FOLDER = ../Tests
RESULT_FOLDER = ./results
TEST_MSG_OK = "--> Teste OK!"
TEST_MSG_FAIL = "--> Teste FAIL!"

# Benchmark Options (Trabalho: Ordenação 02)
INSTANCES_FOLDER = ../../../instancias
BENCHMARK_FOLDER = ./benchmark

all:
	@-mkdir -p $(BIN_FOLDER)
	@-$(CC) -d $(BIN_FOLDER) $(SRC_FOLDER)/*.java $(SRC_FOLDER)/$(PACKAGE_FOLDER)/*.java

run:
	@-java -cp $(BIN_FOLDER) $(BIN_FILE) ${ARGS}

test:
	@-mkdir -p $(RESULT_FOLDER)
	@-rm -f $(RESULT_FOLDER)/*.res

	@-java -cp $(BIN_FOLDER) $(BIN_FILE) ${ARGS} < $(TEST_FOLDER)/${TEST}.in >> $(RESULT_FOLDER)/${TEST}.res
	@-(diff -q $(TEST_FOLDER)/${TEST}.out $(RESULT_FOLDER)/${TEST}.res && echo $(TEST_MSG_OK)) || (echo $(TEST_MSG_FAIL)) && echo

test-all:
	@-mkdir -p $(RESULT_FOLDER)
	@-rm -f $(RESULT_FOLDER)/*.res

	@##################### Selection Sort Test #####################

	@-java -cp $(BIN_FOLDER) $(BIN_FILE) -s < $(TEST_FOLDER)/${TEST}.in >> $(RESULT_FOLDER)/selection_${TEST}.res
	@-echo "Selection Sort" && ((diff -q $(TEST_FOLDER)/${TEST}.out $(RESULT_FOLDER)/selection_${TEST}.res && echo $(TEST_MSG_OK)) || (echo $(TEST_MSG_FAIL)) && echo)

	@##################### Insertion Sort Test #####################

	@-java -cp $(BIN_FOLDER) $(BIN_FILE) -i < $(TEST_FOLDER)/${TEST}.in >> $(RESULT_FOLDER)/insertion_${TEST}.res
	@-echo "Insertion Sort" && ((diff -q $(TEST_FOLDER)/${TEST}.out $(RESULT_FOLDER)/insertion_${TEST}.res && echo $(TEST_MSG_OK)) || (echo $(TEST_MSG_FAIL)) && echo)

	@##################### Merge Sort Test #####################

	@-java -cp $(BIN_FOLDER) $(BIN_FILE) -m < $(TEST_FOLDER)/${TEST}.in >> $(RESULT_FOLDER)/merge_${TEST}.res
	@-echo "Merge Sort"  && ((diff -q $(TEST_FOLDER)/${TEST}.out $(RESULT_FOLDER)/merge_${TEST}.res && echo $(TEST_MSG_OK)) || (echo $(TEST_MSG_FAIL)) && echo)

	@##################### Quick Sort Test #####################

	@-java -cp $(BIN_FOLDER) $(BIN_FILE) -q < $(TEST_FOLDER)/${TEST}.in >> $(RESULT_FOLDER)/quick_${TEST}.res
	@-echo "Quick Sort"  && ((diff -q $(TEST_FOLDER)/${TEST}.out $(RESULT_FOLDER)/quick_${TEST}.res && echo $(TEST_MSG_OK)) || (echo $(TEST_MSG_FAIL)) && echo)

	@##################### Heap Sort Test #####################

	@-java -cp $(BIN_FOLDER) $(BIN_FILE) -h < $(TEST_FOLDER)/${TEST}.in >> $(RESULT_FOLDER)/heap_${TEST}.res
	@-echo "Heap Sort"  && ((diff -q $(TEST_FOLDER)/${TEST}.out $(RESULT_FOLDER)/heap_${TEST}.res && echo $(TEST_MSG_OK)) || (echo $(TEST_MSG_FAIL)) && echo)

	@##################### Default Sort Test #####################

	@-java -cp $(BIN_FOLDER) $(BIN_FILE) -d < $(TEST_FOLDER)/${TEST}.in >> $(RESULT_FOLDER)/default_${TEST}.res
	@-echo "Default Sort"  && ((diff -q $(TEST_FOLDER)/${TEST}.out $(RESULT_FOLDER)/default_${TEST}.res && echo $(TEST_MSG_OK)) || (echo $(TEST_MSG_FAIL)) && echo)

run-instances:
	@-mkdir -p $(BENCHMARK_FOLDER)
	@-rm -f $(BENCHMARK_FOLDER)/*.*

	@-for entropy in 10 50 90 ; do \
		for instance in 100000 500000 1000000 ; do \
			for number in 1 2 3 4 5 6 7 8 9 10 ; do \
				java -cp $(BIN_FOLDER) $(BIN_FILE) -s -b < $(INSTANCES_FOLDER)/$$entropy.$$instance.$$number.in >> $(BENCHMARK_FOLDER)/$$entropy.$$instance.selection.csv ; \
				java -cp $(BIN_FOLDER) $(BIN_FILE) -i -b < $(INSTANCES_FOLDER)/$$entropy.$$instance.$$number.in >> $(BENCHMARK_FOLDER)/$$entropy.$$instance.insertion.csv ; \
				java -cp $(BIN_FOLDER) $(BIN_FILE) -m -b < $(INSTANCES_FOLDER)/$$entropy.$$instance.$$number.in >> $(BENCHMARK_FOLDER)/$$entropy.$$instance.merge.csv ; \
				java -cp $(BIN_FOLDER) $(BIN_FILE) -q -b < $(INSTANCES_FOLDER)/$$entropy.$$instance.$$number.in >> $(BENCHMARK_FOLDER)/$$entropy.$$instance.quick.csv ; \
				java -cp $(BIN_FOLDER) $(BIN_FILE) -h -b < $(INSTANCES_FOLDER)/$$entropy.$$instance.$$number.in >> $(BENCHMARK_FOLDER)/$$entropy.$$instance.heap.csv ; \
				java -cp $(BIN_FOLDER) $(BIN_FILE) -d -b < $(INSTANCES_FOLDER)/$$entropy.$$instance.$$number.in >> $(BENCHMARK_FOLDER)/$$entropy.$$instance.default.csv ; \
			done \
		done \
	done

clean:
	@-rm -r -f $(BIN_FOLDER)
	@-rm -r -f $(BENCHMARK_FOLDER)
	@-rm -r -f $(RESULT_FOLDER)
