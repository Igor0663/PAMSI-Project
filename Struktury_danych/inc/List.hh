#ifndef _LIST_HH
#define _LIST_HH

#include<initializer_list>

template<typename T>
class List
{
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
		
		List(){head = nullptr; tail=nullptr; NoE=0;}
		List(std::initializer_list<T> list);
		List(const List<T>& list);
		~List();
		void push_back(const T& NewElement);
		void push_front(const T& NewElement);
		void pop_back();
		void pop_front();
		void insert(const T& NewElement, unsigned int index);
		void remove(const T& element);
		iterator begin(){return List<T>::iterator(this->head);}
		iterator end(){return List<T>::iterator(nullptr);}
		const_iterator cbegin() const {return List<T>::const_iterator(this->head);}
		const_iterator cend() const {return List<T>::const_iterator(nullptr);}
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		bool empty() const { return this->head == nullptr;}
		unsigned int size() const {return this->NoE;}

	private:
		Node* head;
		Node* tail;
		unsigned int NoE; //number of elements
};

#include"../src/List.cpp"
#include"../src/LisT_Iterators.cpp"
#endif
