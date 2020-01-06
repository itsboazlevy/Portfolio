#ifndef __BINIO_H__
#define __BINIO_H__
#include "virtIO.h"
class binIO_t:public virtIO_t
{
	public:
	binIO_t(){}
	virtual ~binIO_t(){}	
	
	/*
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

	virtIO_t(const string& _pathName = "defPath", modes _mode = rw) 	{pathName = _pathName; mode = _mode;};
	virtual ~virtIO_t() 												{}
	const string& getPathName() const									{return pathName;}
	modes getMode() const												{return mode;}
	void setMode(modes _mode) 											{mode = _mode;}
	stats getStatus() const 											{return status;}
	size_t getPosition() const											{return position;}
	stats setPosition(size_t _position) 								{position = _position;}	
	void openFile();														
	stats closeFile() 													{fclose(fPtr);}
	*/

	virtual binIO_t& operator >> (char& _item)					{read(_item); return *this;}
	virtual binIO_t& operator >> (unsigned char& _item) 		{read(_item); return *this;}
	virtual binIO_t& operator >> (short& _item) 				{read(_item); return *this;}
	virtual binIO_t& operator >> (unsigned short& _item) 		{read(_item); return *this;}
	virtual binIO_t& operator >> (int& _item) 					{read(_item); return *this;}
	virtual binIO_t& operator >> (unsigned int& _item) 			{read(_item); return *this;}
	virtual binIO_t& operator >> (long& _item) 					{read(_item); return *this;}
	virtual binIO_t& operator >> (unsigned long& _item) 		{read(_item); return *this;}
	virtual binIO_t& operator >> (float& _item) 				{read(_item); return *this;}
	virtual binIO_t& operator >> (double& _item) 				{read(_item); return *this;}
	
	virtual binIO_t& operator << (const char& _item) 			{write(_item); return *this;}
	virtual binIO_t& operator << (const unsigned char& _item) 	{write(_item); return *this;}
	virtual binIO_t& operator << (const short& _item)			{write(_item); return *this;}
	virtual binIO_t& operator << (const unsigned short& _item)	{write(_item); return *this;}
	virtual binIO_t& operator << (const int& _item)				{write(_item); return *this;}
	virtual binIO_t& operator << (const unsigned int& _item)	{write(_item); return *this;}
	virtual binIO_t& operator << (const long& _item) 			{write(_item); return *this;}
	virtual binIO_t& operator << (const unsigned long& _item)	{write(_item); return *this;}
	virtual binIO_t& operator << (const float& _item)			{write(_item); return *this;}
	virtual binIO_t& operator << (const double& _item) 			{write(_item); return *this;}
	
	
	private:
	binIO_t(const binIO_t& _bin);
	const binIO_t& operator = (const binIO_t& _bin);	
	
	void operator>>(void* _buf)								{ isRorW = 0; buf = _buf; }
   	void operator<<(const void* _buf)						{ isRorW = 1; buf = (void*)_buf; }
	void operator,(int _len)								{ if(isRorW) writeB(_len);
															 else readB(_len); 	  }     
	
	/*
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
	*/
	void* buf;
	bool isRorW;
	
	template <class T>
	void write(T _dt) 
	{ 
		if (getMode() == r)
		{
			setStatus(bad_access);
			throw getStatus();
		}
		if (0 == fwrite((const void *)&_dt, sizeof(_dt), 1, getFptr()) )
		{
			setStatus(writeErr);
			throw getStatus();
		} 
	}
	
	void writeB(int _len) 
	{ 
		if (getMode() == r)
		{
			setStatus(bad_access);
			throw getStatus();
		}
		if (0 == fwrite(buf, _len, 1, getFptr()) )
		{
			setStatus(writeErr);
			throw getStatus();
		} 
	}
	
	template <class T>
	void read(T _dt) 
	{ 
		if (getMode() == r)
		{
			setStatus(bad_access);
			throw getStatus();
		}
		if (0 == fread((void *)&_dt, sizeof(_dt), 1, getFptr()) )
		{
			setStatus(writeErr);
			throw getStatus();
		} 
	}
	
	void readB(int _len) 
	{ 
		if (getMode() == r)
		{
			setStatus(bad_access);
			throw getStatus();
		}
		if (0 == fread(buf, _len, 1, getFptr()) )
		{
			setStatus(writeErr);
			throw getStatus();
		} 
	}
};	
	
#endif //__BINIO_H__
