#ifndef __MEMMANAGER_H__
#define  __MEMMANAGER_H__
#include <string>
class memManager_t 
{
	public:
		memManager_t()				:position(0), size(0) 	{}
		virtual ~memManager_t() 							{}
		size_t getPos() const 								{ return position; }
		void setPos(size_t _pos)							{ if(_pos > size) throw 0; }
		bool isEmpty() const								{ return size==0; }
		size_t getSize() const								{ return size; }
		virtual size_t write(const char* _data, size_t _length)				= 0; 				
		virtual size_t write(const char* _data, size_t _length, size_t _pos)= 0; 
		virtual size_t read(char* _data, size_t _length)                    = 0; 
		virtual size_t read(char* _data, size_t _length, size_t _pos)		= 0; 
	protected:
		void setSize(size_t _size)							{ size = _size; }
	private:
		memManager_t(const memManager_t& _ref) 				{}
		memManager_t& operator = (const memManager_t& _ref) {}
		size_t position;
		size_t size;
};

#endif /* __MEMMANAGER_H__ */
