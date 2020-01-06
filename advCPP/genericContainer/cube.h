/* Cube Class
   Author: Shahar Baradon */
#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <cstdio>
#include <algorithm>
#include "combine.h"

template<class T>
class AddVec
{
public:
	AddVec();
	void operator()(T& _v);
	
private:
	T m_number;
};

class SumVector
{
public:
	SumVector();
	
	void operator()(int& _v);
	int GetSum()const;
	
private:
	int m_sum;
};

template<class T, class E>
class UpContiner
{
	public:
	UpContiner(T _exp);
	
	void operator()(T& _v)const throw (std::invalid_argument);
	
	private:
	T m_exp;
	T Power(T _val, E _exp)const;
};


//********************************************* Base/First functions ****************************************************//

template<class TContainer, class T>
void GenCont(TContainer& _cont);

int SumVec(std::vector<int>& _vec);

template<class TContainer, class T>
T Accumelate(typename TContainer::const_iterator& _begin, typename TContainer::const_iterator& _end, Combine<TContainer, T>& _combine);

template<class TContainer, class T>
void Pow(TContainer& _cont, T _exp);



#include "../../cube/cube.hpp" 
#endif /*end use of CUBE_H*/
