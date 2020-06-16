
template<typename T>
std::ostream& operator << (std::ostream& ostr, matrix<T> M)
{
	std::pair<unsigned int, unsigned int> dim = M.size();
	for(unsigned int i = 0; i < dim.first; i++)
	{
		for(unsigned int j = 0; j < dim.second; j++)
			ostr << M(i, j) << " ";
		ostr << "\n";
	}
	return ostr;
}

template<typename T>
matrix<T> operator + ( const matrix<T>& A, const matrix<T>& B)
{
	if(A.size() != B.size())
	{
		std::cerr <<"Dimensions don't match! Cannot add!";
		return A;
	}
	matrix<T> C(A.size().first, A.size().second);
	for(unsigned int i = 0; i < C.size().first; i++)
		for(unsigned int j = 0; j < C.size().second; j++)
			C(i,j) = A(i,j) + B(i,j);
	return C;
}

template<typename T>
matrix<T> operator - ( const matrix<T>& A, const matrix<T>& B)
{
	if(A.size() != B.size())
	{
		std::cerr <<"Dimensions don't match! Cannot subtract!";
		return A;
	}
	matrix<T> C(A.size().first, A.size().second);
	for(unsigned int i = 0; i < C.size().first; i++)
		for(unsigned int j = 0; j < C.size().second; j++)
			C(i,j) = A(i,j) - B(i,j);
	return C;
}

template<typename T>
matrix<T> operator * ( const matrix<T>& A, const matrix<T>& B)
{
	if(A.size().second != B.size().first)
	{
		std::cerr <<"Dimensions don't match! Cannot mulitiply!";
		return A;
	}
	matrix<T> C(A.size().first, B.size().second);
	for(unsigned int i = 0; i < C.size().first; i++)
		for(unsigned int j = 0; j < C.size().second; j++)
			for(unsigned int k = 0; k < A.size().second; k++)
				C(i,j) += A(i,k) * B(k, j);
	return C;
}

template<typename T>
void matrix<T>::resize(unsigned int rows, unsigned int cols)
{
	matrix<T> temp = *this;
	this->M.resize(rows * cols, (T)(0));
	this->rows = rows;
	this->cols = cols;
	for(unsigned int i = 0; i < rows;  i++)
		for(unsigned int j = 0; j < cols;  j++)
			if(i < std::min(rows, temp.size().first) and j < std::min(cols, temp.size().second) )
				(*this)(i, j) = temp(i, j);
			else
				(*this)(i,j) = (T)(0);
	return;
}
