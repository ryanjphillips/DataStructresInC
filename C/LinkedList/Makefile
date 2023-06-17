home =/home/ys/Code/BooksAndLearning/DataStructures/LinkedList/
file =linkedList
CC=gcc
flags=-Wextra -Wall -Wfloat-equal

make:
	gcc -o $(file) $(file).c $(flags) 

uncrustify:
	find $(home) -type f -name '*.c' -exec uncrustify --no-backup -l=C {} + 
