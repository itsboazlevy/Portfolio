#ifndef __CONTAINER_H__
#define  __CONTAINER_H__
#include <string>
template <class T>
class container_t
{
	public:
		container_t();
		virtual ~container_t(); 
		virtual bool append(const T* _elemPtr, size_t _index) = 0;
		virtual bool prepend(const T* _elemPtr, size_t _index) = 0;
		virtual bool contains(const T* _elemPtr) const = 0;
		size_t count() const {return m_nItems;}
		virtual const T* find(const T& _elem) const = 0;
		virtual int index(const T* _elemPtr) const = 0;
		bool isEmpty() const {return (m_nItems == 0);}
		virtual bool insert(const T* _elemPtr) = 0;
		virtual T* remove(const T& _elem) = 0;
		virtual T* removeAndDelete(const T& _elem) = 0;
		virtual bool removeAll() = 0;
		virtual bool removeAndDeleteAll() = 0;
	private:
		container_t(const container_t& _conRef);
		container_t& operator = (const container_t& _conRef);
		size_t m_nItems;
};

#endif //__CONTAINER_H__



