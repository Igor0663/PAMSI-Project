#ifndef LIST_ITERATOR_HH
#define LIST_ITERATOR_HH

#include"Node.hh"

template<typename T>
class Iterator
{
		Node<T>* node;
	public:
		Iterator( Node<T>* NewNode = nullptr): node(NewNode){}
	//	~Iterator();
		Iterator&     operator++();
		Iterator      operator++(int);
		T&	      operator*() const;
		Iterator&     operator=(const Iterator& It);
		bool          operator!=(const Iterator& It) const;
};

#include"../src/List_Iterator.cpp"

#endif
