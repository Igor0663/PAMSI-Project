#include<algorithm>

template<typename T>
Vector<T>::Vector()
{
	Cap = 32;
	NoE = 0;
	this->array = new T[Cap];
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list)
{
	Cap = 32;
	NoE = 0;
	this->array = new T[Cap];
	for(auto it = list.begin(); it != list.end(); it++)
		this->push_back(*it);
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] this->array;
}

template<typename T>
T& Vector<T>::operator[](unsigned int index)
{
	return array[index];
}

template<typename T>
const T& Vector<T>::operator[](unsigned int index) const
{
	return array[index];
}

template<typename T>
void Vector<T>::resize(unsigned int newsize)
{
	Cap = newsize;
	T* tmp = new T[newsize];
	for(unsigned int i = 0;i < std::min(this->size(), newsize);i++)
		tmp[i] = this->array[i];
	delete[] this->array;
	this->array = tmp;
	this->NoE = std::min(this->size(), newsize);
	return;
}

template<typename T>
void Vector<T>::pop_back()
{
	if(this->NoE - 1 <= this->Cap * 25 / 100 && this->Cap >=64)		
		this->resize( this->Cap/2);
	this->NoE--;
	return;
}

template<typename T>
void Vector<T>::push_back(const T& NewElement)
{
	if(this->NoE+1 >= this->Cap)
		this->resize(2 * this->Cap);
	this->array[NoE] = NewElement;
	this->NoE++;
	return;
}

template<typename T>
void Vector<T>::clear()
{
	this->NoE = 0;
}

template<typename T>
void Vector<T>::shrink_to_fit()
{
	this->resize(NoE);
	return;
}
