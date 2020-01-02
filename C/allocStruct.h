/* allocation constructs with structurs
   author: Boaz
   date: 30.1.19  */

/*
Allocates memory
Input: the size of int numbers that can be held
Output:	pointer to allocation or NULL
*/
struct da * create (int size, int incrementBlockSize);

/*
Adds an integer into the allocated memory, if out of memory reallocates more. 
Input: data to insert, numOfElements to update, size to update, incrementBlockSize to define realloc size, ptr to insert to and also to change if realloc changes address of allocation
Output:	nullError -1  reallocFail -2   overFlow -4  wrongInput -5  success 1
*/
int insert1 (struct da *myStruct, int data);

/*
removes a single number and returns it to data.
Input: ptr to remove, data to return number, num of elements to update.
Output:	removed number to data. nullError -1  underFlow -3  success 1
*/
int remove1 (struct da *ptr, int *data);

/*
cleans the allocation, allowing memory to control it once again.
Input: ptr to allocation start.
Output:	none.
*/

void destroy (struct da *myStruct);
