void* memInit (size_t ptr,int size);
/*unsigned int*/
/*allignment %4 to be alligned from start and end*/
/*end header is 0*/
/*minimum block size is 8 bytes meaning if user asks for 1 he gets 8*/
/*minimum block size to split is 16 because the result of splitting less is a number that we cant work with*/
/*no numbers in code*/
/*h file test file :(*/ 
unsigned int* memAlloc (void* buff, int size);


memFree (unsigned int*)

