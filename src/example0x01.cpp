// #include "resurgo/math.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

struct t{
	int a;
	int &b=a;
	int &c=a;
	int &d=a;
};

int main() {
	std::cout<<sizeof(t)<<std::endl;
	std::cout<<sizeof(int)<<std::endl;
	return 0;
}
