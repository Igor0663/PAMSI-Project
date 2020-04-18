#include"../inc/List.hh"
#include<stdexcept>
#include<iostream>


template< typename T >
void List<T>::push_back(const T& NewValue)
{
	List<T>::Node* temp = new List<T>::Node(tail, nullptr, NewValue);
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
	List<T>::Node* temp = new List<T>::Node(nullptr, head, NewValue);
	if(this->empty())
		tail = temp;
	else
		head->prev = temp;
	head = temp;
	this->NoE++;
	return;
}

template< typename T >
void List<T>::pop_back()
{
	Node* tmp = tail;
	if(this->size() == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail->prev->next = nullptr;
		tail = tail->prev;
	}
	delete tmp;
	this->NoE--;
	return;
}

template< typename T >
void List<T>::pop_front()
{
	if(this->size() == 1)
	{
		this->pop_back();
		return;
	}
	Node* temp = head;
	head->next->prev = nullptr;
	head = head->next;
	delete temp;
	this->NoE--;
	return;
}

template< typename T >
List<T>::~List()
{
	while(!this->empty())
		this->pop_front();
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
List<T>::List( const std::initializer_list<T>& list)
{
	head = nullptr;
	tail = nullptr;
	NoE = 0;
	for(auto it = list.begin();it!=list.end();it++)
		this->push_back(*it);
}

template<typename T>
void List<T>::erase(iterator& it)
{
	Node& element = it.get_node();
	it++;
	if(element.next == nullptr)
	{
		this -> pop_back();
		return;
	}
	if(element.prev == nullptr)
	{
		this -> pop_front();
		return;
	}
	element.prev->next = element.next;
	element.next->prev = element.prev;
	delete &element;
	this->NoE--;
	return;
}

template<typename T>
void List<T>::erase(reverse_iterator& it)
{
	Node& element = it.get_node();
	it++;
	if(element.next == nullptr)
	{
		this -> pop_back();
		return;
	}
	if(element.prev == nullptr)
	{
		this -> pop_front();
		return;
	}
	element.prev->next = element.next;
	element.next->prev = element.prev;
	delete &element;
	this->NoE--;
	return;
}

template<typename T>
void List<T>::erase(List<T>::Node& element)
{
	if(element.next == nullptr)
	{
		this -> pop_back();
		return;
	}
	if(element.prev == nullptr)
	{
		this -> pop_front();
		return;
	}
	element.prev->next = element.next;
	element.next->prev = element.prev;
	delete &element;
	this->NoE--;
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
			auto it = this->begin();
			for(unsigned int i = 0;i < index;i++) it++;
			Node& node = it.get_node();
			List<T>::Node* temp = new List<T>::Node(node.prev, &node, NewElement);
			node.prev->next = temp;
			node.prev = temp;
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
void List<T>::remove(const T& element)
{
	auto it = this->begin();
	while(it != this->end())
	{
		if(*it == element)
			erase(it);
		else
			it++;
	}
	return;
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
