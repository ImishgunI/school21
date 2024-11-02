CC=gcc
BUILD_PATH=../build/
CFLAGS=-Wall -Werror -Wextra -std=c11

print_module: main_module_entry_point.o print_m.o documentation_module.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_1

main_module_entry_point.o: main_module_entry_point.c
	$(CC) $(CFLAGS) -c main_module_entry_point.c -o $@

print_m.o: print_module.c print_module.h
	$(CC) $(CFLAGS) -c print_module.c -o $@


documentation_module: main_module_entry_point.o documentation_module.o print_m.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_2

documentation_module.o: documentation_module.c documentation_module.h
	$(CC) $(CFLAGS) -c documentation_module.c -o $@


bst_create_test: bst.o test1.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_3

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c -o $@

test1.o: bst_create_test.c
	$(CC) $(CFLAGS) -c bst_create_test.c -o $@

bst_insert_test: bst.o test2.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_4

test2.o: bst_insert_test.c
	$(CC) $(CFLAGS) -c bst_insert_test.c -o $@


bst_traverse_test: bst.o test3.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_5

test3.o: bst_traverse_test.c
	$(CC) $(CFLAGS) -c bst_traverse_test.c -o $@

clean:
	rm *.o
	rm $(BUILD_PATH)Quest_*

clang-format:
	clang-format -i *.c
	clang-format -i *.h
