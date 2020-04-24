template< typename T >
matrix<T>::matrix(unsigned int x, unsigned int y)
{
	this->M = std::vector<T>();
	M.resize( x * y, 0);
	this->row = x;
	this->col = y;
}

template< typename T >
T& matrix<T>::operator()(unsigned int x, unsigned int y)
{
	return this->M[x * row + y];
}

template< typename T >
const T& matrix<T>::operator()(unsigned int x, unsigned int y) const
{
	return this->M[x * row + y];
}
