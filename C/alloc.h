/* alloc construct
   author: Boaz
   date: 28.1.19  */

/*
Allocates memory, size is given to determine ammount
Input: the size of int numbers that can be held and a status to return
Output:	status -1 if null Error 0 if succecful
*/
int *create (int size, int *status);

/*
Adds a number into the allocated memory, if out of memory reallocates more. 
Input: data to insert, numOfElements to update, size to update, incrementBlockSize to define realloc size, status to update, ptr to insert to
and also to change if realloc changes address of allocation
Output:	status -1 if realloc Error 0 if succecful
*/
void insert1 (int **ptr, int data, int *numOfElements, 
int *size, int incrementBlockSize, int *status);

/*
removes a single number and returns it to data.
Input: ptr to remove, data to return number, num of elements to update.
Output:	removed number to data.
*/
int remove1 (int *ptr, int *data, int *numOfElements);

/*
cleans the allocation, allowing memory to control it once again.
Input: ptr to allocation start.
Output:	none.
*/
void destroy (int *ptr);
