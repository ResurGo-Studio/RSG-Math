#include "resurgo/vector.hpp"

using namespace resurgo;

vec::vec(std::size_t size) : _dim(size), data(new double[size]) {}

vec::vec(std::size_t size, std::initializer_list<int> list)
    : _dim(size), data(new double[size]) {
	if (list.size() != size) {
		throw std::invalid_argument(
		    "Initializer list size does not match vector size");
	}
	std::size_t i = 0;
	for (auto it = list.begin(); it != list.end(); ++it) {
		data[i] = *it;
		++i;
	}
}

vec::vec(std::size_t size, std::initializer_list<double> list)
    : _dim(size), data(new double[size]) {
	if (list.size() != size) {
		throw std::invalid_argument(
		    "Initializer list size does not match vector size");
	}
	std::size_t i = 0;
	for (auto it = list.begin(); it != list.end(); ++it) {
		data[i] = *it;
		++i;
	}
}

template <typename T>
vec::vec(std::size_t size, T value) : _dim(size), data(new double[size]) {
	memset(data, value, size);
}

vec::vec(std::initializer_list<double> list)
    : _dim(list.size()), data(new double[list.size()]) {
	for (std::size_t i = 0; i < list.size(); i++) {
		data[i] = list.begin()[i];
	}
}

vec::vec(std::initializer_list<int> list)
    : _dim(list.size()), data(new double[list.size()]) {
	for (std::size_t i = 0; i < list.size(); i++) {
		data[i] = list.begin()[i];
	}
}

template <typename iter>
vec::vec(iter begin, iter end)
    : _dim(end - begin), data(new double[end - begin]) {
	for (std::size_t i = 0; i < end - begin; i++) {
		data[i] = *(begin + i);
	}
}

template <typename iter>
vec::vec(iter begin, std::size_t size) : _dim(size), data(new double[size]) {
	for (std::size_t i = 0; i < size; i++) {
		data[i] = *(begin + i);
	}
}

vec::vec(const vec& v) : _dim(v._dim), data(new double[v._dim]) {
	for (std::size_t i = 0; i < v._dim; i++) {
		data[i] = v.data[i];
	}
}

vec::vec(vec&& v) : _dim(v._dim), data(v.data) {
	for (std::size_t i = 0; i < v._dim; i++) {
		data[i] = v.data[i];
	}
}

vec::~vec() { delete[] data; }

double& vec::operator[](std::size_t index) { return data[index]; }

const double& vec::operator[](std::size_t index) const {
	return index < _dim ? data[index] : ZERO;
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

vec::operator double*() { return data; }

vec::operator const double*() const { return data; }

vec::operator double() const { return data[0]; }

const vec operator+(const vec& v1, const vec& v2) {
	vec result(v1.dim() > v2.dim() ? v1.dim() : v2.dim());
	for (std::size_t i = 0; i < v1.dim(); ++i) {
		result[i] = v1[i] + v2[i];
	}
	return result;
}

const vec operator-(const vec& v1, const vec& v2) {
	vec result(v1.dim());
	for (std::size_t i = 0; i < v1.dim(); ++i) {
		result[i] = v1[i] - v2[i];
	}
	return result;
}

const int operator*(const vec& v1, const vec& v2) {
	int result = 0;
	for (std::size_t i = 0; i < v1.dim(); ++i) {
		result += v1[i] * v2[i];
	}
	return result;
}

const vec operator*(const vec& v1, const double& v2) {
	vec result(v1.dim());
	for (std::size_t i = 0; i < v1.dim(); ++i) {
		result[i] = v1[i] * v2;
	}
	return result;
}

const vec operator*(const double& v1, const vec& v2) {
	vec result(v2.dim());
	for (std::size_t i = 0; i < v2.dim(); ++i) {
		result[i] = v1 * v2[i];
	}
	return result;
}

const vec operator^(const vec& v1, const vec& v2) {
	// limited to my math knowledge
	// I only know how to cross 3d Vectors
	// so I will limit it to 3d Vectors
	if (v1.dim() != 3 || v2.dim() != 3) {
		throw std::invalid_argument(
		    "cross product is only defined for 3d vectors");
	}
	vec result(3);
	result[0] = v1[1] * v2[2] - v1[2] * v2[1];
	result[1] = v1[2] * v2[0] - v1[0] * v2[2];
	result[2] = v1[0] * v2[1] - v1[1] * v2[0];
	return result;
}
