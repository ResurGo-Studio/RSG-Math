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

#include <cmath> //the only library needed


namespace resurgo{
	
	// vec
	class vec{
		public:
			/**
			 * @brief init options for a new vector, eg:
			 * 		v  : vector
			 * 		*D : * dimension
			 * 	the last letter is the initial value
			 */
			enum class init{vec2DN,vec2D0, vec2D01, vec3DN, vec3D0, vec3D1, vec4DN, vec4D0, vec4D1, vec0};

			/**
			 * @brief Construct a new vec object with options
			 *
			 * @param opt options
			 */
			vec(const init opt = init::vec0);

			/**
			 * @brief Destroy the vec object
			 */
			~vec();

			/**
			 * @brief Construct a new vec object
			 *
			 * @param dim - dimension of the vector
			 */
			vec(const int dim);

			/**
			 * @brief Construct a new vec object with dimension and as int value with a double array
			 *
			 * @param dim - dimension of the vector
			 * @param data - the data of the vector
			 */
			vec(const int dim, const double* data);

			/**
			 * @brief Construct a new vec object with dimension and as int value with a float array
			 *
			 * @param dim - dimension of the vector
			 * @param data - the data of the vector
			 */
			vec(const int dim, const float* data);

			/**
			 * @brief Construct a new vec object with dimension and as int value with a int array
			 *
			 * @param dim - dimension of the vector
			 * @param data - the data of the vector
			 */
			vec(const int dim, const int* data);

			/**
			 * @brief A shortcut to generate a 3d vector
			 *
			 * @param x - x value
			 * @param y - y value
			 * @param z - z value
			 */
			vec(const double x, const double y, const double z);

			/**
			 * @brief A shortcut to generate a 2d vector
			 *
			 * @param x - x value
			 * @param y - y value
			 */

			vec(const double x, const double y);

			/**
			 * @brief A shortcut to generate a 3d vector with int value
			 *
			 * @param x - x value
			 * @param y - y value
			 * @param z - z value
			 */
			vec(const int x, const int y, const int z);

			/**
			 * @brief A shortcut to generate a 2d vector with int value
			 *
			 * @param x - x value
			 * @param y - y value
			 */
			vec(const int x, const int y);


			/**
			 * @brief copy another vec
			 *
			 * @param v - the vec to be copied
			 */
			vec(const vec& v);

			/**
			 * @brief Construct a new vec object with dimension and as int value with a float array
			 *
			 * @return the pointer of the array
			 */
			const inline double* get() const{return data;};

			/**
			 * @brief the = operator for vec to assign a vec as int data
			 *
			 * @param data - the data of the vector
			 */
			void operator= (const int* data);

			/**
			 * @brief the = operator for vec to assign a vec as float data
			 *
			 * @param data - the data of the vector
			 */
			void operator= (const float* data);

			/**
			 * @brief the = operator for vec to assign a vec as double data
			 *
			 * @param data - the data of the vector
			 */
			void operator= (const double* data);

			/**
			 * @brief the [] operator for vec to get the data of the vector
			 *
			 * @param index
			 *
			 * @return the index as double
			 */
			const inline double& operator[] (const int index) const{index>=dim?throw "index out of range":0;return data[index];};

			/**
			 * @brief the cross product of two vec
			 *
			 * @param v - the other vec
			 *
			 * @return the cross product of two vec
			 */
			vec cross(vec v);

			/**
			 * @brief the dot product of two vec
			 *
			 * @param v - the other vec
			 *
			 * @return the dot product of two vec
			 */
			double dot(vec v);

			/**
			 * @brief + operator for vec to add a vec
			 *
			 * @param v - the other vec
			 *
			 * @return the result of the addition
			 */
			vec operator+ (vec v);

			/**
			 * @brief - operator for vec to subtract a vec
			 *
			 * @param v - the other vec
			 *
			 * @return the result of the subtraction
			 */
			vec operator- (vec v);

			/**
			 * @brief * operator for vec to multiply a double
			 *
			 * @param d
			 *
			 * @return 
			 */
			vec operator* (double d);

