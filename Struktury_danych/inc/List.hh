#ifndef _LIST_HH
#define _LIST_HH

template<typename T>
class Node
{
		Node* next;
		T value;
	public:
		Node(Node* StartPtr = nullptr): next(StartPtr) {}
		Node(Node* StartPtr, const T& StartValue):next(StartPtr), value(StartValue) {}
		Node* getPtr() const {return this->next; }
		void setPtr(Node* Ptr){this-> next = Ptr;}
		const T& getValue() const {return this->value; }
		T& getValue(){return this->value;}
};

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
		//Iterator begin();
		//Iterator end();
		//ConstIterator cbegin();
		//ConstIterator cend();
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		bool empty(){ return this->head == nullptr;}
		unsigned int size() const {return this->NoE;}

};

#include"../src/List.cpp"

#endif
