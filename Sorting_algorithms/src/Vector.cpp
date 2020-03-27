#include<algorithm>
#include<iostream>
#include<exception>

template<typename T>
Vector<T>::Vector()
{
	Cap = 32;
	NoE = 0;
	this->array = new T[Cap];
}

template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& list)
{
	Cap = 32;
	NoE = 0;
	this->array = new T[Cap];
	for(auto it = list.begin(); it != list.end(); it++)
		this->push_back(*it);
}
template<typename T>
Vector<T>::Vector(const Vector<int>& NewVec)
{
	this->Cap = NewVec.Cap;
	this->NoE = NewVec.NoE;
	this->array = new T[Cap];
	for(unsigned int i = 0; i < NewVec.size();i++)
		this->array[i] = NewVec[i];
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] this->array;
}

template<typename T>
T& Vector<T>::operator[](unsigned int index)
{
	try
	{
		if(index >= this->NoE)
			throw std::out_of_range("Operator []. Index too large.");
		return array[index];
	}
	catch(std::out_of_range& oor)
	{
		std::cerr << "Vector out of range error: " << oor.what() << "\n";
		exit(1);
	}
}

template<typename T>
const T& Vector<T>::operator[](unsigned int index) const
{
	try
	{
		if(index >= this->NoE)
			throw std::out_of_range("Operator []. Index too large.");
		return array[index];
	}
	catch(std::out_of_range& oor)
	{
		std::cerr << "Vector out of range error: " << oor.what() << "\n";
		exit(1);
	}
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
	try
	{
		if(NoE == 0)
			throw std::range_error("Trying to pop empty Vector");
		if(this->NoE - 1 <= this->Cap * 25 / 100 && this->Cap >=64)		
			this->resize( this->Cap/2);
		this->NoE--;
		return;
	}
	catch (std::range_error& oor)
	{
		std::cerr << "Vector range error: " << oor.what() << "\n";
		exit(2);
	}
}

template<typename T>
void Vector<T>::push_back(const T& NewElement)
{
	if(this->NoE+1 >= this->Cap)
		this->resize(std::max(2 * this->Cap, (unsigned int)(1)));
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
