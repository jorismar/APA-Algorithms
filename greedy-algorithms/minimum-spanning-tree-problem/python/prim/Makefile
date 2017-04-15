# Compiler Options
PYTHON = python3
SRC_SCRIPT = prim.py
RESULT_FOLDER = soluctions

# Testing Options
TEST_FOLDER = ../../tests

all:
	@-PYTHONPATH=../utils/ $(PYTHON) $(SRC_SCRIPT)

test:
#	@-mkdir -p $(RESULT_FOLDER)
	@-PYTHONPATH=../utils/ $(PYTHON) $(SRC_SCRIPT) < $(TEST_FOLDER)/${INPUT} #>> $(RESULT_FOLDER)/${INPUT}
