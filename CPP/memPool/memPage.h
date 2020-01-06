#ifndef __MEMPAGE_H__
#define  __MEMPAGE_H__
#include "memManager.h"

class memPage_t:public memManager_t
{
	public:
		memPage_t()					:capacity(defCap)	{ data = new char[capacity]; }
		memPage_t(size_t _cap)		:capacity(_cap)		{ data = new char[capacity]; }
		virtual ~memPage_t()							{ delete[] data;}
		//size_t getPos() const 						{ return position; }
		//void setPos(size_t _pos)						{ if(_pos > size) throw 0; }
		//bool isEmpty() const							{ return size == 0; }
		//size_t getSize() const						{ return size; }
		bool isMemoryFull() const						{ return capacity == getSize(); }
		size_t getCapacity() const						{ return capacity; }
		static void setDefCap(size_t _defCap)			{ defCap = _defCap; }
		static size_t getDefCap()						{ return defCap; }
		virtual size_t write(const char* _data, size_t _length);				
		virtual size_t write(const char* _data, size_t _length, size_t _pos);
		virtual size_t read(char* _data, size_t _length);		
		virtual size_t read(char* _data, size_t _length, size_t _pos);
	protected:
		//void setSize(size_t _size)					{ size == _size; }
	private:
		memPage_t(const memPage_t& _ref);
		memPage_t& operator = (memPage_t& _ref);
		//size_t position;
		//size_t size;
		char* data;
		const size_t capacity;
		static size_t defCap;
};

#endif /* __MEMPAGE_H__ */
