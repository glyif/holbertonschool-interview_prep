#0x09 heap sort
	
	
The files sort.h and 0-heap_sort.c provide the functionality to sort an array 
of integers using heap sort.
The prototype for the sort function is:

	void heap_sort(int *array, size_t size);
	
The sorting function prints the current array state every time two array 
elements are swapped.
The print function has the following prototype:
	
	void print_array(const int *array, size_t size);

In order to use both functions the files 0-heap_sort.c and print_array.c must
be linked together with the calling function. For example, if the main.c
program uses the heap_sort and print_array functions, the following command
will make the executable 0-heap:

	gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c \
										print_array.c -o 0-heap

