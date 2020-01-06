//make this whole thing as generic as possible - needs to be remade
// generic containers, data types, increments, powers, sum?no, accumulate in diffrent patterns, combine function - check * and +


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> Generate( int _start, int _increment, int _end)
{
	vector<int> vec;
	int i;
	// use generate or transform or w/e to not use loop directly
	for ( i = _start; i != _end; i += _increment)
	{
		vec.push_back(i);
	}
	return vec;
}

//////////////////////////////////////////////////////////////////////////

class Add
{
public:
	Add( int& _sum )
	: m_sum(_sum)
	{}
	void operator()(int& _sum) const;
private:
	int& m_sum;
};

void Add::operator()(int& _element) const
{
	m_sum += _element;
}

int Sum (std::vector<int>& _vec)
{
	int sum = 0;
	for_each(_vec.begin(),_vec.end(), Add(sum));
	return sum;
}

//////////////////////////////////////////////////////////////////////////

class Power
{
public:
	Power(int _num)
	: m_num(_num)
	{}
	void operator()(int& _element) const {_element = pow(_element, m_num);}
private:
	int m_num;
};

//////////////////////////////////////////////////////////////////////////

int main()
{
	int myP = 3;
	std::vector<int> vec = Generate ( 1,1,1000);
	cout << Sum(vec) << endl;
	for_each(vec.begin(),vec.end(),Power(3));
	cout << Sum(vec) << endl;
}
