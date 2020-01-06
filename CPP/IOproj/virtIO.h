#ifndef __VIRTIO_H__
#define __VIRTIO_H__
#include <string>
#include <stdio.h>
using namespace std;

class virtIO_t
{
	public:

	enum stats
	{ 
		ok, 
		cant_open_file,
		bad_access, 
		writeErr,
		readErr
	};
	
	enum modes
	{ 
		r, 
		w,
		rw
	};

	virtIO_t(const string& _pathName = "defFile", modes _mode = rw) 	{pathName = _pathName; mode = _mode;}
	virtual ~virtIO_t() 												{}
	const string& getPathName() const									{return pathName;}
	modes getMode() const												{return mode;}
	void setMode(modes _mode) 											{mode = _mode;}
	stats getStatus() const 											{return status;}
	size_t getPosition() const											{return position;}
	stats setPosition(size_t _position) 								{position = _position; fseek(fPtr, _position,SEEK_SET);}	
	void openFile();														
	stats closeFile() 													{fclose(fPtr);}
	
	virtual virtIO_t& operator >> (char& _z) = 0;
	virtual virtIO_t& operator >> (unsigned char& _z) = 0; 
	virtual virtIO_t& operator >> (short& _z) = 0;
	virtual virtIO_t& operator >> (unsigned short& _z) = 0; 
	virtual virtIO_t& operator >> (int& _z) = 0;
	virtual virtIO_t& operator >> (unsigned int& _z) = 0; 
	virtual virtIO_t& operator >> (long& _z) = 0;
	virtual virtIO_t& operator >> (unsigned long& _z) = 0; 
	virtual virtIO_t& operator >> (float& _z) = 0;
	virtual virtIO_t& operator >> (double& _z) = 0; 
	
	virtual virtIO_t& operator << (const char& _z) = 0;
	virtual virtIO_t& operator << (const unsigned char& _z) = 0; 
	virtual virtIO_t& operator << (const short& _z) = 0;
	virtual virtIO_t& operator << (const unsigned short& _z) = 0; 
	virtual virtIO_t& operator << (const int& _z) = 0;
	virtual virtIO_t& operator << (const unsigned int& _z) = 0; 
	virtual virtIO_t& operator << (const long& _z) = 0;
	virtual virtIO_t& operator << (const unsigned long& _z) = 0; 
	virtual virtIO_t& operator << (const float& _z) = 0;
	virtual virtIO_t& operator << (const double& _z) = 0; 
	
	protected:
	void setStatus(stats _status)										{status = _status;}
	FILE* getFptr() 													{return fPtr;}
	private:
	virtIO_t(const virtIO_t& _virt);
	const virtIO_t& operator = (const virtIO_t& _virt);
	string pathName;
	modes mode;
	size_t position;
	stats status;
	FILE* fPtr;

};

void virtIO_t::openFile()
{
	switch (getMode())
	{
		case r:	fPtr = fopen(getPathName().data(),"r");
					break;	
		case w:	fPtr = fopen(getPathName().data(),"w");	
					break;	
		case rw:fPtr = fopen(getPathName().data(),"w+");
	}
}

#endif //__VIRTIO_H__
