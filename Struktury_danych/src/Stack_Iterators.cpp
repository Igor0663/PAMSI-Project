
template< typename T>
bool Stack<T>::iterator::operator!=(const Stack<T>::iterator& It) const
{
	return this->node != It.node;
}

template< typename T >
typename Stack<T>::iterator& Stack<T>::iterator::operator++()
{
	this->node = this->node->next;
	return *this;
}

template< typename T >
typename Stack<T>::iterator Stack<T>::iterator::operator++(int)
{
	Stack<T>::iterator tmp = *this;
	this->node = this->node->next;
	return tmp;
}

template< typename T >
T& Stack<T>::iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename Stack<T>::iterator& Stack<T>::iterator::operator=(const Stack<T>::iterator& It)
{
	this-> node = It -> node;
	return *this;
}






template< typename T>
bool Stack<T>::const_iterator::operator!=(const Stack<T>::const_iterator& It) const
{
	return this->node != It.node;
}


template< typename T >
typename Stack<T>::const_iterator& Stack<T>::const_iterator::operator++()
{
	this->node = this->node->next;
	return *this;
}

template< typename T >
typename Stack<T>::const_iterator Stack<T>::const_iterator::operator++(int)
{
	Stack<T>::const_iterator tmp = *this;
	this->node = this->node->next;
	return tmp;
}

template< typename T >
const T& Stack<T>::const_iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename Stack<T>::const_iterator& Stack<T>::const_iterator::operator=(const Stack<T>::const_iterator& It)
{
	this-> node = It -> node;
	return *this;
}
