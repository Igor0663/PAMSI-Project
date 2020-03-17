#include"../inc/List.hh"
#include<stdexcept>
#include<iostream>

template< typename T >
void List<T>::push_back(const T& NewValue)
{
	List<T>::Node* temp = new List<T>::Node(nullptr, NewValue);
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
	List<T>::Node* temp = new List<T>::Node(head, NewValue);
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
	List<T>::Node* temp = head->next;
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
	List<T>::Node* curr = head;
	List<T>::Node* prev = nullptr;
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
	try
	{
		if(index == 0)
			this->push_front(NewElement);
		else if(index == this->size())
			this->push_back(NewElement);
		else if(index > this->size())
		{
			throw std::out_of_range("Insert method. Index too large!");
			return;
		} 
		else
		{
			List<T>::Node* curr = head;
			List<T>::Node* prev = nullptr;
			for(unsigned int i = 0;i < index;i++)
			{
				prev = curr;
				curr = curr -> next;
			}
			List<T>::Node* New = new List<T>::Node(curr, NewElement);
			prev->next = New;
			NoE++;
			return;
		}
	}
	catch(std::out_of_range& oor)
	{
		std::cerr << "List index out of range: " << oor.what() << "\n";
		exit(1);
	}
}
template<typename T>
List<T>::List(const List<T>& list)
{
	head = nullptr;
	tail = nullptr;
	NoE = 0;
	for(auto it = list.cbegin();it!=list.cend();it++)
		this->push_back(*it);
}

template<typename T>
List<T>::List(std::initializer_list<T> list)
{
	head = nullptr;
	tail = nullptr;
	NoE = 0;
	for(auto it = list.begin();it!=list.end();it++)
		this->push_back(*it);
}

template< typename T >
List<T>::~List()
{
	while(!this->empty())
		this->pop_front();
}
template< typename T>
T& List<T>::operator[](unsigned int ind)
{
	try
	{
		if(ind>=this->size())
			throw std::out_of_range("Operator[]. Index too large!");
	}
	catch(std::out_of_range& oor)
	{
		std::cerr << "List index out of range: " << oor.what() << "\n";
		exit(1);
	}
	List<T>::iterator ptr = this->begin();
	for(unsigned int i=0;i<ind;i++)
		ptr++;
	return *ptr;
}

template< typename T>
const T& List<T>::operator[](unsigned int ind) const 
{
	try
	{
		if(ind>=this->size())
			throw std::out_of_range("Operator[]. Index too large!");
	}
	catch(std::out_of_range& oor)
	{
		std::cerr << "List index out of range: " << oor.what() << "\n";
		exit(1);
	}
	List<T>::const_iterator ptr = this->cbegin();
	for(unsigned int i=0;i<ind;i++)
		ptr++;
	return *ptr;
}

template< typename T>
void List<T>::remove(const T& NewElement)
{
	List<T>::Node* curr;
	List<T>::Node* prev;
	
	while(!(this->empty()) && (*this)[0] == NewElement)
		this->pop_front();
	
	curr = head;
	prev = nullptr;

	while(curr != nullptr)
	{
		if(curr->value == NewElement)
		{
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
			continue;
		}
		prev = curr;
		curr = curr->next;
	}
	return;
}
