#ifndef RSG_MATRIX_HPP
#define RSG_MATRIX_HPP

#include <cmath>
#include <initializer_list>
#include <stdexcept>

#include "consts.hpp"
#include "vector.hpp"
namespace resurgo {
class mat {
       private:
	std::size_t _dim;

	vec* data;

       public:
	enum class option { identity, zero };

	mat(std::size_t dim, int width = -1, option opt = option::zero);

	mat(std::initializer_list<vec> list);

	mat(const mat& other);

	mat(mat&& other);

	~mat();

};
}  // namespace resurgo
#endif
