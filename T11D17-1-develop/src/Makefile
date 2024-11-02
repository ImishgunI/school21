CC=gcc
BUILD_PATH=../build/
CFLAGS=-Wall -Werror -Wextra -std=c11

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o $(BUILD_PATH)Quest_1
dmanager_module.o: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) -c dmanager_module.c -o $@


list_test: list.o list_tests.o 
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_2

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c -o $@

list_tests.o: list_test.c
	$(CC) $(CFLAGS) -c list_test.c -o $@

clean:
	rm *.o
	rm $(BUILD_PATH)Quest_*

clang-format:
	clang-format -i *.c
	clang-format -i *.h

rebuild: clean