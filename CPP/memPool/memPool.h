#ifndef __MEMPOOL_H__
#define  __MEMPOOL_H__
#include "memManager.h"
#include "memPage.h"
#include <vector>
using namespace std;

class memPool_t:public memManager_t
{
	public:
		memPool_t()										{ memPage_t* pagePtr = new memPage_t; data.insert(data.end(), pagePtr); }
		virtual ~memPool_t()							{ size_t i; for(i=0; i< data.size(); i++) delete[] data[i]; }
		//size_t getPos() const 						{ return position; }
		//void setPos(size_t _pos)						{ if(_pos > size) throw 0; }
		//bool isEmpty() const							{ return size == 0; }
		//size_t getSize() const						{ return size; }
		void setPageCap( size_t _pageCap) 				{ memPage_t::setDefCap(_pageCap); }
		size_t getPageCap()								{ return memPage_t::getDefCap(); }
		virtual size_t write(const char* _data, size_t _length);				
		virtual size_t write(const char* _data, size_t _length, size_t _pos);
		virtual size_t read(char* _data, size_t _length);		
		virtual size_t read(char* _data, size_t _length, size_t _pos);
	protected:
		//void setSize(size_t _size)					{ size == _size; }
	private:
		memPool_t(memPool_t& _ref);
		memPool_t& operator = (memPool_t& _ref);
		//size_t position;
		//size_t size;
		vector<memPage_t*> data;
};

#endif /* __MEMPOOL_H__ */




