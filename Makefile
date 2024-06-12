CXX = gcc
NAME = strexplode_test

all: compile run

compile:
	$(CXX) $(NAME).c -o $(NAME)
run:
	./$(NAME)
