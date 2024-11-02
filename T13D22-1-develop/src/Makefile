CC = gcc
BUILD_PATH = ../build/
CFLAGS = -Wall -Werror -Wextra -std=c11 

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.o -o $(BUILD_PATH)cipher

cipher.o: cipher.c cipher.h
	$(CC) $(CFLAGS) -c cipher.c -o $@


logger_cipher: cipher.o logger.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)$@

logger.o: logger.c 
	$(CC) $(CFLAGS) -c logger.c -o $@

clean:
	rm *.o
	rm $(BUILD_PATH)cipher
	rm $(BUILD_PATH)logger_cipher

clang-format:
	clang-format -i *.c
	clang-format -i *.h