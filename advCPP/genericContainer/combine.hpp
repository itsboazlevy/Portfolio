#include <ctype.h>
#include <iostream>

#include "../include/cube/combine.h"



//****************************** ADD Numbers *********************************************//

template<class T>
SumContainer<T>::SumContainer()
: m_sum(0){}

template<class T>
void SumContainer<T>::operator()(const T& _v)
{
	m_sum += _v;
}

template<class T>
T SumContainer<T>::GetSum()const 
{
	return m_sum;
}


template<class TContainer, class T>
AddT<TContainer, T>::AddT()
: m_sum(0){}

template<class TContainer, class T>
T AddT<TContainer, T>::Calc(typename TContainer::const_iterator& _begin, typename TContainer::const_iterator& _end)
{
	SumContainer<T> tempSum;
	tempSum = std::for_each(_begin, _end, SumContainer<T>());
	m_sum = tempSum.GetSum();
	return m_sum;
}

template<class TContainer, class T>
T AddT<TContainer, T>::GetSum()const 
{
	return m_sum;
}

//****************************** Multipal Numbers *********************************************//

template<class T>
MultipalContainer<T>::MultipalContainer()
: m_sum(1){}

template<class T>
void MultipalContainer<T>::operator()(const T& _v)
{
	m_sum *= _v;
}

template<class T>
T MultipalContainer<T>::GetSum()const 
{
	return m_sum;
}


template<class TContainer, class T>
MultipalT<TContainer, T>::MultipalT()
: m_sum(0){}

template<class TContainer, class T>
T MultipalT<TContainer, T>::Calc(typename TContainer::const_iterator& _begin, typename TContainer::const_iterator& _end)
{
	MultipalContainer<T> tempMul;
	tempMul = std::for_each(_begin, _end, MultipalContainer<T>());
	m_sum = tempMul.GetSum();
	return m_sum;
}

template<class TContainer, class T>
T MultipalT<TContainer, T>::GetSum()const 
{
	return m_sum;
}


