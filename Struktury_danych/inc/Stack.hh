#ifndef STACK_HH
#define STACK_HH

#include<initializer_list>

template< typename T>
class Stack{
		
	public:
		struct Node
		{
			Node* next;
			T value;
	
			Node(Node* StartPtr = nullptr): next(StartPtr) {}
			Node(Node* StartPtr, const T& StartValue):next(StartPtr), value(StartValue) {}
		};
		
		class iterator{
				Node* node;
			public:
			iterator( Node* NewNode = nullptr): node(NewNode){}
			iterator&	operator++();
			iterator	operator++(int);
			T&		operator*() const;
			iterator&	operator=(const iterator& It);
			bool		operator!=(const iterator& It) const;
		};
		
		class const_iterator{
				Node* node;
			public:
			const_iterator( Node* NewNode = nullptr): node(NewNode){}
			const_iterator&	operator++();
			const_iterator	operator++(int);
			const T&	operator*() const;
			const_iterator&	operator=(const const_iterator& It);
			bool		operator!=(const const_iterator& It) const;
		};
		Stack(){head = nullptr; NoE=0;}
		Stack(std::initializer_list<T> list);
		Stack(const Stack<T>& list);
		~Stack();
		iterator begin(){return Stack<T>::iterator(this->head);}
		iterator end(){return Stack<T>::iterator(nullptr);}
		const_iterator cbegin() const {return Stack<T>::const_iterator(this->head);}
		const_iterator cend() const {return Stack<T>::const_iterator(nullptr);}
		void push(const T& NewElement);
		T pop();
		const T& top() const;
		unsigned int size() const{return this->NoE;}
		bool empty() const { return this->head == nullptr;}
	private:
		Node* head;
		unsigned int NoE;//number of elements

};

#include"../src/Stack_Iterators.cpp"
#include"../src/Stack.cpp"

#endif
