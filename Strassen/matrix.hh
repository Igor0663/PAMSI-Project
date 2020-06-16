#ifndef MATRIX_HH
#define MATRIX_HH
#include<vector>

template<typename T>
class matrix
{
	unsigned int rows, cols;
	std::vector<T> M;
	public:
		matrix(unsigned int rows = 1, unsigned int cols = 1): rows(rows), cols(cols){this->M.resize(rows * cols, (T)(0)); }
		T& operator()(unsigned int i, unsigned int j) {return this->M[i*cols + j]; }
		const T& operator()(unsigned int i, unsigned int j) const {return this->M[i*cols + j]; }
		std::pair<unsigned int, unsigned int> size() const {return {this->rows,this->cols}; }
		void resize(unsigned int row, unsigned int cols);	
};

#include"matrix.cpp"


#endif
