CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
BUILD_PATH_FOR_TEST = ./module_test/


test: stack.o test.o lexer.o evaluate.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH_FOR_TEST)$@ -lm

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c -o $@

test.o: ./module_test/test.c
	$(CC) $(CFLAGS) -c $^ -o $@

lexer.o: lexer.c
	$(CC) $(CFLAGS) -c lexer.c -o $@

evaluate.o: evaluator.c
	$(CC) $(CFLAGS) -c evaluator.c -o $@

clean: 
	rm *.o

clang-format:
	clang-format -i *.c
	clang-format -i *.h