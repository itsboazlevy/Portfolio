/***************************************************************************************
    Author :		Alex Katz  (alexanderk@experis.co.il)	
    Created :      	17.1.12
    Updated :		20.1.19
    Description : 	Continues memory allocator, Allocates chunks of different sizes
    				from specified user buffer, first fit strat 
****************************************************************************************/
#ifndef __MYMALLOC_H_
#define __MYMALLOC_H_
#include <stddef.h>

/**
 * @brief  :	Initializes the memory allocator
 * @params :	_membuf - the memory buffer to manage 
 *		_nBytes - size of the memory buffer
 * returns:	NULL on error, aligned memory buffer on success
 */
void*	MyMallocInit(void* _membuf, size_t _nBytes);

/**
 * @brief  :	Allocate memory chunk of specified size.
 * @params :	_membuf - the memory buffer returned from MyMallocInit
		_nBytes - the size of the chunk
 * returns:	NULL on error, chunk of requested size (at least) on success
 */
void*	MyMalloc(void* _membuf, size_t _nBytes);

/**
 * @brief  :	Free previously allocated memory chunck
 * @params :	_membuf - the memory chunk returned from MyMalloc
 */
void	MyFree(void* _ptr);


/* Debugging support functions */
void	MyMallocPrint(void* _membuf);


#endif /* __MYMALLOC_H_ */
