/**
 * @file whatever.hpp
 * @brief a pure header vector and matrix library
 * 	  cause I don't know how to name it
 * 	  it is without template
 * @author werdxz ^v^ lwerdxzl@hotmail.com
 * @version 1.0.0
 * @date 2022-11-24
 */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*
	math synopsis
namespace resurgo
{

class vec{
public:
	vec(std::size_t size);

	template<typename T>
	vec(std::size_t size,T value);

	template<typename iter>
	vec(iter begin,iter end);

	template<typename iter>:ClangdTypeHierarchy
	vec(iter begin,std::size_t size);

	vec(const vec& other);

	vec(vec&& other);

	unsigned int size() const;

	inline std::size_t size() const;

	double& operator[](std::size_t index);

	const double& operator[](std::size_t index) const;
	
	vec& operator=(const vec& v);

	vec& operator=(vec&& v);
}


namespace opaerator{
	const vec operator+(const vec& v1,const vec& v2);
	const vec operator-(const vec& v1,const vec& v2);
	const int operator*(const vec& v1,const vec& v2);
	const vec operator*(const vec& v1,const double& v2);
	const vec operator*(const double& v1,const vec& v2);
	const vec operator^(const vec& v1,const vec& v2);

}

}
*/

#include <cmath>  //the only library needed
#include <utility>

namespace resurgo {

class vec {
       private:
	std::size_t _dim;
	double data[];

       public:
	vec(std::size_t size);

	template <typename T>
	vec(std::size_t size, T value);
	template <typename T>
	vec(std::initializer_list<T> list);

	template <typename iter>
	vec(iter begin, iter end);

	template <typename iter>
	vec(iter begin, std::size_t size);

	vec(const vec& v);

	vec(vec&& v);

	inline unsigned int length() const{return std::sqrt(dot(*this));}

	inline std::size_t dim() const{return _dim;}

	double& operator[](std::size_t index);

	const double& operator[](std::size_t index) const;
	
	vec& operator=(const vec& v);

	vec& operator=(vec&& v);

	private:
	int dot(const vec& v) const;

	vec cross(const vec& v) const;

};


namespace RSGoperator{
	const vec operator+(const vec& v1,const vec& v2);
	const vec operator-(const vec& v1,const vec& v2);
	const int operator*(const vec& v1,const vec& v2);
	const vec operator*(const vec& v1,const double& v2);
	const vec operator*(const double& v1,const vec& v2);
	const vec operator^(const vec& v1,const vec& v2);

}

}  // namespace resurgo

#endif
