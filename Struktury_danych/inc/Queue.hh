#ifndef QUEUE_HH
#define QUEUE_HH

#include<initializer_list>

template<typename T>
class Queue{
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
		iterator begin(){return Queue<T>::iterator(this->head);}
		iterator end(){return Queue<T>::iterator(nullptr);}
		const_iterator cbegin() const {return Queue<T>::const_iterator(this->head);}
		const_iterator cend() const {return Queue<T>::const_iterator(nullptr);}
		Queue(){head = nullptr; tail=nullptr; NoE=0;}
		Queue(const std::initializer_list<T>& list);
		Queue(const Queue<T>& list);
		~Queue();
		void push(const T& NewElement);
		T pop();
		const T& front() const;
		bool empty() const { return this->head == nullptr;}
		unsigned int size() const {return this->NoE;}
	private:
		Node* head;
		Node* tail;
		unsigned int NoE;
};


#include"../src/Queue_Iterators.cpp"
#include"../src/Queue.cpp"

#endif
