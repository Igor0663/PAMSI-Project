#ifndef MATRIX_HH
#define MATRIX_HH
#include<vector>

template< typename T>
struct matrix
{
		matrix(unsigned int x = 1, unsigned int y = 1);
		T& operator()(unsigned int x, unsigned int y);
		const T& operator()(unsigned int x, unsigned int y) const;
	private:
		unsigned int row, col;
		std::vector<T> M;
};

#include"../src/Matrix.cpp"

#endif
