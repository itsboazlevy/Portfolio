#ifndef UNIQUE_HPP
#define UNIQUE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>

template <typename T>
class MapInsert
{
public:
	MapInsert( std::tr1::unordered_map<T,size_t>& _map )
	: m_map(_map)
	{}
	void operator() (const T& _t) const;
private:
	std::tr1::unordered_map<T,size_t>& m_map;
};

template <typename T>
void MapInsert<T>::operator()(const T& _v) const
{
	++m_map[_v];
}

template <typename T>
class MapFind
{
public:
	MapFind(std::tr1::unordered_map<T,size_t>& _map, int f)
	: m_map(_map), m_freq(f)
	{

	}
	bool operator() (const T& _t) const;
private:
	std::tr1::unordered_map<T,size_t>& m_map;
	const int m_freq
};

template <typename T>
bool MapFind<T>::operator() (const T& _t) const
{
	return m_map[_t] == m_freq;
}


// void buildFreq(& _vec, & map)
// {
// 	for_each(_vec.begin(), _vec.end(), MapInsert<T>(map));
// }
// T = O(2n)

template <typename T>
typename std::vector<T>::const_iterator
Unique(const std::vector<T>& _vec)
{
	std::tr1::unordered_map<T,size_t> myMap;
	for_each(_vec.begin(), _vec.end(), MapInsert<T>(map));

	typename std::vector<T>::const_iterator it;
	it = find_if(_vec.begin(), _vec.end(), MapFind<T>(myMap, 1));
	return it;
}

#endif //UNIQUE_HPP





