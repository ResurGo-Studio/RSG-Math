#include "resurgo/math.hpp"

using namespace resurgo;

vec::vec(const init opt):dim(0),data(nullptr){
	switch(opt){
		case init::vec2DN:
			this->dim = 2;
			this->data = new double[2];
			this->data[0] = NAN;
			this->data[1] = NAN;
			break;
		case init::vec2D0:
			this->dim = 2;
			this->data = new double[2];
			this->data[0] = 0;
			this->data[1] = 0;
			break;
		case init::vec2D01:
			this->dim = 2;
			this->data = new double[2];
			this->data[0] = 1;
			this->data[1] = 1;
			break;
		case init::vec3DN:
			this->dim = 3;
			this->data = new double[3];
			this->data[0] = NAN;
			this->data[1] = NAN;
			this->data[2] = NAN;
			break;
		case init::vec3D0:
			this->dim = 3;
			this->data = new double[3];
			this->data[0] = 0;
			this->data[1] = 0;
			this->data[2] = 0;
			break;
		case init::vec3D1:
			this->dim = 3;
			this->data = new double[3];
			this->data[0] = 1;
			this->data[1] = 1;
			this->data[2] = 1;
			break;
		case init::vec4DN:
			this->dim = 4;
			this->data = new double[4];
			this->data[0] = NAN;
			this->data[1] = NAN;
			this->data[2] = NAN;
			this->data[3] = NAN;
			break;
		case init::vec4D0:
			this->dim = 4;
			this->data = new double[4];
			this->data[0] = 0;
			this->data[1] = 0;
			this->data[2] = 0;
			this->data[3] = 0;
			break;
		case init::vec4D1:
			this->dim = 4;
			this->data = new double[4];
			this->data[0] = 1;
			this->data[1] = 1;
			this->data[2] = 1;
			this->data[3] = 1;
			break;
		case init::vec0:
			this->dim = 0;
			this->data = nullptr;
			break;
		}
}

vec::~vec(){
	if(this->data != nullptr){
		delete[] this->data;
	}
}

vec::vec(const int dim):dim(dim),data(nullptr){
	if(dim > 0){
		this->data = new double[dim];
		for(int i = 0; i < dim; i++){
			this->data[i] = 0;
		}
	}
}

vec::vec(const int dim, const double* data):dim(dim),data(nullptr){
	if(dim > 0){
		this->data = new double[dim];
		for(int i = 0; i < dim; i++){
			this->data[i] = data[i];
		}
	}
}


vec::vec(const int dim, const float* data):dim(dim),data(nullptr){
	if(dim > 0){
		this->data = new double[dim];
		for(int i = 0; i < dim; i++){
			this->data[i] = data[i];
		}
	}
}

vec::vec(const int dim, const int* data):dim(dim),data(nullptr){
	if(dim > 0){
		this->data = new double[dim];
		for(int i = 0; i < dim; i++){
			this->data[i] = data[i];
		}
	}
}

vec::vec(const double x, const double y, const double z):dim(3),data(nullptr){
	this->data = new double[3];
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
}

vec::vec(const double x, const double y):dim(2),data(nullptr){
	this->data = new double[2];
	this->data[0] = x;
	this->data[1] = y;
}


vec::vec(const int x, const int y, const int z):dim(3),data(nullptr){
	this->data = new double[3];
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
}

vec::vec(const int x, const int y):dim(2),data(nullptr){
	this->data = new double[2];
	this->data[0] = x;
	this->data[1] = y;
}

vec::vec(const vec& v):dim(v.dim),data(nullptr){
	if(v.dim > 0){
		this->data = new double[v.dim];
		for(int i = 0; i < v.dim; i++){
			this->data[i] = v.data[i];
		}
	}
}

void vec::operator= (const int* data){
	if(this->dim > 0){
		for(int i = 0; i < this->dim; i++){
			this->data[i] = data[i];
		}
	}
}

void vec::operator= (const float* data){
	if(this->dim > 0){
		for(int i = 0; i < this->dim; i++){
			this->data[i] = data[i];
		}
	}
}

void vec::operator= (const double* data){
	if(this->dim > 0){
		for(int i = 0; i < this->dim; i++){
			this->data[i] = data[i];
		}
	}
}


vec vec::cross(vec v){
	if(this->dim == 3 && v.dim == 3){
		vec result(3);
		result.data[0] = this->data[1] * v.data[2] - this->data[2] * v.data[1];
		result.data[1] = this->data[2] * v.data[0] - this->data[0] * v.data[2];
		result.data[2] = this->data[0] * v.data[1] - this->data[1] * v.data[0];
		return result;
	}
	else{
		return vec(options::vec3DN);
	}
}

double vec::dot(vec v){
	if(this->dim == v.dim){
		double result = 0;
		for(int i = 0; i < this->dim; i++){
			result += this->data[i] * v.data[i];
		}
		return result;
	}
	else{
		return NAN;
	}
}

