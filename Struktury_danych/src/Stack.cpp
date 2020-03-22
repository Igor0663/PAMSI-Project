#include<stdexcept>
#include<iostream>

template<typename T>
Stack<T>::Stack(const Stack<T>& stack)
{
	head = nullptr;
	NoE = 0;
	Stack<T> tmp;
	for(auto it = stack.cbegin();it!=stack.cend();it++)
		tmp.push(*it);
	for(auto it = tmp.cbegin();it!=tmp.cend();it++)
		this->push(*it);
}

template<typename T>
Stack<T>::Stack(const std::initializer_list<T>& list)
{
	head = nullptr;
	NoE = 0;
	for(auto it = std::rbegin(list);it != std::rend(list);it++)
		this->push(*it);
}

template< typename T >
Stack<T>::~Stack()
{
	while(!this->empty())
		this->pop();
}

template< typename T >
void Stack<T>::push(const T& NewValue)
{
	Stack<T>::Node* temp = new Stack<T>::Node(head, NewValue);
	head = temp;
	this->NoE++;
	return;
}

template< typename T >
T Stack<T>::pop()
{
	try
	{
		if(this->empty())
			throw std::range_error("Trying to pop empty stack");
		T top = this->head->value;
		Stack<T>::Node* temp = head->next;
		delete head;
		head = temp;
		this->NoE--;
		return top;
	}
	catch (std::range_error& oor)
	{
		std::cerr << "Stack range error: " << oor.what() << "\n";
		exit(2);
	}
}

template< typename T >
const T& Stack<T>::top() const
{
	try
	{
		if(this->empty())
			throw std::range_error("Trying to get top value of empty stack");
		return this->head->value;
	}
	catch (std::range_error& oor)
	{
		std::cerr << "Stack range error: " << oor.what() << "\n";
		exit(2);
	}
}
