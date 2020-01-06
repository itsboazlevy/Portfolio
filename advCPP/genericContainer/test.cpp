#include "mu_test.h"
#include "./cube/cube.h"
#include "./cube/combine.h"
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>  

/*template<class T>
void Shuffle(typename std::vector<T>& _vec)
{
	std::random_shuffle(_vec.begin, _vec.end());
}*/

UNIT(cube_int_vec_simple)
	std::vector<int> _vec(1000, 0);
	GenCont<std::vector<int>, int>(_vec);
	typename std::vector<int>::const_iterator begin = _vec.begin();
	typename std::vector<int>::const_iterator end = _vec.end();
	
	ASSERT_THAT(*(begin + 599) == 600);
	ASSERT_EQUAL(SumVec(_vec), 500500);
	
	AddT<std::vector<int>, int> add;
	int i = Accumelate<std::vector<int>, int>(begin, end, add);
	ASSERT_EQUAL(i, 500500);


END_UNIT

UNIT(cube_int_list_simple)
	std::list<int> list(1000, 0);
	GenCont<std::list<int>, int>(list);
	typename std::list<int>::const_iterator begin = list.begin();
	typename std::list<int>::const_iterator end = list.end();
	
	for (int i = 0; i < 599; ++i, ++begin);
	ASSERT_THAT(*(begin) == 600);
	
	AddT<std::list<int>, int> add;
	begin = list.begin();
	int i = Accumelate<std::list<int>, int>(begin, end, add);
	ASSERT_EQUAL(i, 500500);


END_UNIT

UNIT(cube_int_list_mul_simpal)
	std::list<int> list(10, 0);
	GenCont<std::list<int>, int>(list);
	typename std::list<int>::const_iterator begin = list.begin();
	typename std::list<int>::const_iterator end = list.end();
	
	for (int i = 0; i < 8; ++i, ++begin);
	ASSERT_THAT(*(begin) == 9);
	
	MultipalT<std::list<int>, int> mul;
	begin = list.begin();
	int i = Accumelate<std::list<int>, int>(begin, end, mul);
	ASSERT_EQUAL(i, 3628800);


END_UNIT

UNIT(cube_double_list_simple)
	std::list<double> list(1000, 0);
	GenCont<std::list<double>, double>(list);
	typename std::list<double>::const_iterator begin = list.begin();
	typename std::list<double>::const_iterator end = list.end();
	
	for (int i = 0; i < 599; ++i, ++begin);
	ASSERT_THAT(*(begin) == 600);
	
	AddT<std::list<double>, double> add;
	begin = list.begin();
	double i = Accumelate<std::list<double>, double>(begin, end, add);
	ASSERT_THAT(i == 500500);


END_UNIT


UNIT(cube_int_list_pow)
	std::list<int> list(10, 0);
	GenCont<std::list<int>, int>(list);
	typename std::list<int>::const_iterator begin = list.begin();
	typename std::list<int>::const_iterator end = list.end();
	
	Pow<std::list<int>, int>(list, 2);
	for (int i = 0; i < 5; ++i, ++begin);
	ASSERT_THAT(*(begin) == 36);
	
	AddT<std::list<int>, int> add;
	begin = list.begin();
	int i = Accumelate<std::list<int>, int>(begin, end, add);
	ASSERT_THAT(i == 385);


END_UNIT

UNIT(cube_double_list_pow)
	std::list<double> list(10, 0);
	GenCont<std::list<double>, double>(list);
	typename std::list<double>::const_iterator begin = list.begin();
	typename std::list<double>::const_iterator end = list.end();
	
	Pow<std::list<double>, double>(list, 2);
	for (double i = 0; i < 5; ++i, ++begin);
	ASSERT_THAT(*(begin) == 36);
	
	AddT<std::list<double>, double> add;
	begin = list.begin();
	double i = Accumelate<std::list<double>, double>(begin, end, add);
	ASSERT_THAT(i == 385);


END_UNIT

UNIT(cube_double_list_pow_com)
	std::list<double> list(10, 0);
	GenCont<std::list<double>, double>(list);
	typename std::list<double>::const_iterator begin = list.begin();
	//typename std::list<double>::const_iterator end = list.end();
	
	Pow<std::list<double>, double>(list, 1.5);
	for (double i = 0; i < 5; ++i, ++begin);
	ASSERT_THAT(*(begin) == std::pow(6, 1.5));
	

END_UNIT

UNIT(cube_float_list_pow_com)
	std::list<float> list(10, 0);
	GenCont<std::list<float>, float>(list);
	typename std::list<float>::const_iterator begin = list.begin();
	
	Pow<std::list<float>, float>(list, 1.5);
	for (int i = 0; i < 5; ++i, ++begin);
	ASSERT_THAT(*(begin) == std::pow(6, 1.5));
	

END_UNIT





TEST_SUITE(C++ Unit Test Demo for mu_test!)

	TEST(cube_int_vec_simple)
	TEST(cube_int_list_simple)
	TEST(cube_double_list_simple)
	TEST(cube_int_list_mul_simpal)
	TEST(cube_int_list_pow)
	TEST(cube_double_list_pow)
	TEST(cube_double_list_pow_com)


END_SUITE


