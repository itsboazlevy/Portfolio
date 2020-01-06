#ifndef __stl_h__
#define __stl_h__
#include <cstring>
using namespace std;

template <class T>
class equal
{
	public:
		equal(const T& _val):val(_val){}
		bool operator()(const T& _elemRef)const{return _elemRef == val;}
	private:
		T val;

};

template <class T, class C> 
class tContainer_t
{
	typedef typename tContainer_t<T,C>			
	public:
		tContainer_t()							{}
		~tContainer_t() 						{}
		bool isEmpty() const					{return container.empty();}
		size_t size() const						{return container.size();}
		const T& insertEnd(const T* _elemPtr)	{return container.insert(container.size-1,*_elemPtr);}
		const T* getFirst()	const				{return *container.begin();}
		const T* getLast() const				{return *container.end();}
		const T* find(const T& _elemRef) const;	
		//const T* remove()						{return erase();}
		void removeAll()						{container.clear();}
		void removeAndDelete(const T& _elemRef)	{container.erase(container.find(_elemRef));}
		void removeAndDeleteAll()				{container.erase(container.begin(),container.end());}	
	private:
		tContainer_t(const tContainer_t<T,C>& _cont);
		C container;
};

#endif //__stl_h__

template <class T, class C> 
const T* tContainer_t<T,C>::find(const T& _elemRef) const
{ 
	return find_if(container.begin(),container.end(),equal<T>(_elemRef)); 
}

template <class T, class C> 
const T& tContainer_t<T,C>::operator [](size_t _index) const
{ 
	if (typeid(container) == typeid (vector<t*>))
	{
		return (*(vector<T*>*)&m_container);
	}
	if (typeid(container) == typeid (list<t*>))
	{
		return (*(vector<T*>*)&m_container)
	}
}
