// #include "resurgo/math.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include "resurgo/vector.hpp"

using namespace resurgo;
using namespace std;

/**
 * @brief Example 1: Vector addition
 *
 * @tparam T
 * @param list
 *
 * @return 
 */
template <typename T>
int func(std::initializer_list<T> list) {
	for (auto i : list) {
		std::cout << i << std::endl;
	}
}

int main() {
	// std::cout<<sizeof(std::size_t)<<std::endl;
	// std::size_t test1=0; //注释掉这一行就会报错

	vec a{1,2,3};
	vec b{1,2,3};
	vec c = a + b;

	// std::cout<<sizeof(v1)<<std::endl;
	// std::cout<<sizeof(v2)<<std::endl;

	return 0;
}
