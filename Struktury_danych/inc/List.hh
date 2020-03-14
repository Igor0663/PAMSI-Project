#ifndef _LIST_HH
#define _LIST_HH

#include"Node.hh"
#include"List_Iterator.hh"

template<typename T>
class List
{
		Node<T>* head;
		Node<T>* tail;
		unsigned int NoE;
	public:
		List(){head = nullptr; tail=nullptr; NoE=0;}
		~List();
		void push_back(const T& NewElement);
		void push_front(const T& NewElement);
		void pop_back();
		void pop_front();
		void insert(const T& NewElement, unsigned int index);
		//void remove(const T& element);
		Iterator<T> begin();
		Iterator<T> end();
		//ConstIterator<T> cbegin();
		//ConstIterator<T> cend();
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		bool empty(){ return this->head == nullptr;}
		unsigned int size() const {return this->NoE;}

};

#include"../src/List.cpp"

#endif
