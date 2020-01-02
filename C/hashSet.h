#include <stdlib.h>
typedef struct Hash Hash;

typedef enum
{
	NULL_ERR,
	NO_ERR,
	REALLOC_ERR,
	DATA_OVERLAP_ERR,
	DATA_NOT_FOUND_ERR
}ADTErr;

/* 
Description: creates hash
Input: size of hash 
Output: Pointer to hash
Error: NULL pointer if failed or if size is 0
*/
Hash* HashCreate (size_t _size);

/* 
Description: destroys hash
Input: pointer to hash
Output: none
Error: none
*/
void HashDestroy (Hash* _hash);

/* 
Description: checks if given data is already inside hash, reallocates memory, rehashes as much as needed to insert and finaly inserts if no errors
Input: pointer to hash, data to insert
Output: NO_ERR if succesful
Error: NULL_ERR if given pointer hash is not valid, DATA_OVERLAP_ERR if data already exists, REALLOC_ERR if could not allocate more memory 
*/
ADTErr HashInsert (Hash* _hash, int _data);

/* 
Description: checks if given data is inside hash, delets it if found
Input: pointer to hash, data to remove
Output: NO_ERR if succesful
Error: NULL_ERR if given pointer hash is not valid, DATA_NOT_FOUND_ERR if data isnt inside hash
*/
ADTErr HashRemove (Hash* _hash, int _data);

/* 
Description: checks if given data is inside hash, stops search if found data, if reached max rehash num or if reached fresh free index O(1)
Input: pointer to hash, data to search
Output: 1 if found, 0 if not
Error: NULL_ERR if given pointer hash is not valid
*/
int HashIsFound (Hash* _hash, int _data);

/* 
Description: returns number of items in hash 
Input: pointer to hash
Output: number of items
Error: NULL_ERR if given pointer hash is not valid
*/
size_t HashNumOfItems (Hash* _hash);

/* 
Description: returns the size of the hash 
Input: pointer to hash
Output: size of hash
Error: NULL_ERR if given pointer hash is not valid
*/
size_t HashCapacitiy (Hash* _hash);

/* 
Description: returns average of rehashes per insert 
Input: pointer to hash
Output: average rehashes
Error: NULL_ERR if given pointer hash is not valid
*/
double HashAverageRehashes (Hash* _hash);

/* 
Description: returns max number of rehash per single insert
Input: pointer to hash
Output: max rehash number
Error: NULL_ERR if given pointer hash is not valid
*/
size_t HashMaxReHash (Hash* _hash);

/* 
Description: prints hash data and status tables
Input: pointer to hash
Output: prints tables
Error: prints error message
*/
void HashPrint (Hash* _hash);
