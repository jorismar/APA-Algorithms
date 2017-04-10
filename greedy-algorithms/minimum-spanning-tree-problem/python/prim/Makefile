# Compiler Options
PYTHON = python3
SRC_SCRIPT = prim.py

# Testing Options
TEST_FOLDER = ../../tests

all:
	@-PYTHONPATH=../utils/ $(PYTHON) $(SRC_SCRIPT)

test:
	@-PYTHONPATH=../utils/ $(PYTHON) $(SRC_SCRIPT) < $(TEST_FOLDER)/${INPUT}
