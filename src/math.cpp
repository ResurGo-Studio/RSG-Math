#include "resurgo/math.hpp"

using namespace resurgo;

vec::vec(std::size_t size) : _dim(size) {
	data[size] = {0};
}

template <typename T>
vec::vec(std::size_t size, T value) : _dim(size) {
	data[size] = {value};
}

template <typename T>
vec::vec(std::initializer_list<T> list) : _dim(list.size()) {
	data[list.size()] = {0};
	std::size_t i = 0;
	for (auto it = list.begin(); it != list.end(); ++it) {
		data[i] = *it;
		++i;
	}
}

template <typename iter>
vec::vec(iter begin, iter end) : _dim(end - begin) {
	data[end - begin] = {0};
	for (std::size_t i = 0; i < end - begin; i++) {
		data[i] = *(begin + i);
	}
}

template <typename iter>
vec::vec(iter begin, std::size_t size) : _dim(size) {
	data[size] = {0};
	for (std::size_t i = 0; i < size; i++) {
		data[i] = *(begin + i);
	}
}

vec::vec(const vec& v) : _dim(v._dim) {
	data[v._dim] = {0};
	for (std::size_t i = 0; i < v._dim; i++) {
		data[i] = v.data[i];
	}
}

vec::vec(vec&& v) : _dim(v._dim) {
	data[v._dim] = {0};
	for (std::size_t i = 0; i < v._dim; i++) {
		data[i] = v.data[i];
	}
}

double& vec::operator[](std::size_t index) {
	return data[index];
}

const double& vec::operator[](std::size_t index) const {
	return index < _dim ? data[index] : 0.0;
}

vec& vec::operator=(const vec& v) {
	_dim = v._dim;
	for (std::size_t i = 0; i < v._dim; i++) {
		data[i] = v.data[i];
	}
	return *this;
}

vec& vec::operator=(vec&& v) {
	_dim = v._dim;
	for (std::size_t i = 0; i < v._dim; i++) {
		data[i] = v.data[i];
	}
	return *this;
}

namespace RSGoperator {
	// const vec operator+(const vec& v1,const vec& v2){
		// vec v3(v1.dim()>v2.dim()?v1.dim():v2.dim());
		// for(std::size_t i=0;i<v1.dim();i++){
			// v3[i]=v1[i]+v2[i];
		// }
		// return v3;
	// };
}
