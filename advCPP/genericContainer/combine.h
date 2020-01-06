/* Combine Class
   Author: Shahar Baradon */
#ifndef COMBINE_H
#define COMBINE_H

#include <vector>
#include <cstdio>
#include <algorithm>


//Combine class

template<class TContainer, class T>
class Combine
{
public:
	//Pluse(const T& _first){};
	virtual ~Combine() {;}
	virtual T Calc(typename TContainer::const_iterator& _begin, typename TContainer::const_iterator& _end) = 0;

};

//****************************** ADD Numbers *********************************************//

template<class T>
class SumContainer
{
public:
	SumContainer();
	
	void operator()(const T& _v);
	T GetSum()const;
	
private:
	T m_sum;
};

template<class TContainer, class T>
class AddT : public Combine<TContainer, T>
{
public:
	AddT();
	
	virtual T Calc(typename TContainer::const_iterator& _begin, typename TContainer::const_iterator& _end);
	T GetSum()const;
	
private:
	T m_sum;
};


//****************************** Multipal Numbers *********************************************//

template<class T>
class MultipalContainer
{
public:
	MultipalContainer();
	
	void operator()(const T& _v);
	T GetSum()const;
	
private:
	T m_sum;
};

template<class TContainer, class T>
class MultipalT : public Combine<TContainer, T>
{
public:
	MultipalT();
	
	virtual T Calc(typename TContainer::const_iterator& _begin, typename TContainer::const_iterator& _end);
	T GetSum()const;
	
private:
	T m_sum;
};


#include "../../cube/combine.hpp"

#endif /*end use of COMBINE_H*/
