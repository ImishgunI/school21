CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
BUILD_PATH=../../build/
LDFLAGS= -lm

all: Quest_3 

Quest_3: main_executable_module.o data_io.o data_stat.o data_process.o decision.o 
	$(CC) $^ -o $(BUILD_PATH)$@ $(LDFLAGS)

main_executable_module.o: main_executable_module.c data_io.o data_process.o decision.o
	$(CC) $(CFLAGS) -c main_executable_module.c -o $@ $(LDFLAGS)

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o $@ $(LDFLAGS)

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o $@ $(LDFLAGS)

data_process.o: ../data_module/data_process.c ../data_module/data_process.h 
	$(CC) $(CFLAGS) -c ../data_module/data_process.c -o $@ $(LDFLAGS)

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c -o $@ $(LDFLAGS)



#static library
data_stat.a: data_stat.o 
	ar r data_stat.a data_stat.o

build_with_static: main_executable_module.o data_io.o data_stat.a data_process.o decision.o
	$(CC) main_executable_module.o data_io.o data_process.o decision.o -o $(BUILD_PATH)Quest_5 $(LDFLAGS) -L. -l:data_stat.a


#dynamic library
data_process.so: data_process_dm.o
	$(CC) -shared -o $@ $^ $(LDFLAGS)

data_process_dm.o: ../data_module/data_process.c ../data_module/data_process.h
	$(CC) -c -fPIC ../data_module/data_process.c -o $@ $(LDFLAGS)

build_with_dynamic: main_executable_module.o data_io.o data_stat.o data_process.so decision.o 
	$(CC) main_executable_module.o data_io.o data_stat.o decision.o -o $(BUILD_PATH)Quest_6 $(LDFLAGS) -L. -l:data_process.so -Wl,-rpath,.

clean:
	rm *.o

rebuild: clean all
