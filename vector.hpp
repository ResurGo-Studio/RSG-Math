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
 * \~english open compile time and runtime warnings for vectors(make it strict :P ).
 * \~chinese �����Լ�����ʱ ���ж���vectors�ľ��� (Ϊ��ʹ����ϸ��� )
 *
 * \~english this is a macro that will throw exception when you trying to do something
 * \~chinese ����һ�����㳢��ִ��һЩ����ʱ�ᷢ���쳣�ĺ�
 * \~english that are not allowed such as doing operations with vectors with different dimentions.
 * \~chinese ����Բ�ͬά�ȵ�vector���в��������ǲ������
 * \~english if this macro is defined, it will include <cassert> and <cexeptions>
 * \~chinese �������걻������ , ��������<cassert>��<cexeptions>
 * 
 * @note 
 * \~english undefine it to disable it
 * \~chinese ����ȡ�������Ķ�����������
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
	 * \~english a vector class
	 * \~chinese һ��vector��
	 */
class vec {
       private:
	std::size_t _dim;
	double* data;

       public:
	/**
	 * @brief 
	 * \~english Construct a new vec object
	 * \~chinese ����һ���µ�vec����
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
