#include"../inc/List.hh"

template< typename T >
void List<T>::push_back(const T& NewValue)
{
	Node<T>* temp = new Node<T>(nullptr, NewValue);
	if(this->empty())
		head = temp;
	else
		tail->setPtr(temp);
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
	Node<T>* temp = head->getPtr();
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
	while(curr->getPtr()!=nullptr)
	{
		prev = curr;
		curr = curr -> getPtr();
	}
	tail = prev;
	prev->setPtr(nullptr);
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
			curr = curr -> getPtr();
		}
		Node<T>* New = new Node<T>(curr, NewElement);
		prev->setPtr(New);
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
		return head->getValue();
		//DODAJ WYJATEK
	Node<T>* ptr = head;
	for(unsigned int i=0;i<ind;i++)
		ptr = ptr->getPtr();
	return ptr->getValue();
}

template< typename T>
const T& List<T>::operator[](unsigned int ind) const 
{
	if(ind>=this->size())
		return head->getValue();
		//DODAJ WYJATEK
	Node<T>* ptr = head;
	for(unsigned int i=0;i<ind;i++)
		ptr = ptr->getPtr();
	return ptr->getValue();
}
