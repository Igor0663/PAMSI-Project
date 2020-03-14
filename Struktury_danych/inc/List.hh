#ifndef _LIST_HH
#define _LIST_HH

template<typename T>
struct Node
{
	Node* next;
	T value;

	Node(Node* StartPtr = nullptr): next(StartPtr) {}
	Node(Node* StartPtr, const T& StartValue):next(StartPtr), value(StartValue) {}
};

template<typename T>
class Iterator
{
		Node<T>* node;
	public:
		Iterator( Node<T>* NewNode): node(NewNode){}
	//	~Iterator();
		Iterator&     operator++();
		Iterator      operator++(int);
		T	      operator*() const;
		Iterator&     operator=(const Iterator& It);
		bool          operator!=(const Iterator& It) const;
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
