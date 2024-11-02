CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
BUILD_PATH=../build/

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $@

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o $@

s21_string_test.o: s21_string_test.c s21_string_test.h
	$(CC) $(CFLAGS) -c s21_string_test.c -o $@


strlen_tests: main.o s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_1

strcmp_tests: main.o s21_string.o s21_string_test.o
	$(CC) $(CFLAGS)  $^ -o $(BUILD_PATH)Quest_2

strcpy_tests: main.o s21_string.o s21_string_test.o
	$(CC) $(CFLAGS)  $^ -o $(BUILD_PATH)Quest_3

strcat_tests: main.o s21_string.o s21_string_test.o
	$(CC) $(CFLAGS)  $^ -o $(BUILD_PATH)Quest_4

strchr_tests: main.o s21_string.o s21_string_test.o
	$(CC) $(CFLAGS)  $^ -o $(BUILD_PATH)Quest_5

strstr_tests: main.o s21_string.o s21_string_test.o
	$(CC) $(CFLAGS)  $^ -o $(BUILD_PATH)Quest_6

text_processor: text_processor.c s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) -c text_processor.c -o ../build/Quest_8

clang-format:
	clang-format -i *.c
	clang-format -i *.h

clean:
	rm -rf *.o
	rm ../build/Quest_*

rebuild: clean all
