//Design is complete, excluding element, implementation is incomplete.
#ifndef BUFFER_H
#define BUFFER_H

template <typename T>
class Buffer
{
public:
	typedef unsigned char byte;
	
	Buffer(size_t _size = 0);
	Buffer(const Buffer& _buffer);
	Buffer& operator =(const Buffer& _buffer);
	~Buffer();
	
	size_t Size() const;
	void GrowIfNeed(size_t _size);
	
	byte* Begin() const;
	byte* End() const;
	
private:
	size_t m_size;
	size_t m_capacity;
	byte* m_data;
	static double growFactor;
};

#include "../string/buffer.hpp"

#endif //BUFFER_H

