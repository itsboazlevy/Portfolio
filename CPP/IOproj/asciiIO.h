#ifndef __ASCIIIO_H__
#define __ASCIIIO_H__
#include "virtIO.h"
class asciiIO_t:public virtIO_t
{
	public:
	asciiIO_t():virtIO_t() {}
	virtual ~asciiIO_t() {}
	
	/*
	const string& 	getPathName()					 const					{return pathName;}
	stats 			getStatus() const 										{return status;}
	
	size_t 			getPosition() const										{return position;}
	stats 			setPosition(size_t _position) 							{position = _position;}	
	
	modes 			getMode()						 const					{return mode;}
	void 			setMode(modes _mode) 									{mode = _mode;}

	void 			openFile();														
	stats 			closeFile() 											{fclose(fPtr);}												
	*/
	
	virtual asciiIO_t& operator >> (char& _item)				{read(_item,"%c"); return *this;}
	virtual asciiIO_t& operator >> (unsigned char& _item) 		{read(_item,"%c"); return *this;}
	virtual asciiIO_t& operator >> (short& _item) 				{read(_item,"%hi"); return *this;}
	virtual asciiIO_t& operator >> (unsigned short& _item) 		{read(_item,"%hu"); return *this;}
	virtual asciiIO_t& operator >> (int& _item) 				{read(_item,"%d"); return *this;}
	virtual asciiIO_t& operator >> (unsigned int& _item) 		{read(_item,"%u"); return *this;}
	virtual asciiIO_t& operator >> (long& _item) 				{read(_item,"%ld"); return *this;}
	virtual asciiIO_t& operator >> (unsigned long& _item) 		{read(_item,"%lu"); return *this;}
	virtual asciiIO_t& operator >> (float& _item) 				{read(_item,"%f"); return *this;}
	virtual asciiIO_t& operator >> (double& _item) 				{read(_item,"%lf"); return *this;}
	
	virtual asciiIO_t& operator << (const char& _item) 			{write(_item,"%c"); return *this;}
	virtual asciiIO_t& operator << (const unsigned char& _item) {write(_item,"%c"); return *this;}
	virtual asciiIO_t& operator << (const short& _item)			{write(_item,"%hi"); return *this;}
	virtual asciiIO_t& operator << (const unsigned short& _item){write(_item,"%hu"); return *this;}
	virtual asciiIO_t& operator << (const int& _item)			{write(_item,"%d"); return *this;}
	virtual asciiIO_t& operator << (const unsigned int& _item)	{write(_item,"%u"); return *this;}
	virtual asciiIO_t& operator << (const long& _item) 			{write(_item,"%ld"); return *this;}
	virtual asciiIO_t& operator << (const unsigned long& _item)	{write(_item,"%lu"); return *this;}
	virtual asciiIO_t& operator << (const float& _item)			{write(_item,"%f"); return *this;}
	virtual asciiIO_t& operator << (const double& _item) 		{write(_item,"%lf"); return *this;}
	
	private:
	asciiIO_t(const asciiIO_t& _ascii);
	const asciiIO_t& operator = (const asciiIO_t& _ascii);

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
	
	template <class T>
	void write(T _dt,const char* _format) 
	{ 
		if (getMode() == r)
		{
			setStatus(bad_access);
			throw getStatus();
		}
		
		if (fprintf(getFptr(), _format,_dt) < 0)
		{
			setStatus(writeErr);
			throw getStatus();
		} 
		//set pos
	}
	
	template <class T>
	void read(T _dt,const char* _format)
	{ 
		if (getMode() == w)
		{
			setStatus(bad_access);
			throw getStatus();
		}
		if (fscanf(getFptr(), _format,_dt) < 0 )
		{
			setStatus(readErr);
			throw getStatus();
		}
		//set pos
	}
	
};

#endif // __ASCIIIO_H__


