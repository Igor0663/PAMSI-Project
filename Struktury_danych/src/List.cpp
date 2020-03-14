#include"../inc/List.hh"

template< typename T >
void List<T>::push_back(const T& NewValue)
{
	Node<T>* temp = new Node<T>(nullptr, NewValue);
	if(this->empty())
		head = temp;
	else
		tail->next = temp;
	tail = temp;
	this->NoE++;
	return;
}


template< typename T >
void List<T>::push_front(const T& NewValue)
{
	Node<T>* temp = new Node<T>(head, NewValue);
	if(this->empty())
		tail = temp;
	head = temp;
	this->NoE++;
	return;
}
template< typename T >
void List<T>::pop_front()
{
	if(this->empty())
		return;
	Node<T>* temp = head->next;
	delete head;
	head = temp;
	if(this->empty())
		tail = nullptr;
	this->NoE--;
	return;
}
template< typename T >
void List<T>::pop_back()
{
	if(this->empty())
		return;
	Node<T>* curr = head;
	Node<T>* prev = nullptr;
	while(curr->next != nullptr)
	{
		prev = curr;
		curr = curr -> next;
	}
	tail = prev;
	prev->next = nullptr;
	delete curr;
	NoE--;
	return;
}
template<typename T>
void List<T>::insert(const T& NewElement, unsigned int index)
{
	if(index == 0)
		this->push_front(NewElement);
	else if(index == this->size())
		this->push_back(NewElement);
	else if(index > this->size())
		return;//DODAJ WYJATEK
	else
	{
		Node<T>* curr = head;
		Node<T>* prev = nullptr;
		for(unsigned int i = 0;i < index;i++)
		{
			prev = curr;
			curr = curr -> next;
		}
		Node<T>* New = new Node<T>(curr, NewElement);
		prev->next = New;
		NoE++;
		return;
	}
}

template< typename T >
List<T>::~List<T>()
{
	while(!this->empty())
		this->pop_front();
}
template< typename T>
T& List<T>::operator[](unsigned int ind)
{
	if(ind>=this->size())
		return head->value;
		//DODAJ WYJATEK
	Node<T>* ptr = head;
	for(unsigned int i=0;i<ind;i++)
		ptr = ptr->next;
	return ptr->value;
}

template< typename T>
const T& List<T>::operator[](unsigned int ind) const 
{
	if(ind>=this->size())
		return head->value;
		//DODAJ WYJATEK
	Node<T>* ptr = head;
	for(unsigned int i=0;i<ind;i++)
		ptr = ptr->next;
	return ptr->value;
}

template< typename T>
Iterator<T> List<T>::begin()
{
	return Iterator<T>(this->head);
}
template< typename T>
Iterator<T> List<T>::end()
{
	return Iterator<T>(nullptr);
}

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
T Iterator<T>::operator*() const
{
	return node->value;
}
template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& It)
{
	this-> node = It -> node;
	return *this;
}
