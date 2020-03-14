#ifndef NODE_HH
#define NODE_HH

template<typename T>
struct Node
{
	Node* next;
	T value;

	Node(Node* StartPtr = nullptr): next(StartPtr) {}
	Node(Node* StartPtr, const T& StartValue):next(StartPtr), value(StartValue) {}
};

#endif
