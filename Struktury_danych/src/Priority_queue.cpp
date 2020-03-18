#include<algorithm>
#include<exception>
#include<iostream>

template<typename T>
Priority_queue<T>::~Priority_queue()
{
	delete heap;
}
template<typename T>
Priority_queue<T>::Priority_queue(const Priority_queue& Pqueue)
{
	heap = new Vector<T>();
	for(unsigned int i = 0; i < Pqueue.size();i++)
		this->heap->push_back((*Pqueue.heap)[i]);
}

template<typename T>
void Priority_queue<T>::push(const T& NewElement)
{
	this->heap->push_back(NewElement);
	unsigned int index = this->heap->size() - 1;
	while(true)
	{
		if(index == 0)
			break;
		if((*this->heap)[index] <= (*this->heap)[(index + 1)/2 - 1])
			break;
		std::swap((*this->heap)[(index+1)/2 - 1], (*this->heap)[index]);
		index = (index + 1)/2 - 1;
	}
	return;
}

template<typename T>
const T& Priority_queue<T>::top() const
{
	try
	{
	if(this->empty())
		throw std::range_error("Trying to get top value of empty queue");
	return (*this->heap)[0];
	}
	catch (std::range_error& oor)
	{
		std::cerr << "Priority queue range error: " << oor.what() << "\n";
		exit(2);
	}
}

template<typename T>
T Priority_queue<T>::pop()
{
	try
	{
		if(this->empty())
			throw std::range_error("Trying to pop empty queue");
	}
	catch (std::range_error& oor)
	{
		std::cerr << "Priority queue range error: " << oor.what() << "\n";
		exit(2);
	}
	T top_value = (*this->heap)[0];
	std::swap((*this->heap)[0], (*this->heap)[this->size() -1]);
	this->heap->pop_back();
	unsigned int index = 0;
	bool left_exists = false;
	bool right_exists = false;
	T l_value = top_value;
	T r_value = top_value;
	while(true)
	{
		if(2*( index + 1 ) - 1 >= this->size())
			left_exists = false;
		else
		{
			left_exists = true;
			l_value = (*this->heap)[2*(index + 1) - 1];
		}
		if(2*(index + 1) >= this->size())
			right_exists = false;
		else
		{
			right_exists = true;
			r_value = (*this->heap)[2*(index + 1)];
		}
		if( !(left_exists || right_exists) )
			break;
		if(!right_exists)
		{
			if( l_value > (*this->heap)[index])
			{
				std::swap((*this->heap)[2*(index + 1) -1],  (*this->heap)[index]);
				index = 2*(index + 1) - 1;
				continue;
			}
			else
				break;
		}
		if( std::max(l_value, r_value) <= (*this->heap)[index])
			break;
		if( l_value >= r_value )
		{
			std::swap((*this->heap)[2*(index + 1) -1],  (*this->heap)[index]);
			index = 2*(index + 1) - 1;
			continue;
		}
		else
		{
			std::swap((*this->heap)[2*(index + 1)],  (*this->heap)[index]);
			index = 2*(index + 1);
			continue;
		}

	}

	return top_value;
}
