.PHONY = format sample cppcheck

CC = g++
valgrindFile = valgrind.txt
FLAGS = --std=c++11
HEADERS = arrayList.h
SRC = main.cpp arrayList.cpp

make.out: ${SRC}
	$(CC) $(FLAGS) $^ -o $@ 

debug.out: ${SRC}
	$(CC) $(FLAGS) -g $^ -o $@ 

format: ${SRC}
	clang-format -i $^
 
gdb: debug.out 
	gdb --args ./debug.out 

valgrind.txt: debug.out make.out
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=${valgrindFile} make.out < sample.in

valgrind-check: debug.out make.out
	valgrind --log-file=mem_test_report $(file).out < sample.in

cppcheck:
	 cppcheck --enable=all --error-exitcode=1 --language=c++ ./*.cpp ./*.h ./*.hpp
