/**
 * @file vector.hpp
 * @brief 
 * @author werdxz ^v^ lwerdxzl@hotmail.com
 * @version 1.0.0
 * @date 2022-11-24
 */

#ifndef RSG_VECTOR_HPP
#define RSG_VECTOR_HPP

/**
 * @brief 
 * \~English open compile time and runtime warnings for vectors(make it strict :P ).
 * \~Chinese 编译以及运行时 进行对于vectors的警告 (为了使其更严格（雾 )
 *
 * \~English this is a macro that will throw exception when you trying to do something
 * \~Chinese 这是一个在你尝试执行一些操作时会产生异常的宏
 * \~English that are not allowed such as doing operations with vectors with different dimentions.
 * \~Chinese 比如对不同维度的vector进行操作，这是不允许的
 * \~English if this macro is defined, it will include <cassert> and <cexeptions>
 * \~Chinese 如果这个宏被定义了 , 他将引用<cassert>和<cexeptions>
 * 
 * @note 
 * \~English undefine it to disable it
 * \~Chinese 可以取消对他的定义来禁用他
 */
#define RSG_VECTOR_STRICT

#ifdef RSG_VECTOR_STRICT
#define A
#endif

#include <cmath>
#include <initializer_list>
#include <stdexcept>

#include "consts.hpp"

namespace resurgo {

	/**
	 * @brief 
	 * \~English a vector class
	 * \~Chinese 一个 vector 类
	 */
class vec {
       private:
	std::size_t _dim;
	double* data;

       public:
	/**
	 * @brief 
	 * \~English Construct a new vec object
	 * \~Chinese 创建一个新的 vec 对象
	 *
	 * @param size
	 */
	vec(std::size_t size);

	vec(std::size_t size, std::initializer_list<int> list);

	vec(std::size_t size, std::initializer_list<double> list);

	template <typename T>
	vec(std::size_t size, T value);

	vec(std::initializer_list<int> list);

	vec(std::initializer_list<double> list);

	template <typename iter>
	vec(iter begin, iter end);

	template <typename iter>
	vec(iter begin, std::size_t size);

	vec(const vec& v);

	vec(vec&& v);

	~vec();

	inline unsigned int length() const { return std::sqrt(dot(*this)); }

	inline std::size_t dim() const { return _dim; }

	double& operator[](std::size_t index);

	const double& operator[](std::size_t index) const;

	vec& operator=(const vec& v);

	vec& operator=(vec&& v);

	operator double() const;

	operator double*();

	operator const double*() const;

       private:
	int dot(const vec& v) const;

	vec cross(const vec& v) const;
};

const vec operator+(const vec& v1, const vec& v2);
const vec operator-(const vec& v1, const vec& v2);
const int operator*(const vec& v1, const vec& v2);
const vec operator*(const vec& v1, const double& v2);
const vec operator*(const double& v1, const vec& v2);
const vec operator^(const vec& v1, const vec& v2);

}  // namespace resurgo

#endif
