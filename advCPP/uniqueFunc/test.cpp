#include "unique.hpp"
#include <algorithm>

void genRuns(std::vector<int>& v, int n, int rl){
	v.clear();
	for(int i = 0; i < n/rl; ++i){
		for(int j = 0; j < rl; ++ j)
			v.push_back(i);
	}
}

void print(std::vector<int>& v){
	int n = (int)v.size();
	for(int i = 0; i < n; ++i)
		std::cout << v[i] << ",";
	std::cout << '\n';
}

void shuffle(std::vector<int>& v){
	std::random_shuffle(v.begin(), v.end());
}

// void gen(std::vector<int>& v, int n,
// 		std::vector< std::pair<int, int> > const& u){

void gen(std::vector<int>& v, int n, int uniq, int where = 0){

	genRuns(v, n, n/100);
	//print(v);
	shuffle(v);
	//print(v);
	// for(int i = 0; i < n; ++i){
	// 	v.push_back(7);
	// }
	// for(size_t i = 0; i < u.size(); ++i)
	// 	v[ u[i].first ] = u[i].second;
	v[where] = uniq;
}

void test(int len, int n, int w)
{
	typename std::vector<int>::const_iterator it;
	std::vector<int> myVec;
	gen(myVec, len, n, w);
	it = Unique(myVec);
	if(it != myVec.end())
		std::cout << "found one : " << *it << '\n';
	else
		std::cout << "none \n";
}

int main()
{
	test(1000, -9, 0);
	test(1000, -9, 1000-1);
	test(1000, -9, 1000/3);
	test(1000, 9, 1000-1);
	test(1000000, -9, 1000000/3);

//unit test, string test and cat test
}
