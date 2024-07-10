CXX = gcc
TEST = strexplode_test
LONG_TEST = strexplode_longtest
OBJ = strexplode.c

all: compile compile_long run

compile:
	@$(CXX) -g0 -o $(TEST) $(TEST).c $(OBJ)

compile_long:
	@$(CXX) -g0 -o $(LONG_TEST) $(LONG_TEST).c $(OBJ)

run:
	./$(TEST)

