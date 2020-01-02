#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include "MyMalloc.h"

typedef char 		Byte;
typedef ssize_t 	BlockSize;
typedef ssize_t		BlockMeta;

#define FIRST_META 2*sizeof(BlockMeta)
#define TOTAL_META 3*sizeof(BlockMeta)

/* Mask for alignment to the short, long, double or 16 bytes boundary */
/* Currently we use 4/8 bytes */
#define A_MASK (sizeof(BlockMeta)-1)
#define ALIGN_PREV(X)  ((X) & ~A_MASK)
#define ALIGN_NEXT(X) (((X) + A_MASK) & ~A_MASK)

/*
 * The memory buffer is marked by it's size in the first long int location
 *  and by NULL/0 in the last
 *
 * The allocation is always aligned to the sizeof(metadata) boundary
 *
 * Each block holds the size of the block (brutto) in the first int/long
 *  and is marked by sign as free (positive) or allocated (negative)
 */
enum {
	BLOCK_ALLOC =  -1,
	BLOCK_NONE  =   0,
	BLOCK_FREE  =  +1
};

/*
 * These are memory block accesor/setter functions
 * in Debug mode should be 'static';
 * in Prod  mode should have been 'inline';
 */
static void *BlockFirst(void *_mem)
{
	return (char *)_mem + sizeof(BlockMeta);
}

static BlockSize BlockGetSize(void *_block)
{
	return *(BlockSize *)_block;
}

static void* BlockListNext(void *_block)
{
	return (Byte*)_block + abs(BlockGetSize(_block));
}

static void BlockSetSize(void *_block, BlockMeta _size)
{
	*(BlockSize *)_block = _size;
}

static void* Block2Data(void* _block)
{
	return ((Byte *)_block + sizeof(BlockMeta));
}

static void* Data2Block(void* _block)
{
	return ((Byte *)_block - sizeof(BlockMeta));
}

static int IsBlockFree(void* _block)
{
	return (BlockGetSize(_block) > 0);
}
static int IsBlockAlloc(void* _block)
{
	return (BlockGetSize(_block) < 0);
}

static void BlockSetState(void *_block, int _state)
{
	int size = abs(BlockGetSize(_block));

	if (_state == BLOCK_ALLOC)
		BlockSetSize(_block, -size);
	else
		BlockSetSize(_block,  size);
}

/*
 * Perform the allocation and if needed split the block into two.
 */
static int BlockSplit(void *_block, size_t _size)
{
	int cur = BlockGetSize(_block);

	if (cur == _size)
	{	/* just mark allocated */
		BlockSetState(_block, BLOCK_ALLOC);
		return 0;
	}
	else if (cur > _size)
	{	/* split - first part allocated */
		BlockSetSize (_block, _size);
		BlockSetState(_block, BLOCK_ALLOC);

		/* rest of block is still free */
		_block = BlockListNext(_block);
		BlockSetSize (_block, cur - _size);
		BlockSetState(_block, BLOCK_FREE);
		return 1;
	}
	return -1;
}

/*
 * Check if there are contiguous free blocks and join them into one
 */
static BlockMeta BlockJoin(void *_block)
{
	void *next = _block;
	int   size = 0;

	while (IsBlockFree(next))
	{
		size += BlockGetSize(next);
		BlockSetSize(next, BLOCK_NONE);
		next  = BlockListNext(next);
	}

	BlockSetSize (_block, size);
	BlockSetState(_block, BLOCK_FREE);

	return size;
}

/*************************************************************/
void *MyMallocInit(void* _mem, size_t _nBytes)
{
	size_t size;
	void  *blk, *mem;

	assert(_mem);

	/* align memory buffer start & total size accordingly */
	mem  = blk  = (void *)ALIGN_NEXT((size_t)_mem);
	size = ALIGN_PREV((size_t)_mem + _nBytes) - (size_t)blk;

	/* ensure there is enough memory for metadata */
	assert(size > TOTAL_META);

	/* clear the entire memory buffer */
	memset(_mem, 0, _nBytes);

	/* mark the size of the entire memory */
	BlockSetSize(blk, size);

	/* mark the size of the first (and only) free block */
	blk = BlockFirst(blk);
	BlockSetSize (blk, size - FIRST_META);
	BlockSetState(blk, BLOCK_FREE);

	return mem;
}

/*************************************************************/
void* MyMalloc(void* _mem, size_t _nBytes)
{
	void *cBlck;
	int   acc = 0;

	assert(_mem);

	/* align memory buffer start */
	_mem = (void *)ALIGN_NEXT((size_t)_mem);

	/* align allocation size to next BlockMeta boundary
	 * and add size for block length
	 */
	_nBytes = ALIGN_NEXT(_nBytes + sizeof(BlockMeta));

	/* ensure the memory requested is not bigger than entire memory */
	if (_nBytes >= BlockGetSize(_mem) - TOTAL_META)
		return 0;

	for ( cBlck = BlockFirst(_mem);			/* start at first block */
		  0    != BlockGetSize(cBlck);		/* until terminator	0  */
		  cBlck = BlockListNext(cBlck)		/* jump to next block */
		)
	{
		if (IsBlockFree(cBlck))
		{
			acc = BlockJoin(cBlck);			/* join contiguous blocks */
			if (acc > _nBytes)				/* we have enough memory */
			{
				BlockSplit(cBlck, _nBytes);
				return Block2Data(cBlck);
			}
		}
	}

	return NULL;
}

/*************************************************************/
void MyFree(void* _ptr)
{
	void *cBlck = Data2Block(_ptr);

	/* check for validity of _ptr and that the block is free */
	assert(_ptr);
	assert(IsBlockAlloc(cBlck));

	BlockSetState(cBlck, BLOCK_FREE);
	BlockJoin(cBlck);

}

void MyMallocPrint(void* _mem)
{
	void *blk;

	assert(_mem);

	printf("----------------------------------------\n");
	printf("\npointer to entire memory: %p\n",_mem);
	printf("\ntotal number of bytes in memory: %ld", BlockGetSize(_mem));

	/* set pointer in order to the begining of the first block */
	blk = BlockFirst(_mem);

	while (BlockGetSize(blk))
	{
		printf("\nblock pointer: %p",blk);
		printf("\nnumber of bytes in block: %ld", BlockGetSize(blk));

		blk = BlockListNext(blk);
	}
	printf("\n----------------------------------------\n");
}
