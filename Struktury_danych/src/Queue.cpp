#include<exception>
#include<iostream>

template<typename T>
Queue<T>::Queue(const Queue<T>& list)
{
	head = nullptr;
	tail = nullptr;
	NoE = 0;
	for(auto it = list.cbegin();it!=list.cend();it++)
		this->push(*it);
}

template<typename T>
Queue<T>::Queue(const std::initializer_list<T>& list)
{
	head = nullptr;
	tail = nullptr;
	NoE = 0;
	for(auto it = list.begin();it!=list.end();it++)
		this->push(*it);
}

template< typename T >
Queue<T>::~Queue()
{
	while(!this->empty())
		this->pop();
}

template< typename T >
T Queue<T>::pop()
{
	try
	{
		if(this->empty())
			throw std::range_error("Trying to pop empty queue");
		Queue<T>::Node* temp = head->next;
		T tmp = head->value;
		delete head;
		head = temp;
		if(this->empty())
			tail = nullptr;
		this->NoE--;
		return tmp;
	}
	catch (std::range_error& oor)
	{
		std::cerr << "Queue range error: " << oor.what() << "\n";
		exit(2);
	}
}

template< typename T >
const T& Queue<T>::front() const
{
	try
	{
		if(this->empty())
			throw std::range_error("Trying to get front value of empty queue");
		return head->value;
	}
	catch (std::range_error& oor)
	{
		std::cerr << "Queue range error: " << oor.what() << "\n";
		exit(2);
	}
}

template< typename T >
void Queue<T>::push(const T& NewValue)
{
	Queue<T>::Node* temp = new Queue<T>::Node(nullptr, NewValue);
	if(this->empty())
		head = temp;
	else
		tail->next = temp;
	tail = temp;
	this->NoE++;
	return;
}
