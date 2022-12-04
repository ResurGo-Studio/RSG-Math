//#include "resurgo/math.hpp"
#include <utility>
#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>

#include "resurgo/math.hpp"

using namespace resurgo;

	const vec operator+(const vec& v1,const vec& v2){
		vec v3(v1.dim()>v2.dim()?v1.dim():v2.dim());
		std::cout<<v1[114514]<<std::endl;
		for(std::size_t i=0;i<v3.dim();i++){
			v3[i]=v1[i]+v2[i];
		}
		return v3;
	};


int main(){
	std::cout<<sizeof(std::size_t)<<std::endl;
	std::size_t test1=0;
	std::size_t test2=0;

	vec v1(3);
	vec v2(4);
	std::cout<<sizeof(v1)<<std::endl;
	std::cout<<sizeof(v2)<<std::endl;


	std::cout<<(v1+v2)[0]<<std::endl;
	return 0;
}
