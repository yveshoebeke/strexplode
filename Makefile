CXX = gcc
NAME = strexplode_test
LONG_NAME = strexplode_longtest

all: compile compile_longtest run

compile:
	$(CXX) $(NAME).c -o $(NAME)
compile_longtest:
	$(CXX) $(LONG_NAME).c -o $(LONG_NAME)
run:
	./$(NAME)