			/**
			 * @brief get the length(dimension) of the vec
			 *
			 * @return the length of the vec
			 */
			const inline int getDim() const {return dim;}

			/**
			 * @brief get the length of the vec
			 *
			 * @return the length of the vec
			 */
			const inline double length() const {double sum = 0; for(int i = 0; i < dim; i++) sum += data[i] * data[i]; return sqrt(sum);}

		private:
			int dim;
			double* data;
			bool useAsteriskAsCross = true;
	};

	class mat{
		public:
			/**
			 * @brief init option for a mat:
			 */
			enum class init{mat0, mat1, mat4D0, mat4DN, matI4D};
			/**
			 * @brief  option for a mat, used with a vector
			 */
			enum class option{Scaling,Rotation,Translation};

			/**
			 * @brief Construct a new mat object init option
			 *
			 * @param initOption - the init option
			 */
			mat(const init initOption=init::mat0);

			/**
			 * @brief Construct a new mat object with option and vec
			 *
			 * @param opt
			 * @param v
			 */
			mat(const option opt, const vec& v);
			/**
			 * @brief Construct a new mat object
			 *
			 * @param row - row of the matrix
			 * @param col - column of the matrix
			 */
			mat(const int row, const int col);

			/**
			 * @brief Construct a new mat object with row and col and as int value
			 *
			 * @param row - row of the matrix
			 * @param col - column of the matrix
			 * @param as_int - if true, the matrix will be outputted as int
			 */
			mat(const int row, const int col, const bool as_int);

			/**
			 * @brief Construct a new mat object with row and col and as int value with a double array
			 *
			 * @param row - row of the matrix
			 * @param col - column of the matrix
			 * @param data - the data of the matrix
			 */
			mat(const int row, const int col, const double** data);

			/**
			 * @brief Construct a new mat object with row and col and as int value with a int array
			 *
			 * @param row - row of the matrix
			 * @param col - column of the matrix
			 * @param data - the data of the matrix
			 */
			mat(const int row, const int col, const int** data);

			/**
			 * @brief Construct a new mat object with row n col
			 *
			 * @param rowNcol - row and column of the matrix
			 */
			mat(const int rowNcol);

			/**
			 * @brief Construct a new mat object with row n col and as int value
			 *
			 * @param rowNcol - row and column of the matrix
			 * @param as_int - if true, the matrix will be outputted as int
			 */
			mat(const int rowNcol, const bool as_int);

			/**
			 * @brief Construct a new mat object with row n col as same number and as int value with a double array
			 *
			 * @param rowNcol - row and column of the matrix
			 * @param data - the data of the matrix
			 */
			mat(const int rowNcol, const double** data);

			/**
			 * @brief Construct a new mat object with row n col as same number and as int value with a int array
			 *
			 * @param rowNcol - row and column of the matrix
			 * @param data - the data of the matrix
			 */
			mat(const int rowNcol, const int** data);

			/**
			 * @brief Construct a new mat object with row and col and as int value with a float array
			 *
			 * @return the pointer of the array
			 */
			void* get();

			/**
			 * @brief the = operator for mat to assign a mat as int data
			 *
			 * @param data - the data of the matrix
			 */
			void operator= (const int** data);

			/**
			 * @brief the = operator for mat to assign a mat as double data
			 *
			 * @param data - the data of the matrix
			 */
			void operator= (const double** data);

			/**
			 * @brief the [] operator for mat to get the data of the matrix
			 *
			 * @param index
			 *
			 * @return a wild pointer of the index
			 */
			void* operator[] (const int index);

			const inline int getRow() const { return row; }
			const inline int getCol() const { return col; }
			const inline bool getAsInt() const { return as_int; }
		private:
			int row;
			int col;
			bool as_int;
			vec* data;
	};

	vec operator* (mat m, vec v);
	vec operator* (vec v, mat m);
}

class temp{
	public:
		temp(int a, int *b){};
		~temp();
		void print();
	private:
};

#endif
