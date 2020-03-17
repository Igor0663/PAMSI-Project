
template< typename T>
bool Queue<T>::iterator::operator!=(const Queue<T>::iterator& It) const
{
	return this->node != It.node;
}

template< typename T >
typename Queue<T>::iterator& Queue<T>::iterator::operator++()
{
	this->node = this->node->next;
	return *this;
}

template< typename T >
typename Queue<T>::iterator Queue<T>::iterator::operator++(int)
{
	Queue<T>::iterator tmp = *this;
	this->node = this->node->next;
	return tmp;
}

template< typename T >
T& Queue<T>::iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename Queue<T>::iterator& Queue<T>::iterator::operator=(const Queue<T>::iterator& It)
{
	this-> node = It -> node;
	return *this;
}






template< typename T>
bool Queue<T>::const_iterator::operator!=(const Queue<T>::const_iterator& It) const
{
	return this->node != It.node;
}


template< typename T >
typename Queue<T>::const_iterator& Queue<T>::const_iterator::operator++()
{
	this->node = this->node->next;
	return *this;
}

template< typename T >
typename Queue<T>::const_iterator Queue<T>::const_iterator::operator++(int)
{
	Queue<T>::const_iterator tmp = *this;
	this->node = this->node->next;
	return tmp;
}

template< typename T >
const T& Queue<T>::const_iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename Queue<T>::const_iterator& Queue<T>::const_iterator::operator=(const Queue<T>::const_iterator& It)
{
	this-> node = It -> node;
	return *this;
}
