
template< typename T>
bool Iterator<T>::operator!=(const Iterator& It) const
{
	return this->node != It.node;
}

template< typename T >
Iterator<T>& Iterator<T>::operator++()
{
	this->node = this->node->getPtr();
	return *this;
}

template< typename T >
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator<T> tmp = *this;
	this->node = this->node->next;
	return tmp;
}

template< typename T >
T& Iterator<T>::operator*() const
{
	return node->value;
}
template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& It)
{
	this-> node = It -> node;
	return *this;
}
