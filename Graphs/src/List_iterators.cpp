template< typename T>
bool List<T>::iterator::operator!=(const List<T>::iterator& It) const
{
	return this->node != It.node;
}

template< typename T >
typename List<T>::iterator& List<T>::iterator::operator++()
{
	this->node = this->node->next;
	return *this;
}

template< typename T >
typename List<T>::iterator List<T>::iterator::operator++(int)
{
	List<T>::iterator tmp = *this;
	this->node = this->node->next;
	return tmp;
}

template< typename T >
T& List<T>::iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename List<T>::iterator& List<T>::iterator::operator=(const List<T>::iterator& It)
{
	this-> node = It -> node;
	return *this;
}






template< typename T>
bool List<T>::const_iterator::operator!=(const List<T>::const_iterator& It) const
{
	return this->node != It.node;
}


template< typename T >
typename List<T>::const_iterator& List<T>::const_iterator::operator++()
{
	this->node = this->node->next;
	return *this;
}

template< typename T >
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
	List<T>::const_iterator tmp = *this;
	this->node = this->node->next;
	return tmp;
}

template< typename T >
const T& List<T>::const_iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator=(const List<T>::const_iterator& It)
{
	this-> node = It -> node;
	return *this;
}







template< typename T>
bool List<T>::reverse_iterator::operator!=(const List<T>::reverse_iterator& It) const
{
	return this->node != It.node;
}

template< typename T >
typename List<T>::reverse_iterator& List<T>::reverse_iterator::operator++()
{
	this->node = this->node->prev;
	return *this;
}

template< typename T >
typename List<T>::reverse_iterator List<T>::reverse_iterator::operator++(int)
{
	List<T>::reverse_iterator tmp = *this;
	this->node = this->node->prev;
	return tmp;
}

template< typename T >
T& List<T>::reverse_iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename List<T>::reverse_iterator& List<T>::reverse_iterator::operator=(const List<T>::reverse_iterator& It)
{
	this-> node = It -> node;
	return *this;
}






template< typename T>
bool List<T>::const_reverse_iterator::operator!=(const List<T>::const_reverse_iterator& It) const
{
	return this->node != It.node;
}


template< typename T >
typename List<T>::const_reverse_iterator& List<T>::const_reverse_iterator::operator++()
{
	this->node = this->node->prev;
	return *this;
}

template< typename T >
typename List<T>::const_reverse_iterator List<T>::const_reverse_iterator::operator++(int)
{
	List<T>::const_reverse_iterator tmp = *this;
	this->node = this->node->prev;
	return tmp;
}

template< typename T >
const T& List<T>::const_reverse_iterator::operator*() const
{
	return node->value;
}
template<typename T>
typename List<T>::const_reverse_iterator& List<T>::const_reverse_iterator::operator=(const List<T>::const_reverse_iterator& It)
{
	this-> node = It -> node;
	return *this;
}
