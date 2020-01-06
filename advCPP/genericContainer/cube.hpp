#include <ctype.h>
#include <iostream>
#include <cmath>

#include "../include/cube/cube.h"

//*************** AddVec **********************//

template<class T>
AddVec<T>::AddVec()
:m_number(0){}

template<class T>
void AddVec<T>::operator()(T& _v)
{
	++m_number;
	_v += m_number;
}


//*************** SumVector ******************//

SumVector::SumVector(): m_sum(0){}

void SumVector::operator()(int& _v)
{
	m_sum += _v;
}

int SumVector::GetSum()const 
{
	return m_sum;
}

//**************** UpContiner *************//
template<class T, class E>
UpContiner<T, E>::UpContiner(T _exp)
:m_exp(_exp){}

template<class T, class E>
void UpContiner<T, E>::operator()(T& _v)const throw (std::invalid_argument)
{
	if (m_exp < 0 && _v < 0)
	{
		throw std::invalid_argument("Negative exp + number");
	}
	if (0 == _v)
	{
		_v = 0;
	}
	if (0 == m_exp)
	{
		_v = 1;
	}
	if(_v < 0)
	{
		_v = Power(_v, -m_exp) * (-1);
	}
	else 
	{
		_v = Power(_v, m_exp);
	}
}

template<class T, class E>
T UpContiner<T, E>::Power(T _val, E _exp)const
{
	T i;
	T result = 1;
	for (i = 1; i <= _exp; ++i)
	{
		result *= _val;
	}
	return result;
}

template<>
int UpContiner<int, int>::Power(int _val, int _exp)const
{
	int i;
	int result = 1;
	for (i = 1; i <= _exp; ++i)
	{
		result *= _val;
	}
	return result;
}

template<>
double UpContiner<double, double>::Power(double _val, double _exp)const
{
	double result = std::pow(_val, _exp);
	return result;
}

template<>
float UpContiner<float, float>::Power(float _val, float _exp)const
{
	float result = std::pow(_val, _exp);
	return result;
}


//********************************************* Base/First functions ****************************************************//

template<class TContainer, class T>
void GenCont(TContainer& _cont)
{
	std::for_each(_cont.begin(), _cont.end(), AddVec<T>());
}

int SumVec(std::vector<int>& _vec)
{
	SumVector s;
	s = std::for_each(_vec.begin(), _vec.end(), SumVector());
	int num = s.GetSum();
	return num;
}

template<class TContainer, class T>
T Accumelate(typename TContainer::const_iterator& _begin, typename TContainer::const_iterator& _end, Combine<TContainer, T>& _combine)
{
	T num =_combine.Calc(_begin, _end);
	
	return num;
}

template<class TContainer, class T>
void Pow(TContainer& _cont, T _exp)
{
	std::for_each(_cont.begin(), _cont.end(), UpContiner<T, T>(_exp));
}
